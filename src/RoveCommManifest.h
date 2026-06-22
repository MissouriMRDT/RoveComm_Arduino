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

#define RC_MANIFEST_TIME                                    1771280511
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
//[LeftSpeed, RightSpeed] (-1 - 1) -> (-100% - 100%)
#define RC_COREBOARD_DRIVELEFTRIGHT_DATA_ID                                     3000      
#define RC_COREBOARD_DRIVELEFTRIGHT_DATA_COUNT                                  2         
#define RC_COREBOARD_DRIVELEFTRIGHT_DATA_TYPE                                   float     

//[LF, LM, LR, RF, RM, RR] (-1 - 1) -> (-100% - 100%)
#define RC_COREBOARD_DRIVEINDIVIDUAL_DATA_ID                                    3001      
#define RC_COREBOARD_DRIVEINDIVIDUAL_DATA_COUNT                                 6         
#define RC_COREBOARD_DRIVEINDIVIDUAL_DATA_TYPE                                  float     

//[Enabled]
#define RC_COREBOARD_WATCHDOGOVERRIDE_DATA_ID                                   3002      
#define RC_COREBOARD_WATCHDOGOVERRIDE_DATA_COUNT                                1         
#define RC_COREBOARD_WATCHDOGOVERRIDE_DATA_TYPE                                 uint8_t   

//[Pan, Tilt] (0 - 180)
#define RC_COREBOARD_LEFTGIMBAL_DATA_ID                                         3003      
#define RC_COREBOARD_LEFTGIMBAL_DATA_COUNT                                      2         
#define RC_COREBOARD_LEFTGIMBAL_DATA_TYPE                                       int16_t   

//[Pan, Tilt] (0 - 180)
#define RC_COREBOARD_RIGHTGIMBAL_DATA_ID                                        3004      
#define RC_COREBOARD_RIGHTGIMBAL_DATA_COUNT                                     2         
#define RC_COREBOARD_RIGHTGIMBAL_DATA_TYPE                                      int16_t   

//[Pan, Tilt] (0 - 180)
#define RC_COREBOARD_BACKGIMBAL_DATA_ID                                         3005      
#define RC_COREBOARD_BACKGIMBAL_DATA_COUNT                                      2         
#define RC_COREBOARD_BACKGIMBAL_DATA_TYPE                                       int16_t   

//[R, G, B] (brightness 0 - 255)
#define RC_COREBOARD_LEDRGB_DATA_ID                                             3006      
#define RC_COREBOARD_LEDRGB_DATA_COUNT                                          3         
#define RC_COREBOARD_LEDRGB_DATA_TYPE                                           uint8_t   

//[Color] (RGBA)
#define RC_COREBOARD_BACKIMAGE_DATA_ID                                          3007      
#define RC_COREBOARD_BACKIMAGE_DATA_COUNT                                       256       
#define RC_COREBOARD_BACKIMAGE_DATA_TYPE                                        uint32_t  

//[R, G, B] (brightness 0 - 255)
#define RC_COREBOARD_INTERNALRGB_DATA_ID                                        3008      
#define RC_COREBOARD_INTERNALRGB_DATA_COUNT                                     3         
#define RC_COREBOARD_INTERNALRGB_DATA_TYPE                                      uint8_t   

//[Color] (RGBA)
#define RC_COREBOARD_INTERNALIMAGE_DATA_ID                                      3009      
#define RC_COREBOARD_INTERNALIMAGE_DATA_COUNT                                   256       
#define RC_COREBOARD_INTERNALIMAGE_DATA_TYPE                                    uint32_t  

//[State] (DisplayState)
#define RC_COREBOARD_STATEDISPLAY_DATA_ID                                       3010      
#define RC_COREBOARD_STATEDISPLAY_DATA_COUNT                                    1         
#define RC_COREBOARD_STATEDISPLAY_DATA_TYPE                                     uint8_t   

//[Brightness] (0 - 255)
#define RC_COREBOARD_BRIGHTNESS_DATA_ID                                         3011      
#define RC_COREBOARD_BRIGHTNESS_DATA_COUNT                                      1         
#define RC_COREBOARD_BRIGHTNESS_DATA_TYPE                                       uint8_t   

//[Mode] (0: Teleop 1: Autonomy)
#define RC_COREBOARD_SETWATCHDOGMODE_DATA_ID                                    3012      
#define RC_COREBOARD_SETWATCHDOGMODE_DATA_COUNT                                 1         
#define RC_COREBOARD_SETWATCHDOGMODE_DATA_TYPE                                  uint8_t   

//[Message] (null terminated string)
#define RC_COREBOARD_LEDTEXT_DATA_ID                                            3013      
#define RC_COREBOARD_LEDTEXT_DATA_COUNT                                         256       
#define RC_COREBOARD_LEDTEXT_DATA_TYPE                                          char      

////////////////////Telemetry
//[FL, ML, BL, FR, MR, BR] (-1 - 1) -> (-100% - 100%)
#define RC_COREBOARD_MOTORSPEEDS_DATA_ID                                        3100      
#define RC_COREBOARD_MOTORSPEEDS_DATA_COUNT                                     6         
#define RC_COREBOARD_MOTORSPEEDS_DATA_TYPE                                      float     

//[FL, ML, BL, FR, MR, BR] (A)
#define RC_COREBOARD_MOTORCURRENTS_DATA_ID                                      3101      
#define RC_COREBOARD_MOTORCURRENTS_DATA_COUNT                                   6         
#define RC_COREBOARD_MOTORCURRENTS_DATA_TYPE                                    float     

//[FL, ML, BL, FR, MR, BR] (A battery side)
#define RC_COREBOARD_VESCCURRENTS_DATA_ID                                       3102      
#define RC_COREBOARD_VESCCURRENTS_DATA_COUNT                                    6         
#define RC_COREBOARD_VESCCURRENTS_DATA_TYPE                                     float     

//[Roll, Pitch] (deg)
#define RC_COREBOARD_IMUDATA_DATA_ID                                            3103      
#define RC_COREBOARD_IMUDATA_DATA_COUNT                                         2         
#define RC_COREBOARD_IMUDATA_DATA_TYPE                                          float     

//[X, Y, Z] (m/s2)
#define RC_COREBOARD_ACCELEROMETERDATA_DATA_ID                                  3104      
#define RC_COREBOARD_ACCELEROMETERDATA_DATA_COUNT                               3         
#define RC_COREBOARD_ACCELEROMETERDATA_DATA_TYPE                                float     

//[FanSpeed, BoardTemperature, OtherTemperature] (rpm, C, C)
#define RC_COREBOARD_THERMAL_DATA_ID                                            3105      
#define RC_COREBOARD_THERMAL_DATA_COUNT                                         3         
#define RC_COREBOARD_THERMAL_DATA_TYPE                                          float     

