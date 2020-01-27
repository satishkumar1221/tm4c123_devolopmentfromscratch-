/*
 * pwm_timer_lib.h
 *
 *  Created on: Jan 26, 2020
 *      Author: satish
 */

#ifndef INCLUDE_PWM_TIMER_LIB_H_
#define INCLUDE_PWM_TIMER_LIB_H_

#include "tm4c123gh6pm.h"
void intilize_general_purpose_timer();
void starttimer();
uint8_t timeout_reached();


#endif /* INCLUDE_PWM_TIMER_LIB_H_ */
