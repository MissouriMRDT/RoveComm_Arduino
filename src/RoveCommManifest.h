#ifndef RoveCommManifest_h
#define RoveCommManifest_h
//RC:2.2

#include <stdint.h>
#include "RoveCommPacket.h"


//RoveComm Port IDs
#define RC_ROVECOMM_ETHERNET_UDP_PORT      	                 11000 
#define RC_ROVECOMM_ETHERNET_DRIVE_LIGHTING_BOARD_PORT       11001
#define RC_ROVECOMM_ETHERNET_BMSBOARD_PORT                   11002
#define RC_ROVECOMM_ETHERNET_POWERBOARD_PORT                 11003
#define RC_ROVECOMM_ETHERNET_CAMERABOARD_PORT                11004
#define RC_ROVECOMM_ETHERNET_N3_PORT                         11005
#define RC_ROVECOMM_ETHERNET_SHIMBLEBOARD_PORT               11006
#define RC_ROVECOMM_ETHERNET_ARMBOARD_PORT                   11007
#define RC_ROVECOMM_ETHERNET_SRA_ACTUATIONBOARD_PORT         11008
#define RC_ROVECOMM_ETHERNET_SRA_SENSORBOARD_PORT            11009
#define RC_ROVECOMM_ETHERNET_WIRELESS_ESTOP_PORT             11010
#define RC_ROVECOMM_ETHERNET_PR_CONTROLLER_PORT              11011
#define RC_ROVECOMM_ETHERNET_BSMS_PORT                       11012
#define RC_ROVECOMM_ETHERNET_BLACK_BOX_PORT                  11013
#define RC_ROVECOMM_ETHERNET_AUTONOMY_PORT                   11015

//IP Addresses
#define RC_ROVECOMM_SUBNET_IP_FIRST_OCTET     192
#define RC_ROVECOMM_SUBNET_IP_SECOND_OCTET    168
#define RC_ROVECOMM_SUBNET_IP_THIRD_OCTET       1
        
#define RC_ROCKETROVER900_FOURTHOCTET          82
#define RC_ROCKETBASE900_FOURTHOCTET           83
#define RC_ROCKETROVE58_FOURTHOCTET            84
#define RC_ROCKETBASE58_FOURTHOCTET            85
#define RC_ROCKETROVER24_FOURTHOCTET           86
#define RC_ROCKETROVERSPARE_FOURTHOCTET        87
        
#define RC_OPEN_FOURTHOCTET                    130
#define RC_DRIVEBOARD_FOURTHOCTET              131
#define RC_BMSBOARD_FOURTHOCTET                132
#define RC_POWERBOARD_FOURTHOCTET              133
#define RC_CAMERABOARD_FOURTHOCTET             134
#define RC_N3_FOURTHOCTET                      135
#define RC_SHIMBLEBOARD_FOURTHOCTET    	   	   136
#define RC_ARMBOARD_FOURTHOCTET                137
#define RC_SRAACTUATIONBOARD_FOURTHOCTET       138
#define RC_SRASENSORSBOARD_FOURTHOCTET         139
#define RC_WIRELESS_ESTOP_FOURTHOCTET          140
#define RC_PR_CONTROLLER_FOURTHOCTET           141
#define RC_BSMS_FOURTHOCTET                    142
#define RC_BLACKBOX_FOURTHOCTET       		   143
#define RC_AUTONOMY_FOURTHOCTET                144

#define RC_STREAMERPI_FOURTHOCTET 		       150
        
#define RC_GRANDSTREAM1_FOURTHOCTET            226
#define RC_GRANDSTREAM2_FOURTHOCTET            227

/*RoveCommDataIDs: (0, 65535)
 *AABCC
 *AA-Board Number
 *B -Command Type
 *CC-Command Number
 */ 
 
//Board numbers
#define _DRIVEBOARD_BOARDNUMBER      01*1000
#define _BMSBOARD_BOARDNUMBER        02*1000
#define _POWERBOARD_BOARDNUMBER      03*1000
#define _CAMERABOARD_BOARDNUMBER     04*1000    
#define _N3_BOARDNUMBER              05*1000    
#define _SHIMBLEBOARD_BOARDNUMBER    06*1000    
#define _ARMBOARD_BOARDNUMBER        7*1000    
#define _SRAACTUATION_BOARDNUMBER    8*1000    
#define _SRASENSORS_BOARDNUMBER      9*1000
#define _WIRELESS_ESTOP_BOARDNUMBER  10*1000
#define _PR_CONTROLLER_BOARDNUMBER   11*1000
#define _BSMS_BOARDNUMBER            12*1000
#define _BLACKBOX_BOARDNUMBER        13*1000
#define _LIGHTING_BOARDNUMBER        14*1000
#define _AUTONOMY_BOARDNUMBER		 15*1000  

//Command Types
#define _TYPE_COMMAND     0*100
#define _TYPE_TELEMETRY   1*100
#define _TYPE_ERROR       2*100


///////////////////////////////////////////////////
//             RoveComm System Id's              //
///////////////////////////////////////////////////
#define RC_ROVECOMM_PING_DATA_ID					1
#define RC_ROVECOMM_PING_REPLY_DATA_ID				2
#define RC_ROVECOMM_SUBSCRIBE_REQUEST_DATA_ID		3
#define	RC_ROVECOMM_UNSUBSCRIBE_REQUEST_DATA_ID 	4
#define	ROVECOMM_INVALID_VERSION_DATA_ID			5
#define	ROVECOMM_NO_DATA_DATA_ID			        6		


///////////////////////////////////////////////////
//                DriveBoard                     //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//UDP/////
//Drive Left Right
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_DATAID            	00+_TYPE_COMMAND+_DRIVEBOARD_BOARDNUMBER
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_DATATYPE          	int16_t			// (-1000, 1000)-->(-100%, 100%)
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_DATACOUNT        	2				//[LeftSpeed, RightSpeed]
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_DRIVEMAXFORWARD   	1000
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_DRIVEMAXREVERSE   	-1000
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_DRIVEZERO         	0
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_LEFTSPEEDENTRY    	0
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_RIGHTSPEEDENTRY    1

