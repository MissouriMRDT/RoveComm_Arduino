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
  struct _packet packPacket(const uint16_t data_id, const uint16_t data_count, const data_type_t data_type, const void* data)
  {
  //create a new _packet
  struct _packet packet;
    
  //Pack upd packt with header data
  packet.bytes[0] = ROVECOMM_VERSION;
  packet.bytes[1] = data_id  >> 8;
  packet.bytes[2] = data_id;
  packet.bytes[3] = data_count >> 8;
  packet.bytes[4] = data_count;
  packet.bytes[5] = data_type;
    
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

    } else if ( data_type == FLOAT )
    {
      //Convert data to float array
      float* data_float = (float*)data;
      uint16_t  index    = 0;
      for(int i=0; i < 4 * data_count; i+=4)
      { 
        union {
          float floatVal;
          unsigned char bytes[4];
        } convert;
        convert.floatVal = data_float[index];
        //Pack values into packet bytes
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i    ] = convert.bytes[3];
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 1] = convert.bytes[2];
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 2] = convert.bytes[1];
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 3] = convert.bytes[0];
        index++;
      }
    } else if ( data_type == DOUBLE )
    {
      //Convert data to double array
      double* data_double = (double*)data;
      uint16_t  index    = 0;
      for(int i=0; i < 8 * data_count; i+=8)
      { 
        union {
          double doubleVal;
          unsigned char bytes[8];
        } convert;
        convert.doubleVal = data_double[index];
        //Pack values into packet bytes
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i    ] = convert.bytes[7];
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 1] = convert.bytes[6];
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 2] = convert.bytes[5];
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 3] = convert.bytes[4];
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 4] = convert.bytes[3];
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 5] = convert.bytes[2];
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 6] = convert.bytes[1];
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 7] = convert.bytes[0];
        index++;
      }
    } else if ( data_type == CHAR )
    {
      //Convert data to char array
      char* data_char = (char*)data;
      for(int i=0; i < 1 * data_count; i+=1)
      { 
        //Pack values into packet bytes
        packet.bytes[ROVECOMM_PACKET_HEADER_SIZE + i]     = data_char[i];
      }
    } else // invalid => set data_count = 0
    { 
      struct _packet PACKET_INVALID = { 0 };
      return PACKET_INVALID; 
    } 
    return packet;
  }

  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  struct rovecomm_packet unpackPacket(uint8_t _packet_bytes[])
  {
    //for if we encounter an incompatible rovecomm message
    if(_packet_bytes[0] != ROVECOMM_VERSION)
    {
     struct rovecomm_packet invalid_version_packet = {0};
     invalid_version_packet.data_id = RC_ROVECOMM_INVALID_VERSION_DATA_ID;
     invalid_version_packet.data_count = 1;
     return invalid_version_packet;
    }

    //create new RoveComm packet
    struct rovecomm_packet rovecomm_packet = {0};
    //Unpack header
    uint16_t data_id   =(_packet_bytes[1] << 8)
                       | _packet_bytes[2];

    uint16_t data_count =(_packet_bytes[3] << 8)
                       | _packet_bytes[4];
    data_type_t data_type  =  (data_type_t)_packet_bytes[5];

    //Pack data into packet
    rovecomm_packet.data_count = data_count;
    rovecomm_packet.data_id    = data_id;
    rovecomm_packet.data_type = data_type;

    //Unpack data based on data_type
    if(data_type ==  INT32_T)
    { 
      for(int i = 0; i < data_count*4; i+=4)
      {
        rovecomm_packet.data[i] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 3];
        rovecomm_packet.data[i + 1] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 2];
        rovecomm_packet.data[i + 2] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 1];
        rovecomm_packet.data[i + 3] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i];
      }        
    } 
    else if(data_type ==  UINT32_T )
    { 
      for(int i = 0; i < data_count*4; i+=4)
      {
        rovecomm_packet.data[i] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 3];
        rovecomm_packet.data[i + 1] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 2];
        rovecomm_packet.data[i + 2] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 1];
        rovecomm_packet.data[i + 3] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i];
      }        
    } 
    else if(data_type ==  INT16_T)
    { 
      for(int i = 0; i < data_count*2; i+=2)
      {
        rovecomm_packet.data[i] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 1];
        rovecomm_packet.data[i + 1] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i];
      }
    }
    else if(data_type == UINT16_T)
    { 
      for(int i = 0; i < data_count*2; i+=2)
      {
        rovecomm_packet.data[i] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 1];
        rovecomm_packet.data[i + 1] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i];
      }
    } 
    else if(data_type ==  INT8_T )
    {
      for(int i = 0; i < data_count; i++)
      {
        rovecomm_packet.data[i] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i];
      }
    } 
    else if(data_type ==  UINT8_T )
    {
      for(int i = 0; i < data_count; i++)
      {
        rovecomm_packet.data[i] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i];
      }    
    } 
    else if(data_type ==  FLOAT )
    {
      for(int i = 0; i < data_count*4; i+=4)
      {
        rovecomm_packet.data[i] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 3];
        rovecomm_packet.data[i + 1] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 2];
        rovecomm_packet.data[i + 2] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 1];
        rovecomm_packet.data[i + 3] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i];
      }    
    } else if(data_type ==  DOUBLE )
    {
      for(int i = 0; i < data_count*8; i+=8)
      {
        rovecomm_packet.data[i] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 7];
        rovecomm_packet.data[i + 1] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 6];
        rovecomm_packet.data[i + 2] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 5];
        rovecomm_packet.data[i + 3] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 4];
        rovecomm_packet.data[i + 4] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 3];
        rovecomm_packet.data[i + 5] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 2];
        rovecomm_packet.data[i + 6] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i + 1];
        rovecomm_packet.data[i + 7] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i];
      }    
    } else if(data_type ==  CHAR )
    {
      for(int i = 0; i < data_count; i++)
      {
        rovecomm_packet.data[i] = _packet_bytes[ROVECOMM_PACKET_HEADER_SIZE + i];
      }    
    } 
    else
    { 
      data_count = 0; // invalid_data
    }
    
    return rovecomm_packet;
  }


  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  struct rovecomm_packet unpackPacket(EthernetClient client)
  {

    //array of bytes that form the header
    uint8_t header[ROVECOMM_PACKET_HEADER_SIZE];

    //read in the header (standard size of 5 bytes)
    for(uint8_t i = 0; i < ROVECOMM_PACKET_HEADER_SIZE; i++)
      {
      header[i] = client.read();
      }

    //for if we encounter an incompatible rovecomm message
    if(header[0] != ROVECOMM_VERSION)
      {
      struct rovecomm_packet invalid_version_packet = {0};
      invalid_version_packet.data_id = RC_ROVECOMM_INVALID_VERSION_DATA_ID;
      invalid_version_packet.data_count = 1;
      invalid_version_packet.data[1] = {0};
      return invalid_version_packet;
      }

    //create new RoveComm packet
    struct rovecomm_packet rovecomm_packet = {0};

    //Unpack header
    uint16_t data_id  = (header[1] << 8)
                       | header[2];
    uint16_t data_count = (header[3] << 8)
                       | header[4];
    data_type_t data_type  =  (data_type_t)header[5];

    //Unpack data based on data_type
    if(data_type ==  INT32_T)
    { 
      for ( int i=0; i < data_count*4; i+=4 )
        { 
          rovecomm_packet.data[i + 3] = client.read();
          rovecomm_packet.data[i + 2] = client.read();
          rovecomm_packet.data[i + 1] = client.read();
          rovecomm_packet.data[i] = client.read();        
        }
    }  
    else if(data_type ==  UINT32_T )
    { 
      for ( int i=0; i < data_count*4; i+=4)
        { 
          rovecomm_packet.data[i + 3] = client.read();
          rovecomm_packet.data[i + 2] = client.read();
          rovecomm_packet.data[i + 1] = client.read();
          rovecomm_packet.data[i] = client.read();   
        }
    } 
    else if(data_type ==  INT16_T)
    { 
     for  ( int i=0; i < data_count*2; i+=2 )
        { 
          rovecomm_packet.data[i + 1] = client.read();
          rovecomm_packet.data[i] = client.read();   
        }
    } 
    else if(data_type == UINT16_T)
    { 
      for ( int i=0; i < data_count*2; i+=2 )
        { 
          rovecomm_packet.data[i + 1] = client.read();
          rovecomm_packet.data[i] = client.read(); 
        }
    } 
    else if(data_type ==  INT8_T )
    {
      for ( int i=0; i < data_count; i++ )
        { 
          rovecomm_packet.data[i] = client.read(); 
        }
    } 
    else if(data_type ==  UINT8_T )
    {
      for ( int i=0; i < data_count; i++ )
        { 
          rovecomm_packet.data[i] = client.read(); 
        }
    } 
    else if(data_type == FLOAT )
    {
      for ( int i=0; i < data_count*4; i++ )
        { 
          rovecomm_packet.data[i + 3] = client.read();
          rovecomm_packet.data[i + 2] = client.read();
          rovecomm_packet.data[i + 1] = client.read();
          rovecomm_packet.data[i] = client.read();           
        }
    } else if(data_type == DOUBLE )
    {
      for ( int i=0; i < data_count*8; i++ )
        { 
          rovecomm_packet.data[i + 7] = client.read();
          rovecomm_packet.data[i + 6] = client.read();
          rovecomm_packet.data[i + 5] = client.read();
          rovecomm_packet.data[i + 4] = client.read();
          rovecomm_packet.data[i + 3] = client.read();
          rovecomm_packet.data[i + 2] = client.read();
          rovecomm_packet.data[i + 1] = client.read();
          rovecomm_packet.data[i] = client.read();           
        }
    } else if(data_type ==  CHAR )
    {
      for ( int i=0; i < data_count; i++ )
        { 
          rovecomm_packet.data[i] = client.read(); 
        }
    } 
    else
      { 
      data_count = 0; // invalid_data
      } 

    //Pack data into packet
    rovecomm_packet.data_count = data_count;
    rovecomm_packet.data_id    = data_id;
    return rovecomm_packet;
  }
}// end namespace/////////////////////////////////////////////////////////////////////////////////////////////////
