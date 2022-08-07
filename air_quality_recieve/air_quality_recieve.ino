
int indexA,indexB,indexC,indexD,indexE,indexF,indexG;
String data1,data2,data3,data4,data5,data6,data7;
int t,h,p,mq2value,mq135value,mq7value,dustDensity;
String datain;
#include <WiFi.h>
#include <ThingSpeak.h>
unsigned long lastTime = 0;
unsigned long timerDelay = 100;



const char* ssid = "Zaid";   
const char* password = "zaidmalik";  

WiFiClient  client;

unsigned long myChannelNumber = 1;


const char * myWriteAPIKey = "J9VUAXH13CNWNXQJ";

void setup() {
  // put your setup code here, to run once:
Serial.begin(57600);
Serial2.begin(38400);
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
 
   if ((millis() - lastTime) > timerDelay) { 
  if (Serial2.available() > 0) {
//  Serial.print("available");
    // read the incoming bytes:
  datain= Serial2.readStringUntil('!');
  }
//  Serial.println(datain);
  // put your main code here, to run repeatedly:
parse_data(datain);
Serial.print(t);
//Serial.print(",");
Serial.print(h);
//Serial.print(",");
Serial.print(mq2value);
//Serial.print(",");
Serial.print(p);
//Serial.print(",");
Serial.print(mq7value);

//Serial.print(",");
Serial.print(mq135value);
Serial.print(" ");
Serial.println(dustDensity);

ThingSpeak.setField(1, t);
  ThingSpeak.setField(2, h);
    ThingSpeak.setField(3, mq2value);
     ThingSpeak.setField(4, p);
      ThingSpeak.setField(5, mq7value);
       ThingSpeak.setField(6, mq135value);
         ThingSpeak.setField(7,dustDensity);

    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
//    delay(100);
   lastTime = millis();
  }
}
