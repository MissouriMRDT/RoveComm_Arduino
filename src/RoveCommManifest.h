/*******************************************************************************
 * NOTICE! 
 * This file is auto generated and will be overwritten if edited
 * and committed. To make changes, edit the manifest.json file or
 * edit manifest_parser.py if it is a formatting issue.
 ******************************************************************************/

#ifndef ROVECOMM_MANIFEST_H
#define ROVECOMM_MANIFEST_H

#include <stdint.h>
#include <IPAddress.h>

#define RC_COREBOARD_FIRSTOCTET                             192       
#define RC_COREBOARD_SECONDOCTET                            168       
#define RC_COREBOARD_THIRDOCTET                             2         
#define RC_COREBOARD_FOURTHOCTET                            110       
#define RC_COREBOARD_IPADDRESS                              {192, 168, 2, 110}

#define RC_PMSBOARD_FIRSTOCTET                              192       
#define RC_PMSBOARD_SECONDOCTET                             168       
#define RC_PMSBOARD_THIRDOCTET                              2         
#define RC_PMSBOARD_FOURTHOCTET                             102       
#define RC_PMSBOARD_IPADDRESS                               {192, 168, 2, 102}

#define RC_NAVBOARD_FIRSTOCTET                              192       
#define RC_NAVBOARD_SECONDOCTET                             168       
#define RC_NAVBOARD_THIRDOCTET                              2         
#define RC_NAVBOARD_FOURTHOCTET                             104       
#define RC_NAVBOARD_IPADDRESS                               {192, 168, 2, 104}

#define RC_BASESTATIONNAVBOARD_FIRSTOCTET                   192       
#define RC_BASESTATIONNAVBOARD_SECONDOCTET                  168       
#define RC_BASESTATIONNAVBOARD_THIRDOCTET                   100       
#define RC_BASESTATIONNAVBOARD_FOURTHOCTET                  112       
#define RC_BASESTATIONNAVBOARD_IPADDRESS                    {192, 168, 100, 112}

#define RC_SIGNALSTACKBOARD_FIRSTOCTET                      192       
#define RC_SIGNALSTACKBOARD_SECONDOCTET                     168       
#define RC_SIGNALSTACKBOARD_THIRDOCTET                      100       
#define RC_SIGNALSTACKBOARD_FOURTHOCTET                     101       
#define RC_SIGNALSTACKBOARD_IPADDRESS                       {192, 168, 100, 101}

#define RC_ARMBOARD_FIRSTOCTET                              192       
#define RC_ARMBOARD_SECONDOCTET                             168       
#define RC_ARMBOARD_THIRDOCTET                              2         
#define RC_ARMBOARD_FOURTHOCTET                             107       
#define RC_ARMBOARD_IPADDRESS                               {192, 168, 2, 107}

#define RC_AUGERBOARD_FIRSTOCTET                            192       
#define RC_AUGERBOARD_SECONDOCTET                           168       
#define RC_AUGERBOARD_THIRDOCTET                            2         
#define RC_AUGERBOARD_FOURTHOCTET                           108       
#define RC_AUGERBOARD_IPADDRESS                             {192, 168, 2, 108}

#define RC_AUTONOMYBOARD_FIRSTOCTET                         192       
#define RC_AUTONOMYBOARD_SECONDOCTET                        168       
#define RC_AUTONOMYBOARD_THIRDOCTET                         3         
#define RC_AUTONOMYBOARD_FOURTHOCTET                        100       
#define RC_AUTONOMYBOARD_IPADDRESS                          {192, 168, 3, 100}

#define RC_CAMERA1BOARD_FIRSTOCTET                          192       
#define RC_CAMERA1BOARD_SECONDOCTET                         168       
#define RC_CAMERA1BOARD_THIRDOCTET                          4         
#define RC_CAMERA1BOARD_FOURTHOCTET                         100       
#define RC_CAMERA1BOARD_IPADDRESS                           {192, 168, 4, 100}

#define RC_CAMERA2BOARD_FIRSTOCTET                          192       
#define RC_CAMERA2BOARD_SECONDOCTET                         168       
#define RC_CAMERA2BOARD_THIRDOCTET                          4         
#define RC_CAMERA2BOARD_FOURTHOCTET                         101       
#define RC_CAMERA2BOARD_IPADDRESS                           {192, 168, 4, 101}

#define RC_CAMERASERVERBOARD_FIRSTOCTET                     192       
#define RC_CAMERASERVERBOARD_SECONDOCTET                    168       
#define RC_CAMERASERVERBOARD_THIRDOCTET                     4         
#define RC_CAMERASERVERBOARD_FOURTHOCTET                    102       
#define RC_CAMERASERVERBOARD_IPADDRESS                      {192, 168, 4, 102}

#define RC_IRSPECTROMETERBOARD_FIRSTOCTET                   192       
#define RC_IRSPECTROMETERBOARD_SECONDOCTET                  168       
#define RC_IRSPECTROMETERBOARD_THIRDOCTET                   3         
#define RC_IRSPECTROMETERBOARD_FOURTHOCTET                  104       
#define RC_IRSPECTROMETERBOARD_IPADDRESS                    {192, 168, 3, 104}

#define RC_RAMANBOARD_FIRSTOCTET                            192       
#define RC_RAMANBOARD_SECONDOCTET                           168       
#define RC_RAMANBOARD_THIRDOCTET                            3         
#define RC_RAMANBOARD_FOURTHOCTET                           105       
#define RC_RAMANBOARD_IPADDRESS                             {192, 168, 3, 105}

#define RC_ROVESOSIMULATORBOARD_FIRSTOCTET                  127       
#define RC_ROVESOSIMULATORBOARD_SECONDOCTET                 0         
#define RC_ROVESOSIMULATORBOARD_THIRDOCTET                  0         
#define RC_ROVESOSIMULATORBOARD_FOURTHOCTET                 1         
#define RC_ROVESOSIMULATORBOARD_IPADDRESS                   {127, 0, 0, 1}



#define ROVECOMM_UPDATE_RATE                                100       
#define RC_ROVECOMM_ETHERNET_UDP_PORT                       11000     
#define RC_ROVECOMM_ETHERNET_TCP_PORT                       12000     


#define RC_ROVECOMM_SUBNET_MAC_FIRST_BYTE                   222       
#define RC_ROVECOMM_SUBNET_MAC_SECOND_BYTE                  173       


///////////////////////////////////////////////////
////////////        System Packets      ///////////         
///////////////////////////////////////////////////

#define RC_ROVECOMM_PING_DATA_ID                            1         
#define RC_ROVECOMM_PING_REPLY_DATA_ID                      2         
#define RC_ROVECOMM_SUBSCRIBE_DATA_ID                       3         
#define RC_ROVECOMM_UNSUBSCRIBE_DATA_ID                     4         
#define RC_ROVECOMM_INVALID_VERSION_DATA_ID                 5         
#define RC_ROVECOMM_NO_DATA_DATA_ID                         6         


///////////////////////////////////////////////////
////////////        COREBOARD           ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[LeftSpeed, RightSpeed] (-1, 1)-> (-100%, 100%)
#define RC_COREBOARD_DRIVELEFTRIGHT_DATA_ID                                     3000      
#define RC_COREBOARD_DRIVELEFTRIGHT_DATA_COUNT                                  2         
#define RC_COREBOARD_DRIVELEFTRIGHT_DATA_TYPE                                   float     

//[LF, LM, LR, RF, RM, RR] (-1, 1)-> (-100%, 100%)
#define RC_COREBOARD_DRIVEINDIVIDUAL_DATA_ID                                    3001      
#define RC_COREBOARD_DRIVEINDIVIDUAL_DATA_COUNT                                 6         
#define RC_COREBOARD_DRIVEINDIVIDUAL_DATA_TYPE                                  float     

//[0-override off, 1-override on]
#define RC_COREBOARD_WATCHDOGOVERRIDE_DATA_ID                                   3002      
#define RC_COREBOARD_WATCHDOGOVERRIDE_DATA_COUNT                                1         
#define RC_COREBOARD_WATCHDOGOVERRIDE_DATA_TYPE                                 uint8_t   

