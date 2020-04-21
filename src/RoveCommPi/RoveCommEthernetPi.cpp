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
#include <iostream>
#include <fcntl.h>

int RoveCommEthernetPi::begin() //we dont actually use the 4th octect to describe the socket.
{
	int rv;

	memset(&this->hints, 0, sizeof(hints));
	this->hints.ai_family = AF_INET; // use IPv4
	this->hints.ai_socktype = SOCK_DGRAM; //use UDP (user datagram protocol) packets
	this->hints.ai_flags = AI_PASSIVE; //use own IP instead of specified

	for (int i = 0; i < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS; i++)
	{
		this->subscriberList[i] = nullptr;
	}

	if ((this->rv=getaddrinfo(nullptr, udpPort, &hints, &servinfo)) != 0) //if we fail to generate the rest of the information to create a socket
	{

		//add at least a commented manual packing of servinfo, possibly actually manually pack.
		//getaddrinfo returns 0 for success, anything else is an error
		return 1; //quit with code 1 for error handling
	}
	p = servinfo;
	//for (this->p = this->servinfo; this->p != nullptr; this->p->ai_next) //not really sure why this is needed, but its good practice
	while (p != nullptr)
	{
		//we should only have one entity in the servinfo linked list and then a nullptr in our simple case
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
		//removed a conditional check here because this always succeeds currently, might need to be fixed later if we change Rover network architecture
		break; //if we made a socket and bound successfully, end loop
		p = p->ai_next;
	}

	if (this->p == nullptr)
	{
		//handle no socket error
		return 2; // quit with code 2 for error handling
	}
	
	fcntl(this->recvSock, F_SETFL, O_NONBLOCK); //set the socket into non-blocking mode so that the readfrom call in RoveComm.Read() returns 0 if there isn't a packet to read instead of blocking
	
	return 0; //listener socket successfully created
}

struct rovecomm_packet RoveCommEthernetPi::read()
{
	struct rovecomm_packet packet = {0}; //instantiate a packet
	uint16_t data_id = 0;
	roveware::data_type_t data_type;
	uint8_t data_count = 0; //packet stuff from TIVA implementation
	struct sockaddr_in their_addr; //stores the addr we receive packets from
	socklen_t addrlen = sizeof(their_addr); //size of the their_addr struct
    memset(this->buf, 0, sizeof(this->buf)); // reset the incoming buffer to 0's every time to ensure we dont read erroneous data on different sized packets
	int packet_size = recvfrom(this->recvSock, this->buf, MAXBUFLEN-1, 0, (sockaddr*)&their_addr, &addrlen); //see if we received a packet
	char* recvAdd = inet_ntoa(their_addr.sin_addr);
	size_t len = strlen(recvAdd) + 1;
	char* theirAddress = new char[len];
	for (int i = 0; i < len; i++)
	{
		theirAddress[i] = recvAdd[i];
	}
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
				if (this->subscriberList[i] == nullptr)
				{
					memset(&this->hints, 0, sizeof(this->hints));
					this->hints.ai_family = AF_INET; //use IPv4
					this->hints.ai_socktype = SOCK_DGRAM; //use UDP sockets
					int rv;
					if ((rv = getaddrinfo(theirAddress, udpPort, &this->hints, &this->servinfo)) != 0)
					{
						//handle an error here at some point, not sure of the best method to handle at the moment;
						//this means we couldn't prepare for a socket to be built pointing at sourceIP:RC_ROVECOMM_ETHERNET_UDP_PORT
						//this means that our pointer doesn't actually work for sending data to the target IP address, this is not an issue on the current Rover network but might need to be fixed if architecture changes.
					}
					
					this->subscriberList[i] = new addrinfo;
					*this->subscriberList[i] = *this->servinfo;
					break; //break after we add the subscriber to the subscriber list
				} //end if non-populated member in subscribers array
				else if (strcmp(inet_ntoa(((struct sockaddr_in *)this->subscriberList[i]->ai_addr)->sin_addr),theirAddress) == 0)
				{
					break; //if the subscriber entry already exists, don't duplicate it;
				} //end elseif for not overwriting existing members

			} //end for iteration over subscribers
			if (this->p == nullptr)
			{
				//handle error for when we don't produce a valid target here at some point, if Rover network changes
			}

		} // end Subscribe block
		else if (packet.data_id == RC_ROVECOMM_UNSUBSCRIBE_REQUEST_DATA_ID)
		{
			for (int i =0; i < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS; i++)
			{
				if (strcmp(inet_ntoa(((struct sockaddr_in *)this->subscriberList[i]->ai_addr)->sin_addr),theirAddress) != 0)
				{
					continue;
				}
				if (strcmp(inet_ntoa(((struct sockaddr_in *)this->subscriberList[i]->ai_addr)->sin_addr),theirAddress) == 0)
				{
					delete this->subscriberList[i];
					this->subscriberList[i] = nullptr; //come back and fix this to move things up the list and reinitialize the other parts.
					for (int j = i; j + 1 < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS; j++)
					{
						this->subscriberList[j] = this->subscriberList[j + 1];
						this->subscriberList[j + 1] = nullptr;
						//move this into the i loop when I have time to test and validate
					}

				} //end if matching
			} //end primary loop over subscriberList
		} //end unsubscribe request
		else if (packet.data_id == RC_ROVECOMM_PING_DATA_ID)
		{
			this->writeTo(RC_ROVECOMM_PING_REPLY_DATA_ID, (uint8_t)1, (uint8_t)1, theirAddress, RC_ROVECOMM_ETHERNET_UDP_PORT); //this should match the current specification for pings

			//this->_writeto(RC_ROVECOMM_PING_REPLY_DATA_ID, ); //finish implementation
		}

	} //end received packet
	if (theirAddress != nullptr)
	{
		delete[] theirAddress;
	}
	return packet;
} //end read function

