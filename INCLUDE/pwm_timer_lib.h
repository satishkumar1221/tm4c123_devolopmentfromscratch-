/*
 * pwm_timer_lib.h
 *
 *  Created on: Jan 26, 2020
 *      Author: satish
 */

#ifndef INCLUDE_PWM_TIMER_LIB_H_
#define INCLUDE_PWM_TIMER_LIB_H_

#include "tm4c123gh6pm.h"


typedef enum
{
    single_shot_mode = 0x01,
    periodicmode
}timer_config;


void intilize_general_purpose_timer();
void starttimer(uint32_t delay , timer_config config);
uint8_t timeout_reached();
void stopttimer();


#endif /* INCLUDE_PWM_TIMER_LIB_H_ */
