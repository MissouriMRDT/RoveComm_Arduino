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

#include "../RoveCommManifest.h"
#include "../RoveCommPacket.h"
#include "RoveCommEthernetTCP.h"
#include "RoveCommEthernetUDP.h"

/**
 * @brief A wrapper for a RoveCommEthernetTCP and a RoveCommEthernetUDP instance.
 * 
 */
class RoveCommEthernet {
public:
    RoveCommEthernetTCP TCP;
    RoveCommEthernetUDP UDP;

    /**
     * @brief Initialize the ethernet stack and begin listening for connections.
     * 
     * @param ip The static IP Address this board will have.
     * @param mac Any 6 bytes, so long as they are unique to this board.
     * @param udpPort Port to use for UDP communication. Default is RC_ROVECOMM_ETHERNET_UDP_PORT
     * @param tcpPort Port to use for TCP communication. Default is RC_ROVECOMM_ETHERNET_TCP_PORT
     */
    void begin(IPAddress ip, uint16_t udpPort=RC_ROVECOMM_ETHERNET_UDP_PORT, uint16_t tcpPort=RC_ROVECOMM_ETHERNET_TCP_PORT);
    
    /**
     * @brief Initialize the ethernet stack and begin listening for connections.
     * 
     * @param ip The static IP Address this board will have.
     * @param udpPort Port to use for UDP communication. Default is RC_ROVECOMM_ETHERNET_UDP_PORT
     * @param tcpPort Port to use for TCP communication. Default is RC_ROVECOMM_ETHERNET_TCP_PORT
     */
    void begin(IPAddress ip, uint8_t *mac, uint16_t udpPort=RC_ROVECOMM_ETHERNET_UDP_PORT, uint16_t tcpPort=RC_ROVECOMM_ETHERNET_TCP_PORT);

    /**
     * @brief Read the latest TCP data and, if none, the latest UDP packet off the network.
     * 
     * @param dest A RoveCommPacket object to store the read packet into. This prevents an expensive memory copy.
     * @return true if a packet was read.
     * @return false if no packet was read. The packet's dataId field will also be set to RC_ROVECOMM_NO_DATA_DATA_ID
     */
    bool read(RoveCommPacket &dest);

    /**
     * @brief Convenience method to follow an old code pattern. Prefer read(packet) instead.
     * 
     * @return RoveCommPacket 
     */
    RoveCommPacket read() {
        RoveCommPacket packet;
        read(packet);
        return packet;
    }

    ///// CONVENIENCE METHODS ////////////////////////////////////////////////////////////////////////////////////////////

