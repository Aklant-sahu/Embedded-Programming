int temp, counter1 = 0,counter2=0,prev_count1=0,prev_count2=0; 
int setpoint1=0,setpoint2=0;
double kp=0,ki=0,kd=0;
float error1=0,val1=0,prev_error1=0,cum_error1=0;
float error2=0,val2=0,prev_error2=0,cum_error2=0;
double curr_time1=0,prev_time1=0,dt1=0,rate1=0;
double curr_time2=0,prev_time2=0,dt2=0,rate2=0;
 int inc=0;
double pii = 22/7;

double k_encoder = 200*pii/658;
double sp, rpm;
double prev_speed_time1=0,count_diff1=0;


#define dir1 4
#define pwm1 5
#define dir2 6
#define pwm2 7
#define wheel 100 // size in mm
#define gear 47
#define count_per_rev gear*7*4 // count per revolution
int motor1dir=LOW,motor2dir=HIGH;
int refdir1=LOW,refdir2=HIGH;

void setup() {


  pinMode(2, INPUT_PULLUP); // internal pullup input pin 2 
  pinMode(3, INPUT_PULLUP); // internal pullup input pin 3
    pinMode(18, INPUT_PULLUP); // internal pullup input pin 2 
  pinMode(19, INPUT_PULLUP);
  
  pinMode(dir1,OUTPUT); // internal pullup input pin 2 
  pinMode(pwm1, OUTPUT); // internal pullup input pin 3
    pinMode(dir2, OUTPUT); // internal pullup input pin 2 
  pinMode(pwm2, OUTPUT);
  
  
//Setting up interrupt
  //A rising pulse from encodenren activated A(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(2), a1, CHANGE);
//  attachInterrupt(digitalPinToInterrupt(3), b1, RISING);
  attachInterrupt(digitalPinToInterrupt(18), a2, CHANGE);
//  attachInterrupt(digitalPinToInterrupt(19), b2, RISING);
  
  kp=1.5;

ki=0.00006;
  kd=0;
  
  setpoint1=2000;
  prev_error1=0;
  prev_time1=millis();
prev_speed_time1=millis();

  setpoint2=2000;
  prev_error2=0;
  prev_time2=millis();
     digitalWrite(dir1,LOW);
    digitalWrite(dir2,HIGH);

    Serial.begin (9600);
  }
   
  void loop() {



//         val1=Pidinc(counter1,prev_error1,prev_time1,cum_error1,kp,ki,kd,setpoint1,1,dir1,motor1dir);
 val2=Pidinc(counter2,prev_error2,prev_time2,cum_error2,kp,ki,kd,setpoint2,1,dir2,motor2dir);
 float valspeed=rpm(counter2,prev_speed_time2,count_diff);
 

//      digitalWrite(dir1,LOW);
//    digitalWrite(dir2,HIGH);
//   analogWrite(pwm1,val1);
digitalWrite(dir2,motor2dir);
    analogWrite(pwm2,val2);






  }
   
  void a1() {
  // A is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(3)==LOW) {
  counter1++;
  }else{
  counter1--;
  }
  }
   
  void b1() {
  // ai1 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(2)==LOW) {
  counter1--;
  }else{
  counter1++;
  }
  }

    void a2() {
  // A is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(19)==LOW) {
  counter2++;
  }else{
  counter2--;
  }
  }
   
  void b2() {
  // ai1 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(18)==LOW) {
  counter2--;
  }else{
  counter2++;
  }
  }
  float bound(float x, float x_min, float x_max) {
    if (x < x_min) { x = x_min; }
    if (x > x_max) { x = x_max; }
    return x;
}

double Pidinc (double inp,float &prev_err,double &prev_ti,float &cum_err,double kp,double ki,double kd,double setp,int flag,int dirpin,int &dir,int refdir){
   double err=setp-inp;
   double crr=millis();
   double dt=crr-prev_ti;
   prev_ti=crr;
   double rate=(err-prev_err)/dt;
   prev_err=err;
  if(abs(err)<0.1*setp ){
   cum_err +=(err*dt);
  }
  else{
    ki=0;
  }
   double out=kp*err + ki*cum_err + kd*rate;
//  Serial.print(out);
//  
//   Serial.print(',');
  if(inp>setp && out<0){
    if(out<-255){
    out=255;
  }
  else{
    out=abs(out);
  }
  if(refdir==HIGH){
 dir=LOW;
  }
  else if(refdir==LOW){
    dir=HIGH;
  }
  }
else if(inp<setp && out<0){
  if(out<-255){
    out=255;
  }
  else{
    out=abs(out);
  }
  if(refdir==HIGH){
 dir=HIGH;
  }
  else if(refdir==LOW){
    dir=LOW;
  }
    }
  else{
    dir=refdir;
    out= bound(out, 0, 255);
  }
  if (flag==1){
   Serial.print(inp);
   Serial.print(',');
   Serial.print(setp);
//   Serial.print(',');
//   Serial.print(out);
    Serial.println();
  }
   
  return out;
  
}
float rpm(double inp,float &prev_count,double &prev_ti){
 double time1 = millis() - prev_ti;
   prev_ti=millis();

   if(prev_count != inp){
   count_diff = prev_count - inp;
   }
   if(count_diff <0){
   count_diff = abs(count_diff) ;
       sp = count_diff/time1;
   }

    sp = sp * k_encoder; 
    sp = sp * 60000; //distance travelled in 1 minute
    sp = sp/(200*(22/7)); //Revolutions per minute

    return sp;
   
  
}
