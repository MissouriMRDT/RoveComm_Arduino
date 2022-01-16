#ifndef TeensyRoveCommManifest_h
#define TeensyRoveCommManifest_h

#include <stdint.h>
#include"TeensyRoveCommPacket.h"

#define RC_DRIVEBOARD_FOURTHOCTET                 134       
#define RC_ROVECOMM_DRIVEBOARD_PORT               11004     

#define RC_BMSBOARD_FOURTHOCTET                   133       
#define RC_ROVECOMM_BMSBOARD_PORT                 11003     

#define RC_POWERBOARD_FOURTHOCTET                 132       
#define RC_ROVECOMM_POWERBOARD_PORT               11002     

#define RC_BLACKBOXBOARD_FOURTHOCTET              146       
#define RC_ROVECOMM_BLACKBOXBOARD_PORT            11015     

#define RC_NAVBOARD_FOURTHOCTET                   136       
#define RC_ROVECOMM_NAVBOARD_PORT                 11006     

#define RC_GIMBALBOARD_FOURTHOCTET                135       
#define RC_ROVECOMM_GIMBALBOARD_PORT              11005     

#define RC_MULTIMEDIABOARD_FOURTHOCTET            140       
#define RC_ROVECOMM_MULTIMEDIABOARD_PORT          11010     

#define RC_ARMBOARD_FOURTHOCTET                   131       
#define RC_ROVECOMM_ARMBOARD_PORT                 11001     

#define RC_SCIENCEACTUATIONBOARD_FOURTHOCTET      137       
#define RC_ROVECOMM_SCIENCEACTUATIONBOARD_PORT    11007     

#define RC_SCIENCESENSORSBOARD_FOURTHOCTET        138       
#define RC_ROVECOMM_SCIENCESENSORSBOARD_PORT      11008     

#define RC_AUTONOMYBOARD_FOURTHOCTET              139       
#define RC_ROVECOMM_AUTONOMYBOARD_PORT            11009     

#define RC_CAMERA1BOARD_FOURTHOCTET               141       
#define RC_ROVECOMM_CAMERA1BOARD_PORT             11011     

#define RC_CAMERA2BOARD_FOURTHOCTET               142       
#define RC_ROVECOMM_CAMERA2BOARD_PORT             11012     

#define RC_PRCONTROLLERBOARD_FOURTHOCTET          143       
#define RC_ROVECOMM_PRCONTROLLERBOARD_PORT        11013     

#define RC_HEATERBOARD_FOURTHOCTET                144       
#define RC_ROVECOMM_HEATERBOARD_PORT              11014     

#define RC_MICROPIBOARD_FOURTHOCTET               142       
#define RC_ROVECOMM_MICROPIBOARD_PORT             11015     



#define ROVECOMM_UPDATE_RATE                      100       
#define RC_ROVECOMM_ETHERNET_UDP_PORT             11000     
#define RC_ROVECOMM_SUBNET_IP_FIRST_OCTET         192       
#define RC_ROVECOMM_SUBNET_IP_SECOND_OCTET        168       
#define RC_ROVECOMM_SUBNET_IP_THIRD_OCTET         1         


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
////////////        DRIVEBOARD          ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[LeftSpeed, RightSpeed] (-1000, 1000)-> (-100%, 100%)
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_DATA_ID                          1000      
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_DATA_COUNT                       2         
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_DATA_TYPE                        int16_t   

//[LF, LR, RF, RR] (-1000, 1000)-> (-100%, 100%)
#define RC_DRIVEBOARD_DRIVEINDIVIDUAL_DATA_ID                         1001      
#define RC_DRIVEBOARD_DRIVEINDIVIDUAL_DATA_COUNT                      4         
#define RC_DRIVEBOARD_DRIVEINDIVIDUAL_DATA_TYPE                       int16_t   

//[0-Turn off Watchdog Override, 1-Turn on Watchdog Override]
#define RC_DRIVEBOARD_WATCHDOGOVERRIDE_DATA_ID                        1002      
#define RC_DRIVEBOARD_WATCHDOGOVERRIDE_DATA_COUNT                     1         
#define RC_DRIVEBOARD_WATCHDOGOVERRIDE_DATA_TYPE                      uint8_t   

