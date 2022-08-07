void openn()
{
//    digitalWrite(dirPin, LOW);
// if(prev_state==0){
//
//
//        digitalWrite(stepPin,HIGH); 
//        prev_state=1;
////          Serial.println("High");
// }
//else if(prev_state==1)
//{
//        digitalWrite(stepPin,LOW);
//          prev_state=0;
////           Serial.println("low");
//} 
 digitalWrite(dirPin, LOW);
 digitalWrite(stepPin,HIGH); 
  digitalWrite(stepPin,LOW);


        Serial.println("Arms open");
  
}

void closee()
{
//  digitalWrite(dirPin, HIGH);
//if(prev_state==0){
//        digitalWrite(stepPin,HIGH); 
//          prev_state=1;
//}
//
//else if(prev_state==1){
//  digitalWrite(stepPin,LOW); 
//    prev_state=0;
//}
 digitalWrite(dirPin, HIGH);
 digitalWrite(stepPin,HIGH); 
  digitalWrite(stepPin,LOW);

      Serial.println("Arms close");

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
