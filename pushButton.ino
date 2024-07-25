#define BUTTONPIN 2
#define LEDPIN 8

void setup() {
  Serial.begin(9600);
  pinMode(BUTTONPIN,INPUT);
  pinMode(LEDPIN,OUTPUT);

}

void loop() {
  if (digitalRead(BUTTONPIN)==HIGH)
  {
    digitalWrite(LEDPIN,HIGH);
  }
  else 
  {
    digitalWrite(LEDPIN,LOW);
    
  }
  

}
