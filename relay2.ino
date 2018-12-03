#define OUT1 8    //set your pin numbers here
#define OUT2 9
#define OUT3 10
int to_blink=0;
unsigned long previousMillis = 0;        // will store last time LED was updated

unsigned long delay1=1800000;  //30min*60sec*1000ms=1800000ms
unsigned long delay2=900000;    //15mins*60sec*1000ms=900000ms
unsigned long delay3=1800000; //30min*60sec*1000ms=1800000ms


unsigned long BLINK_FOR=900000; //15min*60sec*1000ms=900000 sec for testing. 

void setup() {
int once_repeted=0; //flag
int to_blink=0; //flag
 int interval=1000; 
 pinMode(OUT1,OUTPUT);
pinMode(OUT2,OUTPUT);
pinMode(OUT3,OUTPUT);

//initiall all relays off
digitalWrite(OUT1,HIGH);
digitalWrite(OUT2,HIGH);
digitalWrite(OUT3,HIGH);
//ASSUMING LOW LEVEL -----> RELAY ON
}

void relay1(void);
void relay2(void);
void relay3(void);
void blink_relay(void);



void relay1()
{
  digitalWrite(OUT1,LOW); //turn on;
  unsigned long startMillis = millis();
while (millis() - startMillis < delay1); //30mins
  digitalWrite(OUT1,HIGH);//turn off
}

void relay2()
{
  digitalWrite(OUT2,LOW); //turn on
  unsigned long startMillis = millis();
while (millis() - startMillis < delay2); //15mins
digitalWrite(OUT2,HIGH); //turn off relay 2

}
void relay3()
{
  digitalWrite(OUT3,LOW); //turn on;
  unsigned long startMillis = millis();
while (millis() - startMillis < delay3); //15mins
  digitalWrite(OUT3,HIGH);//turn off
}

void blink_relay()
{
  unsigned long startMillis = millis();
while (millis() - startMillis < BLINK_FOR )//Blink for 30mins
  {
    digitalWrite(OUT2,LOW); //turn on
    delay(1000);//delay
    digitalWrite(OUT2,HIGH);//turn off
    delay(1000);//wait a second
  }
}

void loop()
{
  relay1();
  relay2();
  relay3();
  blink_relay();
}
