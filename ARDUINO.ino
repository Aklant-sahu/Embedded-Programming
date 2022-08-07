#include<Servo.h>
double kp = 0.5;
double ki = 1;
double kd = 0.1;
int val;
Servo myservo;
 
unsigned long currentTime, previousTime;
double elapsedTime;
double error;
double lastError;
double input, output, setPoint=0;
double cumError, rateError;
int i;
 

void setup(){
// put your setup code here, to run once:
  pinMode(9,OUTPUT);

  Serial.begin(9600);
  myservo.attach(9);
  input=90;
//  for(i=0;i<input;i++)
//  {
//  myservo.write(i);
//    delay(10);
//  } 
//  
  
}

void loop() 
{
  //put your main code here, to run repeatedly:
  output = computePID(input);
  delay(100);
  myservo.write(output);
    
}
double computePID(double inp){     
        currentTime = millis();                //get current time
        elapsedTime = (double)(currentTime - previousTime);        //compute time elapsed from previous computation
        
        error = setPoint - inp;                                // determine error
        cumError += error * elapsedTime;                // compute integral
        rateError = (error - lastError)/elapsedTime;   // compute derivative
 
        double out = kp*error + ki*cumError + kd*rateError;                //PID output               
 
        lastError = error;                                //remember current error
        previousTime = currentTime; 
  //remember current time
  Serial.print(elapsedTime);
  Serial.print("  error--");
  Serial.print(error);
  Serial.print("  output--");
  Serial.println(output);
               

 
        return -out;                                        //have function return the PID output
}
