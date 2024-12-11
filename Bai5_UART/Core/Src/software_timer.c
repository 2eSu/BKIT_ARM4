/*
 * software_timer.c
 *
 *  Created on: Sep 24, 2023
 *      Author: HaHuyen
 */

#include "software_timer.h"

#define TIMER_CYCLE_2 1
#define NUMBER_OF_TIMER	3
/*
 * bief: state --> timer is on or off (1: on, 0: off)
 * */
struct {
	bool state;
	unsigned int count;
} timer[NUMBER_OF_TIMER];
/* timer[0]: to read button
 * timer[1]: to blink number
 * timer[2]: to increase number over time
 * */


uint16_t flag_timer2 = 0;
uint16_t timer2_counter = 0;
uint16_t timer2_MUL = 0;

void timer_init(){
	HAL_TIM_Base_Start_IT(&htim2);
}

void setTimer2(uint16_t duration){
	timer2_MUL = duration/TIMER_CYCLE_2;
	timer2_counter = timer2_MUL;
	flag_timer2 = 0;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2){
		if(timer2_counter > 0){
			timer2_counter--;
			if(timer2_counter == 0) {
				flag_timer2 = 1;
				timer2_counter = timer2_MUL;
			}
		}
		led7_Scan();
	}
}

void set_timer(unsigned i, unsigned int time) {
	timer[i].count = time * FREQUENCY_OF_TIM / 1000.0;
	timer[i].state = 1;
}
/*
 * @brief:	run all timers that is on
 * @para:	none
 * @retval:	none
 * */
void run_timer(void) {
	for (unsigned i = 0; i < NUMBER_OF_TIMER; i++) {
		if (timer[i].state) {
			timer[i].count--;
			if (timer[i].count <= 0) {
				timer[i].state = 0;
			}
		}
	}
}
bool is_timer_on(unsigned i) {
	return (timer[i].state == 1);
}

