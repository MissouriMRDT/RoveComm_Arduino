#ifndef TeensyRoveCommManifest_h
#define TeensyRoveCommManifest_h

#include <stdint.h>
#include"TeensyRoveCommPacket.h"

#define RC_DRIVEBOARD_FOURTHOCTET                 134       
#define RC_ROVECOMM_DRIVEBOARD_PORT               11004     

#define RC_STEERBOARD_FOURTHOCTET                 154       
#define RC_ROVECOMM_STEERBOARD_PORT               11024     

#define RC_BMSBOARD_FOURTHOCTET                   133       
#define RC_ROVECOMM_BMSBOARD_PORT                 11003     

#define RC_POWERBOARD_FOURTHOCTET                 132       
#define RC_ROVECOMM_POWERBOARD_PORT               11002     

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
#define RC_DRIVEBOARD_WATCHDOGOVERRIDE_DATA_ID                        1004      
#define RC_DRIVEBOARD_WATCHDOGOVERRIDE_DATA_COUNT                     1         
#define RC_DRIVEBOARD_WATCHDOGOVERRIDE_DATA_TYPE                      uint8_t   

////////////////////Telemetry
//[LF, LR, RF, RR] (-1000, 1000)-> (-100%, 100%)
#define RC_DRIVEBOARD_DRIVESPEEDS_DATA_ID                             1100      
#define RC_DRIVEBOARD_DRIVESPEEDS_DATA_COUNT                          4         
#define RC_DRIVEBOARD_DRIVESPEEDS_DATA_TYPE                           int16_t   

////////////////////Error


///////////////////////////////////////////////////
////////////        STEERBOARD          ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[LF, LR, RF, RR] (0, 359)
#define RC_STEERBOARD_SETSTEERINGANGLE_DATA_ID                        1002      
#define RC_STEERBOARD_SETSTEERINGANGLE_DATA_COUNT                     4         
#define RC_STEERBOARD_SETSTEERINGANGLE_DATA_TYPE                      int16_t   

//[PointTurnSpeed] (-1000,1000) (Full speed CCW, full speed CW)
#define RC_STEERBOARD_POINTTURN_DATA_ID                               1003      
#define RC_STEERBOARD_POINTTURN_DATA_COUNT                            1         
#define RC_STEERBOARD_POINTTURN_DATA_TYPE                             int16_t   

//[LF, LR, RF, RR] (-1000, 1000)-> (-100%, 100%)
#define RC_STEERBOARD_SETSTEERINGSPEEDS_DATA_ID                       1005      
#define RC_STEERBOARD_SETSTEERINGSPEEDS_DATA_COUNT                    4         
#define RC_STEERBOARD_SETSTEERINGSPEEDS_DATA_TYPE                     int16_t   

////////////////////Telemetry
//[LF, LR, RF, RR] -> (0, 360)
#define RC_STEERBOARD_DRIVEANGLES_DATA_ID                             1101      
#define RC_STEERBOARD_DRIVEANGLES_DATA_COUNT                          4         
#define RC_STEERBOARD_DRIVEANGLES_DATA_TYPE                           int16_t   

//[M1, M2, M3, M4] (A)
#define RC_STEERBOARD_STEERINGMOTORCURRENTS_DATA_ID                   1102      
#define RC_STEERBOARD_STEERINGMOTORCURRENTS_DATA_COUNT                4         
#define RC_STEERBOARD_STEERINGMOTORCURRENTS_DATA_TYPE                 float     

////////////////////Error
//[(0-undermaxcurrent, 1-overcurrent)] [LF, LR, RF, RL (Bitmask)]
#define RC_STEERBOARD_STEERINGMOTOROVERCURRENT_DATA_ID                1200      
#define RC_STEERBOARD_STEERINGMOTOROVERCURRENT_DATA_COUNT             1         
#define RC_STEERBOARD_STEERINGMOTOROVERCURRENT_DATA_TYPE              uint8_t   



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
//[(0-Disable, 1-Enable)], [M1, M2, M3, M4, Spare (Bitmask)]
#define RC_POWERBOARD_MOTORBUSENABLE_DATA_ID                          3000      
#define RC_POWERBOARD_MOTORBUSENABLE_DATA_COUNT                       1         
#define RC_POWERBOARD_MOTORBUSENABLE_DATA_TYPE                        uint8_t   

