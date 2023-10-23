/*
Szkic Arduino Sygnalizacja Świetlna - Polska
Autor: Kamil Kosmela, 22-10-2023
*/

#define LED_WR 5
#define LED_WY 6
#define LED_WG 7
#define LED_ER 10
#define LED_EY 11
#define LED_EG 12
#define BUTTON_W 4
#define BUTTON_E 3
int buttonState_W = 0;
int buttonState_E = 0;

void setup()
{
pinMode(LED_WR, OUTPUT); // pin wyjściowy dla diody LED west red
pinMode(LED_WY, OUTPUT); // pin wyjściowy dla diody LED west yellow
pinMode(LED_WG, OUTPUT); // pin wyjściowy dla diody LED west green
pinMode(LED_ER, OUTPUT); // pin wyjściowy dla diody LED east red
pinMode(LED_EY, OUTPUT); // pin wyjściowy dla diody LED east yellow
pinMode(LED_EG, OUTPUT); // pin wyjściowy dla diody LED east green
pinMode(BUTTON_W, INPUT); // pin wejściowy dla przycisku west
pinMode(BUTTON_E, INPUT); // pin wejściowy dla przycisku east
digitalWrite(LED_WR, HIGH); 
digitalWrite(LED_EG, HIGH);
}

void loop()
{
buttonState_W = digitalRead(BUTTON_W);
buttonState_E = digitalRead(BUTTON_E);


if ( buttonState_W == HIGH && digitalRead(LED_EG) == HIGH)
{
//zamykamy ruch dla east
digitalWrite(LED_EG, LOW);
digitalWrite(LED_EY, HIGH);
delay(2000);
digitalWrite(LED_EY, LOW);
digitalWrite(LED_ER, HIGH);
delay(3000); // czekamy, az pojazdy zdaza przejechac most
// otwieramy ruch dla west
digitalWrite(LED_WY, HIGH); 
delay(2000);
digitalWrite(LED_WR, LOW); 
digitalWrite(LED_WY, LOW); 
digitalWrite(LED_WG, HIGH);
}
if ( buttonState_E == HIGH && digitalRead(LED_WG) == HIGH )
{
// zamykamy ruch dla west
digitalWrite(LED_WG, LOW);
digitalWrite(LED_WY, HIGH);
delay(2000);
digitalWrite(LED_WY, LOW);
digitalWrite(LED_WR, HIGH);
delay(3000); // czekamy, az pojazdy zdaza przejechac most
// otwieramy ruch dla east
digitalWrite(LED_EY, HIGH); 
delay(2000);
digitalWrite(LED_EY, LOW); 
digitalWrite(LED_ER, LOW); 
digitalWrite(LED_EG, HIGH);
}
}
