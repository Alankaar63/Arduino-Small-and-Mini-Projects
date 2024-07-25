# define LED_PIN 9
# define P_PIN A4
void setup() {
  pinMode(LED_PIN,OUTPUT);

}

void loop() {
  int poten = analogRead(P_PIN);
  int led_brightness = poten/4;
  analogWrite(LED_PIN,led_brightness); 
  // delayMicroseconds(1000000);
 
}
