#ifndef RoveCommManifest_h
#define RoveCommManifest_h

#include <stdint.h>
#include"RoveCommPacket.h"

#define RC_BMSBOARD_FIRSTOCTET                    192       
#define RC_BMSBOARD_SECONDOCTET                   168       
#define RC_BMSBOARD_THIRDOCTET                    2         
#define RC_BMSBOARD_FOURTHOCTET                   100       

#define RC_POWERBOARD_FIRSTOCTET                  192       
#define RC_POWERBOARD_SECONDOCTET                 168       
#define RC_POWERBOARD_THIRDOCTET                  2         
#define RC_POWERBOARD_FOURTHOCTET                 101       

#define RC_COREBOARD_FIRSTOCTET                   192       
#define RC_COREBOARD_SECONDOCTET                  168       
#define RC_COREBOARD_THIRDOCTET                   2         
#define RC_COREBOARD_FOURTHOCTET                  110       

#define RC_NAVBOARD_FIRSTOCTET                    192       
#define RC_NAVBOARD_SECONDOCTET                   168       
#define RC_NAVBOARD_THIRDOCTET                    2         
#define RC_NAVBOARD_FOURTHOCTET                   104       

#define RC_SIGNALSTACKBOARD_FIRSTOCTET            192       
#define RC_SIGNALSTACKBOARD_SECONDOCTET           168       
#define RC_SIGNALSTACKBOARD_THIRDOCTET            3         
#define RC_SIGNALSTACKBOARD_FOURTHOCTET           101       

#define RC_ARMBOARD_FIRSTOCTET                    192       
#define RC_ARMBOARD_SECONDOCTET                   168       
#define RC_ARMBOARD_THIRDOCTET                    2         
#define RC_ARMBOARD_FOURTHOCTET                   107       

#define RC_SCIENCEACTUATIONBOARD_FIRSTOCTET       192       
#define RC_SCIENCEACTUATIONBOARD_SECONDOCTET      168       
#define RC_SCIENCEACTUATIONBOARD_THIRDOCTET       2         
#define RC_SCIENCEACTUATIONBOARD_FOURTHOCTET      108       

#define RC_AUTONOMYBOARD_FIRSTOCTET               192       
#define RC_AUTONOMYBOARD_SECONDOCTET              168       
#define RC_AUTONOMYBOARD_THIRDOCTET               3         
#define RC_AUTONOMYBOARD_FOURTHOCTET              100       

#define RC_CAMERA1BOARD_FIRSTOCTET                192       
#define RC_CAMERA1BOARD_SECONDOCTET               168       
#define RC_CAMERA1BOARD_THIRDOCTET                4         
#define RC_CAMERA1BOARD_FOURTHOCTET               100       

#define RC_CAMERA2BOARD_FIRSTOCTET                192       
#define RC_CAMERA2BOARD_SECONDOCTET               168       
#define RC_CAMERA2BOARD_THIRDOCTET                4         
#define RC_CAMERA2BOARD_FOURTHOCTET               101       



#define ROVECOMM_UPDATE_RATE                      100       
#define RC_ROVECOMM_ETHERNET_UDP_PORT             11000     
#define RC_ROVECOMM_ETHERNET_TCP_PORT             12000     


#define RC_ROVECOMM_SUBNET_MAC_FIRST_BYTE         222       
#define RC_ROVECOMM_SUBNET_MAC_SECOND_BYTE        173       


///////////////////////////////////////////////////
////////////        System Packets      ///////////         
///////////////////////////////////////////////////

#define RC_ROVECOMM_PING_DATA_ID                  1         
#define RC_ROVECOMM_PING_REPLY_DATA_ID            2         
#define RC_ROVECOMM_SUBSCRIBE_DATA_ID             3         
#define RC_ROVECOMM_UNSUBSCRIBE_DATA_ID           4         
#define RC_ROVECOMM_INVALID_VERSION_DATA_ID       5         
#define RC_ROVECOMM_NO_DATA_DATA_ID               6         


///////////////////////////////////////////////////
////////////        BMSBOARD            ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//Power rover off but keep BMS active
#define RC_BMSBOARD_ESTOP_DATA_ID                                     1000      
#define RC_BMSBOARD_ESTOP_DATA_COUNT                                  1         
#define RC_BMSBOARD_ESTOP_DATA_TYPE                                   uint8_t   

//Power rover and BMS off
#define RC_BMSBOARD_SUICIDE_DATA_ID                                   1001      
#define RC_BMSBOARD_SUICIDE_DATA_COUNT                                1         
#define RC_BMSBOARD_SUICIDE_DATA_TYPE                                 uint8_t   

