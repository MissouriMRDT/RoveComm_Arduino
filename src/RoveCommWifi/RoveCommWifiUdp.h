#ifndef RoveWifiUdp_h
#define RoveWifiUdp_h

#include <stdint.h>
#include <stddef.h>
#include <WifiUdp.h>

#include "RoveCommManifest.h"
#include "RoveCommPacket.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RoveCommWifiUdp
{
  public:
    
    struct rovecomm_packet read();

    /////begin/////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Overloaded begin
	void begin();
    
	/////write////////////////////////////////////////////////////////////////////////
	//Single-value write
	//Overloaded for each data type
    void write(const uint16_t data_id, const uint8_t data_count, const uint8_t  data);
    void write(const uint16_t data_id, const uint8_t data_count, const uint16_t data);
    void write(const uint16_t data_id, const uint8_t data_count, const uint32_t data);
    void write(const uint16_t data_id, const uint8_t data_count, const int8_t   data);
    void write(const uint16_t data_id, const uint8_t data_count, const int16_t  data);
    void write(const uint16_t data_id, const uint8_t data_count, const int32_t  data);

    //Array entry write
	//Overloaded for each data type
    void write(const uint16_t data_id, const uint8_t data_count, const uint8_t  *data);
    void write(const uint16_t data_id, const uint8_t data_count, const uint16_t *data);
    void write(const uint16_t data_id, const uint8_t data_count, const uint32_t *data);
    void write(const uint16_t data_id, const uint8_t data_count, const int8_t   *data);
    void write(const uint16_t data_id, const uint8_t data_count, const int16_t  *data);
    void write(const uint16_t data_id, const uint8_t data_count, const int32_t  *data);

	/////writeTo///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Single-value writeTo
	//Overloaded for each data type
    void writeTo(const uint16_t data_id,    const uint8_t data_count, const uint8_t  data,
                 const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

    void writeTo(const uint16_t data_id,    const uint8_t data_count, const uint16_t data, 
                 const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

    void writeTo(const uint16_t data_id,    const uint8_t data_count, const uint32_t data, 
                 const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

    void writeTo(const uint16_t data_id,    const uint8_t data_count, const int8_t   data, 
                 const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

    void writeTo(const uint16_t data_id,    const uint8_t data_count, const int16_t  data, 
                 const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

    void writeTo(const uint16_t data_id,    const uint8_t data_count, const int32_t  data, 
                 const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

    //Array entry write
	//Overloaded for each data type
    void writeTo(const uint16_t data_id,    const uint8_t data_count, const uint8_t  *data,
                 const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

    void writeTo(const uint16_t data_id,    const uint8_t data_count, const uint16_t *data, 
                 const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

    void writeTo(const uint16_t data_id,    const uint8_t data_count, const uint32_t *data, 
                 const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

    void writeTo(const uint16_t data_id,    const uint8_t data_count, const int8_t   *data, 
                 const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

    void writeTo(const uint16_t data_id,    const uint8_t data_count, const int16_t  *data, 
                 const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

    void writeTo(const uint16_t data_id,    const uint8_t data_count, const int32_t  *data, 
                 const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);
  
  private:
    //Called by overloaded write functions
    void _write(  const uint8_t  data_type_length, const roveware::data_type_t data_type, 
                  const uint16_t data_id,    const uint8_t data_count, const void* data);
    //Called by overloaded writeTo functions
    void _writeTo(const uint8_t  data_type_length, const roveware::data_type_t data_type,
                  const uint16_t data_id,    const uint8_t data_count, const void* data,
                  const uint8_t  ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);
    void _writeTo(const uint8_t  data_type_length, const roveware::data_type_t data_type,
                  const uint16_t data_id,    const uint8_t data_count, const void* data,
                  IPAddress ipaddress, const uint16_t port);
};

#endif // RoveWifiUdp_h