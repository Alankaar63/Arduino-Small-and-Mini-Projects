// C++ code
#define BUTTONPIN 2
#define RED 8
volatile bool buttonPress = false;
volatile int count = 0;

volatile unsigned long timeStart;
unsigned long debounceDelay = 50;
int LEDSTATE = LOW;

void buttonPressLed() {
  if (LEDSTATE == LOW) {
    LEDSTATE = HIGH;
  } else {
    LEDSTATE = LOW;
  }
  digitalWrite(RED, LEDSTATE);
}

void buttonRiseInterrupt() {
  unsigned long timeNow = millis();
  if (timeNow - timeStart > debounceDelay) {
    timeStart = timeNow;
    buttonPress = true;
  }
}
void setup() {
  timeStart = millis();
  Serial.begin(115200);
  pinMode(RED, OUTPUT);
  pinMode(BUTTONPIN, INPUT);
  digitalWrite(RED, LEDSTATE);
  attachInterrupt(digitalPinToInterrupt(BUTTONPIN),
                  buttonRiseInterrupt, RISING);
}

void loop() {
  if (buttonPress) {
    buttonPress = false;
    buttonPressLed();
    count += 1;
    Serial.println(count);
  }
}
