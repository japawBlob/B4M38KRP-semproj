# B4M38KRP-semproj

Goal of semestral project is to implement some kind of USB device, that will natively communicate with any USB enabled computer.  
Hardware used in this project will be STM3240G-EVAL (https://www.st.com/en/evaluation-tools/stm3240g-eval.html). And maybe Raspberry pico W (https://www.raspberrypi.com/products/raspberry-pi-pico/), depending on which project will be the one that will be implemented.

## Topic 1. multimedia controller using STM3240G-EVAL

Aim of this project is to use pins on the development board and connect one or more rotary encoders to it. The encoders will be used for various uses, but main one is to implement multimedia controller, which will be able to increase or decrease sound volume of host device based on the movement of rotary encoder.  
The current level of volume can be displayed on build in LCD display and buttons can be used as other multimedia buttons, such as pause, play, next or previous track.

### Developement stages:
- [ ] LED blinking, really basic functions.
- [ ] Basic communication working, being able to exchange basic data with computer via USB.
- [ ] Implement basic peripheral function using rotary encoder e.g. scrolling.
- [ ] Implement more advanced function for rotary encoder, like multimedia controll.
- [ ] Add the multimedia statistics, like volume level to LCD.
- [ ] Implement more functions for rotary encoder. Switch between those functions via button, and display currently active function on LCD.
- [ ] Add mode advanced multimedia statistics, like if the song is playing or stopped, or name of the song.
- [ ] Implement other multimedia controlls for buttons.

## Side-Topic 2. wireless adapter using Raspberry Pi Pico W

I originally wanted to use ESP32 as base for wireless adapter for PC. But based on what i found online serial port on ESP32 isn't fast enough, and doesn't support USB speeds. However other hardware as newer ESP32-S2 or Raspberry Pi Pico W are able to communicate via USB without problem. I currently don't own ESP32-S2, but I have ordered mentioned Raspberry pi board. The only problem is - I only ordered it, and it is still on it's way and I canno't tell for sure, when it will be delivered.  
For that reason I am making this a Side-Topic. If it will arrive and I will have some spare time I will gladly try to implement this instead of the first one, but I am not betting my money on it:).

### Developement stages:
- [ ] Wait for Raspberry Pi Pico W to arrive
- [ ] Very basic functionality working. LED blinking.
- [ ] Basic comunication working, being able to exchange basic data with computer via USB.
- [ ] Connect to any wireless network using data provided by host computer.
- [ ] Create host driver, if needed, to exchange data with raspberry pi, and accept network data.

The development for this is much less straightforward and I would for sure need to study this subject to greater detail in order to implement this correctly. I am not sure if this side topic will ever see the light of day, but I like the idea and wanted to share it, just in case.
