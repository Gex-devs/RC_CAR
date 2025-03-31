#include <Arduino.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>
#include <printf.h>

RF24 radio(7, 8); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};
void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(addresses[1]);    // 00002
  radio.openReadingPipe(1, addresses[0]); // 00001
  radio.setPALevel(RF24_PA_MIN);
}
void loop()
{
  delay(5);

  radio.stopListening();
  int potValue = analogRead(A0); // Read button instead
  int angleValue = map(potValue, 0, 1023, 0, 180);
  radio.write(&angleValue, sizeof(angleValue));
  delay(5);
  radio.startListening();
  while (!radio.available())
    ;
}
