/*
 * Probe-Scope Digital Test LED Driver
 * 
 * @Company
 *   Probe-Scope Team
 * 
 * @File Name
 *   leds.c
 * 
 * @Summary
 *   Interface to the debug LEDs on the board.
*/

#include "leds.h"

#include <xc.h>
#include <stdbool.h>

#include "../ports.h"


void
led_on (led_t led)
{
	switch (led)
	{
		case LED_0:
			LED_0_LAT = LED_ON;
			break;
		
		case LED_1:
			LED_1_LAT = LED_ON;
			break;
		
		case LED_2:
			LED_2_LAT = LED_ON;
			break;
		
		default:
			break;
	}
}

void
led_off (led_t led)
{
	switch (led)
	{
		case LED_0:
			LED_0_LAT = LED_OFF;
			break;
		
		case LED_1:
			LED_1_LAT = LED_OFF;
			break;
		
		case LED_2:
			LED_2_LAT = LED_OFF;
			break;
		
		default:
			break;
	}
}

void
led_toggle (led_t led)
{
	switch (led)
	{
		case LED_0:
			LED_0_LAT ^= 1;
			break;
		
		case LED_1:
			LED_1_LAT ^= 1;
			break;
		
		case LED_2:
			LED_2_LAT ^= 1;
			break;
		
		default:
			break;
	}
}

bool
led_get (led_t led)
{
	bool result = false;

	switch (led)
	{
		case LED_0:
			result = ((LED_0_LAT == LED_ON) ? true : false);
			break;
		
		case LED_1:
			result = ((LED_1_LAT == LED_ON) ? true : false);
			break;
		
		case LED_2:
			result = ((LED_2_LAT == LED_ON) ? true : false);
			break;
		
		default:
			break;
	}
	
	return result;
}