//Drive Left Right
#define RC_DRIVEBOARD_DRIVEINDIVIDUAL_DATAID            	01+_TYPE_COMMAND+_DRIVEBOARD_BOARDNUMBER
#define RC_DRIVEBOARD_DRIVEINDIVIDUAL_DATATYPE          	int16_t			// (-1000, 1000)-> (-100%, 100%)
#define RC_DRIVEBOARD_DRIVEINDIVIDUAL_DATACOUNT        	    6				//[LF, LM, LR, RF, M, RR]
#define RC_DRIVEBOARD_DRIVEINDIVIDUAL_DRIVEMAXFORWARD   	1000
#define RC_DRIVEBOARD_DRIVEINDIVIDUAL_DRIVEMAXREVERSE   	-1000
#define RC_DRIVEBOARD_DRIVEINDIVIDUAL_DRIVEZERO         	0

//TCP/////
//Watchdog Override
#define RC_DRIVEBOARD_WATCHDOG_DATAID           02+_TYPE_COMMAND+_DRIVEBOARD_BOARDNUMBER
#define RC_DRIVEBOARD_WATCHDOG_DATATYPE         uint8_t			
#define RC_DRIVEBOARD_WATCHDOG_DATACOUNT        1				
#define RC_DRIVEBOARD_WATCHDOG_TURN_OFF   	    1
#define RC_DRIVEBOARD_WATCHDOG_TURN_ON         	0

//Telemetry////////////////////////////////////////////////////////////////////////////////////////////
//UDP/////
//Drive Speed
#define RC_DRIVEBOARD_DRIVE_SPEED_DATAID                00+_TYPE_TELEMETRY+_DRIVEBOARD_BOARDNUMBER
#define RC_DRIVEBOARD_DRIVE_SPEED_DATATYPE			    int16_t //(-1000, 1000)-> (-100%, 100%)
#define RC_DRIVEBOARD_DRIVE_SPEED_DATACOUNT         	6      //[LF, LM, LR, RF, RM,RR]

//Error////////////////////////////////////////////////////////////////////////////////////////////
//TCP/////
//WatchDog Triggered
#define RC_DRIVEBOARD_WACHDOGTRIGGERED_DATAID           00+_TYPE_ERROR+_DRIVEBOARD_BOARDNUMBER
#define RC_DRIVEBOARD_WACHDOGTRIGGERED_DATATYPE			uint8_t
#define RC_DRIVEBOARD_WACHDOGTRIGGERED_DATACOUNT       	1
#define RC_DRIVEBOARD_WACHDOGTRIGGERED_TRIGGERED		1
#define RC_DRIVEBOARD_WACHDOGTRIGGERED_NOTTRIGGERED		0

///////////////////////////////////////////////////
//                BMSBoard                       //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//TCP/////
//BMS Suicide
#define RC_BMSBOARD_SUICIDE_DATAID            	00+_TYPE_COMMAND+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_SUICIDE_DATATYPE          	uint8_t		
#define RC_BMSBOARD_SUICIDE_DATACOUNT        	0		

//Software E-Stop
#define RC_BMSBOARD_SW_ESTOP_DATAID            	01+_TYPE_COMMAND+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_SW_ESTOP_DATATYPE          	uint8_t		
#define RC_BMSBOARD_SW_ESTOP_DATACOUNT        	1   //number of seconds until reboot, defaults to 1

//UDP/////
//Wireless E-Stop Enable
#define RC_BMSBOARD_ENABLE_WIRELESS_ESTOP_DATAID            02+_TYPE_COMMAND+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_ENABLE_WIRELESS_ESTOP_DATATYPE          uint8_t		
#define RC_BMSBOARD_ENABLE_WIRELESS_ESTOP_DATACOUNT        	1   //0 to disable wireless estop functionality, 1 to disable

//Wireless E-Stop 
#define RC_BMSBOARD_WIRELESS_ESTOP_DATAID            03+_TYPE_COMMAND+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_WIRELESS_ESTOP_DATATYPE          uint8_t		
#define RC_BMSBOARD_WIRELESS_ESTOP_DATACOUNT         1   //0 to keep rover alive, 1 to kill rover

//Telemetry//////////////////////////////////////////////////////////////////////////////////////////////
//UDP/////
//Main I_Meas
#define RC_BMSBOARD_MAINIMEASmA_DATAID          00+_TYPE_TELEMETRY+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_MAINIMEASmA_DATATYPE        float	//main current output
#define RC_BMSBOARD_MAINIMEASmA_DATACOUNT      	1

//Pack  V_Meas
#define RC_BMSBOARD_PACK_VMEAS_DATAID           01+_TYPE_TELEMETRY+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_PACK_VMEAS_DATATYPE         float	
#define RC_BMSBOARD_PACK_VMEAS_DATACOUNT        1

//Cell  V_Meas
#define RC_BMSBOARD_CELL_VMEAS_DATAID           02+_TYPE_TELEMETRY+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_CELL_VMEAS_DATATYPE         float	
#define RC_BMSBOARD_CELL_VMEAS_DATACOUNT        8

//Temp_Meas
#define RC_BMSBOARD_TEMPMEASmDEGC_DATAID        03+_TYPE_TELEMETRY+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_TEMPMEASmDEGC_DATATYPE      float	//Temperature Reading in Deg Celcius
#define RC_BMSBOARD_TEMPMEASmDEGC_DATACOUNT     1

//Error//////////////////////////////////////////////////////////////////////////////////////////////
//TCP/////
//Pack Overcurrent
#define RC_BMSBOARD_PACK_OVERCURRENT_DATAID		00+_TYPE_ERROR+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_PACK_OVERCURRENT_DATATYPE	uint8_t	
#define RC_BMSBOARD_PACK_OVERCURRENT_DATACOUNT	1	

//Cell Undervoltage
#define RC_BMSBOARD_CELL_UNDERVOLTAGE_DATAID		01+_TYPE_ERROR+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_CELL_UNDERVOLTAGE_DATATYPE		uint8_t	
#define RC_BMSBOARD_CELL_UNDERVOLTAGE_DATACOUNT		2 //bitmasked value

//Pack Undervoltage
#define RC_BMSBOARD_PACK_UNDERVOLTAGE_DATAID		02+_TYPE_ERROR+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_PACK_UNDERVOLTAGE_DATATYPE		uint8_t	
#define RC_BMSBOARD_PACK_UNDERVOLTAGE_DATACOUNT		1

//Pack Superhot
#define RC_BMSBOARD_PACK_SUPERHOT_DATAID		03+_TYPE_ERROR+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_PACK_SUPERHOT_DATATYPE	    uint8_t	
#define RC_BMSBOARD_PACK_SUPERHOT_DATACOUNT		1

