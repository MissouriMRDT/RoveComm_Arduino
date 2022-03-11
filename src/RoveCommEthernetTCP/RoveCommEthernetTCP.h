#ifndef RoveCommEthernetTCP_h
#define RoveCommEthernetTCP_h

#include <stdint.h>
#include <stddef.h>

#if defined(ENERGIA)
#include <Ethernet.h>
#elif defined(ARDUINO) && (ARDUINO>100)
#include <NativeEthernet.h>
#endif

#include "RoveCommManifest.h"
#include "RoveCommPacket.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RoveCommEthernetTCP
{
  public:
    EthernetServer *TCPServer;

    /////begin////////////////////////////////////////////////////////////////////////
    #if defined(ENERGIA)
    void begin(EthernetServer *TServer, IPAddress IP);
    #elif defined(ARDUINO) && (ARDUINO>100)
    void begin(EthernetServer *TServer, IPAddress IP, uint8_t* mac);
    #endif
    void begin(EthernetServer *TServer);

    /////read////////////////////////////////////////////////////////////////////////
    struct rovecomm_packet read();

    /////writeReliable////////////////////////////////////////////////////////////////////////
    //Single-value writeReliable which ensures delivery
    //Overloaded for each data type
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const uint8_t  data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const uint16_t data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const uint32_t data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const int8_t   data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const int16_t  data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const int32_t  data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const float    data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const double  data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const char    data);

    //Array entry writeReliable which ensures delivery
    //Overloaded for each data type
    void writeReliable(const uint16_t data_id, const int     data_count, const int      *data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const uint8_t  *data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const uint16_t *data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const uint32_t *data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const int8_t   *data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const int16_t  *data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const int32_t  *data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const float    *data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const double  *data);
    void writeReliable(const uint16_t data_id, const uint16_t data_count, const char    *data);
  private:
    //Called by overloaded writeReliable functions
    void _writeReliable(const uint8_t  data_type_length, const roveware::data_type_t data_type, 
                        const uint16_t data_id, const uint16_t data_count, const void* data);

};

#endif // RoveCommEthernetTCP_h