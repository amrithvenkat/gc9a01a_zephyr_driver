# Waveshare GC9A01A display driver.
This driver borrows the code and template of drivers/display/display_ili9xxx.c and .h

This driver uses RP2040 (RaspberryPi Pico) as the controller of choice.

Note: All the development in this driver has been to mimic the "out of tree driver" development where minor changes will be implemented to make it work as a part of the main zephyr repository.

Out of tree driver development follow the pattern of https://github.com/teslabs/zds-2022-drivers-app and https://github.com/zephyrproject-rtos/example-application.


## Usage
1. Set the west workspace using virtual environments of choice and set the zephyr sources.


```shell
workon zephyr-env-name
source path/to/zephyr-env.sh
```

2. In the current directory, use west command as follows to compile for rpi pico.

```shell
west build -b rpi_pico -p -s app
```
Change ```-b rpi_pico``` to your custom board. 
For other boards/custom boards, use custom overlays or even board configurations as seen fit.


## Folder - app
1. the app/boards folder contains the overlay for the rpi_pico overlay. Change it to the required board of your choice. This file contains the device tree definition for the display under spi0 section.

2. app/src contains the main.c where the core program resides.


## Folder - drivers
1. drivers/display contains the core driver code for the GC9A01A display.

## Folder - dts
1. dts/bindings/display contains the device tree stuff for the GC9A01A display.
2. It is important for the intitialization sequence of the display and also configuring it as an SPI device.

## Folder - include
1. include/zephyr/dt-bindings folder contains include file that is used in the overlay to select the pixel format. This can be omitted but keeping it for further development.


Finally any support to make the driver work better or optimize it would be apppreciated. 
