#include <Arduino.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>
#include <printf.h>


RF24 radio(2, 15); //(CE, CSN)
// RF24 radio(7, 8); //(CE, CSN)
String data;
void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.setChannel(5);                   // Channel(0 ... 127)
  radio.setDataRate(RF24_1MBPS);         // RF24_250KBPS, RF24_1MBPS, RF24_2MBPS)
  radio.setPALevel(RF24_PA_HIGH);        // RF24_PA_MIN=-18dBm, RF24_PA_LOW=-12dBm, RF24_PA_HIGH=-6dBm, RF24_PA_MAX=0dBm
  radio.openWritingPipe(0x1234567890LL); // 0x1234567890


}
void loop()
{
  if (Serial.available() > 0)
  {
    char receivedData[64];                                            // buffer to hold the received data
    int numBytesRead = Serial.readBytesUntil('\n', receivedData, 64); // read the data until a newline character is received or buffer is full
    receivedData[numBytesRead] = '\0';
    Serial.println(receivedData);
    radio.write(&receivedData, 6);
    // if (receivedData == "start")
    // {
    //   data = "start";
    //   radio.write(&data, 6);
    // }
    // else if (receivedData == "stop")
    // {
    //   data = "stops";
    //   radio.write(&data, 6);
    // }
  }
  
}
