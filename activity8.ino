#define LEDPIN 7
int blinkstate = 500;
int LEDSTATE = LOW;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int val = Serial.parseInt();
    if (val >= 100 && val <= 4000) {
      blinkstate = val;
    }
  }

  if (LEDSTATE == LOW) {
    LEDSTATE = HIGH;
  } else {
    LEDSTATE = LOW;
  }
  
  digitalWrite(LEDPIN, LEDSTATE);  // This line sets the LED to the current state (HIGH or LOW)
  delay(blinkstate);
}

