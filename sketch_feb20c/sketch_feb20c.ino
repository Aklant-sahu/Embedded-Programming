#define inputclk 4
#define inputdt 5
#define firstled 9
#define secondled 10
#define button 13
int count=0,a;
int but,butswitch=0;
int currentstateclk;
int previousstateclk;
void setup()
{
  pinMode(inputclk,INPUT);
pinMode(inputdt,INPUT);
pinMode(firstled,OUTPUT);
pinMode(secondled,OUTPUT);
pinMode(button,INPUT);
Serial.begin(9600);
previousstateclk=digitalRead(inputclk);

}
void loop() {
  but=digitalRead(13);
  
  
  if(but==LOW)
  {
   
  if(butswitch%2==0)
  {
     digitalWrite(firstled,HIGH);
      digitalWrite(secondled,LOW);
      
  }
  else
  {
     digitalWrite(firstled,LOW);
     digitalWrite(secondled,HIGH);
    
  }
   butswitch++;
  }
  
}
