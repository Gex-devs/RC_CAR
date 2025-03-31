#include <Arduino.h>
#include <SPI.h>
// #include <nRF24L01.h>
#include <RF24.h>

int motor_A_1 = A0;
int motor_A_2 = A1;


RF24 radio(10, 9);
const byte addresses[][6] = {"00001", "00002"};

void setup()
{
  pinMode(motor_A_1, OUTPUT);
  pinMode(motor_A_2, OUTPUT);
  radio.begin();
  radio.openWritingPipe(addresses[0]);    // 00001
  radio.openReadingPipe(1, addresses[1]); // 00002
  radio.setPALevel(RF24_PA_MIN);
}

void loop()
{
  delay(5);
  radio.startListening();
  if (radio.available())
  {
    while (radio.available())
    {
      int angleV = 0;
      radio.read(&angleV, sizeof(angleV));
      if (angleV > 0)
      {
        digitalWrite(motor_A_1, HIGH);
      }else{
        digitalWrite(motor_A_1, LOW);
      }
    }
    delay(5);
    radio.stopListening();
  }
}