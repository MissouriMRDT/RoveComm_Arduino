#include "RoveCommEthernetTCP.h"
#include "RoveCommPacket.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
#include          <SPI.h>         // Energia/master/hardware/lm4f/libraries/SPI
#include          <Energia.h>
#include          <Ethernet.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommEthernetTCP::begin(EthernetServer *TServer, IPAddress IP)
{
    //Set IP
    Ethernet.enableActivityLed();
    Ethernet.enableLinkLed(); 

    //Set up Ethernet
    Ethernet.begin(   0, IP);

    //Set up server, and start listening for clients
    TCPServer = TServer;
    TCPServer->begin();
}

void RoveCommEthernetTCP::begin(EthernetServer *TServer)
{
    //Set up server, and start listening for clients
    TCPServer = TServer;
    TCPServer->begin();
}

struct rovecomm_packet RoveCommEthernetTCP::read() 
{ 
  //Create new RoveCommPacket
        Serial.println("Read something");

  rovecomm_packet packet = { 0 };
  //check if there is a message from client
  EthernetClient client = TCPServer->available();
  //if there is a message from the client and there is something to read
  if(client && client.peek() != -1)
    {
      Serial.println("Read something");
      packet = roveware::unpackPacket(client); 
    }
  //if there is no message, just return that there is no data to read
  else
    {
    packet.data_id = ROVECOMM_NO_DATA_DATA_ID;
    packet.data_count = 0;
    }
  
  //return the packet
  return packet;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommEthernetTCP::_writeReliable(EthernetServer *TServer, const uint8_t data_type_length, const roveware::data_type_t data_type, const uint16_t data_id, const uint8_t data_count, const void* data)
{ 
  //Creat packed udp packet
  struct roveware::_packet _packet = roveware::packPacket(data_id, data_count, data_type, data);

  //write to all available clients
  TServer->write( _packet.bytes, (ROVECOMM_PACKET_HEADER_SIZE + (data_type_length * data_count))); 
}

//Overloaded writeReliable////////////////////////////////////////////////////////////////////////////////////////////////////
//Single-value write
//handles the data->pointer conversion for user
void RoveCommEthernetTCP::writeReliable(        EthernetServer *TServer, const uint16_t  data_id, const uint8_t data_count, const  int32_t data )
{                  int32_t data_p[1];
                   data_p[0] = data;
                   _writeReliable( TServer, 4,  roveware::INT32_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetTCP::writeReliable(        EthernetServer *TServer, const uint16_t  data_id, const uint8_t data_count, const uint32_t data )
{                  uint32_t data_p[1];
                   data_p[0] = data;
                   _writeReliable( TServer, 4, roveware::UINT32_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetTCP::writeReliable(        EthernetServer *TServer, const uint16_t  data_id, const uint8_t data_count, const  int16_t data )
{                  int16_t data_p[1];
                   data_p[0] = data;
                   _writeReliable( TServer, 2,  roveware::INT16_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetTCP::writeReliable(        EthernetServer *TServer, const uint16_t  data_id, const uint8_t data_count, const uint16_t data )
{                  uint16_t data_p[1];
                   data_p[0] = data;
                   _writeReliable( TServer, 2, roveware::UINT16_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetTCP::writeReliable(         EthernetServer *TServer, const uint16_t data_id, const uint8_t data_count, const   int8_t data )
{                  int8_t data_p[1];
                   data_p[0] = data;
                   _writeReliable( TServer, 1,   roveware::INT8_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetTCP::writeReliable(        EthernetServer *TServer, const uint16_t  data_id, const uint8_t data_count, const  uint8_t data )
{                  uint8_t data_p[1];
                   data_p[0] = data;
                   _writeReliable( TServer, 1,  roveware::UINT8_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetTCP::writeReliable(        EthernetServer *TServer, const uint16_t  data_id, const uint8_t data_count, const  float data )
{                  float data_p[1];
                   data_p[0] = data;
                   _writeReliable( TServer, 4,  roveware::FLOAT, data_id,               data_count,        (void*) data_p ); }
//Array-Entry write///////////////////////////////////
void RoveCommEthernetTCP::writeReliable(        EthernetServer *TServer, const uint16_t  data_id, const uint8_t data_count, const  int32_t *data )
{                  _writeReliable( TServer, 4,  roveware::INT32_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetTCP::writeReliable(        EthernetServer *TServer, const uint16_t  data_id, const uint8_t data_count, const uint32_t *data )
{                  _writeReliable( TServer, 4, roveware::UINT32_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetTCP::writeReliable(        EthernetServer *TServer, const uint16_t  data_id, const uint8_t data_count, const  int16_t *data )
{                  _writeReliable( TServer, 2,  roveware::INT16_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetTCP::writeReliable(        EthernetServer *TServer, const uint16_t  data_id, const uint8_t data_count, const uint16_t *data )
{                  _writeReliable( TServer, 2, roveware::UINT16_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetTCP::writeReliable(        EthernetServer *TServer, const uint16_t data_id, const uint8_t data_count, const   int8_t *data )
{                  _writeReliable( TServer, 1,   roveware::INT8_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetTCP::writeReliable(        EthernetServer *TServer, const uint16_t  data_id, const uint8_t data_count, const  uint8_t *data )
{                  _writeReliable( TServer, 1,  roveware::UINT8_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetTCP::writeReliable(        EthernetServer *TServer, const uint16_t  data_id, const uint8_t data_count, const  float *data )
{                  _writeReliable( TServer, 4,  roveware::FLOAT, data_id,               data_count,        (void*) data ); }