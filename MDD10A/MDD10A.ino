
int val;


void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
Serial.begin(9600);


}

void loop() {
  digitalWrite(4,LOW);
  // put your main code here, to run repeatedly:
for(val=0;val<256;val++)
{
  analogWrite(3,val);
  delay(40);
}
}
