void setup() {
  // put your setup code here, to run once:
pinMode(3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(3,HIGH);
delay(2000);
digitalWrite(3,LOW);
delay(2000);
}
