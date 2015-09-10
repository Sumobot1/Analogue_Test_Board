#include	"xc.h"				// XC compiler general include file

#include	"stdint.h"			// Include integer definitions
#include	"stdbool.h"			// Include Boolean (true/false) definitions

#include	"PIC16F676header.h"			// Include user-created constants and functions

void initPorts(void)
{
	// TODO - Initialize oscillator, ports, and add (optional) user functions.

	// Initialize user ports and peripherals.

	
    ADCON0 = 0b00000001;		// Set 4MHz conversion clock, A/D off,
	ADCON1 = 0b00010000;		// left justified result, VDD reference
    ANSEL = 0b01110000;			// Make all PORTA pins digital I/O
    CMCON = 0b00000111;
	//ANSELH = 0b00000000;		// Make all PORTB pins digital I/O
    //OPTION_REG = 0b01010111;	// PORTB pull-ups on, TMR0 internal div 256

	// Set port directions for I/O pins: 0 = Output, 1 = Input

	TRISA = 0b00000000;			// Set runLED, IR LEDs as outputs in PORTA
	//TRISB = 0b00000000;			// Set all PORTB pins for LED output
	TRISC = 0b00000111;			// Set up receive and transmit lines for IR
    // demodulator (U5) and LED11, servo outputs

	// Set starting I/O conditions.

	PORTA = 0;					// Turn off all PORTA outputs, turn on run LED
	//PORTB = 0;					// Turn off all PORTB LEDs
	PORTC = 0;					// Turn off all PORTC outputs

	// Enable interrupts, if needed.
}