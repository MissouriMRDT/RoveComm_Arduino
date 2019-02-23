/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MRDT => TivaC1294/TivaC129E Launchpad
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "RoveCommPacket.h"
#include "RoveCommManifest.h"

#include <Energia.h>

#include <stdint.h>
#include <stddef.h>

namespace roveware //////////////////////////////////////////////////////////////////////////////////////////
{ 
  struct PackedPacket packPacket( uint16_t data_id, uint8_t data_count, uint8_t data_type, const void* data )
  {
    struct PackedPacket Packet;
    Packet.bytes[ 0 ] = ROVECOMM_VERSION;
    Packet.bytes[ 1 ] = data_id  >> 8;
    Packet.bytes[ 2 ] = data_id;
    Packet.bytes[ 3 ] = data_count;
    Packet.bytes[ 4 ] = data_type;
    Packet.byte_count = COUNT::MAX_HEADER_BYTES;

    if((        data_type == DATA_TYPE::INT8_T  )
    || (        data_type == DATA_TYPE::UINT8_T )
    || (        data_type == DATA_TYPE::BOOL_T ))
    { uint8_t*  data_8t = (uint8_t*)data;
      for(int i=0; i < 1 * data_count; i+=1)
      { Packet.bytes[ COUNT::MAX_HEADER_BYTES + i ]     = data_8t[ i ];
        Packet.byte_count += 1; } }

    else if(  ( data_type == DATA_TYPE::INT16_T  )
           || ( data_type == DATA_TYPE::UINT16_T ))
    { uint16_t* data_16t = (uint16_t*)data;
      uint16_t  index    = 0;
      for( int i=0; i < 2 * data_count; i+=2 )
      { Packet.bytes[ COUNT::MAX_HEADER_BYTES + i     ] = data_16t[ index ] >> 8;
        Packet.bytes[ COUNT::MAX_HEADER_BYTES + i + 1 ] = data_16t[ index ];
        Packet.byte_count += 2;
        index++; } }

    else if(  ( data_type == DATA_TYPE::INT32_T ) 
           || ( data_type == DATA_TYPE::UINT32_T)
           || ( data_type == DATA_TYPE::FLOAT_T))
    { uint32_t* data_32t = (uint32_t*)data;
      uint16_t  index    = 0;
      for( int i=0; i < 4 * data_count; i+=4 )
      { Packet.bytes[ COUNT::MAX_HEADER_BYTES + i     ] = data_32t[ index ] >> 24;
        Packet.bytes[ COUNT::MAX_HEADER_BYTES + i + 1 ] = data_32t[ index ] >> 16;
        Packet.bytes[ COUNT::MAX_HEADER_BYTES + i + 2 ] = data_32t[ index ] >> 8;
        Packet.bytes[ COUNT::MAX_HEADER_BYTES + i + 3 ] = data_32t[ index ];
        Packet.byte_count += 4;
        index++; } }

    return Packet;
  }

