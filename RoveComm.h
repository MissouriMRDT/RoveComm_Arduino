/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MRDT => TivaC1294/TivaC129E Launchpad
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ROVECOMM_H
#define ROVECOMM_H

#include "RoveCommManifest.h"
#include "RoveCommPacket.h"

#include <Energia.h>

#include <stdint.h>
#include <stddef.h>

class RoveCommEthernet //////////////////////////////////////////////////////////////////////////////////////
{
  public:

    IPAddress     RoveCommSubscriberIps[ COUNT::MAX_SUBSCRIBER_IPS ] = { INADDR_NONE };
 
    void begin(   uint8_t  ip_4);
    void begin(   uint8_t  ip_1,     uint8_t ip_2, uint8_t ip_3, uint8_t ip_4, uint16_t port );

    void write(   uint16_t data_id,  uint8_t data_count,        uint8_t  data   );
    void write(   uint16_t data_id,  uint8_t data_count,        uint16_t data   );
    void write(   uint16_t data_id,  uint8_t data_count,        uint32_t data   );
    void write(   uint16_t data_id,  uint8_t data_count,        int8_t   data   );
    void write(   uint16_t data_id,  uint8_t data_count,        int16_t  data   );
    void write(   uint16_t data_id,  uint8_t data_count,        int32_t  data   );
    void write(   uint16_t data_id,  uint8_t data_count,  const uint8_t  data[] );
    void write(   uint16_t data_id,  uint8_t data_count,  const uint16_t data[] );
    void write(   uint16_t data_id,  uint8_t data_count,  const uint32_t data[] );
    void write(   uint16_t data_id,  uint8_t data_count,  const int8_t   data[] );
    void write(   uint16_t data_id,  uint8_t data_count,  const int16_t  data[] );
    void write(   uint16_t data_id,  uint8_t data_count,  const int32_t  data[] );

    void write(   uint16_t data_id,  uint8_t data_count,        uint8_t  data,    uint8_t ip_4 );
    void write(   uint16_t data_id,  uint8_t data_count,        uint16_t data,    uint8_t ip_4 );
    void write(   uint16_t data_id,  uint8_t data_count,        uint32_t data,    uint8_t ip_4 );
    void write(   uint16_t data_id,  uint8_t data_count,        int8_t   data,    uint8_t ip_4 );
    void write(   uint16_t data_id,  uint8_t data_count,        int16_t  data,    uint8_t ip_4 );
    void write(   uint16_t data_id,  uint8_t data_count,        int32_t  data,    uint8_t ip_4 );

    void write(   uint16_t data_id,  uint8_t data_count,  const uint8_t  data[] , uint8_t ip_4 );
    void write(   uint16_t data_id,  uint8_t data_count,  const uint16_t data[] , uint8_t ip_4 );
    void write(   uint16_t data_id,  uint8_t data_count,  const uint32_t data[] , uint8_t ip_4 );
    void write(   uint16_t data_id,  uint8_t data_count,  const int8_t   data[] , uint8_t ip_4 );
    void write(   uint16_t data_id,  uint8_t data_count,  const int16_t  data[] , uint8_t ip_4 );
    void write(   uint16_t data_id,  uint8_t data_count,  const int32_t  data[] , uint8_t ip_4 );

    void write(   uint16_t data_id, uint8_t  data_count,  uint8_t data_type,      const void* data );
    void writeTo( uint16_t data_id, uint8_t  data_count,  uint8_t data_type,      const void* data, uint8_t  ip_4 );
    void writeTo( uint16_t data_id, uint8_t  data_count,  uint8_t data_type,      const void* data, 
                  uint8_t  ip_1,    uint8_t  ip_2,        uint8_t     ip_3,       uint8_t ip_4,     uint16_t port );

    struct RoveCommPacket read();
};

class RoveCommAtlasEthernet /////////////////////////////////////////////////////////////////////////////////
{
public:

    IPAddress     RoveCommSubscriberIps[  COUNT::MAX_SUBSCRIBER_IPS ] = { INADDR_NONE };
 
    void begin(   uint8_t  ip_4);
    void write(   uint16_t data_id, uint8_t data_byte_count, const void* data );
    void writeTo( uint16_t data_id, uint8_t data_byte_count, const void* data, uint8_t  ip_4 );

    struct RoveCommAtlasPacket read();
};

#endif // ROVECOMM_H