//[(0-Disable, 1-Enable)], [Gimbal, Multi, Aux (Bitmask)]
#define RC_POWERBOARD_12VACTBUSENABLE_DATA_ID                         3001      
#define RC_POWERBOARD_12VACTBUSENABLE_DATA_COUNT                      1         
#define RC_POWERBOARD_12VACTBUSENABLE_DATA_TYPE                       uint8_t   

//[(0-Disable, 1-Enable)], [Gimbal, Multi, Aux, Drive, Nav, Cam, Extra (Bitmask)]
#define RC_POWERBOARD_12VLOGICBUSENABLE_DATA_ID                       3002      
#define RC_POWERBOARD_12VLOGICBUSENABLE_DATA_COUNT                    1         
#define RC_POWERBOARD_12VLOGICBUSENABLE_DATA_TYPE                     uint8_t   

//[(0-Disable, 1-Enable)], [12V, Rockets, Aux, Drive (Bitmask)]
#define RC_POWERBOARD_30VBUSENABLE_DATA_ID                            3003      
#define RC_POWERBOARD_30VBUSENABLE_DATA_COUNT                         1         
#define RC_POWERBOARD_30VBUSENABLE_DATA_TYPE                          uint8_t   

//[(0-Disable, 1-Enable)]
#define RC_POWERBOARD_VACUUMENABLE_DATA_ID                            3004      
#define RC_POWERBOARD_VACUUMENABLE_DATA_COUNT                         1         
#define RC_POWERBOARD_VACUUMENABLE_DATA_TYPE                          uint8_t   

////////////////////Telemetry
//[(0-Disabled, 1-Enabled)],[M1, M2, M3, M4, Spare(Bitmask)]
#define RC_POWERBOARD_MOTORBUSENABLED_DATA_ID                         3100      
#define RC_POWERBOARD_MOTORBUSENABLED_DATA_COUNT                      1         
#define RC_POWERBOARD_MOTORBUSENABLED_DATA_TYPE                       uint8_t   

//[(0-Disable, 1-Enable)], [Gimbal, Multi, Aux (Bitmask)]
#define RC_POWERBOARD_12VACTBUSENABLED_DATA_ID                        3101      
#define RC_POWERBOARD_12VACTBUSENABLED_DATA_COUNT                     1         
#define RC_POWERBOARD_12VACTBUSENABLED_DATA_TYPE                      uint8_t   

//[(0-Disable, 1-Enable)], [Gimbal, Multi, Aux, Drive, Nav, Cam, Extra (Bitmask)]
#define RC_POWERBOARD_12VLOGICBUSENABLED_DATA_ID                      3102      
#define RC_POWERBOARD_12VLOGICBUSENABLED_DATA_COUNT                   1         
#define RC_POWERBOARD_12VLOGICBUSENABLED_DATA_TYPE                    uint8_t   

//[(0-Disable, 1-Enable)], [12V, Rockets, Aux, Drive (Bitmask)]
#define RC_POWERBOARD_THIRTYVENABLED_DATA_ID                          3103      
#define RC_POWERBOARD_THIRTYVENABLED_DATA_COUNT                       1         
#define RC_POWERBOARD_THIRTYVENABLED_DATA_TYPE                        uint8_t   

//[(0-Disabled, 1-Enabled)]
#define RC_POWERBOARD_VACUUMENABLED_DATA_ID                           3104      
#define RC_POWERBOARD_VACUUMENABLED_DATA_COUNT                        1         
#define RC_POWERBOARD_VACUUMENABLED_DATA_TYPE                         uint8_t   

//[M1, M2, M3, M4, Spare] (A)
#define RC_POWERBOARD_MOTORBUSCURRENT_DATA_ID                         3105      
#define RC_POWERBOARD_MOTORBUSCURRENT_DATA_COUNT                      5         
#define RC_POWERBOARD_MOTORBUSCURRENT_DATA_TYPE                       float     

//[Gimbal, Multi, Aux, Logic] (A)
#define RC_POWERBOARD_12VBUSCURRENT_DATA_ID                           3106      
#define RC_POWERBOARD_12VBUSCURRENT_DATA_COUNT                        4         
#define RC_POWERBOARD_12VBUSCURRENT_DATA_TYPE                         float     

