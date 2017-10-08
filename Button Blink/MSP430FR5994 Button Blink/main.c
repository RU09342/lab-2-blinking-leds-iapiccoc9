#include <msp430.h> 
//Chris Iapicco
//Created: September 13th, 2017
//Last Updated: September 24th, 2017
/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    unsigned int i;  //Creates an integer i for use in for loops
    PM5CTL0 &= ~LOCKLPM5;//Turns off the default GPIO high impedance mode
    P1DIR= BIT0; //Sets the direction of PORT1.0 to output
    P5DIR =0x00; //Sets all PORT5 bits to input
    P5REN = BIT5;  //Sets the port 5.5 pullup/pulldown resistor to enabled
    P5OUT = BIT5;  //Sets the port 5.5 resistor to pullup
    while (1) //Creates an infinite loop
    {
        if ((P5IN & BIT5) == 0x00) //Determines if the button is pressed down, and the pin is shorted to gnd
        {
            P1OUT ^= BIT0; //Toggles the output on port 1.0
            for (i = 40000; i > 1; i--); //Creates a delay to prevent one button press from being registered multiple times
        }
     }



    return 0;
}