////////////////////Telemetry
//[LF, LR, RF, RR] (-1000, 1000)-> (-100%, 100%)
#define RC_DRIVEBOARD_DRIVESPEEDS_DATA_ID                             1100      
#define RC_DRIVEBOARD_DRIVESPEEDS_DATA_COUNT                          4         
#define RC_DRIVEBOARD_DRIVESPEEDS_DATA_TYPE                           int16_t   



///////////////////////////////////////////////////
////////////        BMSBOARD            ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[delay] (s) -> a delay of 0 will shutdown, not restart and cannot be reversed
#define RC_BMSBOARD_BMSSTOP_DATA_ID                                   2000      
#define RC_BMSBOARD_BMSSTOP_DATA_COUNT                                1         
#define RC_BMSBOARD_BMSSTOP_DATA_TYPE                                 uint8_t   

////////////////////Telemetry
//[Main] (A)
#define RC_BMSBOARD_PACKI_MEAS_DATA_ID                                2100      
#define RC_BMSBOARD_PACKI_MEAS_DATA_COUNT                             1         
#define RC_BMSBOARD_PACKI_MEAS_DATA_TYPE                              float     

//[Pack_Out] (V)
#define RC_BMSBOARD_PACKV_MEAS_DATA_ID                                2101      
#define RC_BMSBOARD_PACKV_MEAS_DATA_COUNT                             1         
#define RC_BMSBOARD_PACKV_MEAS_DATA_TYPE                              float     

//[C1-G, C2-1, C3-2, C4-3, C5-4, C6-5, C7-6, C8-7] (V)
#define RC_BMSBOARD_CELLV_MEAS_DATA_ID                                2102      
#define RC_BMSBOARD_CELLV_MEAS_DATA_COUNT                             8         
#define RC_BMSBOARD_CELLV_MEAS_DATA_TYPE                              float     

//[Temp] (degC)
#define RC_BMSBOARD_TEMP_MEAS_DATA_ID                                 2103      
#define RC_BMSBOARD_TEMP_MEAS_DATA_COUNT                              1         
#define RC_BMSBOARD_TEMP_MEAS_DATA_TYPE                               float     

////////////////////Error
//
#define RC_BMSBOARD_PACKOVERCURRENT_DATA_ID                           2200      
#define RC_BMSBOARD_PACKOVERCURRENT_DATA_COUNT                        1         
#define RC_BMSBOARD_PACKOVERCURRENT_DATA_TYPE                         uint8_t   

//(bitmasked)
#define RC_BMSBOARD_CELLUNDERVOLTAGE_DATA_ID                          2201      
#define RC_BMSBOARD_CELLUNDERVOLTAGE_DATA_COUNT                       1         
#define RC_BMSBOARD_CELLUNDERVOLTAGE_DATA_TYPE                        uint8_t   

//
#define RC_BMSBOARD_PACKUNDERVOLTAGE_DATA_ID                          2202      
#define RC_BMSBOARD_PACKUNDERVOLTAGE_DATA_COUNT                       1         
#define RC_BMSBOARD_PACKUNDERVOLTAGE_DATA_TYPE                        uint8_t   

//
#define RC_BMSBOARD_PACKSUPERHOT_DATA_ID                              2203      
#define RC_BMSBOARD_PACKSUPERHOT_DATA_COUNT                           1         
#define RC_BMSBOARD_PACKSUPERHOT_DATA_TYPE                            uint8_t   



///////////////////////////////////////////////////
////////////        POWERBOARD          ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[(0-Disable, 1-Enable)], [M1, M2, M3, M4, M5, M6 Spare (Bitmask)]
#define RC_POWERBOARD_MOTORBUSENABLE_DATA_ID                          3000      
#define RC_POWERBOARD_MOTORBUSENABLE_DATA_COUNT                       1         
#define RC_POWERBOARD_MOTORBUSENABLE_DATA_TYPE                        uint8_t   

