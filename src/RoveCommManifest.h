#ifndef RoveCommManifest_h
#define RoveCommManifest_h
//RC:2.1

#include <stdint.h>
#include "RoveCommPacket.h"

#define RC_ROVECOMM_ETHERNET_UDP_PORT      	 11000 // todo Skelton Port Masking

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
        
#define RC_FOREARM_FOURTHOCTET                 128
#define RC_BICEP_FOURTHOCTET                   129
#define RC_OPEN_FOURTHOCTET                    130
#define RC_ARMBOARD_FOURTHOCTET                131
#define RC_POWERBOARD_FOURTHOCTET              132
#define RC_BMSBOARD_FOURTHOCTET                133
#define RC_DRIVEBOARD_FOURTHOCTET              134
#define RC_SHIMBLEBOARD_FOURTHOCTET    	   	   135
#define RC_NAVCAMERABOARD_FOURTHOCTET          136
#define RC_SRAACTUATIONBOARD_FOURTHOCTET       137
#define RC_SRASENSORSBOARD_FOURTHOCTET         138
#define RC_AUTONOMY_FOURTHOCTET                139
#define RC_BLACKBOX_FOURTHOCTET       		   140
#define RC_NETWORKTESTER_FOURTOCTET            141
#define RC_LIGHTINGBOARD_FOURTHOCTET 		   142
        
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
#define _NAVBOARD_BOARDNUMBER        05*1000    
#define _SHIMBLEBOARD_BOARDNUMBER    06*1000    
#define _LIGHTINGBOARD_BOARDNUMBER   07*1000    
#define _ARMBOARD_BOARDNUMBER        8*1000    
#define _SRAACTUATION_BOARDNUMBER    9*1000    
#define _SRASENSORS_BOARDNUMBER      10*1000
#define _AUTONOMY_BOARDNUMBER		 11*1000  

//Command Types
#define _TYPE_COMMAND     0*100
#define _TYPE_TELEMETRY   1*100


///////////////////////////////////////////////////
//             RoveComm System Id's              //
///////////////////////////////////////////////////
#define RC_ROVECOMM_PING_DATA_ID					1
#define RC_ROVECOMM_PING_REPLY_DATA_ID				2
#define RC_ROVECOMM_SUBSCRIBE_REQUEST_DATA_ID		3
#define	RC_ROVECOMM_UNSUBSCRIBE_REQUEST_DATA_ID 	4
#define	ROVECOMM_INVALID_VERSION_DATA_ID			5		

///////////////////////////////////////////////////
//                DriveBoard                     //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//Drive Left Right
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_DATAID            	00+_TYPE_COMMAND+_DRIVEBOARD_BOARDNUMBER
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_DATATYPE          	int16_t			// (-1000, 1000)-->(-100%, 100%)
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_DATACOUNT        	2				//[LeftSpeed, RightSpeed]
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_HEADER				RC_DRIVEBOARD_DRIVELEFTRIGHT_DATAID,RC_DRIVEBOARD_DRIVELEFTRIGHT_DATACOUNT
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_DRIVEMAXFORWARD   	1000
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_DRIVEMAXREVERSE   	-1000
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_DRIVEZERO         	0
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_LEFTSPEEDENTRY    	0
#define RC_DRIVEBOARD_DRIVELEFTRIGHT_RIGHTSPEEDENTRY    1
        
//Speed Ramp Value
#define RC_DRIVEBOARD_SPEEDRAMPVALUEs_DATAID            01+_TYPE_COMMAND+_DRIVEBOARD_BOARDNUMBER
#define RC_DRIVEBOARD_SPEEDRAMPVALUEs_DATATYPE          uint16_t		//ms to full speed
#define RC_DRIVEBOARD_SPEEDRAMPVALUEs_DATACOUNT        	1
#define RC_DRIVEBOARD_SPEEDRAMPVALUEs_HEADER			RC_DRIVEBOARD_SPEEDRAMPVALUEs_DATAID,RC_DRIVEBOARD_SPEEDRAMPVALUEs_DATACOUNT
      
//Drive Motors
#define RC_DRIVEBOARD_DRIVEMOTORS_DATAID            	02+_TYPE_COMMAND+_DRIVEBOARD_BOARDNUMBER
#define RC_DRIVEBOARD_DRIVEMOTORS_DATATYPE          	int16_t			// (-1000, 1000)-->(-100%, 100%)
#define RC_DRIVEBOARD_DRIVEMOTORS_DATACOUNT        	    6				//[M0, M1, M2, M3, M4, M5]
#define RC_DRIVEBOARD_DRIVEMOTORS_HEADER				RC_DRIVEBOARD_DRIVEMOTORS_DATAID,RC_DRIVEBOARD_DRIVEMOTORS_DATACOUNT
#define RC_DRIVEBOARD_DRIVEMOTORS_DRIVEMAXFORWARD   	1000
#define RC_DRIVEBOARD_DRIVEMOTORS_DRIVEMAXREVERSE   	-1000
#define RC_DRIVEBOARD_DRIVEMOTORS_DRIVEZERO         	0

//Telemetry////////////////////////////////////////////////////////////////////////////////////////////
//WatchDog Triggered
#define RC_DRIVEBOARD_WACHDOGTRIGGERED_DATAID           00+_TYPE_TELEMETRY+_DRIVEBOARD_BOARDNUMBER
#define RC_DRIVEBOARD_WACHDOGTRIGGERED_DATATYPE			uint8_t
#define RC_DRIVEBOARD_WACHDOGTRIGGERED_DATACOUNT       	1
#define RC_DRIVEBOARD_WACHDOGTRIGGERED_HEADER			RC_DRIVEBOARD_WACHDOGTRIGGERED_DATAID,RC_DRIVEBOARD_WACHDOGTRIGGERED_DATACOUNT
#define RC_DRIVEBOARD_WACHDOGTRIGGERED_TRIGGERED		1
#define RC_DRIVEBOARD_WACHDOGTRIGGERED_NOTTRIGGERED		0

