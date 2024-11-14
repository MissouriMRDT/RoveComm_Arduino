#ifndef ROVECOMM_PACKET_H
#define ROVECOMM_PACKET_H

#include <stddef.h>
#include <stdint.h>

#include "Platform.h"
#include "RoveCommManifest.h"

//////////////////////////////////////////////////////

// User can define a different max data count before including RoveComm
#ifndef ROVECOMM_PACKET_MAX_DATA_COUNT
#if ROVECOMM_TIVA
#define ROVECOMM_PACKET_MAX_DATA_COUNT (65535 / 2) // Tiva can only support 21,000 uint8_t at once due to memory issues
#elif ROVECOMM_TEENSY
#define ROVECOMM_PACKET_MAX_DATA_COUNT                                                                                 \
    (65535 / 2) // Teensy can only support 32,000 uint8_t at once due to memory issues
#endif
#endif

#define ROVECOMM_PACKET_HEADER_SIZE 6
#define ROVECOMM_VERSION 3

//////////////////////////////////////////////////////
// Carries RoveComm packet data
// Used to return RoveComm::read() values as a struct
////////////////////////////////////////////////
// The RoveComm udp packet header is 6 bytes long:
// uint8_t  rovecomm version
// uint16_t data id
// uint16_t  data count
// uint8_t  data type
//////////////////////////////////////////////////////
struct RoveCommPacket {
    uint16_t dataId;
    uint16_t dataCount;
    uint8_t dataType;
    uint8_t data[ROVECOMM_PACKET_MAX_DATA_COUNT];

    // Prevent electricals from unknowingly copying a large packet buffer
    // Nevermind as of C++ 20 this is no longer allowed
    // RoveCommPacket(const RoveCommPacket& other) = delete;
    // RoveCommPacket& operator=(const RoveCommPacket& other) = delete;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace rovecomm {
// DataType RoveComm encoding
enum data_type_t {
    INT8_T = 0,
    UINT8_T = 1,
    INT16_T = 2,
    UINT16_T = 3,
    INT32_T = 4,
    UINT32_T = 5,
    FLOAT = 6,
    DOUBLE = 7,
    CHAR = 8
};

// Get size of a RoveComm data type based on its enum value
size_t dataTypeSize(const data_type_t dataType);

// Pack a RoveCommPacket into the given buffer in network byte order
// Returns the number of bytes packed or 0 if the data is invalid
size_t packPacket(uint8_t *dest, uint16_t dataId, uint16_t dataCount, data_type_t dataType, const uint8_t *data);

// Unpack a netowrk byte order buffer into a RoveCommPacket
// Returns true if the packet was successfully read, else false
bool unpackPacket(RoveCommPacket &dest, const uint8_t *buffer);

} // namespace rovecomm

#endif // ROVECOMM_PACKET_H
