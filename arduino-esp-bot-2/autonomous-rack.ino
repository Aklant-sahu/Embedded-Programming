void autopickup()
{
  if((dist1-dist2>minerror || dist2-dist1>minerror) && (dist1>8 || dist2>9))
  {
rectify();
  }
  else{
      if (dist1>=mindist   ){
         if( ly<-40){
       prev_intake=0;
       intake();
     }
     
     else if (dist1 >=mindist+4){
        digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
  analogWrite(pwmL1,autospeed+30);
  analogWrite(pwmR1,autospeed+30);
  analogWrite(pwmL2, autospeed+30);
  analogWrite(pwmR2,autospeed+30);

  Serial.println("Towards rack");
     }
     else{
      digitalWrite(dirb1, LOW);
        analogWrite(pwmb1, autoint);
        digitalWrite(dirb2, LOW);
        analogWrite(pwmb2, autoint);
//        Serial.println("Hold Balls");
        digitalWrite(dirL1, LOW);
        
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
  analogWrite(pwmL1,autospeed+30);
  analogWrite(pwmR1,autospeed+30);
  analogWrite(pwmL2, autospeed+30);
  analogWrite(pwmR2,autospeed+30);

  Serial.println("Towards rack");
     }
       
      }
      else{
      
   while((ly<-40&& lx<bufneg && lx>bufpos) ||ly==0){
  fetch_data();
    parse_data(datain);  
    stopmotors();
      digitalWrite(dirb1, LOW);
        analogWrite(pwmb1, autoint);
        digitalWrite(dirb2, LOW);
        analogWrite(pwmb2, autoint);
        Serial.println("Hold Balls");
   }
    prev_intake=0;
       intake();
   
  }



  }
}

void rectify(){
   if( ly<-40){
       prev_intake=0;
       intake();
     }
     else{
  if(dist1-dist2>minerror){
      digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, HIGH);
   analogWrite(pwmL1,autospeed-20);
  analogWrite(pwmR1, autospeed-20);
  analogWrite(pwmL2,autospeed-20);
  analogWrite(pwmR2, autospeed-20);

    Serial.println("CLockwise Slow");
  }
  else if(dist2-dist1>minerror){
    
   digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
    analogWrite(pwmL1,autospeed-20);
  analogWrite(pwmR1,autospeed-20);
  analogWrite(pwmL2,autospeed-20);
  analogWrite(pwmR2,autospeed-20);

    Serial.println("Anti-CLockwise Slow");
  }
     }
 
}