//Cycle rover power off and back on
#define RC_BMSBOARD_REBOOT_DATA_ID                                    1002      
#define RC_BMSBOARD_REBOOT_DATA_COUNT                                 1         
#define RC_BMSBOARD_REBOOT_DATA_TYPE                                  uint8_t   

////////////////////Telemetry
//Total current draw from battery
#define RC_BMSBOARD_PACKCURRENT_DATA_ID                               1100      
#define RC_BMSBOARD_PACKCURRENT_DATA_COUNT                            1         
#define RC_BMSBOARD_PACKCURRENT_DATA_TYPE                             float     

//Pack voltage
#define RC_BMSBOARD_PACKVOLTAGE_DATA_ID                               1101      
#define RC_BMSBOARD_PACKVOLTAGE_DATA_COUNT                            1         
#define RC_BMSBOARD_PACKVOLTAGE_DATA_TYPE                             float     

//C1, C2, C3, C4, C5, C6, C7, C8
#define RC_BMSBOARD_CELLVOLTAGE_DATA_ID                               1102      
#define RC_BMSBOARD_CELLVOLTAGE_DATA_COUNT                            8         
#define RC_BMSBOARD_CELLVOLTAGE_DATA_TYPE                             float     

//Temperature inside battery pack
#define RC_BMSBOARD_PACKTEMP_DATA_ID                                  1103      
#define RC_BMSBOARD_PACKTEMP_DATA_COUNT                               1         
#define RC_BMSBOARD_PACKTEMP_DATA_TYPE                                float     

////////////////////Error
//Higher current draw than the battery can support. Rover will Reboot automatically
#define RC_BMSBOARD_OVERCURRENT_DATA_ID                               1200      
#define RC_BMSBOARD_OVERCURRENT_DATA_COUNT                            1         
#define RC_BMSBOARD_OVERCURRENT_DATA_TYPE                             uint8_t   

//(bitmasked) [1-Undervolt, 0-OK]. Rover will EStop automatically
#define RC_BMSBOARD_CELLUNDERVOLTAGE_DATA_ID                          1201      
#define RC_BMSBOARD_CELLUNDERVOLTAGE_DATA_COUNT                       1         
#define RC_BMSBOARD_CELLUNDERVOLTAGE_DATA_TYPE                        uint8_t   

//(bitmasked) [1-Critical, 0-OK]. Rover will Suicide automatically
#define RC_BMSBOARD_CELLCRITICAL_DATA_ID                              1202      
#define RC_BMSBOARD_CELLCRITICAL_DATA_COUNT                           1         
#define RC_BMSBOARD_CELLCRITICAL_DATA_TYPE                            uint8_t   

//Pack overheat
#define RC_BMSBOARD_PACKOVERHEAT_DATA_ID                              1203      
#define RC_BMSBOARD_PACKOVERHEAT_DATA_COUNT                           1         
#define RC_BMSBOARD_PACKOVERHEAT_DATA_TYPE                            uint8_t   



///////////////////////////////////////////////////
////////////        POWERBOARD          ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//M1, M2, M3, M4, M5, M6, MSpare, Aux, HCSpare, Core, GPS, Router, Cam, LCSpare (bitmasked) [1-Enable, 0-No change]
#define RC_POWERBOARD_ENABLEBUS_DATA_ID                               2000      
#define RC_POWERBOARD_ENABLEBUS_DATA_COUNT                            1         
#define RC_POWERBOARD_ENABLEBUS_DATA_TYPE                             uint16_t  

//M1, M2, M3, M4, M5, M6, MSpare, Aux, HCSpare, Core, GPS, Router, Cam, LCSpare (bitmasked) [1-Disable, 0-No change]
#define RC_POWERBOARD_DISABLEBUS_DATA_ID                              2001      
#define RC_POWERBOARD_DISABLEBUS_DATA_COUNT                           1         
#define RC_POWERBOARD_DISABLEBUS_DATA_TYPE                            uint16_t  

//M1, M2, M3, M4, M5, M6, MSpare, Aux, HCSpare, Core, GPS, Router, Cam, LCSpare (bitmasked) [1-Enable, 0-Disable]
#define RC_POWERBOARD_SETBUS_DATA_ID                                  2002      
#define RC_POWERBOARD_SETBUS_DATA_COUNT                               1         
#define RC_POWERBOARD_SETBUS_DATA_TYPE                                uint16_t  

////////////////////Telemetry
//M1, M2, M3, M4, M5, M6, MSpare, Aux, HCSpare, Core, GPS, Router, Cam, LCSpare (bitmasked) [1-Enabled, 0-Disabled]
#define RC_POWERBOARD_BUSSTATUS_DATA_ID                               2100      
#define RC_POWERBOARD_BUSSTATUS_DATA_COUNT                            1         
#define RC_POWERBOARD_BUSSTATUS_DATA_TYPE                             uint16_t  

