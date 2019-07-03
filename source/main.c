/*	Author: zlian030
*       Partner(s) Name: 
*	Lab Section:
*	Assignment: Lab #6  Exercise #1
*	Exercise Description: [optional - include for your own benefit]
*
*	I acknowledge all content contained herein, excluding template or example
*	code, is my own original work.
*/
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {start, LED1, LED2, LED3} state;
/*unsigned char temp = 0x00;
unsigned char temp2 = 0x00;*/
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
	    state = LED1;
	    break;
	case LED1:
	    state = LED2;
	    break;
	case LED2:
	    state = LED3;
	    break;
	case LED3:
	    state = LED1;
	    break;
		    
		    
}
