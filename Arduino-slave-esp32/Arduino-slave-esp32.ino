#include <SoftwareSerial.h>                                                    //add the soft serial libray
#define rxpin 3                                                               //set the RX pin to pin 2
#define txpin 4                                                                //set the TX pin to pin 3
const int BUFFER_SIZE = 100;
char buf[BUFFER_SIZE];

SoftwareSerial myserial(rxpin, txpin);
void setup() {

Serial.begin(38400);
Serial2.begin(19200);
}

void loop() {

if (Serial2.available() > 0) {
//  Serial.print("available");
    // read the incoming bytes:
    int rlen = Serial2.readBytesUntil('!', buf, BUFFER_SIZE);

  for(int i = 0; i < rlen; i++)
  {
     Serial.print(buf[i]);

 }

Serial.println("");
  }



}
