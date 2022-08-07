int temp, counter1 = 0,counter2=0,prev_count1=0,prev_count2=0; 
int setpoint1=0,setpoint2=0;
double kp=0,ki=0,kd=0;
float error1=0,val1=0,prev_error1=0,cum_error1=0;
float error2=0,val2=0,prev_error2=0,cum_error2=0;
double curr_time1=0,prev_time1=0,dt1=0,rate1=0;
double curr_time2=0,prev_time2=0,dt2=0,rate2=0;
 int inc=0;


#define dir1 4
#define pwm1 5
#define dir2 6
#define pwm2 7
#define wheel 100 // size in mm
#define gear 47
#define count_per_rev gear*7*4 // count per revolution
int motor1dir=LOW,motor2dir=HIGH;





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
  attachInterrupt(digitalPinToInterrupt(2), a1, RISING);
   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(3), b1, RISING);

  attachInterrupt(digitalPinToInterrupt(18), a2, RISING);
   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(19), b2, RISING);
  
  kp=3;
//  ki=100000;
ki=0.0001;
  kd=0.5;
  
  setpoint1=5000;
  prev_error1=0;
  prev_time1=millis();

  setpoint2=5000;
  prev_error2=0;
  prev_time2=millis();
     digitalWrite(dir1,LOW);
    digitalWrite(dir2,HIGH);

    Serial.begin (9600);
  }
   
  void loop() {


//   Serial.print(counter1);
//      Serial.print(',');
//
//    Serial.print(setpoint1);
//    Serial.println();
//    
//  error1=setpoint1-counter1;
//
//  
//  rate=(error1-prev_error)/dt;
//  prev_error=error1;
//  
//
//  curr_time=millis();
//  dt=curr_time-prev_time;
//  prev_time=curr_time;
//  
//  cum_error+=(error1*dt);
//   
//  val1=kp*error1 + ki*cum_error +kd*rate;
//   val1 = bound(val1, 0, 255);



         val1=Pid(counter1,prev_error1,prev_time1,cum_error1,kp,ki,kd,setpoint1,1,4,motor1dir);
 val2=Pid(counter2,prev_error2,prev_time2,cum_error2,kp,ki,kd,setpoint2,1,6,motor2dir);
 

    
   analogWrite(pwm1,val1);
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

double Pid (double inp,float &prev_err,double &prev_ti,float &cum_err,double kp,double ki,double kd,double setp,int flag,int dirpin,int dir){

 

   double err=setp-inp;
   double crr=millis();
   double dt=crr-prev_ti;
   prev_ti=crr;
  
   double rate=(err-prev_err)/dt;
   prev_err=err;
  
   cum_err +=(err*dt);
   
  double out=kp*err + ki*cum_err + kd*rate;
  if(out>=0){
     out= bound(out, 0, 255);
  }
  else{
    digitalWrite(dirpin,~dir);
  out= bound(out, 0, 255);
  }


   if (flag==1){
   Serial.print(inp);
   Serial.print(',');
   Serial.print(setp);
//   Serial.print(out);

   Serial.println();
  }
  return out;
  
}
