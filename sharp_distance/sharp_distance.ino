#include<SharpIR.h>
#define IR A0
#define model 430
SharpIR SharpIR(IR, model);
void setup() {
    // Sharp IR code for Robojax.com
 Serial.begin(9600);
 Serial.println("Robojax Sharp IR  ");
}

void loop() {
    // Sharp IR code for Robojax.com
 

  // takes the time before the loop on the library begins

  int dis=SharpIR.distance();  // this returns the distance to the object you're measuring

  // Sharp IR code for Robojax.com

  Serial.print("Mean distance: ");  // returns it to the serial monitor
  Serial.println(dis);
      delay(50);  
  //Serial.println(analogRead(A0));
 
     
}
