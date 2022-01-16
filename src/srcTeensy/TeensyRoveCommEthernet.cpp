#include "TeensyRoveCommEthernet.h"
#include "TeensyRoveCommPacket.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
#include          <SPI.h>         // Energia/master/hardware/lm4f/libraries/SPI
#include          <NativeEthernet.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RoveCommEthernet::begin(const uint8_t ip_octet_4, EthernetServer* TCPServer)
{
  //start UDP client and assigning board IP
  UDP.begin(192, 168, 1, ip_octet_4);
  //initializing the TCP server with the correct port
  TCP.begin(TCPServer);
}

void RoveCommEthernet::begin(const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, EthernetServer* TCPServer)
{
  //start UDP client and assigning board IP
  UDP.begin(ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4);
  //initializing the TCP server with the correct port
  TCP.begin(TCPServer);
}

/////////////////////////////////////////////////////////////////////////////////
struct rovecomm_packet RoveCommEthernet::read()
{
  //checks for TCP packets first, as they should be infrequent and require acks
  rovecomm_packet = TCP.read();
  if(rovecomm_packet.data_id != RC_ROVECOMM_NO_DATA_DATA_ID)
  {
    return rovecomm_packet;
  }

  //check for UDP packets if no TCP were read
  rovecomm_packet = UDP.read();
  if(rovecomm_packet.data_id != RC_ROVECOMM_NO_DATA_DATA_ID)
  {
    return rovecomm_packet;
  }

  //otherwise just return no data
  rovecomm_packet.data_id = RC_ROVECOMM_NO_DATA_DATA_ID;
  rovecomm_packet.data_count = 0;
  return rovecomm_packet;
}

/////write////////////////////////////////////////////////////////////////////////
//Single-value write
//Overloaded for each data type
//Causes bug when doing:RoveComm.write(SINGLE_VALUE_EXAMPLE_ID, 1, analogRead(A0));
//void write(const uint16_t data_id, const int     data_count, const int      data);
void RoveCommEthernet::write(const uint16_t data_id, const uint8_t data_count, const uint8_t  data)
{           UDP.write(data_id, data_count, data); }

void RoveCommEthernet::write(const uint16_t data_id, const uint8_t data_count, const uint16_t data)
{           UDP.write(data_id, data_count, data); }

void RoveCommEthernet::write(const uint16_t data_id, const uint8_t data_count, const uint32_t data)
{           UDP.write(data_id, data_count, data); }

void RoveCommEthernet::write(const uint16_t data_id, const uint8_t data_count, const int8_t   data)
{           UDP.write(data_id, data_count, data); }

void RoveCommEthernet::write(const uint16_t data_id, const uint8_t data_count, const int16_t  data)
{           UDP.write(data_id, data_count, data); }

void RoveCommEthernet::write(const uint16_t data_id, const uint8_t data_count, const int32_t  data)
{           UDP.write(data_id, data_count, data); }

void RoveCommEthernet::write(const uint16_t data_id, const uint8_t data_count, const float    data)
{           UDP.write(data_id, data_count, data); }


//Array entry write
//Overloaded for each data type
void RoveCommEthernet::write(const uint16_t data_id, const int     data_count, const int      *data)
{           UDP.write(data_id, data_count, data); }

void RoveCommEthernet::write(const uint16_t data_id, const uint8_t data_count, const uint8_t  *data)
{           UDP.write(data_id, data_count, data); }

void RoveCommEthernet::write(const uint16_t data_id, const uint8_t data_count, const uint16_t *data)
{           UDP.write(data_id, data_count, data); }

void RoveCommEthernet::write(const uint16_t data_id, const uint8_t data_count, const uint32_t *data)
{           UDP.write(data_id, data_count, data); }

void RoveCommEthernet::write(const uint16_t data_id, const uint8_t data_count, const int8_t   *data)
{           UDP.write(data_id, data_count, data); }

