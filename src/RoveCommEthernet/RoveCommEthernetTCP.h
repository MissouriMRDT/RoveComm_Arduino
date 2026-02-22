#ifndef ROVECOMM_ETHERNET_TCP_H
#define ROVECOMM_ETHERNET_TCP_H

#include <stdint.h>
#include <stddef.h>

#include "Platform.h"
#if ROVECOMM_TIVA
#include <Ethernet.h>
#elif ROVECOMM_TEENSY
#include <NativeEthernet.h>
#else
#include <Ethernet.h>
#endif

#include "../RoveCommManifest.h"
#include "../RoveCommPacket.h"
#include "../RoveCommInterface.h"

#define ROVECOMM_PACKET_READ_TIMEOUT 10000
#define ROVECOMM_PACKET_WRITE_TIMEOUT 10000

class RoveCommEthernetTCP : public RoveCommInterface {
public:
    /**
     * @brief Initialize the TCP server and begin accepting connections.
     * 
     * @param port The port to listen on. Incoming connections will be maintained on other ports.
     */
    void begin(uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT);

    /**
     * @brief Read the latest TCP data off the network.
     * 
     * @param dest A RoveCommPacket object to store the read packet into. This prevents an expensive memory copy.
     * @return true if a packet was read.
     * @return false if no packet was read. The packet's dataId field will also be set to RC_ROVECOMM_NO_DATA_DATA_ID
     */
    bool read(RoveCommPacket &dest);

private:
    // EthernetServer singleton. This class already maintains connections which we treat as subscribers.
    static EthernetServer _TCPServer;

    // Called by overloaded write functions
    void _write(const rovecomm::data_type_t dataType, const uint16_t dataId, const uint16_t dataCount, const void *data) override;
    // Write over TCP to the given ip and port
    void _writeTo(const rovecomm::data_type_t dataType, const uint16_t dataId, const uint16_t dataCount, const void *data,
                          const IPAddress ip, const uint16_t port) override;
};

#endif // ROVECOMM_ETHERNET_TCP_H