  /////////////////////////////////////////////////////////////////////////////////////
  struct RoveCommPacket unpackPacket( const uint8_t packet_bytes[], uint8_t remote_ip ) 
  {
    struct RoveCommPacket Packet;
    Packet.version               = packet_bytes[0];
    if( Packet.version          == ROVECOMM_VERSION )
    { 
      Packet.remote_ip           = remote_ip;
      Packet.data_id             = ( packet_bytes[ 1 ] << 8 )
                                 |   packet_bytes[ 2 ];
      Packet.data_count          =   packet_bytes[ 3 ];
      Packet.data_type           =   packet_bytes[ 4 ];

      if( Packet.data_type      ==  DATA_TYPE::INT8_T )
      { for( int i=0;          i < 1*Packet.data_count; i+=1 )
        { int8_t data            = packet_bytes[ COUNT::MAX_HEADER_BYTES + i];
          Packet.data[i]         = data; } } 

      else if( Packet.data_type ==  DATA_TYPE::UINT8_T )
      { for( int i=0;          i < 1*Packet.data_count; i+=1 )
        { uint8_t data           = packet_bytes[ COUNT::MAX_HEADER_BYTES + i];
          Packet.data[i]         = data; } } 

      else if( Packet.data_type ==  DATA_TYPE::INT16_T)
      { uint16_t  index          = 0;
        for( int i=0;          i < 2*Packet.data_count; i+=2 )
        { int16_t data           = ( packet_bytes[ COUNT::MAX_HEADER_BYTES + i    ] << 8)
                                 |   packet_bytes[ COUNT::MAX_HEADER_BYTES + i + 1];
          Packet.data[ index ]   = data;
          index++; } } 

      else if( Packet.data_type == DATA_TYPE::UINT16_T )
      { uint16_t  index          = 0;
        for( int i=0;          i < 2*Packet.data_count; i+=2 )
        { uint16_t data          = ( packet_bytes[ COUNT::MAX_HEADER_BYTES + i    ] << 8)
                                 |   packet_bytes[ COUNT::MAX_HEADER_BYTES + i + 1];
          Packet.data[index]     = data;
          index++; } } 

      else if( Packet.data_type == DATA_TYPE::INT32_T )
      { uint16_t index           = 0;
        for(int i=0;           i < 4*Packet.data_count; i+=4 )
        { int32_t data           = ( packet_bytes[ COUNT::MAX_HEADER_BYTES + i     ] << 24)
                                 | ( packet_bytes[ COUNT::MAX_HEADER_BYTES + i + 1 ] << 16)
                                 | ( packet_bytes[ COUNT::MAX_HEADER_BYTES + i + 2 ] << 8)
                                 |   packet_bytes[ COUNT::MAX_HEADER_BYTES + i + 3 ];
          Packet.data[index]     = data;
          index++; } }

      else if( Packet.data_type == DATA_TYPE::UINT32_T )
      { uint16_t index           = 0;
        for(int i=0;           i < 4*Packet.data_count; i+=4 )
        { uint32_t data          = ( packet_bytes[ COUNT::MAX_HEADER_BYTES + i     ] << 24)
                          | ( packet_bytes[ COUNT::MAX_HEADER_BYTES + i + 1 ] << 16)
                          | ( packet_bytes[ COUNT::MAX_HEADER_BYTES + i + 2 ] << 8)
                          |   packet_bytes[ COUNT::MAX_HEADER_BYTES + i + 3 ];
          Packet.data[index] = data;
          index++; } } 

      else if( Packet.data_type == DATA_TYPE::FLOAT_T )
      { uint16_t index    = 0;
        for(int i=0;    i < 4*Packet.data_count; i+=4 )
        { float data      = ( packet_bytes[ COUNT::MAX_HEADER_BYTES + i     ] << 24)
                          | ( packet_bytes[ COUNT::MAX_HEADER_BYTES + i + 1 ] << 16)
                          | ( packet_bytes[ COUNT::MAX_HEADER_BYTES + i + 2 ] << 8)
                          |   packet_bytes[ COUNT::MAX_HEADER_BYTES + i + 3 ];
          Packet.data[index] = data;
          index++; } }

      else if( Packet.data_type ==  DATA_TYPE::BOOL_T )
      { for( int i=0; i   < 1*Packet.data_count; i+=1 )
        { bool data       = packet_bytes[ COUNT::MAX_HEADER_BYTES + i];
          Packet.data[i]  = data; } }
    }

    return Packet;
  }

  namespace atlas ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  {
    struct PackedPacket packPacket( uint16_t data_id, uint16_t data_byte_count, const uint8_t data_bytes[] )
    {
      struct PackedPacket       Packet;
      Packet.bytes[ 0 ]       = atlas::ROVECOMM_VERSION;   // RoveComm version 1 for all AtlasBoards
      Packet.bytes[ 1 ]       = 0x00FF          >>      8; // sequence number was hardcoded to 255 (unused) for AtlasBoard's write
      Packet.bytes[ 2 ]       = 0x00FF          &  0x00FF; // sequence number was hardcoded to 255 (unused) for AtlasBoard's write
      Packet.bytes[ 3 ]       = 0x00;                      // flags           was hardcoded to 0   (unused) for AtlasBoard's write
      Packet.bytes[ 4 ]       = data_id         >>      8;
      Packet.bytes[ 5 ]       = data_id         &  0x00FF;
      Packet.bytes[ 6 ]       = data_byte_count >>      8;
      Packet.bytes[ 7 ]       = data_byte_count &  0x00FF;

      for( int i=0;       i   < data_byte_count; i++ )
      { Packet.bytes[ 8 + i ] = data_bytes[ i ]; }

      Packet.byte_count       = atlas::COUNT::MAX_HEADER_BYTES + data_byte_count; 

      return Packet;
    }

    //////////////////////////////////////////////////////////////////////////////////////////
    struct RoveCommAtlasPacket unpackPacket( const uint8_t packet_bytes[], uint8_t remote_ip )
    {
      struct RoveCommAtlasPacket Packet;
      if( packet_bytes[0]        == atlas::ROVECOMM_VERSION )
      { Packet.remote_ip          =   remote_ip;
        Packet.version            =   packet_bytes[ 0 ];
        Packet.sequence           = ( packet_bytes[ 1 ] << 8 ) 
                                  |   packet_bytes[ 2 ];
        Packet.flags              =   packet_bytes[ 3 ];
        Packet.data_id            = ( packet_bytes[ 4 ] << 8 ) 
                                  |   packet_bytes[ 5 ];
        Packet.data_byte_count    = ( packet_bytes[ 6 ] << 8 )
                                  |   packet_bytes[ 7 ];

        for( int i=0;        i    <   Packet.data_byte_count; i++ )
        { Packet.data_bytes[ i ]  =   packet_bytes[ 8 + i ]; } }

      return Packet;
    }
  } // end namespace
} //   end namespace

