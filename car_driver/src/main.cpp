#include <Arduino.h>
#include <driver.h>
#include <SPI.h>      
#include <nRF24L01.h> 
#include <RF24.h>     

RF24 radio(9, 10);                       
byte data[2];
void setup(){
  delay(1000);
  Serial.begin(9600);
  Serial.println("Setup");
  radio.begin();                                        
  radio.setChannel(5);                                  // Channel  0 ... 127
  radio.setDataRate     (RF24_1MBPS);                   // RF24_250KBPS, RF24_1MBPS, RF24_2MBPS
  radio.setPALevel      (RF24_PA_HIGH);                 // RF24_PA_MIN=-18dBm, RF24_PA_LOW=-12dBm, RF24_PA_HIGH=-6dBm, RF24_PA_MAX=0dBm
  radio.openReadingPipe (1, 0x1234567890LL);            // 0x1234567890
  radio.startListening  ();    
  Serial.println(radio.available());                         
//radio.stopListening   ();                             
}
void loop(){
  if(radio.available()){                           
    radio.read(&data, 2);                  
    Serial.print(data[0]);
    Serial.println(data[1]);
  }
}