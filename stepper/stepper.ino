const int stepPin = 44; //Stepper motor
const int dirPin =41; 
const int enPin = 59;
//const int stepdelay=365;
const int stepdelay=235;
int prev_state=0;

const int stepPin1 = 45; //Stepper motor
const int dirPin1 =49; 
const int enPin1 = 53;
//const int stepdelay=365;
double prev=0,curr=0;


void setup() {
  
  // put your setup code here, to run once:
Serial.begin(74880);

  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);

  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);


    pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);

  pinMode(enPin1,OUTPUT);
  digitalWrite(enPin1,LOW);
}
void openn()
{
  for(int i=0;i<10;i++){
  digitalWrite(dirPin1, LOW);

        digitalWrite(stepPin1,HIGH); 
        delayMicroseconds(stepdelay); 
        digitalWrite(stepPin1,LOW); 

        delayMicroseconds(stepdelay);

//        Serial.println("Arms open");
  }
  prev=millis();
}

void closee()
{for(int i=0;i<10;i++){
  digitalWrite(dirPin1, HIGH);

        digitalWrite(stepPin1,HIGH); 
        delayMicroseconds(stepdelay); 
        digitalWrite(stepPin1,LOW); 
        
        delayMicroseconds(stepdelay);
//
//      Serial.println("Arms close");
}
}
//
//
//
//void openn()
//{
//  for(int i=0;i<10;i++){
//  digitalWrite(dirPin, LOW);
//analogWrite(stepPin,127);
//
//        Serial.println("Arms open");
//  }
//}
//
//void closee()
//{for(int i=0;i<10;i++){
//  digitalWrite(dirPin, HIGH);
//analogWrite(stepPin,127);
//        
//      Serial.println("Arms close");
//}
//}








void loop() {
  // put your main code here, to run repeatedly:
  curr=millis();
  if (curr-prev<=1000){
openn();
  }
  else{
  closee();
}

Serial.println(curr-prev);


//
//closee();
//Serial.println("closee");
   
     
}