RoveCommEthernetPi::~RoveCommEthernetPi()
{
	for (int i = 0; i < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS; i++)
	{
		if (this->subscriberList[i] != nullptr)
		{
			delete this->subscriberList[i];
			this->subscriberList[i] = nullptr;
		}
	}
	shutdown(this->recvSock, SHUT_RDWR);

}

void RoveCommEthernetPi::_write(const uint8_t data_type_length, const roveware::data_type_t data_type, const uint16_t data_id, const uint8_t data_count, const void* data)
{
	struct roveware::_packet _packet = roveware::packPacket(data_id, data_count, data_type, data); //make a packet using the overall c++ method
	int buffLen = ROVECOMM_PACKET_HEADER_SIZE + (data_type_length * data_count);
	char* buf2 = new char [buffLen]; //make a char buffer
	for (int i = 0; i < buffLen; i++)
	{
		buf2[i] = (char) _packet.bytes[i]; //populate a char array with the information to write, C++ likes chars and not uint8's
	} //end converting packet from uint8's to chars for Linux C++ Socket compliance

	for (int i = 0; i < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS; i++)
	{
		if (this->subscriberList[i] != nullptr)
		{
			sendto(this->recvSock, buf2, buffLen, 0, this->subscriberList[i]->ai_addr, this->subscriberList[i]->ai_addrlen);
		}
		
	} //end for loop for sending packets to subscribers
	delete[] buf2;
} //end _write

void RoveCommEthernetPi::_writeto(const uint8_t data_type_length, const roveware::data_type_t data_type, const uint16_t data_id, const uint8_t data_count, const void* data, const char* IPAddress, const uint16_t port)
{
	struct roveware::_packet _packet = roveware::packPacket(data_id, data_count, data_type, data); //make a packet using the overall c++ method
	int buffLen = ROVECOMM_PACKET_HEADER_SIZE + (data_type_length * data_count);
	char* buf2 = new char [buffLen]; //make a char buffer
	for (int i = 0; i < buffLen; i++)
	{
		buf[i] = (char) _packet.bytes[i]; //populate a char array with the information to write, C++ likes chars and not uint8's
	} //end converting packet from uint8's to chars for Linux C++ Socket compliance
	this->servinfo = new addrinfo;
	int rv;
	memset(&this->hints, 0, sizeof(this->hints));
	this->hints.ai_family = AF_INET;
	this->hints.ai_socktype = SOCK_DGRAM;

	if ((rv = getaddrinfo(IPAddress, udpPort, &this->hints, &this->servinfo)) != 0)
	{
		//handle the inability to find address info error at some point
	}


	int numbytes;
	if ((numbytes = sendto(this->recvSock, buf, buffLen, 0, this->servinfo->ai_addr, this->servinfo->ai_addrlen)) == -1)
	{
		//failed to send message, add handling later
	}
	//freeaddrinfo(this->servinfo); // we don't need servinfo anymore, free it

	delete buf2;
} //end _writeto function



