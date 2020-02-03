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
eeprom_struct eeprom_access;

/*Prototypes */
static eeprom_status poll_check_eeprom_status();
 
static void initlize_eeprom_struct();


static void initlize_eeprom_struct()
{
   eeprom_access.access_struct.block_number = 0x01;              
   eeprom_access.access_struct.ee_offset_value = 0x01;//Access one word at a time
   eeprom_access.pwd_protected.password_protected_status = FALSE;
   eeprom_access. data_cpd_rcvd_eeprom. ptr_fault_array = &Fault_Info;
   eeprom_access. data_cpd_rcvd_eeprom. ptr_warmup_cycles = &warm_up_cycles;
   eeprom_access. data_cpd_rcvd_eeprom. ptr_malfunctionrepeated = &malfunctiontimes;
}
   
//static void storedatatoeeprom()

/*Function Defanitions*/

static eeprom_status poll_check_eeprom_status()
{
    uint8_t i=0;
    //   startimer(time_out_configuredvalue1,0x01);
       eeprom_status temp_status = eeprom_notokay;
       eeprom_status eeprom_pass_status = eeprom_okay;

      while((EEPROM_EEDONE_R & EE_DONE_MASK))
      {

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
      initlize_eeprom_struct();
      write_contents_toeeprom(&eeprom_access);

}

/*This function was written to push the data into interface register */
/*Write a logic for multi block data and add a check for data check */
void mem_copy(const void *source , const void *destination , uint32_t size)
{
    int i=0;
    char *src = (char*)source;  
    char *dst = (char*)destination;
    /*Add a check to read contents from e2prom before writing it */
    /*Access one word at a same time */
    EEPROM_EEOFFSET_R = eeprom_access.access_struct.ee_offset_value;
    for(i =0 ; i<size ; i++)
    {
        /*Offset and destination must be set a same time*/

        dst[i] =src[i];
        i++;

    }

}

/*Multiple Data Copy E2PROM */
void write_contents_toeeprom(eeprom_struct *access_handle)
{
        /* Access the EEPROM Registers */
        EEPROM_EEBLOCK_R = access_handle->access_struct.block_number;

        
        if(access_handle->pwd_protected.password_protected_status)
        {
       
        }
        else
        {
            /* code */
        }
        if(!EEPROM_EEDONE_R)
        {
            mem_copy(&access_handle->data_cpd_rcvd_eeprom, (uint32_t *)EEPROM_EERDWR_R_ADDRINCR, sizeof(access_handle->data_cpd_rcvd_eeprom)); //EEPROM_EERDWR_R_ADDRINCR
        }
        else
        {
            /* code */
            testfaillogic(EEPROM_FAULT);
        }
        

}

void write_contents_eeprom_byAddress(uint32_t *source_address , uint32_t *destination_address ,uint32_t size) // By block in the eeprom
{

}

/*void read_contents_from_eeprom()
{

}

void lock_blocks_eeprom()
{

}

void mass_erase_eeprom()
{

}*/

