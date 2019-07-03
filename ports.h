/*
 * Probe-Scope Digital Test Port Definitions
 * 
 * @Company
 *   Probe-Scope Team
 * 
 * @File Name
 *   ports.h
 * 
 * @Summary
 *   Defines the IO ports used by the hardware.
*/

#include <xc.h>

#ifndef PORTS_H
#define	PORTS_H

#define LED_0_LAT      LATCbits.LATC13
#define LED_0_PORT     PORTCbits.RC13
#define LED_0_TRIS     TRISCbits.TRISC13

#define LED_1_LAT      LATCbits.LATC14
#define LED_1_PORT     PORTCbits.RC14
#define LED_1_TRIS     TRISCbits.TRISC14

#define LED_2_LAT      LATCbits.LATC15
#define LED_2_PORT     PORTCbits.RC15
#define LED_2_TRIS     TRISCbits.TRISC15

#define BUTTON_LAT     LATBbits.LATB10
#define BUTTON_PORT    PORTBbits.RB10
#define BUTTON_TRIS    TRISBbits.TRISB10
#define BUTTON_ANSEL   ANSELBbits.ANSB10


#define PORT_INPUT  1
#define PORT_OUTPUT 0

#define PIN_DIGITAL 0
#define PIN_ANALOG  1

#define PIN_ON      1
#define PIN_OFF     0

#define OPEN_DRAIN  1
#define PUSH_PULL   0

#define PULLUP_EN   1
#define PULLUP_DIS  0


#ifdef	__cplusplus
extern "C"
{
#endif


void ports_init ();


#ifdef	__cplusplus
}
#endif

#endif /* PORTS_H */
