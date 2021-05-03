# RoveComm
The UDP packet protocol used by MRDT modular microcontrollers

## Dependencies
The current implementation of RoveComm is for the Tiva C Microcontrollers. The ethernet libraries used are from the Energia project.

## Packet Structure
The RoveComm udp packet header is 6 bytes long:
* uint8_t rovecomm_version
* uint16_t data_id   
* uint8_t  data_type
* uint16_t  data_count

The packet then countains a data_count number of data elements. The size of each element depends on the data type.

## Use
Examples of how to implement RoveComm on the Tiva C Microcontrollers are [here](https://github.com/MissouriMRDT/RoveComm/tree/master/examples).
