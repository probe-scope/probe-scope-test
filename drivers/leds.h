/*
 * Probe-Scope Digital Test LED Driver
 * 
 * @Company
 *   Probe-Scope Team
 * 
 * @File Name
 *   leds.h
 * 
 * @Summary
 *   Interface to the debug LEDs on the board.
*/

#ifndef LEDS_H
#define LEDS_H


#include <stdbool.h>


#define LED_COUNT 3

#define LED_ON     1
#define LED_OFF    0

#define LED_ON_OD  0
#define LED_OFF_OD 1


#ifdef	__cplusplus
extern "C"
{
#endif


typedef enum
{
    LED_0,
    LED_1,
	LED_2
} led_t;


void led_on     (led_t led);
void led_off    (led_t led);
void led_toggle (led_t led);
bool led_get    (led_t led);


#ifdef	__cplusplus
}
#endif

#endif /* LEDS_H */
