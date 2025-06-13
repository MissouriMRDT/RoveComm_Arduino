#ifndef ROVECOMM_ETHERNET_UDP_H
#define ROVECOMM_ETHERNET_UDP_H

#include <stdint.h>
#include <stddef.h>

#include "Platform.h"
#if ROVECOMM_TIVA
#include <EthernetUdp.h>
#elif ROVECOMM_TEENSY
#include <NativeEthernet.h>
#endif

#include "../RoveCommManifest.h"
#include "../RoveCommPacket.h"
#include "../RoveCommInterface.h"

#define ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS 10

class RoveCommEthernetUDP : public RoveCommInterface {
public:
    /**
     * @brief Initialize the UDP socket and begin accepting connections.
     * 
     * @param port The port to send from.
     */
    void begin(uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT);

    /**
     * @brief Read the latest UDP data off the network.
     * 
     * @param dest A RoveCommPacket object to store the read packet into. This prevents an expensive memory copy.
     * @return true if a packet was read.
     * @return false if no packet was read. The packet's dataId field will also be set to RC_ROVECOMM_NO_DATA_DATA_ID
     */
    bool read(RoveCommPacket &dest);

private:
    // EthernetUDP singleton
    static EthernetUDP _UDPServer;
    // List of IPs listening to traffic from _write()
    static IPAddress _subscriberIps[ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS];

    // Called by overloaded write functions
    void _write(const rovecomm::data_type_t dataType, const uint16_t dataId, const uint16_t dataCount, const void *data) override;
    // Called by overloaded writeTo functions
    void _writeTo(const rovecomm::data_type_t dataType, const uint16_t dataId, const uint16_t dataCount, const void *data,
                  const IPAddress ip, const uint16_t port) override;
};

#endif // ROVECOMM_ETHERNET_UDP_H
