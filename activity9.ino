#define RED 12
int blinkstate = 470;
int LEDSTATE = LOW;
unsigned long timeStart;


void setup() {
  timeStart = millis();
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(RED, OUTPUT);
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
}
