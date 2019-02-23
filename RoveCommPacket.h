/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MRDT => TivaC1294/TivaC129E Launchpad
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ROVECOMM_PACKET_H
#define ROVECOMM_PACKET_H

#include "RoveCommManifest.h"

#include <Energia.h> 
#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

#include <stdint.h>
#include <stddef.h>

struct RoveCommPacket ////////////////////////////////////////////////////////////
{ 
  int      data_id                                     =   ROVECOMM_NO_RX.DATA_ID;
  int      data_count                                  =   0;
  int      data[ sizeof(int) * COUNT::MAX_DATA_BYTES ] = { 0 };
  uint8_t  data_type                                   =   0; 
  uint8_t  remote_ip                                   =   0;
  uint8_t  version                                     =   0; };

struct RoveCommAtlasPacket ////////////////////////////////////////////////////////////////
{ 
  uint16_t data_id                             =   roveware::atlas::ROVECOMM_NO_RX.DATA_ID;
  uint16_t data_byte_count                     =   0;
  uint8_t  data_bytes[ COUNT::MAX_DATA_BYTES ] = { 0 };
  uint8_t  remote_ip                           =   0;
  uint8_t  version                             =   0;
  uint8_t  flags                               =   0;
  uint16_t sequence                            =   0; 
};

namespace roveware //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
  struct PackedPacket //////////////////////////////////////////////////////
  { 
    size_t  byte_count = 0;
    uint8_t bytes[ COUNT::MAX_HEADER_BYTES + COUNT::MAX_DATA_BYTES ] = { 0 }; 
  };

  struct PackedPacket   packPacket(         uint16_t data_id,        uint8_t data_count, uint8_t data_type, const void* data );
  struct RoveCommPacket unpackPacket( const uint8_t  packet_bytes[], uint8_t remote_ip );

  namespace atlas ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  {
    struct PackedPacket /////////////////////////////////////////////////////////////////////
    { 
      size_t  byte_count = 0;
      uint8_t bytes[ atlas::COUNT::MAX_HEADER_BYTES + atlas::COUNT::MAX_DATA_BYTES ] = { 0 }; 
    };

    struct PackedPacket        packPacket(         uint16_t data_id,       uint16_t data_byte_count, const uint8_t data_bytes[] );
    struct RoveCommAtlasPacket unpackPacket( const uint8_t  packet_bytes[], uint8_t remote_ip );

  } // end namespace
} //   end namespace

#endif // ROVECOMM_PACKET_H