#ifndef RoveSerial_h
#define RoveSerial_h

#include <stdint.h>
#include <stddef.h>

#include "RoveCommManifest.h"
#include "RoveCommPacket.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RoveCommSerial
{
  private:
    Stream *_Serial;
	
    //Called by overloaded write functions
    void _write(  const uint8_t  data_type_length, const roveware::data_type_t data_type, 
                  const uint16_t data_id,    const uint8_t data_count, const void* data);

  public:
    /////begin///////////////////////////
	void begin(Stream *serialObject);
    
	/////Read/////////////////////
	struct rovecomm_packet read();
	
	/////write////////////////////////////////////////////////////////////////////////
	//Single-value write
	//Overloaded for each data type
    //Causes bug when doing:RoveComm.write(SINGLE_VALUE_EXAMPLE_ID, 1, analogRead(A0));
	//void write(const uint16_t data_id, const int     data_count, const int      data);
    void write(const uint16_t data_id, const uint8_t data_count, const uint8_t  data);
    void write(const uint16_t data_id, const uint8_t data_count, const uint16_t data);
    void write(const uint16_t data_id, const uint8_t data_count, const uint32_t data);
    void write(const uint16_t data_id, const uint8_t data_count, const int8_t   data);
    void write(const uint16_t data_id, const uint8_t data_count, const int16_t  data);
    void write(const uint16_t data_id, const uint8_t data_count, const int32_t  data);

    //Array entry write
	//Overloaded for each data type
    void write(const uint16_t data_id, const int     data_count, const int      *data);
    void write(const uint16_t data_id, const uint8_t data_count, const uint8_t  *data);
    void write(const uint16_t data_id, const uint8_t data_count, const uint16_t *data);
    void write(const uint16_t data_id, const uint8_t data_count, const uint32_t *data);
    void write(const uint16_t data_id, const uint8_t data_count, const int8_t   *data);
    void write(const uint16_t data_id, const uint8_t data_count, const int16_t  *data);
    void write(const uint16_t data_id, const uint8_t data_count, const int32_t  *data);
  
};

#endif // RoveSerial_h