///////////////////////////////////////////////////
//                PowerBoard                     //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//TCP/////
//Motor bus enable
#define RC_POWERBOARD_MOTOR_BUSENABLE_DATAID        00+_TYPE_COMMAND+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_MOTOR_BUSENABLE_DATATYPE      uint8_t 		
#define RC_POWERBOARD_MOTOR_BUSENABLE_DATACOUNT     1   //[Enable/Disable][M1, M2, M3, M4, M5, M6]	(bitmask)
#define RC_POWERBOARD_MOTOR_BUSENABLE_ENABLE		    1
#define RC_POWERBOARD_MOTOR_BUSENABLE_DISABLE       0

//12V bus enable
#define RC_POWERBOARD_12V_BUSENABLE_DATAID          01+_TYPE_COMMAND+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_12V_BUSENABLE_DATATYPE        uint8_t 		
#define RC_POWERBOARD_12V_BUSENABLE_DATACOUNT       1   //[Enable/Disable][Act, Logic]  (bitmask)
#define RC_POWERBOARD_12V_BUSENABLE_ENABLE			    1
#define RC_POWERBOARD_12V_BUSENABLE_DISABLE         0

//30V bus enable
#define RC_POWERBOARD_30V_BUSENABLE_DATAID          02+_TYPE_COMMAND+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_30V_BUSENABLE_DATATYPE        uint8_t 		
#define RC_POWERBOARD_30V_BUSENABLE_DATACOUNT       1   //[Enable/Disable][12V Board, Rockets, Aux]  (bitmask)
#define RC_POWERBOARD_30V_BUSENABLE_ENABLE			    1
#define RC_POWERBOARD_30V_BUSENABLE_DISABLE         0

//Vacuum enable
#define RC_POWERBOARD_VACUUM_ENABLE_DATAID          03+_TYPE_COMMAND+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_VACUUM_ENABLE_DATATYPE        uint8_t 		
#define RC_POWERBOARD_VACUUM_ENABLE_DATACOUNT       1   //[Enable/Disable]
#define RC_POWERBOARD_VACUUM_ENABLE_ENABLE			    1
#define RC_POWERBOARD_VACUUM_ENABLE_DISABLE         0

//Patch Panel enable
#define RC_POWERBOARD_PATCH_PANELENABLE_DATAID      04+_TYPE_COMMAND+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_PATCH_PANELENABLE_DATATYPE    uint8_t 		
#define RC_POWERBOARD_PATCH_PANELENABLE_DATACOUNT   1   //[Enable/Disable][Panels 1-8]  (bitmask)
#define RC_POWERBOARD_PATCH_PANELENABLE_ENABLE			1
#define RC_POWERBOARD_PATCH_PANELENABLE_DISABLE     0

//Telemetry//////////////////////////////////////////////////////////////////////////////////////////////
//UDP/////
//Motor bus enabled
#define RC_POWERBOARD_MOTOR_BUSENABLED_DATAID        00+_TYPE_TELEMETRY+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_MOTOR_BUSENABLED_DATATYPE      uint8_t 		
#define RC_POWERBOARD_MOTOR_BUSENABLED_DATACOUNT     1   //[Enabled/Disabled][M1, M2, M3, M4, M5, M6]	(bitmask)

//12V bus enabled
#define RC_POWERBOARD_12V_BUSENABLED_DATAID          01+_TYPE_TELEMETRY+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_12V_BUSENABLED_DATATYPE        uint8_t 		
#define RC_POWERBOARD_12V_BUSENABLED_DATACOUNT       1   //[Enabled/Disabled][Act, Logic]  (bitmask)

//30V bus enabled
#define RC_POWERBOARD_30V_BUSENABLED_DATAID          02+_TYPE_TELEMETRY+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_30V_BUSENABLED_DATATYPE        uint8_t 		
#define RC_POWERBOARD_30V_BUSENABLED_DATACOUNT       1   //[Enabled/Disabled][12V Board, Rockets, Aux]  (bitmask)

//Vacuum enabled
#define RC_POWERBOARD_VACUUM_ENABLED_DATAID          03+_TYPE_TELEMETRY+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_VACUUM_ENABLED_DATATYPE        uint8_t 		
#define RC_POWERBOARD_VACUUM_ENABLED_DATACOUNT       1   //[Enabled/Disabled]

//Patch Panel enabled
#define RC_POWERBOARD_PATCH_PANELENABLED_DATAID      04+_TYPE_TELEMETRY+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_PATCH_PANELENABLED_DATATYPE    uint8_t 		
#define RC_POWERBOARD_PATCH_PANELENABLED_DATACOUNT   1   //[Enabled/Disabled][Panels 1-8]  (bitmask)

//Motor bus current
#define RC_POWERBOARD_MOTOR_BUS_CURRENT_DATAID       05+_TYPE_TELEMETRY+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_MOTOR_BUS_CURRENT_DATATYPE     float 		
#define RC_POWERBOARD_MOTOR_BUS_CURRENT_DATACOUNT    6   //[M1, M2, M3, M4, M5, M6]	

//12V bus current
#define RC_POWERBOARD_12V_BUS_CURRENT_DATAID         06+_TYPE_TELEMETRY+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_12V_BUS_CURRENT_DATATYPE       float 		
#define RC_POWERBOARD_12V_BUS_CURRENT_DATACOUNT      2   //[Act, Logic]  

//30V bus current
#define RC_POWERBOARD_30V_BUS_CURRENT_DATAID         07+_TYPE_TELEMETRY+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_30V_BUS_CURRENT_DATATYPE       float 		
#define RC_POWERBOARD_30V_BUS_CURRENT_DATACOUNT      3  //[12V Board, Rockets, Aux] 

//Vacuum current
#define RC_POWERBOARD_VACUUM_CURRENT_DATAID          08+_TYPE_TELEMETRY+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_VACUUM_CURRENT_DATATYPE        float 		
#define RC_POWERBOARD_VACUUM_CURRENT_DATACOUNT       1    

//Error//////////////////////////////////////////////////////////////////////////////////////////////
//TCP/////
//Motor bus overcurrent
#define RC_POWERBOARD_MOTOR_BUS_OVERCURRENT_DATAID          00+_TYPE_ERROR+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_MOTOR_BUS_OVERCURRENT_DATATYPE        uint8_t 		
#define RC_POWERBOARD_MOTOR_BUS_OVERCURRENT_DATACOUNT       1   //[M1, M2, M3, M4, M5, M6, M7, Spare]	(bitmask)

