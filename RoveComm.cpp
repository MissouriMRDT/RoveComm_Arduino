/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MRDT => TivaC1294/TivaC129E Launchpad
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "RoveComm.h"
#include "RoveCommPacket.h"
#include "RoveCommManifest.h"

#include <Energia.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

///////////////////////////////////////////////////////////////////////
EthernetUDP EthernetUdp;

static uint8_t read_packet_byte_buff[  COUNT::MAX_DATA_BYTES ] = { 0 };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static void beginEthernetUdp(   uint8_t ip_1, uint8_t ip_2, uint8_t  ip_3, uint8_t ip_4, uint16_t port );

static void writeToEthernetUdp( uint8_t packet_bytes[],     size_t   packet_byte_count, 
                                uint8_t ip_1, uint8_t ip_2, uint8_t  ip_3, uint8_t ip_4, uint16_t port );

static IPAddress readFromEthernetUdp( size_t packet_byte_count_in, size_t* packet_byte_count_out, uint8_t* packet_byte_buff_out );

///////////////////////////////////////////////////////////////////////////////////////////////////
static void beginEthernetUdp( uint8_t ip_1, uint8_t ip_2, uint8_t  ip_3, uint8_t ip_4, uint16_t port )
{ 
  IPAddress LocalIp = IPAddress( ip_1, ip_2, ip_3, ip_4 );
  Ethernet.enableActivityLed();
  Ethernet.enableLinkLed(); 
  Ethernet.begin( 0, LocalIp );
  EthernetUdp.begin( port );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
static void writeToEthernetUdp(  uint8_t packet_bytes[],     size_t   packet_byte_count,
                                 uint8_t ip_1, uint8_t ip_2, uint8_t  ip_3, uint8_t ip_4, uint16_t port )
{ 
  IPAddress                RemoteIp =    IPAddress( ip_1, ip_2, ip_3, ip_4 );
  EthernetUdp.beginPacket( RemoteIp,     port );
  EthernetUdp.write(       packet_bytes, packet_byte_count );
  EthernetUdp.endPacket(); 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static IPAddress readFromEthernetUdp( size_t packet_byte_count_in, size_t* packet_byte_count_out, uint8_t* packet_byte_buff_out )
{ 
  size_t  packet_byte_count     = EthernetUdp.parsePacket();
  if (  ( packet_byte_count    <= 0 )
  ||    ( packet_byte_count    >  packet_byte_count_in ) ) 
  {      
         *packet_byte_count_out = 0;
          return INADDR_NONE; }
  else
  {      *packet_byte_count_out = EthernetUdp.read( packet_byte_buff_out, packet_byte_count );
          IPAddress RemoteIp    = EthernetUdp.remoteIP(); 
          return RemoteIp;
} }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommEthernet::begin(    uint8_t ip_4 )
{                this->begin(    SUBNET::IP_1, SUBNET::IP_2, SUBNET::IP_3, ip_4, PORT::ROVECOMM_ETHERNET_UDP ); }

void RoveCommEthernet::begin(    uint8_t ip_1, uint8_t ip_2, uint8_t ip_3, uint8_t ip_4, uint16_t port )
{                      beginEthernetUdp( ip_1,         ip_2,         ip_3,         ip_4,          port ); }

///////////////////////////////////////////////////////////////////////////////////////
void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  uint8_t  data )
{  uint8_t data_array[1] = { data }; 
   this->write( data_id, data_count, data_array );
}

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  uint16_t data )
{  uint16_t data_array[1] = { data }; 
   this->write( data_id, data_count, data_array );
}

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  uint32_t data )
{  uint32_t data_array[1] = { data }; 
   this->write( data_id, data_count, data_array );
}

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  int8_t   data )
{  int8_t data_array[1] = { data }; 
   this->write( data_id, data_count, data_array );
}

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  int16_t  data )
{  int16_t data_array[1] = { data }; 
   this->write( data_id, data_count, data_array );
}

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  int32_t  data )
{  int32_t data_array[1] = { data }; 
   this->write( data_id, data_count, data_array );
}

