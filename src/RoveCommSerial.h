#ifndef RoveSerial_h
#define RoveSerial_h

#include <stdint.h>
#include <stddef.h>

#include "RoveCommManifest.h"
#include "RoveCommPacket.h"
#include <Energia.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RoveCommSerial
{
  private:
    HardwareSerial *_Serial;

    void _write(  const uint8_t  data_type_length, const roveware::data_type_t data_type, // Called by overloaded write functions
                  const uint16_t data_id,    const uint8_t data_count, const void* data);

  public: 
    void                   begin(HardwareSerial *SerialPtr, int baud = 9600);
    bool                   available();
    struct rovecomm_packet read();
  
    // Overloaded by each data type /////////////////////////////////////////////////
    void write(const int      data_id, const int     data_count, const int      data);
    void write(const uint16_t data_id, const uint8_t data_count, const uint8_t  data);
    void write(const uint16_t data_id, const uint8_t data_count, const uint16_t data);
    void write(const uint16_t data_id, const uint8_t data_count, const int8_t   data);
    void write(const uint16_t data_id, const uint8_t data_count, const int16_t  data);
    void write(const uint16_t data_id, const uint8_t data_count, const int32_t  data);
    
    // Overloaded for each data type Array entry write ///////////////////////////////
    void write(const int      data_id, const int     data_count, const int      *data);
    void write(const uint16_t data_id, const uint8_t data_count, const uint8_t  *data);
    void write(const uint16_t data_id, const uint8_t data_count, const uint16_t *data);
    void write(const uint16_t data_id, const uint8_t data_count, const int8_t   *data);
    void write(const uint16_t data_id, const uint8_t data_count, const int16_t  *data);
    void write(const uint16_t data_id, const uint8_t data_count, const int32_t  *data);
};

#endif // RoveSerial_h