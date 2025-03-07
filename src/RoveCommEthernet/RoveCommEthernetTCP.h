#ifndef ROVECOMM_ETHERNET_TCP_H
#define ROVECOMM_ETHERNET_TCP_H

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

#define ROVECOMM_PACKET_READ_TIMEOUT 10000
#define ROVECOMM_PACKET_WRITE_TIMEOUT 10000

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RoveCommEthernetTCP {
public:
    /////begin//////////////////////////////////////////////////////////////////////////////////////////////////////////
    void begin(uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT);

    /////read///////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool read(RoveCommPacket &dest);

    /////write//////////////////////////////////////////////////////////////////////////////////////////////////
    // Array entry write which ensures delivery
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
    // Single-value write which ensures delivery
    // Overloaded for each data type
    void write(uint16_t dataId, uint16_t dataCount, uint8_t  data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, uint16_t data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, uint32_t data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, int8_t   data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, int16_t  data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, int32_t  data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, float    data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, double   data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, char     data) { write(dataId, 1, &data); }

    /////writeTo////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Array entry write which ensures delivery
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
    // Single-value writeTo which ensures delivery
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
    // EthernetServer singleton
    static EthernetServer _TCPServer;
    // Called by overloaded write functions
    void _write(const rovecomm::data_type_t dataType, const uint16_t dataId, const uint16_t dataCount, const void *data); 
    // Write over TCP to the given ip and port
    void _writeTo(const rovecomm::data_type_t dataType, const uint16_t dataId, const uint16_t dataCount, const void *data,
                          const IPAddress ip, const uint16_t port);
};

#endif // ROVECOMM_ETHERNET_TCP_H