//[12V Board, Rockets, Aux, Drive] (A)
#define RC_POWERBOARD_30VBUSCURRENT_DATA_ID                           3107      
#define RC_POWERBOARD_30VBUSCURRENT_DATA_COUNT                        4         
#define RC_POWERBOARD_30VBUSCURRENT_DATA_TYPE                         float     

//[Vacuum] (A)
#define RC_POWERBOARD_VACUUMCURRENT_DATA_ID                           3108      
#define RC_POWERBOARD_VACUUMCURRENT_DATA_COUNT                        1         
#define RC_POWERBOARD_VACUUMCURRENT_DATA_TYPE                         float     

////////////////////Error
//[(0-undermaxcurrent, 1-overcurrent)] [M1, M2, M3, M4, Spare (Bitmask)]
#define RC_POWERBOARD_MOTORBUSOVERCURRENT_DATA_ID                     3200      
#define RC_POWERBOARD_MOTORBUSOVERCURRENT_DATA_COUNT                  1         
#define RC_POWERBOARD_MOTORBUSOVERCURRENT_DATA_TYPE                   uint8_t   

//[(0-undermaxcurrent, 1-overcurrent)] [Gimbal, Multi, Aux, Logic (Bitmask)]
#define RC_POWERBOARD_12VBUSOVERCURRENT_DATA_ID                       3201      
#define RC_POWERBOARD_12VBUSOVERCURRENT_DATA_COUNT                    1         
#define RC_POWERBOARD_12VBUSOVERCURRENT_DATA_TYPE                     uint8_t   

//[(0-undermaxcurrent, 1-overcurrent)] [12V Board, Rockets, Aux, Drive (Bitmask)]
#define RC_POWERBOARD_30VBUSOVERCURRENT_DATA_ID                       3202      
#define RC_POWERBOARD_30VBUSOVERCURRENT_DATA_COUNT                    1         
#define RC_POWERBOARD_30VBUSOVERCURRENT_DATA_TYPE                     uint8_t   

//[(0-undermaxcurrent, 1-overcurrent)] [Vacuum]
#define RC_POWERBOARD_VACCUUMOVERCURRENT_DATA_ID                      3203      
#define RC_POWERBOARD_VACCUUMOVERCURRENT_DATA_COUNT                   1         
#define RC_POWERBOARD_VACCUUMOVERCURRENT_DATA_TYPE                    uint8_t   



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
//[Pan, Tilt](degrees 0-270)
#define RC_GIMBALBOARD_LEFTDRIVEGIMBALINCREMENT_DATA_ID               6000      
#define RC_GIMBALBOARD_LEFTDRIVEGIMBALINCREMENT_DATA_COUNT            2         
#define RC_GIMBALBOARD_LEFTDRIVEGIMBALINCREMENT_DATA_TYPE             int16_t   

//[Pan, Tilt](degrees 0-270)
#define RC_GIMBALBOARD_RIGHTDRIVEGIMBALINCREMENT_DATA_ID              6001      
#define RC_GIMBALBOARD_RIGHTDRIVEGIMBALINCREMENT_DATA_COUNT           2         
#define RC_GIMBALBOARD_RIGHTDRIVEGIMBALINCREMENT_DATA_TYPE            int16_t   

//[Pan, Tilt](degrees 0-270)
#define RC_GIMBALBOARD_LEFTMAINGIMBALINCREMENT_DATA_ID                6002      
#define RC_GIMBALBOARD_LEFTMAINGIMBALINCREMENT_DATA_COUNT             2         
#define RC_GIMBALBOARD_LEFTMAINGIMBALINCREMENT_DATA_TYPE              int16_t   

//[Pan, Tilt](degrees 0-270)
#define RC_GIMBALBOARD_RIGHTMAINGIMBALINCREMENT_DATA_ID               6003      
#define RC_GIMBALBOARD_RIGHTMAINGIMBALINCREMENT_DATA_COUNT            2         
#define RC_GIMBALBOARD_RIGHTMAINGIMBALINCREMENT_DATA_TYPE             int16_t   

//[Pan, Tilt](degrees 0-270)
#define RC_GIMBALBOARD_LEFTDRIVEGIMBALABSOLUTE_DATA_ID                6004      
#define RC_GIMBALBOARD_LEFTDRIVEGIMBALABSOLUTE_DATA_COUNT             2         
#define RC_GIMBALBOARD_LEFTDRIVEGIMBALABSOLUTE_DATA_TYPE              int16_t   

