void clockwise_slow()
{

 
speed_slow=map(cir, 40, 255, 0, clockwise);
  analogWrite(pwmL1, speed_slow);
  analogWrite(pwmR1, speed_slow);
  analogWrite(pwmL2, speed_slow);
  analogWrite(pwmR2, speed_slow);
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
  Serial.println("CLockwise Slow");

  
}



void anticlockwise_slow()
{
speed_slow=map(squ, 40, 255, 0, clockwise);
  analogWrite(pwmL1, speed_slow);
  analogWrite(pwmR1, speed_slow);
  analogWrite(pwmL2, speed_slow);
  analogWrite(pwmR2, speed_slow);
 digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, HIGH);
  Serial.println("Anti-CLockwise Slow");

  
}
void rotation(){
  if (cir>40){
    clockwise_slow();
  }
  else if(squ>40){
    anticlockwise_slow();
  }
  else{
    stopmotors();
  }
}
