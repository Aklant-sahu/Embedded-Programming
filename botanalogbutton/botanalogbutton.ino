#define motor1 6
#define dir1 44
#define motor2 4
#define dir2 14

#define motor3 7
#define dir3 46
#define motor4 5
#define dir4 15

int val1, val2, in1, in2, in3, in4, a;
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
  pinMode(motor1, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(dir4, OUTPUT);
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

  if (PS3.PS3Connected || PS3.PS3NavigationConnected)
  {if(PS3.getAnalogButton(L1)==0 && PS3.getAnalogButton(R1)==0 && PS3.getAnalogButton(L2)==0 && PS3.getAnalogButton(R2)==0)
  {
    digitalWrite(dir2, HIGH);
        digitalWrite(dir3, HIGH);
        digitalWrite(dir1, LOW);
        digitalWrite(dir4, LOW);
        analogWrite(motor1,0);
        analogWrite(motor4,0);
        analogWrite(motor2,0);
        analogWrite(motor3,0);
        Serial.println("rest");
        
  }
    else
    {
    if(PS3.getAnalogButton(L1)==255 && PS3.getAnalogButton(R1)==0 && PS3.getAnalogButton(L2)==0 && PS3.getAnalogButton(R2)==0)
    {digitalWrite(dir2, HIGH);
        digitalWrite(dir3, HIGH);
        digitalWrite(dir1, LOW);
        digitalWrite(dir4, LOW);
        analogWrite(motor1,0);
        analogWrite(motor4,0);
        analogWrite(motor2,100);
        analogWrite(motor3,100);
        Serial.println("north west");
        Serial.println(PS3.getAnalogButton(L1));

    }
      if(PS3.getAnalogButton(L1)==0 && PS3.getAnalogButton(R1)==255 && PS3.getAnalogButton(L2)==0 && PS3.getAnalogButton(R2)==0)
    {digitalWrite(dir1, HIGH);
        digitalWrite(dir4, HIGH);
        digitalWrite(dir2, LOW);
        digitalWrite(dir3, LOW);
        analogWrite(motor1,100);
        analogWrite(motor4,100);
        analogWrite(motor2,0);
        analogWrite(motor3,0);
        Serial.println("north east");
    }
          if(PS3.getAnalogButton(L1)==0 && PS3.getAnalogButton(R1)==0 && PS3.getAnalogButton(L2)>0 && PS3.getAnalogButton(R2)==0)
    {digitalWrite(dir1, HIGH);
        digitalWrite(dir4, LOW);
        digitalWrite(dir2, LOW);
        digitalWrite(dir3, LOW);
        analogWrite(motor1,100);
        analogWrite(motor4,100);
        analogWrite(motor2,0);
        analogWrite(motor3,0);
        Serial.println("anti clock");
    }
       if(PS3.getAnalogButton(L1)==0 && PS3.getAnalogButton(R1)==0 && PS3.getAnalogButton(L2)==0 && PS3.getAnalogButton(R2)>0)
    {digitalWrite(dir2, HIGH);
        digitalWrite(dir3, LOW);
        digitalWrite(dir1, LOW);
        digitalWrite(dir4, LOW);
        analogWrite(motor1,0);
        analogWrite(motor4,0);
        analogWrite(motor2,100);
        analogWrite(motor3,100);
        Serial.println("CLOCK");
    }
    if(PS3.getAnalogButton(L1)==255&&PS3.getAnalogButton(R1)==255)
    {digitalWrite(dir2, HIGH);
        digitalWrite(dir3, HIGH);
        digitalWrite(dir1, LOW);
        digitalWrite(dir4, LOW);
        analogWrite(motor1,100);
        analogWrite(motor4,100);
        analogWrite(motor2,0);
        analogWrite(motor3,0);
        Serial.println("SOUTH WEST");
    }
       if(PS3.getAnalogButton(L2)>100&&PS3.getAnalogButton(R2)>100 )
    {digitalWrite(dir2, LOW);
        digitalWrite(dir3, LOW);
        digitalWrite(dir1, LOW);
        digitalWrite(dir4, LOW);
        analogWrite(motor1,0);
        analogWrite(motor4,0);
        analogWrite(motor2,100);
        analogWrite(motor3,100);
        Serial.println("SOUTH WEST");
    }
    if((PS3.getAnalogButton(L1)>200&&PS3.getAnalogButton(L2)>200)||(PS3.getAnalogButton(R2)>200&&PS3.getAnalogButton(R1)>200)||(PS3.getAnalogButton(R2)>200&&PS3.getAnalogButton(L1)>200)||(PS3.getAnalogButton(L2)>200&&PS3.getAnalogButton(R1)>200))
    {
      Serial.println("invalid");
    }
  }
      
      
 
  }
}
  
