/*
 * Probe-Scope Digital Test Button Driver
 * 
 * @Company
 *   Probe-Scope Team
 * 
 * @File Name
 *   buttons.h
 * 
 * @Summary
 *   Interface to the button on the board.
*/

#ifndef BUTTONS_H
#define	BUTTONS_H

#include <stdbool.h>

#ifdef	__cplusplus
extern "C"
{
#endif


bool button_read (void);


#ifdef	__cplusplus
}
#endif

#endif	/* BUTTONS_H */
