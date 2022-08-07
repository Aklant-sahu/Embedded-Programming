#define inputclk 4
#define inputdt 5
#define firstled 9
#define secondled 10
int count=0;
int currentstateclk;
int previousstateclk;






void setup() {
  // put your setup code here, to run once:
pinMode(inputclk,INPUT);
pinMode(inputdt,INPUT);
pinMode(firstled,OUTPUT);
pinMode(secondled,OUTPUT);
Serial.begin(9600);
previousstateclk=digitalRead(inputclk);


}

void loop() {
  // put your main code here, to run repeatedly:
currentstateclk=digitalRead(inputclk);
if(currentstateclk!=previousstateclk)
{
  if(digitalRead(inputdt)!=currentstateclk)
  {if(count<-254)
  {
    count=0;
  }
  else{
     count--;
    analogWrite(firstled,-count);
     digitalWrite(secondled,LOW);
     Serial.println(count);
  }
  }
  else
    {
      if(count>254)
  {
    count=0;
  }
  else{
    count++;
    analogWrite(secondled,count);
     digitalWrite(firstled,LOW);
     Serial.println(count);
  }
  }
  previousstateclk=currentstateclk;
}
}
