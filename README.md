# B4M38KRP-semproj

The goal of the semestral project is to implement some kind of USB device that will natively communicate with any USB-enabled computer.  
The hardware used in this project will be STM3240G-EVAL (https://www.st.com/en/evaluation-tools/stm3240g-eval.html). And maybe Raspberry pico W (https://www.raspberrypi.com/products/raspberry-pi-pico/), depending on the project's implementation.

## Topic 1. multimedia controller using STM3240G-EVAL

This project aims to use pins on the development board and connect one or more rotary encoders. The encoders will be used for various uses. However, the main one is to implement a multimedia controller, which will be able to increase or decrease the sound volume of the host device based on the movement of the rotary encoder.  
The current volume level can be displayed on the built-in LCD, and buttons can be used as other multimedia buttons, such as pause, play, next or previous track.

### Development stages:
- [ ] LED blinking, really basic functions.
- [ ] Basic communication working, exchange basic data with computer via USB.
- [ ] Implement basic peripheral function using rotary encoder e.g. scrolling.
- [ ] Implement more advanced functions for the rotary encoder, like multimedia control.
- [ ] Add the multimedia statistics, like volume level, to LCD.
- [ ] Implement more functions for rotary encoder. Switch between those functions via button, and display the currently active function on LCD.
- [ ] Add mode advanced multimedia statistics, like if the song is playing or stopped or the name of the song.
- [ ] Implement other multimedia controls for buttons.

## Side-Topic 2. wireless adapter using Raspberry Pi Pico W

I originally wanted to use ESP32 as the base for the wireless adapter for the PC. However, based on what I found online - the serial port on ESP32 isn't fast enough and doesn't support USB speeds. Other hardware, such as newer ESP32-S2 or Raspberry Pi Pico W, can communicate via USB without a problem. I currently don't own ESP32-S2, but I have ordered mentioned Raspberry Pi board. The only problem is - I only ordered it, and it is still on its way, and I can't tell for sure when it will be delivered.  
For that reason, I am making this a Side-Topic. If it arrives and I have some spare time, I will gladly try to implement this instead of the first one, but I am not betting my money on it:).

### Development stages:
- [ ] Wait for Raspberry Pi Pico W to arrive
- [ ] Very basic functionality working. LED blinking.
- [ ] Basic communication working, exchanging basic data with computer via USB.
- [ ] Connect to any wireless network using data provided by the host computer.
- [ ] Create a host driver, if needed, to exchange data with raspberry pi, and accept network data.

The development for this is much less straightforward, and I would certainly need to study this subject in greater detail to implement this correctly. I am unsure if this side topic will ever see the light of day, but I like the idea and wanted to share it, just in case.