//[Tilt](degrees -180-180)
#define RC_COREBOARD_LEFTDRIVEGIMBALINCREMENT_DATA_ID                           3003      
#define RC_COREBOARD_LEFTDRIVEGIMBALINCREMENT_DATA_COUNT                        1         
#define RC_COREBOARD_LEFTDRIVEGIMBALINCREMENT_DATA_TYPE                         int16_t   

//[Tilt](degrees -180-180)
#define RC_COREBOARD_RIGHTDRIVEGIMBALINCREMENT_DATA_ID                          3004      
#define RC_COREBOARD_RIGHTDRIVEGIMBALINCREMENT_DATA_COUNT                       1         
#define RC_COREBOARD_RIGHTDRIVEGIMBALINCREMENT_DATA_TYPE                        int16_t   

//[Pan, Tilt](degrees -180-180)
#define RC_COREBOARD_LEFTMAINGIMBALINCREMENT_DATA_ID                            3005      
#define RC_COREBOARD_LEFTMAINGIMBALINCREMENT_DATA_COUNT                         2         
#define RC_COREBOARD_LEFTMAINGIMBALINCREMENT_DATA_TYPE                          int16_t   

//[Pan, Tilt](degrees -180-180)
#define RC_COREBOARD_RIGHTMAINGIMBALINCREMENT_DATA_ID                           3006      
#define RC_COREBOARD_RIGHTMAINGIMBALINCREMENT_DATA_COUNT                        2         
#define RC_COREBOARD_RIGHTMAINGIMBALINCREMENT_DATA_TYPE                         int16_t   

//[Tilt](degrees -180-180)
#define RC_COREBOARD_BACKDRIVEGIMBALINCREMENT_DATA_ID                           3007      
#define RC_COREBOARD_BACKDRIVEGIMBALINCREMENT_DATA_COUNT                        1         
#define RC_COREBOARD_BACKDRIVEGIMBALINCREMENT_DATA_TYPE                         int16_t   

//[R, G, B] (0, 255)
#define RC_COREBOARD_LEDRGB_DATA_ID                                             3008      
#define RC_COREBOARD_LEDRGB_DATA_COUNT                                          3         
#define RC_COREBOARD_LEDRGB_DATA_TYPE                                           uint8_t   

//[Pattern] (Enum)
#define RC_COREBOARD_LEDPATTERNS_DATA_ID                                        3009      
#define RC_COREBOARD_LEDPATTERNS_DATA_COUNT                                     1         
#define RC_COREBOARD_LEDPATTERNS_DATA_TYPE                                      uint8_t   

//[Teleop, Autonomy, Reached Goal] (enum)
#define RC_COREBOARD_STATEDISPLAY_DATA_ID                                       3010      
#define RC_COREBOARD_STATEDISPLAY_DATA_COUNT                                    1         
#define RC_COREBOARD_STATEDISPLAY_DATA_TYPE                                     uint8_t   

//Set Brightness (0-255)
#define RC_COREBOARD_BRIGHTNESS_DATA_ID                                         3011      
#define RC_COREBOARD_BRIGHTNESS_DATA_COUNT                                      1         
#define RC_COREBOARD_BRIGHTNESS_DATA_TYPE                                       uint8_t   

//0: Teleop, 1: Autonomy
#define RC_COREBOARD_SETWATCHDOGMODE_DATA_ID                                    3012      
#define RC_COREBOARD_SETWATCHDOGMODE_DATA_COUNT                                 1         
#define RC_COREBOARD_SETWATCHDOGMODE_DATA_TYPE                                  uint8_t   

//Set the message to display on the lighting panel; null terminator ends string early
#define RC_COREBOARD_LEDTEXT_DATA_ID                                            3013      
#define RC_COREBOARD_LEDTEXT_DATA_COUNT                                         256       
#define RC_COREBOARD_LEDTEXT_DATA_TYPE                                          char      

////////////////////Telemetry
//[FL, ML, BL, FR, MR, BR] (-1, 1)-> (-100%, 100%)
#define RC_COREBOARD_MOTORSPEEDS_DATA_ID                                        3100      
#define RC_COREBOARD_MOTORSPEEDS_DATA_COUNT                                     6         
#define RC_COREBOARD_MOTORSPEEDS_DATA_TYPE                                      float     

//[FL, ML, BL, FR, MR, BR] Motor current draw
#define RC_COREBOARD_MOTORCURRENTS_DATA_ID                                      3101      
#define RC_COREBOARD_MOTORCURRENTS_DATA_COUNT                                   6         
#define RC_COREBOARD_MOTORCURRENTS_DATA_TYPE                                    float     

//[FL, ML, BL, FR, MR, BR] VESC (battery side) current draw
#define RC_COREBOARD_VESCCURRENTS_DATA_ID                                       3102      
#define RC_COREBOARD_VESCCURRENTS_DATA_COUNT                                    6         
#define RC_COREBOARD_VESCCURRENTS_DATA_TYPE                                     float     

//[Roll, Pitch, Yaw] degrees
#define RC_COREBOARD_IMUDATA_DATA_ID                                            3103      
#define RC_COREBOARD_IMUDATA_DATA_COUNT                                         3         
#define RC_COREBOARD_IMUDATA_DATA_TYPE                                          float     

//[xAxis, yAxis, zAxis] Accel in m/s^2
#define RC_COREBOARD_ACCELEROMETERDATA_DATA_ID                                  3104      
#define RC_COREBOARD_ACCELEROMETERDATA_DATA_COUNT                               3         
#define RC_COREBOARD_ACCELEROMETERDATA_DATA_TYPE                                float     

////////////////////Error
//[MotorID, FaultCode]
#define RC_COREBOARD_VESCFAULT_DATA_ID                                          3200      
#define RC_COREBOARD_VESCFAULT_DATA_COUNT                                       2         
#define RC_COREBOARD_VESCFAULT_DATA_TYPE                                        uint8_t   

////////////////////Enums
enum COREBOARD_MOTORS {FRONT_LEFT,MIDDLE_LEFT,BACK_LEFT,FRONT_RIGHT,MIDDLE_RIGHT,BACK_RIGHT}; 
enum COREBOARD_DISPLAYSTATE {TELEOP,AUTONOMY,REACHED_GOAL}; 
enum COREBOARD_PATTERNS {MRDT,BELGIUM,MERICA,DIRT,DOTA,MCD,WINDOWS}; 
enum COREBOARD_VESCFAULTCODE {FAULT_CODE_NONE,FAULT_CODE_OVER_VOLTAGE,FAULT_CODE_UNDER_VOLTAGE,FAULT_CODE_DRV,FAULT_CODE_ABS_OVER_CURRENT,FAULT_CODE_OVER_TEMP_FET,FAULT_CODE_OVER_TEMP_MOTOR,FAULT_CODE_GATE_DRIVER_OVER_VOLTAGE,FAULT_CODE_GATE_DRIVER_UNDER_VOLTAGE,FAULT_CODE_MCU_UNDER_VOLTAGE,FAULT_CODE_BOOTING_FROM_WATCHDOG_RESET,FAULT_CODE_ENCODER_SPI,FAULT_CODE_ENCODER_SINCOS_BELOW_MIN_AMPLITUDE,FAULT_CODE_ENCODER_SINCOS_ABOVE_MAX_AMPLITUDE,FAULT_CODE_FLASH_CORRUPTION,FAULT_CODE_HIGH_OFFSET_CURRENT_SENSOR_1,FAULT_CODE_HIGH_OFFSET_CURRENT_SENSOR_2,FAULT_CODE_HIGH_OFFSET_CURRENT_SENSOR_3,FAULT_CODE_UNBALANCED_CURRENTS,FAULT_CODE_BRK,FAULT_CODE_RESOLVER_LOT,FAULT_CODE_RESOLVER_DOS,FAULT_CODE_RESOLVER_LOS,FAULT_CODE_FLASH_CORRUPTION_APP_CFG,FAULT_CODE_FLASH_CORRUPTION_MC_CFG,FAULT_CODE_ENCODER_NO_MAGNET,FAULT_CODE_ENCODER_MAGNET_TOO_STRONG,FAULT_CODE_PHASE_FILTER}; 


