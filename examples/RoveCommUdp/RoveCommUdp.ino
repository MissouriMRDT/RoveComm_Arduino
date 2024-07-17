//Example of receiving and writing rovecomm data for a mock driveboard

#include <RoveComm.h>

// create rovecomm context
RoveCommEthernet RoveComm;
// packets can be quite large so better to keep just one around
RoveCommPacket packet;

int16_t motorSpeeds[RC_DRIVEBOARD_DRIVESPEEDS_DATA_COUNT] = {-500, 200, 740, -720, 10, -182};

// we will set up a timer to periodically send the current drive speeds (not required)
void telemetry() {
    // send over UDP to all subscribed IP addresses
    RoveComm.write(RC_DRIVEBOARD_DRIVESPEEDS_DATA_ID, RC_DRIVEBOARD_DRIVESPEEDS_DATA_COUNT, motorSpeeds);
}
// the hardware timer that will call telemetry() using an interrupt
#define TELEMETRY_PERIOD 150'000 // microseconds
IntervalTimer Telemetry;

void setup() {
    // start up serial communication
    Serial.begin(9600);

    // initialize rovecomm
    Serial.println("Initializing rovecomm...");
    RoveComm.begin(RC_COREBOARD_IPADDRESS);
    Serial.println("RoveComm initialized!");

    Telemetry.begin(telemetry, TELEMETRY_PERIOD);
}

void loop() {
    // read newest data into our packet variable
    // if no data is available or there is no connection, the packet.dataId will be set to RC_ROVECOMM_NO_DATA_DATA_ID
    // if a packet with an incorrect version makes it into the network, packet.dataID will be RC_ROVECOMM_INVALID_VERSION_DATA_ID
    // as a convenience, RoveComm.read(packet) will return false if either of these error codes are returned
    if (RoveComm.read(packet)) {
        // Print the data id
        Serial.printf("Received a packet with data id: %d\n", packet.dataId);
    }

    // change behavior based on packet id
    // you can find all known dataId's in RoveCommManifest.h
    switch(packet.data_id) {
        // because we declare a new variable inside this case block, we need to declare a scope for it
        case RC_DRIVEBOARD_DRIVEINDIVIDUAL_DATA_ID:
        {
            // cast the packet to the correct data type
            int16_t *speeds = (int16_t*)packet.data;

            Serial.println("We received an individual wheel drive command:");
            for (int i = 0; i < RC_DRIVEBOARD_DRIVESPEEDS_DATA_COUNT; i++) {
                Serial.print(motorSpeeds[i]);
                Serial.print(", ");
            }

            // set the motor speeds to the commanded speeds in RoveComm
            motorSpeeds[0] = speeds[0];
            motorSpeeds[1] = speeds[1];
            motorSpeeds[2] = speeds[2];
            motorSpeeds[3] = speeds[3];
            motorSpeeds[4] = speeds[4];
            motorSpeeds[5] = speeds[5];
            break;
        }
        case RC_DRIVEBOARD_DRIVELEFTRIGHT_DATA_ID:
        {
            // cast the packet to the correct data type
            int16_t *speeds = (int16_t*)packet.data;

            Serial.println("We received a left/right drive command:");
            Serial.printf("Left: %d, Right: %d\n", speeds[0], speeds[1]);

            // set the motor speeds to the commanded speeds in RoveComm
            motorSpeeds[0] = speeds[0];
            motorSpeeds[1] = speeds[0];
            motorSpeeds[2] = speeds[0];
            motorSpeeds[3] = speeds[1];
            motorSpeeds[4] = speeds[1];
            motorSpeeds[5] = speeds[1];
            break;
        }
    }
}
