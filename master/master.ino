#include<SoftwareSerial.h>
int val;
SoftwareSerial mySerial(10,11);

char masterswitchdata;
void setup() {  
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  
  // put your setup code here, to run once:
  pinMode(3,INPUT);
  

  pinMode(6,INPUT);
   Serial.begin(19200);
   mySerial.begin(9600);
  

}

void loop() {
  
  val=digitalRead(3);
  mySerial.write(val);
 
  
  
  
  
  

}
