#include "RoveCommEthernetTCP.h"
#include "RoveCommPacket.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined(ENERGIA)
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

#elif defined(ARDUINO) && (ARDUINO>100)
#define MAX_CLIENTS   8
void RoveCommEthernetTCP::begin(EthernetServer *TServer, IPAddress IP)
{
    //Set IP
    Ethernet.hardwareStatus();
    Ethernet.linkStatus();
    //Set up Ethernet
    Ethernet.begin(   IP, IP); // The 4th octet is used as the MAC address for the Teensy to avoid confusion
    //Set up server, and start listening for clients
    TCPServer = TServer;
    TCPServer->begin();
}
#endif

void RoveCommEthernetTCP::begin(EthernetServer *TServer)
{
    //Set up server, and start listening for clients
    TCPServer = TServer;
    TCPServer->begin();
}

struct rovecomm_packet RoveCommEthernetTCP::read() 
{ 
  //Create new RoveCommPacket
  rovecomm_packet packet = { 0 };

  //the Ethernet Server class avalaible() function returns clients within its array in a round-robin fashion
  //however there is no guarantee that the client returned has data to be read, therefore we do a full
  //circuit of the array and stop at the client that has data to be returned.

  for(uint8_t i = 0; i < MAX_CLIENTS; i++) 
  {
    EthernetClient client = TCPServer->available();

    if(client.available() > 0) 
    {
      packet = roveware::unpackPacket(client);
      return packet;
    }
  }
  
  //return an empty packet
  packet.data_id = RC_ROVECOMM_NO_DATA_DATA_ID;
  packet.data_count = 0;
  return packet;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommEthernetTCP::_writeReliable(const uint8_t data_type_length, const roveware::data_type_t data_type, const uint16_t data_id, const uint16_t data_count, const void* data)
{ 
  //Creat packed udp packet
  struct roveware::_packet _packet = roveware::packPacket(data_id, data_count, data_type, data);

  //write to all available clients
  TCPServer->write( _packet.bytes, (ROVECOMM_PACKET_HEADER_SIZE + (data_type_length * data_count))); 
}

//Overloaded writeReliable////////////////////////////////////////////////////////////////////////////////////////////////////
//Single-value write
//handles the data->pointer conversion for user
void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const  int32_t data )
{                  int32_t data_p[1];
                   data_p[0] = data;
                   _writeReliable(  4,  roveware::INT32_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const uint32_t data )
{                  uint32_t data_p[1];
                   data_p[0] = data;
                   _writeReliable(  4, roveware::UINT32_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const  int16_t data )
{                  int16_t data_p[1];
                   data_p[0] = data;
                   _writeReliable(  2,  roveware::INT16_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const uint16_t data )
{                  uint16_t data_p[1];
                   data_p[0] = data;
                   _writeReliable(  2, roveware::UINT16_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetTCP::writeReliable(         const uint16_t data_id, const uint16_t data_count, const   int8_t data )
{                  int8_t data_p[1];
                   data_p[0] = data;
                   _writeReliable(  1,   roveware::INT8_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const  uint8_t data )
{                  uint8_t data_p[1];
                   data_p[0] = data;
                   _writeReliable(  1,  roveware::UINT8_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const  float data )
{                  float data_p[1];
                   data_p[0] = data;
                   _writeReliable(  4,  roveware::FLOAT, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const  double data )
{                  double data_p[1];
                   data_p[0] = data;
                   _writeReliable(  8,  roveware::DOUBLE, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const  char data )
{                  char data_p[1];
                   data_p[0] = data;
                   _writeReliable(  1,  roveware::CHAR, data_id,               data_count,        (void*) data_p ); }
//Array-Entry write///////////////////////////////////
void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const  int32_t *data )
{                  _writeReliable(  4,  roveware::INT32_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const uint32_t *data )
{                  _writeReliable(  4, roveware::UINT32_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const  int16_t *data )
{                  _writeReliable(  2,  roveware::INT16_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const uint16_t *data )
{                  _writeReliable(  2, roveware::UINT16_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetTCP::writeReliable(        const uint16_t data_id, const uint16_t data_count, const   int8_t *data )
{                  _writeReliable(  1,   roveware::INT8_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const  uint8_t *data )
{                  _writeReliable(  1,  roveware::UINT8_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const  float *data )
{                  _writeReliable(  4,  roveware::FLOAT, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const  double *data )
{                  _writeReliable(  8,  roveware::DOUBLE, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetTCP::writeReliable(        const uint16_t  data_id, const uint16_t data_count, const  char *data )
{                  _writeReliable(  1,  roveware::CHAR, data_id,               data_count,        (void*) data ); }