//[(0-Disable, 1-Enable)], [Gimbal-Act, Multi-Act, Science-Act (Bitmask)]
#define RC_POWERBOARD_TWELVEVACTBUSENABLE_DATA_ID                     3001      
#define RC_POWERBOARD_TWELVEVACTBUSENABLE_DATA_COUNT                  1         
#define RC_POWERBOARD_TWELVEVACTBUSENABLE_DATA_TYPE                   uint8_t   

//[(0-Disable, 1-Enable)], [Gimbal-Log, Multi-Log, Science-Log, Drive-Log, Nav, Cam1, Cam2 (Bitmask)]
#define RC_POWERBOARD_TWELVEVLOGICBUSENABLE_DATA_ID                   3002      
#define RC_POWERBOARD_TWELVEVLOGICBUSENABLE_DATA_COUNT                1         
#define RC_POWERBOARD_TWELVEVLOGICBUSENABLE_DATA_TYPE                 uint8_t   

//[(0-Disable, 1-Enable)], [TwelveV, POE, Aux, Extra, Heater (Bitmask)]
#define RC_POWERBOARD_THIRTYVBUSENABLE_DATA_ID                        3003      
#define RC_POWERBOARD_THIRTYVBUSENABLE_DATA_COUNT                     1         
#define RC_POWERBOARD_THIRTYVBUSENABLE_DATA_TYPE                      uint8_t   

////////////////////Telemetry
//[(0-Disabled, 1-Enabled)], [M1, M2, M3, M4, M5, M6 Spare (Bitmask)]
#define RC_POWERBOARD_MOTORBUSENABLED_DATA_ID                         3100      
#define RC_POWERBOARD_MOTORBUSENABLED_DATA_COUNT                      1         
#define RC_POWERBOARD_MOTORBUSENABLED_DATA_TYPE                       uint8_t   

//[(0-Disabled, 1-Enabled)], [Gimbal-Act, Multi-Act, Science-Act (Bitmask)]
#define RC_POWERBOARD_TWELVEVACTBUSENABLED_DATA_ID                    3101      
#define RC_POWERBOARD_TWELVEVACTBUSENABLED_DATA_COUNT                 1         
#define RC_POWERBOARD_TWELVEVACTBUSENABLED_DATA_TYPE                  uint8_t   

//[(0-Disabled, 1-Enabled)], [Gimbal-Log, Multi-Log, Science-Log, Drive-Log, Nav, Cam1, Cam2 (Bitmask)]
#define RC_POWERBOARD_TWELVEVLOGICBUSENABLED_DATA_ID                  3102      
#define RC_POWERBOARD_TWELVEVLOGICBUSENABLED_DATA_COUNT               1         
#define RC_POWERBOARD_TWELVEVLOGICBUSENABLED_DATA_TYPE                uint8_t   

//[(0-Disabled, 1-Enabled)], [TwelveV, POE, Aux, Extra, Heater (Bitmask)]
#define RC_POWERBOARD_THIRTYVENABLED_DATA_ID                          3103      
#define RC_POWERBOARD_THIRTYVENABLED_DATA_COUNT                       1         
#define RC_POWERBOARD_THIRTYVENABLED_DATA_TYPE                        uint8_t   

//[M1, M2, M3, M4, M5, M6, Spare] (A)
#define RC_POWERBOARD_MOTORBUSCURRENT_DATA_ID                         3104      
#define RC_POWERBOARD_MOTORBUSCURRENT_DATA_COUNT                      7         
#define RC_POWERBOARD_MOTORBUSCURRENT_DATA_TYPE                       float     

//[Gimbal-Act, Multi-Act, Science-Act, Logic] (A)
#define RC_POWERBOARD_TWELVEVACTBUSCURRENT_DATA_ID                    3105      
#define RC_POWERBOARD_TWELVEVACTBUSCURRENT_DATA_COUNT                 4         
#define RC_POWERBOARD_TWELVEVACTBUSCURRENT_DATA_TYPE                  float     

//[Gimbal-Log, Mulit-Log, Science-Log, Drive-Log, Nav, Cam1, Cam2] (A)
#define RC_POWERBOARD_TWELVEVLOGICBUSCURRENT_DATA_ID                  3106      
#define RC_POWERBOARD_TWELVEVLOGICBUSCURRENT_DATA_COUNT               7         
#define RC_POWERBOARD_TWELVEVLOGICBUSCURRENT_DATA_TYPE                float     

