#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
char slavedata;
char masterswitchdata;
void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  digitalWrite(3,LOW);

  pinMode(6,INPUT);
   Serial.begin(19200);
   mySerial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
if (mySerial.available()>0)
{
  slavedata=mySerial.read();
}
if(slavedata=='1')
{
   digitalWrite(3,HIGH);
}
else if(slavedata=='0')
{
   digitalWrite(3,LOW);
}
masterswitchdata=digitalRead(6);
if(masterswitchdata==HIGH)
{
  mySerial.write('1');
    
}
else
{
  mySerial.write('0');
}


}
