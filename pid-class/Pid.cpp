#include "Arduino.h"
#include "Pid.h"

Pid::Pid(int inp,int dirpin,int refdir){
  inp=inp;
  dirpin=dirpin;
  refdir=refdir;
  count_diff=0;
  sp=0;
  prev_time=0;
  prev_count=0;
  prev_err=0;
  err=0;
  cum_err=0;
  out=0;
}

void Pid::setGains(double kp,double ki,double kd){
  kp=kp;
  ki=ki;
  kd=kd;
}
void Pid::show(){
    Serial.print(inp);
   Serial.print(',');
   Serial.print(setp);
    Serial.println();
}
void Pid::setSetPoint(float setp){
  setp=setp;
}
void Pid::resetSetPoint(){
  setp=0;
}

double Pid::calculate(int inp,int &dir){
  
   err=setp-inp;
   curr_time=millis();
   dt=curr_time-prev_time;
   prev_time=curr_time;
   rate=(err-prev_err)/dt;
   prev_err=err;
  if(abs(err)<0.1*setp ){
   cum_err +=(err*dt);
  }
  else{
    ki=0;
  }
   out=kp*err + ki*cum_err + kd*rate;

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
  
   
  return out;
  

}
void Pid::setEncConst(double k){
  k_encoder=k;
}

double Pid::Rpm(int inp){
  
   double time1 = millis() - prev_time;
   prev_time=millis();

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
float Pid::bound(float x, float x_min, float x_max) {
    if (x < x_min) { x = x_min; }
    if (x > x_max) { x = x_max; }
    return x;
}
