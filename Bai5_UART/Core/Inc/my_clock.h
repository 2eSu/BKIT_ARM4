/*
 * my_clock.h
 *
 *  Created on: Dec 11, 2024
 *      Author: ADMIN
 */

#ifndef INC_MY_CLOCK_H_
#define INC_MY_CLOCK_H_


#include "my_display.h"
#include <stdbool.h>
#include "button.h"
void update_ds3231_register(void);
void fsm_clock(void);
#endif /* INC_MY_CLOCK_H_ */
