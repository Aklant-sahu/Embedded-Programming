void mapNavMac()
{
  if(lx>40 && ly<0)
  {
    spdr = map(lx, 40, 127, spdrMax, 0);
    rightFront.setDir(HIGH);
    leftBack.setDir(HIGH);
    rightFront.setPwm(spdr);
    leftBack.setPwm(spdr);
  }
  else if(lx<-40 && ly<0)
  {
    spdl = map(lx, -40, -128, spdlMax, 0);
    leftFront.setDir(HIGH);
    rightBack.setDir(HIGH);
    leftFront.setPwm(spdl);
    rightBack.setPwm(spdl);
  }

  if(lx>40 && ly>0)
  {
    spdr = map(lx, 40, 127, spdrMax, 0);
    rightFront.setDir(LOW);
    leftBack.setDir(LOW);
    rightFront.setPwm(spdr);
    leftBack.setPwm(spdr);
  }
  else if(lx<-40 && ly>0)
  {
    spdl = map(lx, -40, -128, spdlMax, 0);
    leftFront.setDir(LOW);
    rightBack.setDir(LOW);
    leftFront.setPwm(spdl);
    rightBack.setPwm(spdl);
  }

  if(lx>40 && ly==0)
  {
      spdl = map(lx, -40, -128, 0, spdlMax);
    leftFront.setDir(HIGH);
  leftBack.setDir(LOW);
   rightFront.setDir(LOW);
   rightBack.setDir(HIGH);
  leftFront.setPwm(spdl);
  leftBack.setPwm(spdl);
  rightFront.setPwm(spdl);
  rightBack.setPwm(spdl);
  }
  else if(lx<-40 && ly==0)
  {


   spdr = map(lx, 40, 127, 0, spdrMax);
   leftFront.setDir(LOW);
   leftBack.setDir(HIGH);
   rightFront.setDir(HIGH);
   rightBack.setDir(LOW);
   leftFront.setPwm(spdr);
   leftBack.setPwm(spdr);
   rightFront.setPwm(spdr);
   rightBack.setPwm(spdr);
  }

  else if(ly<-40 && lx==0)
  {
    spdl = map(ly, -40, -128, 0, spdlMax);
    leftFront.setDir(HIGH);
  leftBack.setDir(HIGH);
   rightFront.setDir(HIGH);
   rightBack.setDir(HIGH);
  
  leftFront.setPwm(spdl);
  leftBack.setPwm(spdl);
  rightFront.setPwm(spdl);
  rightBack.setPwm(spdl);
  }
  else if(ly>40 && lx==0)
  {
    spdl = map(lx, 40, 127, 0, spdlMax);
    leftFront.setDir(LOW);
  leftBack.setDir(LOW);
   rightFront.setDir(LOW);
   rightBack.setDir(LOW);
  leftFront.setPwm(spdl);
  leftBack.setPwm(spdl);
  rightFront.setPwm(spdl);
  rightBack.setPwm(spdl);
  }
  if(ry<buff2 && (rx>bufneg && rx<bufpos))
      {
        speed_slow = map(ry, buff2, -128, 0, slow);
        forward_slow(speed_slow);
          Serial.println("Forward slow");
      }
  else if(ry>buff1 &&( rx>bufneg && rx<bufpos))
      {
         speed_slow = map(ry,buff1, 127, 0,slow);
        backward_slow(speed_slow);
         Serial.println("backward Slow");
      }
  else if(rx<buff2 && (ry>bufneg && ry<bufpos))
      {
        
    speed_fast=map(rx, buff2, -128, 0,slow);
        left_slow(speed_slow);
          Serial.println("left slow");
      }
  else if(rx>buff1 && (ry>bufneg && ry<bufpos))
      {
        speed_fast=map(rx, buff1, 127, 0, slow);
        right_slow(speed_slow);
          Serial.println("right slow");
      }

  if(lx>-40 && lx<40 && ly>-40 && ly<40 && rx>-40 && rx<40 && ry>-40 && ry<40)
  {
    leftFront.killMotor();
    rightBack.killMotor();
    rightFront.killMotor();
    leftBack.killMotor();
  }
}
