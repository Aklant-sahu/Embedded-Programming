#include <DHT.h>


#include <Wire.h>
#include <Adafruit_BMP085.h>
#define seaLevelPressure_hPa 1010
Adafruit_BMP085 bmp;
#define DHTPIN 8
#define DHTTYPE DHT11
#define mq135 A0
#define mq2pin A1
#define mq7pin A2

int mq2value;
int mq135value,mq7value;
char mq2[]= " ";
DHT dht(DHTPIN, DHTTYPE);
void setup()
{
  pinMode(mq135,INPUT);
pinMode(mq2pin,INPUT);
pinMode(mq7pin,INPUT);
pinMode(A4,INPUT);
pinMode(A5,INPUT);


 dht.begin();
  Serial.begin(9600);
}

void loop()
{
 
  mq2value = analogRead(mq2pin);
  mq135value=analogRead(mq135);
    mq7value=analogRead(mq7pin);
   float h = dht.readHumidity();
  float t = dht.readTemperature();
  if(isnan(h) || isnan(t)){
    t=31;
    h=60;
  }
 
//  Serial.print("Temp= ");
//  Serial.print(t);
//  Serial.print(" *C ");
//  Serial.print("  Humid = ");
//  Serial.print(h);
//  Serial.print(" % ");
//  if (mq2value<=700){
//   Serial.print(" No smoke ");  
//  }
//  else{
//   Serial.print(" Smoke detected ");  
//  }
//Serial.print("smoke");
//Serial.print(mq2value);
//Serial.print(" ");
//      Serial.print(" Pressure = ");
//    Serial.print(0.95);
//    Serial.print(" atm ");
//
//    Serial.print(" Altitude = ");
//    Serial.print(bmp.readAltitude());
//    Serial.print(" meters ");

 
             // prints the value read
//Serial.print("  C0=");
//Serial.print(mq7value);
//Serial.print(" ");
// Serial.print("  AirQua=");
//Serial.print(mq135value);               // prints the value read
//Serial.println(" PPM");
//400ppm – 750ppm: Good for health
//750 ppm – 1200 ppm: Take care
//1200 ppm (and above): Harmful to health

Serial.print(t); Serial.print("A");
Serial.print(h); Serial.print("B");
Serial.print(mq2value); Serial.print("C");
Serial.print(0.95); Serial.print("D");
Serial.print(mq7value); Serial.print("E");
Serial.print(mq135value); Serial.print("F");
Serial.print("!");

 
  delay(500);
}
