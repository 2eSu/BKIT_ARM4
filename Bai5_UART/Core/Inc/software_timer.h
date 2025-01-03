/*
 * software_timer.h
 *
 *  Created on: Sep 24, 2023
 *      Author: HaHuyen
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "tim.h"
#include <stdbool.h>

#define FREQUENCY_OF_TIM	1000 //Hz
#define READ_BUTTON_TIME	10 //50ms
#define BLINKING_TIME		1000 // blink in 2Hz
#define INCREASE_TIME		200//200ms

void set_timer(unsigned i, unsigned int time);
void run_timer(void);
bool is_timer_on(unsigned i);

extern uint16_t flag_timer2;

void timer_init();
void setTimer2(uint16_t duration);

#endif /* INC_SOFTWARE_TIMER_H_ */
