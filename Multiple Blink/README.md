# Functionality
The function of the code is to blink two LEDs on the launchpad simultaneously. This is performed by creating an infinite loop an timing each of the LED's using a count register with a modulus divison to set how long it should be in between each LED's toggle.

# Resources used
For this code, the resource center was not used. The basic MSP430 principles were applied directly from the "Simple Blink" project, with a little bit more logic used.

# Differences between boards
As before, the default high impedance mode for the MSP430FRxxx boards needed to be shut off. Furthermore, the pin that is mapped to the second LED on each launchpad differed from board to board and needed to be accounted for.

# Difficulties
The only difficulty ran into this lab was the timing. Originally, timing was done sequentially, meaning one button woud blink, then the other. When it was discovered that each LED should have independent timing, this idea was refined. Ideas were taken from the class lab session to implement modulus timing instead.

  