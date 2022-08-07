#ifndef Pid_h
#define Pid_h
#include "Arduino.h"

class Pid{
  private:
  float bound(float x, float x_min, float x_max);
  float err;
  float prev_err;
  float cum_err;
  float rate;
  float setp;
  
  
  double curr_time;
  double prev_time;
  double dt;

  double kp;
  double ki;
  double kd;
  double k_encoder;

  int dirpin;
//  int dir;
  int refdir;
  int prev_count;
  int count_diff;
  int sp;
  float out;

  int inp;

  public:
  
  Pid(int inp,int dirpin,int refdir);
  void show();
  void setGains(double kp,double ki,double kd);
  double calculate(int inp,int &dir);
  double Rpm(int inp);
  void setSetPoint(float setp);
  void resetSetPoint();
  void setEncConst(double k);
  
  
  
};
#endif