///////////////////////////////////////////////////
////////////        PMSBOARD            ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//Power off all systems except network (PMS will stay on)
#define RC_PMSBOARD_ESTOP_DATA_ID                                               4000      
#define RC_PMSBOARD_ESTOP_DATA_COUNT                                            1         
#define RC_PMSBOARD_ESTOP_DATA_TYPE                                             uint8_t   

//Power off all systems including network, cannot recover without physical reboot (PMS will stay on)
#define RC_PMSBOARD_SUICIDE_DATA_ID                                             4001      
#define RC_PMSBOARD_SUICIDE_DATA_COUNT                                          1         
#define RC_PMSBOARD_SUICIDE_DATA_TYPE                                           uint8_t   

//Cycle all systems including network off and back on (PMS will stay on)
#define RC_PMSBOARD_REBOOT_DATA_ID                                              4002      
#define RC_PMSBOARD_REBOOT_DATA_COUNT                                           1         
#define RC_PMSBOARD_REBOOT_DATA_TYPE                                            uint8_t   

//[Motor, Core, Aux] (bitmasked) [1-Enable, 0-No change]
#define RC_PMSBOARD_ENABLEBUS_DATA_ID                                           4003      
#define RC_PMSBOARD_ENABLEBUS_DATA_COUNT                                        1         
#define RC_PMSBOARD_ENABLEBUS_DATA_TYPE                                         uint8_t   

//[Motor, Core, Aux] (bitmasked) [1-Disable, 0-No change]
#define RC_PMSBOARD_DISABLEBUS_DATA_ID                                          4004      
#define RC_PMSBOARD_DISABLEBUS_DATA_COUNT                                       1         
#define RC_PMSBOARD_DISABLEBUS_DATA_TYPE                                        uint8_t   

//[Motor, Core, Aux] (bitmasked) [1-Enable, 0-Disable]
#define RC_PMSBOARD_SETBUS_DATA_ID                                              4005      
#define RC_PMSBOARD_SETBUS_DATA_COUNT                                           1         
#define RC_PMSBOARD_SETBUS_DATA_TYPE                                            uint8_t   

////////////////////Telemetry
//Total current draw from battery
#define RC_PMSBOARD_PACKCURRENT_DATA_ID                                         4100      
#define RC_PMSBOARD_PACKCURRENT_DATA_COUNT                                      1         
#define RC_PMSBOARD_PACKCURRENT_DATA_TYPE                                       float     

//Pack voltage
#define RC_PMSBOARD_PACKVOLTAGE_DATA_ID                                         4101      
#define RC_PMSBOARD_PACKVOLTAGE_DATA_COUNT                                      1         
#define RC_PMSBOARD_PACKVOLTAGE_DATA_TYPE                                       float     

//C1, C2, C3, C4, C5, C6
#define RC_PMSBOARD_CELLVOLTAGE_DATA_ID                                         4102      
#define RC_PMSBOARD_CELLVOLTAGE_DATA_COUNT                                      6         
#define RC_PMSBOARD_CELLVOLTAGE_DATA_TYPE                                       float     

//Current draw by aux systems (before 12V buck)
#define RC_PMSBOARD_AUXCURRENT_DATA_ID                                          4103      
#define RC_PMSBOARD_AUXCURRENT_DATA_COUNT                                       1         
#define RC_PMSBOARD_AUXCURRENT_DATA_TYPE                                        float     

//Current draw from other devices (CS1, CS2, CS3)
#define RC_PMSBOARD_MISCCURRENT_DATA_ID                                         4104      
#define RC_PMSBOARD_MISCCURRENT_DATA_COUNT                                      3         
#define RC_PMSBOARD_MISCCURRENT_DATA_TYPE                                       float     

//[Motor, Core, Aux, Network] (bitmasked) [1-Enabled, 0-Disabled]
#define RC_PMSBOARD_BUSSTATUS_DATA_ID                                           4105      
#define RC_PMSBOARD_BUSSTATUS_DATA_COUNT                                        1         
#define RC_PMSBOARD_BUSSTATUS_DATA_TYPE                                         uint8_t   

////////////////////Error
//Higher current draw than the battery can support. Rover will Reboot automatically
#define RC_PMSBOARD_PACKOVERCURRENT_DATA_ID                                     4200      
#define RC_PMSBOARD_PACKOVERCURRENT_DATA_COUNT                                  1         
#define RC_PMSBOARD_PACKOVERCURRENT_DATA_TYPE                                   uint8_t   

//(bitmasked) [1-Undervolt, 0-OK]. Rover will EStop automatically
#define RC_PMSBOARD_CELLUNDERVOLTAGE_DATA_ID                                    4201      
#define RC_PMSBOARD_CELLUNDERVOLTAGE_DATA_COUNT                                 1         
#define RC_PMSBOARD_CELLUNDERVOLTAGE_DATA_TYPE                                  uint8_t   

//(bitmasked) [1-Critical, 0-OK]. Rover will Suicide automatically
#define RC_PMSBOARD_CELLCRITICAL_DATA_ID                                        4202      
#define RC_PMSBOARD_CELLCRITICAL_DATA_COUNT                                     1         
#define RC_PMSBOARD_CELLCRITICAL_DATA_TYPE                                      uint8_t   

//Aux system current draw too high. Rover will disable Aux bus automatically
#define RC_PMSBOARD_AUXOVERCURRENT_DATA_ID                                      4203      
#define RC_PMSBOARD_AUXOVERCURRENT_DATA_COUNT                                   1         
#define RC_PMSBOARD_AUXOVERCURRENT_DATA_TYPE                                    uint8_t   



///////////////////////////////////////////////////
////////////        NAVBOARD            ///////////         
///////////////////////////////////////////////////

////////////////////Telemetry
//[Lat, Long, Alt] [(-90, 90), (-180, 180)(deg), (0, 1000)]
#define RC_NAVBOARD_GPSLATLONALT_DATA_ID                                        6100      
#define RC_NAVBOARD_GPSLATLONALT_DATA_COUNT                                     3         
#define RC_NAVBOARD_GPSLATLONALT_DATA_TYPE                                      double    

//[Pitch, Yaw, Roll] [(-90, 90), (0, 360), (-90, 90)] (deg)
#define RC_NAVBOARD_IMUDATA_DATA_ID                                             6101      
#define RC_NAVBOARD_IMUDATA_DATA_COUNT                                          3         
#define RC_NAVBOARD_IMUDATA_DATA_TYPE                                           float     

//[Heading] [ 0, 360 ]
#define RC_NAVBOARD_COMPASSDATA_DATA_ID                                         6102      
#define RC_NAVBOARD_COMPASSDATA_DATA_COUNT                                      1         
#define RC_NAVBOARD_COMPASSDATA_DATA_TYPE                                       float     

//[Number of satellites]
#define RC_NAVBOARD_SATELLITECOUNTDATA_DATA_ID                                  6103      
#define RC_NAVBOARD_SATELLITECOUNTDATA_DATA_COUNT                               1         
#define RC_NAVBOARD_SATELLITECOUNTDATA_DATA_TYPE                                uint8_t   

//[xAxis, yAxis, zAxis] Accel in m/s^2
#define RC_NAVBOARD_ACCELEROMETERDATA_DATA_ID                                   6104      
#define RC_NAVBOARD_ACCELEROMETERDATA_DATA_COUNT                                3         
#define RC_NAVBOARD_ACCELEROMETERDATA_DATA_TYPE                                 float     

//[horizontal_accur, vertical_accur, heading_accur, fix_type, is_differentia] [meters, meters, degrees, ublox_navpvt fix type (http://docs.ros.org/en/noetic/api/ublox_msgs/html/msg/NavPVT.html), boolean]
#define RC_NAVBOARD_ACCURACYDATA_DATA_ID                                        6105      
#define RC_NAVBOARD_ACCURACYDATA_DATA_COUNT                                     5         
#define RC_NAVBOARD_ACCURACYDATA_DATA_TYPE                                      float     

