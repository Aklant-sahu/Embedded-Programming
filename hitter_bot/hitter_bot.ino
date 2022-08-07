#define motor1 12
#define dir1 49
#define motor2 13
#define dir2 51

#define motor3 7
#define dir3 46
int pos,dir;

void setup() {
  // put your setup code here, to run once:
  pos=160;
  dir=1;
  pinMode(motor1,OUTPUT); 
  pinMode(dir1,OUTPUT);

  pinMode(motor2,OUTPUT); 
  pinMode(dir2,OUTPUT);
    pinMode(motor3,OUTPUT); 
  pinMode(dir3,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()==0){
  digitalWrite(dir1,dir);
  digitalWrite(dir2,dir);
  analogWrite(motor1,pos);
  analogWrite(motor2,pos);
  
}
pos=Serial.parseInt();
dir=Serial.parseInt();
Serial.print(pos);
Serial.print(" ");
Serial.println(dir);
}
/*void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dir1,dir);
  digitalWrite(dir2,dir);
  analogWrite(motor1,pos);
  analogWrite(motor2,pos);
  delay(15000);
  pos=0;
  dir=0;
}*/
  
