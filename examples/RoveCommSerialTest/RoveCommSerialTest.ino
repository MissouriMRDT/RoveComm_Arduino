
#include "RoveCommSerial.h"

//RoveCommSerial MotorController;
RoveCommSerial MotorController1;
RoveCommSerial MotorController2;
RoveCommSerial MotorController3;
RoveCommSerial MotorController4;
RoveCommSerial MotorController5;
RoveCommSerial MotorController6;
RoveCommSerial MotorController7;

///////////////////////////////////////////////////////////////////////////////////////////////
// You can't use Serial 0 for MotorController pins AND the ICDI Usb Serial Monitor
void setup() {
  Serial.begin(9600); //MotorController.begin( &Serial, 9600); // PA_1=TX(0), PA_0=RX(0) =ICDI
   
  MotorController1.begin(&Serial1); // PB_1=TX(1), PB_0=RX(1)
  MotorController2.begin(&Serial2); // PA_7=TX(2), PA_6=RX(2)
  MotorController3.begin(&Serial3); // PA_5=TX(3), PA_4=RX(3)
  MotorController4.begin(&Serial4); // PK_1=TX(4), PK_0=RX(4)
  MotorController5.begin(&Serial5); // PC_7=TX(5), PC_6=RX(5)
  MotorController6.begin(&Serial6); // PP_1=TX(6), PP_0=RX(6)
  MotorController7.begin(&Serial7); // PC_5=TX(7), PC_4=RX(7)
  delay(10);
}

void loop() {//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  uint8_t  data[]     = { 1, 2, 3, 4, 5, 6, 7, 8 };
  uint8_t  data_count = sizeof(data) / sizeof(data[0]);
  
  Serial.print("MotorControllers Write All: "); 
  for(int i = 0; i < data_count; i++) 
  { Serial.print(data[i]); Serial.print(", "); } 
  Serial.println();
 
  MotorController1.write(1111, data_count, data); 
  MotorController2.write(2222, data_count, data);
  MotorController3.write(3333, data_count, data);
  MotorController4.write(4444, data_count, data);
  MotorController5.write(5555, data_count, data);
  MotorController6.write(6666, data_count, data);
  MotorController7.write(7777, data_count, data);

  if( MotorController1.available() ) {
    rovecomm_packet serial_1_packet = MotorController1.read();
    Serial.print("MotorController1 Read ");
    Serial.print(serial_1_packet.data_id); 
    Serial.print(": ");
    for(int i = 0; i < serial_1_packet.data_count; i++) 
    { Serial.print(serial_1_packet.data[i]); Serial.print(", "); }
    Serial.println();
  }

  if( MotorController2.available() ) {
    rovecomm_packet serial_2_packet = MotorController2.read();
    Serial.print("MotorController2 Read ");
    Serial.print(serial_2_packet.data_id); 
    Serial.print(": ");
    for(int i = 0; i < serial_2_packet.data_count; i++) 
    { Serial.print(serial_2_packet.data[i]); Serial.print(", "); }
  }

  if( MotorController3.available() ) {
    rovecomm_packet serial_3_packet = MotorController3.read();
    Serial.print("MotorController3 Read ");
    Serial.print(serial_3_packet.data_id); 
    Serial.print(": ");
    for(int i = 0; i < serial_3_packet.data_count; i++) 
    { Serial.print(serial_3_packet.data[i]); Serial.print(", "); }
    Serial.println();
  }

  if( MotorController4.available() ) {
    rovecomm_packet serial_4_packet = MotorController4.read();
    Serial.print("MotorController4 Read ");
    Serial.print(serial_4_packet.data_id); 
    Serial.print(": ");
    for(int i = 0; i < serial_4_packet.data_count; i++) 
    { Serial.print(serial_4_packet.data[i]); Serial.print(", "); }
    Serial.println();
  }

  if( MotorController5.available() ) {
    rovecomm_packet serial_5_packet = MotorController5.read();
    Serial.print("MotorController5 Read ");
    Serial.print(serial_5_packet.data_id); 
    Serial.print(": ");
    for(int i = 0; i < serial_5_packet.data_count; i++) 
    { Serial.print(serial_5_packet.data[i]); Serial.print(", "); }
    Serial.println();
  }

  if( MotorController6.available() ) {
    rovecomm_packet serial_6_packet = MotorController6.read();
    Serial.print("MotorController6 Read ");
    Serial.print(serial_6_packet.data_id);     
    Serial.print(": ");
    for(int i = 0; i < serial_6_packet.data_count; i++) 
    { Serial.print(serial_6_packet.data[i]); Serial.print(", "); }
    Serial.println();
  }

  if( MotorController7.available() ) {
    rovecomm_packet serial_7_packet = MotorController7.read();
    Serial.print("MotorController7 Read ");
    Serial.print(serial_7_packet.data_id); 
    Serial.print(": ");
    for(int i = 0; i < serial_7_packet.data_count; i++) 
    { Serial.print(serial_7_packet.data[i]); Serial.print(", "); }
    Serial.println();
  }
  
  delay(1000);
}