//[Pan, Tilt](degrees 0-270)
#define RC_GIMBALBOARD_RIGHTDRIVEGIMBALABSOLUTE_DATA_ID               6005      
#define RC_GIMBALBOARD_RIGHTDRIVEGIMBALABSOLUTE_DATA_COUNT            2         
#define RC_GIMBALBOARD_RIGHTDRIVEGIMBALABSOLUTE_DATA_TYPE             int16_t   

//[Pan, Tilt](degrees 0-270)
#define RC_GIMBALBOARD_LEFTMAINGIMBALABSOLUTE_DATA_ID                 6006      
#define RC_GIMBALBOARD_LEFTMAINGIMBALABSOLUTE_DATA_COUNT              2         
#define RC_GIMBALBOARD_LEFTMAINGIMBALABSOLUTE_DATA_TYPE               int16_t   

//[Pan, Tilt](degrees 0-270)
#define RC_GIMBALBOARD_RIGHTMAINGIMBALABSOLUTE_DATA_ID                6007      
#define RC_GIMBALBOARD_RIGHTMAINGIMBALABSOLUTE_DATA_COUNT             2         
#define RC_GIMBALBOARD_RIGHTMAINGIMBALABSOLUTE_DATA_TYPE              int16_t   

//
#define RC_GIMBALBOARD_INITIATETESTROUTINE_DATA_ID                    6008      
#define RC_GIMBALBOARD_INITIATETESTROUTINE_DATA_COUNT                 1         
#define RC_GIMBALBOARD_INITIATETESTROUTINE_DATA_TYPE                  uint8_t   

////////////////////Telemetry
//Array of 8 servo positions
#define RC_GIMBALBOARD_SERVOPOSITION_DATA_ID                          6100      
#define RC_GIMBALBOARD_SERVOPOSITION_DATA_COUNT                       8         
#define RC_GIMBALBOARD_SERVOPOSITION_DATA_TYPE                        int16_t   

////////////////////Error


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

////////////////////Telemetry
////////////////////Error


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

//0-Disable Closed Loop, 1-Enable Closed Loop
#define RC_ARMBOARD_SETCLOSEDLOOPSTATE_DATA_ID                        8006      
#define RC_ARMBOARD_SETCLOSEDLOOPSTATE_DATA_COUNT                     1         
#define RC_ARMBOARD_SETCLOSEDLOOPSTATE_DATA_TYPE                      uint8_t   

//[Power] (-1000, 1000) (m%)
#define RC_ARMBOARD_GRIPPERMOVE_DATA_ID                               8010      
#define RC_ARMBOARD_GRIPPERMOVE_DATA_COUNT                            1         
#define RC_ARMBOARD_GRIPPERMOVE_DATA_TYPE                             int16_t   

//[0-Turn off Watchdog Override, 1-Turn on Watchdog Override]
#define RC_ARMBOARD_WATCHDOGOVERRIDE_DATA_ID                          8011      
#define RC_ARMBOARD_WATCHDOGOVERRIDE_DATA_COUNT                       1         
#define RC_ARMBOARD_WATCHDOGOVERRIDE_DATA_TYPE                        uint8_t   

//[Base Tilt Up, Base Tilt Down, Base Twist CW, Base Twist CCW, Elbow Tilt Up, Elbow Tilt Down, Elbow  Twist CW, Elbow  Twist CCW] (0-Turn off Limit Switch Override, 1-Turn on Limit Switch Override) (bitmasked)
#define RC_ARMBOARD_LIMITSWITCHOVERRIDE_DATA_ID                       8012      
#define RC_ARMBOARD_LIMITSWITCHOVERRIDE_DATA_COUNT                    1         
#define RC_ARMBOARD_LIMITSWITCHOVERRIDE_DATA_TYPE                     uint8_t   

//[1-Base, 2-Elbow, 3-Wrist]
#define RC_ARMBOARD_REBOOTODRIVE_DATA_ID                              8013      
#define RC_ARMBOARD_REBOOTODRIVE_DATA_COUNT                           1         
#define RC_ARMBOARD_REBOOTODRIVE_DATA_TYPE                            uint8_t   

