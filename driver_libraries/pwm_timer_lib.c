/*
 * pwm_timer_lib.c
 *
 *  Created on: Jan 26, 2020
 *      Author: satish
 */

#include "pwm_timer_lib.h"
#define clear_timer_enable 0xFE
#define time_out_configuredvalue  0x4B0000 

/*Genrally used for a timeout feature*/
void intilize_general_purpose_timer()
{
   /*Initilize GPTM*/
    SYSCTL_RCGCTIMER_R = 0X01;
   /*Timer registers enable*/
   TIMER0_CTL_R = (TIMER0_CTL_R & clear_timer_enable);
   TIMER0_CFG_R = 0x00;
   /*Start the timer for one shot execution */
   TIMER0_TAMR_R = TIMER0_TAMR_R | TIMER_TAMR_TACDIR | TIMER_TAMR_TAMIE | TIMER_TAMR_TAMR_1_SHOT ;
   TIMER0_TAILR_R = time_out_configuredvalue;
   TIMER0_IMR_R = 0x01;
}

void starttimer()
{
    TIMER0_CTL_R = (TIMER0_CTL_R | 0x01);
}

uint8_t timeout_reached()
{
    TIMER0_CTL_R = (TIMER0_CTL_R & clear_timer_enable);
    return(01);
}

