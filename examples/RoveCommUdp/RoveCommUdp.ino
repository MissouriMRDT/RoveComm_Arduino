//Example of receiving and writing rovecomm data for a mock driveboard

#include "RoveComm.h"
#if defined(ENERGIA)
#include "RoveWatchdog.h"
#elif defined(ARDUINO_TEENSY41) 
#include <TimerOne.h>
#endif

RoveCommEthernet RoveComm;
rovecomm_packet packet;

int16_t motor_speed[6] = {-500, 200, 740, -720, 10, -182};

//declare the Ethernet Server in the top level sketch with the requisite port ID any time you want to use RoveComm
EthernetServer TCPServer(RC_ROVECOMM_DRIVEBOARD_PORT);
#if defined(ENERGIA)
RoveWatchdog Watchdog;
void setup() 
{
  Serial.begin(9600);
  Watchdog.attach(Telemetry);
  //Set up rovecomm with the correct IP and the TCP server
  RoveComm.begin(RC_DRIVEBOARD_FOURTHOCTET, &TCPServer);
  delay(100);
  Watchdog.start(ROVECOMM_UPDATE_RATE);
  Serial.println("Started: ");
}
void Telemetry()
{
    RoveComm.write(RC_DRIVEBOARD_DRIVESPEEDS_DATA_ID, RC_DRIVEBOARD_DRIVESPEEDS_DATA_COUNT, motor_speed);
    Watchdog.clear();
}
#elif defined(ARDUINO_TEENSY41) 
void setup() 
{
  Serial.begin(9600);
  Timer1.initialize(100000);
  Timer1.attachInterrupt(Telemetry);
  //Set up rovecomm with the correct IP and the TCP server
  RoveComm.begin(RC_DRIVEBOARD_FOURTHOCTET, &TCPServer, RC_ROVECOMM_DRIVEBOARD_MAC);
  delay(100);
  Serial.println("Started: ");
}
void Telemetry()
{
    RoveComm.write(RC_DRIVEBOARD_DRIVESPEEDS_DATA_ID, RC_DRIVEBOARD_DRIVESPEEDS_DATA_COUNT, motor_speed);
}
#endif

void loop() 
{
  packet = RoveComm.read();

  Serial.println("Data id: ");
  Serial.println(packet.data_id);

  switch(packet.data_id)
  {
    case RC_DRIVEBOARD_DRIVEINDIVIDUAL_DATA_ID:
      Serial.println("We received an individual wheel drive command");
      break;
    case RC_DRIVEBOARD_DRIVELEFTRIGHT_DATA_ID:
      //cast the packet to the correct data type
      int16_t* speeds;
      speeds = (int16_t*)packet.data;
      
      //print out speeds nicely formatted
      Serial.println("We received a left/right drive command:");

      char buf[100];
      sprintf(buf, "Left: %d, Right: %d", speeds[0], speeds[1]);
      Serial.println(buf);

      //set the motor speeds to the commanded speeds in RoveComm
      motor_speed[0] = speeds[0];
      motor_speed[1] = speeds[0];
      motor_speed[2] = speeds[0];
      motor_speed[3] = speeds[1];
      motor_speed[4] = speeds[1];
      motor_speed[5] = speeds[1];
      break;
    default:
      Serial.println("Unexpected data id: ");
      Serial.println(packet.data_id);
      break;
  }
}