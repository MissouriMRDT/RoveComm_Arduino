#ifndef ROVECOMM_TCP_H
#define ROVECOMM_TCP_H

// in your header file, include RoveComm.h and declare an instance of RoveCommEthernet
#include <RoveComm.h>
// create rovecomm context
RoveCommEthernet RoveComm;
// packets can be quite large so better to keep just one around
RoveCommPacket packet;

uint8_t reflectanceData[RC_INSTRUMENTSBOARD_REFLECTANCEREADING_DATA_COUNT];
void takeReading();
void sendData();

#endif // ROVECOMM_TCP_H
