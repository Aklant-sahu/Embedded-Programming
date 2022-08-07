#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int a,pos =0,i=0;    // variable to store the servo position

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
   myservo.write(0);
}

void loop() {
  
  /*Serial.println("Enter the position of servo between 0 to 180");
  while (Serial.available() == 0)
  {
  }
*/
for(i=1;i<=180;i++){
  
  myservo.write(i);
  delay(50);

  
}

}
