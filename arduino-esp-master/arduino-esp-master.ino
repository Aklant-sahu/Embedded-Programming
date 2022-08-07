//#include<SoftwareSerial.h>
//
//SoftwareSerial mySerial(10,11);

int val;

char masterswitchdata;
void setup() {  
//  pinMode(10,INPUT);
//  pinMode(11,OUTPUT);
  
  // put your setup code here, to run once:
  pinMode(3,INPUT);
  

  pinMode(6,INPUT);
//   Serial.begin(19200);
//mySerial.begin(9600);
   Serial.begin(115200);

}

void loop() {
  
//  val=15;
//  mySerial.write(val);
//  delay(10);
//  if(mySerial.available()){
//     Serial.println(mySerial.read()); }
Serial.println("hi");
delay(10);
 
 

}
