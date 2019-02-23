/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MRDT => TivaC1294/TivaC129E Launchpad
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ROVECOMM_MANIFEST_H
#define ROVECOMM_MANIFEST_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// todo Andrew?   => Notice the Port for Atlas was 11000 (not the 1100? that presently used in your branch)

#include <stdint.h>

///////////////////////////////////
const uint8_t ROVECOMM_VERSION = 2;

struct ROVECOMM_ID ////////////////////////////////////////////////////////////////////
{
  uint16_t DATA_ID    = 0;
  uint16_t DATA_TYPE  = 0; //DATA_TYPE::NO_DATA;
  uint16_t DATA_COUNT = 0;

  ROVECOMM_ID( uint16_t data_id,   uint16_t   data_type,   uint16_t    data_count ): 
               DATA_ID( data_id ), DATA_TYPE( data_type ), DATA_COUNT( data_count ) { }
};

namespace SUBNET ////////// 
{ const uint8_t IP_1 = 192; 
  const uint8_t IP_2 = 168;
  const uint8_t IP_3 = 1; } 

namespace IP ////////////////
{ enum { RED      = 100, 
         ARMBOARD = 131, }; }

namespace PORT //////////////////////////////////
{ const uint16_t ROVECOMM_ETHERNET_UDP = 11000; }

namespace BOARD /////////////////////////
{ enum { ROVECOMM_ID  =  65 * 1000,

         DRIVEBOARD    =  1 * 1000,
         BMSBOARD      =  2 * 1000,
         POWERBOARD    =  3 * 1000,
         CAMERABOARD   =  4 * 1000,
         NAVBOARD      =  5 * 1000,
         SHIMBLEBOARD  =  6 * 1000,
         LIGHTINGBOARD =  7 * 1000,
         ARMBOARD      =  8 * 1000,
         SRAACTUATION  =  9 * 1000,
         SRASENSORS    = 10 * 1000,
         OPENBOARD     = 11 * 1000, }; }

namespace DATA_TYPE ///////////////////////////
{ enum { INT8_T =0, UINT8_T =1,
         INT16_T=2, UINT16_T=3, 
         INT32_T=4, UINT32_T=5,
         FLOAT_T=6, BOOL_T  =7, NO_DATA=8, }; }

namespace COUNT ////////////////////////////////////////////////////////////////////////////
{ const uint8_t MAX_HEADER_BYTES  =5; // Todo Eli/Skelton/Andrew new packet numbers sign off
  const uint8_t MAX_DATA_BYTES    =255;
  const uint8_t MAX_SUBSCRIBER_IPS=10; }

namespace MSG ////////////////
{ enum { CMD   = 0 * 100, 
         TELEM = 1 * 100, 
         OPEN  = 2 * 100, 
         SYS   = 9 * 100, }; }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                        DATA_ID,                              DATA_TYPE               DATA_COUNT
const struct ROVECOMM_ID ROVECOMM_NO_RX               = { BOARD::ROVECOMM_ID + MSG::SYS + 1,    DATA_TYPE::NO_DATA,     0 };
const struct ROVECOMM_ID ROVECOMM_RX_ID_UNKNOWN       = { BOARD::ROVECOMM_ID + MSG::SYS + 2,    DATA_TYPE::NO_DATA,     0 };
const struct ROVECOMM_ID ROVECOMM_PING_REQUEST        = { BOARD::ROVECOMM_ID + MSG::SYS + 3,    DATA_TYPE::NO_DATA,     0 };
const struct ROVECOMM_ID ROVECOMM_PING_ACK            = { BOARD::ROVECOMM_ID + MSG::SYS + 4,    DATA_TYPE::NO_DATA,     0 };
const struct ROVECOMM_ID ROVECOMM_SUBSCRIBE_REQUEST   = { BOARD::ROVECOMM_ID + MSG::SYS + 5,    DATA_TYPE::NO_DATA,     0 };
const struct ROVECOMM_ID ROVECOMM_UNSUBSCRIBE_REQUEST = { BOARD::ROVECOMM_ID + MSG::SYS + 6,    DATA_TYPE::NO_DATA,     0 };
const struct ROVECOMM_ID ROVECOMM_INVALID_VERSION     = { BOARD::ROVECOMM_ID + MSG::SYS + 7,    DATA_TYPE::NO_DATA,     0 };

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TODO Andrew/Eli

  const struct ROVECOMM_ID CMD_ARMBOARD_ESTOP             = { BOARD::ARMBOARD + MSG::CMD     +   1,    DATA_TYPE::NO_DATA,     0 };
