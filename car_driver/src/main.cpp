#include <Arduino.h>
#include <driver.h>
#include <SPI.h>
#include "RF24.h"

// Setup the NRF24L01+ radio module
RF24 radio(22, 0); // CE, CSN pins
const uint64_t pipes[2] = {0xE7E7E7E7E7, 0xC2C2C2C2C2};

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setRetries(15,15);
  radio.setPayloadSize(32);
  radio.setChannel(5);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MIN);
  radio.setAutoAck(true);
  radio.enableDynamicPayloads();
  radio.openReadingPipe(1, pipes[1]);
  radio.startListening();
}

void loop() {
  // Check if there is data available to read
  if (radio.available()) {
    uint8_t received_data[32];
    radio.read(&received_data, sizeof(received_data));

    // Print the received data
    Serial.print("Received: ");
    for (int i = 0; i < sizeof(received_data); i++) {
      Serial.print((char)received_data[i]);
    }
    Serial.println();

    // Reset the radio module to prepare for the next transmission
    radio.stopListening();
    radio.startListening();
  }
}
