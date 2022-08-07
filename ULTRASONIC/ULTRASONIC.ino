float val,dist;
void setup(){
// put your setup code here, to run once:
  pinMode(3,INPUT);
 pinMode(4,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(4,LOW);
  delayMicroseconds(2);
  digitalWrite(4,HIGH);
  delayMicroseconds(10);
    digitalWrite(4,LOW);
    
    val=pulseIn(3,HIGH);
    dist=(val/2000000)*33500.;
   
    if(dist<2.5||dist>380)
    {
      Serial.println("out of range");
    }
    else
    {
       Serial.print("Distance(in cm)-");
    Serial.println(dist);
    }
    delay(500);
    
    
  

}
