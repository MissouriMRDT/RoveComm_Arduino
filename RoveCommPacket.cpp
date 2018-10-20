#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "Energia.h"

#include "RoveCommPacket.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace roveware
{
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  struct udp_packet packUdpPacket(const uint16_t data_id, const uint8_t data_count, const data_type_t data_type, const void* data)
  {
    struct udp_packet udp_packet;

    udp_packet.bytes[0] = data_id  >> 8;
    udp_packet.bytes[1] = data_id;
    udp_packet.bytes[2] = data_count;
    udp_packet.bytes[3] = data_type;

    if(( data_type == INT32_T )
    || ( data_type == UINT32_T))
    {
      uint32_t* data_32t = (uint32_t*)data;
      uint16_t  index    = 0;
      for(int i=0; i < 4 * data_count; i+=4)
      { 
        udp_packet.bytes[ROVECOMM_ETHERNET_UDP_PACKET_HEADER_SIZE + i    ] = data_32t[index] >> 24;
        udp_packet.bytes[ROVECOMM_ETHERNET_UDP_PACKET_HEADER_SIZE + i + 1] = data_32t[index] >> 16;
        udp_packet.bytes[ROVECOMM_ETHERNET_UDP_PACKET_HEADER_SIZE + i + 2] = data_32t[index] >> 8;
        udp_packet.bytes[ROVECOMM_ETHERNET_UDP_PACKET_HEADER_SIZE + i + 3] = data_32t[index];
        index++;
      }
    } else if(( data_type == INT16_T )
           || ( data_type == UINT16_T))
    {
      uint16_t* data_16t = (uint16_t*)data;
      uint16_t  index    = 0;
      for(int i=0; i < 2 * data_count; i+=2)
      { 
        udp_packet.bytes[ROVECOMM_ETHERNET_UDP_PACKET_HEADER_SIZE + i    ] = data_16t[index] >> 8;
        udp_packet.bytes[ROVECOMM_ETHERNET_UDP_PACKET_HEADER_SIZE + i + 1] = data_16t[index];
        index++;
      }

    } else if(( data_type == INT8_T )
           || ( data_type == UINT8_T))
    {    
      uint8_t* data_8t = (uint8_t*)data;
      for(int i=0; i < 1 * data_count; i+=1)
      { 
        udp_packet.bytes[ROVECOMM_ETHERNET_UDP_PACKET_HEADER_SIZE + i]     = data_8t[i];
      }

    } else // invalid => set data_count = 0
    { 
      struct udp_packet udp_packet_INVALID = { 0 };
      return udp_packet_INVALID; 
    } 
    return udp_packet;
  }

  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  struct rovecomm_packet unpackUdpPacket(const uint8_t udp_packet_bytes[])
  {
    struct rovecomm_packet rovecomm_packet = { 0 };

       uint16_t data_id    =              (udp_packet_bytes[0] << 8)
                           |               udp_packet_bytes[1];
        uint8_t data_count =               udp_packet_bytes[2];
    data_type_t data_type  =  (data_type_t)udp_packet_bytes[3];

   if(( data_type ==  INT32_T )
   || ( data_type == UINT32_T ))
    { 
      uint16_t  index    = 0;
      for(int i=0; i < 4*data_count; i+=4 )
      { 
        rovecomm_packet.data[index] = (udp_packet_bytes[ROVECOMM_ETHERNET_UDP_PACKET_HEADER_SIZE + i]     << 24)
                                    | (udp_packet_bytes[ROVECOMM_ETHERNET_UDP_PACKET_HEADER_SIZE + i + 1] << 16)
                                    | (udp_packet_bytes[ROVECOMM_ETHERNET_UDP_PACKET_HEADER_SIZE + i + 2] << 8)
                                    |  udp_packet_bytes[ROVECOMM_ETHERNET_UDP_PACKET_HEADER_SIZE + i + 3];
        index++;
      }
    } else if(( data_type ==  INT16_T )
           || ( data_type == UINT16_T ))
    { 
      uint16_t  index    = 0;
      for(int i=0; i < 2*data_count; i+=2 )
      { 
        rovecomm_packet.data[index] = (udp_packet_bytes[ROVECOMM_ETHERNET_UDP_PACKET_HEADER_SIZE + i    ] << 8)
                                    |  udp_packet_bytes[ROVECOMM_ETHERNET_UDP_PACKET_HEADER_SIZE + i + 1];
        index++;
      }
    } else if(( data_type ==  INT8_T )
           || ( data_type == UINT8_T ))
    {
      for(int i=0; i < 1*data_count; i+=1 )
      { 
        rovecomm_packet.data[i] = udp_packet_bytes[ROVECOMM_ETHERNET_UDP_PACKET_HEADER_SIZE + i];
      }
     } else
    { 
      data_count = 0; // invalid_data
    }

    rovecomm_packet.data_count = data_count;
    rovecomm_packet.data_id    = data_id;
    return rovecomm_packet;
  }

}// end namespace/////////////////////////////////////////////////////////////////////////////////////////////////

