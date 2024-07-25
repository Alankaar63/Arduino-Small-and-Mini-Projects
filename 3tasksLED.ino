#define RED 12
#define YELLOW 10
#define GREEN 11

#define BUTTONPIN 2
#define POTEN A4

int blinkstate = 470;
int LEDSTATE = LOW;
unsigned long timeStart;


void setup() {
  timeStart = millis();
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUTTONPIN, INPUT);
}

void loop() {

  unsigned long timeNow = millis();
  if (Serial.available() > 0) {
    int val = Serial.parseInt();
    if (val > 100 && val < 4000) {
      blinkstate = val;
    }
  }

  if (timeNow - timeStart > blinkstate) {
    if (LEDSTATE == LOW) {
      LEDSTATE = HIGH;
    } else {
      LEDSTATE = LOW;
    }
    digitalWrite(RED, LEDSTATE);
    timeStart = timeNow;
  }

  if (digitalRead(BUTTONPIN) == HIGH) {
    digitalWrite(GREEN, HIGH);
  } else {
    digitalWrite(GREEN, LOW);
  }
  int poten = analogRead(POTEN);
  int led_brightness = poten / 4;
  analogWrite(YELLOW, led_brightness);
}
