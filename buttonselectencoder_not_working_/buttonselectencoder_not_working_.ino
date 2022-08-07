#define inputclk 4
#define inputdt 5
#define firstled 9
#define secondled 10
#define button 13
int count = 0;
int but, butswitch = 0;
int currentstateclk;
int previousstateclk;






void setup() {
  // put your setup code here, to run once:
  pinMode(inputclk, INPUT);
  pinMode(inputdt, INPUT);
  pinMode(firstled, OUTPUT);
  pinMode(secondled, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
  previousstateclk = digitalRead(inputclk);


}

void loop() {
  but = digitalRead(13);
  if (but == HIGH)
  {
    butswitch++;
  }

  // put your main code here, to run repeatedly:
  if (butswitch / 2 == 0)
  {
    currentstateclk = digitalRead(inputclk);
   if  (currentstateclk != previousstateclk)
    {
      if (digitalRead(inputdt) != currentstateclk)
      {
      }
      else
      {
        if (count > 254)
       
      {
        count = 0;
      }
      else {
        count++;
        analogWrite(firstled, count);
        digitalWrite(secondled, LOW);
        Serial.println(count);
      }
    }
    previousstateclk = currentstateclk;
  }
  else
  { count = 0;
    currentstateclk = digitalRead(inputclk);
    if (currentstateclk != previousstateclk)
    {
      if (digitalRead(inputdt) != currentstateclk)
      { 
      }
      else
      { if (count > 254)
        {
          count = 0;
        }
        else {
          count++;
          analogWrite(secondled, count);
          digitalWrite(firstled, LOW);
          Serial.println(count);
        }
      }
      previousstateclk = currentstateclk;
    }
  }
}