////////////////////Error
//[MotorID, FaultCode]
#define RC_COREBOARD_VESCFAULT_DATA_ID                                          3200      
#define RC_COREBOARD_VESCFAULT_DATA_COUNT                                       2         
#define RC_COREBOARD_VESCFAULT_DATA_TYPE                                        uint8_t   

////////////////////Enums
enum COREBOARD_MOTORS {FRONT_LEFT,MIDDLE_LEFT,BACK_LEFT,FRONT_RIGHT,MIDDLE_RIGHT,BACK_RIGHT}; 
enum COREBOARD_DISPLAYSTATE {TELEOP,AUTONOMY,REACHED_GOAL}; 
enum COREBOARD_VESCFAULTCODE {NONE,OVER_VOLTAGE,UNDER_VOLTAGE,DRV,ABS_OVER_CURRENT,OVER_TEMP_FET,OVER_TEMP_MOTOR,GATE_DRIVER_OVER_VOLTAGE,GATE_DRIVER_UNDER_VOLTAGE,MCU_UNDER_VOLTAGE,BOOTING_FROM_WATCHDOG_RESET,ENCODER_SPI,ENCODER_SINCOS_BELOW_MIN_AMPLITUDE,ENCODER_SINCOS_ABOVE_MAX_AMPLITUDE,FLASH_CORRUPTION,HIGH_OFFSET_CURRENT_SENSOR_1,HIGH_OFFSET_CURRENT_SENSOR_2,HIGH_OFFSET_CURRENT_SENSOR_3,UNBALANCED_CURRENTS,BRK,RESOLVER_LOT,RESOLVER_DOS,RESOLVER_LOS,FLASH_CORRUPTION_APP_CFG,FLASH_CORRUPTION_MC_CFG,ENCODER_NO_MAGNET,ENCODER_MAGNET_TOO_STRONG,PHASE_FILTER}; 


///////////////////////////////////////////////////
////////////        PMSBOARD            ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//Power off all systems except network (PMS will stay on)
#define RC_PMSBOARD_ESTOP_DATA_ID                                               4000      
#define RC_PMSBOARD_ESTOP_DATA_COUNT                                            0         
#define RC_PMSBOARD_ESTOP_DATA_TYPE                                             uint8_t   

//Power off all systems including network, cannot recover without physical reboot (PMS will stay on)
#define RC_PMSBOARD_SUICIDE_DATA_ID                                             4001      
#define RC_PMSBOARD_SUICIDE_DATA_COUNT                                          0         
#define RC_PMSBOARD_SUICIDE_DATA_TYPE                                           uint8_t   

//Cycle all systems including network off and back on (PMS will stay on)
#define RC_PMSBOARD_REBOOT_DATA_ID                                              4002      
#define RC_PMSBOARD_REBOOT_DATA_COUNT                                           0         
#define RC_PMSBOARD_REBOOT_DATA_TYPE                                            uint8_t   

//[Motor, Core, Aux] (bitmask enable)
#define RC_PMSBOARD_ENABLEBUS_DATA_ID                                           4003      
#define RC_PMSBOARD_ENABLEBUS_DATA_COUNT                                        1         
#define RC_PMSBOARD_ENABLEBUS_DATA_TYPE                                         uint8_t   

//[Motor, Core, Aux] (bitmask disable)
#define RC_PMSBOARD_DISABLEBUS_DATA_ID                                          4004      
#define RC_PMSBOARD_DISABLEBUS_DATA_COUNT                                       1         
#define RC_PMSBOARD_DISABLEBUS_DATA_TYPE                                        uint8_t   

//[Motor, Core, Aux] (bitmask enabled)
#define RC_PMSBOARD_SETBUS_DATA_ID                                              4005      
#define RC_PMSBOARD_SETBUS_DATA_COUNT                                           1         
#define RC_PMSBOARD_SETBUS_DATA_TYPE                                            uint8_t   

////////////////////Telemetry
//[PackCurrent, AuxCurrent, LowCurrent, NetworkCurrent, RadioM2Current, RadioM9Current, Cell1Voltage, Cell2Voltage, Cell3Voltage, Cell4Voltage, Cell5Voltage, Cell6Voltage] (A, A, A, A, A, A, V, V, V, V, V, V)
#define RC_PMSBOARD_CURRENTANDVOLTAGE_DATA_ID                                   4100      
#define RC_PMSBOARD_CURRENTANDVOLTAGE_DATA_COUNT                                12        
#define RC_PMSBOARD_CURRENTANDVOLTAGE_DATA_TYPE                                 float     

//[Motor, Core, Aux, RadioM2, RadioM9, Network] (bitmask enabled)
#define RC_PMSBOARD_BUSSTATUS_DATA_ID                                           4101      
#define RC_PMSBOARD_BUSSTATUS_DATA_COUNT                                        1         
#define RC_PMSBOARD_BUSSTATUS_DATA_TYPE                                         uint8_t   

////////////////////Error
//Higher current draw than the battery can support. Rover will Reboot automatically
#define RC_PMSBOARD_PACKOVERCURRENT_DATA_ID                                     4200      
#define RC_PMSBOARD_PACKOVERCURRENT_DATA_COUNT                                  0         
#define RC_PMSBOARD_PACKOVERCURRENT_DATA_TYPE                                   uint8_t   

//[C1, C2, C3, C4, C5, C6] (bitmask undervolt) Rover will EStop automatically
#define RC_PMSBOARD_CELLUNDERVOLTAGE_DATA_ID                                    4201      
#define RC_PMSBOARD_CELLUNDERVOLTAGE_DATA_COUNT                                 1         
#define RC_PMSBOARD_CELLUNDERVOLTAGE_DATA_TYPE                                  uint8_t   

//[C1, C2, C3, C4, C5, C6] (bitmask critical) Rover will Suicide automatically
#define RC_PMSBOARD_CELLCRITICAL_DATA_ID                                        4202      
#define RC_PMSBOARD_CELLCRITICAL_DATA_COUNT                                     1         
#define RC_PMSBOARD_CELLCRITICAL_DATA_TYPE                                      uint8_t   

//Aux system current draw too high. Rover will disable Aux bus automatically
#define RC_PMSBOARD_AUXOVERCURRENT_DATA_ID                                      4203      
#define RC_PMSBOARD_AUXOVERCURRENT_DATA_COUNT                                   0         
#define RC_PMSBOARD_AUXOVERCURRENT_DATA_TYPE                                    uint8_t   



///////////////////////////////////////////////////
////////////        NAVBOARD            ///////////         
///////////////////////////////////////////////////

