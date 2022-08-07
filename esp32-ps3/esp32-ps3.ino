#include <Ps3Controller.h>
int lX,lY,rX,rY;

//#include<SoftwareSerial.h>
#include<HardwareSerial.h>//needed to create SUART Port
//SoftwareSerial SUART(4, 5); //SRX = DPin-4, STX = Dpin-5 RX/TX pin sod SUART Port
#define RXp2 16
#define TXp2 17
void send(int a,int b,int c,int d){
   Serial.print(a);
 Serial.print(" ");
 Serial.print(b);
 Serial.print(" ");
 Serial.print(c);
 Serial.print(" ");
 Serial.println(d);

if (a==-1){
  a=0;
}
if (b==-1){
  b=0;
}
if (c==-1){
  c=0;
}
if (d==-1){
  d=0;
}

    Serial2.print(a);
    Serial2.print(",");
    Serial2.print(b);
    Serial2.print(",");
    Serial2.print(c);
    Serial2.print(",");
    Serial2.print(d);
  
  Serial2.println("!");     
    
//    
//    Serial2.write(a);
//    Serial2.write(",");
//    Serial2.write(b);
//    Serial2.write(",");
//    Serial2.write(c);
//    Serial2.write(",");
//    Serial2.write(d);
//    Serial2.write("!");//newline character
         

}

void setup()
{
    Serial.begin(115200);
       Serial2.begin(19200, SERIAL_8N1, RXp2, TXp2);

    Ps3.begin("B4:E6:2D:E9:58:9D");


}

 
void loop()
{
  if (Ps3.isConnected()){
//    Serial.println("Controller connected!");
    
     lX =(Ps3.data.analog.stick.lx);
 lY =(Ps3.data.analog.stick.ly);
 rX =(Ps3.data.analog.stick.rx);
 rY =(Ps3.data.analog.stick.ry);

// Serial.print(lX);
// Serial.print(" ");
// Serial.print(lY);
// Serial.print(" ");
// Serial.print(rX);
// Serial.print(" ");
// Serial.println(rY);
send(lX,lY,rX,rY);
  }

}
