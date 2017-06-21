# USB driver practice 
Implement a CP210x usb serial device driver

CP210x serial device
idVendor=10c4
idProduct=ea60

2017-06-19: Understand how to register a usb driver with vendor id and device id.
2017-06-21: usb_register by usb_serial_driver wrapper. Note: .num_ports need to set a value.

## Getting Started
Step1: remove original cp210x.ko module and insert our new cp210x.ko

Step2: Register usb driver with Device ID/Vendor ID

Step3: Implement usb_serial_driver wrapper

## Test result

### Insert module
Insert cp210x module and register usb_serial_driver 
```
[ 5097.392802] usbcore: registered new interface driver cp210x
[ 5097.392818] usbserial: USB Serial support registered for cp210x driver practice
[ 5101.861981] usb 1-4: new full-speed USB device number 12 using xhci_hcd
[ 5102.077089] usb 1-4: New USB device found, idVendor=10c4, idProduct=ea60
[ 5102.077093] usb 1-4: New USB device strings: Mfr=1, Product=2, SerialNumber=3
[ 5102.077095] usb 1-4: Product: CP2102 USB to UART Bridge Controller
[ 5102.077096] usb 1-4: Manufacturer: Silicon Labs
[ 5102.077098] usb 1-4: SerialNumber: 0001
```
### Plug-in cp210x device
Callback functions of usb_serial_driver 
.probe
.attach
.port_probe
```
[ 5102.085893] cp210x_probe
[ 5102.085897] cp210x 1-4:1.0: cp210x driver practice converter detected
[ 5102.085899] cp210x_startup
[ 5102.085920] cp210x_port_probe
[ 5102.085974] usb 1-4: cp210x driver practice converter now attached to ttyUSB0
```
### echo /dev/ttyUSBx
```
[ 5109.992103] cp210x_open
[ 5113.650594] cp210x_close
```
### Remove cp210x device
Callback functions of usb_serial_driver
.port_remove
.disconnect
.release
```
[ 5455.281565] usb 1-4: USB disconnect, device number 12
[ 5455.282029] cp210x_port_remove
[ 5455.282044] cp210x driver practice ttyUSB0: cp210x driver practice converter now disconnected from ttyUSB0
[ 5455.282096] cp210x_disconnect
[ 5455.282104] cp210x_release
[ 5455.282125] cp210x 1-4:1.0: device disconnected
```

