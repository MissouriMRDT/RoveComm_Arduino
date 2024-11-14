#include "RoveCommEthernetTCP.h"

EthernetServer RoveCommEthernetTCP::_TCPServer;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define MAX_CLIENTS 8
void RoveCommEthernetTCP::begin(const uint16_t port) {
    // Set up server, and start listening for clients
#if ROVECOMM_TIVA
    // In the Tiva Energia implementation, we must specify a port when we construct the EthernetServer object.
    // This doesn't allocate anything until we call begin() and then there is no way to safely dispose of
    // the server again. Therefore, we can reconstruct the _TCPServer singleton as much as we want but only
    // until we call begin(), then we must make sure we don't reset the singleton again.
    static bool _alreadyBegan = false;
    if (_alreadyBegan) return;
    _TCPServer = EthernetServer(port);
    _TCPServer.begin();
    _alreadyBegan = true;
#elif ROVECOMM_TEENSY
    _TCPServer.begin(port);
#endif
}

bool RoveCommEthernetTCP::read(RoveCommPacket &dest) {
    // reset packet
    dest.dataId = RC_ROVECOMM_NO_DATA_DATA_ID;
    dest.dataCount = 0;

#if ROVECOMM_TEENSY
    // Teensy implementation is set to not block on startup
    if (Ethernet.linkStatus() != EthernetLinkStatus::LinkON) return false;
#endif

    for (uint8_t i = 0; i < MAX_CLIENTS; i++) {

        // The Ethernet Server class avalaible() function returns clients within its array in a round-robin fashion
        // however there is no guarantee that the client returned has data to be read, therefore we do a full
        // circuit of the array and stop at the client that has data to be returned.
        EthernetClient client = _TCPServer.available();
        if (client.available() == 0) return false;

        // Parse header - this code is duplicated in unpackPacket but we need to parse the header to know how many
        // bytes to read and pass to unpackPacket
        uint8_t readBuf[ROVECOMM_PACKET_HEADER_SIZE + ROVECOMM_PACKET_MAX_DATA_COUNT];
        int bytesRead = client.read(readBuf, ROVECOMM_PACKET_HEADER_SIZE);
        if (bytesRead < ROVECOMM_PACKET_HEADER_SIZE) return false;
        if (readBuf[0] != ROVECOMM_VERSION) {
            dest.dataId = RC_ROVECOMM_INVALID_VERSION_DATA_ID;
            return false;
        }
        uint16_t dataCount = (readBuf[3] << 8) | readBuf[4];
        uint8_t dataType = readBuf[5];

        size_t typeSize = rovecomm::dataTypeSize(static_cast<rovecomm::data_type_t>(dataType));
        if (typeSize == 0) return false;

        size_t dataSize = typeSize * dataCount;
        if (dataSize > ROVECOMM_PACKET_MAX_DATA_COUNT) return false;

        // TCP works on a stream instead of discrete packets, so we read until we have enough bytes
        uint32_t startTimestamp = millis();
        size_t bytesRemaining = dataSize;
        uint8_t *copyPtr = readBuf + ROVECOMM_PACKET_HEADER_SIZE;
        do {
            int bytesRead = client.read(copyPtr, bytesRemaining);
            if (bytesRead == -1 || millis() - startTimestamp >= ROVECOMM_PACKET_READ_TIMEOUT) return false;
            copyPtr += bytesRead;
            bytesRemaining -= bytesRead;
        } while (bytesRemaining > 0);

        // RoveComm transmits in network byte order so we must swap the bytes in place
        if (rovecomm::unpackPacket(dest, readBuf)) return true;
    }
    // No clients with data were found
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommEthernetTCP::_writeReliable(const rovecomm::data_type_t dataType, const uint16_t dataId,
                                         const uint16_t dataCount, const void *data) {

#if ROVECOMM_TEENSY
    // Teensy implementation is set to not block on startup
    if (Ethernet.linkStatus() != EthernetLinkStatus::LinkON) return;
#endif

    // Pack data into a buffer for writing
    uint8_t writeBuf[ROVECOMM_PACKET_HEADER_SIZE + ROVECOMM_PACKET_MAX_DATA_COUNT];
    size_t sendSize =
        rovecomm::packPacket(writeBuf, dataId, dataCount, dataType, reinterpret_cast<const uint8_t *>(data));
    if (sendSize == 0) return;

    // Write to all available clients
    uint32_t startTimestamp = millis();
    size_t bytesRemaining = sendSize;
    size_t totalBytesSent = 0;
    do {
        size_t bytesSent = _TCPServer.write(writeBuf + totalBytesSent, bytesRemaining);
        if (bytesSent == 0 || millis() - startTimestamp >= ROVECOMM_PACKET_WRITE_TIMEOUT) return;
        totalBytesSent += bytesSent;
        bytesRemaining -= bytesSent;
    } while (bytesRemaining > 0);
}

void RoveCommEthernetTCP::_writeToReliable(const rovecomm::data_type_t dataType, const uint16_t dataId,
                                           const uint16_t dataCount, const void *data, const IPAddress ip,
                                           const uint16_t port) {
#if ROVECOMM_TEENSY
    // Teensy implementation is set to not block on startup
    if (Ethernet.linkStatus() != EthernetLinkStatus::LinkON) return;
#endif

    // Temporarily connect to the given IP
    EthernetClient client;
    if (!client.connect(ip, port)) return;

    // Pack data into a buffer for writing
    uint8_t writeBuf[ROVECOMM_PACKET_HEADER_SIZE + ROVECOMM_PACKET_MAX_DATA_COUNT];
    size_t sendSize =
        rovecomm::packPacket(writeBuf, dataId, dataCount, dataType, reinterpret_cast<const uint8_t *>(data));
    if (sendSize == 0) return;

    // Write to the given IP
    uint32_t startTimestamp = millis();
    size_t bytesRemaining = sendSize;
    size_t totalBytesSent = 0;
    do {
        size_t bytesSent = client.write(writeBuf + totalBytesSent, bytesRemaining);
        if (bytesSent == 0 || millis() - startTimestamp >= ROVECOMM_PACKET_WRITE_TIMEOUT) return;
        totalBytesSent += bytesSent;
        bytesRemaining -= bytesSent;
    } while (bytesRemaining > 0);

    // Close connection
    client.stop();
}
