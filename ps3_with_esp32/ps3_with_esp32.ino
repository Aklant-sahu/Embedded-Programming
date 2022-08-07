/* Hello World Example


   This example code is in the Public Domain (or CC0 licensed, at your option.)


   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
  
#include <Ps3Controller.h>
void setup()
{
    Serial.begin(115200);
 
    Ps3.begin("YourDeviceAddress");
 
    Serial.println("Initialization finished.");
}
void loop()
{
  if (Ps3.isConnected()){
    Serial.println("Controller connected!");
  }
  else{
    Serial.println("Not connected!");
  }
 
  delay(1000);
}
