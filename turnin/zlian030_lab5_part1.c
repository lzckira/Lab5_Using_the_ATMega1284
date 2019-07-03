/*	Author: zlian030
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
    unsigned char tmpA = 0x00;
//    unsigned char tmpC = 0x00;

    while (1) {	
	tmpA = ~PINA;
	if ((tmpA & 0x0F) >= 0x0D) {
	    PORTC = 0x3F;
	}	
        else if (((tmpA & 0x0F) >= 0x0A) && ((tmpA & 0x0F) < 0x0D)) {
            PORTC = 0x3E;
        }
        else if (((tmpA & 0x0F) >= 0x07) && ((tmpA & 0x0F) < 0x0A)) {
            PORTC = 0x3C;
        }
        else if (((tmpA & 0x0F) >= 0x05) && ((tmpA & 0x0F) < 0x07)) {
            PORTC = 0x38;
        }
        else if (((tmpA & 0x0F) >= 0x03) && ((tmpA & 0x0F) < 0x05)) {
            PORTC = 0x70;
        }
        else if (((tmpA & 0x0F) >= 0x01) && ((tmpA & 0x0F) < 0x03)){
            PORTC = 0x60;
        }	
	else {
	    PORTC = 0x40;
	}

//	PORTC = tmpC;
    }
    return 1;
}
