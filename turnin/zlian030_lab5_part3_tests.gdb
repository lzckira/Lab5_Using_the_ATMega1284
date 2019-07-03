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

enum States {start, left, leftWait, right, rightWait, wait} state;
unsigned char temp = 0x00;
unsigned char temp2 = 0x00;
void Tick();

int main(void) {

DDRA = 0x00; PORTA = 0xFF; // Configure port B's 8 pins as inputs
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
	    state = wait;
	    break;
	case left:
	    state = leftWait;
	    break;
	case leftWait:
	    if (!(~PINA & 0x01)) {
		state = wait;
	    }
	    else {
		state = leftWait;
	    }
	    break;
	case right:
	    state = rightWait;
	    break;
	case rightWait:
	    if (!(~PINA & 0x01)){
		state = wait;
	    }
            else {
                state = rightWait;
            }
            break;
        case wait:
            if ((~PINA & 0X01) && (temp2 == 0x00)) {
                state = left;
            }
	    else if ((~PINA & 0x01)  && (temp2 == 0x01)) {
                state = right;
            }
	    else {
		state = wait;
	    } 
            break;
	default:
	    state = wait;
	    break;
    }

    switch(state) {
        case start:
            break;
        case left:
            temp = temp + 0x01;
	    if (temp == 0x05) {
		    temp2 = 0x01;
	    }
            break;
	case leftWait:
	    break;
        case right:
	    temp = temp - 0x01;

	    if (temp == 0x00) {
		    temp2 = 0x00;
	    }
            break;
	case rightWait:
	    break;
        case wait:
            break;
        default:

            break;
    }
    
    PORTC = 0x01 << temp;    
}
