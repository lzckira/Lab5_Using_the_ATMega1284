/*	Author: zlian030
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>

#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {start, press, waitRelease} state;
//unsigned char order = 0x01;
unsigned char cont = 0x00;

void Tick();

int main(void) {

DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
    state = start;
    while (1) {
	Tick();
    }
    return 1;
}


void Tick() {
    switch(state) {
	case start:
	    state = waitRelease;
	    break;
	case press:
	    if (~PINA == 0x01) {
	        state = waitRelease;
	        cont = cont + 0x01;
	    }
	    else {
		state = press;
	    }
	    break;
	
	case waitRelease:
	    if (~PINA == 0x00) {
		state = press;
	    }
	    else {
		state = waitRelease;
	    }
	    break;
        default:
	    state = waitRelease;
            break;
    }

    switch (state) {
	case start:
	    break;
        case press:
	    if (cont == 0x00) {
		 PORTC = 0x01;   
	    }
	    else if (cont == 0x01) {
                 PORTC = 0x02;
	    
	    }
	    else if (cont == 0x02) {
                 PORTC = 0x03;
	    
	    }
            else if (cont == 0x03) {
                 PORTC = 0x04;
	    
	    }
            else if (cont == 0x04) {
                 PORTC = 0x05;
	    
	    }
            else if (cont == 0x05) {
                 PORTC = 0x06;
	    
	    }
            else {
                 PORTC = 0x00;
	    
	    }
	    break;    
        case waitRelease:
            if (cont == 0x00) {
                 PORTC = 0x01;
            }
            else if (cont == 0x01) {
                 PORTC = 0x02;

            }
            else if (cont == 0x02) {
                 PORTC = 0x03;

            }
            else if (cont == 0x03) {
                 PORTC = 0x04;

            }
            else if (cont == 0x04) {
                 PORTC = 0x05;

            }
            else if (cont == 0x05) {
                 PORTC = 0x06;

            }
            else {
                 PORTC = 0x00;

            }

            break;
        default:

            break;


    } 
    


      
}
