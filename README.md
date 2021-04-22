# LaskaKit Simple Joystick
Are you looking for a finished trasnmitter and receiver, which you can easily program? Let's check our set of wireless transmitter and receiver which are based on Arduino evaluation boards and used wireless modules are nRF24L01 which are working on 2.4 GHz.

### Transmitter
The transmitter is based on the popular Arduino Nano. The transmitter may be powered from miniUSB which is on the board or from 4 AAA batteries which are on the bottom side of transmitter. 

The wireless module is used nRF24L01 with external antenna.

The control parts are joystick with the button in the center and external switch on the right side.

![Transmitter](https://github.com/LaskaKit/Simple_2.4G_Joystick_Transmitter/blob/main/img/joystickTX_top.jpg)

The movement in X and Y axis is measured by trimmer resistor. The outputs of trimmers are connected to A0 and A1. The middle button is connected to A2.
The switch is connected to D7.
The transmitter may be turned off thanks to the switch between batteries and Arduino Nano.

#### Uploading of code
For uploading of code, choose Arduino Nano in Board Manager. If you see some error message, choose the type of microcontroller ATmega328P (old bootloader).

### Receiver
The receiver is based on Arduino Pro Micro with ATmega32u4 microcontroller. The wireless module is the same like in the transmitter - nRF24L01 but in SMD or THT version. The receiver is designed for both types of nRF24L01 modules. 
The output pins are D9, D6, D5 and D3. The digital outputs may be used also as PWM outputs - for example for servos.
The output may be USB what you can see in example code.

![Receiver TOP](https://github.com/LaskaKit/Simple_2.4G_Joystick_Transmitter/blob/main/img/joystickRX_top.jpg)

![Receiver BOT](https://github.com/LaskaKit/Simple_2.4G_Joystick_Transmitter/blob/main/img/joystickRX_bot.jpg)

Thanks to used microcontroller - ATmega32u4, which includes USB connectivity as USB-CDC (com port) and also USB-HID - the same like keyboard and mouse.
The using of USB-HID - keyboard emulation, you may see in the video below.

### Uploading of code
Choose the Arduino Pro Micro

## Example code
The data from transmitter is sent to receiver where the values from joystick and switch are interpreted as buttons in keyboard.
The external switch is used as the launcher of rocket in the game.

![LaskaKit Simple Joystick demo](https://github.com/LaskaKit/Simple_2.4G_Joystick_Transmitter/blob/main/img/LaskaKit_Simple_joystick_demor.gif)

https://github.com/LaskaKit/Simple_2.4G_Joystick_Transmitter/tree/main/SW/Joystick%20and%20VirtualKeyboard