//[TwelveV, POE, Aux, Extra, Heater] (A)
#define RC_POWERBOARD_THIRTYVBUSCURRENT_DATA_ID                       3107      
#define RC_POWERBOARD_THIRTYVBUSCURRENT_DATA_COUNT                    5         
#define RC_POWERBOARD_THIRTYVBUSCURRENT_DATA_TYPE                     float     

////////////////////Error
//[(0-undermaxcurrent, 1-overcurrent)] [M1, M2, M3, M4, M5, M6, Spare (Bitmask)]
#define RC_POWERBOARD_MOTORBUSOVERCURRENT_DATA_ID                     3200      
#define RC_POWERBOARD_MOTORBUSOVERCURRENT_DATA_COUNT                  1         
#define RC_POWERBOARD_MOTORBUSOVERCURRENT_DATA_TYPE                   uint8_t   

//[(0-undermaxcurrent, 1-overcurrent)] [Gimbal-Act, Multi-Act, Science-Act (Bitmask)]
#define RC_POWERBOARD_TWELVEVACTBUSOVERCURRENT_DATA_ID                3201      
#define RC_POWERBOARD_TWELVEVACTBUSOVERCURRENT_DATA_COUNT             1         
#define RC_POWERBOARD_TWELVEVACTBUSOVERCURRENT_DATA_TYPE              uint8_t   

//[(0-undermaxcurrent, 1-overcurrent)] [TwelveV Board, POE, Aux, Extra, Heater (Bitmask)]
#define RC_POWERBOARD_THIRTYVBUSOVERCURRENT_DATA_ID                   3202      
#define RC_POWERBOARD_THIRTYVBUSOVERCURRENT_DATA_COUNT                1         
#define RC_POWERBOARD_THIRTYVBUSOVERCURRENT_DATA_TYPE                 uint8_t   

//[(0-undermaxcurrent, 1-overcurrent)] [Gimbal-Log, Multi-Log, Science-Log, Drive-Log, Nav, Cam1, Cam2 (Bitmask)]
#define RC_POWERBOARD_TWELVEVLOGICBUSOVERCURRENT_DATA_ID              3203      
#define RC_POWERBOARD_TWELVEVLOGICBUSOVERCURRENT_DATA_COUNT           1         
#define RC_POWERBOARD_TWELVEVLOGICBUSOVERCURRENT_DATA_TYPE            uint8_t   



///////////////////////////////////////////////////
////////////        BLACKBOXBOARD       ///////////         
///////////////////////////////////////////////////

////////////////////Commands
////////////////////Telemetry
//[(0-Disable, 1-Enable)]
#define RC_BLACKBOXBOARD_BLACKBOXLISTENING_DATA_ID                    4100      
#define RC_BLACKBOXBOARD_BLACKBOXLISTENING_DATA_COUNT                 1         
#define RC_BLACKBOXBOARD_BLACKBOXLISTENING_DATA_TYPE                  uint8_t   



///////////////////////////////////////////////////
////////////        NAVBOARD            ///////////         
///////////////////////////////////////////////////

////////////////////Commands
////////////////////Telemetry
//[Lat, Long] [(-90, 90), (-180, 180)] (deg)
#define RC_NAVBOARD_GPSLATLON_DATA_ID                                 5100      
#define RC_NAVBOARD_GPSLATLON_DATA_COUNT                              2         
#define RC_NAVBOARD_GPSLATLON_DATA_TYPE                               double    

//[Pitch, Yaw, Roll] [(-90, 90), (0, 360), (-90, 90)] (deg)
#define RC_NAVBOARD_IMUDATA_DATA_ID                                   5101      
#define RC_NAVBOARD_IMUDATA_DATA_COUNT                                3         
#define RC_NAVBOARD_IMUDATA_DATA_TYPE                                 float     