////////////////////Telemetry
//[Lat, Lon, Alt, HorizontalAccuracy, VerticalAccuracy, HeadingAccuracy, FixType, IsDifferential] (deg, deg, m, m, m, deg, ublox_navpvt fix type http://docs.ros.org/en/noetic/api/ublox_msgs/html/msg/NavPVT.html, bool)
#define RC_NAVBOARD_GPSLATLONALT_DATA_ID                                        6100      
#define RC_NAVBOARD_GPSLATLONALT_DATA_COUNT                                     8         
#define RC_NAVBOARD_GPSLATLONALT_DATA_TYPE                                      double    

//[Heading] (0 - 360)
#define RC_NAVBOARD_COMPASSDATA_DATA_ID                                         6102      
#define RC_NAVBOARD_COMPASSDATA_DATA_COUNT                                      1         
#define RC_NAVBOARD_COMPASSDATA_DATA_TYPE                                       float     

//[Satellites]
#define RC_NAVBOARD_SATELLITECOUNTDATA_DATA_ID                                  6103      
#define RC_NAVBOARD_SATELLITECOUNTDATA_DATA_COUNT                               1         
#define RC_NAVBOARD_SATELLITECOUNTDATA_DATA_TYPE                                uint8_t   

////////////////////Error
//
#define RC_NAVBOARD_GPSLOCKERROR_DATA_ID                                        6200      
#define RC_NAVBOARD_GPSLOCKERROR_DATA_COUNT                                     0         
#define RC_NAVBOARD_GPSLOCKERROR_DATA_TYPE                                      uint8_t   



///////////////////////////////////////////////////
////////////        SIGNALSTACKBOARD    ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[Speed] (-1000 - 1000) -> (-100% - 100%)
#define RC_SIGNALSTACKBOARD_OPENLOOP_DATA_ID                                    7000      
#define RC_SIGNALSTACKBOARD_OPENLOOP_DATA_COUNT                                 1         
#define RC_SIGNALSTACKBOARD_OPENLOOP_DATA_TYPE                                  int16_t   

//[Heading] (0 - 360)
#define RC_SIGNALSTACKBOARD_SETANGLETARGET_DATA_ID                              7001      
#define RC_SIGNALSTACKBOARD_SETANGLETARGET_DATA_COUNT                           1         
#define RC_SIGNALSTACKBOARD_SETANGLETARGET_DATA_TYPE                            float     

//[Rover Lat, Rover Lon, Basestation Lat, Basestation Lon] (-90 - 90, -180 - 180, -90 - 90, -180 - 180)
#define RC_SIGNALSTACKBOARD_SETGPSTARGET_DATA_ID                                7002      
#define RC_SIGNALSTACKBOARD_SETGPSTARGET_DATA_COUNT                             4         
#define RC_SIGNALSTACKBOARD_SETGPSTARGET_DATA_TYPE                              double    

//[Enabled]
#define RC_SIGNALSTACKBOARD_WATCHDOGOVERRIDE_DATA_ID                            7003      
#define RC_SIGNALSTACKBOARD_WATCHDOGOVERRIDE_DATA_COUNT                         1         
#define RC_SIGNALSTACKBOARD_WATCHDOGOVERRIDE_DATA_TYPE                          uint8_t   

////////////////////Telemetry
//[Heading] (0 - 360)
#define RC_SIGNALSTACKBOARD_COMPASSANGLE_DATA_ID                                7100      
#define RC_SIGNALSTACKBOARD_COMPASSANGLE_DATA_COUNT                             1         
#define RC_SIGNALSTACKBOARD_COMPASSANGLE_DATA_TYPE                              float     



///////////////////////////////////////////////////
////////////        ARMBOARD            ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[X, J2, J3, J4, J5, J6] (-32768 - 32767) -> (-100% - 100%)
#define RC_ARMBOARD_OPENLOOP_DATA_ID                                            8000      
#define RC_ARMBOARD_OPENLOOP_DATA_COUNT                                         6         
#define RC_ARMBOARD_OPENLOOP_DATA_TYPE                                          int16_t   

//[X, J2, J3, J4, J5, J6] (in, deg, deg, deg, deg, deg)
#define RC_ARMBOARD_TARGETANGLE_DATA_ID                                         8001      
#define RC_ARMBOARD_TARGETANGLE_DATA_COUNT                                      6         
#define RC_ARMBOARD_TARGETANGLE_DATA_TYPE                                       float     

//[X, J2, J3, J4, J5, J6] (in, deg, deg, deg, deg, deg)
#define RC_ARMBOARD_TARGETANGLEINCREMENT_DATA_ID                                8002      
#define RC_ARMBOARD_TARGETANGLEINCREMENT_DATA_COUNT                             6         
#define RC_ARMBOARD_TARGETANGLEINCREMENT_DATA_TYPE                              float     

//[Gripper] (-32768 - 32767) -> (-100% - 100%)
#define RC_ARMBOARD_GRIPPEROPENLOOP_DATA_ID                                     8003      
#define RC_ARMBOARD_GRIPPEROPENLOOP_DATA_COUNT                                  1         
#define RC_ARMBOARD_GRIPPEROPENLOOP_DATA_TYPE                                   int16_t   

//[X, Y, Z, J4, J5, J6] (in, in, in, deg, deg, deg)
#define RC_ARMBOARD_IKPOSITION_DATA_ID                                          8004      
#define RC_ARMBOARD_IKPOSITION_DATA_COUNT                                       6         
#define RC_ARMBOARD_IKPOSITION_DATA_TYPE                                        float     

//[X, Y, Z, J4, J5, J6] (in, in, in, deg, deg, deg)
#define RC_ARMBOARD_IKWRISTINCREMENT_DATA_ID                                    8005      
#define RC_ARMBOARD_IKWRISTINCREMENT_DATA_COUNT                                 6         
#define RC_ARMBOARD_IKWRISTINCREMENT_DATA_TYPE                                  float     

//[TX, TY, TZ, RX, RY, RZ] (in, in, in, deg, deg, deg)
#define RC_ARMBOARD_IKWORLDINCREMENT_DATA_ID                                    8006      
#define RC_ARMBOARD_IKWORLDINCREMENT_DATA_COUNT                                 6         
#define RC_ARMBOARD_IKWORLDINCREMENT_DATA_TYPE                                  float     

//[Enabled]
#define RC_ARMBOARD_LASER_DATA_ID                                               8007      
#define RC_ARMBOARD_LASER_DATA_COUNT                                            1         
#define RC_ARMBOARD_LASER_DATA_TYPE                                             uint8_t   

//[Position] (0 - 180)
#define RC_ARMBOARD_LINEARSERVO_DATA_ID                                         8008      
#define RC_ARMBOARD_LINEARSERVO_DATA_COUNT                                      1         
#define RC_ARMBOARD_LINEARSERVO_DATA_TYPE                                       uint8_t   