// etc...
// Todo should we move declerations to indivdualized component files (ie => ArmBoardManifst.h, DriveBoardManifest.h, etc...) ?

namespace   roveware ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{ namespace atlas
  {
    const uint8_t  ROVECOMM_VERSION           =    1;
    const uint16_t ROVECOMM_FLAGS_ACK_REQUEST = 0x01;

    namespace IP ///////////////
    { enum { RED     = 100, 
            ARMBOARD = 131, }; }
    
    namespace COUNT /////////////////////////
    { const uint8_t MAX_HEADER_BYTES = 5;
      const uint8_t MAX_DATA_BYTES   = 255; }

    namespace BOARD /////////////////
    { enum { ROVECOMM  = 0x0000,
             ARMBOARD  = 0x0300, }; }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                                    DATA_ID,                          DATA_TYPE              DATA_COUNT
    const struct ROVECOMM_ID    ROVECOMM_PING_REQUEST                 = { atlas::BOARD::ROVECOMM + 1,       DATA_TYPE::NO_DATA,    0 };
    const struct ROVECOMM_ID    ROVECOMM_PING_ACK                     = { atlas::BOARD::ROVECOMM + 2,       DATA_TYPE::NO_DATA,    0 };
    const struct ROVECOMM_ID    ROVECOMM_SUBSCRIBE_REQUEST            = { atlas::BOARD::ROVECOMM + 3,       DATA_TYPE::NO_DATA,    0 };
    const struct ROVECOMM_ID    ROVECOMM_UNSUBSCRIBE_REQUEST          = { atlas::BOARD::ROVECOMM + 4,       DATA_TYPE::NO_DATA,    0 };
    const struct ROVECOMM_ID    ROVECOMM_INVALID_VERSION              = { atlas::BOARD::ROVECOMM + 5,       DATA_TYPE::NO_DATA,    0 };