///////////////////////////////////////////////////
//                BMSBoard                       //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//Software E-Stop
#define RC_BMSBOARD_SWESTOPs_DATAID            	00+_TYPE_COMMAND+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_SWESTOPs_DATATYPE          	uint8_t		//sec delay before re-activation, 0 to stay off until reboot
#define RC_BMSBOARD_SWESTOPs_DATACOUNT        	1		
#define RC_BMSBOARD_SWESTOPs_HEADER				RC_BMSBOARD_SWESTOPs_DATAID,RC_BMSBOARD_SWESTOPs_DATACOUNT		

//Telemetry//////////////////////////////////////////////////////////////////////////////////////////////
//Main I_Meas
#define RC_BMSBOARD_MAINIMEASmA_DATAID          00+_TYPE_TELEMETRY+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_MAINIMEASmA_DATATYPE        int32_t	//main current output mA
#define RC_BMSBOARD_MAINIMEASmA_DATACOUNT      	1
#define RC_BMSBOARD_MAINIMEASmA_HEADER			RC_BMSBOARD_MAINIMEASmA_DATAID,RC_BMSBOARD_MAINIMEASmA_DATACOUNT				

//Pack Cell V_Meas
#define RC_BMSBOARD_VMEASmV_DATAID            	01+_TYPE_TELEMETRY+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_VMEASmV_DATATYPE          	uint16_t	//[Pack_Out, C1-G, C2-1, C3-2, C4-3, C5-4, C6-5, C7-6, C8-7]
#define RC_BMSBOARD_VMEASmV_DATACOUNT        	9	
#define RC_BMSBOARD_VMEASmV_HEADER				RC_BMSBOARD_VMEASmV_DATAID,RC_BMSBOARD_VMEASmV_DATACOUNT
#define RC_BMSBOARD_VMEASmV_PACKENTRY			0			
#define RC_BMSBOARD_VMEASmV_C1ENTRY				1
#define RC_BMSBOARD_VMEASmV_C2ENTRY				2
#define RC_BMSBOARD_VMEASmV_C3ENTRY				3
#define RC_BMSBOARD_VMEASmV_C4ENTRY				4
#define RC_BMSBOARD_VMEASmV_C5ENTRY				5
#define RC_BMSBOARD_VMEASmV_C6ENTRY				6
#define RC_BMSBOARD_VMEASmV_C7ENTRY				7
#define RC_BMSBOARD_VMEASmV_C8ENTRY				8

//Temp_Meas
#define RC_BMSBOARD_TEMPMEASmDEGC_DATAID        02+_TYPE_TELEMETRY+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_TEMPMEASmDEGC_DATATYPE      uint16_t	//Temperature Reading in mDeg Celcius
#define RC_BMSBOARD_TEMPMEASmDEGC_DATACOUNT     1
#define RC_BMSBOARD_TEMPMEASmDEGC_HEADER		RC_BMSBOARD_TEMPMEASmDEGC_DATAID,RC_BMSBOARD_TEMPMEASmDEGC_DATACOUNT				

//Error Report
#define RC_BMSBOARD_ERROR_DATAID				03+_TYPE_TELEMETRY+_BMSBOARD_BOARDNUMBER
#define RC_BMSBOARD_ERROR_DATATYPE				uint8_t	
#define RC_BMSBOARD_ERROR_DATACOUNT				9	
#define RC_BMSBOARD_ERROR_HEADER				RC_BMSBOARD_ERROR_DATAID,RC_BMSBOARD_ERROR_DATACOUNT
#define RC_BMSBOARD_ERROR_NOERROR				0
#define RC_BMSBOARD_ERROR_UNDERVOLTAGE			1
#define RC_BMSBOARD_ERROR_OVERCURRENT 			2
#define	RC_BMSBOARD_ERROR_PINFAULT				3 //Pin Fault if a voltage measurment reads as 0V. Since it is unlikely a cell can physically reach 0V, it will bw assumed that the pin, trace, or component involved in the measurement is damaged. 
#define RC_BMSBOARD_ERROR_PACKENTRY				0
#define RC_BMSBOARD_ERROR_C1ENTRY				1
#define RC_BMSBOARD_ERROR_C2ENTRY				2
#define RC_BMSBOARD_ERROR_C3ENTRY				3
#define RC_BMSBOARD_ERROR_C4ENTRY				4
#define RC_BMSBOARD_ERROR_C5ENTRY				5
#define RC_BMSBOARD_ERROR_C6ENTRY				6
#define RC_BMSBOARD_ERROR_C7ENTRY				7
#define RC_BMSBOARD_ERROR_C8ENTRY				8

