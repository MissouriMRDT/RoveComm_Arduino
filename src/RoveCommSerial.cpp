#include "RoveCommSerial.h"
#include "RoveCommPacket.h"

/////////////////////////////
#include "RoveCommManifest.h"
#include "RoveCommPacket.h"

#include <Energia.h>

////////////////////////////////////////////
uint8_t crc7(uint8_t *buffer, uint8_t size)
{
  uint8_t crc_7 = 0;
  uint8_t i    = 0;
  uint8_t j    = 0;

  for (i = 0; i < size; i++)
  { 
    crc_7 = crc_7 ^ (buffer[i] & 0xFF);
    for (j = 0; j < 8; j++)
    {  
      if (crc_7 & 0x01) 
      { 
        crc_7 = crc_7 ^ 0x91; 
      } 
      crc_7 = crc_7 >> 1; 
    } 
  } 
  return crc_7;
}

//Pass a pointer to an Energia::HardwareSerial instance on hardware/lm4f/cores/lm4f/HardwareSerial.cpp
void RoveCommSerial::begin(HardwareSerial *SerialPtr, int baud) 
{
  this->_Serial = SerialPtr;
  this->_Serial->begin(baud);
  delay(10);
}

//////////////////////////////////////////
bool RoveCommSerial::available() 
{
  return (this->_Serial->available() != 0);
}

////////////////////////////////////////////////////////////
struct   rovecomm_packet  RoveCommSerial::read()
{ 
  struct rovecomm_packet  rovecomm_packet = { 0 };
  uint8_t                 packet_bytes[255];
  
  for(int i=0; i < sizeof(packet_bytes); i++ ) 
  { 
    if(                 this->_Serial->available() ) 
    {        
      packet_bytes[i] = this->_Serial->read();
    } else if ( i > 0 ) 
    { 
      uint8_t read_crc_7 =      packet_bytes  [i-1];
      uint8_t calc_crc_7 = crc7(packet_bytes, (i-1));
            
      if( read_crc_7 == calc_crc_7 ) 
      { 
        rovecomm_packet = roveware::unpackUdpPacket(packet_bytes); 
      }
      break; 
    } else 
    {   
      break; 
    }
  }
  return rovecomm_packet;
}

// Overloaded write handles the data->pointer conversion for user ////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommSerial::_write(const uint8_t data_type_length, const roveware::data_type_t data_type, const uint16_t data_id, const uint8_t data_count, const void* data)
{ 
  struct  roveware::udp_packet packet = roveware::packUdpPacket(data_id, data_count, data_type, data);
  int     packet_length               = ROVECOMM_PACKET_HEADER_SIZE + data_type_length * data_count;
  uint8_t crc_7[1]                    = { crc7(packet.bytes, packet_length) };
  this->_Serial->write(packet.bytes, packet_length);
  this->_Serial->write(crc_7,        1);
}

// Single-value write ////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommSerial::write(        const int  data_id, const int data_count, const           int data )
{                  int  data_p[1];
                   data_p[0] = data;
                   this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data_p ); }
                   
void RoveCommSerial::write(        const uint16_t  data_id, const uint8_t data_count, const  int32_t data )
{                  int32_t data_p[1];
                   data_p[0] = data;
                   this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommSerial::write(        const uint16_t  data_id, const uint8_t data_count, const  int16_t data )
{                  int16_t data_p[1];
                   data_p[0] = data;
                   this->_write( 2,  roveware::INT16_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommSerial::write(        const uint16_t  data_id, const uint8_t data_count, const uint16_t data )
{                  uint16_t data_p[1];
                   data_p[0] = data;
                   this->_write( 2, roveware::UINT16_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommSerial::write(         const uint16_t data_id, const uint8_t data_count, const   int8_t data )
{                  int8_t data_p[1];
                   data_p[0] = data;
                   this->_write( 1,   roveware::INT8_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommSerial::write(        const uint16_t  data_id, const uint8_t data_count, const  uint8_t data )
{                  uint8_t data_p[1];
                   data_p[0] = data;
                   this->_write( 1,  roveware::UINT8_T, data_id,               data_count,        (void*) data_p ); }

// Array-Entry write //////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommSerial::write(        const int  data_id, const int data_count, const  int *data )
{                  this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data ); }

void RoveCommSerial::write(        const uint16_t  data_id, const uint8_t data_count, const  int32_t *data )
{                  this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data ); }

void RoveCommSerial::write(        const uint16_t  data_id, const uint8_t data_count, const  int16_t *data )
{                  this->_write( 2,  roveware::INT16_T, data_id,               data_count,        (void*) data ); }

void RoveCommSerial::write(        const uint16_t  data_id, const uint8_t data_count, const uint16_t *data )
{                  this->_write( 2, roveware::UINT16_T, data_id,               data_count,        (void*) data ); }

void RoveCommSerial::write(         const uint16_t data_id, const uint8_t data_count, const   int8_t *data )
{                  this->_write( 1,   roveware::INT8_T, data_id,               data_count,        (void*) data ); }

void RoveCommSerial::write(        const uint16_t  data_id, const uint8_t data_count, const  uint8_t *data )
{                  this->_write( 1,  roveware::UINT8_T, data_id,               data_count,        (void*) data ); }
