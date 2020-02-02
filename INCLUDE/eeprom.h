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
#include "diagnostic_manager.h"

#define EEPROM_EERDWR_R_ADDRINCR         (0x400AF014)


typedef enum 
{
  TRUE,
  FALSE
}Boolean;

typedef enum
{
    eeprom_okay,  //0
    eeprom_statuspending, //1
    eeprom_notokay //2

}eeprom_status;
extern eeprom_status eeprom_init_stat;


typedef struct {
    /* data */
    uint16_t block_number; 
    uint16_t ee_offset_value;
   // uint8_t readwriteincrementregister;
   // uint16_t eeprom_read_write_interfacereg;
    Boolean status_eedoneregister;

}eeprom_access_structure;

typedef struct 
{
    Boolean password_protected_status;
    uint32_t ee_last_password; 
    uint32_t ee_second_password;
    uint32_t ee_first_password; 
    /* data */
}eeprom_passwordstruct;




/*Function pointers to all the functions that need data to be filled in this structure*/
/*Eventally have to modify the linker file to select section by section for the transfer of the data in block*/
typedef struct 
{
     /*For now I need ot transfer 5 Bytes of data */
     uint8_t *ptr_fault_array;
     uint8_t *ptr_warmup_cycles;
     uint8_t *ptr_malfunctionrepeated;
     

}eeprom_data_Structure;// common structure to have all the elements that have to be stored in the e2prom 


typedef struct 
{
   eeprom_access_structure access_struct; 
   eeprom_passwordstruct  pwd_protected; 
   eeprom_data_Structure data_cpd_rcvd_eeprom;
}eeprom_struct;

extern eeprom_struct eeprom_access;
void mem_copy(const void *source , const void *destination , uint32_t size);

void write_contents_toeeprom(eeprom_struct *access_handle);
void eeprom_driver_init();

#endif /* INCLUDE_EEPROM_H_ */
