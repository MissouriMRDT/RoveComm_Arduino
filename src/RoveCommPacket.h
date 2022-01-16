#ifndef ROVECOMM_PACKET_H
#define ROVECOMM_PACKET_H

#include <stdint.h>
#include <stddef.h>
#include "RoveCommManifest.h"
#include "Ethernet.h"

//////////////////////////////////////////////////////
#define ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS      10
#define ROVECOMM_PACKET_MAX_DATA_COUNT        255
#define ROVECOMM_PACKET_HEADER_SIZE    5
#define ROVECOMM_VERSION    2

//////////////////////////////////////////////////////
//Carrys RoveComm packet data
//Used to return RoveComm::read() values as a struct
struct rovecomm_packet
{
  uint16_t data_id;
  uint8_t data_count;
  uint8_t data_type;
  char data[ROVECOMM_PACKET_MAX_DATA_COUNT*4];
};  

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace roveware
{
  //DataType RoveComm encoding
  enum data_type_t { INT8_T=0, UINT8_T=1, INT16_T=2, UINT16_T=3, INT32_T=4, UINT32_T=5, FLOAT=6};

  ////////////////////////////////////////////////
  // The RoveComm udp packet header is 5 bytes long:
  // uint8_t  rovecomm_version
  // uint16_t data_id   
  // uint8_t  data_type
  // uint8_t  data_count

  //Carrys Udp packet data
  struct _packet
  {
    uint8_t bytes[ROVECOMM_PACKET_HEADER_SIZE + sizeof(int) * ROVECOMM_PACKET_MAX_DATA_COUNT];
  };

  struct _packet        packPacket(const uint16_t data_id, const uint8_t data_count, const data_type_t data_type, const void* data);

  //for UDP packets, of known size
  struct rovecomm_packet unpackPacket(uint8_t  _packet[]);
  //for TCP, where we read streams of data, with size determined by parsing header
  struct rovecomm_packet unpackPacket(EthernetClient client);

}// end namespace/////////////////////////////////////////////////////////////////////////////////////////////////

#endif // ROVECOMM_PACKET_H