//////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  const uint8_t  data[] )
{ this->write( data_id, data_count, DATA_TYPE::UINT8_T, data ); }

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  const uint16_t data[] )
{ this->write( data_id, data_count, DATA_TYPE::UINT16_T, data ); }

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  const uint32_t data[] )
{ this->write( data_id, data_count, DATA_TYPE::UINT32_T, data ); }

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  const int8_t   data[] )
{ this->write( data_id, data_count, DATA_TYPE::INT8_T, data ); }

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  const int16_t  data[] )
{ this->write( data_id, data_count, DATA_TYPE::INT16_T, data ); }

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  const int32_t  data[] )
{ this->write( data_id, data_count, DATA_TYPE::INT32_T, data ); }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count, uint8_t data,  uint8_t ip_4 )
{  uint8_t data_array[1] = { data }; 
   this->write( data_id, data_count, data_array, ip_4 );
}

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count, uint16_t data, uint8_t ip_4 )
{  uint16_t data_array[1] = { data }; 
   this->write( data_id, data_count, data_array, ip_4 );
}

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count, uint32_t data, uint8_t ip_4 )
{  uint32_t data_array[1] = { data }; 
   this->write( data_id, data_count, data_array, ip_4 );
}

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count, int8_t   data, uint8_t ip_4 )
{  int8_t data_array[1] = { data }; 
   this->write( data_id, data_count, data_array, ip_4 );
}

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count, int16_t  data, uint8_t ip_4 )
{  int16_t data_array[1] = { data }; 
   this->write( data_id, data_count, data_array, ip_4 );
}

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count, int32_t  data,  uint8_t ip_4 )
{  int32_t data_array[1] = { data }; 
   this->write( data_id, data_count, data_array, ip_4 );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  const uint8_t  data[] , uint8_t ip_4 )
{ this->writeTo( data_id, data_count, DATA_TYPE::UINT8_T, data, ip_4 ); }

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  const uint16_t data[] , uint8_t ip_4 )
{ this->writeTo( data_id, data_count, DATA_TYPE::UINT16_T, data, ip_4 ); }

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  const uint32_t data[] , uint8_t ip_4 )
{ this->writeTo( data_id, data_count, DATA_TYPE::UINT32_T, data, ip_4 ); }

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  const int8_t   data[] , uint8_t ip_4 )
{ this->writeTo( data_id, data_count, DATA_TYPE::INT8_T, data, ip_4 ); }

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  const int16_t  data[] , uint8_t ip_4 )
{ this->writeTo( data_id, data_count, DATA_TYPE::INT16_T, data, ip_4 ); }

