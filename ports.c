/*
 * Probe-Scope Digital Test Port Definitions
 * 
 * @Company
 *   Probe-Scope Team
 * 
 * @File Name
 *   ports.c
 * 
 * @Summary
 *   Defines the IO ports used by the hardware.
*/

#include "ports.h"

#include <xc.h>


void
ports_init ()
{
	LED_0_TRIS   = PORT_OUTPUT;
	LED_0_LAT    = PIN_OFF;
	
	LED_1_TRIS   = PORT_OUTPUT;
	LED_1_LAT    = PIN_OFF;
	
	LED_2_TRIS   = PORT_OUTPUT;
	LED_2_LAT    = PIN_OFF;
	
	BUTTON_TRIS  = PORT_INPUT;
	BUTTON_LAT   = PIN_OFF;
	BUTTON_ANSEL = PIN_DIGITAL;
}
