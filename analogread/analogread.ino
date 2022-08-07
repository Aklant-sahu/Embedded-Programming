int val;
float voltage,vout;
void setup() {
  // put your setup code here, to run once:
pinMode(A3,INPUT);
pinMode(3,OUTPUT);
Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
val=analogRead(A3);
voltage=map(val,0,1023,0,5);
vout=map(val,0,1023,0,255);

Serial.println(vout);
analogWrite(3,vout);
delay(500);


}