//Prompt arm for J1-6 positions
#define RC_ARMBOARD_REQUESTJOINTPOSITIONS_DATA_ID                     8014      
#define RC_ARMBOARD_REQUESTJOINTPOSITIONS_DATA_COUNT                  1         
#define RC_ARMBOARD_REQUESTJOINTPOSITIONS_DATA_TYPE                   uint8_t   

//Start auto pushing arm J1-6 positions
#define RC_ARMBOARD_TOGGLEPOSITIONTELEM_DATA_ID                       8015      
#define RC_ARMBOARD_TOGGLEPOSITIONTELEM_DATA_COUNT                    1         
#define RC_ARMBOARD_TOGGLEPOSITIONTELEM_DATA_TYPE                     uint8_t   

//Prompt arm for XYZPYR Data
#define RC_ARMBOARD_REQUESTAXESPOSITIONS_DATA_ID                      8016      
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

//[Motor][Error Type][Error Specific]
#define RC_ARMBOARD_ODRIVEERROR_DATA_ID                               8202      
#define RC_ARMBOARD_ODRIVEERROR_DATA_COUNT                            3         
#define RC_ARMBOARD_ODRIVEERROR_DATA_TYPE                             uint8_t   



///////////////////////////////////////////////////
////////////        SCIENCEACTUATIONBOARD///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[Power] (-1000, 1000) (m%)
#define RC_SCIENCEACTUATIONBOARD_ZAXIS_DATA_ID                        9000      
#define RC_SCIENCEACTUATIONBOARD_ZAXIS_DATA_COUNT                     1         
#define RC_SCIENCEACTUATIONBOARD_ZAXIS_DATA_TYPE                      int16_t   

//[Power] (-1000, 1000) (m%)
#define RC_SCIENCEACTUATIONBOARD_GENEVAOPENLOOP_DATA_ID               9001      
#define RC_SCIENCEACTUATIONBOARD_GENEVAOPENLOOP_DATA_COUNT            1         
#define RC_SCIENCEACTUATIONBOARD_GENEVAOPENLOOP_DATA_TYPE             int16_t   

//[Chemical 1, Chemical 2, Chemical 3] (0, 1000) (m%)
#define RC_SCIENCEACTUATIONBOARD_CHEMICALS_DATA_ID                    9002      
#define RC_SCIENCEACTUATIONBOARD_CHEMICALS_DATA_COUNT                 3         
#define RC_SCIENCEACTUATIONBOARD_CHEMICALS_DATA_TYPE                  uint16_t  

//[absolute position]
#define RC_SCIENCEACTUATIONBOARD_GENEVATOPOSITION_DATA_ID             9003      
#define RC_SCIENCEACTUATIONBOARD_GENEVATOPOSITION_DATA_COUNT          1         
#define RC_SCIENCEACTUATIONBOARD_GENEVATOPOSITION_DATA_TYPE           uint8_t   

//[relative position]
#define RC_SCIENCEACTUATIONBOARD_GENEVAINCREMENTPOSITION_DATA_ID      9004      
#define RC_SCIENCEACTUATIONBOARD_GENEVAINCREMENTPOSITION_DATA_COUNT   1         
#define RC_SCIENCEACTUATIONBOARD_GENEVAINCREMENTPOSITION_DATA_TYPE    int8_t    

//[Z-axis Top, Z-axis Bottom, Geneva Set, Geneva Home] (0-Turn off Limit Switch Override, 1-Turn on Limit Switch Override) (bitmasked)
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHOVERRIDE_DATA_ID          9005      
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHOVERRIDE_DATA_COUNT       1         
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHOVERRIDE_DATA_TYPE        uint8_t   

//[Power] (-1000, 1000) (m%)
#define RC_SCIENCEACTUATIONBOARD_MIXERVELOCITY_DATA_ID                9006      
#define RC_SCIENCEACTUATIONBOARD_MIXERVELOCITY_DATA_COUNT             4         
#define RC_SCIENCEACTUATIONBOARD_MIXERVELOCITY_DATA_TYPE              int16_t   

