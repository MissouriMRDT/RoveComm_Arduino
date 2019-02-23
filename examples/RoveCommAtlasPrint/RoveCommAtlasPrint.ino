
#include "RoveComm.h"

RoveCommAtlasEthernet RoveComm; // 2019 dev

void setup() 
{
  pinMode(PN_1, OUTPUT);
  Serial.begin(   9600 );
  RoveComm.begin( 100 ); // Todo Eli/Andrew => RoveCommManifest.h
}

int i = 0;

void loop()
{
  if( i++ > 1000 )
  {
    //digitalWrite( PN_1, HIGH );
    RoveComm.writeTo(roveware::atlas::ROVECOMM_SUBSCRIBE_REQUEST.DATA_ID, 0, 0, roveware::atlas::IP::ARMBOARD );
    i = 0;
  }

  RoveCommAtlasPacket RoveCommPacket = RoveComm.read();

  if(RoveCommPacket.data_id != roveware::atlas::ROVECOMM_NO_RX.DATA_ID )
  {
    float seconds = millis() / 1000.0;

    Serial.print( "Read: " );
    Serial.print( "  Seconds : "  ); Serial.println( seconds ); 
    Serial.print( ", Remote Ip: " ); Serial.println( RoveCommPacket.remote_ip );
    Serial.print( ", Data   Id: " ); Serial.println( RoveCommPacket.data_id   );
    Serial.println( "Data: " );

    for( int i=0; i < RoveCommPacket.data_byte_count; i ++ )
    { Serial.print(   RoveCommPacket.data_bytes[ i ] );
      Serial.print( ", ");
    }
  }

  delay(1);
}