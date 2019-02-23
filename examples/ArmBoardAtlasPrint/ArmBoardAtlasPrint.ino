#include "RoveComm.h"
#include "RoveTimerInterrupt.h"

RoveCommAtlasEthernet RoveComm;
RoveTimerInterrupt    TelemetryScanTimer;

void telemetryScan() //////////////////////////////////////////////////////////////////////////////////////////////////
{ 
  static float degrees   =             0.0;
  float  telem_degrees[] = { degrees + 1.1, degrees + 2.2, degrees + 3.3, degrees + 4.4, 
                             degrees + 5.5, degrees + 6.6, degrees + 7.7, degrees + 8.8 };
                            
  if( degrees < 351.2 )    { degrees = degrees + 1.0; }
  else                     { degrees = 0.0;           }

  Serial.println();           Serial.print( "Telemetry Scan Joint degrees " ); 
  for( int i=0; i < 8; i++ ){ Serial.print(  telem_degrees[ i ] ); 
                              Serial.print( ", " );            }  Serial.println(); 
    
  RoveComm.writeTo( roveware::atlas::TELEM_ARMBOARD_MILLIDEGREES.DATA_ID, 
                  roveware::atlas::TELEM_ARMBOARD_MILLIDEGREES.DATA_COUNT * sizeof(float), // RoveComm1 used data_byte_count
                  telem_degrees, 100 );

  //////////////////////////////////////
  //TELEM_ARMBOARD_MILLAMPS ????  /////
  //TELEM_ARMBOARD_MILLIDEGREES = 0x318,
  //TELEM_ARMBOARD_FAULT        = 0x340,
  //TELEM_ARMBOARD_XYZ          = 0x31A*/
} 


void setup() /////////////////////////////////////////////////////
{
  pinMode(PN_1, OUTPUT);
  Serial.begin( 9600 );
  RoveComm.begin( roveware::atlas::IP::ARMBOARD );
  TelemetryScanTimer.attachMillis( telemetryScan, T7_B, 5000 );
  TelemetryScanTimer.start();
}


