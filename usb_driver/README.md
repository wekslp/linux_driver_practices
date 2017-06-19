# USB driver practice 
Implement a CP210x usb serial device driver 

CP210x serial device
idVendor=10c4
idProduct=ea60

2017-06-19: Understand how to register a usb driver with vendor id and device id.

## Getting Started
Step1: remove original cp210x.ko module and insert our new cp210x.ko
Step2: Register usb driver with Device ID/Vendor ID
Step3: Implement probe function.


