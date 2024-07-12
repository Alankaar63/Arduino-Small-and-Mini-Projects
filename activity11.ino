#define BUTTONPIN 2
#define RED 8
#define YELLOW 7
#define GREEN 12

int redState = LOW;
int buttonState;
int toggleLedState = 1;

unsigned long timeStart;
unsigned long interval = 40;

unsigned long timeRedStart;
unsigned long redInterval = 1000;

void setProgram() {
  timeStart = millis();
  timeRedStart = millis();
  Serial.begin(115200);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUTTONPIN, INPUT);
  buttonState = digitalRead(BUTTONPIN);
}

void redLed() {
  if (redState == LOW) {
    redState = HIGH;
  } else {
    redState = LOW;
  }
  digitalWrite(RED, redState);
}

void toggleLed2_3() {
  if (buttonState == HIGH) {
    if (toggleLedState == 1) {
      digitalWrite(YELLOW, HIGH);
      digitalWrite(GREEN, LOW);
      toggleLedState = 2;
    } else {
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, HIGH);
      toggleLedState = 1;
    }
  }
}

void setup() {
  setProgram();
}

void loop() {
  unsigned long timeNow = millis();

  if (timeNow - timeStart > interval) {
    int buttonNewState = digitalRead(BUTTONPIN);
    if (buttonNewState != buttonState) {
      timeStart = timeNow;
      buttonState = buttonNewState;
      toggleLed2_3();
    }
  }

  if (timeNow - timeRedStart > redInterval) {
    redLed();
    timeRedStart = timeNow;
  }
}