//[Position] (0 - 180)
#define RC_ARMBOARD_CACHE_DATA_ID                                               8009      
#define RC_ARMBOARD_CACHE_DATA_COUNT                                            1         
#define RC_ARMBOARD_CACHE_DATA_TYPE                                             uint8_t   

//[Enabled]
#define RC_ARMBOARD_WATCHDOGOVERRIDE_DATA_ID                                    8010      
#define RC_ARMBOARD_WATCHDOGOVERRIDE_DATA_COUNT                                 1         
#define RC_ARMBOARD_WATCHDOGOVERRIDE_DATA_TYPE                                  uint8_t   

//[X+, X-, J2+, J2-, J3+, J3-, J4+, J4-, J5+, J5-] (bitmask override enabled)
#define RC_ARMBOARD_LIMITSWITCHOVERRIDE_DATA_ID                                 8011      
#define RC_ARMBOARD_LIMITSWITCHOVERRIDE_DATA_COUNT                              1         
#define RC_ARMBOARD_LIMITSWITCHOVERRIDE_DATA_TYPE                               uint16_t  

//[X, J2, J3, J4, J5, J6] (bitmask override enabled)
#define RC_ARMBOARD_CLOSEDLOOPOVERRIDE_DATA_ID                                  8012      
#define RC_ARMBOARD_CLOSEDLOOPOVERRIDE_DATA_COUNT                               1         
#define RC_ARMBOARD_CLOSEDLOOPOVERRIDE_DATA_TYPE                                uint8_t   

//[X, Roll] (bitmask start calibration)
#define RC_ARMBOARD_CALIBRATEENCODER_DATA_ID                                    8013      
#define RC_ARMBOARD_CALIBRATEENCODER_DATA_COUNT                                 1         
#define RC_ARMBOARD_CALIBRATEENCODER_DATA_TYPE                                  uint8_t   

//[X+, X-, J2+, J2-, J3+, J3-, J4+, J4-, J5+, J5-] (bitmask override enabled)
#define RC_ARMBOARD_SOFTLIMITOVERRIDE_DATA_ID                                   8014      
#define RC_ARMBOARD_SOFTLIMITOVERRIDE_DATA_COUNT                                1         
#define RC_ARMBOARD_SOFTLIMITOVERRIDE_DATA_TYPE                                 uint16_t  

//[Pan, Tilt] (0 - 180)
#define RC_ARMBOARD_ARMGIMBAL1_DATA_ID                                          8015      
#define RC_ARMBOARD_ARMGIMBAL1_DATA_COUNT                                       2         
#define RC_ARMBOARD_ARMGIMBAL1_DATA_TYPE                                        int16_t   

//[Pan, Tilt] (0 - 180)
#define RC_ARMBOARD_ARMGIMBAL2_DATA_ID                                          8016      
#define RC_ARMBOARD_ARMGIMBAL2_DATA_COUNT                                       2         
#define RC_ARMBOARD_ARMGIMBAL2_DATA_TYPE                                        int16_t   

//[TX, TY, TZ, RX, RY, RZ] (in, in, in, deg, deg, deg)
#define RC_ARMBOARD_IKTOOLINCREMENT_DATA_ID                                     8017      
#define RC_ARMBOARD_IKTOOLINCREMENT_DATA_COUNT                                  6         
#define RC_ARMBOARD_IKTOOLINCREMENT_DATA_TYPE                                   float     

////////////////////Telemetry
//[X, J2, J3, J4, J5, J6, GX, GY, GZ] (in, deg, deg, deg, deg, deg, in, in, in)
#define RC_ARMBOARD_POSITION_DATA_ID                                            8100      
#define RC_ARMBOARD_POSITION_DATA_COUNT                                         9         
#define RC_ARMBOARD_POSITION_DATA_TYPE                                          float     

//[X+, X-, J2+, J2-, J3+, J3-, J4+, J4-, J5+, J5-] (bitmask depressed)
#define RC_ARMBOARD_LIMITSWITCH_DATA_ID                                         8101      
#define RC_ARMBOARD_LIMITSWITCH_DATA_COUNT                                      1         
#define RC_ARMBOARD_LIMITSWITCH_DATA_TYPE                                       uint16_t  

//[X+, X-, J2+, J2-, J3+, J3-, J4+, J4-, J5+, J5-] (bitmask triggered)
#define RC_ARMBOARD_SOFTLIMIT_DATA_ID                                           8102      
#define RC_ARMBOARD_SOFTLIMIT_DATA_COUNT                                        1         
#define RC_ARMBOARD_SOFTLIMIT_DATA_TYPE                                         uint16_t  

//[X, J2, J3, J4, J5, J6, G] (ping time ms)
#define RC_ARMBOARD_SMOCOPING_DATA_ID                                           8103      
#define RC_ARMBOARD_SMOCOPING_DATA_COUNT                                        7         
#define RC_ARMBOARD_SMOCOPING_DATA_TYPE                                         uint16_t  

//[X, J2, J3, J4, J5, J6] (in, deg, deg, deg, deg, deg)
#define RC_ARMBOARD_TARGET_DATA_ID                                              8104      
#define RC_ARMBOARD_TARGET_DATA_COUNT                                           6         
#define RC_ARMBOARD_TARGET_DATA_TYPE                                            float     



///////////////////////////////////////////////////
////////////        AUGERBOARD          ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[Speed] (-32768 - 32767) -> (-100% - 100%)
#define RC_AUGERBOARD_AUGERAXIS_DATA_ID                                         9000      
#define RC_AUGERBOARD_AUGERAXIS_DATA_COUNT                                      1         
#define RC_AUGERBOARD_AUGERAXIS_DATA_TYPE                                       int16_t   

//[AugerAxis+, AugerAxis-] (bitmask override enabled)
#define RC_AUGERBOARD_LIMITSWITCHOVERRIDE_DATA_ID                               9001      
#define RC_AUGERBOARD_LIMITSWITCHOVERRIDE_DATA_COUNT                            1         
#define RC_AUGERBOARD_LIMITSWITCHOVERRIDE_DATA_TYPE                             uint8_t   

//Request calibration of the AugerAxis encoder
#define RC_AUGERBOARD_CALIBRATEENCODER_DATA_ID                                  9002      
#define RC_AUGERBOARD_CALIBRATEENCODER_DATA_COUNT                               0         
#define RC_AUGERBOARD_CALIBRATEENCODER_DATA_TYPE                                uint8_t   

//[Speed] (-1000 - 1000) -> (-100% - 100%)
#define RC_AUGERBOARD_AUGER_DATA_ID                                             9003      
#define RC_AUGERBOARD_AUGER_DATA_COUNT                                          1         
#define RC_AUGERBOARD_AUGER_DATA_TYPE                                           int16_t   

