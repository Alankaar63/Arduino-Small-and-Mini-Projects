#define RED 12
#define YELLOW 11
#define GREEN 10
#define TRIGGERPIN 7
#define ECHOPIN 2

unsigned long timeStartUltrasonicSensor = millis();
unsigned long timeInterval = 3000;

volatile unsigned long pulseStart;
volatile unsigned long pulseEnd;
volatile bool flag = false;

void trigger() {
  digitalWrite(TRIGGERPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGERPIN, LOW);
}

void powerOnLedSource(double distance) {
  if (distance >= 100) {
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
    Serial.println("YOU CAN GO!");
  } else if (distance >= 15) {
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    Serial.println("WAIT!");
  } else {
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    Serial.println("WARNING! OBSTACLE TOO CLOSE!");
  }
}
double getUltrasonicSensor() {
  double durationMicros = pulseEnd - pulseStart;
  double distance = durationMicros / 58.0;
  return distance;
}

void echoInterrupt() {
  if (digitalRead(ECHOPIN) == HIGH) {
    pulseStart = micros();
  } else {
    pulseEnd = micros();
    flag = true;
  }
}
void setup() {
  Serial.begin(115200);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGGERPIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ECHOPIN),
                  echoInterrupt, CHANGE);
}

void loop() {
  unsigned long timeNowUltrasonicSensor = millis();
  if (timeNowUltrasonicSensor - timeStartUltrasonicSensor > timeInterval) {
    timeStartUltrasonicSensor = timeNowUltrasonicSensor;
    trigger();
    if (flag) {
      flag = false;
      double distance = getUltrasonicSensor();
      powerOnLedSource(distance);
    }
  }
}
