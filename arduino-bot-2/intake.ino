void intake(){
  
      if(ll1>50){
       int val=map(ll1,50,255,0,spb);
        digitalWrite(dirb1, HIGH);
        analogWrite(pwmb1, val);
        digitalWrite(dirb2, HIGH);
        analogWrite(pwmb2, val);
        Serial.println("Release Balls");
     
        }
          else if(prev_intake==0){
      digitalWrite(dirb1, HIGH);
        analogWrite(pwmb1, 0);
        digitalWrite(dirb2, HIGH);
        analogWrite(pwmb2, 0);
        Serial.println("stop intake");

   }
}