//[Enabled]
#define RC_AUGERBOARD_WATCHDOGOVERRIDE_DATA_ID                                  9004      
#define RC_AUGERBOARD_WATCHDOGOVERRIDE_DATA_COUNT                               1         
#define RC_AUGERBOARD_WATCHDOGOVERRIDE_DATA_TYPE                                uint8_t   

//[White, 365, 405, 500] (brightness 0 - 255)
#define RC_AUGERBOARD_LED_DATA_ID                                               9005      
#define RC_AUGERBOARD_LED_DATA_COUNT                                            4         
#define RC_AUGERBOARD_LED_DATA_TYPE                                             uint8_t   

//[AFFilters, SoilTrapdoor] (0 - 180)
#define RC_AUGERBOARD_AUGERSERVO_DATA_ID                                        9006      
#define RC_AUGERBOARD_AUGERSERVO_DATA_COUNT                                     2         
#define RC_AUGERBOARD_AUGERSERVO_DATA_TYPE                                      int16_t   

//[Pan, Tilt] (0 - 180)
#define RC_AUGERBOARD_AUGERGIMBAL_DATA_ID                                       9007      
#define RC_AUGERBOARD_AUGERGIMBAL_DATA_COUNT                                    2         
#define RC_AUGERBOARD_AUGERGIMBAL_DATA_TYPE                                     int16_t   

////////////////////Telemetry
//[AugerAxis] (in)
#define RC_AUGERBOARD_POSITION_DATA_ID                                          9100      
#define RC_AUGERBOARD_POSITION_DATA_COUNT                                       1         
#define RC_AUGERBOARD_POSITION_DATA_TYPE                                        float     

//[AugerSpeed] (rpm)
#define RC_AUGERBOARD_AUGERSPEED_DATA_ID                                        9101      
#define RC_AUGERBOARD_AUGERSPEED_DATA_COUNT                                     1         
#define RC_AUGERBOARD_AUGERSPEED_DATA_TYPE                                      float     

//[AugerAxis+, AugerAxis-] (bitmask depressed)
#define RC_AUGERBOARD_LIMITSWITCH_DATA_ID                                       9102      
#define RC_AUGERBOARD_LIMITSWITCH_DATA_COUNT                                    1         
#define RC_AUGERBOARD_LIMITSWITCH_DATA_TYPE                                     uint8_t   

//[Temperature, Humidity] (C, relative %)
#define RC_AUGERBOARD_ENVIRONMENTAL_DATA_ID                                     9103      
#define RC_AUGERBOARD_ENVIRONMENTAL_DATA_COUNT                                  2         
#define RC_AUGERBOARD_ENVIRONMENTAL_DATA_TYPE                                   float     

//[AugerCurrent] (A)
#define RC_AUGERBOARD_AUGERCURRENT_DATA_ID                                      9104      
#define RC_AUGERBOARD_AUGERCURRENT_DATA_COUNT                                   1         
#define RC_AUGERBOARD_AUGERCURRENT_DATA_TYPE                                    float     

//[AugerAxis] (ping time ms)
#define RC_AUGERBOARD_SMOCOPING_DATA_ID                                         9105      
#define RC_AUGERBOARD_SMOCOPING_DATA_COUNT                                      1         
#define RC_AUGERBOARD_SMOCOPING_DATA_TYPE                                       uint16_t  

//[LEDTimer] (ms)
#define RC_AUGERBOARD_LEDSTATUS_DATA_ID                                         9106      
#define RC_AUGERBOARD_LEDSTATUS_DATA_COUNT                                      1         
#define RC_AUGERBOARD_LEDSTATUS_DATA_TYPE                                       int32_t   



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

//[Lat, Lon, AUTONOMYWAYPOINTTYPES]
#define RC_AUTONOMYBOARD_ADDPOSITIONLEG_DATA_ID                                 11002     
#define RC_AUTONOMYBOARD_ADDPOSITIONLEG_DATA_COUNT                              3         
#define RC_AUTONOMYBOARD_ADDPOSITIONLEG_DATA_TYPE                               double    

//[Lat, Lon, AUTONOMYWAYPOINTTYPES, MarkerRadius (meters)]
#define RC_AUTONOMYBOARD_ADDMARKERLEG_DATA_ID                                   11003     
#define RC_AUTONOMYBOARD_ADDMARKERLEG_DATA_COUNT                                4         
#define RC_AUTONOMYBOARD_ADDMARKERLEG_DATA_TYPE                                 double    

//[Lat, Lon, AUTONOMYWAYPOINTTYPES, ObjectRadius (meters)]
#define RC_AUTONOMYBOARD_ADDOBJECTLEG_DATA_ID                                   11004     
#define RC_AUTONOMYBOARD_ADDOBJECTLEG_DATA_COUNT                                4         
#define RC_AUTONOMYBOARD_ADDOBJECTLEG_DATA_TYPE                                 double    

//Clear queued positions, markers, and objects waypoints.
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATA_ID                                 11005     
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATA_COUNT                              1         
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATA_TYPE                               uint8_t   

//A multiplier from 0.0 to 1.0 that will scale the max power effort of Autonomy.
#define RC_AUTONOMYBOARD_SETMAXSPEED_DATA_ID                                    11006     
#define RC_AUTONOMYBOARD_SETMAXSPEED_DATA_COUNT                                 1         
#define RC_AUTONOMYBOARD_SETMAXSPEED_DATA_TYPE                                  float     

//A multiplier from 0.0 to 1.0 that will filter points from the traversability map. Higher values will result in more conservative pathing.
#define RC_AUTONOMYBOARD_SETMINTRAVSCORE_DATA_ID                                11007     
#define RC_AUTONOMYBOARD_SETMINTRAVSCORE_DATA_COUNT                             1         
#define RC_AUTONOMYBOARD_SETMINTRAVSCORE_DATA_TYPE                              float     

//A multiplier from 0.0 to 1.0 that will bias the pathing algorithm towards shorter paths (lower values) or safer paths (higher values).
#define RC_AUTONOMYBOARD_SETBETABIAS_DATA_ID                                    11008     
#define RC_AUTONOMYBOARD_SETBETABIAS_DATA_COUNT                                 1         
#define RC_AUTONOMYBOARD_SETBETABIAS_DATA_TYPE                                  float     

//[Enum (AUTONOMYLOG), Enum (AUTONOMYLOG), Enum (AUTONOMYLOG)] {Console, File, RoveComm}
#define RC_AUTONOMYBOARD_SETLOGGINGLEVELS_DATA_ID                               11009     
#define RC_AUTONOMYBOARD_SETLOGGINGLEVELS_DATA_COUNT                            3         
#define RC_AUTONOMYBOARD_SETLOGGINGLEVELS_DATA_TYPE                             uint8_t   

