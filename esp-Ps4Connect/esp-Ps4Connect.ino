#include <PS4Controller.h>
//esptool --chip esp32 erase_flash  do this in the base env and thennn connect
void setup() {
  Serial.begin(115200);

  // Replace the "1a:2b:3c:01:01:01" with the MAC address
  // the controller wants to pair to
  // Note: MAC address must be unicast
  PS4.begin("c8:b2:9b:75:22:df");
  Serial.println("Ready.");
}

void loop() {
  if (PS4.isConnected()) {
    Serial.println("Connected!");
  }

  delay(3000);
}