//12V bus overcurrent
#define RC_POWERBOARD_12V_BUS_OVERCURRENT_DATAID          01+_TYPE_ERROR+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_12V_BUS_OVERCURRENT_DATATYPE        uint8_t 		
#define RC_POWERBOARD_12V_BUS_OVERCURRENT_DATACOUNT       1   //[Act, Logic]  (bitmask)

//30V bus overcurrent
#define RC_POWERBOARD_30V_BUS_OVERCURRENT_DATAID          02+_TYPE_ERROR+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_30V_BUS_OVERCURRENT_DATATYPE        uint8_t 		
#define RC_POWERBOARD_30V_BUS_OVERCURRENT_DATACOUNT       1  //[12V Board, Rockets, Aux]  (bitmask)

//Vacuum overcurrent
#define RC_POWERBOARD_VACUUM_OVERCURRENT_DATAID          03+_TYPE_ERROR+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_VACUUM_OVERCURRENT_DATATYPE        uint8_t 		
#define RC_POWERBOARD_VACUUM_OVERCURRENT_DATACOUNT       1   

//Patch Panel overcurrent
#define RC_POWERBOARD_PATCH_PANEL_OVERCURRENT_DATAID          04+_TYPE_ERROR+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_PATCH_PANEL_OVERCURRENT_DATATYPE        uint8_t 		
#define RC_POWERBOARD_PATCH_PANEL_OVERCURRENT_DATACOUNT       1   //[Panels 1-8] (bitmask)

///////////////////////////////////////////////////
//                CameraBoard                    //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////

//Telemetry//////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////
//                NavigationBoard                //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////

//Telemetry//////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////
//                ShimbleBoard                   //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//UDP/////
//Left Drive Gimbal Increment
#define RC_SHIMBLEBOARD_LEFT_DRIVE_SERVOINC_DATAID         00+_TYPE_COMMAND+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_LEFT_DRIVE_SERVOINC_DATATYPE       int16_t	//Degrees
#define RC_SHIMBLEBOARD_LEFT_DRIVE_SERVOINC_DATACOUNT	   2		//[Pan, Tilt]

//Right Drive Gimbal Increment
#define RC_SHIMBLEBOARD_RIGHT_DRIVE_SERVOINC_DATAID         01+_TYPE_COMMAND+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_RIGHT_DRIVE_SERVOINC_DATATYPE       int16_t	//Degrees
#define RC_SHIMBLEBOARD_RIGHT_DRIVE_SERVOINC_DATACOUNT		2		//[Pan, Tilt]

//Left Main Gimbal Increment
#define RC_SHIMBLEBOARD_LEFT_MAIN_SERVOINC_DATAID         02+_TYPE_COMMAND+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_LEFT_MAIN_SERVOINC_DATATYPE       int16_t	//Degrees
#define RC_SHIMBLEBOARD_LEFT_MAIN_SERVOINC_DATACOUNT	  2		//[Pan, Tilt]

//Right Main Gimbal Increment
#define RC_SHIMBLEBOARD_RIGHT_MAIN_SERVOINC_DATAID         03+_TYPE_COMMAND+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_RIGHT_MAIN_SERVOINC_DATATYPE       int16_t	//Degrees
#define RC_SHIMBLEBOARD_RIGHT_MAIN_SERVOINC_DATACOUNT	   2		//[Pan, Tilt]

//TCP/////
//Left Drive Gimbal Absolute
#define RC_SHIMBLEBOARD_LEFT_DRIVE_SERVOABS_DATAID         04+_TYPE_COMMAND+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_LEFT_DRIVE_SERVOABS_DATATYPE       int16_t	//Degrees
#define RC_SHIMBLEBOARD_LEFT_DRIVE_SERVOABS_DATACOUNT	   2		//[Pan, Tilt]

//Right Drive Gimbal Absolute
#define RC_SHIMBLEBOARD_RIGHT_DRIVE_SERVOABS_DATAID         05+_TYPE_COMMAND+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_RIGHT_DRIVE_SERVOABS_DATATYPE       int16_t	//Degrees
#define RC_SHIMBLEBOARD_RIGHT_DRIVE_SERVOABS_DATACOUNT		2		//[Pan, Tilt]

//Left Main Gimbal Absolute
#define RC_SHIMBLEBOARD_LEFT_MAIN_SERVOABS_DATAID         06+_TYPE_COMMAND+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_LEFT_MAIN_SERVOABS_DATATYPE       int16_t	//Degrees
#define RC_SHIMBLEBOARD_LEFT_MAIN_SERVOABS_DATACOUNT	  2		//[Pan, Tilt]

//Right Main Gimbal Absolute
#define RC_SHIMBLEBOARD_RIGHT_MAIN_SERVOABS_DATAID         07+_TYPE_COMMAND+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_RIGHT_MAIN_SERVOABS_DATATYPE       int16_t	//Degrees
#define RC_SHIMBLEBOARD_RIGHT_MAIN_SERVOABS_DATACOUNT	   2		//[Pan, Tilt]

//Telemetry//////////////////////////////////////////////////////////////////////////////////////////////
//UDP/////
//Servo Position
#define RC_SHIMBLEBOARD_SERVODEG_DATAID       	00+_TYPE_TELEMETRY+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_SERVODEG_DATATYPE     	int16_t	//Degrees
#define RC_SHIMBLEBOARD_SERVODEG_DATACOUNT		8		//[S1][S2][S3][S4][S5][S6][S7][S8]

///////////////////////////////////////////////////
//                SRAActuationBoard              //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//UDP/////
//Z-Axis
#define RC_SRAACTUATION_Z_AXIS_DATAID     	00+_TYPE_COMMAND+_SRAACTUATION_BOARDNUMBER
#define RC_SRAACTUATION_Z_AXIS_DATATYPE   	int16_t
#define RC_SRAACTUATION_Z_AXIS_DATACOUNT  	1   //[-1000, 1000] speed

//Geneva Open Loop
#define RC_SRAACTUATION_GENEVA_OPENLOOP_DATAID     	01+_TYPE_COMMAND+_SRAACTUATION_BOARDNUMBER
#define RC_SRAACTUATION_GENEVA_OPENLOOP_DATATYPE   	int16_t
#define RC_SRAACTUATION_GENEVA_OPENLOOP_DATACOUNT  	1   //[-1000, 1000] speed

