#include <LiquidCrystal.h>
#define ECHOPIN 2
#define TRIGGERPIN 9
#define LCD_RS A5
#define LCD_E A4
#define LCD_DB4 6
#define LCD_DB5 5
#define LCD_DB6 3
#define LCD_DB7 4

unsigned long timeStart;
unsigned long timeInterval = 60;

LiquidCrystal lcd(LCD_RS, LCD_E, LCD_DB4, LCD_DB5, LCD_DB6, LCD_DB7);

void trigger() {
  digitalWrite(TRIGGERPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGERPIN, LOW);
}

double getUltrasonicSensor() {
  double durationMicros = pulseIn(ECHOPIN, HIGH);
  double distance = durationMicros / 58.0;
  return distance;
}

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  timeStart = millis();
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  lcd.setCursor(0, 0);
  lcd.print(timeInterval);
  lcd.print("ms");
}

void loop() {
  unsigned long timeNow = millis();
  if (timeNow - timeStart > timeInterval) {
    timeStart = timeNow;
    trigger();
    double distance = getUltrasonicSensor();
    lcd.setCursor(0, 1);
     lcd.print("                "); // 16 spaces to clear the line

    lcd.setCursor(0, 1);
    lcd.print("dist:");
    lcd.print(distance, 2); // Print distance with 2 decimal places
    delay(500);

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}