///////////////////////////////////////////////////
//                PowerBoard                     //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//Bus_Enabe
#define RC_POWERBOARD_BUSENABLE_DATAID          00+_TYPE_COMMAND+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_BUSENABLE_DATATYPE        uint8_t		//[Act, Log, Comm, 0 0000], [M1, M2, M3, M4, M5, M6, M7, Aux], [Enable/Disable]
#define RC_POWERBOARD_BUSENABLE_DATACOUNT       3		
#define RC_POWERBOARD_BUSENABLE_HEADER			RC_POWERBOARD_BUSENABLE_DATAID,RC_POWERBOARD_BUSENABLE_DATACOUNT		
#define RC_POWERBOARD_BUSENABLE_ENABLE			1
#define RC_POWERBOARD_BUSENABLE_DISABLE         0
#define RC_POWERBOARD_BUSENABLE_ACTBIT		   	0
#define RC_POWERBOARD_BUSENABLE_LOGBIT		   	1
#define RC_POWERBOARD_BUSENABLE_COMMBIT		   	2
#define RC_POWERBOARD_BUSENABLE_M1BIT		   	0
#define RC_POWERBOARD_BUSENABLE_M2BIT		   	1
#define RC_POWERBOARD_BUSENABLE_M3BIT		   	2
#define RC_POWERBOARD_BUSENABLE_M4BIT		   	3
#define RC_POWERBOARD_BUSENABLE_M5BIT		   	4
#define RC_POWERBOARD_BUSENABLE_M6BIT		   	5
#define RC_POWERBOARD_BUSENABLE_M7BIT		   	6
#define RC_POWERBOARD_BUSENABLE_AUXBIT		   	7
#define RC_POWERBOARD_BUSENABLE_ALCENTRY		0
#define RC_POWERBOARD_BUSENABLE_MOTORSENTRY		1

//Telemetry//////////////////////////////////////////////////////////////////////////////////////////////
//IMeas
#define RC_POWERBOARD_IMEASmA_DATAID            00+_TYPE_TELEMETRY+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_IMEASmA_DATATYPE          uint16_t	//[Act, Log, Comm, M1, M2, M3, M4, M5, M6, M7, Aux]
#define RC_POWERBOARD_IMEASmA_DATACOUNT         11	
#define RC_POWERBOARD_IMEASmA_HEADER			RC_POWERBOARD_IMEASmA_DATAID,RC_POWERBOARD_IMEASmA_DATACOUNT				
#define RC_POWERBOARD_IMEASmA_ACTENTRY			0
#define RC_POWERBOARD_IMEASmA_LOGENTRY			1
#define RC_POWERBOARD_IMEASmA_COMMENTRY			2
#define RC_POWERBOARD_IMEASmA_M1ENTRY			3
#define RC_POWERBOARD_IMEASmA_M2ENTRY			4
#define RC_POWERBOARD_IMEASmA_M3ENTRY			5
#define RC_POWERBOARD_IMEASmA_M4ENTRY			6
#define RC_POWERBOARD_IMEASmA_M5ENTRY			7
#define RC_POWERBOARD_IMEASmA_M6ENTRY			8
#define RC_POWERBOARD_IMEASmA_M7ENTRY			9
#define RC_POWERBOARD_IMEASmA_AUXENTRY			10

//Bus Enable
#define RC_POWERBOARD_BUSENABLED_DATAID			01+_TYPE_TELEMETRY+_POWERBOARD_BOARDNUMBER
#define RC_POWERBOARD_BUSENABLED_DATATYPE       uint8_t	//[Act, Log, Comm, 0 0000], [M1, M2, M3, M4, M5, M6, M7, Aux]
#define RC_POWERBOARD_BUSENABLED_DATACOUNT      2
#define RC_POWERBOARD_BUSENABLED_HEADER			RC_POWERBOARD_BUSENABLED_DATAID,RC_POWERBOARD_BUSENABLED_DATACOUNT			
#define RC_POWERBOARD_BUSENABLED_ENABLED   		1
#define RC_POWERBOARD_BUSENABLED_DISABLED       0		
#define RC_POWERBOARD_BUSENABLED_ACTBIT		   	0
#define RC_POWERBOARD_BUSENABLED_LOGBIT		   	1
#define RC_POWERBOARD_BUSENABLED_COMMBIT		2
#define RC_POWERBOARD_BUSENABLED_M1BIT		   	0
#define RC_POWERBOARD_BUSENABLED_M2BIT		   	1
#define RC_POWERBOARD_BUSENABLED_M3BIT		   	2
#define RC_POWERBOARD_BUSENABLED_M4BIT		   	3
#define RC_POWERBOARD_BUSENABLED_M5BIT		   	4
#define RC_POWERBOARD_BUSENABLED_M6BIT		   	5
#define RC_POWERBOARD_BUSENABLED_M7BIT		   	6
#define RC_POWERBOARD_BUSENABLED_AUXBIT		   	7
#define RC_POWERBOARD_BUSENABLED_ALCENTRY		0
#define RC_POWERBOARD_BUSENABLED_MOTORSENTRY	1

///////////////////////////////////////////////////
//                CameraBoard                    //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//Camera MUX
#define RC_CAMERABOARD_CAMMUX_DATAID            	00+_TYPE_COMMAND+_CAMERABOARD_BOARDNUMBER
#define RC_CAMERABOARD_CAMMUX_DATATYPE          	uint8_t
#define RC_CAMERABOARD_CAMMUX_DATACOUNT        		1		//(0-3) (Cam0-Cam3)
#define RC_CAMERABOARD_CAMMUX_HEADER				RC_CAMERABOARD_CAMMUX_DATAID,RC_CAMERABOARD_CAMMUX_DATACOUNT	
#define RC_CAMERABOARD_CAMMUX_ENABLED   			1
#define RC_CAMERABOARD_CAMMUX_DISABLED         		0

//Telemetry//////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////
//                NavigationBoard                //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//Calibrate IMU
#define RC_NAVBOARD_CALIBRATEIMU_DATAID            	00+_TYPE_COMMAND+_NAVBOARD_BOARDNUMBER
#define RC_NAVBOARD_CALIBRATEIMU_DATATYPE          	uint8_t		//calibration time ms
#define RC_NAVBOARD_CALIBRATEIMU_DATACOUNT        	1		
#define RC_NAVBOARD_CALIBRATEIMU_HEADER				RC_NAVBOARD_CALIBRATEIMU_DATAID,RC_NAVBOARD_CALIBRATEIMU_DATACOUNT		