//[Distance, Quality]
#define RC_NAVBOARD_LIDARDATA_DATA_ID                                 5102      
#define RC_NAVBOARD_LIDARDATA_DATA_COUNT                              2         
#define RC_NAVBOARD_LIDARDATA_DATA_TYPE                               float     

//[Number of satellites]
#define RC_NAVBOARD_SATELLITECOUNTDATA_DATA_ID                        5103      
#define RC_NAVBOARD_SATELLITECOUNTDATA_DATA_COUNT                     1         
#define RC_NAVBOARD_SATELLITECOUNTDATA_DATA_TYPE                      uint16_t  

////////////////////Error
//
#define RC_NAVBOARD_GPSLOCKERROR_DATA_ID                              5200      
#define RC_NAVBOARD_GPSLOCKERROR_DATA_COUNT                           1         
#define RC_NAVBOARD_GPSLOCKERROR_DATA_TYPE                            uint8_t   



///////////////////////////////////////////////////
////////////        GIMBALBOARD         ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[Pan, Tilt](degrees 0-180)
#define RC_GIMBALBOARD_LEFTDRIVEGIMBALINCREMENT_DATA_ID               6000      
#define RC_GIMBALBOARD_LEFTDRIVEGIMBALINCREMENT_DATA_COUNT            2         
#define RC_GIMBALBOARD_LEFTDRIVEGIMBALINCREMENT_DATA_TYPE             int16_t   

//[Pan, Tilt](degrees 0-180)
#define RC_GIMBALBOARD_RIGHTDRIVEGIMBALINCREMENT_DATA_ID              6001      
#define RC_GIMBALBOARD_RIGHTDRIVEGIMBALINCREMENT_DATA_COUNT           2         
#define RC_GIMBALBOARD_RIGHTDRIVEGIMBALINCREMENT_DATA_TYPE            int16_t   

//[Pan, Tilt](degrees 0-180)
#define RC_GIMBALBOARD_LEFTMAINGIMBALINCREMENT_DATA_ID                6002      
#define RC_GIMBALBOARD_LEFTMAINGIMBALINCREMENT_DATA_COUNT             2         
#define RC_GIMBALBOARD_LEFTMAINGIMBALINCREMENT_DATA_TYPE              int16_t   

//[Pan, Tilt](degrees 0-180)
#define RC_GIMBALBOARD_RIGHTMAINGIMBALINCREMENT_DATA_ID               6003      
#define RC_GIMBALBOARD_RIGHTMAINGIMBALINCREMENT_DATA_COUNT            2         
#define RC_GIMBALBOARD_RIGHTMAINGIMBALINCREMENT_DATA_TYPE             int16_t   

//
#define RC_GIMBALBOARD_INITIATETESTROUTINE_DATA_ID                    6004      
#define RC_GIMBALBOARD_INITIATETESTROUTINE_DATA_COUNT                 1         
#define RC_GIMBALBOARD_INITIATETESTROUTINE_DATA_TYPE                  uint8_t   



///////////////////////////////////////////////////
////////////        MULTIMEDIABOARD     ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//Headlight intensity for the front of rover
#define RC_MULTIMEDIABOARD_HEADLIGHTINTENSITY_DATA_ID                 7000      
#define RC_MULTIMEDIABOARD_HEADLIGHTINTENSITY_DATA_COUNT              1         
#define RC_MULTIMEDIABOARD_HEADLIGHTINTENSITY_DATA_TYPE               uint8_t   

//[R, G, B] (0, 255)
#define RC_MULTIMEDIABOARD_LEDRGB_DATA_ID                             7001      
#define RC_MULTIMEDIABOARD_LEDRGB_DATA_COUNT                          3         
#define RC_MULTIMEDIABOARD_LEDRGB_DATA_TYPE                           uint8_t   

//[Pattern] (Enum)
#define RC_MULTIMEDIABOARD_LEDPATTERNS_DATA_ID                        7002      
#define RC_MULTIMEDIABOARD_LEDPATTERNS_DATA_COUNT                     1         
#define RC_MULTIMEDIABOARD_LEDPATTERNS_DATA_TYPE                      uint8_t   

