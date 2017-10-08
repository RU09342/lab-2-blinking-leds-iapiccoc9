#include <msp430.h> 
//Chris Iapicco
//Created: September 13th, 2017
//Last Updated: October 4th, 2017
/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    unsigned int i; //Creates an int for use in delay
    P1DIR=0x01;//Sets PORT1.0 to output
    P1REN=0x08;//Enables resistor at PORT1.3
    P1OUT=0x08;//Enables pullup resistor at PORT1.3

    while (1)//Creates an infinite loop
    {

        if ((P1IN & 0x08) != 0x08)//Checks if the button at PORT1.3 is pressed
        {
            P1OUT^=0x01;//Toggles the LED at PORT1.0
            for (i=50000;i>1;i--);//Delay
        }

    }

    return 0;
}