    const struct ROVECOMM_ID    ROVECOMM_NO_RX                        = { atlas::BOARD::ROVECOMM + 6,       DATA_TYPE::NO_DATA,    0 };
    const struct ROVECOMM_ID    ROVECOMM_RX_ID_UNKNOWN                = { atlas::BOARD::ROVECOMM + 7,       DATA_TYPE::NO_DATA,    0 };

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                                     DATA_ID,                          DATA_TYPE              DATA_COUNT
    const struct ROVECOMM_ID    CMD_ARMBOARD_ESTOP                     = { atlas::BOARD::ARMBOARD + 0x20,    DATA_TYPE::NO_DATA,    0 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_ENABLE_ALL                = { atlas::BOARD::ARMBOARD + 0x30,    DATA_TYPE::BOOL_T,     0 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_ENABLE_MAIN               = { atlas::BOARD::ARMBOARD + 0x31,    DATA_TYPE::BOOL_T,     0 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_ENABLE_SHOULDER_ROLL      = { atlas::BOARD::ARMBOARD + 0x32,    DATA_TYPE::BOOL_T,     0 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_ENABLE_SHOULDER_PITCH     = { atlas::BOARD::ARMBOARD + 0x33,    DATA_TYPE::BOOL_T,     0 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_ENABLE_ELBOW_PITCH        = { atlas::BOARD::ARMBOARD + 0x34,    DATA_TYPE::BOOL_T,     0 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_ENABLE_ELBOW_ROLL         = { atlas::BOARD::ARMBOARD + 0x35,    DATA_TYPE::BOOL_T,     0 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_ENABLE_WRIST_PITCH_ROLL   = { atlas::BOARD::ARMBOARD + 0x36,    DATA_TYPE::BOOL_T,     0 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_ENABLE_WRIST_PITCH_ROLL2  = { atlas::BOARD::ARMBOARD + 0x37,    DATA_TYPE::BOOL_T,     0 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_ENABLE_POKER              = { atlas::BOARD::ARMBOARD + 0x38,    DATA_TYPE::BOOL_T,     0 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_ENABLE_GRIPPER            = { atlas::BOARD::ARMBOARD + 0x39,    DATA_TYPE::BOOL_T,     0 };
    const struct ROVECOMM_ID    CMD_ENABLE_TELEM_STREAM_JOINT_DEGREES  = { atlas::BOARD::ARMBOARD + 0x67,    DATA_TYPE::NO_DATA,    0 };

    const struct ROVECOMM_ID    CMD_ARMBOARD_DRIVE_DECIPERCENT         = { atlas::BOARD::ARMBOARD + 0x27,    DATA_TYPE::INT16_T,    8 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_DRIVE_POKER_DECIPERCENT   = { atlas::BOARD::ARMBOARD + 0x60,    DATA_TYPE::INT16_T,    1 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_DRIVE_GRIPPER_DECIPERCENT = { atlas::BOARD::ARMBOARD + 0x64,    DATA_TYPE::INT16_T,    1 };

    const struct ROVECOMM_ID    CMD_ARMBOARD_MOVE_DEGREES              = { atlas::BOARD::ARMBOARD + 0x10,    DATA_TYPE::FLOAT_T,    6 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_MOVE_IK_XYZ               = { atlas::BOARD::ARMBOARD + 0x11,    DATA_TYPE::FLOAT_T,    6 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_MOVE_IK_dXYZ              = { atlas::BOARD::ARMBOARD + 0x12,    DATA_TYPE::FLOAT_T,    6 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_MOVE_WRIST_IK_dXYZ        = { atlas::BOARD::ARMBOARD + 0x13,    DATA_TYPE::FLOAT_T,    6 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_SET_IK_OPERATING_POINT    = { atlas::BOARD::ARMBOARD + 0x66,    DATA_TYPE::FLOAT_T,    6 };

    const struct ROVECOMM_ID    CMD_ARMBOARD_INVERT_GRIPPER_COMMANDS   = { atlas::BOARD::ARMBOARD + 0x65,    DATA_TYPE::BOOL_T,     0 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_ALLOW_OVERTRAVEL          = { atlas::BOARD::ARMBOARD + 0x81,    DATA_TYPE::NO_DATA,    0 };
    const struct ROVECOMM_ID    CMD_ARMBOARD_DISALLOW_OVERTRAVEL       = { atlas::BOARD::ARMBOARD + 0x80,    DATA_TYPE::NO_DATA,    0 };
    const struct ROVECOMM_ID    CMD_ARM_READ_MAIN_CURRENT_REQUEST      = { atlas::BOARD::ARMBOARD + 0x70,    DATA_TYPE::NO_DATA,    0 };
    const struct ROVECOMM_ID    CMD_ARM_READ_JOINT_DEGREES_REQUEST     = { atlas::BOARD::ARMBOARD + 0x19,    DATA_TYPE::NO_DATA,    0 };
    const struct ROVECOMM_ID    CMD_ARM_READ_IK_COORDINATES_REQUEST    = { atlas::BOARD::ARMBOARD + 0x28,    DATA_TYPE::NO_DATA,    0 };

  //const struct ROVECOMM_ID    TELEM_ARMBOARD_MILLAMPS ????
    const struct ROVECOMM_ID    TELEM_ARMBOARD_MILLIDEGREES            = { atlas::BOARD::ARMBOARD + 0x18,    DATA_TYPE::FLOAT_T,    6 };
  //const struct ROVECOMM_ID    TELEM_ARMBOARD_FAULT                   = { atlas::BOARD::ARMBOARD + 0x40,    DATA_TYPE::INT16_T,    1 };
  //const struct ROVECOMM_ID    TELEM_ARMBOARD_XYZ                     = { atlas::BOARD::ARMBOARD + 0x1A,    DATA_TYPE::FLOAT_T,    6 };// wat 6?
  } // end namespace
} //   end namespace ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // ROVECOMM_MANIFEST_H