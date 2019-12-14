#include "RoveCommWifiUdp.h"
#include "RoveCommPacket.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
#include          <SPI.h>         // Energia/master/hardware/lm4f/libraries/SPI
#include          <Energia.h>
#include          <WiFiUdp.h>     

WiFiUDP           WifiUdp;
IPAddress RoveComm_WifiUdpSubscriberIps[ROVECOMM_WIFI_UDP_MAX_SUBSCRIBERS] = { INADDR_NONE };

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommWifiUdp::begin(const int board_ip_octet) 
{
  //begin using default IP Address
  this->begin(RC_ROVECOMM_SUBNET_IP_FIRST_OCTET, RC_ROVECOMM_SUBNET_IP_SECOND_OCTET, RC_ROVECOMM_SUBNET_IP_THIRD_OCTET, (uint8_t)board_ip_octet);
}
void RoveCommWifiUdp::begin()
{ 
  WifiUdp.begin(RC_ROVECOMM_WIFI_UDP_PORT); 
  delay(1);
}

/////////////////////////////////////////////////////////////////////////////////
struct rovecomm_packet RoveCommWifiUdp::read() 
{ 
  //Create new RoveCommPacket
  struct rovecomm_packet rovecomm_packet = { 0 };

  //Todo: Why don't we pass these directly into the rovecomm_packet we just made?
  uint16_t data_id    =  0;
  roveware::data_type_t data_type;
  uint8_t data_count =  0;
   
