/* 
 * File:   PIC16F676.h
 * Author: peetm2593
 *
 * Created on June 24, 2015, 1:31 PM
 */



#define IRReciever RA5
#define ModeLED RA4
#define HIIN RC0
#define MIDIN RC1
#define LOIN RC2
/*We ignored RA3 because it is not analogue.  It is the mclr bit*/
#define GREEN2 RC5
#define BLUE2 RC4
#define RED2 RC3
#define GREEN1 RA2
#define BLUE1 RA1
#define RED1 RA0

#define _XTAL_FREQ	4000000			// Set clock frequency for time delays
#define FCY			_XTAL_FREQ/4	// Set processor cycle time

void initPorts(void);    // Port configuration function prototype declaration