//M1, M2, M3, M4, M5, M6, MSpare, Aux, HCSpare, Core, GPS, Router, Cam, LCSpare, NetSW1, NetSW2, NetSW3, POE
#define RC_POWERBOARD_BUSCURRENT_DATA_ID                              2101      
#define RC_POWERBOARD_BUSCURRENT_DATA_COUNT                           18        
#define RC_POWERBOARD_BUSCURRENT_DATA_TYPE                            float     

////////////////////Error
//M1, M2, M3, M4, M5, M6, MSpare, Aux, HCSpare, Core, GPS, Router, Cam, LCSpare, NetSW1, NetSW2, NetSW3, POE (bitmasked) [1-Overcurrent, 0-OK]
#define RC_POWERBOARD_BUSOVERCURRENT_DATA_ID                          2200      
#define RC_POWERBOARD_BUSOVERCURRENT_DATA_COUNT                       1         
#define RC_POWERBOARD_BUSOVERCURRENT_DATA_TYPE                        uint32_t  



///////////////////////////////////////////////////
////////////        COREBOARD           ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[LeftSpeed, RightSpeed] (-1, 1)-> (-100%, 100%)
#define RC_COREBOARD_DRIVELEFTRIGHT_DATA_ID                           3000      
#define RC_COREBOARD_DRIVELEFTRIGHT_DATA_COUNT                        2         
#define RC_COREBOARD_DRIVELEFTRIGHT_DATA_TYPE                         float     

//[LF, LM, LR, RF, RM, RR] (-1, 1)-> (-100%, 100%)
#define RC_COREBOARD_DRIVEINDIVIDUAL_DATA_ID                          3001      
#define RC_COREBOARD_DRIVEINDIVIDUAL_DATA_COUNT                       6         
#define RC_COREBOARD_DRIVEINDIVIDUAL_DATA_TYPE                        float     

//[0-Turn off Watchdog Override, 1-Turn on Watchdog Override]
#define RC_COREBOARD_WATCHDOGOVERRIDE_DATA_ID                         3002      
#define RC_COREBOARD_WATCHDOGOVERRIDE_DATA_COUNT                      1         
#define RC_COREBOARD_WATCHDOGOVERRIDE_DATA_TYPE                       uint8_t   

//[Tilt](degrees -180-180)
#define RC_COREBOARD_LEFTDRIVEGIMBALINCREMENT_DATA_ID                 3003      
#define RC_COREBOARD_LEFTDRIVEGIMBALINCREMENT_DATA_COUNT              1         
#define RC_COREBOARD_LEFTDRIVEGIMBALINCREMENT_DATA_TYPE               int16_t   

//[Tilt](degrees -180-180)
#define RC_COREBOARD_RIGHTDRIVEGIMBALINCREMENT_DATA_ID                3004      
#define RC_COREBOARD_RIGHTDRIVEGIMBALINCREMENT_DATA_COUNT             1         
#define RC_COREBOARD_RIGHTDRIVEGIMBALINCREMENT_DATA_TYPE              int16_t   

//[Pan, Tilt](degrees -180-180)
#define RC_COREBOARD_LEFTMAINGIMBALINCREMENT_DATA_ID                  3005      
#define RC_COREBOARD_LEFTMAINGIMBALINCREMENT_DATA_COUNT               2         
#define RC_COREBOARD_LEFTMAINGIMBALINCREMENT_DATA_TYPE                int16_t   

//[Pan, Tilt](degrees -180-180)
#define RC_COREBOARD_RIGHTMAINGIMBALINCREMENT_DATA_ID                 3006      
#define RC_COREBOARD_RIGHTMAINGIMBALINCREMENT_DATA_COUNT              2         
#define RC_COREBOARD_RIGHTMAINGIMBALINCREMENT_DATA_TYPE               int16_t   

//[Tilt](degrees -180-180)
#define RC_COREBOARD_BACKDRIVEGIMBALINCREMENT_DATA_ID                 3007      
#define RC_COREBOARD_BACKDRIVEGIMBALINCREMENT_DATA_COUNT              1         
#define RC_COREBOARD_BACKDRIVEGIMBALINCREMENT_DATA_TYPE               int16_t   

//[R, G, B] (0, 255)
#define RC_COREBOARD_LEDRGB_DATA_ID                                   3008      
#define RC_COREBOARD_LEDRGB_DATA_COUNT                                3         
#define RC_COREBOARD_LEDRGB_DATA_TYPE                                 uint8_t   