////////////////////Telemetry
//[absolute position]
#define RC_SCIENCEACTUATIONBOARD_GENEVACURRENTPOSITION_DATA_ID        9100      
#define RC_SCIENCEACTUATIONBOARD_GENEVACURRENTPOSITION_DATA_COUNT     1         
#define RC_SCIENCEACTUATIONBOARD_GENEVACURRENTPOSITION_DATA_TYPE      uint8_t   

//[Z-axis Top, Z-axis Bottom, Geneva Set, Geneva Home] (bitmasked)
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHTRIGGERED_DATA_ID         9101      
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHTRIGGERED_DATA_COUNT      1         
#define RC_SCIENCEACTUATIONBOARD_LIMITSWITCHTRIGGERED_DATA_TYPE       uint8_t   

////////////////////Error


///////////////////////////////////////////////////
////////////        SCIENCESENSORSBOARD ///////////         
///////////////////////////////////////////////////

////////////////////Commands
//[(LED On = 1/LED Off = 0)]
#define RC_SCIENCESENSORSBOARD_UVLEDCONTROL_DATA_ID                   10000     
#define RC_SCIENCESENSORSBOARD_UVLEDCONTROL_DATA_COUNT                1         
#define RC_SCIENCESENSORSBOARD_UVLEDCONTROL_DATA_TYPE                 uint8_t   

//
#define RC_SCIENCESENSORSBOARD_RUNSPECTROMETER_DATA_ID                10001     
#define RC_SCIENCESENSORSBOARD_RUNSPECTROMETER_DATA_COUNT             1         
#define RC_SCIENCESENSORSBOARD_RUNSPECTROMETER_DATA_TYPE              uint8_t   

////////////////////Telemetry
//Sends half of the spectrum read
#define RC_SCIENCESENSORSBOARD_SPECTROMETERDATA_DATA_ID               10100     
#define RC_SCIENCESENSORSBOARD_SPECTROMETERDATA_DATA_COUNT            144       
#define RC_SCIENCESENSORSBOARD_SPECTROMETERDATA_DATA_TYPE             uint16_t  

//[Gass concentration %, Temperature (C)]
#define RC_SCIENCESENSORSBOARD_METHANE_DATA_ID                        10101     
#define RC_SCIENCESENSORSBOARD_METHANE_DATA_COUNT                     2         
#define RC_SCIENCESENSORSBOARD_METHANE_DATA_TYPE                      float     

//[CO2 Concentration (ppm)]
#define RC_SCIENCESENSORSBOARD_CO2_DATA_ID                            10102     
#define RC_SCIENCESENSORSBOARD_CO2_DATA_COUNT                         1         
#define RC_SCIENCESENSORSBOARD_CO2_DATA_TYPE                          uint16_t  

//[partial pressure, (mBar), temperature (C), concentration (ppm), barometric pressue (mBar)]
#define RC_SCIENCESENSORSBOARD_O2_DATA_ID                             10103     
#define RC_SCIENCESENSORSBOARD_O2_DATA_COUNT                          4         
#define RC_SCIENCESENSORSBOARD_O2_DATA_TYPE                           float     

//
#define RC_SCIENCESENSORSBOARD_NO_DATA_ID                             10104     
#define RC_SCIENCESENSORSBOARD_NO_DATA_COUNT                          1         
#define RC_SCIENCESENSORSBOARD_NO_DATA_TYPE                           float     

//[ N2O volume (ppm)]
#define RC_SCIENCESENSORSBOARD_N2O_DATA_ID                            10105     
#define RC_SCIENCESENSORSBOARD_N2O_DATA_COUNT                         1         
#define RC_SCIENCESENSORSBOARD_N2O_DATA_TYPE                          uint16_t  

////////////////////Error


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
#define RC_AUTONOMYBOARD_CURRENTLOG_DATA_ID                           11200     
#define RC_AUTONOMYBOARD_CURRENTLOG_DATA_COUNT                        255       
#define RC_AUTONOMYBOARD_CURRENTLOG_DATA_TYPE                         char      

////////////////////Error


///////////////////////////////////////////////////
////////////        CAMERA1BOARD        ///////////         
///////////////////////////////////////////////////

////////////////////Commands
////////////////////Telemetry
////////////////////Error


///////////////////////////////////////////////////
////////////        CAMERA2BOARD        ///////////         
///////////////////////////////////////////////////

////////////////////Commands
////////////////////Telemetry
////////////////////Error


#endif // RoveCommManifest_h