//[Teleop, Autonomy, Reached Goal] (enum)
#define RC_MULTIMEDIABOARD_STATEDISPLAY_DATA_ID                       7003      
#define RC_MULTIMEDIABOARD_STATEDISPLAY_DATA_COUNT                    1         
#define RC_MULTIMEDIABOARD_STATEDISPLAY_DATA_TYPE                     uint8_t   



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

//[1-enable, 0-disable]
#define RC_ARMBOARD_SOLENOID_DATA_ID                                  8007      
#define RC_ARMBOARD_SOLENOID_DATA_COUNT                               1         
#define RC_ARMBOARD_SOLENOID_DATA_TYPE                                uint8_t   

//[Power] (-1000, 1000) (m%)
#define RC_ARMBOARD_GRIPPERMOVE_DATA_ID                               8008      
#define RC_ARMBOARD_GRIPPERMOVE_DATA_COUNT                            1         
#define RC_ARMBOARD_GRIPPERMOVE_DATA_TYPE                             int16_t   

//[0-Turn off Watchdog Override, 1-Turn on Watchdog Override]
#define RC_ARMBOARD_WATCHDOGOVERRIDE_DATA_ID                          8009      
#define RC_ARMBOARD_WATCHDOGOVERRIDE_DATA_COUNT                       1         
#define RC_ARMBOARD_WATCHDOGOVERRIDE_DATA_TYPE                        uint8_t   

//[Base Tilt Up, Base Tilt Down, Base Twist CW, Base Twist CCW, Elbow Tilt Up, Elbow Tilt Down, Elbow  Twist CW, Elbow  Twist CCW] (0-Turn off Limit Switch Override, 1-Turn on Limit Switch Override) (bitmasked)
#define RC_ARMBOARD_LIMITSWITCHOVERRIDE_DATA_ID                       8010      
#define RC_ARMBOARD_LIMITSWITCHOVERRIDE_DATA_COUNT                    1         
#define RC_ARMBOARD_LIMITSWITCHOVERRIDE_DATA_TYPE                     uint8_t   

//[1-Base, 2-Elbow, 3-Wrist]
#define RC_ARMBOARD_REBOOTODRIVE_DATA_ID                              8011      
#define RC_ARMBOARD_REBOOTODRIVE_DATA_COUNT                           1         
#define RC_ARMBOARD_REBOOTODRIVE_DATA_TYPE                            uint8_t   

//Prompt arm for J1-6 positions
#define RC_ARMBOARD_REQUESTJOINTPOSITIONS_DATA_ID                     8012      
#define RC_ARMBOARD_REQUESTJOINTPOSITIONS_DATA_COUNT                  1         
#define RC_ARMBOARD_REQUESTJOINTPOSITIONS_DATA_TYPE                   uint8_t   

//Start auto pushing arm J1-6 positions
#define RC_ARMBOARD_TOGGLEPOSITIONTELEM_DATA_ID                       8013      
#define RC_ARMBOARD_TOGGLEPOSITIONTELEM_DATA_COUNT                    1         
#define RC_ARMBOARD_TOGGLEPOSITIONTELEM_DATA_TYPE                     uint8_t   

//Prompt arm for XYZPYR Data
#define RC_ARMBOARD_REQUESTAXESPOSITIONS_DATA_ID                      8014      
#define RC_ARMBOARD_REQUESTAXESPOSITIONS_DATA_COUNT                   1         
#define RC_ARMBOARD_REQUESTAXESPOSITIONS_DATA_TYPE                    uint8_t   

////////////////////Telemetry
//[M1, M2, M3, M4, M5, M6] (0, A)
#define RC_ARMBOARD_MOTORCURRENTS_DATA_ID                             8100      
#define RC_ARMBOARD_MOTORCURRENTS_DATA_COUNT                          6         
#define RC_ARMBOARD_MOTORCURRENTS_DATA_TYPE                           float     

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

//[E1, E2, E3, E4, E5, E6] (0-Good, 1-Failure)
#define RC_ARMBOARD_ENCODERSTATUS_DATA_ID                             8201      
#define RC_ARMBOARD_ENCODERSTATUS_DATA_COUNT                          1         
#define RC_ARMBOARD_ENCODERSTATUS_DATA_TYPE                           uint8_t   



