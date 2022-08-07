int val;
int pos =0;
#define dir 4
#define pwm 5
#define enca 2
#define encb 3

void setup() {
  // put your setup code here, to run once:
pinMode(dir,OUTPUT);
pinMode(pwm,OUTPUT);
pinMode(enca,INPUT);
pinMode(encb,INPUT);
Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(enca),readEncoder,RISING);

}

void loop() {
digitalWrite(dir,LOW);
analogWrite(pwm,25);
Serial.println(pos);

}
void readEncoder(){
  int b=digitalRead(encb);
  if (b>0){
    if(pos<359){
    pos+=2.678;
    }
    else{
      pos=0;
    }
  }
  else{
    if(pos>-359){
    pos-=2.678;
    }
    else{
      pos=0;
    }
}
}
