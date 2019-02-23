
/////////////////////
#include "RoveComm.h"

////////////////////////////////////////////////////////////////////////////////////////
uint8_t ip_4          = 131;

int     packet_data[15] = {        1,          2,          3,          4,          5,
                               65001,      65002,      65003,      65004,      65005,
                          2000000001, 2000000001, 2000000001, 2000000001, 2000000001, };

//////////////////////
void setup() 
{
  Serial.begin( 9600 );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // RoveComm 2019
  struct roveware::PackedPacket PackedPacket = roveware::packPacket( 65535, 15, DATA_TYPE::INT32_T, packet_data );

  Serial.println("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"); 
  Serial.print("RoveComm2019 PackedPacket:"); 
  Serial.print("  Version: 0x");         Serial.print( PackedPacket.bytes[ 0 ], HEX ); Serial.print(" ");
  Serial.print(", Data Id: 0x");         Serial.print( PackedPacket.bytes[ 1 ], HEX ); Serial.print(", 0x"); Serial.print(   PackedPacket.bytes[  2 ], HEX ); 
  Serial.print(", Data count: 0x");      Serial.print( PackedPacket.bytes[ 3 ], HEX );
  Serial.print(", Data type: 0x");       Serial.print( PackedPacket.bytes[ 4 ], HEX ); 

  Serial.println("Data:");
  for(int i=0; i <= (sizeof(int)*15) ; i++ )
  { 
    Serial.print(" 0x"); 
    Serial.print( PackedPacket.bytes[ 5 + i ], HEX ); 
    Serial.print(", "); 

    if( ( i == (sizeof(int)*5) ) || ( i == (sizeof(int)*10) ) )
    { Serial.println(); } 
  }

  Serial.println(); 
  Serial.println(); 

  struct RoveCommPacket UnpackedPacket = roveware::unpackPacket( PackedPacket.bytes, ip_4 );

  Serial.println("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"); 
  Serial.print("RoveComm2019 UnpackedPacket:"); 
  Serial.print("  Version: ");         Serial.print(   UnpackedPacket.version         ); 
  Serial.print(", Remote Ip4: ");      Serial.print(   UnpackedPacket.remote_ip       ); 
  Serial.print(", Data Id: ");         Serial.print(   UnpackedPacket.data_id         );
  Serial.print(", Data count: ");      Serial.println( UnpackedPacket.data_count      ); 
  
  Serial.println("Data : ");

  for( int i=0; i <UnpackedPacket.data_count; i++ )
  { 
    Serial.print( UnpackedPacket.data[ i ] ); 
    Serial.print(", "); 

    if( ( i == 5 ) || ( i == 10 ) )
    { Serial.println(); }
  }

  /* Todo Sys */
 
  Serial.println(); 
  Serial.println(); 
  Serial.println(); 
  Serial.println(); 

  delay(500);

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // RoveComm 2018
  struct roveware::atlas::PackedPacket PackedAtlasPacket = roveware::atlas::packPacket( 65535, sizeof(int)*15, (uint8_t*)packet_data );

  Serial.println("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"); 
  Serial.print("RoveCommAtlas PackedPacket:"); 
  Serial.print("  Version: 0x");         Serial.print( PackedAtlasPacket.bytes[ 0 ], HEX ); Serial.print(" ");
  Serial.print(", Sequence: 0x");        Serial.print( PackedAtlasPacket.bytes[ 1 ], HEX ); Serial.print(", 0x"); Serial.print(   PackedAtlasPacket.bytes[  2 ], HEX ); 
  Serial.print(", Flags: 0x");           Serial.print( PackedAtlasPacket.bytes[ 3 ], HEX );
  Serial.print(", Data Id: 0x");         Serial.print( PackedAtlasPacket.bytes[ 4 ], HEX ); Serial.print(", 0x"); Serial.print(   PackedAtlasPacket.bytes[  5 ], HEX ); 
  Serial.print(", Data byte count: 0x"); Serial.print( PackedAtlasPacket.bytes[ 6 ], HEX ); Serial.print(", 0x"); Serial.println( PackedAtlasPacket.bytes[  7 ], HEX );

  Serial.println("Data:");
  for(int i=0; i <= (sizeof(int)*15) ; i++ )
  { 
    Serial.print(" 0x"); 
    Serial.print( PackedAtlasPacket.bytes[ 8 + i ], HEX ); 
    Serial.print(", "); 

    if( ( i == (sizeof(int)*5) ) || ( i == (sizeof(int)*10) ) )
    { Serial.println(); } 
  }

  Serial.println(); 
  Serial.println(); 

  struct RoveCommAtlasPacket UnpackedAtlasPacket = roveware::atlas::unpackPacket( PackedAtlasPacket.bytes, ip_4 );

  Serial.println("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"); 
  Serial.print("RoveCommAtlas UnpackedPacket:"); 
  Serial.print("  Version: ");         Serial.print(   UnpackedAtlasPacket.version         ); 
  Serial.print(", Sequence: ");        Serial.print(   UnpackedAtlasPacket.sequence        ); 
  Serial.print(", Flags: ");           Serial.print(   UnpackedAtlasPacket.flags           ); 
  Serial.print(", Remote Ip4: ");      Serial.print(   UnpackedAtlasPacket.remote_ip       ); 
  Serial.print(", Data Id: ");         Serial.print(   UnpackedAtlasPacket.data_id         ); 
  Serial.print(", Data byte count: "); Serial.println( UnpackedAtlasPacket.data_byte_count );

  int* unpack_data = (int*)UnpackedAtlasPacket.data_bytes;
  
  Serial.println("Data : ");
  for(int i=0; i < 15; i++)
  { 
    Serial.print( unpack_data[ i ] ); 
    Serial.print(", "); 

    if( ( i == 5 ) || ( i == 10 ) )
    { Serial.println(); }
  }
 
   /* Todo Sys */

  struct roveware::atlas::PackedPacket PackedAtlasPacket   = roveware::atlas::packPacket(   roveware::atlasROVECOMM_SUBSCRIBE_REQUEST.DATA_ID, 0, 0 );
  struct RoveCommAtlasPacket           UnpackedAtlasPacket = roveware::atlas::unpackPacket( PackedAtlasPacket.bytes, ip_4 );

  Serial.print("RoveCommAtlas Subscribe request:"); 
  Serial.print("  Version: ");         Serial.print(   UnpackedAtlasPacket.version         ); 
  Serial.print(", Sequence: ");        Serial.print(   UnpackedAtlasPacket.sequence        ); 
  Serial.print(", Flags: ");           Serial.print(   UnpackedAtlasPacket.flags           ); 
  Serial.print(", Remote Ip4: ");      Serial.print(   UnpackedAtlasPacket.remote_ip       ); 
  Serial.print(", Data Id: ");         Serial.print(   UnpackedAtlasPacket.data_id         ); 
  Serial.print(", Data byte count: "); Serial.println( UnpackedAtlasPacket.data_byte_count );

  Serial.println(); 
  Serial.println(); 
  Serial.println(); 
  Serial.println(); 

  delay(500);
}