# B4M38KRP-semproj

The goal of the semestral project is to implement some kind of USB device that will natively communicate with any USB-enabled computer.  
The hardware used in this project will be STM3240G-EVAL (https://www.st.com/en/evaluation-tools/stm3240g-eval.html). And maybe Raspberry pico W (https://www.raspberrypi.com/products/raspberry-pi-pico/), depending on the project's implementation.

## Topic 1. multimedia controller using STM3240G-EVAL

This project aims to use pins on the development board and connect one or more rotary encoders. The encoders will be used for various uses. However, the main one is to implement a multimedia controller, which will be able to increase or decrease the sound volume of the host device based on the movement of the rotary encoder.  
The current volume level can be displayed on the built-in LCD, and buttons can be used as other multimedia buttons, such as pause, play, next or previous track.

### Development stages:
- [x] LED blinking, really basic functions.
- [x] Basic communication working, exchange basic data with computer via USB.
- [x] Implement basic peripheral function using rotary encoder e.g. scrolling.
- [x] Implement more advanced functions for the rotary encoder, like multimedia control.
- [ ] Add the multimedia statistics, like volume level, to LCD. (Not possible with basic driver)
- [x] Implement more functions for rotary encoder. Switch between those functions via button, and display the currently active function on LCD.
- [ ] Add mode advanced multimedia statistics, like if the song is playing or stopped or the name of the song. (Not possible with basic driver)
- [x] Implement other multimedia controls for buttons.

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


# Final report

The implemented device is a multimedia controller. As of today, my Raspberry Pi Pico W still hasn't arrived, so that idea was not further developed. 

Implemented device consists of board STM3240G-EVAL and connected rotary encoder.

My implementation of multimedia controller is able to do the following actions via USB. 
- modify volume
- mute sound
- scroll (like with mouse scroll wheel)
- turn on and off caps lock
- display caps lock state on display

The device has two main operating modes. Named **Volume control** and **Scroll control**. We can switch between these modes by pressing built-in user button.

In **Volume control**:
- rotary encoder is used for increasing and decreasing the volume of the connected device
- pressing the rotary encoder button mutes the sound

In **Scroll control**:
- rotary encoder is used for scrolling
- pressing the rotary encoder button toggles the caps lock

The LCD is active during both modes. Displaying which mode is currently active and the state of caps lock.

## Implementation 

The final implementation of the defined behaviour was the easiest part. The most difficult one was to satisfy Windows device recognition and getting the BSP driver to work. 

I started by creating a project via the provided instructions and was able to send basic mouse commands. In this project, I was able to transform into keyboard, attach rotary encoder and send volume up and volume down commands to the PC. Unfortunately, these volume controls defined in Keyboard page are Unix only. For Windows, I would need to implement volume control functionality from Consumer device page.

But first, I decided to implement LCD functionality, which I thought would be work for a few hours at most. After one man-day, I was able to make the LCD work properly. I made the BSD library work by initialising the board I/O to default, which generated needed HAL drivers, then inserted the BSD driver and removed redundant files like audio. 

This was followed by implementing increasing and decreasing volume. I managed to get volume controls using Consumer device page working on Linux, but Windows had problems again. After a few hours of desperate searching, I stripped Report descriptor from the multimedia keyboard using [hidrd](https://github.com/DIGImend/hidrd) and [usbhid-dump](https://github.com/DIGImend/usbhid-dump) utils. Found out that their implementation is almost identical, with the difference that I used volume up and volume down for multiple data values. This report descriptor worked with Windows without a problem. 

This was followed by implementing scrolling, with similar progress as previous USB devices. Linux worked fine just with the implementation of a mouse wheel, but I needed to add mouse buttons and mouse movement to the report descriptor in order to convince Windows to accept the scroll messages. 

Since I also wanted the CAPS LOCK functionality and to show the state on LCD, I also added keyboard, which I had implemented earlier to the Report descriptor. For reading out the state of CAPS LOCK, I read out LED from keyboard. In order to have a proper output handler (output from PC perspective, input from USB device perspective), I regenerated the project with Custom HID Device instead of HID Device option since Custom HID Device also generates the interrupt handler for incoming messages. 

In conclusion - adding BSD drivers for older boards is a pain. Luckily for newer boards, it can be generated by CUBE. Linux will interpret anything from the Report descriptor as long as it makes sense, at least a little bit. Windows is REALLY strict about what it will accept. 