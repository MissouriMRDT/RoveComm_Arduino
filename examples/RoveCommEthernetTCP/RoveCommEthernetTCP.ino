#include "RoveComm.h"
#if defined(ARDUINO_TEENSY41) 
#include <TimerOne.h>
#endif
//rovecomm and packet instances
RoveCommEthernet RoveComm;
rovecomm_packet packet; 

//timekeeping variables
uint32_t last_update_time;

//declare the Ethernet Server in the top level sketch with the requisite port ID any time you want to use RoveComm
EthernetServer TCPServer(RC_ROVECOMM_DRIVEBOARD_PORT);

void setup()
{
    //start up serial communication
    Serial.begin(9600);

    //initialize the ethernet device and rovecomm instance
    RoveComm.begin(RC_DRIVEBOARD_FOURTHOCTET, &TCPServer);
    delay(100);

    //update timekeeping
    last_update_time = millis();
}

void loop()
{
  packet = RoveComm.read();
  Serial.println(packet.data_id);
  if(packet.data_id != RC_ROVECOMM_NO_DATA_DATA_ID)
  {
      //cast the data to the expected data type
      uint16_t* data = (uint16_t*)packet.data;
      
      //now print out all of the data
      for(int i = 0; i < packet.data_count; i++)
      {
        Serial.println(data[i]);
      }
  }

  //Write some sample data back every 100 milliseconds, it is important that any
  //telemetry is NOT rate limited (using delays) as this will prevent
  //packets from arriving in a timely manner 
 
  if(millis()-last_update_time >= ROVECOMM_UPDATE_RATE)
  {
      RoveComm.writeReliable(9600, 1, (uint8_t)1);
      RoveComm.writeReliable(9600, 1, (uint8_t)2);
      RoveComm.writeReliable(9600, 1, (uint8_t)3);

      last_update_time = millis();
  }
} 