int val,condition;
float pwmin;

void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(A1,INPUT);
pinMode(7,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
val=analogRead(A1);

pwmin=map(val,0,1023,0,255);
digitalWrite(4,LOW);
Serial.println(val);
delay(500);
condition=digitalRead(7);

  analogWrite(3,pwmin);
  
 
}
