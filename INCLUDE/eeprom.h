/*
 * eeprom.h
 *
 *  Created on: Feb 1, 2020
 *      Author: satish
 */

#ifndef INCLUDE_EEPROM_H_
#define INCLUDE_EEPROM_H_

#include "tm4c123gh6pm.h"
#include "pwm_timer_lib.h"
#include "sys_init.h"
typedef enum
{
    eeprom_okay,  //0
    eeprom_statuspending, //1
    eeprom_notokay //2

}eeprom_status;
extern eeprom_status eeprom_init_stat;


void eeprom_driver_init();

#endif /* INCLUDE_EEPROM_H_ */