//[Lat, Lon, ObstacleRadius (meters)]
#define RC_AUTONOMYBOARD_ADDOBSTACLE_DATA_ID                                    11010     
#define RC_AUTONOMYBOARD_ADDOBSTACLE_DATA_COUNT                                 3         
#define RC_AUTONOMYBOARD_ADDOBSTACLE_DATA_TYPE                                  double    

//Clear queued permanent obstacles.
#define RC_AUTONOMYBOARD_CLEAROBSTACLES_DATA_ID                                 11011     
#define RC_AUTONOMYBOARD_CLEAROBSTACLES_DATA_COUNT                              1         
#define RC_AUTONOMYBOARD_CLEAROBSTACLES_DATA_TYPE                               uint8_t   

////////////////////Telemetry
//[State] (AUTONOMYSTATE)
#define RC_AUTONOMYBOARD_CURRENTSTATE_DATA_ID                                   11100     
#define RC_AUTONOMYBOARD_CURRENTSTATE_DATA_COUNT                                1         
#define RC_AUTONOMYBOARD_CURRENTSTATE_DATA_TYPE                                 uint8_t   

//[State] (0: Teleop 1: Autonomy 2: Reached Goal)
#define RC_AUTONOMYBOARD_STATEDISPLAY_DATA_ID                                   11101     
#define RC_AUTONOMYBOARD_STATEDISPLAY_DATA_COUNT                                1         
#define RC_AUTONOMYBOARD_STATEDISPLAY_DATA_TYPE                                 uint8_t   

//[Thread, FPS] (AUTONOMYTHREADS, fps)
#define RC_AUTONOMYBOARD_THREADFPS_DATA_ID                                      11103     
#define RC_AUTONOMYBOARD_THREADFPS_DATA_COUNT                                   2         
#define RC_AUTONOMYBOARD_THREADFPS_DATA_TYPE                                    uint32_t  

//[Lat, Lon, Lat, Lon, ...] (deg, deg, deg, deg, ...)
#define RC_AUTONOMYBOARD_PATHWAYPOINTS_DATA_ID                                  11104     
#define RC_AUTONOMYBOARD_PATHWAYPOINTS_DATA_COUNT                               1000      
#define RC_AUTONOMYBOARD_PATHWAYPOINTS_DATA_TYPE                                double    

//[EstimatedTimeToGoal] (s)
#define RC_AUTONOMYBOARD_TIMEREMAINING_DATA_ID                                  11105     
#define RC_AUTONOMYBOARD_TIMEREMAINING_DATA_COUNT                               1         
#define RC_AUTONOMYBOARD_TIMEREMAINING_DATA_TYPE                                double    

////////////////////Enums
enum AUTONOMYBOARD_AUTONOMYSTATE {IDLE,NAVIGATING,SEARCHPATTERN,APPROACHINGMARKER,APPROACHINGOBJECT,VERIFYINGGPS,VERIFYINGMARKER,VERIFYINGOBJECT,REVERSING,STUCK}; 
enum AUTONOMYBOARD_AUTONOMYLOG {TRACEL3,TRACEL2,TRACEL1,DEBUG,INFO,NOTICE,WARNING,ERROR,CRITICAL}; 
enum AUTONOMYBOARD_AUTONOMYTHREADS {NOTSET,MAINPROCESS,MAINCAM,REARCAM,TAGDETECTOR,OBJECTDETECTOR,STATEMACHINE,ROVECOMMUDP,ROVECOMMTCP}; 
enum AUTONOMYBOARD_AUTONOMYWAYPOINTTYPES {CONTINUOUSNAVIGATE,ROCKPICK,WATERBOTTLE,MALLET,ANY,TAG0,TAG1,TAG2,TAG3}; 


///////////////////////////////////////////////////
////////////        CAMERA1BOARD        ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[Camera, Restart]
#define RC_CAMERA1BOARD_TAKEPICTURE_DATA_ID                                     12000     
#define RC_CAMERA1BOARD_TAKEPICTURE_DATA_COUNT                                  2         
#define RC_CAMERA1BOARD_TAKEPICTURE_DATA_TYPE                                   uint8_t   

//[Camera, Restart]
#define RC_CAMERA1BOARD_TOGGLESTREAM_DATA_ID                                    12001     
#define RC_CAMERA1BOARD_TOGGLESTREAM_DATA_COUNT                                 2         
#define RC_CAMERA1BOARD_TOGGLESTREAM_DATA_TYPE                                  uint8_t   

//[Arguments] (0x1f delimited, 0x04 terminated list with maximum length of 16383 characters for RPi-Camera/config.toml/ffmpeg_arguments, byte after 0x04 is camera index. See RPI-Camera/config.toml for substitutions)
#define RC_CAMERA1BOARD_SETFFMPEGARGUMENTS_DATA_ID                              12002     
#define RC_CAMERA1BOARD_SETFFMPEGARGUMENTS_DATA_COUNT                           16384     
#define RC_CAMERA1BOARD_SETFFMPEGARGUMENTS_DATA_TYPE                            char      

//[Arguments] (0x1f delimited, 0x04 terminated list with maximum length of 16383 characters for RPi-Camera/config.toml/picture_arguments, byte after 0x04 is camera index. See RPI-Camera/config.toml for substitutions)
#define RC_CAMERA1BOARD_SETPICTUREARGUMENTS_DATA_ID                             12003     
#define RC_CAMERA1BOARD_SETPICTUREARGUMENTS_DATA_COUNT                          16384     
#define RC_CAMERA1BOARD_SETPICTUREARGUMENTS_DATA_TYPE                           char      

////////////////////Telemetry
//[Connected, Streaming] (bitmask indexes, bitmask indexes)
#define RC_CAMERA1BOARD_AVAILABLECAMERAS_DATA_ID                                12100     
#define RC_CAMERA1BOARD_AVAILABLECAMERAS_DATA_COUNT                             2         
#define RC_CAMERA1BOARD_AVAILABLECAMERAS_DATA_TYPE                              uint8_t   

//Picture has been taken.
#define RC_CAMERA1BOARD_PICTURETAKEN_DATA_ID                                    12101     
#define RC_CAMERA1BOARD_PICTURETAKEN_DATA_COUNT                                 0         
#define RC_CAMERA1BOARD_PICTURETAKEN_DATA_TYPE                                  uint8_t   

//[cpu0, cpu1, cpu2, cpu3, mem, storage] (% usage)
#define RC_CAMERA1BOARD_UTILIZATION_DATA_ID                                     12102     
#define RC_CAMERA1BOARD_UTILIZATION_DATA_COUNT                                  6         
#define RC_CAMERA1BOARD_UTILIZATION_DATA_TYPE                                   uint8_t   



///////////////////////////////////////////////////
////////////        CAMERA2BOARD        ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[Camera, Restart]
#define RC_CAMERA2BOARD_TAKEPICTURE_DATA_ID                                     13000     
#define RC_CAMERA2BOARD_TAKEPICTURE_DATA_COUNT                                  2         
#define RC_CAMERA2BOARD_TAKEPICTURE_DATA_TYPE                                   uint8_t   

