#include<SharpIR.h>

/*----------------------variable declaration--------------------------*/
/*-----distance sensors-----------*/
#define IR1 A2
#define IR2 A4
#define IR3 A8
#define IR4 A10
#define model 430
float dist1=0,dist2=0,dist3=0,dist4=0;
SharpIR SharpIR1(IR1, model); //left side
SharpIR SharpIR2(IR2, model);
SharpIR SharpIR3(IR3, model); //left side
SharpIR SharpIR4(IR4, model);// right side
const int mindist=4,minerror=0,minerror2=3,minerror3=6,mindist1=4;
 int autospeed=60;
const int autoint=190;
int prev_intake1=0;


/*----------------------Stepper motor--------------------------*/
//#define stepPin A9//Stepper motor
//#define dirPin A6
//#define enPin A7

const int stepPin = 45; 
const int dirPin =49; 
const int enPin = 53;
//const int stepdelay=365;
const int stepdelay=700;
int prev_state=0;
char prev_step_state='H';

/*---------------------Base motor--------------------------*/

const int clockwise=80;
//#define pwmR1 12 //Base motors
//#define dirR1 32
//#define pwmL1 13
//#define dirL1 34

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


/*----------------------Mega torque motor---lift--------------------------*/

int pwmg = 5; //Mega torque motor pinouts for piling lagori
int dirg = 31;
int spg =200;

#define ENCA A7 // YELLOW
#define ENCB A6
//int prev_enca=0,prev_encb=0;
int prev_a_state=0,prev_b_state=0;
int count=0;
//int stop_count1=2000,stop_count2=4000,stop_count3=6000,stop_count4=8000;
int stop_count[] = {2000, 4000,6000, 8000};
int st_count=0,target=0;
int lifting_up=0,lifting_down=0;
const int p=0.8;

/*----------------------Intake motor--------------------------*/

int pwmb1 = 10; //Back motor pinouts to pick balls from rack
int dirb1 = 36;
int pwmb2 = 11;
int dirb2 = 38;
int spb = 255;
int prev_intake=0;


/*----------------------Data parsing--------------------------*/
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

/*----------------------Timing operations--------------------------*/
int bufpos=60;
int bufneg=-60;
int buff1=40;
int buff2=-40;
//unsigned long timer=millis();
static uint32_t timer1=0,timer2=2,timer3=3;

unsigned long currentMicros;
int interval1=238;
int interval2=100;

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

parse_data(datain);
   
if (prev_intake==1 || rr1==1){
    prev_intake=1;
 distances();
  autopickup();

}
else if(prev_intake1==1 || squ>40){
   prev_intake1=1;
  distances();
  autoposition();
}
else{
navigation_decision();
gripper();
intake();
 lifting();
 rotation();

unsigned long currentMillis = millis();
currentMicros = micros();
if ((leftt==1 || rightt==1)){
 
gripper();


}
//
}
datain="";
}
