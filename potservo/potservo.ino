#include <Servo.h>
int val,valpos;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

float pos = 0;    // variable to store the servo position

void setup() {
  pinMode(A2,INPUT);
  myservo.attach(9);
  Serial.begin(9600);// attaches the servo on pin 9 to the servo object
}

void loop() {
  val=analogRead(A2);
  pos=map(val,0,1023,0,180);
  Serial.println(pos);
  myservo.write(pos);
  
  
}
