#ifndef ROVECOMM_ETHERNET_H
#define ROVECOMM_ETHERNET_H

#include <stdint.h>
#include <stddef.h>

#include "Platform.h"
#if ROVECOMM_TIVA
#include <Ethernet.h>
#elif ROVECOMM_TEENSY
#include <NativeEthernet.h>
#endif

#include "RoveCommManifest.h"
#include "RoveCommPacket.h"
#include "RoveCommEthernetTCP.h"
#include "RoveCommEthernetUDP.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RoveCommEthernet {
public:
    RoveCommEthernetTCP TCP;
    RoveCommEthernetUDP UDP;

    /////begin//////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Initiate RoveComm with the given address
    void begin(IPAddress ip, uint16_t udpPort=RC_ROVECOMM_ETHERNET_UDP_PORT, uint16_t tcpPort=RC_ROVECOMM_ETHERNET_TCP_PORT);
    void begin(IPAddress ip, uint8_t *mac, uint16_t udpPort=RC_ROVECOMM_ETHERNET_UDP_PORT, uint16_t tcpPort=RC_ROVECOMM_ETHERNET_TCP_PORT);

    /////read///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Reads the latest TCP data and, if none, the latest UDP packet
    // Returns true if a packet was read
    // Returns false if no packet was read. The packet's dataId field will also be set to RC_ROVECOMM_NO_DATA_DATA_ID
    bool read(RoveCommPacket &dest);
    // Convenience method to follow old code pattern. Prefer read(packet) instead.
    RoveCommPacket read() {
        RoveCommPacket packet;
        read(packet);
        return packet;
    }

    ///// CONVENIENCE METHODS ////////////////////////////////////////////////////////////////////////////////////////////

    /////write////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Array entry write
    // Overloaded for each data type
    void write(uint16_t dataId, uint16_t dataCount, const uint8_t  *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const uint16_t *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const uint32_t *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const int8_t   *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const int16_t  *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const int32_t  *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const float    *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const double   *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const char     *data) { UDP.write(dataId, dataCount, data); }
    // Single-value write
    // Overloaded for each data type
    void write(uint16_t dataId, uint8_t  data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint32_t data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, int8_t   data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, int16_t  data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, int32_t  data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, float    data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, double   data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, char     data) { write(dataId, 1, &data); }

    /////writeTo//////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Array entry write
    // Overloaded for each data type
    void writeTo(uint16_t dataId, uint16_t dataCount, const uint8_t  *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const uint16_t *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const uint32_t *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const int8_t   *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const int16_t  *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const int32_t  *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const float    *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const double   *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const char     *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    // Single-value writeTo
    // Overloaded for each data type
    void writeTo(uint16_t dataId, uint8_t  data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, uint32_t data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, int8_t   data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, int16_t  data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, int32_t  data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, float    data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, double   data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, char     data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }

    /////writeReliable////////////////////////////////////////////////////////////////////////////////////////////////////
    // Array entry writeReliable which ensures delivery
    // Overloaded for each data type
    void writeReliable(uint16_t dataId, uint16_t dataCount, const uint8_t  *data) { TCP.writeReliable(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const uint16_t *data) { TCP.writeReliable(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const uint32_t *data) { TCP.writeReliable(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const int8_t   *data) { TCP.writeReliable(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const int16_t  *data) { TCP.writeReliable(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const int32_t  *data) { TCP.writeReliable(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const float    *data) { TCP.writeReliable(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const double   *data) { TCP.writeReliable(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const char     *data) { TCP.writeReliable(dataId, dataCount, data); }
    // Single-value writeReliable which ensures delivery
    // Overloaded for each data type
    void writeReliable(uint16_t dataId, uint8_t  data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, uint16_t data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, uint32_t data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, int8_t   data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, int16_t  data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, int32_t  data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, float    data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, double   data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, char     data) { writeReliable(dataId, 1, &data); }

    friend class RoveCommEthernetUDP;
    friend class RoveCommEthernetTCP;
};

// extern RoveCommEthernet RoveComm;

#endif // ROVECOMM_ETHERNET_H
