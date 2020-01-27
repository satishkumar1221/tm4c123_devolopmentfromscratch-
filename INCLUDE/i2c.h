/*
 * i2c.h
 *
 *  Created on: Jan 25, 2020
 *      Author: satish
 */

#ifndef INCLUDE_I2C_H_
#define INCLUDE_I2C_H_

#include <stdint.h>
#include <tm4c123gh6pm.h>
#include "exception_handlers.h"

#define configure_gpio_pctlreg_portb 0x03 

#define I2C0_MCS_R_addr              ((volatile uint32_t *)0x40020004)
#define I2C1_MCS_R_addr             ((volatile uint32_t *)0x40021004)
#define I2C2_MCS_R_addr             ((volatile uint32_t *)0x40022004)
#define I2C3_MCS_R_addr             ((volatile uint32_t *)0x40023004)
typedef enum
{
    module0 = 0x01, /*corresponds to port A*/
    module1 = 0x02, /*corresponds to port b*/
    module2 = 0x04, /*corresponds to port D*/
    module3 = 0x08 /*corresponds to port E*/

}i2c_peripherals;


typedef enum
{
    i2c_bus0, /*corresponds to port B*/
    i2c_bus1, /*corresponds to port A*/
    i2c_bus2 , /*corresponds to port D*/
    i2c_bus3  /*corresponds to port E*/

}i2c_bus;
typedef enum 
{
    RCGC_GPIO_PORTA = 0X01,
    RCGC_GPIO_PORTB = 0X02, 
    RCGC_GPIO_PORTC = 0X04,
    RCGC_GPIO_PORTD = 0X08,
    RCGC_GPIO_PORTE = 0X10,
    RCGC_GPIO_PORTF = 0X20

}portselect; 
typedef enum 
{
      pin0 = 0X01,
      pin1 = 0X02, 
      pin2 = 0X04,
      pin3 = 0X08,
      pin4 = 0X10,
      pin5 = 0X20,
      pin6 = 0X40,
      pin7 = 0X80

}configure_gpio_pins;

typedef enum
{
    master = 0,
    slave

}master_slave;

typedef enum 
{
    onehundredkb_sec = 100,
    
}set_clk_rate; 

typedef struct 
{
    uint32_t slave_address;
    /*this can also be as tructure or a pointer based on requirement.For now it is a 8Byte infirmation */ 
    uint8_t data; 

}slave_addr_data;
typedef struct 
{
    i2c_peripherals modules_to_be_enabled;
   // portselect ports_i2c_present; 
    //configure_gpio_pins  pins_select; 
     master_slave master_slave_config; // or the bits according to the ports for master (0<<modules_to_be_enabled) for slave (1<<modules_to_be_enabled)
    slave_addr_data slave_addr_data_tobesent;
    /*generic api pending . pass the handle after config by the customer*/

}i2c_configuration; 

typedef struct
{
    i2c_bus bus;
    i2c_peripherals i2c_moduleselect;
    portselect i2c_portselect;
    uint32_t scl_pin;
    uint32_t sda_pin;
    uint8_t master; 
    uint8_t slave; 


}i2c_port_pin_config_table;

extern i2c_configuration i2c_config ;
/*function protoypes to inililize i2c*/
void initilize_i2c();
void initilize_i2c_structure();
/*Make a generic function 
 initilizei2cmodule(modulenumber , masterslave ,slave address , slavedata)*/
 void initilizei2cmodulemasterconfig(i2c_bus modulenumber , uint8_t master , uint8_t slave , uint32_t slave_address , uint8_t slavedata , set_clk_rate baud);
 void initilizei2cmoduleslaveconfig(i2c_bus modulenumber , uint8_t master , uint8_t slave , set_clk_rate baud);
#endif /* INCLUDE_I2C_H_ */
