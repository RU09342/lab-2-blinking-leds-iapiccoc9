#include <msp430.h>
//Chris Iapicco
//Updated: September 24th, 2017
//Last Updated: October 6th, 2017
/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    unsigned int i; //Creates an int for use in delay loops
    P1DIR|=BIT5; //Sets the direction of PORT1.5 to output
    P1REN|=BIT3;//Enables resistor at P1.3
    P1OUT|=BIT3;//P1.3 resistor-> pullup
    P1IE|=BIT3;//P1.3 interrupt enable
    P1IES|=BIT3;//P1.3 interrupt edge selected to falling edge
    _enable_interrupt();//Enables interrupts
    while (1) //Creates an infinite loop
    {

    }
    return 0;
}
unsigned int i;//Int for timing
#pragma vector=PORT1_VECTOR//Port 1 interrupt service routine
__interrupt void Port_1(void)
{
    P1OUT^=BIT5;//Toggle GPIO output @ P1.5
   for(i=40000;i>1;i--);//Delay loop
   P1IFG&=~BIT3;//Clears P1.3 interrupt flag
}
