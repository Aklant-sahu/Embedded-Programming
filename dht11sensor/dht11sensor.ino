#include <DHT.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#define seaLevelPressure_hPa 1010
Adafruit_BMP085 bmp;
#define DHTPIN 8
#define DHTTYPE DHT11
#define mq135 A0
#define mq2pin A1

int mq2value;
int mq135value;
char mq2[]= " ";
DHT dht(DHTPIN, DHTTYPE);
void setup() 
{
  pinMode(mq135,INPUT);
pinMode(mq2pin,INPUT);
pinMode(A4,INPUT);
pinMode(A5,INPUT);


 dht.begin();
  Serial.begin(9600);
}

void loop() 
{
  
  mq2value = analogRead(mq2pin);
  mq135value=analogRead(mq135);
   float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  Serial.print("Temp= ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("  Humid = ");
  Serial.print(h);
  Serial.print(" % ");
  if (mq2value<=700){
   Serial.print(" No smoke ");  
  }
  else{
   Serial.print(" Smoke detected ");  
  }
      Serial.print(" Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.print(" Pa ");

    Serial.print(" Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.print(" meters ");

  
             // prints the value read

 Serial.print("  AirQua=");
Serial.print(mq135value);               // prints the value read
Serial.println(" PPM");
//400ppm – 750ppm: Good for health
//750 ppm – 1200 ppm: Take care
//1200 ppm (and above): Harmful to health




  
  delay(500);
}
