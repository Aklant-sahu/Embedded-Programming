int val;
void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
Serial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
    while(Serial.available()==0)
    {
    }
    
    val=Serial.read();
    if(val==0)
    {
      digitalWrite(3,LOW);
    }
    else
     {
      digitalWrite(3,HIGH);
    }
}
