#include <HardwareSerial.h>
HardwareSerial mySerial(2);
String val=" ";

void setup() {
  // put your setup code here, to run once:
//Serial.begin(9600);
//Serial2.begin(19200);
Serial.begin(115200);
}

void loop() {
  
  // put your main code here, to run repeatedly:
//  while (Serial2.available()!=0){
//    val=Serial2.readString();
//    Serial.println("message recieved");
//
//  }
//  Serial.println(val);

}
