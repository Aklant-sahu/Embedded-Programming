void openn()
{
  for(int i=0;i<10;i++){
  digitalWrite(dirPin, LOW);

        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(stepdelay); 
        digitalWrite(stepPin,LOW); 

        delayMicroseconds(1000-stepdelay);

        Serial.println("Arms open");
  }
}

void closee()
{for(int i=0;i<10;i++){
  digitalWrite(dirPin, HIGH);

        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(stepdelay); 
        digitalWrite(stepPin,LOW); 
        
        delayMicroseconds(1000-stepdelay);

      Serial.println("Arms close");
}
}
//
//
//
//void openn()
//{
//  for(int i=0;i<10;i++){
//  digitalWrite(dirPin, LOW);
//analogWrite(stepPin,127);
//
//        Serial.println("Arms open");
//  }
//}
//
//void closee()
//{for(int i=0;i<10;i++){
//  digitalWrite(dirPin, HIGH);
//analogWrite(stepPin,127);
//        
//      Serial.println("Arms close");
//}
//}

void intake(){
  
       if(rr1>50) {
        int val=map(rr1,50,255,0,spb);
        digitalWrite(dirb1, HIGH);
        analogWrite(pwmb1, val);
        digitalWrite(dirb2, HIGH);
        analogWrite(pwmb2, val);
        Serial.println("Hold Balls");
      
  }

        else if(ll1>50){
       int val=map(ll1,50,255,0,spb);
        digitalWrite(dirb1, LOW);
        analogWrite(pwmb1, val);
        digitalWrite(dirb2, LOW);
        analogWrite(pwmb2, val);
        Serial.println("Release Balls");
      
        }
          else{
      digitalWrite(dirb1, HIGH);
        analogWrite(pwmb1, 0);
        digitalWrite(dirb2, HIGH);
        analogWrite(pwmb2, 0);
        //Serial.println("stop intake");
   }
}

void gripper()
{

   if(leftt==1){
    openn();
   }
   else if(rightt==1){
    closee();
   }
   else if(ll1>=0 || rr1>=0){
    intake();
   }
 

}
