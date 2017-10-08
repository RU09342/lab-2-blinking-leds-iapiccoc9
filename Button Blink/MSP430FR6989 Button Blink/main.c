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

    unsigned int i;//Creates an int for delay
    PM5CTL0 &=~LOCKLPM5;//Disables the GPIO high impedance mode
    P1DIR=0x01;//Sets PORT1.0 to output
    P1REN=BIT1;//Enables resistor at PORT1.1
    P1OUT|=BIT1;//Sets resistor at PORT1.1 to pullup

    while (1)//Creates an infinite loop
    {
        if ((P1IN & BIT1 )== 0x00)//Checks if button at PORT1.1 is pressed
        {
            P1OUT^=0x01;//Toggles LED output at PORT1.0
            for (i=40000;i>1;i--);//Creates delay loop
        }
    }

    return 0;
}
