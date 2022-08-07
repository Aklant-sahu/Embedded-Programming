
int pos=0, val3=0;
float val1;
int input=A0;
void setup() {
  // put your setup code here, to run once:
pinMode(input,INPUT);
pinMode(3,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

val1=Serial.println(analogRead(A0));
pos=(val1/923.0)*70;
Serial.println(val2);
val3=digitalRead(3);
if (val3==HIGH)
{
  Serial.println("junction detected");
}
else
{

Serial.println(pos);
}
/*if (val2>70 || val2<0)
{
  Serial.println("***");
}/*/


}
