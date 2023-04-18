#include <Arduino.h>
#include <nRF24L01.h>                                    
#include <RF24.h>    
#include <SPI.h>
#include <printf.h>
                                 
RF24 radio(2, 15); //(CE, CSN)
//RF24 radio(7, 8); //(CE, CSN)
byte data[2];                                   
void setup(){
  Serial.begin(9600);
  radio.begin();        
  printf_begin();                                
  radio.setChannel(5);  // Channel(0 ... 127)
  radio.setDataRate(RF24_1MBPS);  // RF24_250KBPS, RF24_1MBPS, RF24_2MBPS)
  radio.setPALevel(RF24_PA_HIGH); //RF24_PA_MIN=-18dBm, RF24_PA_LOW=-12dBm, RF24_PA_HIGH=-6dBm, RF24_PA_MAX=0dBm
  radio.openWritingPipe(0x1234567890LL);  // 0x1234567890
  radio.printDetails();

}
void loop(){
  data[0] = 5;                             
  data[1] = 4;                             
  radio.write(&data, 2);
  delay(1000);
  Serial.println("sent");
}