////////////////////Error
//
#define RC_NAVBOARD_GPSLOCKERROR_DATA_ID                                        6200      
#define RC_NAVBOARD_GPSLOCKERROR_DATA_COUNT                                     1         
#define RC_NAVBOARD_GPSLOCKERROR_DATA_TYPE                                      uint8_t   



///////////////////////////////////////////////////
////////////        BASESTATIONNAVBOARD ///////////         
///////////////////////////////////////////////////



///////////////////////////////////////////////////
////////////        SIGNALSTACKBOARD    ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//Motor decipercent [-1000, 1000]
#define RC_SIGNALSTACKBOARD_OPENLOOP_DATA_ID                                    7000      
#define RC_SIGNALSTACKBOARD_OPENLOOP_DATA_COUNT                                 1         
#define RC_SIGNALSTACKBOARD_OPENLOOP_DATA_TYPE                                  int16_t   

//[Heading] [0, 360)
#define RC_SIGNALSTACKBOARD_SETANGLETARGET_DATA_ID                              7001      
#define RC_SIGNALSTACKBOARD_SETANGLETARGET_DATA_COUNT                           1         
#define RC_SIGNALSTACKBOARD_SETANGLETARGET_DATA_TYPE                            float     

//[Rover Lat, Rover Long, Basestation Lat, Basestation Long] [Lat:(-90, 90), Long:(-180, 180)] (deg)
#define RC_SIGNALSTACKBOARD_SETGPSTARGET_DATA_ID                                7002      
#define RC_SIGNALSTACKBOARD_SETGPSTARGET_DATA_COUNT                             4         
#define RC_SIGNALSTACKBOARD_SETGPSTARGET_DATA_TYPE                              double    

//[0-override off, 1-override on]
#define RC_SIGNALSTACKBOARD_WATCHDOGOVERRIDE_DATA_ID                            7003      
#define RC_SIGNALSTACKBOARD_WATCHDOGOVERRIDE_DATA_COUNT                         1         
#define RC_SIGNALSTACKBOARD_WATCHDOGOVERRIDE_DATA_TYPE                          uint8_t   

////////////////////Telemetry
//[Heading] [0, 360)
#define RC_SIGNALSTACKBOARD_COMPASSANGLE_DATA_ID                                7100      
#define RC_SIGNALSTACKBOARD_COMPASSANGLE_DATA_COUNT                             1         
#define RC_SIGNALSTACKBOARD_COMPASSANGLE_DATA_TYPE                              float     

////////////////////Error
//(1-Watchdog timeout, 0-OK)
#define RC_SIGNALSTACKBOARD_WATCHDOGSTATUS_DATA_ID                              7200      
#define RC_SIGNALSTACKBOARD_WATCHDOGSTATUS_DATA_COUNT                           1         
#define RC_SIGNALSTACKBOARD_WATCHDOGSTATUS_DATA_TYPE                            uint8_t   



///////////////////////////////////////////////////
////////////        ARMBOARD            ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[X, J2, J3, J4, P, R] Motor decipercent [-1000, 1000]
#define RC_ARMBOARD_SETINDIVIDUALSPEEDS_DATA_ID                                 8000      
#define RC_ARMBOARD_SETINDIVIDUALSPEEDS_DATA_COUNT                              6         
#define RC_ARMBOARD_SETINDIVIDUALSPEEDS_DATA_TYPE                               int16_t   

//[JointID, Decipercent] Motor decipercent [-1000, 1000]
#define RC_ARMBOARD_SETJOINTSPEED_DATA_ID                                       8001      
#define RC_ARMBOARD_SETJOINTSPEED_DATA_COUNT                                    2         
#define RC_ARMBOARD_SETJOINTSPEED_DATA_TYPE                                     int16_t   

//[X, J2, J3, J4, P, R] (in, deg, deg, deg, deg, deg)
#define RC_ARMBOARD_SETINDIVIDUALTARGETANGLES_DATA_ID                           8002      
#define RC_ARMBOARD_SETINDIVIDUALTARGETANGLES_DATA_COUNT                        6         
#define RC_ARMBOARD_SETINDIVIDUALTARGETANGLES_DATA_TYPE                         float     

//[JointID, Position] (in for id 0, deg otherwise)
#define RC_ARMBOARD_SETJOINTTARGETANGLE_DATA_ID                                 8003      
#define RC_ARMBOARD_SETJOINTTARGETANGLE_DATA_COUNT                              2         
#define RC_ARMBOARD_SETJOINTTARGETANGLE_DATA_TYPE                               float     

//[X, J2, J3, J4, P, R] (in, deg, deg, deg, deg, deg)
#define RC_ARMBOARD_INCREMENTINDIVIDUALTARGETANGLES_DATA_ID                     8004      
#define RC_ARMBOARD_INCREMENTINDIVIDUALTARGETANGLES_DATA_COUNT                  6         
#define RC_ARMBOARD_INCREMENTINDIVIDUALTARGETANGLES_DATA_TYPE                   float     

//[JointID, Angle] (in for id 0, deg otherwise)
#define RC_ARMBOARD_INCREMENTJOINTTARGETANGLE_DATA_ID                           8005      
#define RC_ARMBOARD_INCREMENTJOINTTARGETANGLE_DATA_COUNT                        2         
#define RC_ARMBOARD_INCREMENTJOINTTARGETANGLE_DATA_TYPE                         float     

//[X, Y, Z, J4, P, R] (in, in, in, deg, deg, deg)
#define RC_ARMBOARD_SETIKPOSITION_DATA_ID                                       8006      
#define RC_ARMBOARD_SETIKPOSITION_DATA_COUNT                                    6         
#define RC_ARMBOARD_SETIKPOSITION_DATA_TYPE                                     float     

//[X, Y, Z, J4, P, R] (in, in, in, deg, deg, deg)
#define RC_ARMBOARD_INCREMENTIKPOSITION_DATA_ID                                 8007      
#define RC_ARMBOARD_INCREMENTIKPOSITION_DATA_COUNT                              6         
#define RC_ARMBOARD_INCREMENTIKPOSITION_DATA_TYPE                               float     

//[J4, P, R] (deg, deg, deg)
#define RC_ARMBOARD_SETLOCKMODEPOSITION_DATA_ID                                 8008      
#define RC_ARMBOARD_SETLOCKMODEPOSITION_DATA_COUNT                              3         
#define RC_ARMBOARD_SETLOCKMODEPOSITION_DATA_TYPE                               float     

//[J4, P, R] (deg, deg, deg)
#define RC_ARMBOARD_INCREMENTLOCKMODEPOSITION_DATA_ID                           8009      
#define RC_ARMBOARD_INCREMENTLOCKMODEPOSITION_DATA_COUNT                        3         
#define RC_ARMBOARD_INCREMENTLOCKMODEPOSITION_DATA_TYPE                         float     

//[0-disable, 1-enable]
#define RC_ARMBOARD_LASER_DATA_ID                                               8010      
#define RC_ARMBOARD_LASER_DATA_COUNT                                            1         
#define RC_ARMBOARD_LASER_DATA_TYPE                                             uint8_t   

//[0-retract, 1-extend]
#define RC_ARMBOARD_SOLENOID_DATA_ID                                            8011      
#define RC_ARMBOARD_SOLENOID_DATA_COUNT                                         1         
#define RC_ARMBOARD_SOLENOID_DATA_TYPE                                          uint8_t   

//Motor decipercent [-1000, 1000]
#define RC_ARMBOARD_SETGRIPPERSPEED_DATA_ID                                     8012      
#define RC_ARMBOARD_SETGRIPPERSPEED_DATA_COUNT                                  1         
#define RC_ARMBOARD_SETGRIPPERSPEED_DATA_TYPE                                   int16_t   

//[0-override off, 1-override on] (bitmasked)
#define RC_ARMBOARD_WATCHDOGOVERRIDE_DATA_ID                                    8013      
#define RC_ARMBOARD_WATCHDOGOVERRIDE_DATA_COUNT                                 1         
#define RC_ARMBOARD_WATCHDOGOVERRIDE_DATA_TYPE                                  uint8_t   

