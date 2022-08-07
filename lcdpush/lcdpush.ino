int val=LOW,a,b;
void setup() {
  // put your setup code here, to run once:
pinMode(7,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

val=digitalRead(7);







if(val==HIGH)
{
  
for(a=0;a<5;a++)
{
  Serial.print("hello");
}
 
  
}
for(b=0;val==HIGH;b++)
{
  val=digitalRead(7);
 
}
