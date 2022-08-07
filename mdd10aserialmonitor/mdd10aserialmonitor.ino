int val;
float pwmin;

void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Enter the speed between 0 and 255 ");


while(Serial.available()==0)
{digitalWrite(4,LOW);
  analogWrite(3,val);
}
val=Serial.parseInt();


Serial.println(val);
 
 

}
