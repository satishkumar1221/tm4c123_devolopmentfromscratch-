#include "api.h"
#include "tm4c123gh6pm.h"
#include "constdata_gpio.h"
#include "i2c.h"
#include "pwm_timer_lib.h"
#include "eeprom.h"


void corereset();
void systemresetfunction();
void sys_init();
void system_clkregister_initilize();
void systick_initlize();
void powerdown_sequence();
void intilize_rcc2_registers();
void initilize_rcc_registers();
void initilize_gpio();
void i2c_exception_handler(uint32_t *MSR_Status);