//[X+, X-, J2+, J2-, J3+, J3-, J4+, J4-, P] (0-override off, 1-override on) (bitmasked)
#define RC_ARMBOARD_LIMITSWITCHOVERRIDE_DATA_ID                                 8014      
#define RC_ARMBOARD_LIMITSWITCHOVERRIDE_DATA_COUNT                              1         
#define RC_ARMBOARD_LIMITSWITCHOVERRIDE_DATA_TYPE                               uint16_t  

//[X, J2, J3, J4, P, R] (0-override off, 1-override on) (bitmasked)
#define RC_ARMBOARD_CLOSEDLOOPOVERRIDE_DATA_ID                                  8015      
#define RC_ARMBOARD_CLOSEDLOOPOVERRIDE_DATA_COUNT                               1         
#define RC_ARMBOARD_CLOSEDLOOPOVERRIDE_DATA_TYPE                                uint8_t   

//[X, Roll] (1-calibrate, 0-no action) (bitmasked)
#define RC_ARMBOARD_CALIBRATEENCODER_DATA_ID                                    8016      
#define RC_ARMBOARD_CALIBRATEENCODER_DATA_COUNT                                 1         
#define RC_ARMBOARD_CALIBRATEENCODER_DATA_TYPE                                  uint8_t   

//[X+, X-, J2+, J2-, J3+, J3-, J4+, J4-, P+, P-] (0-override off, 1-override on) (bitmasked)
#define RC_ARMBOARD_SOFTLIMITOVERRIDE_DATA_ID                                   8017      
#define RC_ARMBOARD_SOFTLIMITOVERRIDE_DATA_COUNT                                1         
#define RC_ARMBOARD_SOFTLIMITOVERRIDE_DATA_TYPE                                 uint16_t  

//Shut off all motors (set decipercents to 0 and disable closed loop)
#define RC_ARMBOARD_ESTOP_DATA_ID                                               8018      
#define RC_ARMBOARD_ESTOP_DATA_COUNT                                            1         
#define RC_ARMBOARD_ESTOP_DATA_TYPE                                             uint8_t   

////////////////////Telemetry
//[X, J2, J3, J4, P, R] (in, deg, deg, deg, deg, deg)
#define RC_ARMBOARD_POSITIONS_DATA_ID                                           8100      
#define RC_ARMBOARD_POSITIONS_DATA_COUNT                                        6         
#define RC_ARMBOARD_POSITIONS_DATA_TYPE                                         float     

//[X, Y, Z, J4, P, R] (in, in, in, deg, deg, deg)
#define RC_ARMBOARD_COORDINATES_DATA_ID                                         8101      
#define RC_ARMBOARD_COORDINATES_DATA_COUNT                                      6         
#define RC_ARMBOARD_COORDINATES_DATA_TYPE                                       float     

//[X+, X-, J2+, J2-, J3+, J3-, J4+, J4-, P] (0-off, 1-on) (bitmasked)
#define RC_ARMBOARD_LIMITSWITCHTRIGGERED_DATA_ID                                8102      
#define RC_ARMBOARD_LIMITSWITCHTRIGGERED_DATA_COUNT                             1         
#define RC_ARMBOARD_LIMITSWITCHTRIGGERED_DATA_TYPE                              uint16_t  

////////////////////Error
//(1-Watchdog timeout, 0-OK)
#define RC_ARMBOARD_WATCHDOGSTATUS_DATA_ID                                      8200      
#define RC_ARMBOARD_WATCHDOGSTATUS_DATA_COUNT                                   1         
#define RC_ARMBOARD_WATCHDOGSTATUS_DATA_TYPE                                    uint8_t   

////////////////////Enums
enum ARMBOARD_JOINTS {X,J2,J3,J4,PITCH,ROLL}; 


///////////////////////////////////////////////////
////////////        AUGERBOARD          ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//Motor decipercent [-1000, 1000]
#define RC_AUGERBOARD_AUGERAXIS_OPENLOOP_DATA_ID                                9000      
#define RC_AUGERBOARD_AUGERAXIS_OPENLOOP_DATA_COUNT                             1         
#define RC_AUGERBOARD_AUGERAXIS_OPENLOOP_DATA_TYPE                              int16_t   

//Absolute position (in)
#define RC_AUGERBOARD_AUGERAXIS_SETPOSITION_DATA_ID                             9001      
#define RC_AUGERBOARD_AUGERAXIS_SETPOSITION_DATA_COUNT                          1         
#define RC_AUGERBOARD_AUGERAXIS_SETPOSITION_DATA_TYPE                           float     

//(in)
#define RC_AUGERBOARD_AUGERAXIS_INCREMENTPOSITION_DATA_ID                       9002      
#define RC_AUGERBOARD_AUGERAXIS_INCREMENTPOSITION_DATA_COUNT                    1         
#define RC_AUGERBOARD_AUGERAXIS_INCREMENTPOSITION_DATA_TYPE                     float     

//[AugerAxis+, AugerAxis-] (0-override off, 1-override on) (bitmasked)
#define RC_AUGERBOARD_LIMITSWITCHOVERRIDE_DATA_ID                               9003      
#define RC_AUGERBOARD_LIMITSWITCHOVERRIDE_DATA_COUNT                            1         
#define RC_AUGERBOARD_LIMITSWITCHOVERRIDE_DATA_TYPE                             uint8_t   

//Request calibration of the AugerAxis encoder
#define RC_AUGERBOARD_CALIBRATEENCODER_DATA_ID                                  9004      
#define RC_AUGERBOARD_CALIBRATEENCODER_DATA_COUNT                               1         
#define RC_AUGERBOARD_CALIBRATEENCODER_DATA_TYPE                                uint8_t   

//Motor decipercent [-1000, 1000]
#define RC_AUGERBOARD_AUGER_DATA_ID                                             9005      
#define RC_AUGERBOARD_AUGER_DATA_COUNT                                          1         
#define RC_AUGERBOARD_AUGER_DATA_TYPE                                           int16_t   

//[0-override off, 1-override on]
#define RC_AUGERBOARD_WATCHDOGOVERRIDE_DATA_ID                                  9006      
#define RC_AUGERBOARD_WATCHDOGOVERRIDE_DATA_COUNT                               1         
#define RC_AUGERBOARD_WATCHDOGOVERRIDE_DATA_TYPE                                uint8_t   

//Request a reading of the temperature at the end of the auger
#define RC_AUGERBOARD_REQUESTTEMPERATURE_DATA_ID                                9007      
#define RC_AUGERBOARD_REQUESTTEMPERATURE_DATA_COUNT                             1         
#define RC_AUGERBOARD_REQUESTTEMPERATURE_DATA_TYPE                              uint8_t   

//Request a reading of the humidity at the end of the auger
#define RC_AUGERBOARD_REQUESTHUMIDITY_DATA_ID                                   9008      
#define RC_AUGERBOARD_REQUESTHUMIDITY_DATA_COUNT                                1         
#define RC_AUGERBOARD_REQUESTHUMIDITY_DATA_TYPE                                 uint8_t   

//Ultraviolet LED on AutoFluorescence (0-off, 1-on)
#define RC_AUGERBOARD_UVLED_DATA_ID                                             9009      
#define RC_AUGERBOARD_UVLED_DATA_COUNT                                          1         
#define RC_AUGERBOARD_UVLED_DATA_TYPE                                           uint8_t   

//[Pan, Tilt](degrees -180-180)
#define RC_AUGERBOARD_AUGERGIMBALINCREMENT_DATA_ID                              9010      
#define RC_AUGERBOARD_AUGERGIMBALINCREMENT_DATA_COUNT                           2         
#define RC_AUGERBOARD_AUGERGIMBALINCREMENT_DATA_TYPE                            int16_t   

