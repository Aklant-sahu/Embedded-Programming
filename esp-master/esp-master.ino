// this sample code provided by www.programmingboss.com
#define RXp2 16
#define TXp2 17
void setup() {
  // put your setup code here, to run once:
//  Serial.begin(19200);
  Serial2.begin(19200, SERIAL_8N1, RXp2, TXp2);
}
void loop() {
    Serial2.print("<");
    Serial2.print(123);
    Serial2.print(",");
    Serial2.print(456);
    Serial2.print(">");
    Serial2.println("!");
//    Serial.println("hiii");
}
