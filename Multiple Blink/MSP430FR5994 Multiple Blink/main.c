#include <msp430.h> 
//Chris Iapicco
//Created: September 13th, 2017
//Last Uppdated: September 24th, 2017
/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    unsigned int count; //Creates an int to be used for count
    PM5CTL0 &=~LOCKLPM5;//Turns off the GPIO default high impedance mode
    P1DIR=0x03;//Sets the two lsb in PORT1 to output

    while(1)//Creates an infinite loop
    {
        if (count%1000==0) P1OUT^=0x01;//Toggles the LED at PORT1.0 every 1000 loops

        if (count%2500==0) //Toggles the LED at PORT1.1 every 2500 loops
        {
            P1OUT^=0x02; //Toggles the LED at PORT1.1
            count=0;//Resets the count register
        }
        count++;//Increments
    }

    return 0;
}
