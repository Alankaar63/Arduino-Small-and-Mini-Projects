#include <LiquidCrystal.h>
#define LCD_RS A5
#define LCD_E A4
#define LCD_DB4 6
#define LCD_DB5 5
#define LCD_DB6 3
#define LCD_DB7 4
int counter = 1;
LiquidCrystal lcd(LCD_RS, LCD_E, LCD_DB4, LCD_DB5, LCD_DB6, LCD_DB7);
void setup() {
  lcd.begin(16, 2);
  // lcd.setCursor(0,0);
  // lcd.print("hello");
  // lcd.setCursor(0,1);
  // lcd.print("world");
  // delay(1000);
  // lcd.setCursor(6, 1);
  // lcd.print("ARDUINO YOU AS WELL!");
}

void loop() {
  // lcd.setCursor(6, 0);
  // lcd.print(counter);
  // counter++;
  // delay(1000);
  if (counter > 0 && counter <= 3) {
    lcd.setCursor(1, 0);
    lcd.print(counter);
    counter++;
    delay(1000);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("BARCA BEST!");
    while (true) {
    }
  }
}