//Set Declination
#define RC_NAVBOARD_SETDECLINATION_DATAID           01+_TYPE_COMMAND+_NAVBOARD_BOARDNUMBER
#define RC_NAVBOARD_SETDECLINATION_DATATYPE         int8_t		//declination(degrees
#define RC_NAVBOARD_SETDECLINATION_DATACOUNT        1		
#define RC_NAVBOARD_SETDECLINATION_HEADER			RC_NAVBOARD_SETDECLINATION_DATAID,RC_NAVBOARD_SETDECLINATION_DATACOUNT	

//Telemetry//////////////////////////////////////////////////////////////////////////////////////////////
//GPS Lat Lon
#define RC_NAVBOARD_GPSLATLON_DATAID        	00+_TYPE_TELEMETRY+_NAVBOARD_BOARDNUMBER
#define RC_NAVBOARD_GPSLATLON_DATATYPE      	int64_t	//Latitude longitude in udeg
#define RC_NAVBOARD_GPSLATLON_DATACOUNT			2	//[lat][lon]
#define RC_NAVBOARD_GPSLATLON_HEADER			RCNAVBOARD_GPSLATLON_DATAID,RC_NAVBOARD_GPSLATLON_DATACOUNT				
#define RC_NAVBOARD_GPSLATLON_LATENTRY			0
#define RC_NAVBOARD_GPSLATLON_LONENTRY			1

//IMU PYR
#define RC_NAVBOARD_IMUPYR_DATAID          		01+_TYPE_TELEMETRY+_NAVBOARD_BOARDNUMBER
#define RC_NAVBOARD_IMUPYR_DATATYPE        		int16_t	//PYR in radians
#define RC_NAVBOARD_IMUPYR_DATACOUNT			3		//[pitch][yaw][roll]
#define RC_NAVBOARD_IMUPYR_HEADER				RC_NAVBOARD_IMUPYR_DATAID,RC_NAVBOARD_IMUPYR_DATACOUNT				
#define RC_NAVBOARD_IMUPYR_PITCHENTRY			0
#define RC_NAVBOARD_IMUPYR_YAWENTRY				1
#define RC_NAVBOARD_IMUPYR_ROLLENTRY			2

//LIDAR INFO
#define RC_LIDAR_DISTANCE_DATAID				02+_TYPE_TELEMETRY+_NAVBOARD_BOARDNUMBER
#define RC_LIDAR_DISTANCE_DATATYPE			    uint16_t
#define RC_LIDAR_DISTANCE_DATACOUNT			    2
#define RC_LIDAR_DISTANCE_HEADER				RC_LIDAR_DISTANCE_DATAID,RC_LIDAR_DISTANCE_DATACOUNT
#define RC_LIDAR_DISTANCE_DISTANCEENTRY		    0
#define RC_LIDAR_DISTANCE_VALIDDENTRY		    1

//GPS Aditional Information
#define RC_NAVBOARD_GPSADD_DATAID				03+_TYPE_TELEMETRY+_NAVBOARD_BOARDNUMBER
#define RC_NAVBOARD_GPSADD_DATATYPE				uint8_t
#define RC_NAVBOARD_GPSADD_DATACOUNT			2
#define RC_NAVBOARD_GPSADD_HEADER				RC_NAVBOARD_GPSADD_DATAID,RC_NAVBOARD_GPSADD_DATACOUNT
#define RC_NAVBOARD_GPSADD_QUALITY				0
#define RC_NAVBOARD_GPSADD_COUNT				1

///////////////////////////////////////////////////
//                ShimbleBoard                   //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//Servo Increment
#define RC_SHIMBLEBOARD_SERVOINC_DATAID         00+_TYPE_COMMAND+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_SERVOINC_DATATYPE       int16_t	//Degrees
#define RC_SHIMBLEBOARD_SERVOINC_DATACOUNT		8		//[S1][S2][S3][S4][S5][S6][S7][S8]
#define RC_SHIMBLEBOARD_SERVOINC_HEADER			RC_SHIMBLEBOARD_SERVOINC_DATAID,RC_SHIMBLEBOARD_SERVOINC_DATACOUNT				
#define RC_SHIMBLEBOARD_SERVOINC_S1ENTRY		0
#define RC_SHIMBLEBOARD_SERVOINC_S2ENTRY		1
#define RC_SHIMBLEBOARD_SERVOINC_S3ENTRY		2
#define RC_SHIMBLEBOARD_SERVOINC_S4ENTRY		3
#define RC_SHIMBLEBOARD_SERVOINC_S5ENTRY		4
#define RC_SHIMBLEBOARD_SERVOINC_S6ENTRY		5
#define RC_SHIMBLEBOARD_SERVOINC_S7ENTRY		6
#define RC_SHIMBLEBOARD_SERVOINC_S8ENTRY		7

//Servo Absolute
#define RC_SHIMBLEBOARD_SERVOABSOLUTE_DATAID       01+_TYPE_COMMAND+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_SERVOABSOLUTE_DATATYPE     int16_t	//Degrees
#define RC_SHIMBLEBOARD_SERVOABSOLUTE_DATACOUNT		8		//[S1][S2][S3][S4][S5][S6][S7][S8]
#define RC_SHIMBLEBOARD_SERVOABSOLUTE_HEADER		RC_SHIMBLEBOARD_SERVOTOPOS_DATAID,RC_SHIMBLEBOARD_SERVOTOPOS_DATACOUNT				
#define RC_SHIMBLEBOARD_SERVOABSOLUTE_S1ENTRY		0
#define RC_SHIMBLEBOARD_SERVOABSOLUTE_S2ENTRY		1
#define RC_SHIMBLEBOARD_SERVOABSOLUTE_S3ENTRY		2
#define RC_SHIMBLEBOARD_SERVOABSOLUTE_S4ENTRY		3
#define RC_SHIMBLEBOARD_SERVOABSOLUTE_S5ENTRY		4
#define RC_SHIMBLEBOARD_SERVOABSOLUTE_S6ENTRY		5
#define RC_SHIMBLEBOARD_SERVOABSOLUTE_S7ENTRY		6
#define RC_SHIMBLEBOARD_SERVOABSOLUTE_S8ENTRY		7