void loop() ////////////////////////////////////////////////////////////////////////////////
{
  RoveCommAtlasPacket RoveCommPacket = RoveComm.read();

  //////////////////////////////////////////////////////////////////////////////
  if( RoveCommPacket.data_id != roveware::atlas::ROVECOMM_NO_RX.DATA_ID )
  {
    float seconds = millis() / 1000.0;

    Serial.print( "Read: " );
    Serial.print( "  Seconds : "  ); Serial.println( seconds ); 
    Serial.print( ", Remote Ip: " ); Serial.println( RoveCommPacket.remote_ip );
    Serial.print( ", Data   Id: " ); Serial.println( RoveCommPacket.data_id   );
  }

  //////////////////////////////////////////////////////////////////////////////////////////
  if( RoveCommPacket.data_id  == roveware::atlas::ROVECOMM_RX_ID_UNKNOWN.DATA_ID )
  { Serial.print("ROVECOMM_RX_ID_UNKNOWN: "); Serial.println( RoveCommPacket.data_id );  }

  ///////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_ESTOP.DATA_ID )
  { Serial.println("CMD_ARMBOARD_ESTOP");  }

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

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_INVERT_GRIPPER_COMMANDS.DATA_ID )
  { Serial.println(                                   "CMD_ARMBOARD_INVERT_GRIPPER_COMMANDS: " ); }

  /////////////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_DRIVE_GRIPPER_DECIPERCENT.DATA_ID )
  { Serial.println(                                   "CMD_ARMBOARD_DRIVE_GRIPPER_DECIPERCENT: " ); 
 
    uint16_t*  decipercents = (uint16_t*)RoveCommPacket.data_bytes;
    Serial.print( "Gripper: " );        Serial.println( decipercents[0] ); }

  ///////////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_DRIVE_POKER_DECIPERCENT.DATA_ID )
  { Serial.println(                                   "CMD_ARMBOARD_DRIVE_POKER_DECIPERCENT: " );
 
    uint16_t* decipercents = (uint16_t*)RoveCommPacket.data_bytes;
    Serial.print( "Poker: " );         Serial.println( decipercents[0] ); }

  /////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_ALLOW_OVERTRAVEL.DATA_ID )
  { Serial.println(                                   "CMD_ARMBOARD_ALLOW_OVERTRAVEL: " );
 
    uint8_t joint = RoveCommPacket.data_bytes[0];

    if      ( joint == 1 ){ Serial.println( "Shoulder pitch limit allow overtravel " ); }
    else if ( joint == 0 ){ Serial.println( "Shoulder roll  limit allow overtravel " ); } 
    else if ( joint == 2 ){ Serial.println( "Elbow    pitch limit allow overtravel " ); } }

  ///////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_DISALLOW_OVERTRAVEL.DATA_ID )
  { Serial.println(                         "CMD_ARMBOARD_DISALLOW_OVERTRAVEL: " );
 
    uint8_t joint = RoveCommPacket.data_bytes[0];

    if      ( joint == 1 ){ Serial.println( "Shoulder pitch limit disallow overtravel " ); }
    else if ( joint == 0 ){ Serial.println( "Shoulder roll  limit disallow overtravel " ); } 
    else if ( joint == 2 ){ Serial.println( "Elbow    pitch limit disallow overtravel " ); } }

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

  //////////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_SET_IK_OPERATING_POINT.DATA_ID )
  { Serial.println(                                   "CMD_ARMBOARD_SET_IK_OPERATING_POINT: " ); 
  
    float* coordinates  = (float*)RoveCommPacket.data_bytes; // wtf int16_t for increment ik?

    Serial.print(  "Ik operating point offset dX_1 ?:  " ); Serial.println( coordinates[0] ); 
    Serial.print(  "Ik operating point offset dY_1 ?:  " ); Serial.println( coordinates[1] ); 
    Serial.print(  "Ik operating point offset dZ_1 ?:  " ); Serial.println( coordinates[2] ); }

  ////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_MOVE_IK_XYZ.DATA_ID )
  { Serial.println(                                   "CMD_ARMBOARD_MOVE_IK_XYZ: " ); 
  
    float* coordinates = (float*)RoveCommPacket.data_bytes;

    Serial.print(  "X_1 ?: " ); Serial.println( coordinates[0] ); 
    Serial.print(  "Y_1 ?: " ); Serial.println( coordinates[1] ); 
    Serial.print(  "Z_1 ?: " ); Serial.println( coordinates[2] ); 
    Serial.print(  "X_2 ?: " ); Serial.println( coordinates[3] ); 
    Serial.print(  "Y_2 ?: " ); Serial.println( coordinates[4] ); 
    Serial.print(  "Z_2 ?: " ); Serial.println( coordinates[5] ); }

  /////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_MOVE_IK_dXYZ.DATA_ID )
  { Serial.println(                                   "CMD_ARMBOARD_MOVE_IK_dXYZ: " ); 
  
    int16_t* coordinates  = (int16_t*)RoveCommPacket.data_bytes; // wtf int16_t for increment ik?
    int16_t* decipercents = (int16_t*)RoveCommPacket.data_bytes;

    Serial.print(  "dX_1 ?:  " ); Serial.println( coordinates[0] ); 
    Serial.print(  "dY_1 ?:  " ); Serial.println( coordinates[1] ); 
    Serial.print(  "dZ_1 ?:  " ); Serial.println( coordinates[2] ); 
    Serial.print(  "dX_2 ?:  " ); Serial.println( coordinates[3] ); 
    Serial.print(  "dY_2 ?:  " ); Serial.println( coordinates[4] ); 
    Serial.print(  "dZ_2 ?:  " ); Serial.println( coordinates[5] ); 
    Serial.print(  "Gripper: " ); Serial.println( decipercents[6] ); 
    Serial.print(  "Poker:   " ); Serial.println( decipercents[7] ); }

  ///////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_MOVE_WRIST_IK_dXYZ.DATA_ID )
  { Serial.println(                                   "CMD_ARMBOARD_MOVE_WRIST_IK_dXYZ: " ); 
  
    int16_t* coordinates  = (int16_t*)RoveCommPacket.data_bytes; // wtf int16_t for increment ik?

    Serial.print(  "Wrist dX_1 ?:  " ); Serial.println( coordinates[0] ); 
    Serial.print(  "Wrist dY_1 ?:  " ); Serial.println( coordinates[1] ); 
    Serial.print(  "Wrist dZ_1 ?:  " ); Serial.println( coordinates[2] ); 
    Serial.print(  "Wrist dX_2 ?:  " ); Serial.println( coordinates[3] ); 
    Serial.print(  "Wrist dY_2 ?:  " ); Serial.println( coordinates[4] ); 
    Serial.print(  "Wrist dZ_2 ?:  " ); Serial.println( coordinates[5] ); }

  //////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_ENABLE_ALL.DATA_ID )
  { Serial.println(                                   "CMD_ARMBOARD_ENABLE_ALL: " ); 
  
    bool* enable  = (bool*)RoveCommPacket.data_bytes;
    
    Serial.print(  "Enable Shoulder pitch      motor:  " ); Serial.println( enable[1] );
    Serial.print(  "Enable Shoulder roll       motor:  " ); Serial.println( enable[0] ); 
    Serial.print(  "Enable Elbow    pitch      motor:  " ); Serial.println( enable[2] ); 
    Serial.print(  "Enable Elbow    roll       motor:  " ); Serial.println( enable[3] ); 
    Serial.print(  "Enable Wrist    pitch/roll motors: " ); Serial.println( enable[4] ); 
    Serial.print(  "Enable Gripper             motor:  " ); Serial.println( enable[5] ); 
    Serial.print(  "Enable Poker               motor:  " ); Serial.println( enable[6] ); }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_ENABLE_MAIN.DATA_ID )
  { Serial.println(                                   "CMD_ARMBOARD_ENABLE_MAIN: " ); 
    Serial.print(                                     "Enable:  " ); Serial.println( ((bool*)RoveCommPacket.data_bytes)[0] ); }

  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_ENABLE_SHOULDER_PITCH.DATA_ID ) ///////////////////////////
  { Serial.println(                                   "CMD_ARMBOARD_ENABLE_SHOULDER_PITCH: " ); 
    Serial.print(                                     "Enable:  " ); Serial.println( ((bool*)RoveCommPacket.data_bytes)[0] ); }

  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_ENABLE_SHOULDER_ROLL.DATA_ID ) ////////////////////////////
  { Serial.println(                                   "CMD_ARMBOARD_ENABLE_SHOULDER_ROLL: " ); 
    Serial.print(                                     "Enable:  " ); Serial.println( ((bool*)RoveCommPacket.data_bytes)[0] ); }

  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_ENABLE_ELBOW_PITCH.DATA_ID ) //////////////////////////////
  { Serial.println(                                   "CMD_ARMBOARD_ENABLE_ELBOW_PITCH: " ); 
    Serial.print(                                     "Enable:  " ); Serial.println( ((bool*)RoveCommPacket.data_bytes)[0] ); }

  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_ENABLE_ELBOW_ROLL.DATA_ID ) ///////////////////////////////
  { Serial.println(                                   "CMD_ARMBOARD_ENABLE_ELBOW_ROLL: " ); 
    Serial.print(                                     "Enable:  " ); Serial.println( ((bool*)RoveCommPacket.data_bytes)[0] ); }

  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_ENABLE_WRIST_PITCH_ROLL.DATA_ID ) /////////////////////////
  { Serial.println(                                   "CMD_ARMBOARD_ENABLE_WRIST_PITCH_ROLL: " ); 
    Serial.print(                                     "Enable:  " ); Serial.println( ((bool*)RoveCommPacket.data_bytes)[0] ); }

  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_ENABLE_WRIST_PITCH_ROLL2.DATA_ID )
  { Serial.println(                                   "CMD_ARMBOARD_ENABLE_WRIST_PITCH_ROLL_REDUNDANT: " ); 
    Serial.print(                                     "Enable:  " ); Serial.println( ((bool*)RoveCommPacket.data_bytes)[0] ); }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_ENABLE_GRIPPER.DATA_ID )
  { Serial.println(                                   "CMD_ARMBOARD_ENABLE_GRIPPER: " ); 
    Serial.print(                                     "Enable:  " ); Serial.println( ((bool*)RoveCommPacket.data_bytes)[0] ); }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARMBOARD_ENABLE_POKER.DATA_ID )
  { Serial.println(                                   "CMD_ARMBOARD_ENABLE_POKER: " ); 
    Serial.print(                                      "Enable:  " ); Serial.println( ((bool*)RoveCommPacket.data_bytes)[0] ); }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ENABLE_TELEM_STREAM_JOINT_DEGREES.DATA_ID )
  { Serial.println(                                   "CMD_ENABLE_TELEM_STREAM_JOINT_DEGREES: " ); 
    Serial.print(                                     "Enable:  " ); Serial.println( ((bool*)RoveCommPacket.data_bytes)[0] ); }

  /////////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARM_READ_MAIN_CURRENT_REQUEST.DATA_ID )
  { Serial.println(                                   "CMD_ARM_READ_MAIN_CURRENT_REQUEST: " ); }

  //////////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARM_READ_JOINT_DEGREES_REQUEST.DATA_ID )
  { Serial.println(                                   "CMD_ARM_READ_JOINT_DEGREES_REQUEST: " ); }

  ///////////////////////////////////////////////////////////////////////////////////////////////////
  else if( RoveCommPacket.data_id  == roveware::atlas::CMD_ARM_READ_IK_COORDINATES_REQUEST.DATA_ID )
  { Serial.println(                                   "CMD_ARM_READ_IK_COORDINATES_REQUEST: " ); }

  delay(1);
}