
#include "sys_init.h"
#include "pwm_timer_lib.h"
#define i2c_busy 0x01
#define time_out_configuredvalue  0x320000
uint32_t timercount;
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
              *MSR_Status  =  0x04;
              timercount=0;
              stopttimer();
          }
    }
}
