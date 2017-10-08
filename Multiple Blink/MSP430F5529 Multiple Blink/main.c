#include <msp430.h> 
//Chris Iapicco
//Created: September 13th, 2017
//Last Updated: Deptember 22nd, 2017
/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    unsigned int i; //Creates an int for delay
    P1DIR=0x01; //Changes the direction of PORT1.0 to output
    P1SEL=0x00; //Sets all of PORT1 to I/O
    P4DIR = 0x80; //Sets PORT4.7 to output
    P4SEL = 0x00; //Sets all of PORT4 to I/O

    unsigned int count=0;
    while(1) //Creates an infinite loop
    {
        if (count%1000==0) P1OUT^=0x01;//Toggles the LED at PORT1.0 every 1000 loops

        if (count%2500==0)//Toggles the LED at PORT4.7 every 2500 loops
        {
            P4OUT^=0x80;//Toggles the LED at PORT4.7
            count=0;//Resets the count register
        }

        count++;//Increments the count register


    }

    return 0;
}
