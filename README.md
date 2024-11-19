# RoveComm

The UDP and TCP packet protocol used by MRDT modular microcontrollers

## Cloning / Updating

Since the manifest.json is located in a different repository the steps for cloning and updating the repository are a bit
different than usual. Everytime the manifest.json is updated, the **update** command listed below needs to be executed.

- Clone: `git clone --recurse-submodules https://gitlab.com/MissouriMRDT/RoveComm_Arduino.git`
- Update: `git submodule update --init --recursive`

## Dependencies

The current implementation of RoveComm supports Tiva C and Teensy 4.1 Microcontrollers. The ethernet libraries used are
Energia Ethernet for the Tiva C and NativeEthernet for the Teensy 4.1.

## Packet Structure

A RoveComm packet header is 6 bytes long:

| Field     | Size     | Description                                                  |
| :-------- | -------- | ------------------------------------------------------------ |
| version   | uint8_t  | The version of RoveComm this packet was sent from (always 3) |
| dataId    | uint16_t | A number indicating the purpose of this packet               |
| dataCount | uint16_t | How many elements in this packet's data array                |
| dataType  | uint8_t  | An enum representing the type of the packet's data           |

The packet then countains a `dataCount` number of data elements. The size of each element depends on the `dataType`.

Due to memory limitations, the Tiva can only support 21,845 uint8_ts, 10,922 uint16_ts, 5461 uint32_ts, 5461 floats, or
2730 doubles at once.

Due to memory limitations, the Teensy can only support 32,767 uint8_ts, 16,383 uint16_ts, 8,191 uint32_ts, 8,191 floats,
or 4,095 doubles at once.

## Use

First, include `RoveComm.h` and create an instance of the `RoveCommEthernet` class:

```cpp
#include <RoveComm.h>
RoveCommEthernet RoveComm;
```

Before using RoveComm, you must call `RoveComm.begin()` with the IP address of the board:

```cpp
void setup() {
    // all known ip addresses are already defined in RoveCommManifest.h
    RoveComm.begin(RC_BOARDNAME_IPADDRERSS);
}
```

To read any incoming data, use `RoveComm.read()`:

```cpp
RoveCommPacket packet;
void loop() {
    bool packetWasRead = RoveComm.read(packet);
    if (packetWasRead) {
        // do something with the data
    }
}
```

It is a common pattern to `switch` over the `dataId`:

```cpp
RoveCommPacket packet;
void loop() {
    RoveComm.read(packet);
    switch (packet.dataId) {
    case RC_BOARDNAME_ACTION1_DATAID:
        peformAction1();
    case RC_BOARDNAME_ACTION2_DATAID:
        peformAction2();
    case RC_BOARDNAME_ACTION3_DATAID:
        peformAction3();
    }
}
```

Methods for sending data:

| Method                                                        | Description                                          |
| :------------------------------------------------------------ | ---------------------------------------------------- |
| `RoveComm.write(dataId, dataCount, data);`                    | Send data over UDP to all subscribers                |
| `RoveComm.write(dataId, datum);`                              | Send a single datum over UDP to all subscribers      |
| `RoveComm.writeTo(dataId, dataCount, data, IPAddress, port);` | Send over UDP to the given IP/port                   |
| `RoveComm.writeTo(dataId, datum, IPAddress, port);`           | Send a single datum over UDP to the given IP/port    |
| `RoveComm.writeReliable(dataId, dataCount, data);`            | Send data over TCP to all open connections           |
| `RoveComm.writeReliable(dataId, datum);`                      | Send a single datum over TCP to all open connections |

Examples of how to implement RoveComm on the Tiva C Microcontroller and Teensy 4.1 are [here](/examples).

## Planned Features

- WiFi compatibility (ESP32 boards only)
- Send data to IP/port over TCP with `writeReliableTo()`
