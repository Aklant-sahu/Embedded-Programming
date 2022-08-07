void fetch_data(){

  
if(Serial2.available() > 0) {
//  Serial.print("available");
    // read the incoming bytes:
  datain= Serial2.readStringUntil('!');
}
}
