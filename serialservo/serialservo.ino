#include <Servo.h>

Servo myservo;
Servo myservo2;
// create servo object to control a servo
// twelve servo objects can be created on most boards

int a,pos = 0;    // variable to store the servo position

void setup() {
  
  myservo.attach(6);
  myservo2.attach(3);
  Serial.begin(115200);
   myservo.write(0);
   
}

void loop() {
  
  Serial.println("Enter the position of servo between 0 to 180");
  while (Serial.available() == 0)
  {
    myservo.write(pos);
    myservo2.write(180-pos);
  }
  pos = Serial.parseInt();
  Serial.println(pos);
 
  
  
  



}
