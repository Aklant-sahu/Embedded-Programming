/*
 Example sketch for the PS3 Bluetooth library - developed by Kristian Lauszus
 For more information visit my blog: http://blog.tkjelectronics.dk/ or
 send me an e-mail:  kristianl@tkjelectronics.com
 */
int val1,val2,in1,in2,a;
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
  pinMode(3,OUTPUT);
  pinMode(6,OUTPUT);
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
       val1=PS3.getAnalogHat(LeftHatX);
    if (val1 > 126) {
      if(val1>127)
      {
        in1=map(val1,127,255,0,255);
        analogWrite(3,in1);
        analogWrite(6,0);
      }
        if(val1==127)
        {
          analogWrite(6,0);
          analogWrite(3,0);
        }
       
      }
     
 
     else
      {
        in2=map(val1,0,126,255,0);
        analogWrite(6,in2);
       analogWrite(3,0);
        
      }
       Serial.print(F("\r\nLeftHatX: "));
     
      Serial.print(val1);
      Serial.print(F("\tLeftHatY: "));
      val2=PS3.getAnalogHat(LeftHatY);
      
      Serial.print(val2);
      
    }
  }

    
