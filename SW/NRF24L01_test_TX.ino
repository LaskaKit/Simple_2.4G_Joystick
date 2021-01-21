/* Kod vysilace pro LasKKit Simple Joystick - Arduino NANO
 * 4kanaly ,datove piny A0, A1, A2, A3
 *
 * Pouzita knihovna https://github.com/nRF24/RF24
 * 
 */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CH3_Pin A2
#define CH4_Pin 7

const uint64_t my_radio_pipe = 0x0022; //Identifikator zarizeni - stejny kod musi byt nastaven na prijimaci

RF24 radio(4, 10);  //zapojeni CE a CSN pinu
//maximalne 32 kanalu

struct Data_to_be_sent {
  byte ch1;
  byte ch2;
  byte ch3;
  byte ch4;
 };
Data_to_be_sent sent_data;

void setup()
{
  //Nastaveni vstupnich pinu
  pinMode(CH3_Pin, INPUT_PULLUP);
  pinMode(CH4_Pin, INPUT);
  
  //Nastaveni NRF24
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(my_radio_pipe);
  
  //Reset hodnot kanalu
  sent_data.ch1 = 127;
  sent_data.ch2 = 127;
  sent_data.ch3 = 0;
  sent_data.ch4 = 0;
}

void loop()
{
/*Nastaveni kanalu /velkost vychilek a reverz serv/
  Normal:    data.ch1 = map( analogRead(A0), 0, 1024, 0, 255);
  Reverz:  data.ch1 = map( analogRead(A0), 0, 1024, 255, 0);  */
  
  sent_data.ch1 = map( analogRead(A0), 0, 1000, 110, 220); // CH1 - potenciometr joysticku
  sent_data.ch2 = map( analogRead(A1), 0, 1124, 255, 60);  // CH2 - potenciometr joysticku
  sent_data.ch3 = digitalRead(CH3_Pin);
  sent_data.ch4 = digitalRead(CH4_Pin);
  
  radio.write(&sent_data, sizeof(Data_to_be_sent));
}
