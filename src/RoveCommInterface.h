#ifndef ROVECOMM_INTERFACE_H
#define ROVECOMM_INTERFACE_H

#include "RoveCommManifest.h"
#include "RoveCommPacket.h"

/**
 * @brief An interface used internally by RoveComm to share boilerplate between
 * RoveCommEthernet, RoveCommWifi, etc
 * 
 */
class RoveCommInterface {
    /**
     * @brief Send data to all subscribers via UDP. Overloaded for each data type.
     * 
     * @param dataId ID of this packet. e.g. RC_COREBOARD_DRIVELEFTRIGHT_DATA_ID
     * @param dataCount How many elements are in the data array.
     * @param data The data to send.
     */
    void write(uint16_t dataId, uint16_t dataCount, const uint8_t  *data) { _write(rovecomm::UINT8_T,  dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const uint16_t *data) { _write(rovecomm::UINT16_T, dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const uint32_t *data) { _write(rovecomm::UINT32_T, dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const int8_t   *data) { _write(rovecomm::INT8_T,   dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const int16_t  *data) { _write(rovecomm::INT16_T,  dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const int32_t  *data) { _write(rovecomm::INT32_T,  dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const float    *data) { _write(rovecomm::FLOAT,    dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const double   *data) { _write(rovecomm::DOUBLE,   dataId, dataCount, data); }
    void write(uint16_t dataId, uint16_t dataCount, const char     *data) { _write(rovecomm::CHAR,     dataId, dataCount, data); }

    /**
     * @brief Convenience method for sending a single value to all subscribers via UDP. Overloaded for each data type.
     * 
     * @param dataId ID of this packet. e.g. RC_COREBOARD_WATCHDOGOVERRIDE_DATA_ID
     * @param data The datum to send.
     */
    void write(uint16_t dataId, uint16_t dataCount, uint8_t  data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, uint16_t data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, uint32_t data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, int8_t   data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, int16_t  data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, int32_t  data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, float    data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, double   data) { write(dataId, 1, &data); }
    void write(uint16_t dataId, uint16_t dataCount, char     data) { write(dataId, 1, &data); }

    /**
     * @brief Send data to a specific IP address via UDP. The packet is not sent to this board's subscribers.
     * Overloaded for each data type.
     * 
     * @param dataId ID of this packet. e.g. RC_COREBOARD_DRIVELEFTRIGHT_DATA_ID
     * @param dataCount How many elements are in the data array.
     * @param data The data to send.
     * @param ip The destination IP for this packet.
     * @param port The destination port for this packet.
     */
    void writeTo(uint16_t dataId, uint16_t dataCount, const uint8_t  *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::UINT8_T,  dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const uint16_t *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::UINT16_T, dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const uint32_t *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::UINT32_T, dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const int8_t   *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::INT8_T,   dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const int16_t  *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::INT16_T,  dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const int32_t  *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::INT32_T,  dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const float    *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::FLOAT,    dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const double   *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::DOUBLE,   dataId, dataCount, data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t dataCount, const char     *data, IPAddress ip, uint16_t port) { _writeTo(rovecomm::CHAR,     dataId, dataCount, data, ip, port); }

    /**
     * @brief Convenience method for sending a single value to a specific IP address via UDP.
     * The packet is not sent to this board's subscribers. Overloaded for each data type.
     * 
     * @param dataId ID of this packet. e.g. RC_COREBOARD_WATCHDOGOVERRIDE_DATA_ID
     * @param data The datum to send.
     * @param ip The destination IP for this packet.
     * @param port The destination port for this packet.
     */
    void writeTo(uint16_t dataId, uint8_t  data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, uint16_t data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, uint32_t data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, int8_t   data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, int16_t  data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, int32_t  data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, float    data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, double   data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }
    void writeTo(uint16_t dataId, char     data, IPAddress ip, uint16_t port) { writeTo(dataId, 1, &data, ip, port); }

protected:

    virtual void _write(const rovecomm::data_type_t dataType, const uint16_t dataId, const uint16_t dataCount, const void *data) = 0;
    virtual void _writeTo(const rovecomm::data_type_t dataType, const uint16_t dataId, const uint16_t dataCount, const void *data,
                          const IPAddress ip, const uint16_t port) = 0;

};

#endif // ROVECOMM_INTERFACE_H