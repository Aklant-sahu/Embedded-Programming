#include <ps4.h>
#include <PS4Controller.h>
#include <ps4_int.h>


//
//#include <PS4Controller.h>
int lX,lY,rX,rY,cro,squ,tri,cir,upp,downn,leftt,rightt,ll1,ll2,rr1,rr2;
#include<HardwareSerial.h>
#define RXp2 16
#define TXp2 17
void send(int a,int b,int c,int d,int e,int f,int g,int h,int i,int j,int k,int l,int m,int n,int o,int p)
{


    Serial2.print(a); 
    Serial2.print("A");
    Serial2.print(b);
    Serial2.print("B");
    Serial2.print(c); 
    Serial2.print("C");
    Serial2.print(d);
    Serial2.print("D");
    Serial2.print(e);
    Serial2.print("E");
    Serial2.print(f);
    Serial2.print("F");
    Serial2.print(g);
    Serial2.print("G");
    Serial2.print(h);
    Serial2.print("H");
    Serial2.print(i);
    Serial2.print("I");
    Serial2.print(j);
    Serial2.print("J");
    Serial2.print(k);
    Serial2.print("K");
    Serial2.print(l);
    Serial2.print("L");
    Serial2.print(m);
    Serial2.print("M");
    Serial2.print(n);
    Serial2.print("N");
    Serial2.print(o);
    Serial2.print("O");
    Serial2.print(p);
    Serial2.print("P");
    Serial2.print("!");
    Serial.print(a); 

}

void setup()
{   Serial.begin(115200);
    Serial2.begin(115200, SERIAL_8N1, RXp2, TXp2);
    PS4.begin("30:83:98:52:5C:48");
    PS4.attachOnConnect(onConnect);
   
  Serial.println("Initialization ready!");
}
void onConnect(){
  Serial.print("Controller connected: ");
  Serial.println(PS4.isConnected());  
}

void loop()
{

  if (PS4.isConnected()){
    
 lX =(PS4.data.analog.stick.lx);
 lY =(PS4.data.analog.stick.ly);
 rX =(PS4.data.analog.stick.rx);
 rY =(PS4.data.analog.stick.ry);
// cro=(PS4.data.analog.button.cross);
// squ=(PS4.data.button.square);
// tri=(PS4.data.analog.button.triangle);
// cir=(PS4.data.button.circle);
// upp=(PS4.data.analog.button.up);
//downn=(PS4.data.analog.button.down);
// leftt=(PS4.data.analog.button.left);
// rightt=(PS4.data.analog.button.right);
  upp=(PS4.data.button.up);
downn=(PS4.data.button.down);
 leftt=(PS4.data.button.left);
 rightt=(PS4.data.button.right);
// 
//ll1=(PS4.data.analog.button.l1);
//rr1=(PS4.data.analog.button.r1);
//
//ll2=(PS4.data.analog.button.l2);
//rr2=(PS4.data.analog.button.r2);
// 
// Serial.println(ll1);
 
 
if (lX==-1){lX=0;}
if (lY==-1){lY=0;}
if (rX==-1){rX=0;}
if (rY==-1){rY=0;}
 Serial.print(lX); Serial.print("A");
    Serial.print(lY); Serial.print("B");
    Serial.print(rX); Serial.print("C");
    Serial.print(rY); Serial.print("D");
    Serial.print("\n");
//send(lX,lY,rX,rY,cro,squ,tri,cir,upp,downn,leftt,rightt,ll1,ll2,rr1,rr2);
  }

}