    /**
     * @brief Send data to all subscribers via UDP. Overloaded for each data type.
     * 
     * @param dataId ID of this packet. e.g. RC_COREBOARD_DRIVELEFTRIGHT_DATA_ID
     * @param dataCount How many elements are in the data array.
     * @param data The data to send.
     */
    void write(uint16_t dataId, uint16_t dataCount, const uint8_t  *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const uint16_t *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const uint32_t *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const int8_t   *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const int16_t  *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const int32_t  *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const float    *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const double   *data) { UDP.write(dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const char     *data) { UDP.write(dataId, dataCount, data); }

    /**
     * @brief Convenience method for sending a single value to all subscribers via UDP. Overloaded for each data type.
     * 
     * @param dataId ID of this packet. e.g. RC_COREBOARD_WATCHDOGOVERRIDE_DATA_ID
     * @param data The datum to send.
     */
    void write(uint16_t dataId, uint8_t  data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint32_t data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, int8_t   data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, int16_t  data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, int32_t  data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, float    data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, double   data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, char     data) { write(dataId, 1, &data); }

    /**
     * @brief Send data to a specific IP address via UDP. The packet is not sent to this board's subscribers.
     * Overloaded for each data type.
     * 
     * @param dataId ID of this packet. e.g. RC_COREBOARD_DRIVELEFTRIGHT_DATA_ID
     * @param dataCount How many elements are in the data array.
     * @param data The data to send.
     * @param ip The destination IP for this packet.
     * @param port The destination port for this packet. Default is RC_ROVECOMM_ETHERNET_UDP_PORT
     */
    void writeTo(uint16_t dataId, uint16_t dataCount, const uint8_t  *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const uint16_t *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const uint32_t *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const int8_t   *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const int16_t  *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const int32_t  *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const float    *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const double   *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const char     *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { UDP.writeTo(dataId, dataCount, data, ip, port); }

    /**
     * @brief Convenience method for sending a single value to a specific IP address via UDP.
     * The packet is not sent to this board's subscribers. Overloaded for each data type.
     * 
     * @param dataId ID of this packet. e.g. RC_COREBOARD_WATCHDOGOVERRIDE_DATA_ID
     * @param data The datum to send.
     * @param ip The destination IP for this packet.
     * @param port The destination port for this packet. Default is RC_ROVECOMM_ETHERNET_UDP_PORT
     */
    void writeTo(uint16_t dataId, uint8_t  data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, uint32_t data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, int8_t   data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, int16_t  data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, int32_t  data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, float    data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, double   data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, char     data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT) { writeTo(dataId, 1, &data, ip, port); }

    /**
     * @brief Send data to all subscribers via TCP. Overloaded for each data type.
     * 
     * @param dataId ID of this packet. e.g. RC_COREBOARD_DRIVELEFTRIGHT_DATA_ID
     * @param dataCount How many elements are in the data array.
     * @param data The data to send.
     */
    void writeReliable(uint16_t dataId, uint16_t dataCount, const uint8_t  *data) { TCP.write(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const uint16_t *data) { TCP.write(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const uint32_t *data) { TCP.write(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const int8_t   *data) { TCP.write(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const int16_t  *data) { TCP.write(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const int32_t  *data) { TCP.write(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const float    *data) { TCP.write(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const double   *data) { TCP.write(dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const char     *data) { TCP.write(dataId, dataCount, data); }

    /**
     * @brief Convenience method for sending a single value to all subscribers via TCP. Overloaded for each data type.
     * 
     * @param dataId ID of this packet. e.g. RC_COREBOARD_WATCHDOGOVERRIDE_DATA_ID
     * @param data The datum to send.
     */
    void writeReliable(uint16_t dataId, uint8_t  data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, uint16_t data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, uint32_t data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, int8_t   data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, int16_t  data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, int32_t  data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, float    data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, double   data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, char     data) { writeReliable(dataId, 1, &data); }

    /**
     * @brief Send data to a specific IP address via TCP. The packet is not sent to this board's subscribers.
     * Overloaded for each data type.
     * 
     * @param dataId ID of this packet. e.g. RC_COREBOARD_DRIVELEFTRIGHT_DATA_ID
     * @param dataCount How many elements are in the data array.
     * @param data The data to send.
     * @param ip The destination IP for this packet.
     * @param port The destination port for this packet. Default is RC_ROVECOMM_ETHERNET_TCP_PORT
     */
    void writeToReliable(uint16_t dataId, uint16_t dataCount, const uint8_t  *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { TCP.writeTo(dataId, dataCount, data, ip, port); }
    void writeToReliable(uint16_t dataId, uint16_t dataCount, const uint16_t *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { TCP.writeTo(dataId, dataCount, data, ip, port); }
    void writeToReliable(uint16_t dataId, uint16_t dataCount, const uint32_t *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { TCP.writeTo(dataId, dataCount, data, ip, port); }
    void writeToReliable(uint16_t dataId, uint16_t dataCount, const int8_t   *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { TCP.writeTo(dataId, dataCount, data, ip, port); }
    void writeToReliable(uint16_t dataId, uint16_t dataCount, const int16_t  *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { TCP.writeTo(dataId, dataCount, data, ip, port); }
    void writeToReliable(uint16_t dataId, uint16_t dataCount, const int32_t  *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { TCP.writeTo(dataId, dataCount, data, ip, port); }
    void writeToReliable(uint16_t dataId, uint16_t dataCount, const float    *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { TCP.writeTo(dataId, dataCount, data, ip, port); }
    void writeToReliable(uint16_t dataId, uint16_t dataCount, const double   *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { TCP.writeTo(dataId, dataCount, data, ip, port); }
    void writeToReliable(uint16_t dataId, uint16_t dataCount, const char     *data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { TCP.writeTo(dataId, dataCount, data, ip, port); }

    /**
     * @brief Convenience method for sending a single value to a specific IP address via TCP.
     * The packet is not sent to this board's subscribers. Overloaded for each data type.
     * 
     * @param dataId ID of this packet. e.g. RC_COREBOARD_WATCHDOGOVERRIDE_DATA_ID
     * @param data The datum to send.
     * @param ip The destination IP for this packet.
     * @param port The destination port for this packet. Default is RC_ROVECOMM_ETHERNET_TCP_PORT
     */
    void writeToReliable(uint16_t dataId, uint8_t  data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { writeToReliable(dataId, 1, &data, ip, port); }
    void writeToReliable(uint16_t dataId, uint16_t data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { writeToReliable(dataId, 1, &data, ip, port); }
    void writeToReliable(uint16_t dataId, uint32_t data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { writeToReliable(dataId, 1, &data, ip, port); }
    void writeToReliable(uint16_t dataId, int8_t   data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { writeToReliable(dataId, 1, &data, ip, port); }
    void writeToReliable(uint16_t dataId, int16_t  data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { writeToReliable(dataId, 1, &data, ip, port); }
    void writeToReliable(uint16_t dataId, int32_t  data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { writeToReliable(dataId, 1, &data, ip, port); }
    void writeToReliable(uint16_t dataId, float    data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { writeToReliable(dataId, 1, &data, ip, port); }
    void writeToReliable(uint16_t dataId, double   data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { writeToReliable(dataId, 1, &data, ip, port); }
    void writeToReliable(uint16_t dataId, char     data, IPAddress ip, uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT) { writeToReliable(dataId, 1, &data, ip, port); }

    friend class RoveCommEthernetUDP;
    friend class RoveCommEthernetTCP;
};

// extern RoveCommEthernet RoveComm;

#endif // ROVECOMM_ETHERNET_H
