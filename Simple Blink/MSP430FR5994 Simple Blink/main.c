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
    unsigned int i; //Creates an int to be used for delay in for loops
    PM5CTL0 &=~LOCKLPM5;//Sets the GPIO default high impedance mode to OFF
    P1DIR=0x01; //Sets the direction for PORT1.0 to output
    P1OUT=0x00; //Sets the output register of PORT1 to all zeros
    while(1) //Creates an infinite loop
    {
        P1OUT^=0x01; ///Toggles the output to PORT1.0

        for (i=40000;i>1;i--); //Creates a delay in between blinks
    }

    return 0;
}
