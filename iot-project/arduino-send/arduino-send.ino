#define echoPin 2 
#define trigPin 3 

#include <SoftwareSerial.h>
SoftwareSerial mySerial(4, 5);

// defines variables
long duration;
int distances=4; 
int threshold=4;
int sensorValue=0;
const int buzzer = 9;
int overflowing=0;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
  Serial.println("with Arduino UNO R3");
  pinMode(buzzer, OUTPUT);
   mySerial.begin(57600);
}
void loop() {

   if(distances<threshold){

//    Serial.println("overflow");
    overflowing=1;
    tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(100);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(50);  
   
  
   }
   else{
     overflowing=0;
   }



    
  
   
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distances = duration * 0.034 / 2; 
  

//  Serial.println(sensorValue);
  Serial.print("Distance: ");
  Serial.print(distances);
  Serial.print(" cm "); 
 Serial.print("threshold ");
  Serial.print(threshold);
    Serial.print(" cm "); 
     Serial.print("overflow ");
  Serial.println(overflowing);
    

    sensorValue = analogRead(A0);
     threshold=map(sensorValue,0,1023,5,20);

mySerial.print(distances); mySerial.print("A");
mySerial.print(threshold); mySerial.print("B");
mySerial.print(overflowing); mySerial.print("C");
mySerial.print("!");
delay(100);
}