//Main Gimbal Increment
#define RC_SHIMBLEBOARD_MAINGIMBALINC_DATAID        02+_TYPE_COMMAND+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_MAINGIMBALINC_DATATYPE      int16_t	//Degrees
#define RC_SHIMBLEBOARD_MAINGIMBALINC_DATACOUNT		2		//[Pan] [Tilt]
#define RC_SHIMBLEBOARD_MAINGIMBALINC_HEADER		RC_SHIMBLEBOARD_SERVOINC_DATAID,RC_SHIMBLEBOARD_SERVOINC_DATACOUNT				
#define RC_SHIMBLEBOARD_MAINGIMBALINC_PANENTRY		0
#define RC_SHIMBLEBOARD_MAINGIMBALINC_TILTENTRY		1

//Main Gimbal Abolute
#define RC_SHIMBLEBOARD_MAINGIMBALABS_DATAID       	03+_TYPE_COMMAND+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_MAINGIMBALABS_DATATYPE     	int16_t	//Degrees
#define RC_SHIMBLEBOARD_MAINGIMBALABS_DATACOUNT		2		//[Pan] [Tilt]
#define RC_SHIMBLEBOARD_MAINGIMBALABS_HEADER		RC_SHIMBLEBOARD_SERVOTOPOS_DATAID,RC_SHIMBLEBOARD_SERVOTOPOS_DATACOUNT				
#define RC_SHIMBLEBOARD_MAINGIMBALABS_PANENTRY		0
#define RC_SHIMBLEBOARD_MAINGIMBALABS_TILTENTRY		1

//Drive Gimbal Increment
#define RC_SHIMBLEBOARD_DRIVEGIMBALINC_DATAID       04+_TYPE_COMMAND+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_DRIVEGIMBALINC_DATATYPE     int16_t	//Degrees
#define RC_SHIMBLEBOARD_DRIVEGIMBALINC_DATACOUNT	2		//[Pan] [Tilt]
#define RC_SHIMBLEBOARD_DRIVEGIMBALINC_HEADER		RC_SHIMBLEBOARD_SERVOINC_DATAID,RC_SHIMBLEBOARD_SERVOINC_DATACOUNT				
#define RC_SHIMBLEBOARD_DRIVEGIMBALINC_PANENTRY		0
#define RC_SHIMBLEBOARD_DRIVEGIMBALINC_TILTENTRY	1

//Drive Gimbal Abolute
#define RC_SHIMBLEBOARD_DRIVEGIMBALABS_DATAID       05+_TYPE_COMMAND+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_DRIVEGIMBALABS_DATATYPE     int16_t	//Degrees
#define RC_SHIMBLEBOARD_DRIVEGIMBALABS_DATACOUNT	2		//[Pan] [Tilt]
#define RC_SHIMBLEBOARD_DRIVEGIMBALABS_HEADER		RC_SHIMBLEBOARD_SERVOTOPOS_DATAID,RC_SHIMBLEBOARD_SERVOTOPOS_DATACOUNT				
#define RC_SHIMBLEBOARD_DRIVEGIMBALABS_PANENTRY		0
#define RC_SHIMBLEBOARD_DRIVEGIMBALABS_TILTENTRY	1

//Servo to set position
#define RC_SHIMBLEBOARD_SERVOTOSETPOS_DATAID    06+_TYPE_COMMAND+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_SERVOTOSETPOS_DATATYPE  uint8_t	//set position
#define RC_SHIMBLEBOARD_SERVOTOSETPOS_DATACOUNT	8		//[S1][S2][S3][S4][S5][S6][S7][S8]
#define RC_SHIMBLEBOARD_SERVOTOSETPOS_HEADER	RC_SHIMBLEBOARD_SERVOTOSETPOS_DATAID,RC_SHIMBLEBOARD_SERVOTOSETPOS_DATACOUNT				
#define RC_SHIMBLEBOARD_SERVOTOSETPOS_S1ENTRY	0
#define RC_SHIMBLEBOARD_SERVOTOSETPOS_S2ENTRY	1
#define RC_SHIMBLEBOARD_SERVOTOSETPOS_S3ENTRY	2
#define RC_SHIMBLEBOARD_SERVOTOSETPOS_S4ENTRY	3
#define RC_SHIMBLEBOARD_SERVOTOSETPOS_S5ENTRY	4
#define RC_SHIMBLEBOARD_SERVOTOSETPOS_S6ENTRY	5
#define RC_SHIMBLEBOARD_SERVOTOSETPOS_S7ENTRY	6
#define RC_SHIMBLEBOARD_SERVOTOSETPOS_S8ENTRY	7 

