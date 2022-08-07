int temp, counter1 = 0,counter2=0; 
int setpoint1=0,setpoint2=0;




#define dir1 4
#define pwm1 5
#define dir2 6
#define pwm2 7
#define wheel 100 // size in mm
#define gear 47
#define count_per_rev gear*7*4 // count per revolution


void setup() {
  Serial.begin (115200);

  pinMode(2, INPUT_PULLUP); // internal pullup input pin 2 
  pinMode(3, INPUT_PULLUP); // internal pullup input pin 3
    pinMode(18, INPUT_PULLUP); // internal pullup input pin 2 
  pinMode(19, INPUT_PULLUP);
  
  
//Setting up interrupt
  //A rising pulse from encodenren activated A(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(2), a1, RISING);
   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(3), b1, RISING);

  attachInterrupt(digitalPinToInterrupt(18), a2, RISING);
   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(19), b2, RISING);
  }
   
  void loop() {
//   Serial.print("counter1  ");
//   Serial.println(counter1);
//   Serial.print("counter2  ");
//   Serial.println(counter2);
   digitalWrite(dir1,LOW);
   analogWrite(pwm1,200);
   digitalWrite(dir2,HIGH);
   analogWrite(pwm2,200);
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
