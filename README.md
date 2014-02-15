knitting-counter
================

A basic counter-decounter useful for knitting addicts :)


## License
This project and all the associated files are placed under the Simplified BSD license, even if the license not explicitely written in each file.

For more details about the license, see the LICENSE.txt.



## Why "knitting counter"?
I live with a knitting addict and there is one important when knitting: counting rows. As I was looking for a project to design and realize my first printed circuit board (PSB), I seemed like a good idea to me to create a counter to count rows.



## Hardware
The circuit is based on a PIC18F25K22 micro-controller. Here are the main reasons why I choosed this chip:
- PIC are easy to program
- PIC are available in DIP package
- I had a Pickit3 programmer
- I had 2 PIC18F25K22 (I don't really know how they got home...)

Hence, the board have an ISP connector for the Pickit3. Some other programmers from Microchip may be compatible.

Three buttons allow to increase, decrease and reset the counter. There are connected to the three pins that can generate external interrupts. Unfortunately, I was not smart enough when I prototyped the circuit to include a filter for bounces.

Three seven-segment displays composed the "screen" (wooh!). There are not all on at the same time. Instead, there are turned on one by one, each with the appropriate digit. Persistence of vision comes into play when this "mutliplexing" is fast enough, giving the impression that the three displays are on at the same time. Each seven-segment display is driven through a transitor used in commutation mode.

Three LEDs are available in the design. I massively used one LED for debugging purpose. There is no real reason for a counter to have LEDs but there were available pins and enough room on the PCB. If one day the board is used for another purpose, these LEDs might be interesting.

Power supply is done with a LM7805. Power voltage is 5V.



## Kicad
The PCB has been designed with Kicad. I choosed Kicad because it is a free cross-platform software.

The repository includes the Kicad project (schematic, custom footprint library, component/footprint association, PCB layout).



## PIC software
The software is made with the Mplab 8 IDE and the C18 compiler.

It basically realizes the functions described in the *Hardware* section:
* Timer 1 manages the display multiplexing.
* Timer 2 mangages software debouncing and inactivity. After an inactivity period, display and Timer 1 are stopped to save power.
* External interrupts manages the counter. Pressing a button restart the inactivy counter. When the display is off, pressing a button will have no other effect than to restart Timer 1 and turn on the display.
