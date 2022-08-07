void autoposition()
{
     if( cir>0){
       prev_intake1=0;
  
     }
  else if((dist3-dist4>minerror || dist4-dist3>minerror))
  {
rectify1();
  }
  else{
      
      
     
     if (dist3 >=mindist){
      autospeed=8*dist3;
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
    

  }
}

void rectify1(){
   if( cir>0){
       prev_intake1=0;
  
     }
     else {

  if(dist3-dist4>0){
    autospeed=10*(dist3-dist4);
    digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
   analogWrite(pwmL1,autospeed);
  analogWrite(pwmR1, autospeed);
  analogWrite(pwmL2,autospeed);
  analogWrite(pwmR2, autospeed);
     Serial.println(autospeed);
    Serial.println("CLockwise Slow");
  }
  
  
     else if(dist4-dist3>0){
        autospeed=10*(dist4-dist3);


      digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, HIGH);
   analogWrite(pwmL1,autospeed);
  analogWrite(pwmR1, autospeed);
  analogWrite(pwmL2,autospeed);
  analogWrite(pwmR2, autospeed);
       Serial.println(autospeed);
    Serial.println("anti-CLockwise Slow1");
  }
//   else{
//     prev_intake1=0;
//   }
 
}
}
