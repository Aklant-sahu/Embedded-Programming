void kill()
{
  analogWrite(pwmL1, 0);
  analogWrite(pwmL2, 0);
  analogWrite(pwmR1, 0);
  analogWrite(pwmR2, 0);

  upc=1;
  gripc=1;
  lc=1;
  rc=1;
  digitalWrite(box_pne, LOW);
  digitalWrite(gpne, LOW);
  digitalWrite(leftpne, LOW);
  digitalWrite(rightpne, LOW);
}

void motor_stop()
{
  analogWrite(pwmL1, 0);
  analogWrite(pwmL2, 0);
  analogWrite(pwmR1, 0);
  analogWrite(pwmR2, 0);
  analogWrite(gpwm, 0);
}
