#ifndef Odometry_h
#define Odometry_h
#include "Arduino.h"

class Odometry{
  private:

  float currX,currY,targetX,targetY;
  float angle,angleToTake;
  float dTheta;
  float d;
  const float pi=3.14159;

  void setAngles(int ang);
  void  setPose(int wheelSize,int counterX,int counterY,float gearRatio);
  
  public:
  
  Odometry(float currX,float currY);
  

   double rectifyAngle();
  double oreint();
  double rectifyPos();
  double clipAngle(int ang);
  void updatePose(int wheelSize,int &counterX,int &counterY,float gearRatio,int ang,boolean rotation,int prevcountx,int prevcounty);

  void ignoreCount(int &counterX,int &counterY,int prevcountx,int prevcounty);
  
  
  
};
#endif
