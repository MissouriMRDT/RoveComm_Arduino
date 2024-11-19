#ifndef ROVECOMM_UDP_H
#define ROVECOMM_UDP_H

#include <IntervalTimer.h>

// in your header file, include RoveComm.h and declare an instance of RoveCommEthernet
#include <RoveComm.h>
// create rovecomm context
RoveCommEthernet RoveComm;
// packets can be quite large so better to keep just one around
RoveCommPacket packet;

// timekeeping variable
uint32_t last_update_time = 0;

// initialize motor speeds to 0
float motorSpeeds[RC_COREBOARD_DRIVESPEEDS_DATA_COUNT] = {0};

void driveRover();

// we will set up a timer to periodically send the current drive speeds (not required)
#define TELEMETRY_PERIOD 150 // milliseconds
uint32_t lastTelemetry;
void telemetry();

#endif // ROVECOMM_UDP_H
