#include <LiquidCrystal.h>

#define LCD_RS A5
#define LCD_E A4
#define LCD_DB4 6
#define LCD_DB5 5
#define LCD_DB6 3
#define LCD_DB7 4

LiquidCrystal lcd(LCD_RS, LCD_E, LCD_DB4, LCD_DB5, LCD_DB6, LCD_DB7);

int cursor = 0;
void displayLcd(String string) {
  if ((string.length() > 16)) {
      string = "text too long!";
  }
  for (int i = string.length(); i<16;i++)
  {
    string+= " ";
  }
  lcd.setCursor(0, cursor);
  lcd.print(string);
  if (cursor == 0) {
    cursor = 1;
  } else {
    cursor = 0;
  }
}

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);
  lcd.begin(16, 2);
}

void loop() {
  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('\n');
    displayLcd(str);
    }
}
