int val=LOW,a;
int count=0,count1,buttonvalue=0;
int currentstateclk;
int previousstateclk;

#define inputclk 4
#define inputdt 5
void setup() {
  // put your setup code here, to run once:
  
  pinMode(13,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(inputclk,INPUT);
pinMode(inputdt,INPUT);
  Serial.begin(9600);
  previousstateclk=digitalRead(inputclk);
  

}

void loop() {
  // put your main code here, to run repeatedly:
val=digitalRead(13);
if(val==LOW)
{
  buttonvalue++;
}
for(a=0;val==LOW;a++)
{
  val=digitalRead(13);
}
if(val==HIGH)
{
if(buttonvalue%2==0)
{
  currentstateclk=digitalRead(inputclk);

   if  (currentstateclk != previousstateclk)
    {
      if (digitalRead(inputdt) != currentstateclk)
      {
      }
      else
      {
        if (count > 1000)
      {
        count = 0;
      }
      else 
      {
        count=count+68;
        count1=map(count,0,1000,0,255);
        analogWrite(9, count1);
        digitalWrite(10, LOW);
        
      }
    }
    previousstateclk = currentstateclk;
    }
}
if(buttonvalue%2!=0)
{
          
  
    currentstateclk = digitalRead(inputclk);
    if (currentstateclk != previousstateclk)
    {
      if (digitalRead(inputdt) != currentstateclk)
      { 
      }
      else
      { if (count > 1000)
        {
          count = 0;
        }
        else {
          count=count+68;
          count1=map(count,0,1000,0,255);
          analogWrite(10, count1);
          digitalWrite(9, LOW);
          
        }
      }
      previousstateclk = currentstateclk;
    } 
}
Serial.print(buttonvalue);
Serial.print(",");
Serial.println(count);


}
}
