
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int val=LOW,a,b,count=1;
void setup() {
  // put your setup code here, to run once:
pinMode(7,INPUT);
Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.

}

void loop() {
  // put your main code here, to run repeatedly:

val=digitalRead(7);







if(val==HIGH)
{

  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
    lcd.print(count);
    count++;
  
}
for(b=0;val==HIGH;b++)
{
  val=digitalRead(7);
 
}




}
