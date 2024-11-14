#include "RoveCommPacket.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace rovecomm {

size_t dataTypeSize(const data_type_t dataType) {
    switch (dataType) {
    case INT8_T:
    case UINT8_T:
    case CHAR:
        return 1;
    case INT16_T:
    case UINT16_T:
        return 2;
    case INT32_T:
    case UINT32_T:
    case FLOAT:
        return 4;
    case DOUBLE:
        return 8;
    default:
        return 0;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Packs a RoveCommPacket into a byte buffer in network order
size_t packPacket(uint8_t *dest, const uint16_t dataId, const uint16_t dataCount, const data_type_t dataType,
                  const uint8_t *data) {
    // Pack header
    dest[0] = ROVECOMM_VERSION;
    dest[1] = dataId >> 8;
    dest[2] = dataId;
    dest[3] = dataCount >> 8;
    dest[4] = dataCount;
    dest[5] = dataType;

    size_t typeSize = dataTypeSize(dataType);
    if (typeSize == 0) return 0;
    if (typeSize * dataCount > ROVECOMM_PACKET_MAX_DATA_COUNT) return 0;

    // RoveComm transmits in network byte order, so we must swap the bytes
    size_t bytesWritten = ROVECOMM_PACKET_HEADER_SIZE;
    for (int el = 0; el < dataCount; el++) {
        for (size_t b = 0; b < typeSize; b++) {
            dest[ROVECOMM_PACKET_HEADER_SIZE + el * typeSize + b] = data[el * typeSize + (typeSize - b - 1)];
            bytesWritten += 1;
        }
    }
    return bytesWritten;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Unpacks a byte buffer in network order into a RoveCommPacket
bool unpackPacket(RoveCommPacket &dest, const uint8_t *buffer) {
    // Unpack header
    if (buffer[0] != ROVECOMM_VERSION) {
        dest.dataId = RC_ROVECOMM_INVALID_VERSION_DATA_ID;
        return false;
    }
    dest.dataId = (buffer[1] << 8) | buffer[2];
    dest.dataCount = (buffer[3] << 8) | buffer[4];
    dest.dataType = (buffer[5]);

    size_t typeSize = rovecomm::dataTypeSize(static_cast<rovecomm::data_type_t>(dest.dataType));

    if (typeSize == 0) return false;
    if (typeSize * dest.dataCount > ROVECOMM_PACKET_MAX_DATA_COUNT) return false;

    // RoveComm transmits in network byte order, so we must swap the bytes
    for (int el = 0; el < dest.dataCount; el++) {
        for (size_t b = 0; b < typeSize; b++) {
            dest.data[el * typeSize + b] = buffer[ROVECOMM_PACKET_HEADER_SIZE + (el * typeSize + 1) - b - 1];
        }
    }
    return true;
}

} // namespace rovecomm
