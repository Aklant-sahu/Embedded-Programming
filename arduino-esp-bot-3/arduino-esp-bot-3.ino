#include<SharpIR.h>


/*-----distance sensors-----------*/
#define IR1 A2
#define IR2 A4
#define model 430
float dist1=0,dist2=0;
SharpIR SharpIR1(IR1, model); //left side
SharpIR SharpIR2(IR2, model); // right side
const int mindist=4,minerror=0,minerror2=3,minerror3=6;
const int autospeed=60;
const int autoint=200;
/*----------------------variable declaration--------------------------*/

const int stepPin = 44; //Stepper motor
const int dirPin =48; 
const int enPin = 52;
//const int stepdelay=365;
const int stepdelay=700;
int prev_state=0;

const int clockwise=100;
#define pwmR1 3 //Base motors
#define dirR1 27
#define pwmL1 2
#define dirL1 25
//
//#define pwmL2 3
//#define dirL2 27
//#define pwmR2 2
//#define dirR2 25

#define pwmL2 7
#define dirL2 35
#define pwmR2 6
#define dirR2 33



int pwmg = 10; //Gripper motor pinouts for piling lagori
int dirg = 36;
int spg =200;

int pwmb1 = 4; //Back motor pinouts to pick balls from rack
int dirb1 = 29;
int pwmb2 = 5;
int dirb2 = 31;
int spb = 200;
int prev_intake=0;


//int pwmb1 = 7; //Back motor pinouts to pick balls from rack
//int dirb1 = 35;
//int pwmb2 = 6;
//int dirb2 = 33;
//int spb = 180;


char c;

int indexA,indexB,indexC,indexD,indexE,indexF,indexG,indexH,indexI,indexJ,indexK,indexL,indexM,indexN,indexO,indexP;
String data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16;
int lx,ly,rx,ry,cro,squ,tri,cir,upp,downn,leftt,rightt,ll1,ll2,rr1,rr2;

int upc=0, gripc=0, lc=0, rc=0;
int speedm = 25;
int speed_fast =0;
int speed_slow =0;
int fast = 120;
int slow = 80;

/*-----------------*/
int bufpos=60;
int bufneg=-60;
int buff1=40;
int buff2=-40;
//unsigned long timer=millis();
static uint32_t timer1=0,timer2=2,timer3=3;

unsigned long currentMicros;
int interval1=100;
int interval2=10;

 String datain ;
/*------------------------------------------------*/



void setup() {
//TCCR5B = TCCR5B & B11111000 | B00000010;    // set timer 5 divisor to     8 for PWM frequency of  3921.16 Hz
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);

  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);

  pinMode(pwmg,OUTPUT);
  pinMode(dirg,OUTPUT);
  pinMode(pwmb1,OUTPUT);
  pinMode(dirb1,OUTPUT);
  pinMode(pwmb2,OUTPUT);
  pinMode(dirb2,OUTPUT);

  pinMode(pwmL1, OUTPUT);
  pinMode(pwmL2, OUTPUT);
  pinMode(dirL1, OUTPUT);
  pinMode(dirL2, OUTPUT);
  pinMode(pwmR1, OUTPUT);
  pinMode(pwmR2, OUTPUT);
  pinMode(dirR1, OUTPUT);
  pinMode(dirR2, OUTPUT);

  Serial.begin(115200);
  Serial2.begin(57600);
}

void loop() {
fetch_data();
  //
//   parse_data(datain); 
//   ps_print();
//
parse_data(datain);
   
if (prev_intake==1 || rr1==1){
    prev_intake=1;
 distances();
  autopickup();

}
else{
navigation_decision();
gripper();
intake();
 lifting();
 rotation();

//unsigned long currentMillis = millis();
currentMicros = micros();
if ((leftt==1 || rightt==1)){
 
gripper();


}

}
datain="";
}
