// Example of receiving and writing rovecomm data for a mock COREBOARD

#include <Arduino.h>

#include "RoveCommEthernetUDP.h"

/***********************************************************************************************************************
 * When should you use UDP?
 * User Datagram Protocol (UDP) does not guarantee that all data is delivered and in the correct order. However, it is
 * easier to work with as it does not require a connection to be established and maintained. We use UDP for almost
 * everything, since our packets are small in size and can be resent if the rover doesn't respond.
 **********************************************************************************************************************/

void setup() {
    // start up serial communication
    Serial.begin(9600);

    // initialize rovecomm
    Serial.println("Initializing rovecomm...");
    RoveComm.begin(RC_COREBOARD_IPADDRESS);
    Serial.println("RoveComm initialized!");

    lastTelemetry = millis();
}

void loop() {
    // read newest data into our packet variable
    // if no data is available or there is no connection, the packet.dataId will be set to RC_ROVECOMM_NO_DATA_DATA_ID
    // if a packet with an incorrect version makes it into the network, packet.dataID will be
    // RC_ROVECOMM_INVALID_VERSION_DATA_ID as a convenience, RoveComm.read(packet) will return false if either of these
    // error codes are returned
    if (RoveComm.read(packet)) {
        // Print the data id
        Serial.printf("Received a packet with data id: %d\n", packet.dataId);
    }

    // change behavior based on packet id
    // you can find all known dataId's in RoveCommManifest.h
    switch (packet.dataId) {
    // because we declare a new variable inside this case block, we need to declare a scope for it
    case RC_COREBOARD_DRIVEINDIVIDUAL_DATA_ID: {
        // cast the packet to the correct data type
        float *speeds = (float *)packet.data;

        Serial.println("We received an individual wheel drive command:");
        for (int i = 0; i < RC_COREBOARD_DRIVESPEEDS_DATA_COUNT; i++) {
            Serial.print(motorSpeeds[i]);
            Serial.print(", ");
        }
        Serial.println();

        // set the motor speeds to the commanded speeds in RoveComm
        motorSpeeds[0] = speeds[0];
        motorSpeeds[1] = speeds[1];
        motorSpeeds[2] = speeds[2];
        motorSpeeds[3] = speeds[3];
        motorSpeeds[4] = speeds[4];
        motorSpeeds[5] = speeds[5];
        break;
    }
    case RC_COREBOARD_DRIVELEFTRIGHT_DATA_ID: {
        // cast the packet to the correct data type
        float *speeds = (float *)packet.data;

        Serial.println("We received a left/right drive command:");
        Serial.printf("Left: %f, Right: %f\n", speeds[0], speeds[1]);

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

    driveRover();

    // if it has been more than 150 milliseconds
    if (millis() - lastTelemetry >= TELEMETRY_PERIOD) {
        telemetry();
        lastTelemetry = millis();
    }
}

void driveRover() {
    // drive the rover
    Serial.println("Driving the rover!");
}

void telemetry() {
    // send over UDP to all subscribed IP addresses
    RoveComm.write(RC_COREBOARD_DRIVESPEEDS_DATA_ID, RC_COREBOARD_DRIVESPEEDS_DATA_COUNT, motorSpeeds);
}