void RoveCommEthernet::write(   uint16_t data_id,  uint8_t data_count,  const int32_t  data[] , uint8_t ip_4 )
{ this->writeTo( data_id, data_count, DATA_TYPE::INT32_T, data, ip_4 ); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommEthernet::write( uint16_t data_id, uint8_t data_count, uint8_t data_type, const void* data )
{
  for ( int i=0; i < COUNT::MAX_SUBSCRIBER_IPS; i++ )
  { if ( this->RoveCommSubscriberIps[ i ] != INADDR_NONE )
    { this->writeTo( data_id, data_count, data_type, data, this->RoveCommSubscriberIps[ i ]  ); } 
} }

void RoveCommEthernet::writeTo( uint16_t data_id, uint8_t  data_count, uint8_t data_type, const void* data, uint8_t  ip_4 )
{  this->writeTo( data_id, data_count, data_type, data, SUBNET::IP_1, SUBNET::IP_2, SUBNET::IP_3, ip_4, PORT::ROVECOMM_ETHERNET_UDP ); }

void RoveCommEthernet::writeTo( uint16_t data_id, uint8_t data_count, uint8_t data_type, const void* data,  
                                uint8_t  ip_1,    uint8_t ip_2,       uint8_t ip_3,      uint8_t     ip_4,  uint16_t port )
{
  struct    roveware::PackedPacket  Packet = roveware::packPacket( data_id, data_count, data_type, data );
  writeToEthernetUdp( Packet.bytes, Packet.byte_count, ip_1, ip_2, ip_3, ip_4, port );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct RoveCommPacket RoveCommEthernet::read() 
{ 
  struct RoveCommPacket Packet;
  size_t    packet_byte_count = 0;
  IPAddress RemoteIp          = readFromEthernetUdp( COUNT::MAX_DATA_BYTES, &packet_byte_count, read_packet_byte_buff );

  if( packet_byte_count > 0 )
  { 
    Packet = roveware::unpackPacket( read_packet_byte_buff, RemoteIp[3] );

    //static bool toggle = false;
    //digitalWrite( high, toggle=!toggle );

    if(       Packet.data_id == ROVECOMM_PING_REQUEST.DATA_ID )
    {       /* this->writeTo(    ROVECOMM_PING_ACK.DATA_ID, sizeof(uint16_t), ?, RemoteIp[3] );*/ } // Todo

    else if ( Packet.data_id == ROVECOMM_SUBSCRIBE_REQUEST.DATA_ID )
    { for ( int i=0; i < COUNT::MAX_SUBSCRIBER_IPS; i++ ) 
      {      if ( this->RoveCommSubscriberIps[ i ] == RemoteIp  )  { /* already subscribed */                     break; }
        else if ( this->RoveCommSubscriberIps[ i ] == INADDR_NONE ){ this->RoveCommSubscriberIps[ i ] = RemoteIp; break; } }}

    else if ( Packet.data_id == ROVECOMM_UNSUBSCRIBE_REQUEST.DATA_ID )
    { for (   int i=0; i < COUNT::MAX_SUBSCRIBER_IPS; i++ )
      { if (  this->RoveCommSubscriberIps[ i ] == RemoteIp ){ this->RoveCommSubscriberIps[ i ] = INADDR_NONE; } }}
  }

  return Packet;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommAtlasEthernet::begin(             uint8_t ip_4 )
{                           beginEthernetUdp(  SUBNET::IP_1, SUBNET::IP_2, SUBNET::IP_3, ip_4, PORT::ROVECOMM_ETHERNET_UDP ); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommAtlasEthernet::write( uint16_t data_id, uint8_t  data_byte_count, const void* data )
{
  for ( int i=0; i < COUNT::MAX_SUBSCRIBER_IPS; i++ )
  { if ( this->RoveCommSubscriberIps[ i ] != INADDR_NONE )
    { this->writeTo( data_id,  data_byte_count, data, this->RoveCommSubscriberIps[ i ] ); } 
} }

void RoveCommAtlasEthernet::writeTo( uint16_t data_id, uint8_t  data_byte_count, const void* data, uint8_t  ip_4 )
{
  struct   roveware::atlas::PackedPacket Packet = roveware::atlas::packPacket( data_id, data_byte_count, (uint8_t*)data );
  writeToEthernetUdp( Packet.bytes, Packet.byte_count, SUBNET::IP_1, SUBNET::IP_2, SUBNET::IP_3, ip_4, PORT::ROVECOMM_ETHERNET_UDP );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct RoveCommAtlasPacket RoveCommAtlasEthernet::read() 
{ 
  struct RoveCommAtlasPacket Packet;
  size_t    packet_byte_count = 0;
  IPAddress RemoteIp          = readFromEthernetUdp( COUNT::MAX_DATA_BYTES, &packet_byte_count, read_packet_byte_buff );

  if( packet_byte_count > 0 )
  {
    Packet = roveware::atlas::unpackPacket( read_packet_byte_buff, RemoteIp[3] );

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if( (     Packet.flags & roveware::atlas::ROVECOMM_FLAGS_ACK_REQUEST ) != 0 )
    {         this->writeTo( roveware::atlas::ROVECOMM_FLAGS_ACK_REQUEST,  sizeof(uint16_t), &Packet.data_id,  RemoteIp[3] ); }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(       Packet.data_id == roveware::atlas::ROVECOMM_PING_REQUEST.DATA_ID )
    {         this->writeTo(    roveware::atlas::ROVECOMM_PING_ACK.DATA_ID, sizeof(uint16_t),  &Packet.sequence, RemoteIp[3] ); } 

    else if ( Packet.data_id == roveware::atlas::ROVECOMM_SUBSCRIBE_REQUEST.DATA_ID )
    { for ( int i=0; i < COUNT::MAX_SUBSCRIBER_IPS; i++ ) 
      {      if ( this->RoveCommSubscriberIps[ i ] == RemoteIp  )  { /* already subscribed */                     break; }
        else if ( this->RoveCommSubscriberIps[ i ] == INADDR_NONE ){ this->RoveCommSubscriberIps[ i ] = RemoteIp; break; } }}

    else if ( Packet.data_id == roveware::atlas::ROVECOMM_UNSUBSCRIBE_REQUEST.DATA_ID )
    { for (   int i=0; i < COUNT::MAX_SUBSCRIBER_IPS; i++ )
      { if (  this->RoveCommSubscriberIps[ i ] == RemoteIp ){ this->RoveCommSubscriberIps[ i ] = INADDR_NONE; } } }
  }

  return Packet; 
}