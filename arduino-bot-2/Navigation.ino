//  HIGH MEANS FORWARD (CLOCKWISE)
//  LOW MEANS BACKWARD  (A-C)
void forward_fast()
{
  speed_fast=map(ly, buff2, -128, 0, fast);
//  analogWrite(pwmL1, speed_fast);
//  analogWrite(pwmR1, speed_fast);
//  analogWrite(pwmL2, speed_fast);
//  analogWrite(pwmR2, speed_fast);
//
//  digitalWrite(dirL1, HIGH);
//  digitalWrite(dirR1, HIGH);
//  digitalWrite(dirL2, HIGH);
//  digitalWrite(dirR2, HIGH);
    digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, HIGH);
  analogWrite(pwmL1, speed_fast);
  analogWrite(pwmR1, speed_fast);
  analogWrite(pwmL2, speed_fast);
  analogWrite(pwmR2, speed_fast);

  Serial.println("forward fast");
  
}

void forward_slow()
{
  speed_slow = map(ry, buff2, -128, 0, slow);
//  analogWrite(pwmL1, speed_slow);
//  analogWrite(pwmR1, speed_slow);
//  analogWrite(pwmL2, speed_slow);
//  analogWrite(pwmR2, speed_slow);
//  digitalWrite(dirL1,HIGH);
//  digitalWrite(dirR1,HIGH);
//  digitalWrite(dirL2, HIGH);
//  digitalWrite(dirR2,HIGH);
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, HIGH);
    analogWrite(pwmL1, speed_slow);
  analogWrite(pwmR1, speed_slow);
  analogWrite(pwmL2, speed_slow);
  analogWrite(pwmR2, speed_slow);

  Serial.println("forward slow");
  
}



void backward_fast()
{
  speed_fast=map(ly, buff1, 127, 0, fast);
//  analogWrite(pwmL1, speed_fast);
//  analogWrite(pwmR1, speed_fast);
//  analogWrite(pwmL2, speed_fast);
//  analogWrite(pwmR2, speed_fast);
//  digitalWrite(dirL1, LOW);
//  digitalWrite(dirR1, LOW);
//  digitalWrite(dirL2, LOW);
//  digitalWrite(dirR2, LOW);
 digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
   analogWrite(pwmL1, speed_fast);
  analogWrite(pwmR1, speed_fast);
  analogWrite(pwmL2, speed_fast);
  analogWrite(pwmR2, speed_fast);
 
  Serial.println("backward Fast");
  
}

void backward_slow()
{speed_slow = map(ry,buff1, 127, 0,slow);
//  analogWrite(pwmL1, speed_slow);
//  analogWrite(pwmR1, speed_slow);
//  analogWrite(pwmL2, speed_slow);
//  analogWrite(pwmR2, speed_slow);
// digitalWrite(dirL1, LOW);
//  digitalWrite(dirR1, LOW);
//  digitalWrite(dirL2, LOW);
//  digitalWrite(dirR2, LOW);
  digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
   analogWrite(pwmL1, speed_slow);
  analogWrite(pwmR1, speed_slow);
  analogWrite(pwmL2, speed_slow);
  analogWrite(pwmR2, speed_slow);

  Serial.println("backward Slow");
}

void right_fast()
{
  speed_fast=map(lx, buff1, 127, 0, fast);
//  analogWrite(pwmL1, speed_fast);
//  analogWrite(pwmR1, speed_fast);
//  analogWrite(pwmL2, speed_fast);
//  analogWrite(pwmR2, speed_fast);
//  digitalWrite(dirL1, HIGH);
//  digitalWrite(dirR1, LOW);
//  digitalWrite(dirL2, LOW);
//  digitalWrite(dirR2, HIGH);
  digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, LOW);
    analogWrite(pwmL1, speed_fast);
  analogWrite(pwmR1, speed_fast);
  analogWrite(pwmL2, speed_fast);
  analogWrite(pwmR2, speed_fast);


  
  Serial.println("Right fast");
}


void right_slow()
{
  speed_fast=map(rx, buff1, 127, 0, slow);
//  analogWrite(pwmL1, speed_slow);
//  analogWrite(pwmR1, speed_slow);
//  analogWrite(pwmL2, speed_slow);
//  analogWrite(pwmR2, speed_slow);
//  digitalWrite(dirL1, HIGH);
//  digitalWrite(dirR1, LOW);
//  digitalWrite(dirL2, LOW);
//  digitalWrite(dirR2, HIGH);
digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, LOW);
    analogWrite(pwmL1, speed_slow);
  analogWrite(pwmR1, speed_slow);
  analogWrite(pwmL2, speed_slow);
  analogWrite(pwmR2, speed_slow);
  
  Serial.println("right slow");
  
}

void left_fast()
{
  speed_fast=map(lx, buff2, -128, 0, fast);
//  analogWrite(pwmL1, speed_fast);
//  analogWrite(pwmR1, speed_fast);
//  analogWrite(pwmL2, speed_fast);
//  analogWrite(pwmR2, speed_fast);
//  digitalWrite(dirL1, LOW);
//  digitalWrite(dirR1, HIGH);
//  digitalWrite(dirL2, HIGH);
//  digitalWrite(dirR2, LOW);

  digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, HIGH);
    analogWrite(pwmL1, speed_fast);
  analogWrite(pwmR1, speed_fast);
  analogWrite(pwmL2, speed_fast);
  analogWrite(pwmR2, speed_fast);

  Serial.println("left fast");
  
}

void left_slow()
{
    speed_fast=map(rx, buff2, -128, 0,slow);
//  analogWrite(pwmL1, speed_slow);
//  analogWrite(pwmR1, speed_slow);
//  analogWrite(pwmL2, speed_slow);
//  analogWrite(pwmR2, speed_slow);
//    digitalWrite(dirL1, LOW);
//  digitalWrite(dirR1, HIGH);
//  digitalWrite(dirL2, HIGH);
//  digitalWrite(dirR2, LOW);

  digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, HIGH);
    analogWrite(pwmL1, speed_slow);
  analogWrite(pwmR1, speed_slow);
  analogWrite(pwmL2, speed_slow);
  analogWrite(pwmR2, speed_slow);

  Serial.println("left slow");
  
}


void stopmotors()
{
    analogWrite(pwmL1, 0);
  analogWrite(pwmR1, 0);
  analogWrite(pwmL2, 0);
  analogWrite(pwmR2, 0);
   Serial.println("stop motors");
}
