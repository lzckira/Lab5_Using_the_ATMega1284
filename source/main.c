/*	Author: zlian030
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>

#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {start, ADD, ADDwait, SUB, SUBwait, wait, reset} state;
unsigned char temp = 0x01;
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
	    state = waitRelease;
	    break;
        case seq1:
	    if (PINA == 0x01) {
		temp = 0x02;
                state = waitRelease;
	    }
            break;
	case seq2:
	    if (PINA == 0x01) {
		temp = 0x03;
                state = waitRelease;
	    }
	    break;
	case seq3;
	    if (PINA == 0x01) {
		temp = 0x04;
                state = waitRelease;
	    }
	    break;
        case seq4:
            if (PINA == 0x01) {
                temp = 0x05;
                state = waitRelease;
            }
            break;
        case seq5:
            if (PINA == 0x01) {
                temp = 0x06;
                state = waitRelease;
            }
            break;
        case seq6:
            if (PINA == 0x01) {
                temp = 0x01;
		state = waitRelease;
            }
            break;


	case waitRelease:
	    if (PINA == 0x00) {
		if (temp == 0x01) {
		    state = seq1;
		}
                else if (temp == 0x02) {
                    state = seq2;
                }
                else if (temp == 0x03) {
                    state = seq3;
                }
                else if (temp == 0x04) {
                    state = seq4;
                }
                else if (temp == 0x05) {
                    state = seq5;
                }
		else {
		    state = seq6;
		}
	    }
	    break;
        default:
	    state = waitRelease;
            break;
    }

    switch (state) {
	case start:
	    break;
        case seq1:
	    PORTB = 0x03;
	    break;
        case seq2:
            PORTB = 0x06;
            break;
        case seq3:
            PORTB = 0x0C;
            break;
        case seq4:
            PORTB = 0x18;
            break;
        case seq5:
            PORTB = 0x30;
            break;
        case seq6:
            PORTB = 0x60;
            break;



    } 
    


    PORTC = temp;    
}