void RoveCommEthernet::write(const uint16_t data_id, const uint8_t data_count, const int16_t  *data)
{           UDP.write(data_id, data_count, data); }

void RoveCommEthernet::write(const uint16_t data_id, const uint8_t data_count, const int32_t  *data)
{           UDP.write(data_id, data_count, data); }

void RoveCommEthernet::write(const uint16_t data_id, const uint8_t data_count, const float    *data)
{           UDP.write(data_id, data_count, data); }

/////writeTo///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Single-value writeTo
//Overloaded for each data type
void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const int  data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }

void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const uint8_t  data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }


void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const uint16_t data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }


void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const uint32_t data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }

void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const int8_t   data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }

void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const int16_t  data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }

void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const int32_t  data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }

void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const float  data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }

//Array entry write
//Overloaded for each data type
void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const int  *data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }

void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const uint8_t  *data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }

void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const uint16_t *data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }

void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const uint32_t *data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }

void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const int8_t   *data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }

void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const int16_t  *data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }

void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const int32_t  *data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }

void RoveCommEthernet::writeTo(const uint16_t data_id,    const uint8_t data_count, const float  *data,
              const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port)
{           UDP.writeTo(data_id, data_count, data, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, RC_ROVECOMM_ETHERNET_UDP_PORT); }

//Overloaded writeReliable////////////////////////////////////////////////////////////////////////////////////////////////////
//Single-value write
//handles the data->pointer conversion for user
void RoveCommEthernet::writeReliable(         const uint16_t  data_id, const uint8_t data_count, const  int32_t data)
{           TCP.writeReliable(data_id, data_count, data); }

void RoveCommEthernet::writeReliable(         const uint16_t  data_id, const uint8_t data_count, const uint32_t data)
{           TCP.writeReliable(data_id, data_count, data); }

void RoveCommEthernet::writeReliable(         const uint16_t  data_id, const uint8_t data_count, const  int16_t data)
{           TCP.writeReliable(data_id, data_count, data); }

void RoveCommEthernet::writeReliable(         const uint16_t  data_id, const uint8_t data_count, const uint16_t data)
{           TCP.writeReliable(data_id, data_count, data); }

void RoveCommEthernet::writeReliable(         const uint16_t data_id, const uint8_t data_count, const   int8_t data)
{           TCP.writeReliable(data_id, data_count, data); }

void RoveCommEthernet::writeReliable(         const uint16_t  data_id, const uint8_t data_count, const  uint8_t data)
{           TCP.writeReliable(data_id, data_count, data); }

void RoveCommEthernet::writeReliable(         const uint16_t  data_id, const uint8_t data_count, const  float   data)
{           TCP.writeReliable(data_id, data_count, data); }
//Array-Entry write///////////////////////////////////
void RoveCommEthernet::writeReliable(         const uint16_t  data_id, const uint8_t data_count, const  int32_t *data)
{           TCP.writeReliable(data_id, data_count, data); }

void RoveCommEthernet::writeReliable(         const uint16_t  data_id, const uint8_t data_count, const uint32_t *data)
{           TCP.writeReliable(data_id, data_count, data); }

void RoveCommEthernet::writeReliable(         const uint16_t  data_id, const uint8_t data_count, const  int16_t *data)
{           TCP.writeReliable(data_id, data_count, data); }

void RoveCommEthernet::writeReliable(         const uint16_t  data_id, const uint8_t data_count, const uint16_t *data)
{           TCP.writeReliable(data_id, data_count, data); }

void RoveCommEthernet::writeReliable(         const uint16_t data_id, const uint8_t data_count, const   int8_t *data)
{           TCP.writeReliable(data_id, data_count, data); }

void RoveCommEthernet::writeReliable(         const uint16_t  data_id, const uint8_t data_count, const  uint8_t *data)
{           TCP.writeReliable(data_id, data_count, data); }

void RoveCommEthernet::writeReliable(         const uint16_t  data_id, const uint8_t data_count, const  float   *data)
{           TCP.writeReliable(data_id, data_count, data); }
