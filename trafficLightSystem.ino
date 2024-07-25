#define RED 12
#define YELLOW 11
#define GREEN 10
void setup()
{
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(GREEN,OUTPUT);
  
  
}

void loop()
{
  digitalWrite(RED,HIGH);
  delay(3000);
  digitalWrite(RED,LOW);
  
  analogWrite(GREEN,255);
  delay(3000);
  analogWrite(GREEN,0);
  
  analogWrite(YELLOW,255);
  delay(1000);
  analogWrite(YELLOW,0);
  
 }
  
