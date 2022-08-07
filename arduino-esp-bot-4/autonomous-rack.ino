void autopickup()
{

  Serial.println("Ball rack");
   if( ly<-40){
       prev_intake=0;
       intake();
     }
  else if((dist1-dist2>minerror || dist2-dist1>minerror) && (dist1>20 && dist2>20))
  {
rectify();
  }
  else{
      if (dist1>=mindist   ){
        
     
     if (dist1 >=mindist+4){
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
      digitalWrite(dirb1, LOW);
        analogWrite(pwmb1, autoint);
        digitalWrite(dirb2, LOW);
        analogWrite(pwmb2, autoint);
//        Serial.println("Hold Balls");
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
     else {
      if(dist1-dist2>minerror){
       
//  if(dist1-dist2>=minerror3){
//   digitalWrite(dirL1, HIGH);
//  digitalWrite(dirR1, LOW);
//  digitalWrite(dirL2, HIGH);
//  digitalWrite(dirR2, LOW);
//   analogWrite(pwmL1,autospeed);
//  analogWrite(pwmR1, autospeed);
//  analogWrite(pwmL2,autospeed);
//  analogWrite(pwmR2, autospeed);
//
//    Serial.println("CLockwise Slow1");
//  }
//   else if(dist1-dist2<minerror3 && dist1-dist2>=minerror2){
//  digitalWrite(dirL1, HIGH);
//  digitalWrite(dirR1, LOW);
//  digitalWrite(dirL2, HIGH);
//  digitalWrite(dirR2, LOW);
//   analogWrite(pwmL1,autospeed-15);
//  analogWrite(pwmR1, autospeed-15);
//  analogWrite(pwmL2,autospeed-15);
//  analogWrite(pwmR2, autospeed-15);
//
//    Serial.println("CLockwise Slow2");
//  }
//  else if(dist1-dist2<minerror2){
//    
// digitalWrite(dirL1, HIGH);
//  digitalWrite(dirR1, LOW);
//  digitalWrite(dirL2, HIGH);
//  digitalWrite(dirR2, LOW);
//    analogWrite(pwmL1,autospeed-30);
//  analogWrite(pwmR1,autospeed-30);
//  analogWrite(pwmL2,autospeed-30);
//  analogWrite(pwmR2,autospeed-30);
//
//    Serial.println("CLockwise Slow3");
//  }

 digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
    analogWrite(pwmL1,autospeed-20);
  analogWrite(pwmR1,autospeed-20);
  analogWrite(pwmL2,autospeed-20);
  analogWrite(pwmR2,autospeed-20);

    Serial.println("CLockwise Slow1");
      }
      else if(dist2-dist1>minerror){
        
//  
//      if(dist2-dist1>=minerror3){
//     digitalWrite(dirL1, LOW);
//  digitalWrite(dirR1, HIGH);
//  digitalWrite(dirL2, LOW);
//  digitalWrite(dirR2, HIGH);
//   analogWrite(pwmL1,autospeed);
//  analogWrite(pwmR1, autospeed);
//  analogWrite(pwmL2,autospeed);
//  analogWrite(pwmR2, autospeed);
//
//    Serial.println("anti-CLockwise Slow1");
//  }
//   else if(dist2-dist1<minerror3 && dist2-dist1>=minerror2){
//        digitalWrite(dirL1, LOW);
//  digitalWrite(dirR1, HIGH);
//  digitalWrite(dirL2, LOW);
//  digitalWrite(dirR2, HIGH);
//     analogWrite(pwmL1,autospeed-15);
//  analogWrite(pwmR1, autospeed-15);
//  analogWrite(pwmL2,autospeed-15);
//  analogWrite(pwmR2, autospeed-15);
//
//       Serial.println("anti-CLockwise Slow2");
//  }
//  else if(dist2-dist1<minerror2){
//    
//      digitalWrite(dirL1, LOW);
//  digitalWrite(dirR1, HIGH);
//  digitalWrite(dirL2, LOW);
//  digitalWrite(dirR2, HIGH);
// analogWrite(pwmL1,autospeed-30);
//  analogWrite(pwmR1,autospeed-30);
//  analogWrite(pwmL2,autospeed-30);
//  analogWrite(pwmR2,autospeed-30);
//
//
//       Serial.println("anti-CLockwise Slow3");
//  }

    digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, HIGH);
      analogWrite(pwmL1,autospeed-20);
  analogWrite(pwmR1,autospeed-20);
  analogWrite(pwmL2,autospeed-20);
  analogWrite(pwmR2,autospeed-20);
      }
  
     }
 
}


//void autopickup()
//{
//   if( ly<-40){
//       prev_intake=0;
//       intake();
//     }
//  else if((dist1-dist2>minerror || dist2-dist1>minerror) && (dist1>6 && dist2>6))
//  {
//rectify();
//  }
//  else{
//      if (dist1>=mindist   ){
//        
//     
//     if (dist1 >=mindist+4){
//      autospeed=10*dist1;
//  digitalWrite(dirL1, LOW);
//  digitalWrite(dirR1, HIGH);
//  digitalWrite(dirL2, HIGH);
//  digitalWrite(dirR2, LOW);
//  analogWrite(pwmL1,autospeed);
//  analogWrite(pwmR1,autospeed);
//  analogWrite(pwmL2, autospeed);
//  analogWrite(pwmR2,autospeed);
//
//  Serial.println("Towards rack");
//     }
//     else{
//
//       autospeed=10*dist1;
//      digitalWrite(dirb1, LOW);
//        analogWrite(pwmb1, autoint);
//        digitalWrite(dirb2, LOW);
//        analogWrite(pwmb2, autoint);
////        Serial.println("Hold Balls");
//        digitalWrite(dirL1, LOW);
//        
//  digitalWrite(dirR1, HIGH);
//  digitalWrite(dirL2, HIGH);
//  digitalWrite(dirR2, LOW);
//  analogWrite(pwmL1,autospeed);
//  analogWrite(pwmR1,autospeed);
//  analogWrite(pwmL2, autospeed);
//  analogWrite(pwmR2,autospeed);
//
//  Serial.println("Towards rack");
//     }
//       
//      }
//      else{
//      
//   while((ly<-40&& lx<bufneg && lx>bufpos) ||ly==0){
//  fetch_data();
//    parse_data(datain);  
//    stopmotors();
//      digitalWrite(dirb1, LOW);
//        analogWrite(pwmb1, autoint);
//        digitalWrite(dirb2, LOW);
//        analogWrite(pwmb2, autoint);
//        Serial.println("Hold Balls");
//   }
//    prev_intake=0;
//       intake();
//   
//  }
//
//
//
//  }
//}
//
//
//void rectify(){
//   if( ly<-40){
//       prev_intake=0;
//       intake();
//     }
//     else {
//
//  if(dist1-dist2>0){
//    autospeed=15*(dist1-dist2);
//
//
//    digitalWrite(dirL1, HIGH);
//  digitalWrite(dirR1, LOW);
//  digitalWrite(dirL2, HIGH);
//  digitalWrite(dirR2, LOW);
//   analogWrite(pwmL1,autospeed);
//  analogWrite(pwmR1, autospeed);
//  analogWrite(pwmL2,autospeed);
//  analogWrite(pwmR2, autospeed);
//     Serial.println(autospeed);
//    Serial.println("CLockwise Slow");
//  }
//  
//  
//      else if(dist2-dist1>=0){
//        autospeed=15*(dist2-dist1);
//      digitalWrite(dirL1, LOW);
//  digitalWrite(dirR1, HIGH);
//  digitalWrite(dirL2, LOW);
//  digitalWrite(dirR2, HIGH);
//   analogWrite(pwmL1,autospeed);
//  analogWrite(pwmR1, autospeed);
//  analogWrite(pwmL2,autospeed);
//  analogWrite(pwmR2, autospeed);
//       Serial.println(autospeed);
//    Serial.println("anti-CLockwise Slow1");
//  }
//   
//     }
// 
//}
