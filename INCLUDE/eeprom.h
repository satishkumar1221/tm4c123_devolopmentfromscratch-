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

#define EEPROM_EERDWR_R_ADDRINCR (0x400AF014)
/*Texas Instruments API have to analyze */
#define OFFSET_FROM_ADDR(x) (((x) >> 2) & 0x0F)
#define EEPROMBlockFromAddr(ui32Addr) ((ui32Addr) >> 6)

/*typedef enum
{
  true,
  false
}Boolean;*/

typedef enum
{
    eeprom_okay,  //0
    eeprom_statuspending, //1
    eeprom_notokay //2

}eeprom_status;
extern eeprom_status eeprom_init_stat;


typedef struct {
    /*Address where data has to be written */
    uint32_t address;
    /*size of the data */
    uint16_t size;
    /*data*/
    uint32_t data; 
    /*status of the eedone register*/
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


extern eeprom_access_structure eeprom_access[];
void eeprom_write(const void *source , const void *destination , uint32_t size ,uint32_t *data );

void write_contents_toeeprom( uint8_t *data,uint8_t isdataarray , uint8_t size);
void write_contents_eeprom_byAddress(uint32_t *source_address , uint32_t *destination_address ,uint32_t size);
void eeprom_driver_init();

#endif /* INCLUDE_EEPROM_H_ */
