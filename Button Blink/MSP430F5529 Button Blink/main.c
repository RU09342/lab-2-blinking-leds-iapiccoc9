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
    unsigned int i;//Creates an int for delay
    P1DIR=BIT0;//Sets PORT1.0 to output
    P1REN=BIT1;//Turns on resistor at PORT 1.1
    P1OUT=BIT1;//Sets PORT1.1 resistor to pullup

    while(1)//Creates an infinite loop
    {
        if ((P1IN & BIT1) ==0x00)//Checks if button at PORT1.1 is pressed
        {
            P1OUT^=BIT0;//Toggles LED at PORT1.0

            for (i=40000;i>1;i--);//Delay
        }
    }

    return 0;
}
