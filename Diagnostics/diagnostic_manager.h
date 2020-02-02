/*
 * diagnostic_manager.h
 *
 *  Created on: Feb 1, 2020
 *      Author: satish
 */

#ifndef DIAGNOSTICS_DIAGNOSTIC_MANAGER_H_
#define DIAGNOSTICS_DIAGNOSTIC_MANAGER_H_
#include "stdint.h"

typedef enum
{
    SPI_Fault,
    I2C_Fault,
    EEPROM_FAULT,
    RAM_FAULT,
    RTC_FAULT,
    Total_DTC_Number
}DTC_Name;

DTC_Name name[Total_DTC_Number];

void set_bits(uint8_t *varname, uint8_t number );
void testfaillogic(DTC_Name Name );
extern uint8_t Fault_Info[Total_DTC_Number];
extern uint8_t warm_up_cycles;//[Total_DTC_Number];
extern uint8_t malfunctiontimes;//[Total_DTC_Number];
/*typedef struct 
{

} ;*/



/*5 DTC's(Diagnostic Trouble codes)*/







#endif /* DIAGNOSTICS_DIAGNOSTIC_MANAGER_H_ */
