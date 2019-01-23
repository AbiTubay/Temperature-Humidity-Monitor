#include <dht.h>
// include the library code
// must have DHT library
#include <LiquidCrystal.h>

#define dht_apin A0

dht dht;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
    dht.read11(dht_apin);
    lcd.setCursor(0,0);
    lcd.print("humid = ");
    lcd.print(dht.humidity);
    lcd.print("%  ");
    lcd.setCursor(0,1);
    lcd.print("temp = ");
    lcd.print(dht.temperature); 
    lcd.print("C");
    delay(2000);
}