//TCP/////
//Chemicals
#define RC_SRAACTUATION_CHEMICALS_DATAID     	02+_TYPE_COMMAND+_SRAACTUATION_BOARDNUMBER
#define RC_SRAACTUATION_CHEMICALS_DATATYPE   	uint8_t	
#define RC_SRAACTUATION_CHEMICALS_DATACOUNT  	3   //[Chemical 1, Chemical 2, Chemical 3]

//Geneva to position
#define RC_SRAACTUATION_GENEVA_TO_POS_DATAID     	03+_TYPE_COMMAND+_SRAACTUATION_BOARDNUMBER
#define RC_SRAACTUATION_GENEVA_TO_POS_DATATYPE   	uint8_t	
#define RC_SRAACTUATION_GENEVA_TO_POS_DATACOUNT  	1   //[Absolute position]

//Geneva increment position
#define RC_SRAACTUATION_GENEVA_INC_POS_DATAID     	04+_TYPE_COMMAND+_SRAACTUATION_BOARDNUMBER
#define RC_SRAACTUATION_GENEVA_INC_POS_DATATYPE   	int8_t	
#define RC_SRAACTUATION_GENEVA_INC_POS_DATACOUNT  	1   //[Relative position]

//Vacuum
#define RC_SRAACTUATION_VACUUM_DATAID     	05+_TYPE_COMMAND+_SRAACTUATION_BOARDNUMBER
#define RC_SRAACTUATION_VACUUM_DATATYPE   	uint8_t	
#define RC_SRAACTUATION_VACUUM_DATACOUNT  	1   //[0-off, 1-on]

//Limit switch override
#define RC_SRAACTUATION_LIMIT_SWITCH_OVERRIDE_DATAID     	06+_TYPE_COMMAND+_SRAACTUATION_BOARDNUMBER
#define RC_SRAACTUATION_LIMIT_SWITCH_OVERRIDE_DATATYPE   	uint8_t	
#define RC_SRAACTUATION_LIMIT_SWITCH_OVERRIDE_DATACOUNT  	1   //[Z-axis Top, Z-axis Bottom, Geneva Set, Geneva Home] (0-Turn off Limit Switch Override, 1-Turn on Limit Switch Override) (bitmasked)

//Telemetry//////////////////////////////////////////////////////////////////////////////////////////////
//UDP/////
//Geneva Current Position
#define RC_SRAACTUATION_GENEVA_CURRENT_POSITION_DATAID     	00+_TYPE_TELEMETRY+_SRAACTUATION_BOARDNUMBER
#define RC_SRAACTUATION_GENEVA_CURRENT_POSITION_DATATYPE   	uint8_t	
#define RC_SRAACTUATION_GENEVA_CURRENT_POSITION_DATACOUNT  	1		//[absolute position]	

//Limit Switch Triggered
#define RC_SRAACTUATION_LIMIT_SWITCH_TRIGGERED_DATAID     	00+_TYPE_TELEMETRY+_SRAACTUATION_BOARDNUMBER
#define RC_SRAACTUATION_LIMIT_SWITCH_TRIGGERED_DATATYPE   	uint8_t	
#define RC_SRAACTUATION_LIMIT_SWITCH_TRIGGERED_DATACOUNT  	1       //[Z-axis Top, Z-axis Bottom, Geneva Set, Geneva Home] (bitmasked)

///////////////////////////////////////////////////
//                SRASensorsBoard                //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//TCP/////
//UV LED Enable
#define RC_SRASENSORSBOARD_UVLEDENABLE_DATAID     	00+_TYPE_COMMAND+_SRASENSORS_BOARDNUMBER
#define RC_SRASENSORSBOARD_UVLEDENABLE_DATATYPE   	uint8_t	
#define RC_SRASENSORSBOARD_UVLEDENABLE_DATACOUNT  	1		
#define RC_SRASENSORSBOARD_UVLEDENABLE_ENABLED		1
#define RC_SRASENSORSBOARD_UVLEDENABLE_DISABLED		0

//Capture Spectrometer Data
#define RC_SRASENSORSBOARD_CAPTURE_SPECTROMETER_DATA_DATAID     	01+_TYPE_COMMAND+_SRASENSORS_BOARDNUMBER
#define RC_SRASENSORSBOARD_CAPTURE_SPECTROMETER_DATA_DATATYPE   	uint16_t	
#define RC_SRASENSORSBOARD_CAPTURE_SPECTROMETER_DATA_DATACOUNT  	1   //number of readings

//Science Light Control
#define RC_SRASENSORSBOARD_LIGHT_CONTROL_DATAID     	02+_TYPE_COMMAND+_SRASENSORS_BOARDNUMBER
#define RC_SRASENSORSBOARD_LIGHT_CONTROL_DATATYPE   	uint8_t	
#define RC_SRASENSORSBOARD_LIGHT_CONTROL_DATACOUNT  	1		
#define RC_SRASENSORSBOARD_LIGHT_CONTROL_ENABLED		1
#define RC_SRASENSORSBOARD_LIGHT_CONTROL_DISABLED		0

//Capture MPPC Data
#define RC_SRASENSORSBOARD_CAPTURE_MPCC_DATA_DATAID     	03+_TYPE_COMMAND+_SRASENSORS_BOARDNUMBER
#define RC_SRASENSORSBOARD_CAPTURE_MPCC_DATA_DATATYPE   	uint16_t	
#define RC_SRASENSORSBOARD_CAPTURE_MPCC_DATA_DATACOUNT  	1   //number of readings

///////////////////////////////////////////////////
//                LightingBoard                  //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//TCP/////
//Headlight Intensity
#define RC_LIGHTINGBOARD_SETLEDINTENS_DATAID            	00+_TYPE_COMMAND+_LIGHTINGBOARD_BOARDNUMBER
#define RC_LIGHTINGBOARD_SETLEDINTENS_DATATYPE          	uint8_t		//0-100%
#define RC_LIGHTINGBOARD_SETLEDINTENS_DATACOUNT        		1		

//LED RGB
#define RC_LIGHTINGBOARD_SETRGB_DATAID            			01+_TYPE_COMMAND+_LIGHTINGBOARD_BOARDNUMBER
#define RC_LIGHTINGBOARD_SETRGB_DATATYPE          			uint8_t		//0-255 rgb value
#define RC_LIGHTINGBOARD_SETRGB_DATACOUNT        			3			//[red][green][blue]

