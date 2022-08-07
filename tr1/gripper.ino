void highpulse()
{
  
  digitalWrite(stepPin,HIGH); 
    digitalWrite(stepPin1,HIGH); 


        Serial.println("H");
        timer1=currentMicros;
  
}

void lowpulse()
{
  
  digitalWrite(stepPin,LOW); 
    digitalWrite(stepPin1,LOW); 



        Serial.println("L");
         timer2=currentMicros;
  
}
void openn(){
  digitalWrite(dirPin, LOW);
    digitalWrite(dirPin1, LOW);
 
if(currentMicros-timer1>=interval1 && prev_step_state== 'H' ){
    highpulse();
    prev_step_state='L';
   }
   else if(currentMicros-timer2>=interval2 && prev_step_state=='L'){
    lowpulse();
    prev_step_state='H';
   }
}

void closee(){
  digitalWrite(dirPin,HIGH);
    digitalWrite(dirPin1,HIGH);

   if(currentMicros-timer1>=interval1 && prev_step_state=='H' ){
    highpulse();
    prev_step_state='L';
   }
   else if(currentMicros-timer2>=interval2 && prev_step_state=='L'){
    lowpulse();
    prev_step_state='H';
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
