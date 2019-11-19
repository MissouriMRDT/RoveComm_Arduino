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
#include <utility>

#include "RoveCommManifest.h"
#include "RoveCommPacket.h"

#define MAXBUFLEN 512; //we can read up to MAXBUFLEN bytes

class RoveCommEthernetPi
{
	private:

	char buf[MAXBUFLEN];
	int recvSock; //set the read socket during initial setup
	//make a struct with int,str for socket,ip instead of using sendSocks and sendSocksInfo
	//int sendSocks[ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS] = {0}; //produce one send socket per subscriber
	//struct sockaddr_in sendSocksInfo[ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS] = {0}; //keep this to easily access the IP's of subscribers
	//TODO: test this and make sure it works
	//using a std::pair to store an (int, string) tuple for subscriber list
	//std::pair<int,std::string> subscriberList[ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS];
	//nope, I'm a big dummy and forgot we need to feed an ai_addr object to the send function
	struct addrinfo *subscriberList[ROVECOMM_ETHERNET_UDP_MAX_SUBSCRIBERS];
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