//Telemetry//////////////////////////////////////////////////////////////////////////////////////////////
//Servo Position
#define RC_SHIMBLEBOARD_SERVOPOS_DATAID       	00+_TYPE_TELEMETRY+_SHIMBLEBOARD_BOARDNUMBER
#define RC_SHIMBLEBOARD_SERVOPOS_DATATYPE     	int16_t	//Degrees
#define RC_SHIMBLEBOARD_SERVOPOS_DATACOUNT		8		//[S1][S2][S3][S4][S5][S6][S7][S8]
#define RC_SHIMBLEBOARD_SERVOPOS_HEADER			RC_SHIMBLEBOARD_SERVOPOS_DATAID,RC_SHIMBLEBOARD_SERVOPOS_DATACOUNT				
#define RC_SHIMBLEBOARD_SERVOPOS_S1ENTRY		0
#define RC_SHIMBLEBOARD_SERVOPOS_S2ENTRY		1
#define RC_SHIMBLEBOARD_SERVOPOS_S3ENTRY		2
#define RC_SHIMBLEBOARD_SERVOPOS_S4ENTRY		3
#define RC_SHIMBLEBOARD_SERVOPOS_S5ENTRY		4
#define RC_SHIMBLEBOARD_SERVOPOS_S6ENTRY		5
#define RC_SHIMBLEBOARD_SERVOPOS_S7ENTRY		6
#define RC_SHIMBLEBOARD_SERVOPOS_S8ENTRY		7

///////////////////////////////////////////////////
//                LightingBoard                  //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//Headlight Intensity
#define RC_LIGHTINGBOARD_SETLEDINTENS_DATAID            	00+_TYPE_COMMAND+_LIGHTINGBOARD_BOARDNUMBER
#define RC_LIGHTINGBOARD_SETLEDINTENS_DATATYPE          	uint8_t		//0-100%
#define RC_LIGHTINGBOARD_SETLEDINTENS_DATACOUNT        		1		
#define RC_LIGHTINGBOARD_SETLEDINTENS_HEADER				RC_LIGHTINGBOARD_SETLEDINTENS_DATAID,RC_LIGHTINGBOARD_SETLEDINTENS_DATACOUNT

//LED RGB
#define RC_LIGHTINGBOARD_SETRGB_DATAID            			01+_TYPE_COMMAND+_LIGHTINGBOARD_BOARDNUMBER
#define RC_LIGHTINGBOARD_SETRGB_DATATYPE          			uint8_t		//0-255 rgb value
#define RC_LIGHTINGBOARD_SETRGB_DATACOUNT        			3			//[red][green][blue]
#define RC_LIGHTINGBOARD_SETRGB_HEADER						RC_LIGHTINGBOARD_SETRGB_DATAID,RC_LIGHTINGBOARD_SETRGB_DATACOUNT		
#define RC_LIGHTINGBOARD_SETRGB_REDENTRY					0
#define RC_LIGHTINGBOARD_SETRGB_GREENENTRY					1
#define RC_LIGHTINGBOARD_SETRGB_BLUEENTRY					2

//LED Function
#define RC_LIGHTINGBOARD_LEDCMND_DATAID            			02+_TYPE_COMMAND+_LIGHTINGBOARD_BOARDNUMBER
#define RC_LIGHTINGBOARD_LEDCMND_DATATYPE          			uint8_t		//command number
#define RC_LIGHTINGBOARD_LEDCMND_DATACOUNT        			1			
#define RC_LIGHTINGBOARD_LEDCMND_HEADER						RC_LIGHTINGBOARD_LEDCMND_DATAID,RC_LIGHTINGBOARD_LEDCMND_DATACOUNT		

//Telemetry//////////////////////////////////////////////////////////////////////////////////////////////

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
#define RC_ARMBOARD_MOVEOPENLOOP_DATAID     04+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_MOVEOPENLOOP_DATATYPE   int16_t	//[-1000, 1000] %-1
#define RC_ARMBOARD_MOVEOPENLOOP_DATACOUNT  8	//[J1][J2][J3][J4][J5][J6]
#define RC_ARMBOARD_MOVEOPENLOOP_HEADER		RC_ARMBOARD_MOVEOPENLOOP_DATAID,RC_ARMBOARD_MOVEOPENLOOP_DATACOUNT
#define RC_ARMBOARD_MOVEOPENLOOP_J1ENTRY	    0
#define RC_ARMBOARD_MOVEOPENLOOP_J2ENTRY	    1
#define RC_ARMBOARD_MOVEOPENLOOP_J3ENTRY	    2
#define RC_ARMBOARD_MOVEOPENLOOP_J4ENTRY	    3
#define RC_ARMBOARD_MOVEOPENLOOP_J5ENTRY	    4
#define RC_ARMBOARD_MOVEOPENLOOP_J6ENTRY	    5
#define RC_ARMBOARD_MOVEOPENLOOP_GRIPPERENTRY	6
#define RC_ARMBOARD_MOVEOPENLOOP_NIPPERENTRY	7


//End Effector Actuation
#define RC_ARMBOARD_ENDEFFECTOR_DATAID     	05+_TYPE_COMMAND+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_ENDEFFECTOR_DATATYPE   	uint8_t	//[0=disable, 1=enable]
#define RC_ARMBOARD_ENDEFFECTOR_DATACOUNT  	2	//[Laser][Solenoid]
#define RC_ARMBOARD_ENDEFFECTOR_HEADER		RC_ARMBOARD_ENDEFFECTOR_DATAID,RC_ARMBOARD_ENDEFFECTOR_DATACOUNT
#define RC_ARMBOARD_ENDEFFECTOR_DISABLE		0
#define RC_ARMBOARD_ENDEFFECTOR_ENABLE		0

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
#define RC_ARMBOARD_FOREARM_DATATYPE   	int16_t	//[J5][J6][-1000, 1000] %-1
#define RC_ARMBOARD_FOREARM_DATACOUNT  	3
#define RC_ARMBOARD_FOREARM_HEADER		RC_ARMBOARD_FOREARM_DATAID,RC_ARMBOARD_FOREARM_DATACOUNT
#define RC_ARMBOARD_FOREARM_J5ENTRY	0
#define RC_ARMBOARD_FOREARM_J6ENTRY	1
#define RC_ARMBOARD_FOREARM_GRIPPER	2


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
#define RC_ARMBOARD_BICEP_MOTORANGLES_HEADER		RC_ARMBOARD_BICEP_MOTORANGLES_DATAID,RC_ARMBOARD_BICEP_MOTORCURRENTS_DATACOUNT
#define	RC_ARMBOARD_BICEP_MOTORANGLES_M1ENTRY		0
#define	RC_ARMBOARD_BICEP_MOTORANGLES_M2ENTRY		1
#define	RC_ARMBOARD_BICEP_MOTORANGLES_M3ENTRY		2
#define	RC_ARMBOARD_BICEP_MOTORANGLES_M4ENTRY		3