//LED Function
#define RC_LIGHTINGBOARD_LEDCMND_DATAID            			02+_TYPE_COMMAND+_LIGHTINGBOARD_BOARDNUMBER
#define RC_LIGHTINGBOARD_LEDCMND_DATATYPE          			uint8_t		//command number
#define RC_LIGHTINGBOARD_LEDCMND_DATACOUNT        			1			

//State Display
#define RC_LIGHTINGBOARD_STATE_DISPLAY_DATAID            			03+_TYPE_COMMAND+_LIGHTINGBOARD_BOARDNUMBER
#define RC_LIGHTINGBOARD_STATE_DISPLAY_DATATYPE          			uint8_t //command number
#define RC_LIGHTINGBOARD_STATE_DISPLAY_DATACOUNT        			1   //(bitmasked)		

///////////////////////////////////////////////////
//                ArmBoard                       //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//MoveToAngle
#define RC_ARMBOARD_MOVETOANGLE_DATAID      00+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_MOVETOANGLE_DATATYPE    int16_t	//deg-1
#define RC_ARMBOARD_MOVETOANGLE_DATACOUNT   6	//[J1][J2][J3][J4][J5][J6]
#define RC_ARMBOARD_MOVETOANGLE_HEADER		RC_ARMBOARD_MOVETOANGLE_DATAID,RC_ARMBOARD_MOVETOANGLE_DATACOUNT
#define RC_ARMBOARD_MOVETOANGLE_J1ENTRY		0
#define RC_ARMBOARD_MOVETOANGLE_J2ENTRY		1
#define RC_ARMBOARD_MOVETOANGLE_J3ENTRY		2
#define RC_ARMBOARD_MOVETOANGLE_J4ENTRY		3
#define RC_ARMBOARD_MOVETOANGLE_J5ENTRY		4
#define RC_ARMBOARD_MOVETOANGLE_J6ENTRY		5

//IK Absolute POS
#define RC_ARMBOARD_IKABSPOS_DATAID      	01+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_IKABSPOS_DATATYPE    	int16_t	//mA
#define RC_ARMBOARD_IKABSPOS_DATACOUNT  	6	//[X][Y][Z][P][[Y][R]
#define RC_ARMBOARD_IKABSPOS_HEADER			RC_ARMBOARD_IKABSPOS_DATAID,RC_ARMBOARD_IKABSPOS_DATACOUNT
#define RC_ARMBOARD_IKABSPOS_XENTRY			0
#define RC_ARMBOARD_IKABSPOS_YENTRY			1
#define RC_ARMBOARD_IKABSPOS_ZENTRY			2
#define RC_ARMBOARD_IKABSPOS_PITCH_ENTRY	3
#define RC_ARMBOARD_IKABSPOS_YAW_ENTRY	    4
#define RC_ARMBOARD_IKABSPOS_ROLL_ENTRY		5

//IK Rover Increment
#define RC_ARMBOARD_IKINCROV_DATAID      	02+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_IKINCROV_DATATYPE    	int16_t	
#define RC_ARMBOARD_IKINCROV_DATACOUNT  	6	//[X][Y][Z][P][[Y][R]
#define RC_ARMBOARD_IKINCROV_HEADER			RC_ARMBOARD_IKINCROV_DATAID,RC_ARMBOARD_IKINCROV_DATACOUNT
#define RC_ARMBOARD_IKINCROV_XENTRY			0
#define RC_ARMBOARD_IKINCROV_YENTRY			1
#define RC_ARMBOARD_IKINCROV_ZENTRY			2
#define RC_ARMBOARD_IKINCROV_PITCH_ENTRY	3
#define RC_ARMBOARD_IKINCROV_YAW_ENTRY		4
#define RC_ARMBOARD_IKINCROV_ROLL_ENTRY		5

//IK Wrist Increment
#define RC_ARMBOARD_IKINCWRIST_DATAID      	03+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_IKINCWRIST_DATATYPE    	int16_t	
#define RC_ARMBOARD_IKINCWRIST_DATACOUNT  	6	//[X][Y][Z][P][[Y][R]
#define RC_ARMBOARD_IKINCWRIST_HEADER		RC_ARMBOARD_IKINCWRIST_DATAID,RC_ARMBOARD_IKINCWRIST_DATACOUNT
#define RC_ARMBOARD_IKINCWRIST_XENTRY		0
#define RC_ARMBOARD_IKINCWRIST_YENTRY		1
#define RC_ARMBOARD_IKINCWRIST_ZENTRY		2
#define RC_ARMBOARD_IKINCWRIST_PITCH_ENTRY	3
#define RC_ARMBOARD_IKINCWRIST_YAW_ENTRY	4
#define RC_ARMBOARD_IKINCWRIST_ROLL_ENTRY	5

//MoveOpenLoop
#define RC_ARMBOARD_MOVEOPENLOOP_DATAID     	04+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_MOVEOPENLOOP_DATATYPE   	int16_t	//[-1000, 1000] %-1
#define RC_ARMBOARD_MOVEOPENLOOP_DATACOUNT  	9	//[J1][J2][J3][J4][J5][J6][Gripper 1][Nipper][Gripper 2]
#define RC_ARMBOARD_MOVEOPENLOOP_HEADER			RC_ARMBOARD_MOVEOPENLOOP_DATAID,RC_ARMBOARD_MOVEOPENLOOP_DATACOUNT
#define RC_ARMBOARD_MOVEOPENLOOP_J1ENTRY	    0
#define RC_ARMBOARD_MOVEOPENLOOP_J2ENTRY	    1
#define RC_ARMBOARD_MOVEOPENLOOP_J3ENTRY	    2
#define RC_ARMBOARD_MOVEOPENLOOP_J4ENTRY	    3
#define RC_ARMBOARD_MOVEOPENLOOP_J5ENTRY	    4
#define RC_ARMBOARD_MOVEOPENLOOP_J6ENTRY	    5
#define RC_ARMBOARD_MOVEOPENLOOP_GRIPPERENTRY	6
#define RC_ARMBOARD_MOVEOPENLOOP_NIPPERENTRY	7
#define RC_ARMBOARD_MOVEOPENLOOP_GRIPPER2ENTRY	8


//End Effector Actuation
#define RC_ARMBOARD_SOLENOID_DATAID     	05+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_SOLENOID_DATATYPE   	uint8_t	//[0=disable, 1=enable]
#define RC_ARMBOARD_SOLENOID_DATACOUNT  	1	//[Solenoid]
#define RC_ARMBOARD_SOLENOID_HEADER		    RC_ARMBOARD_SOLENOID_DATAID,RC_ARMBOARD_SOLENOID_DATACOUNT
#define RC_ARMBOARD_SOLENOID_DISABLE		0
#define RC_ARMBOARD_SOLENOID_ENABLE		    1

