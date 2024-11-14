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

#include "RoveCommManifest.h"
#include "RoveCommPacket.h"

#define ROVECOMM_PACKET_READ_TIMEOUT 10000
#define ROVECOMM_PACKET_WRITE_TIMEOUT 10000

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RoveCommEthernetTCP {
public:
    /////begin//////////////////////////////////////////////////////////////////////////////////////////////////////////
    void begin(uint16_t port=RC_ROVECOMM_ETHERNET_TCP_PORT);

    /////read///////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool read(RoveCommPacket &dest);

    /////writeReliable//////////////////////////////////////////////////////////////////////////////////////////////////
    // Array entry writeReliable which ensures delivery
    // Overloaded for each data type
    void writeReliable(uint16_t dataId, uint16_t dataCount, const uint8_t  *data) { _writeReliable(rovecomm::UINT8_T,  dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const uint16_t *data) { _writeReliable(rovecomm::UINT16_T, dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const uint32_t *data) { _writeReliable(rovecomm::UINT32_T, dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const int8_t   *data) { _writeReliable(rovecomm::INT8_T,   dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const int16_t  *data) { _writeReliable(rovecomm::INT16_T,  dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const int32_t  *data) { _writeReliable(rovecomm::INT32_T,  dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const float    *data) { _writeReliable(rovecomm::FLOAT,    dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const double   *data) { _writeReliable(rovecomm::DOUBLE,   dataId, dataCount, data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, const char     *data) { _writeReliable(rovecomm::CHAR,     dataId, dataCount, data); }
    // Single-value writeReliable which ensures delivery
    // Overloaded for each data type
    void writeReliable(uint16_t dataId, uint16_t dataCount, uint8_t  data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, uint16_t data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, uint32_t data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, int8_t   data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, int16_t  data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, int32_t  data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, float    data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, double   data) { writeReliable(dataId, 1, &data); }
    void writeReliable(uint16_t dataId, uint16_t dataCount, char     data) { writeReliable(dataId, 1, &data); }

private:
    // EthernetServer singleton
    static EthernetServer _TCPServer;
    // Called by overloaded writeReliable functions
    void _writeReliable(const rovecomm::data_type_t dataType, const uint16_t dataId, const uint16_t dataCount, const void *data); 
    // Write over TCP to the given ip and port
    void _writeToReliable(const rovecomm::data_type_t dataType, const uint16_t dataId, const uint16_t dataCount, const void *data,
                          const IPAddress ip, const uint16_t port);

    // TODO: _writeToReliable? other versions of rovecomm have this, but we've never needed it.
};

#endif // ROVECOMM_ETHERNET_TCP_H