//[Pattern] (Enum)
#define RC_COREBOARD_LEDPATTERNS_DATA_ID                              3009      
#define RC_COREBOARD_LEDPATTERNS_DATA_COUNT                           1         
#define RC_COREBOARD_LEDPATTERNS_DATA_TYPE                            uint8_t   

//[Teleop, Autonomy, Reached Goal] (enum)
#define RC_COREBOARD_STATEDISPLAY_DATA_ID                             3010      
#define RC_COREBOARD_STATEDISPLAY_DATA_COUNT                          1         
#define RC_COREBOARD_STATEDISPLAY_DATA_TYPE                           uint8_t   

//Set Brightness (0-255)
#define RC_COREBOARD_BRIGHTNESS_DATA_ID                               3011      
#define RC_COREBOARD_BRIGHTNESS_DATA_COUNT                            1         
#define RC_COREBOARD_BRIGHTNESS_DATA_TYPE                             uint8_t   

//0: Teleop, 1: Autonomy
#define RC_COREBOARD_SETWATCHDOGMODE_DATA_ID                          3012      
#define RC_COREBOARD_SETWATCHDOGMODE_DATA_COUNT                       1         
#define RC_COREBOARD_SETWATCHDOGMODE_DATA_TYPE                        uint8_t   

////////////////////Telemetry
//[LF, LM, LR, RF, RM, RR] (-1, 1)-> (-100%, 100%)
#define RC_COREBOARD_DRIVESPEEDS_DATA_ID                              3100      
#define RC_COREBOARD_DRIVESPEEDS_DATA_COUNT                           6         
#define RC_COREBOARD_DRIVESPEEDS_DATA_TYPE                            float     

////////////////////Enums
enum COREBOARD_DISPLAYSTATE {TELEOP,AUTONOMY,REACHED_GOAL}; 
enum COREBOARD_PATTERNS {MRDT,BELGIUM,MERICA,DIRT,DOTA,MCD,WINDOWS}; 


///////////////////////////////////////////////////
////////////        NAVBOARD            ///////////         
///////////////////////////////////////////////////

////////////////////Telemetry
//[Lat, Long] [(-90, 90), (-180, 180)] (deg)
#define RC_NAVBOARD_GPSLATLON_DATA_ID                                 6100      
#define RC_NAVBOARD_GPSLATLON_DATA_COUNT                              2         
#define RC_NAVBOARD_GPSLATLON_DATA_TYPE                               double    

//[Pitch, Yaw, Roll] [(-90, 90), (0, 360), (-90, 90)] (deg)
#define RC_NAVBOARD_IMUDATA_DATA_ID                                   6101      
#define RC_NAVBOARD_IMUDATA_DATA_COUNT                                3         
#define RC_NAVBOARD_IMUDATA_DATA_TYPE                                 float     

//[Heading] [ 0, 360 ]
#define RC_NAVBOARD_COMPASSDATA_DATA_ID                               6102      
#define RC_NAVBOARD_COMPASSDATA_DATA_COUNT                            1         
#define RC_NAVBOARD_COMPASSDATA_DATA_TYPE                             float     

//[Number of satellites]
#define RC_NAVBOARD_SATELLITECOUNTDATA_DATA_ID                        6103      
#define RC_NAVBOARD_SATELLITECOUNTDATA_DATA_COUNT                     1         
#define RC_NAVBOARD_SATELLITECOUNTDATA_DATA_TYPE                      uint8_t   

//[xAxis, yAxis, zAxis] Accel in m/s^2
#define RC_NAVBOARD_ACCELEROMETERDATA_DATA_ID                         6104      
#define RC_NAVBOARD_ACCELEROMETERDATA_DATA_COUNT                      3         
#define RC_NAVBOARD_ACCELEROMETERDATA_DATA_TYPE                       float     

//[horizontal_accur, vertical_accur, heading_accur] Accuracy in meters/degrees
#define RC_NAVBOARD_ACCURACYDATA_DATA_ID                              6105      
#define RC_NAVBOARD_ACCURACYDATA_DATA_COUNT                           3         
#define RC_NAVBOARD_ACCURACYDATA_DATA_TYPE                            float     

////////////////////Error
//
#define RC_NAVBOARD_GPSLOCKERROR_DATA_ID                              6200      
#define RC_NAVBOARD_GPSLOCKERROR_DATA_COUNT                           1         
#define RC_NAVBOARD_GPSLOCKERROR_DATA_TYPE                            uint8_t   



///////////////////////////////////////////////////
////////////        SIGNALSTACKBOARD    ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[Power] (-1000, 1000) (m%)
#define RC_SIGNALSTACKBOARD_SIGNALSROTATE_DATA_ID                     7000      
#define RC_SIGNALSTACKBOARD_SIGNALSROTATE_DATA_COUNT                  1         
#define RC_SIGNALSTACKBOARD_SIGNALSROTATE_DATA_TYPE                   int16_t   

