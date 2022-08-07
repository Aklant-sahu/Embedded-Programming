int val;
void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
Serial.begin(9600);
}

void loop() {  digitalWrite(4,LOW);
  // put your main code here, to run repeatedly:
val=digitalRead(2);

if(val==LOW)
{
  analogWrite(3,125);
  
}
else
{
   analogWrite(3,0);
}
}
