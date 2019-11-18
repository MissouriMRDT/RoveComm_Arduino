#ifndef RoveEthernetPi_h
#define RoveEthernetPi_h

#include <stdint.h>
#include <stddef.h>
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

#include "RoveCommManifest.h"
#include "RoveCommPacket.h"

#define MAXBUFLEN 100;

class RoveCommEthernetPi
{
	private:
	
	char buf[MAXBUFLEN] = {0};
	int recvSock; //set the read socket during initial setup
	int sendSocks[ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS] = {0}; //produce one send socket per subscriber
	struct sockaddr_in sendSocksInfo[ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS] = {0}; //keep this to easily access the IP's of subscribers
	//TODO: test this and make sure it works
	struct addrinfo hints, *servaddr, *servinfo, *p;
	
	void _write( const uint8_t data_type_length, const roveware::data_type_t data_type, const uint16_t data_id, const uint8_t data_count, const void* data);
	
	public:
	
	struct rovecomm_packet read();
	
	//begin
	int begin(const int board_ip_octect);
	
	//overloaded write one element functions
	void write(const uint16_t data_id, const uint8_t data_count, const uint8_t data);
	void write(const uint16_t data_id, const uint8_t data_count, const uint16_t data);
	void write(const uint16_t data_id, const uint8_t data_count, const uint32_t data);
	void write(const uint16_t data_id, const uint8_t data_count, const int8_t data);
	void write(const uint16_t data_id, const uint8_t data_count, const int16_t data);
	void write(const uint16_t data_id, const uint8_t data_count, const int32_t data);
	
	//overloaded write array functions
	void write(const uint16_t data_id, const uint8_t data_count, const int *data);
	void write(const uint16_t data_id, const uint8_t data_count, const uint8_t *data);
	void write(const uint16_t data_id, const uint8_t data_count, const uint16_t *data);
	void write(const uint16_t data_id, const uint8_t data_count, const uint32_t *data);
	void write(const uint16_t data_id, const uint8_t data_count, const int8_t *data);
	void write(const uint16_t data_id, const uint8_t data_count, const int16_t *data);
	void write(const uint16_t data_id, const uint8_t data_count, const int32_t *data);
	
};

#endif //RoveEthernetPi_h
