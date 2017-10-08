#include <msp430.h> 
//Chris Iapicco
//Created: October 4th, 2017
//Last Updated: October 4th, 2017
/**
 * main.c
 */
unsigned int i=0;//variable used for timing
unsigned int x=0;//variable used for logic
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1OUT|=BIT1;//P1.1 resistor-> pullup, button
	P1REN|=BIT1;//P1.1 resistor enable, button
	P1IE|=BIT1;//P1.1 interrupt enable
	P1IES|=BIT1;//P1.1 interrupt edge->falling edge, button push
	P1DIR|=BIT0;//P1.0 output enabled
	P4DIR&=~BIT7;//P4.7 output disabled
	_enable_interrupt();//Enables interrupts
	while (1)//infinite loop
	{
	    P4OUT^=BIT7;
	    P1OUT^=BIT0;
	    for (i=40000;i>1;i--);
	}
	return 0;
}
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
P1DIR ^= BIT0;//Toggle which LED output is enabled
P4DIR^=BIT7;//Toggle which LED output is enabled
P1IFG &= ~BIT1; // P1.3 IFG cleared
for (i=60000;i>1;i--); // P1.0 = toggle

}

