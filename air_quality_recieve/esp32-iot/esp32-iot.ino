
int indexA,indexB,indexC,indexD,indexE,indexF,indexG;
String data1,data2,data3,data4,data5,data6,data7;

String datain;
#include <WiFi.h>
#include <ThingSpeak.h>
unsigned long lastTime = 0;
unsigned long timerDelay = 100;
float distances,threshold,overflowing;



const char* ssid = "JIO";   
const char* password = "00000000";  

WiFiClient  client;

unsigned long myChannelNumber = 1;


const char * myWriteAPIKey = "TBXXNGREKY0IWQH8";

void setup() {
  // put your setup code here, to run once:
Serial.begin(57600);
//Serial2.begin(38400);
 WiFi.mode(WIFI_STA);  
 WiFi.begin(ssid, password);
  ThingSpeak.begin(client); 

      while(WiFi.status() != WL_CONNECTED){
        Serial.print("Attempting to connect");
//        WiFi.begin(ssid, password);
//         delay(3000);
      }
 Serial.println("\nConnected.");
}

void loop() {
 
 
  if (Serial.available() > 0) {
//  Serial.print("available");
    // read the incoming bytes:
  datain= Serial.readStringUntil('!');
  }
//  Serial.println(datain);
  // put your main code here, to run repeatedly:
parse_data(datain);
Serial.print(distances);

ThingSpeak.setField(1, distances);
  ThingSpeak.setField(2, threshold);
    ThingSpeak.setField(3, overflowing);

    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
//    delay(100);
  
}
