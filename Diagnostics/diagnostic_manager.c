/*
 * diagnostic_manager.c
 *
 *  Created on: Feb 1, 2020
 *      Author: satish
 */

#include "diagnostic_manager.h"

uint8_t Fault_Info[Total_DTC_Number];
uint8_t warm_up_cycles = 0x01 ;
uint8_t malfunctiontimes = 0x02;
void set_bits(uint8_t *varname, uint8_t number )
{
    *(varname) = (*varname |= number);
}
void testfaillogic(DTC_Name Name )
{
    set_bits(&Fault_Info[Name],1);
   // malfunctiontimes[Name]++;
}