///////////////////////////////////////////////////
////////////        SCIENCEACTUATIONBOARD///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[Power] (-1000, 1000) (m%)
#define RC_SCIENCEACTUATIONBOARD_SENSORAXIS_DATA_ID                   9000      
#define RC_SCIENCEACTUATIONBOARD_SENSORAXIS_DATA_COUNT                1         
#define RC_SCIENCEACTUATIONBOARD_SENSORAXIS_DATA_TYPE                 int16_t   

//[Water 1, Water 2, Water 3] (0, 1000) (m%)
#define RC_SCIENCEACTUATIONBOARD_WATER_DATA_ID                        9001      
#define RC_SCIENCEACTUATIONBOARD_WATER_DATA_COUNT                     3         
#define RC_SCIENCEACTUATIONBOARD_WATER_DATA_TYPE                      uint16_t  

//[Zoop-axis Top, Zoop-axis Bottom, Xoop-axis Left, Xoop-axis Right, Sensor Axis Top, Sensor Axis Bottom] (0-Turn off Limit Switch Override, 1-Turn on Limit Switch Override) (bitmasked)
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHOVERRIDE_DATA_ID          9002      
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHOVERRIDE_DATA_COUNT       1         
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHOVERRIDE_DATA_TYPE        uint8_t   

//[Power] (-1000, 1000) (m%)
#define RC_SCIENCEACTUATIONBOARD_XOOPAXIS_DATA_ID                     9003      
#define RC_SCIENCEACTUATIONBOARD_XOOPAXIS_DATA_COUNT                  1         
#define RC_SCIENCEACTUATIONBOARD_XOOPAXIS_DATA_TYPE                   int16_t   

//[Power] (-1000, 1000) (m%)
#define RC_SCIENCEACTUATIONBOARD_ZOOPAXIS_DATA_ID                     9004      
#define RC_SCIENCEACTUATIONBOARD_ZOOPAXIS_DATA_COUNT                  1         
#define RC_SCIENCEACTUATIONBOARD_ZOOPAXIS_DATA_TYPE                   int16_t   

//[Position] (0,180) (degrees)
#define RC_SCIENCEACTUATIONBOARD_SCOOPGRABBER_DATA_ID                 9005      
#define RC_SCIENCEACTUATIONBOARD_SCOOPGRABBER_DATA_COUNT              1         
#define RC_SCIENCEACTUATIONBOARD_SCOOPGRABBER_DATA_TYPE               int16_t   

////////////////////Telemetry
//[scoop z-pos, scoop x-pos, sensor z-axis] (absolute position 0-360)
#define RC_SCIENCEACTUATIONBOARD_ENCODERPOSITIONS_DATA_ID             9100      
#define RC_SCIENCEACTUATIONBOARD_ENCODERPOSITIONS_DATA_COUNT          3         
#define RC_SCIENCEACTUATIONBOARD_ENCODERPOSITIONS_DATA_TYPE           uint16_t  

////////////////////Error
//[Zoop-axis Top, Zoop-axis Bottom, Xoop-axis Left, Xoop-axis Right, Sensor Axis Top, Sensor Axis Bottom] (0-OFF, 1-ON) (bitmasked)
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHTRIGGERED_DATA_ID         9200      
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHTRIGGERED_DATA_COUNT      1         
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHTRIGGERED_DATA_TYPE       uint8_t   



///////////////////////////////////////////////////
////////////        SCIENCESENSORSBOARD ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[Laser 1, 2 ,3] (0-Disable, 1-Enable)
#define RC_SCIENCESENSORSBOARD_FLASERS_DATA_ID                        10000     
#define RC_SCIENCESENSORSBOARD_FLASERS_DATA_COUNT                     1         
#define RC_SCIENCESENSORSBOARD_FLASERS_DATA_TYPE                      uint8_t   

//[UV, White] (0-Disable, 1-Enable)
#define RC_SCIENCESENSORSBOARD_LIGHTS_DATA_ID                         10001     
#define RC_SCIENCESENSORSBOARD_LIGHTS_DATA_COUNT                      1         
#define RC_SCIENCESENSORSBOARD_LIGHTS_DATA_TYPE                       uint8_t   

