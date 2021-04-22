## LaskaKit Simple Joystick
Hledáte hotový vysílač a přijímač, který jednoduše naprogramujete? Pak by se vám mohl líbit náš set vysílače a přijímače, které jsou založeny na vývojových deskách Arduino a jako přijímač a vysílač jsou použity nRF24L01, který pracuje na frekvenci 2.4 GHz.

### Vysílač
Vysílač je založen na vývojové desce Arduino Nano. Vysílač může být napájen z miniUSB přitomného na Arduino Nano nebo ze sady baterií na zadní straně vysílače. 

Jako komunikační modul je využit nRF24L01 s vysílačem a externí anténou. 

Mezi ovládací prvky patří joystick s tlačítkem uprostřed a spínačem na pravé straně. 

![Transmitter](https://github.com/LaskaKit/Simple_2.4G_Joystick_Transmitter/blob/main/img/joystickTX_top.jpg)

Pohyb v osách X a Y obsahují odporové trimry a výstup je namapován na vstupy A0 a A1. Středové tlačítko je připojeno na vstup A2. 
Přepínač je pak připojen na vstup D7.
Celý vysílač můžete vypnout posuvným vypínačem.

#### Nahrávání kódu do vysílače:
Při nahrávání zvolte desku Arduino Nano. Pokud uvidíte chybovou hlášku o nemožnosti nahrávání, ve volbě procesoru zvolte možnost ATmega328P (old bootloader).

### Přijímač
Přijímač je založen na Arduino Pro Micro s mikrokontrolérem ATmega32U4. Bezdrátový modul je opět použitý nRF24L01 v SMD nebo THT verzi - vývojový kit je připraven na osazení jedním z nich.
Výstupem jsou piny D9, D6, D5 a D3, které mohou sloužit jako digitální výstupy, tak i PWM výstupy. 
Jako výstup může sloužit i USB.

![Receiver TOP](https://github.com/LaskaKit/Simple_2.4G_Joystick_Transmitter/blob/main/img/joystickRX_top.jpg)

![Receiver BOT](https://github.com/LaskaKit/Simple_2.4G_Joystick_Transmitter/blob/main/img/joystickRX_bot.jpg)

Díky použitému mikrokontroléru ATmega32U4, který má v sobě integrované USB rozhraní můžete využít jak klasický USB-CDC (COM port), tak i USB-HID (stejně jako klávesnice nebo myš).
Použití USB-HID z ATmega32U4 jako klávesnice pak můžete vidět na videu níže

### Nahrávání kódu do přijímače:
Při nahrávání zvolte desku Arduino Pro Micro.

## Vzorový kód
Data z vysílače jsou odeslána na přijímač, kde data z joysticku a přepínače jsou intepretovány jako tlačítka klávesnice - šipka nahoru, dolů, doprava, doleva a mezerník (ve hře použitý pro rakety).

![LaskaKit Simple Joystick demo](https://github.com/LaskaKit/Simple_2.4G_Joystick_Transmitter/blob/main/img/LaskaKit_Simple_joystick_demor.gif)

https://github.com/LaskaKit/Simple_2.4G_Joystick_Transmitter/tree/main/SW/Joystick%20and%20VirtualKeyboard
