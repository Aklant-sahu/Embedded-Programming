int yourchoice;
int a=LOW,b=LOW,c=LOW,d=LOW;

void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("select between 1,2,3,4");
while(Serial.available()==0)
{
}
yourchoice=Serial.parseInt();
Serial.print("your number is ");
Serial.println(yourchoice);
if(yourchoice==1&&a==LOW)
{digitalWrite(2,HIGH);
a=HIGH;
yourchoice=0;
}
if(yourchoice==1&&a==HIGH)
{digitalWrite(2,LOW);
a=LOW;
yourchoice=0;
}
if(yourchoice==2&&b==LOW)
{digitalWrite(3,HIGH);
b=HIGH;
yourchoice=0;
}
if(yourchoice==2&&b==HIGH)
{digitalWrite(3,LOW);
b=LOW;
yourchoice=0;
}
if(yourchoice==3&&c==LOW)
{digitalWrite(4,HIGH);
c=HIGH;
yourchoice=0;
}
if(yourchoice==3&&c==HIGH)
{digitalWrite(4,LOW);
c=LOW;
yourchoice=0;
}
if(yourchoice==4&&d==LOW)
{digitalWrite(5,HIGH);
d=HIGH;
yourchoice=0;
}
if(yourchoice==4&&d==HIGH)
{digitalWrite(5,LOW);
d=LOW;
yourchoice=0;
}


}
