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
    PM5CTL0 &=~LOCKLPM5; //Turns off the GPIO default high impedance mode to off
    unsigned int count; //Creates an int for LED timing

    P1DIR=0x01; //Sets the direction of PORT1.0 to output
    P9DIR = 0x80; //Sets the direction of PORT9.7 to output


    while(1) //Creates an infinite loop
    {
        if (count%1000==0) P1OUT^=0x01; //Toggles the LED at PORT1.0 every 1000 loops

        if (count%2500==0) //Toggles the LED at PORT9.7 every 2500 loops
        {
            P9OUT^=0x80; //Toggles PORT9.7
            count=0; //Resets the count integer
        }

        count++; //Increments the count integer
    }

    return 0;
}
