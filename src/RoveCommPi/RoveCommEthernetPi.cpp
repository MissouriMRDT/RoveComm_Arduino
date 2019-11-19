#include "RoveCommEthernetPi.h"
#include "RoveCommPacket.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int RoveCommEthernetPi::begin(const int board_ip_octet) //we dont actually use the 4th octect to describe the socket.
{
	int rv;

	memset(&this->hints, 0, sizeof(hints));
	this->hints.ai_family = AF_INET; // use IPv4
	this->hints.ai_socktype = SOCK_DGRAM; //use UDP (user datagram packet)
	this->hints.ai_flags = AI_PASSIVE; //use own IP instead of specified

	for (int i = 0; i < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS; i++)
	{
		//this->subscriberList[i] = std::pair<int,std::string>(0,"0.0.0.0");
		this->subscriberList[i] = std::nullptr;
	}

	if ((rv=getaddrinfo(std::nullptr, RC_ROVECOMM_ETHERNET_UDP_PORT, &hints, &this->servinfo) != 0) //if fail to generate the rest of the information to create a socket
	{
		//add at least a commented manual packing of servinfo, possibly actually manually pack.
		//getaddrinfo returns 0 for success, anything else is an error
		return 1; //quit with code 1 for error handling
	}

	for (this->p = this->servinfo; this->p != std::nullptr; this->p->ai_next) //not really sure why this is needed, but its good practice
	{
		//we should only have one entity in the servinfo linked list and then a nullptr
		if ((this->recvSock = socket(this->p->ai_family, this->p->ai_socktype, this->p->ai_protocol)) == -1)
		{
			//handle non-socket error here
			continue;
		}
		if (bind(this->recvSock, this->p->ai_addr, this->p->ai_addrlen) == -1)
		{
			shutdown(this->recvSock, 2);
			//handle non-bind error here
			continue;
		}

		break; //if we made a socket and bound successfully, end loop
	}

	if (this->p == std::nullptr)
	{
		//handle no socket error
		return 2; // quit with code 2 for error handling
	}

	//freeaddrinfo(this->servinfo); // we don't need servinfo anymore, free it

	return 0; //listener socket successfully created
}

struct rovecomm_packet RoveCommEthernetPi::read()
{
	struct rovecomm_packet packet = {0}; //instantiate a packet

	uint16_t data_id = 0;
	roveware::data_type_t data_type;
	uint8_t data_count = 0; //packet stuff from TIVA implementation

	struct sockaddr_storage their_addr; //stores the addr we receive packets from
	socklen_t addrlen = sizeof(their_addr); //size of the their_addr struct

	int packet_size = recvfrom(this->recvSock, this->buf, MAXBUFLEN-1, 0, (struct sockaddr*)&their_addr, &addrlen); //see if we received a packet
	//check and see if recvfrom actually returns packetwise or stream bytewise
	//recvfrom does acquire the oldest packet in the ethernet buffer for the proper socket.
	if (packet_size != -1) //recvfrom will return -1 in the case of an error
	{
		uint8_t _packet[packet_size];
		for (int i = 0; i < packet_size; i++) //convert the contents of the packet received by recvfrom to uint8's for use with the existing unpackPacket function
		{
			_packet[i] = (uint8_t)buf[i];
		}

		packet = roveware::unpackPacket(_packet); //actually unpack the data into another packet.

		int sockfd;
		//handle the specific function data ids
		if (packet.data_id == RC_ROVECOMM_SUBSCRIBE_REQUEST_DATA_ID)
		{
			for (int i = 0; i < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS; i++)
			{
				if (inet_ntoa(((struct sockaddr_in *)this->subscriberList[i]->ai_addr)->sin_addr) == inet_ntoa(their_addr.sin_addr.s_addr))
				{
					break; //if the socket already exists, break so we don't duplicate;
				}
				else if (inet_ntoa(((struct sockaddr_in *)this->subscriberList[i]->ai_addr)->sin_addr) == "0.0.0.0")
				{
					memset(&this->hints, 0, sizeof(this->hints));
					this->hints.ai_family = AF_INET; //use IPv4
					this->hints.ai_socktype = SOCK_DGRAM; //use UDP sockets
					int rv;
					if ((rv = getaddrinfo(inet_ntoa(their_addr.sin_addr.s_addr), RC_ROVECOMM_ETHERNET_UDP_PORT, &this->hints, &this->servinfo)) != 0)
					{
						//handle an error here at some point, not sure of the best method to handle at the moment;
						//this means we couldn't prepare for a socket to be built pointing at sourceIP:RC_ROVECOMM_ETHERNET_UDP_PORT
					}
					for (this->p = this->servinfo; this->p != nullptr; this->p = this->p->ai_next)
					{
						if ((sockfd  = socket(this->p->ai_family, this->p->ai_socktype, this->p->ai_protocol)) == -1)
						{
							continue;
						}
					}
					//fix the thing;
					//this->subscriberList[i] = std::pair<int,std::string>(sockfd, inet_ntoa(their_addr.sin_addr.s_addr)); //add the subscriber to the list
					this->subscriberList[i] = this->p;
					break; //break after we open the socket;
				} //end elseif non-populated member in subscribers array
			} //end for iteration over subscribers
			if (this->p == nullptr)
			{
				//handle error for when we just don't make a socket here at some point
			}

		} // end Subscribe block
		else if (packet.data_id == RC_ROVECOMM_UNSUBSCRIBE_REQUEST_DATA_ID)
		{
			for (int i =0; i < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS; i++)
			{
				if (inet_ntoa(((struct sockaddr_in *)this->subscriberList[i]->ai_addr)->sin_addr) == "0.0.0.0")
				{
					continue;
				}
				if (inet_ntoa(((struct sockaddr_in *)this->subscriberList[i]->ai_addr)->sin_addr) == inet_ntoa(their_addr.sin_addr.s_addr))
				{
					this->subscriberList[i] = std::nullptr;
				} //end if matching
			} //end primary loop over subscriberList
		} //end unsubscribe request
		else if (packet.data_id == RC_ROVECOMM_PING_DATA_ID)
		{
			const char* data_p[1];
			data_p[0] = "0x01";
			this->_writeto(); //finish implementation
		}

	} //end received packet
} //end read function

void RoveCommEthernetPi::_write(const uint8_t data_type_length, const roveware::data_type_t data_type, const uint16_t data_id, const uint8_t data_count, const void* data)
{
	struct roveware::_packet _packet = roveware::packPacket(data_id, data_count, data_type, data); //make a packet using the overall c++ method
	int buffLen = ROVECOMM_PACKET_HEADER_SIZE + (data_type_length * data_count);
	char* buf[buffLen]; //make a char buffer
	for (int i = 0; i < buffLen; i++)
	{
		buf[i] = (char*) _packet.bytes[i]; //populate a char array with the information to write, C++ likes chars and not uint8's
	}

	for (int i = 0; i < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS; i++)
	{
		if (inet_ntoa(((struct sockaddr_in *)this->subscriberList[i]->ai_addr)->sin_addr) == "0.0.0.0")
		{
			continue;
		}
		sendto(this->recvSock, buf, buffLen, 0, this->subscriberList[i]->ai_addr, this->subscriberList[i]->ai_addrlen);
	} //end for loop for sending packets to people
} //end _write

void RoveCommEthernetPi::_writeTo(const uint8_t data_type_length, const roveware::data_type_t data_type, const uint16_t data_id, const uint8_t data_count, const void* data, const char* IPAddress, const uint16_t port)
{
	struct roveware::_packet _packet = roveware::packPacket(data_id, data_count, data_type, data); //make a packet using the overall c++ method
	int buffLen = ROVECOMM_PACKET_HEADER_SIZE + (data_type_length * data_count);
	char* buf[buffLen]; //make a char buffer
	for (int i = 0; i < buffLen; i++)
	{
		buf[i] = (char*) _packet.bytes[i]; //populate a char array with the information to write, C++ likes chars and not uint8's
	}

	int rv;
	memset(&this->hints, 0, sizeof(this->hints));
	this->hints.ai_family = AF_INET;
	this->hints.ai_socktype = SOCK_DGRAM;

	if ((rv = getaddrinfo(IPAddress, RC_ROVECOMM_ETHERNET_UDP_PORT, &this->hints, &this->servinfo)) != 0)
	{
		//handle the inability to find address info error at some point
	}


	int numbytes;
	if ((numbytes = sendto(this->recvSock, buf, buffLen, 0, this->servinfo->ai_addr, this->servinfo->ai_addrlen)) == -1)
	{
		//failed to send message, add handling later
	}
} //end _writeTo function



//Overloaded write////////////////////////////////////////////////////////////////////////////////////////////////////
//Single-value write
//handles the data->pointer conversion for user
//void RoveCommEthernetUdp::write(        const  uint16_t      data_id, const  int    data_count, const  int     data )
//{                  int data_p[1];
//                   data_p[0] = data;
//                   this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data_p ); }
//
void RoveCommEthernetUdp::write(        const uint16_t  data_id, const uint8_t data_count, const  int32_t data )
{                  int32_t data_p[1];
                   data_p[0] = data;
                   this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetUdp::write(        const uint16_t  data_id, const uint8_t data_count, const uint32_t data )
{                  uint32_t data_p[1];
                   data_p[0] = data;
                   this->_write( 4, roveware::UINT32_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetUdp::write(        const uint16_t  data_id, const uint8_t data_count, const  int16_t data )
{                  int16_t data_p[1];
                   data_p[0] = data;
                   this->_write( 2,  roveware::INT16_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetUdp::write(        const uint16_t  data_id, const uint8_t data_count, const uint16_t data )
{                  uint16_t data_p[1];
                   data_p[0] = data;
                   this->_write( 2, roveware::UINT16_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetUdp::write(         const uint16_t data_id, const uint8_t data_count, const   int8_t data )
{                  int8_t data_p[1];
                   data_p[0] = data;
                   this->_write( 1,   roveware::INT8_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetUdp::write(        const uint16_t  data_id, const uint8_t data_count, const  uint8_t data )
{                  uint8_t data_p[1];
                   data_p[0] = data;
                   this->_write( 1,  roveware::UINT8_T, data_id,               data_count,        (void*) data_p ); }
//Array-Entry write///////////////////////////////////
//void RoveCommEthernetUdp::write(        const  int      data_id, const  int    data_count, const  int     *data )
//{                  this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data ); }
//
void RoveCommEthernetUdp::write(        const uint16_t  data_id, const uint8_t data_count, const  int32_t *data )
{                  this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetUdp::write(        const uint16_t  data_id, const uint8_t data_count, const uint32_t *data )
{                  this->_write( 4, roveware::UINT32_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetUdp::write(        const uint16_t  data_id, const uint8_t data_count, const  int16_t *data )
{                  this->_write( 2,  roveware::INT16_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetUdp::write(        const uint16_t  data_id, const uint8_t data_count, const uint16_t *data )
{                  this->_write( 2, roveware::UINT16_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetUdp::write(         const uint16_t data_id, const uint8_t data_count, const   int8_t *data )
{                  this->_write( 1,   roveware::INT8_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetUdp::write(        const uint16_t  data_id, const uint8_t data_count, const  uint8_t *data )
{                  this->_write( 1,  roveware::UINT8_T, data_id,               data_count,        (void*) data ); }



//Overloaded writeTo//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Single-value writeTo
//handles the data->pointer conversion for user
void RoveCommEthernetUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int data,
                                           const char* IPAddress, const uint16_t port )
{                  int data_p[1];
                   data_p[0] = data;
                   this->_writeTo( 4,  roveware::INT32_T, data_id,                  data_count,       (void*) data_p,
                                                          IPAddress, port ); }
void RoveCommEthernetUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int32_t data, //handling data->pointer conversion for user
                                           const char* IPAddress, const uint16_t port )
{                  int32_t data_p[1];
                   data_p[0] = data;
                   this->_writeTo( 4,  roveware::INT32_T, data_id,                  data_count,       (void*) data_p,
                                                          IPAddress, port ); }
void RoveCommEthernetUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint32_t data,
                                           const char* IPAddress, const uint16_t port )
{                  uint32_t data_p[1];
                   data_p[0] = data;
                   this->_writeTo( 4, roveware::UINT32_T, data_id,                  data_count,        (void*) data_p,
                                                          IPAddress, port ); }
void RoveCommEthernetUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int16_t data,
                                           const char* IPAddress, const uint16_t port )
{                  int16_t data_p[1];
                   data_p[0] = data;
                   this->_writeTo( 2,  roveware::INT16_T, data_id,                 data_count,        (void*) data_p,
                                                          IPAddress,   port ); }
void RoveCommEthernetUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint16_t data,
                                           const char* IPAddress, const uint16_t port )
{                  uint16_t data_p[1];
                   data_p[0] = data;
                   this->_writeTo( 2, roveware::UINT16_T, data_id,                  data_count,        (void*) data_p,
                                                          IPAddress,    port ); }
void RoveCommEthernetUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int8_t  data,
                                           const char* IPAddress, const uint16_t port )
{                  int8_t data_p[1];
                   data_p[0] = data;
                   this->_writeTo( 1,  roveware::INT8_T,  data_id,                  data_count,       (void*) data_p,
                                                          IPAddress,   port ); }

void RoveCommEthernetUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint8_t data,
                                           const char* IPAddress, const uint16_t port )
{                  uint8_t data_p[1];
                   data_p[0] = data;
                   this->_writeTo( 1,  roveware::UINT8_T, data_id,                  data_count,       (void*) data_p,
IPAddress, port ); }
//Array-entry writeTo
//handles the data->pointer conversion for user
void RoveCommEthernetUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int *data, //handling data->pointer conversion for user
                                           const char* IPAddress, const uint16_t port )
{                  this->_writeTo( 4,  roveware::INT32_T, data_id,                  data_count,       (void*) data,
                                                          IPAddress, port ); }
void RoveCommEthernetUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int32_t *data,
                                           const char* IPAddress, const uint16_t port )
{                  this->_writeTo( 4,  roveware::INT32_T, data_id,                  data_count,       (void*) data,
                                                          IPAddress, port ); }

void RoveCommEthernetUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint32_t *data,
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t  ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  this->_writeTo( 4, roveware::UINT32_T, data_id,                  data_count,        (void*) data,
                                                          IPAddress, port ); }

void RoveCommEthernetUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int16_t *data,
                                           const char* IPAddress, const uint16_t port )
{                  this->_writeTo( 2,  roveware::INT16_T, data_id,                 data_count,        (void*) data,
                                                          IPAddress,   port ); }

void RoveCommEthernetUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint16_t *data,
                                           const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t  ip_octet_3, const uint8_t ip_octet_4, const uint16_t port )
{                  this->_writeTo( 2, roveware::UINT16_T, data_id,                  data_count,        (void*) data,
                                                          IPAddress,    port ); }

void RoveCommEthernetUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int8_t  *data,
                                           const char* IPAddress, const uint16_t port )
{                  this->_writeTo( 1,  roveware::INT8_T,  data_id,                  data_count,       (void*) data,
                                                          IPAddress,   port ); }

void RoveCommEthernetUdp::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint8_t *data,
                                           const char* IPAddress, const uint16_t port )
{                  this->_writeTo( 1,  roveware::UINT8_T, data_id,                  data_count,       (void*) data,
IPAddress, port ); }