////////////////////Telemetry
//[AugerAxis] (in)
#define RC_AUGERBOARD_POSITION_DATA_ID                                          9100      
#define RC_AUGERBOARD_POSITION_DATA_COUNT                                       1         
#define RC_AUGERBOARD_POSITION_DATA_TYPE                                        float     

//(in/s)
#define RC_AUGERBOARD_AUGERSPEED_DATA_ID                                        9101      
#define RC_AUGERBOARD_AUGERSPEED_DATA_COUNT                                     1         
#define RC_AUGERBOARD_AUGERSPEED_DATA_TYPE                                      float     

//[AugerAxis+, AugerAxis-] (0-off, 1-on) (bitmasked)
#define RC_AUGERBOARD_LIMITSWITCHTRIGGERED_DATA_ID                              9102      
#define RC_AUGERBOARD_LIMITSWITCHTRIGGERED_DATA_COUNT                           1         
#define RC_AUGERBOARD_LIMITSWITCHTRIGGERED_DATA_TYPE                            uint8_t   

//[Temperature] (degrees C)
#define RC_AUGERBOARD_TEMPERATURE_DATA_ID                                       9103      
#define RC_AUGERBOARD_TEMPERATURE_DATA_COUNT                                    1         
#define RC_AUGERBOARD_TEMPERATURE_DATA_TYPE                                     float     

//[Humidity] (relative humidity %)
#define RC_AUGERBOARD_HUMIDITY_DATA_ID                                          9104      
#define RC_AUGERBOARD_HUMIDITY_DATA_COUNT                                       1         
#define RC_AUGERBOARD_HUMIDITY_DATA_TYPE                                        float     

////////////////////Error
//(1-Watchdog timeout, 0-OK)
#define RC_AUGERBOARD_WATCHDOGSTATUS_DATA_ID                                    9200      
#define RC_AUGERBOARD_WATCHDOGSTATUS_DATA_COUNT                                 1         
#define RC_AUGERBOARD_WATCHDOGSTATUS_DATA_TYPE                                  uint8_t   

//(1-Stalled, 0-OK)
#define RC_AUGERBOARD_AUGERSTALLED_DATA_ID                                      9201      
#define RC_AUGERBOARD_AUGERSTALLED_DATA_COUNT                                   1         
#define RC_AUGERBOARD_AUGERSTALLED_DATA_TYPE                                    uint8_t   



///////////////////////////////////////////////////
////////////        AUTONOMYBOARD       ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//Start Autonomy_Software
#define RC_AUTONOMYBOARD_STARTAUTONOMY_DATA_ID                                  11000     
#define RC_AUTONOMYBOARD_STARTAUTONOMY_DATA_COUNT                               1         
#define RC_AUTONOMYBOARD_STARTAUTONOMY_DATA_TYPE                                uint8_t   

//Return Autonomy_Software to Idle state
#define RC_AUTONOMYBOARD_DISABLEAUTONOMY_DATA_ID                                11001     
#define RC_AUTONOMYBOARD_DISABLEAUTONOMY_DATA_COUNT                             1         
#define RC_AUTONOMYBOARD_DISABLEAUTONOMY_DATA_TYPE                              uint8_t   

//[Lat, Lon]
#define RC_AUTONOMYBOARD_ADDPOSITIONLEG_DATA_ID                                 11002     
#define RC_AUTONOMYBOARD_ADDPOSITIONLEG_DATA_COUNT                              2         
#define RC_AUTONOMYBOARD_ADDPOSITIONLEG_DATA_TYPE                               double    

//[Lat, Lon, MarkerID, MarkerRadius (meters)]
#define RC_AUTONOMYBOARD_ADDMARKERLEG_DATA_ID                                   11003     
#define RC_AUTONOMYBOARD_ADDMARKERLEG_DATA_COUNT                                4         
#define RC_AUTONOMYBOARD_ADDMARKERLEG_DATA_TYPE                                 double    

//[Lat, Lon, ObjectRadius (meters)]
#define RC_AUTONOMYBOARD_ADDOBJECTLEG_DATA_ID                                   11004     
#define RC_AUTONOMYBOARD_ADDOBJECTLEG_DATA_COUNT                                3         
#define RC_AUTONOMYBOARD_ADDOBJECTLEG_DATA_TYPE                                 double    

//Clear queued positions, markers, and objects waypoints.
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATA_ID                                 11005     
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATA_COUNT                              1         
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATA_TYPE                               uint8_t   

//A multiplier from 0.0 to 1.0 that will scale the max power effort of Autonomy
#define RC_AUTONOMYBOARD_SETMAXSPEED_DATA_ID                                    11006     
#define RC_AUTONOMYBOARD_SETMAXSPEED_DATA_COUNT                                 1         
#define RC_AUTONOMYBOARD_SETMAXSPEED_DATA_TYPE                                  float     

//[Enum (AUTONOMYLOG), Enum (AUTONOMYLOG), Enum (AUTONOMYLOG)] {Console, File, RoveComm}
#define RC_AUTONOMYBOARD_SETLOGGINGLEVELS_DATA_ID                               11007     
#define RC_AUTONOMYBOARD_SETLOGGINGLEVELS_DATA_COUNT                            3         
#define RC_AUTONOMYBOARD_SETLOGGINGLEVELS_DATA_TYPE                             uint8_t   

//[Lat, Lon, ObstacleRadius (meters)]
#define RC_AUTONOMYBOARD_ADDOBSTACLE_DATA_ID                                    11008     
#define RC_AUTONOMYBOARD_ADDOBSTACLE_DATA_COUNT                                 3         
#define RC_AUTONOMYBOARD_ADDOBSTACLE_DATA_TYPE                                  double    

//Clear queued permanent obstacles.
#define RC_AUTONOMYBOARD_CLEAROBSTACLES_DATA_ID                                 11009     
#define RC_AUTONOMYBOARD_CLEAROBSTACLES_DATA_COUNT                              1         
#define RC_AUTONOMYBOARD_CLEAROBSTACLES_DATA_TYPE                               uint8_t   

////////////////////Telemetry
//Enum (AUTONOMYSTATE)
#define RC_AUTONOMYBOARD_CURRENTSTATE_DATA_ID                                   11100     
#define RC_AUTONOMYBOARD_CURRENTSTATE_DATA_COUNT                                1         
#define RC_AUTONOMYBOARD_CURRENTSTATE_DATA_TYPE                                 uint8_t   

//
#define RC_AUTONOMYBOARD_REACHEDGOAL_DATA_ID                                    11101     
#define RC_AUTONOMYBOARD_REACHEDGOAL_DATA_COUNT                                 1         
#define RC_AUTONOMYBOARD_REACHEDGOAL_DATA_TYPE                                  uint8_t   

//String version of most current error log
#define RC_AUTONOMYBOARD_CURRENTLOG_DATA_ID                                     11102     
#define RC_AUTONOMYBOARD_CURRENTLOG_DATA_COUNT                                  255       
#define RC_AUTONOMYBOARD_CURRENTLOG_DATA_TYPE                                   char      

//[Thread Enum ID, FPS Value]
#define RC_AUTONOMYBOARD_THREADFPS_DATA_ID                                      11103     
#define RC_AUTONOMYBOARD_THREADFPS_DATA_COUNT                                   2         
#define RC_AUTONOMYBOARD_THREADFPS_DATA_TYPE                                    uint32_t  

////////////////////Enums
enum AUTONOMYBOARD_AUTONOMYSTATE {IDLE,NAVIGATING,SEARCHPATTERN,APPROACHINGMARKER,APPROACHINGOBJECT,VERIFYINGGPS,VERIFYINGMARKER,VERIFYINGOBJECT,AVOIDANCE,REVERSING,STUCK}; 
enum AUTONOMYBOARD_AUTONOMYLOG {TRACEL3,TRACEL2,TRACEL1,DEBUG,INFO,NOTICE,WARNING,ERROR,CRITICAL}; 
enum AUTONOMYBOARD_AUTONOMYTHREADS {MAINPROCESS,MAINCAM,LEFTCAM,RIGHTCAM,GROUNDCAM,MAINDETECTOR,LEFTDETECTOR,RIGHTDETECTOR,STATEMACHINE,ROVECOMMUDP,ROVECOMMTCP}; 