  int packet_size = WifiUdp.parsePacket();
  //Serial.println(packet_size);
  if (packet_size > 0)
  {       
	//Create arreay to take packet
    uint8_t _packet[ packet_size];

	//Read packet and get IP
    WifiUdp.read(_packet, packet_size);
    IPAddress ReadFromIp = WifiUdp.remoteIP();

	//Unpack RoveComm Packet
    rovecomm_packet = roveware::unpackPacket(_packet); 
    
	//Parse special data_ids/////////////////////////////////////////////////////////
	//Subscribe Request
    if (rovecomm_packet.data_id == RC_ROVECOMM_SUBSCRIBE_REQUEST_DATA_ID)
    {
      for (int i=0; i < ROVECOMM_WIFI_UDP_MAX_SUBSCRIBERS; i++) 
      {
		//Break if already subscribed
        if (RoveComm_WifiUdpSubscriberIps[i] == ReadFromIp) 
        {
          break;
        } 
		//Add if not subscribed
		else if (RoveComm_WifiUdpSubscriberIps[i] == INADDR_NONE) 
        {
          RoveComm_WifiUdpSubscriberIps[i]  = ReadFromIp;
          break;
        }
      }
    } 
	//Unsubscribe Request
	else if (rovecomm_packet.data_id == RC_ROVECOMM_UNSUBSCRIBE_REQUEST_DATA_ID)
    {
      for (int i=0; i < ROVECOMM_WIFI_UDP_MAX_SUBSCRIBERS; i++)
      {
		//Remove from subscriber list
        if (RoveComm_WifiUdpSubscriberIps[i] == ReadFromIp)
        {
          RoveComm_WifiUdpSubscriberIps[i]  = INADDR_NONE; // remove subscriber
        }
      }
    }  
  else if (rovecomm_packet.data_id == RC_ROVECOMM_PING_DATA_ID)
    {
      uint8_t data_p[1];
      data_p[0] = 1;
      this->_writeTo( 1,  roveware::UINT8_T, RC_ROVECOMM_PING_REPLY_DATA_ID, 1, (void*) data_p, ReadFromIp, RC_ROVECOMM_WIFI_UDP_PORT);
    }  
  }
  //return the packet
  return rovecomm_packet;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommWifiUdp::_write(const uint8_t data_type_length, const roveware::data_type_t data_type, const uint16_t data_id, const uint8_t data_count, const void* data)
{ 
  //Creat packed udp packet
  struct roveware::_packet _packet = roveware::packPacket(data_id, data_count, data_type, data);
  
  //Send packet to everyone in subscribers
  for (int i=0; i < ROVECOMM_WIFI_UDP_MAX_SUBSCRIBERS; i++)
  {
    if (RoveComm_WifiUdpSubscriberIps[i] != INADDR_NONE)
    {       
      WifiUdp.beginPacket(RoveComm_WifiUdpSubscriberIps[i], RC_ROVECOMM_WIFI_UDP_PORT);
      WifiUdp.write(      _packet.bytes, (ROVECOMM_PACKET_HEADER_SIZE + (data_type_length * data_count))); 
      WifiUdp.endPacket();
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommWifiUdp::_writeTo(const uint8_t data_type_length, const roveware::data_type_t data_type, const uint16_t data_id, const uint8_t data_count, const void* data,
                                   const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port) 
{ 
  //create packed udp packet
  struct roveware::_packet _packet = roveware::packPacket(data_id, data_count, data_type, data);
  
  //Set up IP
  IPAddress WriteToIp(ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4);
  
  //Write to that IP
  WifiUdp.beginPacket(WriteToIp, port);
  WifiUdp.write(      _packet.bytes, (ROVECOMM_PACKET_HEADER_SIZE + (data_type_length * data_count)));
  WifiUdp.endPacket(); 
}

void RoveCommWifiUdp::_writeTo(const uint8_t  data_type_length, const roveware::data_type_t data_type,
                  const uint16_t data_id,    const uint8_t data_count, const void* data,
                  IPAddress ipaddress, const uint16_t port)
{
  //create packed udp packet
  struct roveware::_packet _packet = roveware::packPacket(data_id, data_count, data_type, data);
  
  //Write to that IP
  WifiUdp.beginPacket(ipaddress, port);
  WifiUdp.write(      _packet.bytes, (ROVECOMM_PACKET_HEADER_SIZE + (data_type_length * data_count)));
  WifiUdp.endPacket(); 
}
//Overloaded write////////////////////////////////////////////////////////////////////////////////////////////////////
//Single-value write
//handles the data->pointer conversion for user
//void RoveCommWifiUdp::write(        const  uint16_t      data_id, const  int    data_count, const  int     data ) 
//{                  int data_p[1];
//                   data_p[0] = data;
//                   this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data_p ); }
//
void RoveCommWifiUdp::write(        const uint16_t  data_id, const uint8_t data_count, const  int32_t data )
{                  int32_t data_p[1];
                   data_p[0] = data;
                   this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommWifiUdp::write(        const uint16_t  data_id, const uint8_t data_count, const uint32_t data )
{                  uint32_t data_p[1];
                   data_p[0] = data;
                   this->_write( 4, roveware::UINT32_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommWifiUdp::write(        const uint16_t  data_id, const uint8_t data_count, const  int16_t data )
{                  int16_t data_p[1];
                   data_p[0] = data;
                   this->_write( 2,  roveware::INT16_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommWifiUdp::write(        const uint16_t  data_id, const uint8_t data_count, const uint16_t data )
{                  uint16_t data_p[1];
                   data_p[0] = data;
                   this->_write( 2, roveware::UINT16_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommWifiUdp::write(         const uint16_t data_id, const uint8_t data_count, const   int8_t data )
{                  int8_t data_p[1];
                   data_p[0] = data;
                   this->_write( 1,   roveware::INT8_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommWifiUdp::write(        const uint16_t  data_id, const uint8_t data_count, const  uint8_t data )
{                  uint8_t data_p[1];
                   data_p[0] = data;
                   this->_write( 1,  roveware::UINT8_T, data_id,               data_count,        (void*) data_p ); }
//Array-Entry write///////////////////////////////////
//void RoveCommWifiUdp::write(        const  int      data_id, const  int    data_count, const  int     *data ) 
//{                  this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data ); }
//
void RoveCommWifiUdp::write(        const uint16_t  data_id, const uint8_t data_count, const  int32_t *data )
{                  this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data ); }

void RoveCommWifiUdp::write(        const uint16_t  data_id, const uint8_t data_count, const uint32_t *data )
{                  this->_write( 4, roveware::UINT32_T, data_id,               data_count,        (void*) data ); }

void RoveCommWifiUdp::write(        const uint16_t  data_id, const uint8_t data_count, const  int16_t *data )
{                  this->_write( 2,  roveware::INT16_T, data_id,               data_count,        (void*) data ); }

void RoveCommWifiUdp::write(        const uint16_t  data_id, const uint8_t data_count, const uint16_t *data )
{                  this->_write( 2, roveware::UINT16_T, data_id,               data_count,        (void*) data ); }

void RoveCommWifiUdp::write(         const uint16_t data_id, const uint8_t data_count, const   int8_t *data )
{                  this->_write( 1,   roveware::INT8_T, data_id,               data_count,        (void*) data ); }

void RoveCommWifiUdp::write(        const uint16_t  data_id, const uint8_t data_count, const  uint8_t *data )
{                  this->_write( 1,  roveware::UINT8_T, data_id,               data_count,        (void*) data ); }
//Overloaded writeTo//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Single-value writeTo
//handles the data->pointer conversion for user
void RoveCommWifiUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int data,
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  int data_p[1];
                   data_p[0] = data;
                   this->_writeTo( 4,  roveware::INT32_T, data_id,                  data_count,       (void*) data_p,
                                                          ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, port ); }
void RoveCommWifiUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int32_t data, //handling data->pointer conversion for user
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  int32_t data_p[1];
                   data_p[0] = data;
                   this->_writeTo( 4,  roveware::INT32_T, data_id,                  data_count,       (void*) data_p,
                                                          ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, port ); }
void RoveCommWifiUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint32_t data,
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t  ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  uint32_t data_p[1];
                   data_p[0] = data;
                   this->_writeTo( 4, roveware::UINT32_T, data_id,                  data_count,        (void*) data_p,
                                                          ip_octet_1, ip_octet_2,   ip_octet_3,ip_octet_4, port ); }
void RoveCommWifiUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int16_t data,
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  int16_t data_p[1];
                   data_p[0] = data;
                   this->_writeTo( 2,  roveware::INT16_T, data_id,                 data_count,        (void*) data_p,
                                                          ip_octet_1, ip_octet_2,  ip_octet_3,  ip_octet_4,   port ); }
void RoveCommWifiUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint16_t data,
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t  ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  uint16_t data_p[1];
                   data_p[0] = data;
                   this->_writeTo( 2, roveware::UINT16_T, data_id,                  data_count,        (void*) data_p,
                                                          ip_octet_1, ip_octet_2,   ip_octet_3, ip_octet_4,    port ); }
void RoveCommWifiUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int8_t  data, 
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  int8_t data_p[1];
                   data_p[0] = data;
                   this->_writeTo( 1,  roveware::INT8_T,  data_id,                  data_count,       (void*) data_p, 
                                                          ip_octet_1, ip_octet_2,   ip_octet_3, ip_octet_4,   port ); }

void RoveCommWifiUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint8_t data,
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  uint8_t data_p[1];
                   data_p[0] = data;
                   this->_writeTo( 1,  roveware::UINT8_T, data_id,                  data_count,       (void*) data_p,
ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, port ); }
//Array-entry writeTo
//handles the data->pointer conversion for user
void RoveCommWifiUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int *data, //handling data->pointer conversion for user
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  this->_writeTo( 4,  roveware::INT32_T, data_id,                  data_count,       (void*) data,
                                                          ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, port ); }
void RoveCommWifiUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int32_t *data,
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  this->_writeTo( 4,  roveware::INT32_T, data_id,                  data_count,       (void*) data,
                                                          ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, port ); }

void RoveCommWifiUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint32_t *data,
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t  ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  this->_writeTo( 4, roveware::UINT32_T, data_id,                  data_count,        (void*) data,
                                                          ip_octet_1, ip_octet_2,   ip_octet_3,ip_octet_4, port ); }

void RoveCommWifiUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int16_t *data,
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  this->_writeTo( 2,  roveware::INT16_T, data_id,                 data_count,        (void*) data,
                                                          ip_octet_1, ip_octet_2,  ip_octet_3,  ip_octet_4,   port ); }

void RoveCommWifiUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint16_t *data,
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t  ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  this->_writeTo( 2, roveware::UINT16_T, data_id,                  data_count,        (void*) data,
                                                          ip_octet_1, ip_octet_2,   ip_octet_3, ip_octet_4,    port ); }

void RoveCommWifiUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int8_t  *data, 
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  this->_writeTo( 1,  roveware::INT8_T,  data_id,                  data_count,       (void*) data, 
                                                          ip_octet_1, ip_octet_2,   ip_octet_3, ip_octet_4,   port ); }

void RoveCommWifiUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint8_t *data,
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  this->_writeTo( 1,  roveware::UINT8_T, data_id,                  data_count,       (void*) data,
ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, port ); }