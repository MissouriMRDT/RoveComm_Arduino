#include "Platform.h"
#if ROVECOMM_TIVA
#include <Ethernet.h>
#elif ROVECOMM_TEENSY
#include <NativeEthernet.h>
#endif

#include "RoveCommEthernet.h"

// User can declare their own instance, since you might want Wifi instead of Ethernet
// RoveCommEthernet RoveComm;

void RoveCommEthernet::begin(const IPAddress ip, uint8_t *mac, const uint16_t udpPort, const uint16_t tcpPort) {
#if ROVECOMM_TIVA
    // Set up Ethernet
    Ethernet.enableActivityLed();
    Ethernet.enableLinkLed();
    Ethernet.begin(mac, ip);
#elif ROVECOMM_TEENSY
    // We can't use Ethernet.begin(mac, IP); because it is blocking in the Teensy implementation
    // To get around this, we use Ethernet.begin(mac, 0, 0) which does the same thing as the other one
    // but tries to get an IP automatically over DHCP. By setting the timeouts to be 0, we cut it off early.
    // The annoying part is that we have to set the IP, gateway, dns, and subnet mask manually.
    Ethernet.begin(mac, 0, 0);
    // Set IP of this board
    Ethernet.setLocalIP(ip);
    // Assume the DNS server will be the machine on the same network as the local IP
    // but with last octet being '1'
    IPAddress dns = ip;
    dns[3] = 1;
    Ethernet.setDnsServerIP(ip);
    // Assume the gateway will be the machine on the same network as the local IP
    // but with last octet being '1'
    IPAddress gateway = ip;
    gateway[3] = 1;
    Ethernet.setGatewayIP(gateway);
#endif

    // start UDP client and assigning board IP
    UDP.begin(udpPort);
    // initializing the TCP server with the correct port
    TCP.begin(tcpPort);
}
void RoveCommEthernet::begin(const IPAddress ip, const uint16_t udpPort, const uint16_t tcpPort) {
    uint8_t mac[6] = {
        (uint8_t)RC_ROVECOMM_SUBNET_MAC_FIRST_BYTE,
        (uint8_t)RC_ROVECOMM_SUBNET_MAC_SECOND_BYTE,
        (uint8_t)ip[0],
        (uint8_t)ip[1],
        (uint8_t)ip[2],
        (uint8_t)ip[3],
    };
    begin(ip, mac, udpPort, tcpPort);
}

bool RoveCommEthernet::read(RoveCommPacket &dest) {
    // reset to no data
    dest.dataId = RC_ROVECOMM_NO_DATA_DATA_ID;
    dest.dataCount = 0;

#if ROVECOMM_TEENSY
    // Teensy implementation is set to not block on startup
    if (Ethernet.linkStatus() != EthernetLinkStatus::LinkON) {
        return false;
    }
#endif

    // checks for TCP packets first, as they should be infrequent and require acks
    TCP.read(dest);
    if (dest.dataId != RC_ROVECOMM_NO_DATA_DATA_ID && dest.dataId != RC_ROVECOMM_INVALID_VERSION_DATA_ID) {
        return true;
    }

    // check for UDP packets if no TCP were read
    UDP.read(dest);
    if (dest.dataId != RC_ROVECOMM_NO_DATA_DATA_ID && dest.dataId != RC_ROVECOMM_INVALID_VERSION_DATA_ID) {
        return true;
    }

    return false;
}