///////////////////////////////////////////////////
////////////        CAMERA1BOARD        ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//Change which camera a feed is looking at. [0] is the feed, [1] is the camera to view.
#define RC_CAMERA1BOARD_CHANGECAMERAS_DATA_ID                                   12000     
#define RC_CAMERA1BOARD_CHANGECAMERAS_DATA_COUNT                                2         
#define RC_CAMERA1BOARD_CHANGECAMERAS_DATA_TYPE                                 uint8_t   

//Take a picture with the current camera. [0] is the camera to take a picture with. [1] tells the camera whether to restart the stream afterwards.
#define RC_CAMERA1BOARD_TAKEPICTURE_DATA_ID                                     12001     
#define RC_CAMERA1BOARD_TAKEPICTURE_DATA_COUNT                                  2         
#define RC_CAMERA1BOARD_TAKEPICTURE_DATA_TYPE                                   uint8_t   

//Stop the current camera stream. [0] is the camera to stop streaming. [1] is whether to restart the stream.
#define RC_CAMERA1BOARD_TOGGLESTREAM1_DATA_ID                                   12002     
#define RC_CAMERA1BOARD_TOGGLESTREAM1_DATA_COUNT                                2         
#define RC_CAMERA1BOARD_TOGGLESTREAM1_DATA_TYPE                                 uint8_t   

////////////////////Telemetry
//Bitmask values for which cameras are able to stream. LSB is Camera 0, MSB is Camera 7.
#define RC_CAMERA1BOARD_AVAILABLECAMERAS_DATA_ID                                12100     
#define RC_CAMERA1BOARD_AVAILABLECAMERAS_DATA_COUNT                             1         
#define RC_CAMERA1BOARD_AVAILABLECAMERAS_DATA_TYPE                              uint8_t   

//Which cameras the system is currently streaming on each port
#define RC_CAMERA1BOARD_STREAMINGCAMERAS_DATA_ID                                12101     
#define RC_CAMERA1BOARD_STREAMINGCAMERAS_DATA_COUNT                             4         
#define RC_CAMERA1BOARD_STREAMINGCAMERAS_DATA_TYPE                              uint8_t   

//Picture has been taken.
#define RC_CAMERA1BOARD_PICTURETAKEN1_DATA_ID                                   12102     
#define RC_CAMERA1BOARD_PICTURETAKEN1_DATA_COUNT                                1         
#define RC_CAMERA1BOARD_PICTURETAKEN1_DATA_TYPE                                 uint8_t   

////////////////////Error
//Camera has errored and stopped streaming. [0] is ID of camera as an integer (not bitmask).
#define RC_CAMERA1BOARD_CAMERAUNAVAILABLE_DATA_ID                               12200     
#define RC_CAMERA1BOARD_CAMERAUNAVAILABLE_DATA_COUNT                            1         
#define RC_CAMERA1BOARD_CAMERAUNAVAILABLE_DATA_TYPE                             uint8_t   



///////////////////////////////////////////////////
////////////        CAMERA2BOARD        ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//Take a picture with the current camera. [0] is the camera to take a picture with. [1] tells the camera whether to restart the stream afterwards.
#define RC_CAMERA2BOARD_TAKEPICTURE_DATA_ID                                     13001     
#define RC_CAMERA2BOARD_TAKEPICTURE_DATA_COUNT                                  2         
#define RC_CAMERA2BOARD_TAKEPICTURE_DATA_TYPE                                   uint8_t   

//Stop the current camera stream. [0] is the camera to stop streaming. [1] is whether to restart the stream.
#define RC_CAMERA2BOARD_TOGGLESTREAM2_DATA_ID                                   13002     
#define RC_CAMERA2BOARD_TOGGLESTREAM2_DATA_COUNT                                2         
#define RC_CAMERA2BOARD_TOGGLESTREAM2_DATA_TYPE                                 uint8_t   

////////////////////Telemetry
//Picture has been taken.
#define RC_CAMERA2BOARD_PICTURETAKEN2_DATA_ID                                   13100     
#define RC_CAMERA2BOARD_PICTURETAKEN2_DATA_COUNT                                1         
#define RC_CAMERA2BOARD_PICTURETAKEN2_DATA_TYPE                                 uint8_t   



///////////////////////////////////////////////////
////////////        CAMERASERVERBOARD   ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//Take a picture with the current camera. [0] is the camera to take a picture with.
#define RC_CAMERASERVERBOARD_TAKEPHOTO_DATA_ID                                  14000     
#define RC_CAMERASERVERBOARD_TAKEPHOTO_DATA_COUNT                               1         
#define RC_CAMERASERVERBOARD_TAKEPHOTO_DATA_TYPE                                uint8_t   

//Stop the current camera stream. [0] is the camera to stop streaming. [1] is the action (0 = Shutdown, 1 = Startup, 2 = Restart).
#define RC_CAMERASERVERBOARD_TOGGLESTREAM_DATA_ID                               14001     
#define RC_CAMERASERVERBOARD_TOGGLESTREAM_DATA_COUNT                            2         
#define RC_CAMERASERVERBOARD_TOGGLESTREAM_DATA_TYPE                             uint8_t   

//Adjust brightness level (0-255). [0] is the camera ID, [1] is the brightness level.
#define RC_CAMERASERVERBOARD_ADJUSTBRIGHTNESS_DATA_ID                           14002     
#define RC_CAMERASERVERBOARD_ADJUSTBRIGHTNESS_DATA_COUNT                        2         
#define RC_CAMERASERVERBOARD_ADJUSTBRIGHTNESS_DATA_TYPE                         uint8_t   

//Adjust contrast level (0-255). [0] is the camera ID, [1] is the contrast level.
#define RC_CAMERASERVERBOARD_ADJUSTCONTRAST_DATA_ID                             14003     
#define RC_CAMERASERVERBOARD_ADJUSTCONTRAST_DATA_COUNT                          2         
#define RC_CAMERASERVERBOARD_ADJUSTCONTRAST_DATA_TYPE                           uint8_t   

//Adjust saturation level (0-255). [0] is the camera ID, [1] is the saturation level.
#define RC_CAMERASERVERBOARD_ADJUSTSATURATION_DATA_ID                           14004     
#define RC_CAMERASERVERBOARD_ADJUSTSATURATION_DATA_COUNT                        2         
#define RC_CAMERASERVERBOARD_ADJUSTSATURATION_DATA_TYPE                         uint8_t   

//Adjust hue level (0-255). [0] is the camera ID, [1] is the hue level.
#define RC_CAMERASERVERBOARD_ADJUSTHUE_DATA_ID                                  14005     
#define RC_CAMERASERVERBOARD_ADJUSTHUE_DATA_COUNT                               2         
#define RC_CAMERASERVERBOARD_ADJUSTHUE_DATA_TYPE                                uint8_t   

//Set white balance temperature. [0] is the camera ID, [1] is the white balance level.
#define RC_CAMERASERVERBOARD_SETWHITEBALANCE_DATA_ID                            14008     
#define RC_CAMERASERVERBOARD_SETWHITEBALANCE_DATA_COUNT                         2         
#define RC_CAMERASERVERBOARD_SETWHITEBALANCE_DATA_TYPE                          uint8_t   

//Adjust backlight contrast level (0-255). [0] is the camera ID, [1] is the backlight contrast level.
#define RC_CAMERASERVERBOARD_ADJUSTBACKLIGHTCONTRAST_DATA_ID                    14009     
#define RC_CAMERASERVERBOARD_ADJUSTBACKLIGHTCONTRAST_DATA_COUNT                 2         
#define RC_CAMERASERVERBOARD_ADJUSTBACKLIGHTCONTRAST_DATA_TYPE                  uint8_t   

//Set exposure level. [0] is the camera ID, [1] is the exposure level.
#define RC_CAMERASERVERBOARD_SETEXPOSURE_DATA_ID                                14010     
#define RC_CAMERASERVERBOARD_SETEXPOSURE_DATA_COUNT                             2         
#define RC_CAMERASERVERBOARD_SETEXPOSURE_DATA_TYPE                              int32_t   

