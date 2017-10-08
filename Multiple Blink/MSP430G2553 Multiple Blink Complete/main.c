#include <msp430.h> 
//Chris Iapicco
//Created: September 13th, 2017
//Last Updated: September 21st, 2017
/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1DIR=0x41;  //Sets PORT1.0, and PORT1.2 to output
    unsigned int count=0;
    while(1) //Creates an infinite loop
    {
        if (count%1000==0) P1OUT^=0x01; //Every 1000 cycles toggle LED0

        if (count%2500==0) //Triggers every 2500 cycles
            {
            P1OUT^=0x40;//Toggle LED1
            count=0;//Reset counter register
            }
        count++;//increment counter register
    }

    return 0;
}

