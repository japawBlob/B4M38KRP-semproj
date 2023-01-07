https://www.instructables.com/STM32-As-HID-USB-Keyboard-STM32-Tutorials/

https://eleccelerator.com/tutorial-about-usb-hid-report-descriptors/

https://www.usb.org/hid

https://notes.iopush.net/blog/2016/custom-usb-hid-device-descriptor-media-keyboard/

https://stackoverflow.com/questions/72581980/is-there-a-way-to-use-the-usb-hid-to-control-the-specific-gui-volume-on-windows

https://www.microchip.com/forums/m618147.aspx

https://www.ccsinfo.com/forum/viewtopic.php?t=59253

UBS HID 1.11 28.

Pins used for rotary encoder:
B5 - CLK
B4 - DATA
B6 - CLOCK

GND - GND
APP_V - +

HUD - 96 - mute

Descriptors location:
USBD_FS_DeviceDesc : USB_DEVICE/App/usbd_desc.c

report descriptor : Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.c
