#include <EEPROM.h>
#define LEDPIN 9
#define POTEN_PIN A4
#define EEPROM_ADDRESS 424
#define DEFAULT_VALUE 255
int LEDSTATE = LOW;

byte maxBrightness;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(LEDPIN, OUTPUT);
  maxBrightness = EEPROM.read(EEPROM_ADDRESS);

}

void loop() {
  if (Serial.available() > 0) {
    int data = Serial.parseInt();
    if ((data >= 0) && (data < 256)) {
      EEPROM.write(EEPROM_ADDRESS, data);
      maxBrightness = data;
    }
  }
  if (maxBrightness == 0) {
    // if(LEDSTATE == LOW){
    //   LEDSTATE = HIGH;
    // }
    // else{
    //   LEDSTATE = LOW;
    // }
    // digitalWrite(LEDPIN,LEDSTATE);
    maxBrightness = DEFAULT_VALUE;
  }

  int poten = analogRead(POTEN_PIN);
  int ledBrightness = poten / 4;
  if (ledBrightness > maxBrightness) {
    ledBrightness = maxBrightness;
  }
  analogWrite(LEDPIN, ledBrightness);
}
