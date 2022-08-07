#include <PS3BT.h>
#include <usbhub.h>
int countup=1,countdown=1;

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
int butval;
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


    if (PS3.getButtonClick(PS)) {
      Serial.print(F("\r\nPS"));
      PS3.disconnect();
    }
    else {
      while(PS3.getButtonClick(LEFT)) 
      {
        Serial.print(F("\r\nLEFT"));
      }

      if (PS3.getButtonClick(UP)) {countup++;
      if(countup%2==0)
      {
        digitalWrite(3,HIGH);
      }
      else
      {
        digitalWrite(3,LOW);
      }
        
        Serial.print(F("\r\nUp"));
        
      }
      
      if (PS3.getButtonClick(DOWN)) {
        countdown++;
        Serial.print(F("\r\nDown"));
        if(countdown%2==0)
      {
        digitalWrite(6,HIGH);
      }
      else
      {
        digitalWrite(6,LOW);
      }
        
      }
      

      
    }
}
