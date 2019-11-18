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

int RoveCommEthernetPi::begin(const int board_ip_octet)
{
	int rv;
	
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET; // use IPv4
	hints.ai_socktype = SOCK_DGRAM; //use UDP (user datagram packet)
	hints.ai_flags = AI_PASSIVE; //use own IP instead of specified
	
	for (int i = 0; i < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS; i++)
	{
		//initialize sendSocksInfo
	}
	
	if ((rv=getaddrinfo(std::nullptr, RC_ROVECOMM_ETHERNET_UDP_PORT, &hints, &this->servinfo) != 0) //if fail to generate the rest of the information to create a socket
	{
		return 1; //quit with code 1 for error handling
	}
	
	for (p = this->servinfo, p != std::nullptr, p->ai_next)
	{
		if ((this->recvSock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
		{
			//handle non-socket error here
			continue;
		}
		if (bind(this->recvSock, p->ai_addr, p->ai_addrlen) == -1)
		{
			shutdown(this->recvSock, 2);
			//handle non-bind error here
			continue;
		}
		
		break; //if we made a socket and bound successfully, end loop
	}
	
	if (p == std::nullptr)
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
	int packet_size = recvfrom(this->recvSock, this->buf, MAXBUFLEN-1, 0, (struct sockaddr*)&their_addr, &addrlen); //see if we received a packet
	if (packet_size != -1) //if we received a packet
	{
		uint8_t _packet[packet_size];
		for (int i = 0; i < packet_size; i++) //unpack the packet into uint8_t to use the existing unpackPacket function
		{
			_packet[i] = (uint8_t)buf[i];
		}
		
		packet = roveware::unpackPacket(_packet); //actually unpack the data into another packet.
		
		//handle the specific function data ids
		if (packet.data_id == RC_ROVECOMM_SUBSCRIBE_REQUEST_DATA_ID)
		{
			for (int i = 0; i < ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS; i++)
			{
				if (sendSocksInfo[i]->sin_addr.s_addr == their_addr.sin_addr.s_addr)
				{
					break;
				}
				else if (inet_ntoa(sendSocksInfo[i]->sin_addr.s_addr) == "0.0.0.0")
				{
					
				}
			}
		}
	}
}
