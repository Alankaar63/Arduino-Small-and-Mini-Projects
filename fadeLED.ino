#define LEDPIN 10

void setup() {
  pinMode(LEDPIN,OUTPUT);
  
}

void loop() {
  for (int i=0;i<=255;i++)
  {
    analogWrite(LEDPIN,i);
    delay(5);
  }
  for (int i=255;i>=0;i--)
  {
    analogWrite(LEDPIN,i);
    delay(5);
  }
  

}
