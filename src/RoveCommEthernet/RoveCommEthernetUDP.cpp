#include "RoveCommEthernetUDP.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
EthernetUDP RoveCommEthernetUDP::_UDPServer;
IPAddress RoveCommEthernetUDP::_subscriberIps[ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS];
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommEthernetUDP::begin(const uint16_t port) {
    // Make sure subscriber list is empty
    for (int i = 0; i < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS; i++) {
        _subscriberIps[i] = INADDR_NONE;
    }
    // Set up Ethernet UDP
    _UDPServer.begin(port);
    delay(1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool RoveCommEthernetUDP::read(RoveCommPacket &dest) {
    // default to empty packet
    dest.dataId = RC_ROVECOMM_NO_DATA_DATA_ID;
    dest.dataCount = 0;

#if ROVECOMM_TEENSY
    // Teensy implementation is set to not block on startup
    if (Ethernet.linkStatus() != EthernetLinkStatus::LinkON) return false;
#endif

    // Read the most recent UDP packet from the input buffer
    // RoveCommPackets always fit inside single UDP packet so, unlike with TCP, we know how much
    // data we have to parse.
    uint8_t readBuf[ROVECOMM_PACKET_HEADER_SIZE + ROVECOMM_PACKET_MAX_DATA_COUNT];
    int packetSize = _UDPServer.parsePacket();
    if (packetSize == 0 || packetSize > ROVECOMM_PACKET_HEADER_SIZE + ROVECOMM_PACKET_MAX_DATA_COUNT) return false;

    // Get incoming IP
    IPAddress readIp = _UDPServer.remoteIP();
    _UDPServer.read(readBuf, packetSize);

    // Read data from buffer into RoveCommPacket
    if (!rovecomm::unpackPacket(dest, readBuf)) return false;

    // Parse special dataIds
    // Subscribe Request
    if (dest.dataId == RC_ROVECOMM_SUBSCRIBE_DATA_ID) {
        for (int i = 0; i < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS; i++) {
            // Break if already subscribed
            if (_subscriberIps[i] == readIp) {
                break;
            }
            // Add if not subscribed
            else if (_subscriberIps[i] == INADDR_NONE) {
                _subscriberIps[i] = readIp;
                break;
            }
        }
    }
    // Unsubscribe Request
    else if (dest.dataId == RC_ROVECOMM_UNSUBSCRIBE_DATA_ID) {
        for (int i = 0; i < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS; i++) {
            // Remove from subscriber list
            if (_subscriberIps[i] == readIp) {
                _subscriberIps[i] = INADDR_NONE; // remove subscriber
            }
        }
    } else if (dest.dataId == RC_ROVECOMM_PING_DATA_ID) {
        uint8_t pData[1] = {1};
        this->_writeTo(rovecomm::UINT8_T, RC_ROVECOMM_PING_REPLY_DATA_ID, 1, pData, readIp,
                       RC_ROVECOMM_ETHERNET_UDP_PORT);
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommEthernetUDP::_write(const rovecomm::data_type_t dataType, const uint16_t dataId, const uint16_t dataCount,
                                 const void *data) {

#if ROVECOMM_TEENSY
    // Teensy implementation is set to not block on startup
    if (Ethernet.linkStatus() != EthernetLinkStatus::LinkON) return;
#endif

    // Pack data into a buffer for writing
    uint8_t writeBuf[ROVECOMM_PACKET_HEADER_SIZE + ROVECOMM_PACKET_MAX_DATA_COUNT];
    size_t sendBytes =
        rovecomm::packPacket(writeBuf, dataId, dataCount, dataType, reinterpret_cast<const uint8_t *>(data));
    if (sendBytes == 0) return;

    // Send packet to everyone in subscribers
    for (int i = 0; i < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS; i++) {
        if (_subscriberIps[i] != INADDR_NONE) {
            _UDPServer.beginPacket(_subscriberIps[i], RC_ROVECOMM_ETHERNET_UDP_PORT);
            _UDPServer.write(writeBuf, sendBytes);
            _UDPServer.endPacket();
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommEthernetUDP::_writeTo(const rovecomm::data_type_t dataType, const uint16_t dataId,
                                   const uint16_t dataCount, const void *data, const IPAddress ip,
                                   const uint16_t port) {

#if ROVECOMM_TEENSY
    // Teensy implementation is set to not block on startup
    if (Ethernet.linkStatus() != EthernetLinkStatus::LinkON) return;
#endif

    // Pack data into a buffer for writing
    uint8_t writeBuf[ROVECOMM_PACKET_HEADER_SIZE + ROVECOMM_PACKET_MAX_DATA_COUNT];
    size_t sendBytes =
        rovecomm::packPacket(writeBuf, dataId, dataCount, dataType, reinterpret_cast<const uint8_t *>(data));
    if (sendBytes == 0) return;

    // Write to that IP
    _UDPServer.beginPacket(ip, port);
    _UDPServer.write(writeBuf, sendBytes);
    _UDPServer.endPacket();
}
