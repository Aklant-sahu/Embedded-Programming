int XLEDPIN=3;
int YLEDPIN=6;
int XSWITCH=5;
int YSWITCH=7;
int val1,val2;
void setup() {
  // put your setup code here, to run once:
pinMode(XSWITCH,INPUT);
pinMode(YSWITCH,INPUT);
pinMode(XLEDPIN,OUTPUT);
pinMode(YLEDPIN,OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
val1=digitalRead(XSWITCH);
Serial.println(val1);
val2=digitalRead(YSWITCH);
Serial.println(val2);
if(val1==HIGH)
{
  digitalWrite(XLEDPIN,HIGH);
  delay(500);
  digitalWrite(YLEDPIN,LOW);
  delay(500);
}
if(val2==HIGH )
{
  digitalWrite(YLEDPIN,HIGH);
  delay(500);
  digitalWrite(X                                LEDPIN,HIGH);
   delay(500);
  
}
}
