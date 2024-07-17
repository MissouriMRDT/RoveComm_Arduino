#include <RoveComm.h>

#define ROVECOMM_UPDATE_RATE 100

// create rovecomm context
RoveCommEthernet RoveComm;
// packets can be quite large so better to keep just one around
RoveCommPacket packet;

// timekeeping variable
uint32_t last_update_time = 0;

// example functions
void driveRover(float left, float right) {
    Serial.println("Driving rover!");
}
void rotateCamera(uint16_t rotation) {
    Serial.println("Rotating camera!");
}

void setup() {
    // start up serial communication
    Serial.begin(9600);

    // initialize rovecomm
    Serial.println("Initializing rovecomm...");
    RoveComm.begin(RC_COREBOARD_IPADDRESS);
    Serial.println("RoveComm initialized!");

    last_update_time = millis();
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
    switch (packet.dataId) {
        case RC_COREBOARD_DRIVELEFTRIGHT_DATA_ID:
        // because we declare a new variable inside this case block, we need to declare a scope for it
        {
            // get data from packet - we know from the manifest that the DriveLeftRight will contain 2 floats
            // packet.data is uint8_t pointer, so we must tell C++ to interpret it as a float pointer instead
            float *driveSpeeds = (float*)packet.data;
            driveRover(driveSpeeds[0], driveSpeeds[1]);
            break;
        }
        // No scope is needed since no variables are declared
        case RC_COREBOARD_LEFTDRIVEGIMBALINCREMENT_DATA_ID:
            // we know from the manifest that LeftDriveGimbalIncrement will contain 1 uint16_t
            rotateCamera(((uint16_t*)packet.data)[0]); 
    }

    // write some sample data back every 100 milliseconds, it is important that any
    // telemetry is NOT rate limited (using delays) as this will prevent
    // packets from arriving in a timely manner 

    if (millis() - last_update_time >= ROVECOMM_UPDATE_RATE) {
        // send to all TCP connections
        RoveComm.writeReliable(9600, 1, (uint8_t)1);
        RoveComm.writeReliable(9600, 1, (uint8_t)2);
        RoveComm.writeReliable(9600, 1, (uint8_t)3);

        last_update_time = millis();
    }
} 
