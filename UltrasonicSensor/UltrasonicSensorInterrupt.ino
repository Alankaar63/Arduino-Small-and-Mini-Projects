#define ECHOPIN 3
#define TRIGGERPIN 13

unsigned long timeStart;
unsigned long timeInterval = 500000;

volatile unsigned long timePulseBegin;
volatile unsigned long timePulseEnd;
volatile bool flag = false;

void trigger() {
  digitalWrite(TRIGGERPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGERPIN, LOW);
}

void echoPinInterrupt() {
  if (digitalRead(ECHOPIN) == HIGH)  //start measuring
  {
    timePulseBegin = micros();
  } else  // stop measuring
  {
    timePulseEnd = micros();
    flag = true;
  }
}

double getUltrasonicSensor() {
  double durationMicros = timePulseEnd-timePulseBegin;
  double distance = durationMicros / 58.0;
  return distance;
}

void setup() {
  Serial.begin(115200);
  timeStart = micros();
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGGERPIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ECHOPIN),
                  echoPinInterrupt, CHANGE);
}
void loop() {
  unsigned long timeNow = micros();
  if (timeNow - timeStart > timeInterval) {
    timeStart = timeNow;
    trigger();
    if (flag) {
      flag = false;
      double distance = getUltrasonicSensor();
      Serial.println(distance);
    }
  }
}
