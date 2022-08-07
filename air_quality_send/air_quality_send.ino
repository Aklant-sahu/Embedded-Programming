#include <DHT.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4);

#include <Wire.h>
#include <Adafruit_BMP085.h>
// dust sensor
#define measurePin A3 //Connect dust sensor to Arduino A0 pin
int ledPower = 2;   //Connect 3 led driver pins of dust sensor to Arduino D2

int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
int dustDensity = 0;
#define seaLevelPressure_hPa 1010
Adafruit_BMP085 bmp;
#define DHTPIN 8
#define DHTTYPE DHT11
#define mq135pin A0
#define mq2pin A1
#define mq7pin A2
float prev_t=31,prev_h=60;
int mq2value;
int mq135value,mq7value;

DHT dht(DHTPIN, DHTTYPE);
void setup()
{  pinMode(ledPower,OUTPUT);
  pinMode(mq135pin,INPUT);
pinMode(mq2pin,INPUT);
pinMode(mq7pin,INPUT);
pinMode(A4,INPUT);
pinMode(A5,INPUT);


 dht.begin();
  Serial.begin(57600);
  mySerial.begin(38400);
//mySerial.begin(38400);
}

void loop()
{
  digitalWrite(ledPower,LOW); // power on the LED
  delayMicroseconds(samplingTime);

  voMeasured = analogRead(measurePin); // read the dust value

  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH); //
  mq2value = analogRead(mq2pin);
  mq135value=analogRead(mq135pin);
    mq7value=analogRead(mq7pin);
   int h = dht.readHumidity();
   delay(20);
  int t = dht.readTemperature();
  if(isnan(h) || isnan(t) || h==0 ||t==0){
    t=prev_t;
    h=prev_h;
  }
  else{
    prev_t=t;
    prev_h=h;
  }
  calcVoltage = voMeasured * (5.0 / 1024.0);

  
  // Chris Nafis (c) 2012
  dustDensity = 170 * calcVoltage - 0.1;

  Serial.print("dust " );
  Serial.print(dustDensity);
 Serial.print(" " );
  Serial.print("Temp= ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("  Humid = ");
  Serial.print(h);
  Serial.print(" % ");
//  if (mq2value<=700){
//   Serial.print(" No smoke ");  
//  }
//  else{
//   Serial.print(" Smoke detected ");  
//  }
Serial.print("smoke");
Serial.print(mq2value);
Serial.print(" ");
      Serial.print(" Pressure = ");
    Serial.print(0.95);
    Serial.print(" atm ");

//    Serial.print(" Altitude = ");
//    Serial.print(bmp.readAltitude());
//    Serial.print(" meters ");

 
             // prints the value read
Serial.print("  C0=");
Serial.print(mq7value);
Serial.print(" ");
 Serial.print("  AirQua=");
Serial.print(mq135value);               // prints the value read
Serial.println(" PPM");
//400ppm – 750ppm: Good for health
//750 ppm – 1200 ppm: Take care
//1200 ppm (and above): Harmful to health

//mySerial.print(t); mySerial.print("A");
//mySerial.print(h); mySerial.print("B");
//mySerial.print(mq2value); mySerial.print("C");
//mySerial.print(1); mySerial.print("D");
//mySerial.print(mq7value); mySerial.print("E");
//mySerial.print(mq135value); mySerial.print("F");
//mySerial.print("!");


mySerial.print(t); mySerial.print("A");
mySerial.print(h); mySerial.print("B");
mySerial.print(mq2value); mySerial.print("C");
mySerial.print(1); mySerial.print("D");
mySerial.print(mq7value); mySerial.print("E");
mySerial.print(mq135value); mySerial.print("F");
mySerial.print(dustDensity); mySerial.print("G");
mySerial.print("!");
delay(3000);

}
