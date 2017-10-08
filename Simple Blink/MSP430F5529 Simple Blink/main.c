#include <msp430.h> 
// Chris Iapicco
// September 13th, 2017
// Last updated: September 24th, 2017
unsigned int i=0; //Creates an int for use in for loops for delay
/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1DIR= 0x01; //Sets the first bit of the P1 register to an output

    while (1) //Creates an infinite loop
    {
        P1OUT ^= 0x01; //Toggles the output on PORT1.0

        for(i =0; i< 40000;i++); //Creates a delay between the blinks
    }



    return 0;
}
