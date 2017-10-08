#include <msp430.h> 
//Chris Iapicco
//Created: September 13th, 2017
//Last updated: September 24th, 2017
/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    unsigned int i=0; //Creates an integer to be used in for loops for delay
    PM5CTL0 &=~LOCKLPM5;//Sets the GPIO default high imppedance mode to OFF
    P1DIR=0x01; //Sets the direction of PORT1.0 to be output
    P1OUT=0x01; //Sets the output or PORT1.0 to 1
    while(1) //Creates an infinite loop
    {
        P1OUT^=0x01; //Toggles the output of PORT1.0, the LED

        for (i=20000;i>1;i--); //Creates a delay in between the blinks
    }

    return 0;
}
