#define RED 12
#define YELLOW 11
#define GREEN 10
#define BUTTONPIN 7
int led_brightness =1;
byte LED_ARRAY[3] = {RED,YELLOW,GREEN};

void setup_led()
{
  for(int i=0;i<3;i++)
  {
    pinMode(LED_ARRAY[i],OUTPUT);
  }
}

void LED_STATE()
{
  for (int i=0;i<3;i++)
  {
    digitalWrite(LED_ARRAY[i],LOW);
  }
}

void LED_TOGGLE()
{
  
    if (led_brightness == 1)
    {
      digitalWrite(RED,HIGH);
      digitalWrite(GREEN,HIGH);
      digitalWrite(YELLOW,LOW);
      led_brightness = 2;

    }
    else 
    {
      digitalWrite(YELLOW,HIGH);
      digitalWrite(RED,LOW);
      digitalWrite(GREEN,LOW);
      led_brightness = 1;
    }

}
void setup() {
  pinMode(BUTTONPIN,INPUT);
  setup_led();
  LED_STATE();
}

void loop() {
  if(digitalRead(BUTTONPIN)==LOW)
  {
    LED_TOGGLE();
    delay(300);
  }

}
