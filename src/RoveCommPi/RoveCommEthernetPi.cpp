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
		//initialize sendSocksInfo
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

	freeaddrinfo(this->servinfo); // we don't need servinfo anymore

	return 0; //listener socket successfully created
}

struct rovecomm_packet RoveCommEthernetPi::read()
{
	struct rovecomm_packet packet = {0}; //instantiate a packet

	uint16_t data_id = 0;
	roveware::data_type_t data_type;
	uint8_t data_count = 0; //packet stuff from TIVA implementation

	struct sockaddr_storage their_addr; //stores the addr we receive packets from
	addrlen = sizeof(their_addr); //size of the their_addr struct
	//add type to addrlen
	int packet_size = recvfrom(this->recvSock, this->buf, MAXBUFLEN-1, 0, (struct sockaddr*)&their_addr, &addrlen); //see if we received a packet
	//check and see if recvfrom actually returns packetwise or stream bytewise
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
				if (sendSocksInfo[i]->sin_addr.s_addr == their_addr.sin_addr.s_addr)
				{
					break; //if the socket already exists, break so we don't duplicate;
				}
				else if (inet_ntoa(sendSocksInfo[i]->sin_addr.s_addr) == "0.0.0.0")
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
					break; //break after we open the socket;
				} //end elseif non-populated member in subscribers array
			} //end for iteration over subscribers
			if (this->p == nullptr)
			{
				//handle error for when we just don't make a socket here at some point
			}
			if (i < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS)
			{
				this->sendSocks[i-1] = sockfd;
				this->sendSocksInfo[i-1] = their_addr;
			} //add the subscriber to the class storage
		} // end Subscribe block


	} //end received packet
} //end read function
