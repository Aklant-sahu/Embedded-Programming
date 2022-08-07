
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int val=HIGH,a,b,count=1;
void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  attachInterrupt(0,buttonPressed,CHANGE);

}

void loop() {
  // put your main code here, to run repeatedly:
if(val==LOW)
{

  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
    lcd.print(count);
    count++;
    val=HIGH;
  
}
}
void buttonPressed()
{
  val=digitalRead(2);
}