//[Camera, Restart]
#define RC_CAMERA2BOARD_TOGGLESTREAM_DATA_ID                                    13001     
#define RC_CAMERA2BOARD_TOGGLESTREAM_DATA_COUNT                                 2         
#define RC_CAMERA2BOARD_TOGGLESTREAM_DATA_TYPE                                  uint8_t   

//[Arguments] (0x1f delimited, 0x04 terminated list with maximum length of 16383 characters for RPi-Camera/config.toml/ffmpeg_arguments, byte after 0x04 is camera index. See RPI-Camera/config.toml for substitutions)
#define RC_CAMERA2BOARD_SETFFMPEGARGUMENTS_DATA_ID                              13002     
#define RC_CAMERA2BOARD_SETFFMPEGARGUMENTS_DATA_COUNT                           16384     
#define RC_CAMERA2BOARD_SETFFMPEGARGUMENTS_DATA_TYPE                            char      

//[Arguments] (0x1f delimited, 0x04 terminated list with maximum length of 16383 characters for RPi-Camera/config.toml/picture_arguments, byte after 0x04 is camera index. See RPI-Camera/config.toml for substitutions)
#define RC_CAMERA2BOARD_SETPICTUREARGUMENTS_DATA_ID                             13003     
#define RC_CAMERA2BOARD_SETPICTUREARGUMENTS_DATA_COUNT                          16384     
#define RC_CAMERA2BOARD_SETPICTUREARGUMENTS_DATA_TYPE                           char      

////////////////////Telemetry
//[Connected, Streaming] (bitmask indexes, bitmask indexes)
#define RC_CAMERA2BOARD_AVAILABLECAMERAS_DATA_ID                                13100     
#define RC_CAMERA2BOARD_AVAILABLECAMERAS_DATA_COUNT                             2         
#define RC_CAMERA2BOARD_AVAILABLECAMERAS_DATA_TYPE                              uint8_t   

//Picture has been taken.
#define RC_CAMERA2BOARD_PICTURETAKEN_DATA_ID                                    13101     
#define RC_CAMERA2BOARD_PICTURETAKEN_DATA_COUNT                                 0         
#define RC_CAMERA2BOARD_PICTURETAKEN_DATA_TYPE                                  uint8_t   

//[cpu0, cpu1, cpu2, cpu3, mem, storage] (% usage)
#define RC_CAMERA2BOARD_UTILIZATION_DATA_ID                                     13102     
#define RC_CAMERA2BOARD_UTILIZATION_DATA_COUNT                                  6         
#define RC_CAMERA2BOARD_UTILIZATION_DATA_TYPE                                   uint8_t   



///////////////////////////////////////////////////
////////////        CAMERASERVERBOARD   ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[Camera]
#define RC_CAMERASERVERBOARD_TAKEPHOTO_DATA_ID                                  14000     
#define RC_CAMERASERVERBOARD_TAKEPHOTO_DATA_COUNT                               1         
#define RC_CAMERASERVERBOARD_TAKEPHOTO_DATA_TYPE                                uint8_t   

//[Camera, Action] (id, 0: Shutdown 1: Startup 2: Restart)
#define RC_CAMERASERVERBOARD_TOGGLESTREAM_DATA_ID                               14001     
#define RC_CAMERASERVERBOARD_TOGGLESTREAM_DATA_COUNT                            2         
#define RC_CAMERASERVERBOARD_TOGGLESTREAM_DATA_TYPE                             uint8_t   

//[Camera, Brightness] (id, 0 - 255)
#define RC_CAMERASERVERBOARD_ADJUSTBRIGHTNESS_DATA_ID                           14002     
#define RC_CAMERASERVERBOARD_ADJUSTBRIGHTNESS_DATA_COUNT                        2         
#define RC_CAMERASERVERBOARD_ADJUSTBRIGHTNESS_DATA_TYPE                         uint8_t   

//[Camera, Contrast] (id, 0 - 255)
#define RC_CAMERASERVERBOARD_ADJUSTCONTRAST_DATA_ID                             14003     
#define RC_CAMERASERVERBOARD_ADJUSTCONTRAST_DATA_COUNT                          2         
#define RC_CAMERASERVERBOARD_ADJUSTCONTRAST_DATA_TYPE                           uint8_t   

//[Camera, Saturation] (id, 0 - 255)
#define RC_CAMERASERVERBOARD_ADJUSTSATURATION_DATA_ID                           14004     
#define RC_CAMERASERVERBOARD_ADJUSTSATURATION_DATA_COUNT                        2         
#define RC_CAMERASERVERBOARD_ADJUSTSATURATION_DATA_TYPE                         uint8_t   

//[Camera, Hue] (id, 0 - 255)
#define RC_CAMERASERVERBOARD_ADJUSTHUE_DATA_ID                                  14005     
#define RC_CAMERASERVERBOARD_ADJUSTHUE_DATA_COUNT                               2         
#define RC_CAMERASERVERBOARD_ADJUSTHUE_DATA_TYPE                                uint8_t   

//[Camera, Temperature]
#define RC_CAMERASERVERBOARD_SETWHITEBALANCE_DATA_ID                            14008     
#define RC_CAMERASERVERBOARD_SETWHITEBALANCE_DATA_COUNT                         2         
#define RC_CAMERASERVERBOARD_SETWHITEBALANCE_DATA_TYPE                          uint8_t   

//[Camera, BacklightContrast]
#define RC_CAMERASERVERBOARD_ADJUSTBACKLIGHTCONTRAST_DATA_ID                    14009     
#define RC_CAMERASERVERBOARD_ADJUSTBACKLIGHTCONTRAST_DATA_COUNT                 2         
#define RC_CAMERASERVERBOARD_ADJUSTBACKLIGHTCONTRAST_DATA_TYPE                  uint8_t   

//[Camera, Exposure]
#define RC_CAMERASERVERBOARD_SETEXPOSURE_DATA_ID                                14010     
#define RC_CAMERASERVERBOARD_SETEXPOSURE_DATA_COUNT                             2         
#define RC_CAMERASERVERBOARD_SETEXPOSURE_DATA_TYPE                              int32_t   

////////////////////Telemetry
//[Camera0, Camera1, Camera2, Camera3, Camera4, Camera5, Camera6, Camera7] (bitmask able to stream)
#define RC_CAMERASERVERBOARD_AVAILABLECAMERAS_DATA_ID                           14100     
#define RC_CAMERASERVERBOARD_AVAILABLECAMERAS_DATA_COUNT                        1         
#define RC_CAMERASERVERBOARD_AVAILABLECAMERAS_DATA_TYPE                         uint8_t   