////////////////////Telemetry
//[Lat, Long] [(-90, 90), (-180, 180)] (deg)
#define RC_SIGNALSTACKBOARD_SIGNALSPOSITION_DATA_ID                   7100      
#define RC_SIGNALSTACKBOARD_SIGNALSPOSITION_DATA_COUNT                2         
#define RC_SIGNALSTACKBOARD_SIGNALSPOSITION_DATA_TYPE                 double    

//[Heading] [ 0, 360 ]
#define RC_SIGNALSTACKBOARD_SIGNALSDIRECTION_DATA_ID                  7101      
#define RC_SIGNALSTACKBOARD_SIGNALSDIRECTION_DATA_COUNT               1         
#define RC_SIGNALSTACKBOARD_SIGNALSDIRECTION_DATA_TYPE                float     



///////////////////////////////////////////////////
////////////        ARMBOARD            ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[J1, J2, J3, J4, J5, J6] (rpm)
#define RC_ARMBOARD_ARMVELOCITYCONTROL_DATA_ID                        8000      
#define RC_ARMBOARD_ARMVELOCITYCONTROL_DATA_COUNT                     6         
#define RC_ARMBOARD_ARMVELOCITYCONTROL_DATA_TYPE                      int16_t   

//[J1, J2, J3, J4, J5, J6] (Degrees)
#define RC_ARMBOARD_ARMMOVETOPOSITION_DATA_ID                         8001      
#define RC_ARMBOARD_ARMMOVETOPOSITION_DATA_COUNT                      6         
#define RC_ARMBOARD_ARMMOVETOPOSITION_DATA_TYPE                       float     

//[J1, J2, J3, J4, J5, J6] (Degrees)
#define RC_ARMBOARD_ARMINCREMENTPOSITION_DATA_ID                      8002      
#define RC_ARMBOARD_ARMINCREMENTPOSITION_DATA_COUNT                   6         
#define RC_ARMBOARD_ARMINCREMENTPOSITION_DATA_TYPE                    float     

//[X, Y, Z, Y, P, R] (in)
#define RC_ARMBOARD_ARMMOVEIK_DATA_ID                                 8003      
#define RC_ARMBOARD_ARMMOVEIK_DATA_COUNT                              6         
#define RC_ARMBOARD_ARMMOVEIK_DATA_TYPE                               float     

//[X, Y, Z, Y, P, R] (in)
#define RC_ARMBOARD_ARMINCREMENTIKROVER_DATA_ID                       8004      
#define RC_ARMBOARD_ARMINCREMENTIKROVER_DATA_COUNT                    6         
#define RC_ARMBOARD_ARMINCREMENTIKROVER_DATA_TYPE                     float     

//[X, Y, Z, Y, P, R] (in)
#define RC_ARMBOARD_ARMINCREMENTIKWRIST_DATA_ID                       8005      
#define RC_ARMBOARD_ARMINCREMENTIKWRIST_DATA_COUNT                    6         
#define RC_ARMBOARD_ARMINCREMENTIKWRIST_DATA_TYPE                     float     

//[1-enable, 0-disable]
#define RC_ARMBOARD_LASERS_DATA_ID                                    8006      
#define RC_ARMBOARD_LASERS_DATA_COUNT                                 1         
#define RC_ARMBOARD_LASERS_DATA_TYPE                                  uint8_t   

//0: retract, 1: extend
#define RC_ARMBOARD_ENDEFFECTOR_DATA_ID                               8007      
#define RC_ARMBOARD_ENDEFFECTOR_DATA_COUNT                            1         
#define RC_ARMBOARD_ENDEFFECTOR_DATA_TYPE                             uint8_t   

//[Power] (-1000, 1000) (m%)
#define RC_ARMBOARD_GRIPPERMOVE_DATA_ID                               8008      
#define RC_ARMBOARD_GRIPPERMOVE_DATA_COUNT                            2         
#define RC_ARMBOARD_GRIPPERMOVE_DATA_TYPE                             int16_t   

//[0-Turn off Watchdog Override, 1-Turn on Watchdog Override]
#define RC_ARMBOARD_WATCHDOGOVERRIDE_DATA_ID                          8009      
#define RC_ARMBOARD_WATCHDOGOVERRIDE_DATA_COUNT                       1         
#define RC_ARMBOARD_WATCHDOGOVERRIDE_DATA_TYPE                        uint8_t   

