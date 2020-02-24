
#include "sys_init.h"
#include "pwm_timer_lib.h"
#define i2c_busy 0x01
#define time_out_configuredvalue  0x320000
#include "diagnostic_manager.h"
/*Register access */
#define APIINT (*(volatile uint32_t*)0xE000ED0C)
uint32_t timercount;
//#define systemreset  0x04
void disable_interrupts()
{
    // Added tab before CPSID for compiling without errors.
    __asm(" CPSID I");
}

void enable_interrupts()
{
    // Added tab before CPSIE for compiling without errors
    __asm(" CPSIE I");
}



void i2c_exception_handler(uint32_t *MSR_Status)
{

    if(*MSR_Status & i2c_busy)
    {
          /*start the timer*/
          starttimer(time_out_configuredvalue,single_shot_mode);
          //wawit timer
          while(!timeout_reached())
          {
                 // wait for 300 milli seconds for the BUS to respond
              timercount++;
          }
          if(timeout_reached())
          {
              if((*MSR_Status & i2c_busy) == 0x00)
              {
                 
              }
              else
              {
                  /* code */
              *MSR_Status  =  0x04;
              timercount=0;
              stopttimer();
              testfaillogic(I2C_Fault);

              }
            
          }
    
}
}

void systemresetfunction()
{
    /*confirmed error so unlock the system reset register */
    APIINT = (NVIC_APINT_VECTKEY | NVIC_APINT_SYSRESETREQ);
}

void corereset()
{
     APIINT = (NVIC_APINT_VECTKEY | 0x01);
} 