//Gripper Open Loop
#define RC_ARMBOARD_GRIPPER_DATAID     		06+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_GRIPPER_DATATYPE   		int16_t	//[-1000, 1000] %-1
#define RC_ARMBOARD_GRIPPER_DATACOUNT  		1
#define RC_ARMBOARD_GRIPPER_HEADER			RC_ARMBOARD_GRIPPER_DATAID,RC_ARMBOARD_GRIPPER_DATACOUNT

//Arm Commands
#define RC_ARMBOARD_ARMCOMMANDS_DATAID     	07+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_ARMCOMMANDS_DATATYPE   	uint8_t	//[-1000, 1000] %-1
#define RC_ARMBOARD_ARMCOMMANDS_DATACOUNT  	2
#define RC_ARMBOARD_ARMCOMMANDS_HEADER		RC_ARMBOARD_ARMCOMMANDS_DATAID,RC_ARMBOARD_ARMCOMMANDS_DATACOUNT
#define RC_ARMBOARD_ARMCOMMANDS_SWAPP_GRIPPERENTRY	 0
#define RC_ARMBOARD_POSITION_GETENTRY                1

#define RC_ARMBOARD_POSITION_DATAID     	8+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_POSITION_DATATYPE   	uint8_t	//[-1000, 1000] %-1
#define RC_ARMBOARD_POSITION_DATACOUNT  	1
#define RC_ARMBOARD_POSITION_HEADER		    RC_ARMBOARD_POSITION_DATAID,RC_ARMBOARD_POSITION_DATACOUNT
#define RC_ARMBOARD_POSITION_GET            1


//Forearm Motors
#define RC_ARMBOARD_FOREARM_DATAID     	9+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_FOREARM_DATATYPE   	int16_t	//[J5][J6][Gripper 1][Nipper][Gripper 2][-1000, 1000] %-1
#define RC_ARMBOARD_FOREARM_DATACOUNT  	5
#define RC_ARMBOARD_FOREARM_HEADER		RC_ARMBOARD_FOREARM_DATAID,RC_ARMBOARD_FOREARM_DATACOUNT
#define RC_ARMBOARD_FOREARM_J5ENTRY	0
#define RC_ARMBOARD_FOREARM_J6ENTRY	1
#define RC_ARMBOARD_FOREARM_GRIPPER	2
#define RC_ARMBOARD_FOREARM_NIPPER	3
#define RC_ARMBOARD_FOREARM_GRIPPER2 	4


//Bicep Motors
#define RC_ARMBOARD_BICEP_DATAID     	10+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_BICEP_DATATYPE   	int16_t	//[J1][J2][J3][J4][-1000, 1000] %-1
#define RC_ARMBOARD_BICEP_DATACOUNT  	4
#define RC_ARMBOARD_BICEP_HEADER		RC_ARMBOARD_BICEP_DATAID,RC_ARMBOARD_BICEP_DATACOUNT
#define RC_ARMBOARD_BICEP_J1ENTRY	0
#define RC_ARMBOARD_BICEP_J2ENTRY	1
#define RC_ARMBOARD_BICEP_J3ENTRY	2
#define RC_ARMBOARD_BICEP_J4ENTRY	3

//Forearm Angles
#define RC_ARMBOARD_FOREARM_ANGLE_DATAID     	11+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_FOREARM_ANGLE_DATATYPE   	int16_t	//[J5][J6][-1000, 1000] %-1
#define RC_ARMBOARD_FOREARM_ANGLE_DATACOUNT  	2
#define RC_ARMBOARD_FOREARM_ANGLE_HEADER		RC_ARMBOARD_FOREARM_ANGLE_DATAID,RC_ARMBOARD_FOREARM_ANGLE_DATACOUNT
#define RC_ARMBOARD_FOREARM_ANGLE_J5ENTRY	    0
#define RC_ARMBOARD_FOREARM_ANGLE_J6ENTRY	    1


//Bicep Angles
#define RC_ARMBOARD_BICEP_ANGLE_DATAID     	12+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_BICEP_ANGLE_DATATYPE   	int16_t	//[J1][J2][J3][J4][-1000, 1000] %-1
#define RC_ARMBOARD_BICEP_ANGLE_DATACOUNT  	4
#define RC_ARMBOARD_BICEP_ANGLE_HEADER		RC_ARMBOARD_BICEP_ANGLE_DATAID,RC_ARMBOARD_BICEP_ANGLE_DATACOUNT
#define RC_ARMBOARD_BICEP_ANGLE_J1ENTRY	0
#define RC_ARMBOARD_BICEP_ANGLE_J2ENTRY	1
#define RC_ARMBOARD_BICEP_ANGLE_J3ENTRY	2
#define RC_ARMBOARD_BICEP_ANGLE_J4ENTRY	3

//Tool Selection
#define RC_ARMBOARD_TOOLSELECTION_DATAID     	13+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_TOOLSELECTION_DATATYPE   	uint8_t	//[T1][T2][T3]
#define RC_ARMBOARD_TOOLSELECTION_DATACOUNT  	1
#define RC_ARMBOARD_TOOLSELECTION_HEADER		RC_ARMBOARD_TOOLSELECTION_DATAID,RC_ARMBOARD_TOOLSELECTION_DATACOUNT
#define RC_ARMBOARD_TOOLSELECTION_TOOL1 	    0
#define RC_ARMBOARD_TOOLSELECTION_TOOL2 	    1
#define RC_ARMBOARD_TOOLSELECTION_TOOL3 	    2

//End Effector Actuation
#define RC_ARMBOARD_LASER_DATAID     	14+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_LASER_DATATYPE   	uint8_t	//[0=disable, 1=enable]
#define RC_ARMBOARD_LASER_DATACOUNT  	1	//[Laser]
#define RC_ARMBOARD_LASER_HEADER		RC_ARMBOARD_LASER_DATAID,RC_ARMBOARD_LASER_DATACOUNT
#define RC_ARMBOARD_LASER_DISABLE		0
#define RC_ARMBOARD_LASER_ENABLE		1

