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
    P1OUT &= ~BIT0; //Clears the output of PORT1.0
    P1DIR |=BIT0; //Sets the direction of PORT1.0 to output
    PM5CTL0 &=~LOCKLPM5;//Turns off the GPIO default high impedance mode
    while(1) //Creates an infinite loop
    {
        P1OUT ^=0x01; ///Toggles the output to PORT1.0

        for (i=40000;i>1;i--); //Creates a delay in between blinks
    }

    return 0;
}