//Forearm Motor Angles
#define RC_ARMBOARD_FOREARM_MOTORANGLES_DATAID     	03+_TYPE_TELEMETRY+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_FOREARM_MOTORANGLES_DATATYPE   	uint32_t	//deg-1
#define RC_ARMBOARD_FOREARM_MOTORANGLES_DATACOUNT  	2			//[M1][M2][M3][M4][M5][M6][M7][M8]
#define RC_ARMBOARD_FOREARM_MOTORANGLES_HEADER		RC_ARMBOARD_FOREARM_MOTORANGLES_DATAID,RC_ARMBOARD_FOREARM_MOTORCURRENTS_DATACOUNT
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

//Arm Fault
#define RC_ARMBOARD_ARMFAULT_DATAID      	06+_TYPE_TELEMETRY+_ARMBOARD_BOARDNUMBER
#define RC_ARMBOARD_ARMFAULT_DATATYPE    	int16_t	
#define RC_ARMBOARD_ARMFAULT_DATACOUNT  	1	//enum
#define RC_ARMBOARD_ARMFAULT_HEADER			RC_ARMBOARD_ARMFAULT_DATAID,RC_ARMBOARD_ARMFAULT_DATACOUNT

///////////////////////////////////////////////////
//                SRAActuationBoard              //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//Move Open Loop
#define RC_SRAACTBOARD_MOVEOPENLOOP_DATAID      00+_TYPE_COMMAND+RC_SRAACTUATIONBOARD_FOURTHOCTET
#define RC_SRAACTBOARD_MOVEOPENLOOP_DATATYPE    int16_t	//[-1000, 1000] %-1
#define RC_SRAACTBOARD_MOVEOPENLOOP_DATACOUNT  	4		//[M1, M2, M3, M4]
#define RC_SRAACTBOARD_MOVEOPENLOOP_HEADER		RC_SRAACTBOARD_MOVEOPENLOOP_DATAID,RC_SRAACTBOARD_MOVEOPENLOOP_DATACOUNT
#define	RC_SRAACTBOARD_MOVEOPENLOOP_M1ENTRY		0
#define	RC_SRAACTBOARD_MOVEOPENLOOP_M2ENTRY		1
#define	RC_SRAACTBOARD_MOVEOPENLOOP_M3ENTRY		2
#define	RC_SRAACTBOARD_MOVEOPENLOOP_M4ENTRY		3

//Move To Pos
#define RC_SRAACTBOARD_MOVETOPOS_DATAID      	01+_TYPE_COMMAND+RC_SRAACTUATIONBOARD_FOURTHOCTET
#define RC_SRAACTBOARD_MOVETOPOS_DATATYPE    	uint8_t	//Enum position
#define RC_SRAACTBOARD_MOVETOPOS_DATACOUNT  	1		//[M1]
#define RC_SRAACTBOARD_MOVETOPOS_HEADER			RC_SRAACTBOARD_MOVE_OPENLOOP_DATAID,RC_SRAACTBOARD_MOVE_OPENLOOP_DATACOUNT

//Telemetry//////////////////////////////////////////////////////////////////////////////////////////////
//Motor Currents
#define RC_SRAACTBOARD_MOTORCURRENTS_DATAID     00+_TYPE_TELEMETRY+RC_SRAACTUATIONBOARD_FOURTHOCTET
#define RC_SRAACTBOARD_MOTORCURRENTS_DATATYPE   uint8_t	//a-1
#define RC_SRAACTBOARD_MOTORCURRENTS_DATACOUNT  4		//[M1, M2, M3, M4]
#define RC_SRAACTBOARD_MOTORCURRENTS_HEADER		RC_SRAACTBOARD_MOTORCURRENTS_DATAID,RC_SRAACTBOARD_MOTORCURRENTS_DATACOUNT
#define	RC_SRAACTBOARD_MOTORCURRENTS_M1ENTRY	0
#define	RC_SRAACTBOARD_MOTORCURRENTS_M2ENTRY	1
#define	RC_SRAACTBOARD_MOTORCURRENTS_M3ENTRY	2
#define	RC_SRAACTBOARD_MOTORCURRENTS_M4ENTRY	3

//LS Enabled
#define RC_SRAACTBOARD_LSENABLED_DATAID     	01+_TYPE_TELEMETRY+RC_SRAACTUATIONBOARD_FOURTHOCTET
#define RC_SRAACTBOARD_LSENABLED_DATATYPE   	uint8_t	//[LS1, LS2, LS3, LS4, LS5, LS6, LS7, LS8]
#define RC_SRAACTBOARD_LSENABLED_DATACOUNT  	1		//[MC1]
#define RC_SRAACTBOARD_LSENABLED_HEADER			RC_SRAACTBOARD_MOTORCURRENTS_DATAID,RC_SRAACTBOARD_MOTORCURRENTS_DATACOUNT
#define RC_SRAACTBOARD_LSENABLED_ENABLED		1
#define RC_SRAACTBOARD_LSENABLED_DISABLED		0

