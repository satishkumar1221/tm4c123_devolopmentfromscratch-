/*
 * pwm_timer_lib.c
 *
 *  Created on: Jan 26, 2020
 *      Author: satish
 */

#include "pwm_timer_lib.h"
#define clear_timer_enable 0xFE

#define TACDIR_COUNTDOWN 0x10
/*Genrally used for a timeout feature*/
void intilize_general_purpose_timer()
{
   /*Initilize GPTM*/

   /*Timer registers enable*/


  // TIMER0_TAMATCHR_R  =  time_out_configuredvalue;
  // TIMER0_TAILR_R = time_out_configuredvalue;
   //TIMER0_IMR_R = (TIMER0_IMR_R |TACDIR_COUNTDOWN);
   //TIMER0_ICR_R = 0x00;
}

void stopttimer()
{

    TIMER0_CTL_R = (TIMER0_CTL_R & clear_timer_enable);
    TIMER0_ICR_R = 0x01;
}


void starttimer(uint32_t delay , timer_config config)
{
    SYSCTL_RCGCTIMER_R = 0X01;
    TIMER0_CTL_R = (TIMER0_CTL_R & clear_timer_enable);
    TIMER0_CFG_R = 0x00;
    /*Start the timer for one shot execution */
    TIMER0_TAMR_R = (TIMER0_TAMR_R | TACDIR_COUNTDOWN | /*TIMER_TAMR_TAMIE| */config) ;
    TIMER0_TAMATCHR_R  =  delay;
    TIMER0_TAILR_R = delay;
    TIMER0_CTL_R = (TIMER0_CTL_R | 0x01);
}

uint8_t timeout_reached()
{
    uint8_t temp;
    temp = (TIMER0_RIS_R ==  0x01) ? 1 :0;
    /*clear the interrupt*/

   // TIMER0_CTL_R = (TIMER0_CTL_R & clear_timer_enable);
    return(temp);
}