//Overloaded write////////////////////////////////////////////////////////////////////////////////////////////////////
//Single-value write
//handles the data->pointer conversion for user
//void RoveCommEthernetPi::write(        const  uint16_t      data_id, const  int    data_count, const  int     data )
//{                  int data_p[1];
//                   data_p[0] = data;
//                   this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data_p ); } //C++ allows an int32_t to be called with int
//
void RoveCommEthernetPi::write(        const uint16_t  data_id, const uint8_t data_count, const  int32_t data )
{                  int32_t data_p[1];
                   data_p[0] = data;
                   this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetPi::write(        const uint16_t  data_id, const uint8_t data_count, const uint32_t data )
{                  uint32_t data_p[1];
                   data_p[0] = data;
                   this->_write( 4, roveware::UINT32_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetPi::write(        const uint16_t  data_id, const uint8_t data_count, const  int16_t data )
{                  int16_t data_p[1];
                   data_p[0] = data;
                   this->_write( 2,  roveware::INT16_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetPi::write(        const uint16_t  data_id, const uint8_t data_count, const uint16_t data )
{                  uint16_t data_p[1];
                   data_p[0] = data;
                   this->_write( 2, roveware::UINT16_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetPi::write(         const uint16_t data_id, const uint8_t data_count, const   int8_t data )
{                  int8_t data_p[1];
                   data_p[0] = data;
                   this->_write( 1,   roveware::INT8_T, data_id,               data_count,        (void*) data_p ); }

void RoveCommEthernetPi::write(        const uint16_t  data_id, const uint8_t data_count, const  uint8_t data )
{                  uint8_t data_p[1];
                   data_p[0] = data;
                   this->_write( 1,  roveware::UINT8_T, data_id,               data_count,        (void*) data_p ); }
//Array-Entry write///////////////////////////////////
//void RoveCommEthernetPi::write(        const  int      data_id, const  int    data_count, const  int     *data )
//{                  this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data ); } //C++ allows an int32_t to be called with int
//
void RoveCommEthernetPi::write(        const uint16_t  data_id, const uint8_t data_count, const  int32_t *data )
{                  this->_write( 4,  roveware::INT32_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetPi::write(        const uint16_t  data_id, const uint8_t data_count, const uint32_t *data )
{                  this->_write( 4, roveware::UINT32_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetPi::write(        const uint16_t  data_id, const uint8_t data_count, const  int16_t *data )
{                  this->_write( 2,  roveware::INT16_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetPi::write(        const uint16_t  data_id, const uint8_t data_count, const uint16_t *data )
{                  this->_write( 2, roveware::UINT16_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetPi::write(         const uint16_t data_id, const uint8_t data_count, const   int8_t *data )
{                  this->_write( 1,   roveware::INT8_T, data_id,               data_count,        (void*) data ); }

void RoveCommEthernetPi::write(        const uint16_t  data_id, const uint8_t data_count, const  uint8_t *data )
{                  this->_write( 1,  roveware::UINT8_T, data_id,               data_count,        (void*) data ); }



//Overloaded writeTo//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Single-value writeTo
//handles the data->pointer conversion for user
/*void RoveCommEthernetPi::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int data,
                                           const char* IPAddress, const uint16_t port )
{                  int data_p[1];
                   data_p[0] = data;
                   this->_writeto( 4,  roveware::INT32_T, data_id,                  data_count,       (void*) data_p,
                                                          IPAddress, port ); }*/
void RoveCommEthernetPi::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int32_t data, //handling data->pointer conversion for user
                                           const char* IPAddress, const uint16_t port )
{                  int32_t data_p[1];
                   data_p[0] = data;
                   this->_writeto( 4,  roveware::INT32_T, data_id,                  data_count,       (void*) data_p,
                                                          IPAddress, port ); }
void RoveCommEthernetPi::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint32_t data,
                                           const char* IPAddress, const uint16_t port )
{                  uint32_t data_p[1];
                   data_p[0] = data;
                   this->_writeto( 4, roveware::UINT32_T, data_id,                  data_count,        (void*) data_p,
                                                          IPAddress, port ); }
void RoveCommEthernetPi::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int16_t data,
                                           const char* IPAddress, const uint16_t port )
{                  int16_t data_p[1];
                   data_p[0] = data;
                   this->_writeto( 2,  roveware::INT16_T, data_id,                 data_count,        (void*) data_p,
                                                          IPAddress,   port ); }
void RoveCommEthernetPi::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint16_t data,
                                           const char* IPAddress, const uint16_t port )
{                  uint16_t data_p[1];
                   data_p[0] = data;
                   this->_writeto( 2, roveware::UINT16_T, data_id,                  data_count,        (void*) data_p,
                                                          IPAddress,    port ); }
void RoveCommEthernetPi::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int8_t  data,
                                           const char* IPAddress, const uint16_t port )
{                  int8_t data_p[1];
                   data_p[0] = data;
                   this->_writeto( 1,  roveware::INT8_T,  data_id,                  data_count,       (void*) data_p,
                                                          IPAddress,   port ); }

void RoveCommEthernetPi::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint8_t data,
                                           const char* IPAddress, const uint16_t port )
{                  uint8_t data_p[1];
                   data_p[0] = data;
                   this->_writeto( 1,  roveware::UINT8_T, data_id,                  data_count,       (void*) data_p,
IPAddress, port ); }
//Array-entry writeTo
//handles the data->pointer conversion for user
/*void RoveCommEthernetPi::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int *data, //handling data->pointer conversion for user
                                           const char* IPAddress, const uint16_t port )
{                  this->_writeto( 4,  roveware::INT32_T, data_id,                  data_count,       (void*) data,
                                                          IPAddress, port ); }*/
void RoveCommEthernetPi::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int32_t *data,
                                           const char* IPAddress, const uint16_t port )
{                  this->_writeto( 4,  roveware::INT32_T, data_id,                  data_count,       (void*) data,
                                                          IPAddress, port ); }

void RoveCommEthernetPi::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint32_t *data,
                                           const char* IPAddress, const uint16_t port )
{                  this->_writeto( 4, roveware::UINT32_T, data_id,                  data_count,        (void*) data,
                                                          IPAddress, port ); }

void RoveCommEthernetPi::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int16_t *data,
                                           const char* IPAddress, const uint16_t port )
{                  this->_writeto( 2,  roveware::INT16_T, data_id,                 data_count,        (void*) data,
                                                          IPAddress,   port ); }

void RoveCommEthernetPi::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint16_t *data,
                                           const char* IPAddress, const uint16_t port )
{                  this->_writeto( 2, roveware::UINT16_T, data_id,                  data_count,        (void*) data,
                                                          IPAddress,    port ); }

void RoveCommEthernetPi::writeTo(         const uint16_t data_id,    const uint8_t data_count, const int8_t  *data,
                                           const char* IPAddress, const uint16_t port )
{                  this->_writeto( 1,  roveware::INT8_T,  data_id,                  data_count,       (void*) data,
                                                          IPAddress,   port ); }

void RoveCommEthernetPi::writeTo(         const uint16_t data_id,    const uint8_t data_count, const uint8_t *data,
                                           const char* IPAddress, const uint16_t port )
{                  this->_writeto( 1,  roveware::UINT8_T, data_id,                  data_count,       (void*) data,
IPAddress, port ); }
