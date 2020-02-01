/*
 * eeprom_mngr.c
 *
 *  Created on: Feb 1, 2020
 *      Author: satish
 */
#include "eeprom.h"
#include "pwm_timer_lib.h"

#define EE_DONE_MASK 0x01
#define cpu_cyclesdelay(i,n) while(i<n) {i++;}
#define ERETRY_PRETRY 0x0C
#define reset_sr_eeprom 0x01
#define time_out_configuredvalue1  0x320000

eeprom_status eeprom_init_stat;
static eeprom_status poll_check_eeprom_status();

static eeprom_status poll_check_eeprom_status()
{
    uint8_t i=0;
    //   startimer(time_out_configuredvalue1,0x01);
       eeprom_status temp_status = eeprom_notokay;
       eeprom_status eeprom_pass_status = eeprom_okay;

      while((EEPROM_EEDONE_R & EE_DONE_MASK))
      {
//

          cpu_cyclesdelay(i,10);

          break;

      }
      temp_status = ((EEPROM_EESUPP_R & ERETRY_PRETRY) || (eeprom_pass_status == eeprom_notokay)  && (EEPROM_EEDONE_R == 0)) ? eeprom_notokay : eeprom_okay;
      return(temp_status);
      
}

void eeprom_driver_init()
{
      eeprom_status temp_status = eeprom_notokay;
      int i=0;
      SYSCTL_RCGCEEPROM_R = (EEPROM_EEPROT_PROT_RWPW); 
      /*According to Datasheet wait for 10 clock cycles after initilizing clock */ 
      cpu_cyclesdelay(i,10);
     /*According to datasheet wait until EEDONE register is set to 0 */
     /*Polling the working bit umtil it is clear */
      temp_status = poll_check_eeprom_status();
      
      if(temp_status == eeprom_okay )
      {
          /* Reset the SR_EEPROM according to the document */
        SYSCTL_SREEPROM_R = reset_sr_eeprom;
        SYSCTL_SREEPROM_R = 0;
        /*Insert delay according to datasheet*/
        i=0;
        cpu_cyclesdelay(i,100);
        temp_status = poll_check_eeprom_status();
        if( temp_status == eeprom_notokay)
        {
             systemresetfunction();
        }
      }
      else
      {
          /*eeprom failure*/
          temp_status = eeprom_notokay;
          systemresetfunction();
      }
      eeprom_init_stat = temp_status;


}