////////////////////Telemetry
//[PhotoDiode 1, 2, 3] (Wavelength)
#define RC_SCIENCESENSORSBOARD_FLUOROMETERDATA_DATA_ID                10100     
#define RC_SCIENCESENSORSBOARD_FLUOROMETERDATA_DATA_COUNT             3         
#define RC_SCIENCESENSORSBOARD_FLUOROMETERDATA_DATA_TYPE              float     

//[Gass concentration %, Temperature (C)]
#define RC_SCIENCESENSORSBOARD_METHANE_DATA_ID                        10101     
#define RC_SCIENCESENSORSBOARD_METHANE_DATA_COUNT                     2         
#define RC_SCIENCESENSORSBOARD_METHANE_DATA_TYPE                      float     

//[CO2 Concentration (ppm)]
#define RC_SCIENCESENSORSBOARD_CO2_DATA_ID                            10102     
#define RC_SCIENCESENSORSBOARD_CO2_DATA_COUNT                         1         
#define RC_SCIENCESENSORSBOARD_CO2_DATA_TYPE                          uint16_t  

//[concentration (ppm)]
#define RC_SCIENCESENSORSBOARD_O2_DATA_ID                             10103     
#define RC_SCIENCESENSORSBOARD_O2_DATA_COUNT                          1         
#define RC_SCIENCESENSORSBOARD_O2_DATA_TYPE                           float     

//[concentration (ppm)]
#define RC_SCIENCESENSORSBOARD_CH3_DATA_ID                            10104     
#define RC_SCIENCESENSORSBOARD_CH3_DATA_COUNT                         1         
#define RC_SCIENCESENSORSBOARD_CH3_DATA_TYPE                          float     

//[ NO2 volume (ppm)]
#define RC_SCIENCESENSORSBOARD_NO2_DATA_ID                            10105     
#define RC_SCIENCESENSORSBOARD_NO2_DATA_COUNT                         1         
#define RC_SCIENCESENSORSBOARD_NO2_DATA_TYPE                          uint16_t  



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
#define RC_AUTONOMYBOARD_ADDWAYPOINTS_DATA_ID                         11002     
#define RC_AUTONOMYBOARD_ADDWAYPOINTS_DATA_COUNT                      2         
#define RC_AUTONOMYBOARD_ADDWAYPOINTS_DATA_TYPE                       double    

//
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATA_ID                       11003     
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATA_COUNT                    1         
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATA_TYPE                     uint8_t   

////////////////////Telemetry
//Enum (Idle, Navigating, SearchPattern, Approaching Marker)
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



///////////////////////////////////////////////////
////////////        HEATERBOARD         ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//Bitmask (1-ON, 0-OFF)
#define RC_HEATERBOARD_HEATERTOGGLE_DATA_ID                           15000     
#define RC_HEATERBOARD_HEATERTOGGLE_DATA_COUNT                        1         
#define RC_HEATERBOARD_HEATERTOGGLE_DATA_TYPE                         uint8_t   

////////////////////Telemetry
//[1, 2, 3] (degrees C)
#define RC_HEATERBOARD_THERMO VALUES_DATA_ID                          15100     
#define RC_HEATERBOARD_THERMO VALUES_DATA_COUNT                       3         
#define RC_HEATERBOARD_THERMO VALUES_DATA_TYPE                        float     

//[1, 2, 3] (0-Disabled, 1-Enabled)
#define RC_HEATERBOARD_HEATERENABLED_DATA_ID                          15101     
#define RC_HEATERBOARD_HEATERENABLED_DATA_COUNT                       1         
#define RC_HEATERBOARD_HEATERENABLED_DATA_TYPE                        uint8_t   

////////////////////Error
//Bitmask (1-Overheated, 0-not overheated)
#define RC_HEATERBOARD_OVERHEAT_DATA_ID                               15200     
#define RC_HEATERBOARD_OVERHEAT_DATA_COUNT                            1         
#define RC_HEATERBOARD_OVERHEAT_DATA_TYPE                             uint8_t   



#endif // RoveCommManifest_h