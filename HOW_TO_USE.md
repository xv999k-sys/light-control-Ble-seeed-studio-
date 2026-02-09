How To Use:

Overview
This document explains how to set up and run the BLE LED control project using the Seeed Studio nRF52840 board. It also lists the required tools and shows how to properly connect the components.
______________________________________________________________________________________________

Required Tools 🛠

To run this project, you will need:

Seeed Studio nRF52840 development board

2 × LEDs (one red and one green The best ),Or the color you want

Current-limiting resistors for each LED

Jumper wires

Breadboard (optional)

A compatible battery to power the Seeed Studio board

A device (personal computer) equipped with Bluetooth BLE technology; most devices support this technology.

A modern web browser for the control interface (Chrome or FireFox)
_________________________________________________________________________________________________________________

Connection Instructions (assuming red and green LEDs):

Connect the red LED to pin 5 on the Seeed Studio board (using a resistor).

Connect the green LED to pin 6 on the Seeed Studio board (using a resistor).

Connect the other end of each LED to ground (GND).

Connect the battery to the power input on the Seeed Studio board.

Note: Ensure all connections are secure, and use resistors to protect the LEDs from damage. 

🔗 Seeed Studio nRF52840:  
[The official product page for purchasing the product and learning about the pin identification number (PIN), battery ports, and board connection methods.]
(https://www.seeedstudio.com/Seeed-XIAO-BLE-nRF52840-p-5201.html)

_____________________________________________________________________________________________________________________

Programming Part

After downloading the code package to your device, extract the folder to prepare for the next step.

First, connect the Seeed Studio software to your computer via USB. Then, download and install the Arduino application on your computer.

Second, open the application and download the necessary libraries for Seeed Studio.

Next, copy the code from the (code-seeed.cpp) file into the Arduino code editor, and then upload it to the Seeed Studio board.

Third, open the (index.html) file. You will see the complete interface: the Bluetooth button, power buttons, and intensity control buttons. Connect via Bluetooth and enjoy! 😉

____________________________________________________________________________________________________________________________

Important Tips

Ensure the battery is charged before use to avoid disconnections.

It is recommended to test the project using USB power first before switching to battery power.

If the device does not appear in the BLE scan, make sure:

The board is powered on

You are within BLE range

Bluetooth is enabled on your device