////////////////////Telemetry
//Bitmask values for which cameras are able to stream. LSB is Camera 0, MSB is Camera 7.
#define RC_CAMERASERVERBOARD_AVAILABLECAMERAS_DATA_ID                           14100     
#define RC_CAMERASERVERBOARD_AVAILABLECAMERAS_DATA_COUNT                        1         
#define RC_CAMERASERVERBOARD_AVAILABLECAMERAS_DATA_TYPE                         uint8_t   

//Which cameras the system is currently streaming on each port
#define RC_CAMERASERVERBOARD_STREAMINGCAMERAS_DATA_ID                           14101     
#define RC_CAMERASERVERBOARD_STREAMINGCAMERAS_DATA_COUNT                        4         
#define RC_CAMERASERVERBOARD_STREAMINGCAMERAS_DATA_TYPE                         uint8_t   

//Picture has been taken.
#define RC_CAMERASERVERBOARD_PICTURETAKEN1_DATA_ID                              14102     
#define RC_CAMERASERVERBOARD_PICTURETAKEN1_DATA_COUNT                           1         
#define RC_CAMERASERVERBOARD_PICTURETAKEN1_DATA_TYPE                            uint8_t   

////////////////////Error
//Camera has errored and stopped streaming. [0] is ID of camera as an integer (not bitmask).
#define RC_CAMERASERVERBOARD_CAMERAUNAVAILABLE_DATA_ID                          14200     
#define RC_CAMERASERVERBOARD_CAMERAUNAVAILABLE_DATA_COUNT                       1         
#define RC_CAMERASERVERBOARD_CAMERAUNAVAILABLE_DATA_TYPE                        uint8_t   



///////////////////////////////////////////////////
////////////        IRSPECTROMETERBOARD ///////////         
///////////////////////////////////////////////////



///////////////////////////////////////////////////
////////////        RAMANBOARD          ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//Motor decipercent [-1000, 1000]
#define RC_RAMANBOARD_INSTRUMENTSAXIS_OPENLOOP_DATA_ID                          16000     
#define RC_RAMANBOARD_INSTRUMENTSAXIS_OPENLOOP_DATA_COUNT                       1         
#define RC_RAMANBOARD_INSTRUMENTSAXIS_OPENLOOP_DATA_TYPE                        int16_t   

//Absolute position (in)
#define RC_RAMANBOARD_INSTRUMENTSAXIS_SETPOSITION_DATA_ID                       16001     
#define RC_RAMANBOARD_INSTRUMENTSAXIS_SETPOSITION_DATA_COUNT                    1         
#define RC_RAMANBOARD_INSTRUMENTSAXIS_SETPOSITION_DATA_TYPE                     float     

//(in)
#define RC_RAMANBOARD_INSTRUMENTSAXIS_INCREMENTPOSITION_DATA_ID                 16002     
#define RC_RAMANBOARD_INSTRUMENTSAXIS_INCREMENTPOSITION_DATA_COUNT              1         
#define RC_RAMANBOARD_INSTRUMENTSAXIS_INCREMENTPOSITION_DATA_TYPE               float     

//[InstrumentsAxis+, InstrumentsAxis-] (0-override off, 1-override on) (bitmasked)
#define RC_RAMANBOARD_LIMITSWITCHOVERRIDE_DATA_ID                               16003     
#define RC_RAMANBOARD_LIMITSWITCHOVERRIDE_DATA_COUNT                            1         
#define RC_RAMANBOARD_LIMITSWITCHOVERRIDE_DATA_TYPE                             uint8_t   

//Request calibration of the InstrumentsAxis encoder
#define RC_RAMANBOARD_CALIBRATEENCODER_DATA_ID                                  16004     
#define RC_RAMANBOARD_CALIBRATEENCODER_DATA_COUNT                               1         
#define RC_RAMANBOARD_CALIBRATEENCODER_DATA_TYPE                                uint8_t   

//[0-override off, 1-override on]
#define RC_RAMANBOARD_WATCHDOGOVERRIDE_DATA_ID                                  16005     
#define RC_RAMANBOARD_WATCHDOGOVERRIDE_DATA_COUNT                               1         
#define RC_RAMANBOARD_WATCHDOGOVERRIDE_DATA_TYPE                                uint8_t   

//[0-disable, 1-enable]
#define RC_RAMANBOARD_LASER_DATA_ID                                             16006     
#define RC_RAMANBOARD_LASER_DATA_COUNT                                          1         
#define RC_RAMANBOARD_LASER_DATA_TYPE                                           uint8_t   

//Start a Raman reading, with the provided integration time (milliseconds)
#define RC_RAMANBOARD_REQUESTRAMANREADING_DATA_ID                               16007     
#define RC_RAMANBOARD_REQUESTRAMANREADING_DATA_COUNT                            1         
#define RC_RAMANBOARD_REQUESTRAMANREADING_DATA_TYPE                             uint32_t  

////////////////////Telemetry
//[InstrumentsAxis] (in)
#define RC_RAMANBOARD_POSITION_DATA_ID                                          16100     
#define RC_RAMANBOARD_POSITION_DATA_COUNT                                       1         
#define RC_RAMANBOARD_POSITION_DATA_TYPE                                        float     

//[InstrumentsAxis+, InstrumentsAxis-] (0-off, 1-on) (bitmasked)
#define RC_RAMANBOARD_LIMITSWITCHTRIGGERED_DATA_ID                              16101     
#define RC_RAMANBOARD_LIMITSWITCHTRIGGERED_DATA_COUNT                           1         
#define RC_RAMANBOARD_LIMITSWITCHTRIGGERED_DATA_TYPE                            uint8_t   

//Raman CCD elements 1-512
#define RC_RAMANBOARD_RAMANREADING_PART1_DATA_ID                                16102     
#define RC_RAMANBOARD_RAMANREADING_PART1_DATA_COUNT                             512       
#define RC_RAMANBOARD_RAMANREADING_PART1_DATA_TYPE                              uint16_t  

//Raman CCD elements 513-1024
#define RC_RAMANBOARD_RAMANREADING_PART2_DATA_ID                                16103     
#define RC_RAMANBOARD_RAMANREADING_PART2_DATA_COUNT                             512       
#define RC_RAMANBOARD_RAMANREADING_PART2_DATA_TYPE                              uint16_t  

//Raman CCD elements 1025-1536
#define RC_RAMANBOARD_RAMANREADING_PART3_DATA_ID                                16104     
#define RC_RAMANBOARD_RAMANREADING_PART3_DATA_COUNT                             512       
#define RC_RAMANBOARD_RAMANREADING_PART3_DATA_TYPE                              uint16_t  

//Raman CCD elements 1537-2048
#define RC_RAMANBOARD_RAMANREADING_PART4_DATA_ID                                16105     
#define RC_RAMANBOARD_RAMANREADING_PART4_DATA_COUNT                             512       
#define RC_RAMANBOARD_RAMANREADING_PART4_DATA_TYPE                              uint16_t  

////////////////////Error
//(1-Watchdog timeout, 0-OK)
#define RC_RAMANBOARD_WATCHDOGSTATUS_DATA_ID                                    16200     
#define RC_RAMANBOARD_WATCHDOGSTATUS_DATA_COUNT                                 1         
#define RC_RAMANBOARD_WATCHDOGSTATUS_DATA_TYPE                                  uint8_t   



///////////////////////////////////////////////////
////////////        ROVESOSIMULATORBOARD///////////         
///////////////////////////////////////////////////

////////////////////Telemetry
//Ultrasonic sensor distance reading in centimeters (cm). Value ranges from 0.00 to 500.00 cm
#define RC_ROVESOSIMULATORBOARD_ULTRASONIC1_DATA_ID                             99100     
#define RC_ROVESOSIMULATORBOARD_ULTRASONIC1_DATA_COUNT                          2         
#define RC_ROVESOSIMULATORBOARD_ULTRASONIC1_DATA_TYPE                           float     



#endif // ROVECOMM_MANIFEST_H