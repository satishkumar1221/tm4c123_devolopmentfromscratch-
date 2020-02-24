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
#define HW_Access_Register(x) (*(volatile uint32_t *)x)
uint8_t testvar;
eeprom_status eeprom_init_stat;
eeprom_access_structure eeprom_access[];

/*Prototypes */
static eeprom_status poll_check_eeprom_status();
 
static void initlize_eeprom_struct();

static void eeprom_masserase();

//#define HWREG(x) (*(volatile uint32_t *)x)
static void initlize_eeprom_struct()
{
    /*Malfunction bit */
  // eeprom_access[0].block_number = 0x01;
  // eeprom_access[0].ee_offset_value = 0x01;
   //eeprom_access[1].block_number = 0x01;
   //eeprom_access[1].ee_offset_value = 0x02;

}
 //*****************************************************************************
    //
   // This function implements a workaround for a bug in Blizzard rev A silicon.
    // It ensures that only the 1KB flash sector containing a given EEPROM address
    // is erased if an erase/copy operation is required as a result of a following
    // EEPROM write.
    //
    //*****************************************************************************
static void EEPROMSectorMaskSet(uint32_t ui32Address)
 {
    uint32_t ui32Mask;
    //
    // Determine which page contains the passed EEPROM address.  The 2KB EEPROM
     // is implemented in 16KB of flash with each 1KB sector of flash holding
     // values for 32 consecutive EEPROM words (or 128 bytes).
     //
    uint32_t i = 0;
    ui32Mask = ~(1 << (ui32Address >> 7));

    cpu_cyclesdelay(i,10);
    HW_Access_Register(0x400FD0FC) = 3;
    i=0;
    cpu_cyclesdelay(i,10);
    HW_Access_Register(0x400AE2C0) = ui32Mask;
    i=0;
    cpu_cyclesdelay(i,10);
    HW_Access_Register(0x400FD0FC) = 0;
    i=0;
    cpu_cyclesdelay(i,10);
 }


static void eeprom_masserase()
{
    EEPROM_EEDBGME_R = 0xE37B0001;//EEPROM_EEDBGME_KEY_M | EEPROM_EEDBGME_ME;
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
      for(i=0 ; i<5; i++)
        {
            Fault_Info[i] = i;
        }
      testvar = (sizeof(malfunctiontimes)/sizeof(uint8_t));


}



/*This function was written to push the data into interface register */
/*Write a logic for multi block data and add a check for data check */
void eeprom_write(const void *source , const void *destination , uint32_t size ,uint32_t *data )
{
   // int i =0 ;
    //EEPROM_EEBLOCK_R = access_handle->block_number;
    //char *src = (char*)source;
   // char *dst = (char*)destination;
   // while((EEPROM_EEDONE_R & EE_DONE_MASK));
   // EEPROM_EEBLOCK_R  =   EEPROMBlockFromAddr(access_handle ->address);
    //EEPROM_EEOFFSET_R =  OFFSET_FROM_ADDR(access_handle -> address);
    //size = size/4;
   // for(int i=0 ;i<size ; i++)
   // {
      //  EEPROMSectorMaskSet((uint32_t *)destination);

        /*write the word automatically in the auto incrementing register*/
      //  EEPROM_EERDWRINC_R = *(data);
        /*Wait for the few clock cycles */
        //cpu_cyclesdelay(0,10);



   // }


}


//void read_contents_to_eeprom(eeprom_struct *access_handle)
//{
    /* Accessing the EEPROM registers for reading*/
    //EEPROM_EEBLOCK_R = access_handle->access_struct.block_number;

    //if
//}


void write_contents_eeprom_byAddress(uint32_t *source_address , uint32_t *destination_address ,uint32_t size) // By block in the eeprom
{

}



