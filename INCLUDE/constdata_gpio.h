/*
 * constdata_gpio.h
 *
 *  Created on: Jan 13, 2020
 *      Author: satish
 */

#ifndef INCLUDE_CONSTDATA_GPIO_H_
#define INCLUDE_CONSTDATA_GPIO_H_

#include <stdint.h>
typedef struct
{
    uint8_t afsel_setup;
    uint8_t gpio_dir;
    uint8_t gpio_odr;
    uint8_t digital_enable;
    uint8_t pull_up_activate;
    uint8_t pull_down_activate;
    uint8_t drive_2mA_out;
    uint8_t drive_4mA_out;
    uint8_t drive_8mA_out;
    uint8_t slewrate;
}gpio_config;

typedef struct 
{

}gpio_interrupt_config;

extern const gpio_config gpio_pin_spec[];
//extern const i2c_port_pin_config_table tbl[];

#endif /* INCLUDE_CONSTDATA_GPIO_H_ */
