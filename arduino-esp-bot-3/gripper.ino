void highpulse()
{
  
  digitalWrite(stepPin,HIGH); 


        Serial.println("H");
        timer1=currentMicros;
  
}

void lowpulse()
{
  
  digitalWrite(stepPin,LOW); 


        Serial.println("L");
         timer2=currentMicros;
  
}
void openn(){
  digitalWrite(dirPin, LOW);
   if(currentMicros-timer1>=interval1 ){
    highpulse();
   }
   else if(currentMicros-timer2>=interval2 ){
    lowpulse();
   }
}

void closee(){
  digitalWrite(dirPin,HIGH);
   if(currentMicros-timer1>=interval1 ){
    highpulse();
   }
   else if(currentMicros-timer2>=interval2 ){
    lowpulse();
   }
}




void gripper()
{

   if(leftt==1 ){
    openn();
   }
   else if(rightt==1){
    closee();
   }

}
