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

    unsigned int i; //Creates an int to be used in a delay loop
    P1DIR=0x01; //Sets PORT1.0 to output

    while(1) //Creates an infinite loop
    {
        P1OUT^=0x01; //Toggles the output of PORT1.0

        for (i=40000;i>1;i--); //Creates a delay in between each blink
    }

    return 0;
}