//[J6 Forward, J6 Reverse, J5 Forward, J5 Reverse, J4 Forward, J4 Reverse, J3 Forward, J3 Reverse, J2 Forward, J2 Reverse, J1 Forward, J1 Reverse] (0-Turn off Limit Switch Override, 1-Turn on Limit Switch Override) (bitmasked)
#define RC_ARMBOARD_LIMITSWITCHOVERRIDE_DATA_ID                       8010      
#define RC_ARMBOARD_LIMITSWITCHOVERRIDE_DATA_COUNT                    1         
#define RC_ARMBOARD_LIMITSWITCHOVERRIDE_DATA_TYPE                     uint16_t  

//Prompt arm for J1-6 positions
#define RC_ARMBOARD_REQUESTJOINTPOSITIONS_DATA_ID                     8011      
#define RC_ARMBOARD_REQUESTJOINTPOSITIONS_DATA_COUNT                  1         
#define RC_ARMBOARD_REQUESTJOINTPOSITIONS_DATA_TYPE                   uint8_t   

//Start auto pushing arm J1-6 positions
#define RC_ARMBOARD_TOGGLEPOSITIONTELEM_DATA_ID                       8012      
#define RC_ARMBOARD_TOGGLEPOSITIONTELEM_DATA_COUNT                    1         
#define RC_ARMBOARD_TOGGLEPOSITIONTELEM_DATA_TYPE                     uint8_t   

//Prompt arm for XYZPYR Data
#define RC_ARMBOARD_REQUESTAXESPOSITIONS_DATA_ID                      8013      
#define RC_ARMBOARD_REQUESTAXESPOSITIONS_DATA_COUNT                   1         
#define RC_ARMBOARD_REQUESTAXESPOSITIONS_DATA_TYPE                    uint8_t   

////////////////////Telemetry
//[J1, J2, J3, J4, J5, J6] (0, Deg)
#define RC_ARMBOARD_JOINTANGLES_DATA_ID                               8101      
#define RC_ARMBOARD_JOINTANGLES_DATA_COUNT                            6         
#define RC_ARMBOARD_JOINTANGLES_DATA_TYPE                             float     

//[J1, J2, J3, J4, J5, J6] (0, rpm)
#define RC_ARMBOARD_MOTORVELOCITIES_DATA_ID                           8102      
#define RC_ARMBOARD_MOTORVELOCITIES_DATA_COUNT                        6         
#define RC_ARMBOARD_MOTORVELOCITIES_DATA_TYPE                         float     

//[X, Y, Z, Y, P, R]
#define RC_ARMBOARD_IKCOORDINATES_DATA_ID                             8103      
#define RC_ARMBOARD_IKCOORDINATES_DATA_COUNT                          6         
#define RC_ARMBOARD_IKCOORDINATES_DATA_TYPE                           float     

////////////////////Error
//[WatchDogStatus] (0-WD Not Triggered, 1-WD Triggered) 
#define RC_ARMBOARD_WATCHDOGSTATUS_DATA_ID                            8200      
#define RC_ARMBOARD_WATCHDOGSTATUS_DATA_COUNT                         1         
#define RC_ARMBOARD_WATCHDOGSTATUS_DATA_TYPE                          uint8_t   



///////////////////////////////////////////////////
////////////        SCIENCEACTUATIONBOARD///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[Power] (-1000, 1000) (m%)
#define RC_SCIENCEACTUATIONBOARD_SENSORAXIS_DATA_ID                   9000      
#define RC_SCIENCEACTUATIONBOARD_SENSORAXIS_DATA_COUNT                1         
#define RC_SCIENCEACTUATIONBOARD_SENSORAXIS_DATA_TYPE                 int16_t   

//Sign of value determines direction
#define RC_SCIENCEACTUATIONBOARD_WATERSELECTOR_DATA_ID                9001      
#define RC_SCIENCEACTUATIONBOARD_WATERSELECTOR_DATA_COUNT             1         
#define RC_SCIENCEACTUATIONBOARD_WATERSELECTOR_DATA_TYPE              int8_t    

//Water pump (0-Off, 1-Pump)
#define RC_SCIENCEACTUATIONBOARD_WATERPUMP_DATA_ID                    9002      
#define RC_SCIENCEACTUATIONBOARD_WATERPUMP_DATA_COUNT                 1         
#define RC_SCIENCEACTUATIONBOARD_WATERPUMP_DATA_TYPE                  uint8_t   

//[Zoop-axis Top, Zoop-axis Bottom, Xoop-axis Left, Xoop-axis Right, Sensor Axis Top, Sensor Axis Bottom] (0-Turn off Limit Switch Override, 1-Turn on Limit Switch Override) (bitmasked)
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHOVERRIDE_DATA_ID          9003      
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHOVERRIDE_DATA_COUNT       1         
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHOVERRIDE_DATA_TYPE        uint8_t   

