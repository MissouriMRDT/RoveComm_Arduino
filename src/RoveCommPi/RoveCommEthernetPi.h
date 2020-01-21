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

#define MAXBUFLEN 512 //we can read up to MAXBUFLEN bytes
#define udpPort "11000" //redefined here from the RoveCommManifest as Linux C++ requires a const char* instead of an integer for the port number.

class RoveCommEthernetPi
{
	private:
	//char udpPort[2] = {0x2A, 0xFB};
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

	void _writeto(const uint8_t data_type_length, const roveware::data_type_t data_type, const uint16_t data_id, const uint8_t data_count, const void* data, const char* IPAddress, const uint16_t port);

	public:

	struct rovecomm_packet read();

	//begin
	int begin();

	//overloaded write one element functions
	void write(const uint16_t data_id, const uint8_t data_count, const uint8_t data);
	void write(const uint16_t data_id, const uint8_t data_count, const uint16_t data);
	void write(const uint16_t data_id, const uint8_t data_count, const uint32_t data);
	void write(const uint16_t data_id, const uint8_t data_count, const int8_t data);
	void write(const uint16_t data_id, const uint8_t data_count, const int16_t data);
	void write(const uint16_t data_id, const uint8_t data_count, const int32_t data);

	//overloaded write array functions
	//void write(const uint16_t data_id, const uint8_t data_count, const int *data);
	void write(const uint16_t data_id, const uint8_t data_count, const uint8_t *data);
	void write(const uint16_t data_id, const uint8_t data_count, const uint16_t *data);
	void write(const uint16_t data_id, const uint8_t data_count, const uint32_t *data);
	void write(const uint16_t data_id, const uint8_t data_count, const int8_t *data);
	void write(const uint16_t data_id, const uint8_t data_count, const int16_t *data);
	void write(const uint16_t data_id, const uint8_t data_count, const int32_t *data);

	void writeTo(const uint16_t data_id, const uint8_t data_count, const uint8_t data, const char* IPAddress, const uint16_t port);
	void writeTo(const uint16_t data_id, const uint8_t data_count, const uint16_t data, const char* IPAddress, const uint16_t port);
	void writeTo(const uint16_t data_id, const uint8_t data_count, const uint32_t data, const char* IPAddress, const uint16_t port);
	void writeTo(const uint16_t data_id, const uint8_t data_count, const int8_t data, const char* IPAddress, const uint16_t port);
	void writeTo(const uint16_t data_id, const uint8_t data_count, const int16_t data, const char* IPAddress, const uint16_t port);
	void writeTo(const uint16_t data_id, const uint8_t data_count, const int32_t data, const char* IPAddress, const uint16_t port);

	void writeTo(const uint16_t data_id, const uint8_t data_count, const uint8_t *data, const char* IPAddress, const uint16_t port);
	void writeTo(const uint16_t data_id, const uint8_t data_count, const uint16_t *data, const char* IPAddress, const uint16_t port);
	void writeTo(const uint16_t data_id, const uint8_t data_count, const uint32_t *data, const char* IPAddress, const uint16_t port);
	void writeTo(const uint16_t data_id, const uint8_t data_count, const int8_t *data, const char* IPAddress, const uint16_t port);
	void writeTo(const uint16_t data_id, const uint8_t data_count, const int16_t *data, const char* IPAddress, const uint16_t port);
	void writeTo(const uint16_t data_id, const uint8_t data_count, const int32_t *data, const char* IPAddress, const uint16_t port);

};

#endif //RoveEthernetPi_h
