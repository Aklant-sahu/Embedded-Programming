
void forward_fast()
{
//  speed_fast=map(lx, 0, 127, 0,speed_fast);
  analogWrite(pwmL1, speed_fast);
  analogWrite(pwmR1, speed_fast);
  analogWrite(pwmL2, speed_fast);
  analogWrite(pwmR2, speed_fast);
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
  Serial.println(speed_fast);
  
}

void forward_slow()
{
//  speed_slow = map(rx, 0, 127, 0, 40);
  analogWrite(pwmL1, speed_slow);
  analogWrite(pwmR1, speed_slow);
  analogWrite(pwmL2, speed_slow);
  analogWrite(pwmR2, speed_slow);
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
  
  
}



void backward_fast()
{
  analogWrite(pwmL1, speed_fast);
  analogWrite(pwmR1, speed_fast);
  analogWrite(pwmL2, speed_fast);
  analogWrite(pwmR2, speed_fast);
  digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, HIGH);
  Serial.println(speed_fast);
  
}

void backward_slow()
{
  analogWrite(pwmL1, speed_slow);
  analogWrite(pwmR1, speed_slow);
  analogWrite(pwmL2, speed_slow);
  analogWrite(pwmR2, speed_slow);
  digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, HIGH);
  Serial.println("Going backward Slow");
}

void right_fast()
{
  analogWrite(pwmL1, speed_fast);
  analogWrite(pwmR1, speed_fast);
  analogWrite(pwmL2, speed_fast);
  analogWrite(pwmR2, speed_fast);
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, LOW);
  Serial.println("Going Right fast");
}


void right_slow()
{
  
  analogWrite(pwmL1, speed_slow);
  analogWrite(pwmR1, speed_slow);
  analogWrite(pwmL2, speed_slow);
  analogWrite(pwmR2, speed_slow);
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, LOW);
  Serial.println("Going right slow");
  
}

void left_fast()
{
  
  analogWrite(pwmL1, speed_fast);
  analogWrite(pwmR1, speed_fast);
  analogWrite(pwmL2, speed_fast);
  analogWrite(pwmR2, speed_fast);
  digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, HIGH);
  Serial.println("Going left fast");
  
}

void left_slow()
{
  
  analogWrite(pwmL1, speed_slow);
  analogWrite(pwmR1, speed_slow);
  analogWrite(pwmL2, speed_slow);
  analogWrite(pwmR2, speed_slow);
  digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, HIGH);
  Serial.println("Going left slow");
  
}