//[Power] (-1000, 1000) (m%)
#define RC_SCIENCEACTUATIONBOARD_XOOPAXIS_DATA_ID                     9004      
#define RC_SCIENCEACTUATIONBOARD_XOOPAXIS_DATA_COUNT                  1         
#define RC_SCIENCEACTUATIONBOARD_XOOPAXIS_DATA_TYPE                   int16_t   

//[Power] (-1000, 1000) (m%)
#define RC_SCIENCEACTUATIONBOARD_ZOOPAXIS_DATA_ID                     9005      
#define RC_SCIENCEACTUATIONBOARD_ZOOPAXIS_DATA_COUNT                  1         
#define RC_SCIENCEACTUATIONBOARD_ZOOPAXIS_DATA_TYPE                   int16_t   

//[Position] (0 Open, 1 Closed, 2 Drop)
#define RC_SCIENCEACTUATIONBOARD_SCOOPGRABBER_DATA_ID                 9006      
#define RC_SCIENCEACTUATIONBOARD_SCOOPGRABBER_DATA_COUNT              1         
#define RC_SCIENCEACTUATIONBOARD_SCOOPGRABBER_DATA_TYPE               uint8_t   

//[Position] (0, 1 - 6, 7)
#define RC_SCIENCEACTUATIONBOARD_GOTOPOSITION_DATA_ID                 9007      
#define RC_SCIENCEACTUATIONBOARD_GOTOPOSITION_DATA_COUNT              1         
#define RC_SCIENCEACTUATIONBOARD_GOTOPOSITION_DATA_TYPE               uint8_t   

//Degrees 0-180
#define RC_SCIENCEACTUATIONBOARD_INCREMENTALSCOOP_DATA_ID             9008      
#define RC_SCIENCEACTUATIONBOARD_INCREMENTALSCOOP_DATA_COUNT          1         
#define RC_SCIENCEACTUATIONBOARD_INCREMENTALSCOOP_DATA_TYPE           int8_t    

//Quickly barely open and close the scoop
#define RC_SCIENCEACTUATIONBOARD_BUMPSCOOP_DATA_ID                    9009      
#define RC_SCIENCEACTUATIONBOARD_BUMPSCOOP_DATA_COUNT                 1         
#define RC_SCIENCEACTUATIONBOARD_BUMPSCOOP_DATA_TYPE                  uint8_t   

//Motor speed value (-1000,1000)
#define RC_SCIENCEACTUATIONBOARD_MICROSCOPEFOCUS_DATA_ID              9010      
#define RC_SCIENCEACTUATIONBOARD_MICROSCOPEFOCUS_DATA_COUNT           1         
#define RC_SCIENCEACTUATIONBOARD_MICROSCOPEFOCUS_DATA_TYPE            int16_t   

//[Position] (0, 1-12)
#define RC_SCIENCEACTUATIONBOARD_WATERPOSITION_DATA_ID                9011      
#define RC_SCIENCEACTUATIONBOARD_WATERPOSITION_DATA_COUNT             1         
#define RC_SCIENCEACTUATIONBOARD_WATERPOSITION_DATA_TYPE              uint8_t   

////////////////////Telemetry
//[scoop z-pos, scoop x-pos, sensor z-axis] (absolute position 0-360)
#define RC_SCIENCEACTUATIONBOARD_ENCODERPOSITIONS_DATA_ID             9100      
#define RC_SCIENCEACTUATIONBOARD_ENCODERPOSITIONS_DATA_COUNT          3         
#define RC_SCIENCEACTUATIONBOARD_ENCODERPOSITIONS_DATA_TYPE           float     

////////////////////Error
//[Zoop-axis Top, Zoop-axis Bottom, Xoop-axis Left, Xoop-axis Right, Sensor Axis Top, Sensor Axis Bottom] (0-OFF, 1-ON) (bitmasked)
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHTRIGGERED_DATA_ID         9200      
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHTRIGGERED_DATA_COUNT      1         
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHTRIGGERED_DATA_TYPE       uint8_t   



///////////////////////////////////////////////////
////////////        AUTONOMYBOARD       ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//
#define RC_AUTONOMYBOARD_STARTAUTONOMY_DATA_ID                        11000     
#define RC_AUTONOMYBOARD_STARTAUTONOMY_DATA_COUNT                     1         
#define RC_AUTONOMYBOARD_STARTAUTONOMY_DATA_TYPE                      uint8_t   

//
#define RC_AUTONOMYBOARD_DISABLEAUTONOMY_DATA_ID                      11001     
#define RC_AUTONOMYBOARD_DISABLEAUTONOMY_DATA_COUNT                   1         
#define RC_AUTONOMYBOARD_DISABLEAUTONOMY_DATA_TYPE                    uint8_t   

