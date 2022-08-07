/*---------------Defining libraries----------------*/
#include <PS3BT.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include<SharpIR.h>
#define IR A0
#define model 430
SharpIR SharpIR(IR, model);
#include <SPI.h>
USB Usb;   //USBHub Hub1(&Usb); // Some dongles have a hub inside
BTD Btd(&Usb);   // You have to create the Bluetooth Dongle instance like so
PS3BT PS3(&Btd);    // This will just create the instance
bool printTemperature, printAngle;
int dis=0;
/*----------------------variable declaration--------------------------*/
#define pwmL1 51
#define dirL1 13
#define pwmR1 49
#define dirR1 12


#define pwmR2 31
#define dirR2 3
#define pwmL2 29
#define dirL2 2

#define gpwm 3         
#define gdir 25

#define box_pne 42
#define gpne 44
#define leftpne 38
#define rightpne 28

int lx,ly,rx,ry;
int upc=0, gripc=0, lc=0, rc=0;
int speedm = 25;
int speed_fast = 85;
int speed_slow = 40;

/*-------------------------SETUP---------------------*/
void setup() {
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect 
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
/*-------------------------PINMODE------------------------*/
  pinMode(pwmL1, OUTPUT);
  pinMode(pwmL2, OUTPUT);
  pinMode(dirL1, OUTPUT);
  pinMode(dirL2, OUTPUT);
  pinMode(pwmR1, OUTPUT);
  pinMode(pwmR2, OUTPUT);
  pinMode(dirR1, OUTPUT);
  pinMode(dirR2, OUTPUT);
  pinMode(gdir, OUTPUT);
  pinMode(gpwm, OUTPUT);
  pinMode(box_pne, OUTPUT);
  pinMode(leftpne, OUTPUT);
  pinMode(rightpne, OUTPUT);
  
}
void loop() {
 
  Usb.Task(); // checks which button is pressed
  while(1)
  {
    Usb.Task(); 
    lx=PS3.getAnalogHat(LeftHatX);
    ly=PS3.getAnalogHat(LeftHatY);
    rx=PS3.getAnalogHat(RightHatX);
    ry=PS3.getAnalogHat(RightHatY);
    
  if (PS3.PS3Connected || PS3.PS3NavigationConnected) 
  { 
     dis=SharpIR.distance();
  Serial.println(dis);
  if (dis<29 &&dis>21){
    speed_fast=40;
  }
  else if(dis<21){
    speed_fast=0;
    while(1){
    motor_stop();
    }
  }
      /*-------------------BUTTON FUNCTIONS--------------*/
      if(PS3.getButtonClick(SELECT))
      {
        kill();
        Serial.println("Shut Down");
        break;
      }
 
   

      /*--------------WHEELS & NAVIGATION----------------*/
         
      else if (ly==0 && lx==127)
      {
        forward_fast();
      }
      else if(ly==255 && lx==127)
      {
        backward_fast();
      }
      else if(lx==0 && ly==127)
      {
        left_fast();
      }
      else if(lx==255 && ly==127)
      {
        right_fast();
        //Serial.print(lx);
      }
      else if(ry==0 && rx==127)
      {
        forward_slow();
      }
      else if(ry==255 && rx==127)
      {
        backward_slow();
      }
      else if(rx==0 && ry==127)
      {
        left_slow();
      }
      else if(rx==255 && ry==127)
      {
        right_slow();
      }
      /*----------------------------------- CLOCKWISE AND ANTICLOCKWISE AND DIAGONALS ------------------------------*/
  
      else if(PS3.getButtonPress(L1))
      {
        anticlockwise_slow();
      }
      else if(PS3.getButtonPress(R1))
      {
        clockwise_slow();
      }
      else if(PS3.getButtonPress(L2))
      {
        up_left_slow();
      }
      else if(PS3.getButtonPress(R2))
      {
        up_right_slow();
      }
      else
      {
        motor_stop();
      }
  /*-----------------------------------------DIAGONALS--------------------------------------*/
    /*  else if(lx==0 && ly==0)
      {
        up_left_fast();      // left forward fast
      }
      else if(lx==0 && ly==255)
      {
        down_left_fast();  // left reverse fast
      }
      else if(lx==255 && ly==0)
      {
        up_right_fast(); // right forward fast
      }
      else if(lx==255 && ly==255)
      {
        down_right_fast();  //  right reverse fast
      }
      else if(rx==0 && ry==0)
      {
        up_left_slow();  // left forward slow
      }
      else if(rx==0 && ry==255)
      {
        down_left_slow();  // left reverse slow
      }
      else if(rx==255 && ry==0)
      {
        up_right_slow();   // right forward slow
      }
      else if(rx==255 && ry==255)
      {
        down_right_slow();  // right reverse slow
      }
      */
      /*if (PS3.getButtonClick(PS))
      {
        Serial.print(F("\r\nPS"));
        PS3.disconnect();
        }*/
      }
      else
      {
        motor_stop();
      }
    }
  }
