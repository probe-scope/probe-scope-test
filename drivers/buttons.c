/*
 * Probe-Scope Digital Test Button Driver
 * 
 * @Company
 *   Probe-Scope Team
 * 
 * @File Name
 *   buttons.c
 * 
 * @Summary
 *   Interface to the button on the board.
*/

#include "buttons.h"

#include <stdbool.h>

#include "../ports.h"

bool
button_read (void)
{
    if (BUTTON_PORT == PIN_ON)
	{
		return false;
	}
	else
	{
		return true;
	}
}
