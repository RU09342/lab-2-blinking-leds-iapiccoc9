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
    PM5CTL0 &=~LOCKLPM5;//Turns off the GPIO default high impedance mode
    P1SEL0 =0x00; // Sets the select bits for PORT1
    P1SEL1 = 0x00;// to 00, making the PORT I/O
    P2SEL0 = 0x00; //Sets the select bits for PORT2
    P2SEL1=0x00; // to 00, making the port I/O
    P1DIR =0x01; //Sets PORT1.0 to output
    P2DIR = 0x01; //Sets PORT 2.0 to output
    unsigned int count=0; //Sets the count integer to 0
    P1OUT=0x00;//Sets the output register to 0
    P2OUT=0x00;//Sets the output register to 0
    while(1) //Creates an infinite loop
    {
        if (count%1000==0) P1OUT^=0x01; //Toggles the LED at PORT1.0 every 1000 loops

        if (count%2500==0) //Toggles the LED at PORT2.0 every 2500 loops
        {
            P2OUT^=0x01;//Toggles the output of PORT2.0
            count=0;//Resets the count register to 0
        }

        count++;//Increments count
    }

    return 0;
}
