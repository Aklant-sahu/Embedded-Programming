#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
int masterdata;
char slaveswitchdata;
void setup() {
   pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  pinMode(3,OUTPUT);
  digitalWrite(3,LOW);

  pinMode(6,INPUT);
  
  Serial.begin(38400);
  mySerial.begin(9600);
  
  

}

void loop() {
  // put your main code here, to run repeatedly:
if (mySerial.available()>0)
{
 Serial.println(mySerial.read());
 masterdata=mySerial.read();
 if(masterdata==HIGH)
 {
  digitalWrite(3,HIGH);
 }
 else
 {
digitalWrite(3,LOW);
  
 }
}


}
