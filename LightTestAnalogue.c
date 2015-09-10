/* 
 * File:   LightTest.c
 * Author: peetm2593
 *
 * Created on June 24, 2015, 3:14 PM
 */


#include	"xc.h"				// XC general include file

#include	"stdint.h"			// Include integer definitions
#include	"stdbool.h"			// Include Boolean (true/false) definitions

#include "PIC16F676header.h"

/*==============================================================================
    A/D conversion function. Pass the channel to be converted using one of the
    definitions in CHRP3.h. Returns the most significant 8-bits of the result.
==============================================================================*/

unsigned char adConvert(unsigned char chan) {
    ADON = 1; // Turn A-D converter on
    ADCON0 = (ADCON0 & 0b11000011); // Change the conversion channel by wiping
    ADCON0 = (ADCON0 | chan); // CHS bits and ORing with selected channel
    asm("nop"); // Wait to allow the input to stabilize
    GO_DONE = 1; // Start the conversion

    while (GO_DONE); // Wait for the conversion to finish (GO_DONE=0)

    ADON = 0; // Turn A-D converter off and
    return (ADRESH); // return the upper 8-bits of the result
}

/*==============================================================================
    A/D conversion function. Pass the channel to be converted using one of the
    definitions in CHRP3.h. Returns the most significant 8-bits of the result.
==============================================================================*/

void PWM1(unsigned char number) {
    unsigned char cTemp = 0b00000000;
    while (cTemp < 0b11111111) {
        if (cTemp >= number) {
            RED2 = 0;
        } else {
            RED2 = 1;
        }
        cTemp++;
    }
}

void PWM2(unsigned char number) {
    unsigned char cTemp = 0b00000000;
    while (cTemp < 0b11111111) {
        if (cTemp >= number) {
            GREEN2 = 0;
        } else {
            GREEN2 = 1;
        }
        cTemp++;
    }
}

void PWM3(unsigned char number) {
    unsigned char cTemp = 0b00000000;
    while (cTemp < 0b11111111) {
        if (cTemp >= number) {
            BLUE2 = 0;
        } else {
            BLUE2 = 1;
        }
        cTemp++;
    }
}

/*==============================================================================
    Main program code
==============================================================================*/
int main(void) {
    // Initialize I/O and peripherals for PORTB output
    initPorts();

    while (1) {
        unsigned char HIIN2 = 0b00010000;
        //unsigned char hiin = adConvert(HIIN);
        PWM1(adConvert(HIIN2));
        unsigned char MIDIN2 = 0b00010100;
        //unsigned char midin = adConvert(MIDIN);
        PWM2(adConvert(MIDIN2));
        //unsigned char loin = adConvert(LOIN);
        unsigned char LOIN2 = 0b00011000;
        PWM3(adConvert(LOIN2));
    }
}