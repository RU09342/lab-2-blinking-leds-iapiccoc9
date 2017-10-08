# Functionality

The program written blinks an LED at a given rate. The code works by configuring a port to output, and toggling the output to this pin high and low continuously using an infinite while loop.

# Resources used
The first program that was written, for the MSP430F5529, the resource explorer was used to find example code that demonstrated how to write this code. From there, creating the code for  the other boards was simple.

# Differences between boards
The differences between boards were very slight for this project, and only consisted of including an extra line of code for the "MSP430FRxxxx" boards that turned off the default GPIO high impedance mode, and allowed the LED's to turn on.

# Problems that occurred
The only problem that was ran into involved the line of code that shut off the default GPIO high impedance mode. Because the example used was for a board that didn't require that line, it took a long time to discover that this was required for certain boards.