///////////////////////////////////////////////////
//                SRASensorsBoard                //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//Spectrometer Run
#define RC_SRASENSORSBOARD_SPECTROMETERRUN_DATAID     	00+_TYPE_COMMAND+_SRASENSORS_BOARDNUMBER
#define RC_SRASENSORSBOARD_SPECTROMETERRUN_DATATYPE   	uint8_t	
#define RC_SRASENSORSBOARD_SPECTROMETERRUN_DATACOUNT  	1		
#define RC_SRASENSORSBOARD_SPECTROMETERRUN_HEADER		RC_SRASENSORSBOARD_SPECTROMETERRUN_DATAID,RC_SRASENSORSBOARD_SPECTROMETERRUN_DATACOUNT
#define RC_SRASENSORSBOARD_SPECTROMETERRUN_ENABLED		1
#define RC_SRASENSORSBOARD_SPECTROMETERRUN_DISABLED		0

//UV LED Enable
#define RC_SRASENSORSBOARD_UVLEDENABLE_DATAID     	01+_TYPE_COMMAND+_SRASENSORS_BOARDNUMBER
#define RC_SRASENSORSBOARD_UVLEDENABLE_DATATYPE   	uint8_t	
#define RC_SRASENSORSBOARD_UVLEDENABLE_DATACOUNT  	1		
#define RC_SRASENSORSBOARD_UVLEDENABLE_HEADER		RC_SRASENSORSBOARD_UVLEDENABLE_DATAID,RC_SRASENSORSBOARD_UVLEDENABLE_DATACOUNT
#define RC_SRASENSORSBOARD_UVLEDENABLE_ENABLED		1
#define RC_SRASENSORSBOARD_UVLEDENABLE_DISABLED		0

//Telemetry//////////////////////////////////////////////////////////////////////////////////////////////
//Sensor Data
#define RC_SRASENSORSBOARD_SENSORDATA_DATAID     	00+_TYPE_TELEMETRY+_SRASENSORS_BOARDNUMBER
#define RC_SRASENSORSBOARD_SENSORDATA_DATATYPE   	uint16_t	
#define RC_SRASENSORSBOARD_SENSORDATA_DATACOUNT  	5		//[AirT, AirM, SoilT, SoilM, Methane]	
#define RC_SRASENSORSBOARD_SENSORDATA_HEADER		RC_SRASENSORSBOARD_SENSORDATA_DATAID,RC_SRASENSORSBOARD_SENSORDATA_DATACOUNT
#define RC_SRASENSORSBOARD_SENSORDATA_AIRTENTRY		0
#define RC_SRASENSORSBOARD_SENSORDATA_AIRMENTRY		1
#define RC_SRASENSORSBOARD_SENSORDATA_SOILTENTRY	2
#define RC_SRASENSORSBOARD_SENSORDATA_SOILMENTRY	3
#define RC_SRASENSORSBOARD_SENSORDATA_METHANEENTRY	4

///////////////////////////////////////////////////
//                 AutonomyBoard                 //
///////////////////////////////////////////////////
//Commands//////////////////////////////////////////////////////////////////////////////////////////////
//Enable Autonomy
#define RC_AUTONOMYBOARD_ENABLEAUTONOMY_DATAID		00+_TYPE_COMMAND+_AUTONOMY_BOARDNUMBER
#define RC_AUTONOMYBOARD_ENABLEAUTONOMY_DATATPYE	int32_t
#define RC_AUTONOMYBOARD_ENABLEAUTONOMY_DATACOUNT	1
#define RC_AUTONOMYBOARD_ENABLEAUTONOMY_HEADER		RC_AUTONOMYBOARD_ENABLEAUTONOMY_DATAID,RC_AUTONOMYBOARD_ENABLEAUTONOMY_DATACOUNT

//Disable Autonomy
#define RC_AUTONOMYBOARD_DISABLEAUTONOMY_DATAID		01+_TYPE_COMMAND+_AUTONOMY_BOARDNUMBER
#define RC_AUTONOMYBOARD_DISABLEAUTONOMY_DATATYPE	int32_t
#define RC_AUTONOMYBOARD_DISABLEAUTONOMY_DATACOUNT	1
#define RC_AUTONOMYBOARD_DISABLEAUTONOMY_HEADER		RC_AUTONOMYBOARD_DISABLEAUTONOMY_DATAID,RC_AUTONOMYBOARD_DISABLEAUTONOMY_DATACOUNT

//Add Waypoint
#define RC_AUTONOMYBOARD_ADDWAYPOINT_DATAID			02+_TYPE_COMMAND+_AUTONOMY_BOARDNUMBER
#define RC_AUTONOMYBOARD_ADDWAYPOINT_DATATYPE		int32_t
#define RC_AUTONOMYBOARD_ADDWAYPOINT_DATACOUNT		2
#define RC_AUTONOMYBOARD_ADDWAYPOINT_HEADER			RC_AUTONOMYBOARD_ADDWAYPOINT_DATAID,RC_AUTONOMYBOARD_ADDWAYPOINT_DATACOUNT

//Clear Waypoints
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATAID		03+_TYPE_COMMAND+_AUTONOMY_BOARDNUMBER
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATATYPE	int32_t
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATACOUNT	1
#define RC_AUTONOMYBOARD_CLEARWAYPOINTS_HEADER		RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATAID,RC_AUTONOMYBOARD_CLEARWAYPOINTS_DATACOUNT

//Waypoint Reached? Telemetry?
//Telemetry////////////////////////////////////////////////////////////////////////////////////////////
//To be added, need to determine telemetry wanted/needed by RED for Autonomy and the format for it too.
#endif // RoveCommManifest_h