//[Lat, Lon]
#define RC_AUTONOMYBOARD_ADDPOSITIONLEG_DATA_ID                       11002     
#define RC_AUTONOMYBOARD_ADDPOSITIONLEG_DATA_COUNT                    2         
#define RC_AUTONOMYBOARD_ADDPOSITIONLEG_DATA_TYPE                     double    

//[Lat, Lon]
#define RC_AUTONOMYBOARD_ADDMARKERLEG_DATA_ID                         11003     
#define RC_AUTONOMYBOARD_ADDMARKERLEG_DATA_COUNT                      2         
#define RC_AUTONOMYBOARD_ADDMARKERLEG_DATA_TYPE                       double    

//[Lat, Lon]
#define RC_AUTONOMYBOARD_ADDGATELEG_DATA_ID                           11004     
#define RC_AUTONOMYBOARD_ADDGATELEG_DATA_COUNT                        2         
#define RC_AUTONOMYBOARD_ADDGATELEG_DATA_TYPE                         double    

//
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATA_ID                       11005     
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATA_COUNT                    1         
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATA_TYPE                     uint8_t   

//
#define RC_AUTONOMYBOARD_SETMAXSPEED_DATA_ID                          11006     
#define RC_AUTONOMYBOARD_SETMAXSPEED_DATA_COUNT                       1         
#define RC_AUTONOMYBOARD_SETMAXSPEED_DATA_TYPE                        uint16_t  

////////////////////Telemetry
//Enum (AUTONOMYSTATE)
#define RC_AUTONOMYBOARD_CURRENTSTATE_DATA_ID                         11100     
#define RC_AUTONOMYBOARD_CURRENTSTATE_DATA_COUNT                      1         
#define RC_AUTONOMYBOARD_CURRENTSTATE_DATA_TYPE                       uint8_t   

//
#define RC_AUTONOMYBOARD_REACHEDMARKER_DATA_ID                        11101     
#define RC_AUTONOMYBOARD_REACHEDMARKER_DATA_COUNT                     1         
#define RC_AUTONOMYBOARD_REACHEDMARKER_DATA_TYPE                      uint8_t   

//String version of most current error log
#define RC_AUTONOMYBOARD_CURRENTLOG_DATA_ID                           11102     
#define RC_AUTONOMYBOARD_CURRENTLOG_DATA_COUNT                        255       
#define RC_AUTONOMYBOARD_CURRENTLOG_DATA_TYPE                         char      

////////////////////Enums
enum AUTONOMYBOARD_AUTONOMYSTATE {IDLE,NAVIGATING,SEARCHPATTERN,APPROACHINGMARKER,APPROACHINGGATE,AVOIDANCE,REVERSING,STUCK}; 


///////////////////////////////////////////////////
////////////        CAMERA1BOARD        ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//Change which camera a feed is looking at. [0] is the feed, [1] is the camera to view.
#define RC_CAMERA1BOARD_CHANGECAMERAS_DATA_ID                         12000     
#define RC_CAMERA1BOARD_CHANGECAMERAS_DATA_COUNT                      2         
#define RC_CAMERA1BOARD_CHANGECAMERAS_DATA_TYPE                       uint8_t   

////////////////////Telemetry
//Bitmask values for which cameras are able to stream. LSB is Camera 0, MSB is Camera 7.
#define RC_CAMERA1BOARD_AVAILABLECAMERAS_DATA_ID                      12100     
#define RC_CAMERA1BOARD_AVAILABLECAMERAS_DATA_COUNT                   1         
#define RC_CAMERA1BOARD_AVAILABLECAMERAS_DATA_TYPE                    uint8_t   

//Which cameras the system is currently streaming on each port
#define RC_CAMERA1BOARD_STREAMINGCAMERAS_DATA_ID                      12101     
#define RC_CAMERA1BOARD_STREAMINGCAMERAS_DATA_COUNT                   4         
#define RC_CAMERA1BOARD_STREAMINGCAMERAS_DATA_TYPE                    uint8_t   

////////////////////Error
//Camera has errored and stopped streaming. [0] is ID of camera as an integer (not bitmask).
#define RC_CAMERA1BOARD_CAMERAUNAVAILABLE_DATA_ID                     12200     
#define RC_CAMERA1BOARD_CAMERAUNAVAILABLE_DATA_COUNT                  1         
#define RC_CAMERA1BOARD_CAMERAUNAVAILABLE_DATA_TYPE                   uint8_t   



///////////////////////////////////////////////////
////////////        CAMERA2BOARD        ///////////         
///////////////////////////////////////////////////



#endif // RoveCommManifest_h