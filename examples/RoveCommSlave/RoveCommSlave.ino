#include "RoveComm.h"
#include "RoveTimerInterrupt.h"

RoveCommAtlasEthernet RoveComm;
RoveTimerInterrupt    ScanTimer;

void scan() ///////////////////////////////////////////////////////////////////////////////////////////
{ 
  int16_t data[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

  RoveComm.write( roveware::atlas::CMD_ARMBOARD_DRIVE_DECIPERCENT.DATA_ID, sizeof(int16_t) * 8, data );
} 

void setup() /////////////////////////////////////////////////////
{
  pinMode(PN_1, OUTPUT);
  Serial.begin( 9600 );
  RoveComm.begin( 2 );
  ScanTimer.attachMillis( scan, T7_B, 5000 );
  ScanTimer.start();
}

void loop() ////////////////////////////////////////////////////////////////////////////////
{
  RoveCommAtlasPacket RoveCommPacket = RoveComm.read();
  static bool toggle = false;

  ///////////////////////////////////////////////////////////////////////////////////
  if( RoveCommPacket.data_id == roveware::atlas::ROVECOMM_SUBSCRIBE_REQUEST.DATA_ID )
  {
    digitalWrite( PN_1, toggle=!toggle );
  }

  /////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_DRIVE_DECIPERCENT.DATA_ID )
  { Serial.println(                                   "CMD_ARMBOARD_DRIVE_DECIPERCENT: " ); 

  /////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_DRIVE_DECIPERCENT.DATA_ID )
  { Serial.println(                                   "CMD_ARMBOARD_DRIVE_DECIPERCENT: " ); 

    uint16_t* decipercents = (uint16_t*)RoveCommPacket.data_bytes;

    Serial.print(  "Shoulder pitch: " ); Serial.println( decipercents[1] ); // gross axis order here you atlas guys...
    Serial.print(  "Shoulder roll:  " ); Serial.println( decipercents[0] ); 
    Serial.print(  "Elbow    pitch: " ); Serial.println( decipercents[2] ); 
    Serial.print(  "Elbow    roll:  " ); Serial.println( decipercents[3] ); 
    Serial.print(  "Wrist    pitch: " ); Serial.println( decipercents[4] ); 
    Serial.print(  "Wrist    roll:  " ); Serial.println( decipercents[5] ); 
    Serial.print(  "Gripper:        " ); Serial.println( decipercents[6] ); 
    Serial.print(  "Poker:          " ); Serial.println( decipercents[7] ); }

  /////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_MOVE_DEGREES.DATA_ID )
  { Serial.println(                         "CMD_ARMBOARD_MOVE_DEGREES: " ); 

    float* degrees = (float*)RoveCommPacket.data_bytes;

    Serial.print( "Shoulder pitch: " ); Serial.println( degrees[1] ); 
    Serial.print( "Shoulder roll:  " ); Serial.println( degrees[0] ); 
    Serial.print(  "Elbow   pitch: " ); Serial.println( degrees[2] ); 
    Serial.print(  "Elbow   roll:  " ); Serial.println( degrees[3] ); 
    Serial.print(  "Wrist   pitch: " ); Serial.println( degrees[4] ); 
    Serial.print(  "Wrist   roll:  " ); Serial.println( degrees[5] ); }

  delay(1);
}