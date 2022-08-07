#define motor1 6
#define dir1 44
#define motor2 4
#define dir2 14

#define motor3 7
#define dir3 46
#define motor4 5
#define dir4 15

int val1,val2,in1,in2,in3,in4,a;
#include <PS3BT.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside

BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so
/* You can create the instance of the class in two ways */
PS3BT PS3(&Btd); // This will just create the instance
//PS3BT PS3(&Btd, 0x00, 0x15, 0x83, 0x3D, 0x0A, 0x57); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch

bool printTemperature, printAngle;

void setup() {
  pinMode(motor1,OUTPUT);
  pinMode(dir1,OUTPUT);
    pinMode(motor2,OUTPUT);
  pinMode(dir2,OUTPUT);
    pinMode(motor3,OUTPUT);
  pinMode(dir3,OUTPUT);
    pinMode(motor4,OUTPUT);
  pinMode(dir4,OUTPUT);
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
}
void loop() {
  Usb.Task();

  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
       val1=PS3.getAnalogHat(LeftHatY);
    if (val1 > 126) {
      if(val1>127)
      {digitalWrite(dir1,LOW);
      digitalWrite(dir4,LOW);
        in1=map(val1,127,255,0,100);
        analogWrite(motor1,in1);
        analogWrite(motor4,in1);
      }
        if(val1==127)
        {
          analogWrite(motor1,0);
          analogWrite(motor4,0);
        }
       
      }
     
 
     else
      {digitalWrite(dir1,HIGH);
      digitalWrite(dir4,HIGH);
        in2=map(val1,0,126,100,0);
        analogWrite(motor1,in2);
       analogWrite(motor4,in2);
        
      }
       Serial.print(F("\r\nLeftHatY: "));
     
      Serial.print(val1);
      
      val2=PS3.getAnalogHat(RightHatY);
       if (val2 > 126) {
      if(val2>127)
      {digitalWrite(dir2,LOW);
      digitalWrite(dir3,LOW);
        in3=map(val2,127,255,0,100);
        analogWrite(motor2,in3);
        analogWrite(motor3,in3);
      }
        if(val2==127)
        {
          analogWrite(motor2,0);
          analogWrite(motor3,0);
        }
       
      }
     
 
     else
      {digitalWrite(dir2,HIGH);
      digitalWrite(dir3,HIGH);
        in4=map(val2,0,126,100,0);
        analogWrite(motor2,in4);
       analogWrite(motor3,in4);
        
      }
       Serial.print(F("\r\nRightHatY: "));
     
      Serial.print(val2);
      
      
      
    }
  }