//Do Limit Switches
#define RC_ARMBOARD_DOLS_DATAID     	15+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_DOLS_DATATYPE   	uint8_t	//[0=disable, 1=enable]
#define RC_ARMBOARD_DOLS_DATACOUNT  	1	//[Laser]
#define RC_ARMBOARD_DOLS_HEADER		    RC_ARMBOARD_LASER_DATAID,RC_ARMBOARD_LASER_DATACOUNT
#define RC_ARMBOARD_DOLS_DISABLE		0
#define RC_ARMBOARD_DOLS_ENABLE		    1

//Telemetry//////////////////////////////////////////////////////////////////////////////////////////////
//Motor Currents
#define RC_ARMBOARD_MOTORCURRENTS_DATAID     	00+_TYPE_TELEMETRY+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_MOTORCURRENTS_DATATYPE   	uint8_t	//A-1
#define RC_ARMBOARD_MOTORCURRENTS_DATACOUNT  	8			//[M1][M2][M3][M4][M5][M6][M7][M8]
#define RC_ARMBOARD_MOTORCURRENTS_HEADER		RC_ARMBOARD_MOTORCURRENTS_DATAID,RC_ARMBOARD_MOTORCURRENTS_DATACOUNT
#define	RC_ARMBOARD_MOTORCURRENTS_M1ENTRY		0
#define	RC_ARMBOARD_MOTORCURRENTS_M2ENTRY		1
#define	RC_ARMBOARD_MOTORCURRENTS_M3ENTRY		2
#define	RC_ARMBOARD_MOTORCURRENTS_M4ENTRY		3
#define	RC_ARMBOARD_MOTORCURRENTS_M5ENTRY		4
#define	RC_ARMBOARD_MOTORCURRENTS_M6ENTRY		5
#define	RC_ARMBOARD_MOTORCURRENTS_M7ENTRY		6
#define	RC_ARMBOARD_MOTORCURRENTS_M8ENTRY		7

//Motor Angles
#define RC_ARMBOARD_MOTORANGLES_DATAID     	01+_TYPE_TELEMETRY+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_MOTORANGLES_DATATYPE   	uint32_t	//deg-1
#define RC_ARMBOARD_MOTORANGLES_DATACOUNT  	6			//[M1][M2][M3][M4][M5][M6]
#define RC_ARMBOARD_MOTORANGLES_HEADER		RC_ARMBOARD_MOTORANGLES_DATAID,RC_ARMBOARD_MOTORCURRENTS_DATACOUNT
#define	RC_ARMBOARD_MOTORANGLES_M1ENTRY		0
#define	RC_ARMBOARD_MOTORANGLES_M2ENTRY		1
#define	RC_ARMBOARD_MOTORANGLES_M3ENTRY		2
#define	RC_ARMBOARD_MOTORANGLES_M4ENTRY		3
#define	RC_ARMBOARD_MOTORANGLES_M5ENTRY		4
#define	RC_ARMBOARD_MOTORANGLES_M6ENTRY		5

//Bicep Motor Angles
#define RC_ARMBOARD_BICEP_MOTORANGLES_DATAID     	02+_TYPE_TELEMETRY+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_BICEP_MOTORANGLES_DATATYPE   	uint32_t	//deg-1
#define RC_ARMBOARD_BICEP_MOTORANGLES_DATACOUNT  	4			//[M1][M2][M3][M4][M5][M6][M7][M8]
#define RC_ARMBOARD_BICEP_MOTORANGLES_HEADER		RC_ARMBOARD_BICEP_MOTORANGLES_DATAID,RC_ARMBOARD_BICEP_MOTORANGLES_DATAID
#define	RC_ARMBOARD_BICEP_MOTORANGLES_M1ENTRY		0
#define	RC_ARMBOARD_BICEP_MOTORANGLES_M2ENTRY		1
#define	RC_ARMBOARD_BICEP_MOTORANGLES_M3ENTRY		2
#define	RC_ARMBOARD_BICEP_MOTORANGLES_M4ENTRY		3

//Forearm Motor Angles
#define RC_ARMBOARD_FOREARM_MOTORANGLES_DATAID     	03+_TYPE_TELEMETRY+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_FOREARM_MOTORANGLES_DATATYPE   	uint32_t	//deg-1
#define RC_ARMBOARD_FOREARM_MOTORANGLES_DATACOUNT  	2			//[M1][M2][M3][M4][M5][M6][M7][M8]
#define RC_ARMBOARD_FOREARM_MOTORANGLES_HEADER		RC_ARMBOARD_FOREARM_MOTORANGLES_DATAID,RC_ARMBOARD_FOREARM_MOTORANGLES_DATAID
#define	RC_ARMBOARD_FOREARM_MOTORANGLES_M5ENTRY		0
#define	RC_ARMBOARD_FOREARM_MOTORANGLES_M6ENTRY		1

//Limit Switch Values
#define RC_ARMBOARD_LSVALUE_DATAID     		04+_TYPE_TELEMETRY+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_LSVALUE_DATATYPE   		uint8_t		//[LS1, LS2, LS3, LS4, LS5, LS6, LS7, LS8]
#define RC_ARMBOARD_LSVALUE_DATACOUNT  		2			//[MC1][MC2]
#define RC_ARMBOARD_LSVALUE_HEADER			RC_ARMBOARD_LSVALUE_DATAID,RC_ARMBOARD_LSVALUE_DATACOUNT
#define RC_ARMBOARD_LSVALUE_MC1ENTRY		0
#define RC_ARMBOARD_LSVALUE_MC2ENTRY		1

//IK Value
#define RC_ARMBOARD_IKVALUE_DATAID      	05+_TYPE_TELEMETRY+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_IKVALUE_DATATYPE    	int16_t	
#define RC_ARMBOARD_IKVALUE_DATACOUNT  		6	//[X][Y][Z][P][[Y][R]
#define RC_ARMBOARD_IKVALUE_HEADER			RC_ARMBOARD_IKVALUE_DATAID,RC_ARMBOARD_IKVALUE_DATACOUNT
#define RC_ARMBOARD_IKVALUE_XENTRY			0
#define RC_ARMBOARD_IKVALUE_YENTRY			1
#define RC_ARMBOARD_IKVALUE_ZENTRY			2
#define RC_ARMBOARD_IKVALUE_PITCH_ENTRY		3
#define RC_ARMBOARD_IKVALUE_YAW_ENTRY		4
#define RC_ARMBOARD_IKVALUE_ROLL_ENTRY		5

///////////////////////////////////////////////////
//                 AutonomyBoard                 //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////

//Telemetry////////////////////////////////////////////////////////////////////////////////////////////

#endif // RoveCommManifest_h
