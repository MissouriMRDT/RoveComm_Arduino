#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>


#include "RoveCommPacket.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace roveware
{
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //Packs data into a RoveComm packet
  struct _packet packPacket(const uint16_t data_id, const uint8_t data_count, const data_type_t data_type, const void* data)
  {
	//create a new _packet
    struct _packet packet;

	//Pack upd packt with header data
	packet.bytes[0] = ROVECOMM_VERSION;
    packet.bytes[1] = data_id  >> 8;
    packet.bytes[2] = data_id;
    packet.bytes[3] = data_count;
    packet.bytes[4] = data_type;

	////////////////////////////////////////////////////////////////////////////////////////////////
	//Pack data according to data_type
    if(( data_type == INT32_T )
    || ( data_type == UINT32_T))
    {
	  //Convert data to int32_t array
      uint32_t* data_32t = (uint32_t*)data;
      uint16_t  index    = 0;
      for(int i=0; i < 4 * data_count; i+=4)
      {
		//Pack values into packet bytes
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i    ] = data_32t[index] >> 24;
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 1] = data_32t[index] >> 16;
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 2] = data_32t[index] >> 8;
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 3] = data_32t[index];
        index++;
      }
    } else if(( data_type == INT16_T )
           || ( data_type == UINT16_T))
    {
	  //Convert data to int16_t array
      uint16_t* data_16t = (uint16_t*)data;
      uint16_t  index    = 0;
      for(int i=0; i < 2 * data_count; i+=2)
      {
		//Pack values into packet bytes
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i    ] = data_16t[index] >> 8;
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 1] = data_16t[index];
        index++;
      }

    } else if(( data_type == INT8_T )
           || ( data_type == UINT8_T))
    {
	  //Convert data to int8_t array
      uint8_t* data_8t = (uint8_t*)data;
      for(int i=0; i < 1 * data_count; i+=1)
      {
		//Pack values into packet bytes
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i]     = data_8t[i];
      }

    } else // invalid => set data_count = 0
    {
      struct _packet PACKET_INVALID = { 0 };
      return PACKET_INVALID;
    }
    return packet;
  }

  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  struct rovecomm_packet unpackPacket(const uint8_t _packet_bytes[])
  {
    //for if we encounter an incompatible rovecomm message
    if(_packet_bytes[0] != ROVECOMM_VERSION)
    {
     struct rovecomm_packet invalid_version_packet = {0};
	 invalid_version_packet.data_id = ROVECOMM_INVALID_VERSION_DATA_ID;
	 invalid_version_packet.data_count = 1;
	 invalid_version_packet.data[1] = {0};
     return invalid_version_packet;
    }

    //create new RoveComm packet
    struct rovecomm_packet rovecomm_packet = {0};
    //Unpack header
    //Todo: Why don't we pass these directly into the rovecomm_packet we just made?
    uint16_t data_id   =(_packet_bytes[1] << 8)
                       | _packet_bytes[2];
    uint8_t data_count = _packet_bytes[3];
    data_type_t data_type  =  (data_type_t)_packet_bytes[4];

    //Unpack data based on data_type
    if(data_type ==  INT32_T)
    {
      uint16_t  index    = 0;
      for(int i=0; i < 4*data_count; i+=4 )
      {
        int32_t data = (_packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i]     << 24)
                                    | (_packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 1] << 16)
                                    | (_packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 2] << 8)
                                    |  _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 3];
        rovecomm_packet.data[index] = data;
		index++;
      }
    } else if(data_type ==  UINT32_T )
    {
      uint16_t  index    = 0;
      for(int i=0; i < 4*data_count; i+=4 )
      {
        uint32_t data = (_packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i]     << 24)
                                    | (_packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 1] << 16)
                                    | (_packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 2] << 8)
                                    |  _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 3];
        rovecomm_packet.data[index] = data;
		index++;
      }
    }

	else if(data_type ==  INT16_T)
    {
      uint16_t  index    = 0;
      for(int i=0; i < 2*data_count; i+=2 )
      {
        int16_t data = (_packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i    ] << 8)
                     |  _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 1];
        rovecomm_packet.data[index] = data;
		index++;
      }
    } else if(data_type == UINT16_T)
    {
      uint16_t  index    = 0;
      for(int i=0; i < 2*data_count; i+=2 )
      {
        uint16_t data = (_packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i    ] << 8)
                      |  _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 1];
        rovecomm_packet.data[index] = data;
		index++;
      }
    }

	else if(data_type ==  INT8_T )
    {
      for(int i=0; i < 1*data_count; i+=1 )
      {
		int8_t data = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i];
		rovecomm_packet.data[i] = data;
      }
     } else if(data_type ==  UINT8_T )
    {
      for(int i=0; i < 1*data_count; i+=1 )
      {
		uint8_t data = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i];
		rovecomm_packet.data[i] = data;
      }
    } else
    {
      data_count = 0; // invalid_data
    }

	//Pack data into packet
    rovecomm_packet.data_count = data_count;
    rovecomm_packet.data_id    = data_id;
    return rovecomm_packet;
  }

}// end namespace/////////////////////////////////////////////////////////////////////////////////////////////////
