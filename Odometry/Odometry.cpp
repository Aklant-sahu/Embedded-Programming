#include "Arduino.h"
#include "Odometry.h"


  // To however many digits you want.

Odometry::Odometry(float currX,float currY){
 currX=0;
 currY=0;
 targetX=0;
 targetY=0;
 angle=0;

 angleToTake=0;
 dTheta=0;
 d=0;



}

void Odometry::setAngles(int ang)
{
 angle=clipAngle(ang);
}

double Odometry:: clipAngle(int ang)
{
   return  ang%360;
}
void Odometry::setPose(int wheelSize,int counterX,int counterY,float gearRatio){
  currX=counterX*pi*(wheelSize)/gearRatio;
  currY=counterY*pi*(wheelSize)/gearRatio;
}
 void Odometry::updatePose(int wheelSize,int &counterX,int &counterY,float gearRatio,int ang,boolean rotation,int prevcountx,int prevcounty){
if (rotation==true){

  ignoreCount(counterX,counterY,prevcountx,prevcounty);
  setAngles(ang);
  
}
else{
   setAngles(ang);
   setPose(wheelSize,counterX,counterY,gearRatio);
}
  
 }
  void Odometry::ignoreCount(int &counterX,int &counterY,int prevcountx,int prevcounty){
  counterX=prevcountx;
  counterY=prevcounty;

  }
