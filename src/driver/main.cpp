#include <Arduino.h>
#include <driver.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int motor2_A = PC3;
int motor2_B = PC2;

int motor4_A = PD3;
int motor4_B = PD7;

int motor3_A = PD4;
int motor3_B = PD2;

RF24 radio(10, 9);
char data[6];
Vroom yo = Vroom();

void setup()
{
  pinMode(PD0, OUTPUT);
  delay(1000);
  Serial.begin(9600);
  Serial.println("Setup");
  radio.begin();
  radio.setChannel(5);                      // Channel  0 ... 127
  radio.setDataRate(RF24_1MBPS);            // RF24_250KBPS, RF24_1MBPS, RF24_2MBPS
  radio.setPALevel(RF24_PA_HIGH);           // RF24_PA_MIN=-18dBm, RF24_PA_LOW=-12dBm, RF24_PA_HIGH=-6dBm, RF24_PA_MAX=0dBm
  radio.openReadingPipe(1, 0x1234567890LL); // 0x1234567890
  radio.startListening();
  Serial.println(radio.available());
  // radio.stopListening   ();
}
void loop()
{
  if (radio.available())
  {
    radio.read(&data, 6);
    String dataStr(data); // convert the char array to a String object
    Serial.println(dataStr);
    if (dataStr == "start")
    {
      yo.Forward();
      Serial.println("Moving Forward");
    }
    else if (dataStr == "stops")
    {
      yo.Stop();
      Serial.println("Stopping");
    }
  }
}

