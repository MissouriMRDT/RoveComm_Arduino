// Example of waiting for a request and responding with an important reading from an instrument

#include <Arduino.h>

#include "RoveCommEthernetTCP.h"

/***********************************************************************************************************************
 * When should you use TCP?
 * Transmission Control Protocol (TCP) guarantees all data is delivered and in the correct order. It requires a
 * connection to be established between the sender and receiver. Also, instead of discrete packets, it sends a stream
 * of bytes. We almost never use TCP since we usually just send short dcommands that we can send again if the rover
 * doesn't respond.
 **********************************************************************************************************************/

void setup() {
    // start up serial communication
    Serial.begin(9600);

    // initialize rovecomm
    Serial.println("Initializing rovecomm...");
    RoveComm.begin(RC_COREBOARD_IPADDRESS);
    Serial.println("RoveComm initialized.");
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
    case RC_INSTRUMENTSBOARD_REQUESTREFLECTANCEREADING_DATA_ID:
        takeReading();
        sendData();
        break;
    }
}

void takeReading() {
    Serial.println("Reading reflectance data...");
    for (int i = 0; i < RC_INSTRUMENTSBOARD_REFLECTANCEREADING_DATA_COUNT; i++) {
        reflectanceData[i] = random(256);
        delay(10);
    }
    Serial.println("Rinished reading.");
}

void sendData() {
    // send to reflectanceData to all open TCP connections
    RoveComm.writeReliable(RC_INSTRUMENTSBOARD_REFLECTANCEREADING_DATA_ID,
                           RC_INSTRUMENTSBOARD_REFLECTANCEREADING_DATA_COUNT, reflectanceData);
}
