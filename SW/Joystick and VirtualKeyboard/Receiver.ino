/* Kod prijimace pro LaskaKit Simple Joystick - Arduino Micro
 * Vystup jako USB-HID (klavesnice)
 * 
 * Pouzita knihovna: https://github.com/nRF24/RF24
 * O klavesnici: https://www.arduino.cc/en/Reference/KeyboardModifiers
 * Vyuzite pro hru: https://www.topspeed.com/aviation/aviation-games/fractal-combat-x-ar191216.html
 * 
 * 
 * (c) 2021 laskarduino.cz
 */
 
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "Keyboard.h"

//Muzeme mit az 32 kanalu
struct MyData {
  byte ch1;      //V tomto pripade mame 4 kanaly
  byte ch2;
  byte ch3;
  byte ch4;
};
MyData data;

int prevVal = 0;

const uint64_t pipeIn = 0x0022;   //Identifikator zarizeni - stejny kod musi byt nastaven na vysilaci
RF24 radio(8,10);  //zapojeni CE a CSN pinu

void setup()
{
  Serial.begin(115200);
  
  //Nastaveni NRF24
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);  
  radio.openReadingPipe(1,pipeIn);
  radio.startListening();

  //Nastaveni klavesnice
  Keyboard.begin();
}

//Zde budeme cist prijata data
unsigned long lastRecvTime = 0;
void recvData()
{
  while ( radio.available() ) {
  radio.read(&data, sizeof(MyData));
  lastRecvTime = millis();
  }
}

void loop()
{
  recvData();

  // pokud data z ch1 jsou mensi nez hodnota 140 nebo vetsi nez 180
  if(data.ch1 < 140 || data.ch1 > 180)
  {
    // pokud data z ch1 je vetsi nez hodnota 180
    if(data.ch1 > 180)
    {
      /*Serial.println("Letim doprava");
      Serial.println(data.ch1);*/
      Keyboard.write(0xD7); // sipka doprava
    }
      
    // pokud data z ch1 je mensi nez hodnota 140
    if(data.ch1 < 140)
    {
      /*Serial.println("Letim doleva");
      Serial.println(data.ch1);*/
      Keyboard.write(0xD8); // sipka doleva
    }
  }

  // pokud data z ch2 jsou mensi nez hodnota 150 nebo vetsi nez 190
  if(data.ch2 < 150 || data.ch2 > 190)
  {
    // pokud data z ch1 je vetsi nez hodnota 190
    if(data.ch2 < 150)
    {
      /*Serial.println("Letim nahoru");  
      Serial.println(data.ch2);*/
      Keyboard.write(0xD9); // sipka dolu
    }

    // pokud data z ch2 je mensi nez hodnota 150
    if(data.ch2 > 190)
    {
        /*Serial.println("Letim dolu");
        Serial.println(data.ch2);*/
        Keyboard.write(0xDA); // sipka nahoru
    } 
  }

  // data z ch3 - nepouzito
  if(data.ch3 == 1)
  {
    /*Serial.println("Strelba kulometem");*/   
  }

  // data z ch4 - mezernik
  if(data.ch4 == 1)
  {
    /*Serial.println("Strelba raketou");*/
    Keyboard.write(0x20); // mezernik
  }

}
