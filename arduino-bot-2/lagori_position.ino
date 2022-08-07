void autoposition()
{
  Serial.println("lagori position");
     if( cir>0){
       prev_intake1=0;
  
     }
  else if((dist3-dist4>minerror || dist4-dist3>minerror) && (dist3>6 && dist4>6))
  {
rectify1();
  }
  else{
      
      
     
     if (dist3 >mindist1){
      
        digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
  analogWrite(pwmL1,autospeed);
  analogWrite(pwmR1,autospeed);
  analogWrite(pwmL2, autospeed);
  analogWrite(pwmR2,autospeed);

  Serial.println("Towards rack");
     }
     else{
       stopmotors();
     }
    

  }
}

void rectify1(){
   if( cir>0){
       prev_intake1=0;
  
     }
     else {
if(dist3-dist4>0){
  if(dist3-dist4>=minerror3){
     digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
   analogWrite(pwmL1,autospeed);
  analogWrite(pwmR1, autospeed);
  analogWrite(pwmL2,autospeed);
  analogWrite(pwmR2, autospeed);

    Serial.println("CLockwise Slow1");
  }

   else if(dist3-dist4<minerror3 && dist3-dist4>=minerror2){
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
   analogWrite(pwmL1,autospeed-15);
  analogWrite(pwmR1, autospeed-15);
  analogWrite(pwmL2,autospeed-15);
  analogWrite(pwmR2, autospeed-15);

    Serial.println("CLockwise Slow2");
  }
 else if(dist3-dist4<minerror2){
    
 digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
     analogWrite(pwmL1,autospeed-30);
  analogWrite(pwmR1,autospeed-30);
  analogWrite(pwmL2,autospeed-30);
  analogWrite(pwmR2,autospeed-30);

    Serial.println("CLockwise Slow3");
  }
}
else if(dist4-dist3>0){
    if(dist4-dist3>=minerror3){
     digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, HIGH);
   analogWrite(pwmL1,autospeed);
  analogWrite(pwmR1, autospeed);
  analogWrite(pwmL2,autospeed);
  analogWrite(pwmR2, autospeed);

    Serial.println("anti-CLockwise Slow1");
  }
   else if(dist4-dist3<minerror3 && dist4-dist3>=minerror2){
        digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, HIGH);
    analogWrite(pwmL1,autospeed-15);
  analogWrite(pwmR1, autospeed-15);
  analogWrite(pwmL2,autospeed-15);
  analogWrite(pwmR2, autospeed-15);

       Serial.println("anti-CLockwise Slow2");
  }
  else if(dist4-dist3<minerror2){
    
      digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, HIGH);
       analogWrite(pwmL1,autospeed-30);
  analogWrite(pwmR1,autospeed-30);
  analogWrite(pwmL2,autospeed-30);
  analogWrite(pwmR2,autospeed-30);


       Serial.println("anti-CLockwise Slow3");
  }
}
  
     }
 
}
