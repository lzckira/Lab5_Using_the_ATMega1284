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
    unsigned char tmpC = 0x00;
;
    while (1) {
	tmpA = PINA;
	if (tmpA >= 13) {
	    tmpC = 0x3F;
	}	

        else if (tmpA >= 10) {
            tmpC = 0x3E;
        }

        else if (tmpA >= 7) {
            tmpC = 0x3C;
        }

        else if (tmpA >= 5) {
            tmpC = 0x38;
        }

        else if (tmpA >= 3) {
            tmpC = 0x70;
        }

        else if (tmpA >= 1){
            tmpC = 0x60;
        }
	
	else {
	    tmpC = 0x40;
	}

	PORTC = tmpC;
    }
    return 1;
}
