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

#include "RoveCommManifest.h"
#include "RoveCommPacket.h"

#define ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS 10

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RoveCommEthernetUDP {
public:
    /////begin//////////////////////////////////////////////////////////////////////////////////////////////////////////
    void begin(uint16_t port=RC_ROVECOMM_ETHERNET_UDP_PORT);

    /////read///////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool read(RoveCommPacket &dest);

    /////write//////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Array entry write
    // Overloaded for each data type
    void write(uint16_t dataId, uint16_t dataCount, const uint8_t  *data) { _write(rovecomm::UINT8_T,  dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const uint16_t *data) { _write(rovecomm::UINT16_T, dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const uint32_t *data) { _write(rovecomm::UINT32_T, dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const int8_t   *data) { _write(rovecomm::INT8_T,   dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const int16_t  *data) { _write(rovecomm::INT16_T,  dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const int32_t  *data) { _write(rovecomm::INT32_T,  dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const float    *data) { _write(rovecomm::FLOAT,    dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const double   *data) { _write(rovecomm::DOUBLE,   dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const char     *data) { _write(rovecomm::CHAR,     dataId, dataCount, data); }
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

    /////writeTo////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Array entry write
    // Overloaded for each data type
    void writeTo(uint16_t dataId, uint16_t dataCount, const uint8_t  *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::UINT8_T,  dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const uint16_t *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::UINT16_T, dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const uint32_t *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::UINT32_T, dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const int8_t   *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::INT8_T,   dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const int16_t  *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::INT16_T,  dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const int32_t  *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::INT32_T,  dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const float    *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::FLOAT,    dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const double   *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::DOUBLE,   dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const char     *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::CHAR,     dataId, dataCount, data, ip, port); }
    // Single-value writeTo
    // Overloaded for each data type
    void writeTo(uint16_t dataId, uint8_t  data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, uint32_t data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, int8_t   data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, int16_t  data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, int32_t  data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, float    data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, double   data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, char     data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }

private:
    // EthernetUDP singleton
    static EthernetUDP _UDPServer;
    // List of IPs listening to traffic from _write()
    static IPAddress _subscriberIps[ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS];

    // Called by overloaded write functions
    void _write(const rovecomm::data_type_t dataType, const uint16_t dataId, const uint16_t dataCount, const void *data);
    // Called by overloaded writeTo functions
    void _writeTo(const rovecomm::data_type_t dataType, const uint16_t dataId, const uint16_t dataCount, const void *data,
                  const IPAddress ip, const uint16_t port);
};

#endif // ROVECOMM_ETHERNET_UDP_H
