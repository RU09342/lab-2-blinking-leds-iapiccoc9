# Functionality
This project allowed a button on the launchpad to control an LED that existed in a curcuit on a breadboard. Pressing the button toggled the LED. On the breadboard, power and ground were taken from the pins of the launchpad, and the LED control was booked up to P1.5 on the chip. P1.5 was hooked up to a MOSFET which turned on and off the power being supplied to the LED in series with a current-limiting resistor. The detection of the button being pressed was implemented with polling originally, but was replaced with interrupts later on.

# Resources used
When this part of the lab was tackled, no resources were required, and the knowledge to do it was taken directly from the previous projects completed.

# Difficulties
There was some difficulty in getting this code to work with polling. For that reason, the code was redone using interrupts.

# Known errors
There was some debouncing done using a for loop. This didn't completely solve the problem of the bouncing of the button and sometimes the button will become triggered multiple times on a single press.