#ifndef TeensyRoveCommEthernetTCP_h
#define TeensyRoveCommEthernetTCP_h

#include <stdint.h>
#include <stddef.h>
#include <Arduino.h>
#include <NativeEthernet.h>

#include "TeensyRoveCommManifest.h"
#include "TeensyRoveCommPacket.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RoveCommEthernetTCP
{
  public:
    EthernetServer *TCPServer;

    /////begin////////////////////////////////////////////////////////////////////////
    void begin(EthernetServer *TServer, IPAddress IP);
    void begin(EthernetServer *TServer);

    /////read////////////////////////////////////////////////////////////////////////
    struct rovecomm_packet read();

    /////writeReliable////////////////////////////////////////////////////////////////////////
    //Single-value writeReliable which ensures delivery
    //Overloaded for each data type
    void writeReliable(const uint16_t data_id, const uint8_t data_count, const uint8_t  data);
    void writeReliable(const uint16_t data_id, const uint8_t data_count, const uint16_t data);
    void writeReliable(const uint16_t data_id, const uint8_t data_count, const uint32_t data);
    void writeReliable(const uint16_t data_id, const uint8_t data_count, const int8_t   data);
    void writeReliable(const uint16_t data_id, const uint8_t data_count, const int16_t  data);
    void writeReliable(const uint16_t data_id, const uint8_t data_count, const int32_t  data);
    void writeReliable(const uint16_t data_id, const uint8_t data_count, const float    data);


    //Array entry writeReliable which ensures delivery
    //Overloaded for each data type
    void writeReliable(const uint16_t data_id, const int     data_count, const int      *data);
    void writeReliable(const uint16_t data_id, const uint8_t data_count, const uint8_t  *data);
    void writeReliable(const uint16_t data_id, const uint8_t data_count, const uint16_t *data);
    void writeReliable(const uint16_t data_id, const uint8_t data_count, const uint32_t *data);
    void writeReliable(const uint16_t data_id, const uint8_t data_count, const int8_t   *data);
    void writeReliable(const uint16_t data_id, const uint8_t data_count, const int16_t  *data);
    void writeReliable(const uint16_t data_id, const uint8_t data_count, const int32_t  *data);
    void writeReliable(const uint16_t data_id, const uint8_t data_count, const float    *data);
  private:
    //Called by overloaded writeReliable functions
    void _writeReliable(const uint8_t  data_type_length, const roveware::data_type_t data_type,
                        const uint16_t data_id, const uint8_t data_count, const void* data);

};

#endif // RoveCommEthernetTCP_h
