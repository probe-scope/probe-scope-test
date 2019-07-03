/*
 * Probe-Scope Digital Test Basic (No Harmony) Firmware
 * 
 * @Company
 *   Probe-Scope Team
 * 
 * @File Name
 *   main.c
 * 
 * @Summary
 *   Contains initialization and main task loop for general PIC32MZ EF usage.
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/attribs.h>

#include "ports.h"
#include "common/sw_timer.h"
#include "drivers/buttons.h"
#include "drivers/leds.h"

// BF1SEQ0
#pragma config TSEQ = 0x0000
#pragma config CSEQ = 0xFFFF


int main(void)
{
	// CPU Performance Optimization:
	register unsigned long tmp_cache;                 //KSEG0 cache enable
	__asm__("mfc0 %0,$16,0" :  "=r"(tmp_cache));
	tmp_cache = (tmp_cache & ~7) | 3;
	__asm__("mtc0 %0,$16,0" :: "r" (tmp_cache));
	PRECONbits.PFMWS=2;       //Flash wait states = 2 CPU clock cycles @ 200Mhz        
	PRECONbits.PREFEN = 2;    //Enable predictive prefetch for CPU instructions and CPU data
	
	// Interrupt setup
	PRISSbits.PRI7SS = 7;	//DMA Interrupt with priority level of 7 uses Shadow Set 7
	PRISSbits.PRI6SS = 6;	//Interrupt with priority level of 6 uses Shadow Set 6
	PRISSbits.PRI5SS = 5;	//Interrupt with priority level of 5 uses Shadow Set 5
	PRISSbits.PRI4SS = 4;	//Interrupt with priority level of 4 uses Shadow Set 4
	PRISSbits.PRI3SS = 3;	//Interrupt with priority level of 3 uses Shadow Set 3
	PRISSbits.PRI2SS = 2;	//Interrupt with priority level of 2 uses Shadow Set 2
	INTCONbits.MVEC = 1;	//Enable multi-vector interrupts
	__builtin_enable_interrupts(); // Global Interrupt Enable 
	
	// Subsystem initialization
	ports_init();
	sw_timer_init();
	
	// Timers
	sw_timer blink_timer = TIMER(500);
	sw_timer input_timer = TIMER(10);
	sw_timer_reset(&blink_timer);
	sw_timer_reset(&input_timer);
	
	bool button_state = false;
	led_off(LED_2);
	led_on(LED_0);
	
	while(1)
	{		
		// Button input handling
		if (sw_timer_expired(input_timer))
		{
			sw_timer_reset(&input_timer);
			if (input_timer.length > 50)
			{
				input_timer.length = 50;
			}
			
			if (!button_state && button_read())
			{ // Button Rising Edge
				button_state = true;
				led_on(LED_1);
			}
			else if (button_state && !button_read())
			{ // Button Falling Edge
				button_state = false;
				led_off(LED_1);
			}
		}
		
		// Blink LED
		if (sw_timer_expired(blink_timer))
		{
			sw_timer_reset(&blink_timer);
			
			// Blink normal LEDs
			led_toggle(LED_2);
			led_toggle(LED_0);
		}
	}
}