//[Port0, Port1, Port2, Port3] (currently streaming on each port)
#define RC_CAMERASERVERBOARD_STREAMINGCAMERAS_DATA_ID                           14101     
#define RC_CAMERASERVERBOARD_STREAMINGCAMERAS_DATA_COUNT                        4         
#define RC_CAMERASERVERBOARD_STREAMINGCAMERAS_DATA_TYPE                         uint8_t   

//Picture has been taken
#define RC_CAMERASERVERBOARD_PICTURETAKEN_DATA_ID                               14102     
#define RC_CAMERASERVERBOARD_PICTURETAKEN_DATA_COUNT                            0         
#define RC_CAMERASERVERBOARD_PICTURETAKEN_DATA_TYPE                             uint8_t   

////////////////////Error
//[Camera] (id) Camera has errored and stopped streaming
#define RC_CAMERASERVERBOARD_CAMERAUNAVAILABLE_DATA_ID                          14200     
#define RC_CAMERASERVERBOARD_CAMERAUNAVAILABLE_DATA_COUNT                       1         
#define RC_CAMERASERVERBOARD_CAMERAUNAVAILABLE_DATA_TYPE                        uint8_t   



///////////////////////////////////////////////////
////////////        RAMANBOARD          ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[Speed] (-32768 - 32767) -> (-100% - 100%)
#define RC_RAMANBOARD_INSTRUMENTSAXIS_DATA_ID                                   16000     
#define RC_RAMANBOARD_INSTRUMENTSAXIS_DATA_COUNT                                1         
#define RC_RAMANBOARD_INSTRUMENTSAXIS_DATA_TYPE                                 int16_t   

//[InstrumentsAxis+, InstrumentsAxis-] (bitmask override enabled)
#define RC_RAMANBOARD_LIMITSWITCHOVERRIDE_DATA_ID                               16001     
#define RC_RAMANBOARD_LIMITSWITCHOVERRIDE_DATA_COUNT                            1         
#define RC_RAMANBOARD_LIMITSWITCHOVERRIDE_DATA_TYPE                             uint8_t   

//Request calibration of the InstrumentsAxis encoder
#define RC_RAMANBOARD_CALIBRATEENCODER_DATA_ID                                  16002     
#define RC_RAMANBOARD_CALIBRATEENCODER_DATA_COUNT                               0         
#define RC_RAMANBOARD_CALIBRATEENCODER_DATA_TYPE                                uint8_t   

//[Enabled]
#define RC_RAMANBOARD_WATCHDOGOVERRIDE_DATA_ID                                  16003     
#define RC_RAMANBOARD_WATCHDOGOVERRIDE_DATA_COUNT                               1         
#define RC_RAMANBOARD_WATCHDOGOVERRIDE_DATA_TYPE                                uint8_t   

//[Enabled]
#define RC_RAMANBOARD_LASER_DATA_ID                                             16004     
#define RC_RAMANBOARD_LASER_DATA_COUNT                                          1         
#define RC_RAMANBOARD_LASER_DATA_TYPE                                           uint8_t   

//[Integration Time, Sample Count] (ms, n)
#define RC_RAMANBOARD_REQUESTRAMANREADING_DATA_ID                               16005     
#define RC_RAMANBOARD_REQUESTRAMANREADING_DATA_COUNT                            2         
#define RC_RAMANBOARD_REQUESTRAMANREADING_DATA_TYPE                             uint32_t  

////////////////////Telemetry
//[InstrumentsAxis, TOF] (mm, mm)
#define RC_RAMANBOARD_POSITION_DATA_ID                                          16100     
#define RC_RAMANBOARD_POSITION_DATA_COUNT                                       2         
#define RC_RAMANBOARD_POSITION_DATA_TYPE                                        float     

//[InstrumentsAxis+, InstrumentsAxis-] (bitmask depressed)
#define RC_RAMANBOARD_LIMITSWITCH_DATA_ID                                       16101     
#define RC_RAMANBOARD_LIMITSWITCH_DATA_COUNT                                    1         
#define RC_RAMANBOARD_LIMITSWITCH_DATA_TYPE                                     uint8_t   

//Raman CCD elements 0-511
#define RC_RAMANBOARD_RAMANREADING_PART1_DATA_ID                                16102     
#define RC_RAMANBOARD_RAMANREADING_PART1_DATA_COUNT                             512       
#define RC_RAMANBOARD_RAMANREADING_PART1_DATA_TYPE                              uint16_t  

//Raman CCD elements 512-1023
#define RC_RAMANBOARD_RAMANREADING_PART2_DATA_ID                                16103     
#define RC_RAMANBOARD_RAMANREADING_PART2_DATA_COUNT                             512       
#define RC_RAMANBOARD_RAMANREADING_PART2_DATA_TYPE                              uint16_t  

//Raman CCD elements 1024-1535
#define RC_RAMANBOARD_RAMANREADING_PART3_DATA_ID                                16104     
#define RC_RAMANBOARD_RAMANREADING_PART3_DATA_COUNT                             512       
#define RC_RAMANBOARD_RAMANREADING_PART3_DATA_TYPE                              uint16_t  

//Raman CCD elements 1536-2047
#define RC_RAMANBOARD_RAMANREADING_PART4_DATA_ID                                16105     
#define RC_RAMANBOARD_RAMANREADING_PART4_DATA_COUNT                             512       
#define RC_RAMANBOARD_RAMANREADING_PART4_DATA_TYPE                              uint16_t  

//Raman CCD elements 2048-2559
#define RC_RAMANBOARD_RAMANREADING_PART5_DATA_ID                                16106     
#define RC_RAMANBOARD_RAMANREADING_PART5_DATA_COUNT                             512       
#define RC_RAMANBOARD_RAMANREADING_PART5_DATA_TYPE                              uint16_t  

//[InstrumentsAxis] (ping time ms)
#define RC_RAMANBOARD_SMOCOPING_DATA_ID                                         16107     
#define RC_RAMANBOARD_SMOCOPING_DATA_COUNT                                      1         
#define RC_RAMANBOARD_SMOCOPING_DATA_TYPE                                       uint16_t  



///////////////////////////////////////////////////
////////////        ROVESOSIMULATORBOARD///////////         
///////////////////////////////////////////////////

////////////////////Telemetry
//[Accel X, Accel Y, Accel Z, Gyro X, Gyro Y, Gyro Z, Quat X, Quat Y, Quat Z, Quat W]
#define RC_ROVESOSIMULATORBOARD_IMU_DATA_ID                                     99100     
#define RC_ROVESOSIMULATORBOARD_IMU_DATA_COUNT                                  10        
#define RC_ROVESOSIMULATORBOARD_IMU_DATA_TYPE                                   double    



#endif // ROVECOMM_MANIFEST_H