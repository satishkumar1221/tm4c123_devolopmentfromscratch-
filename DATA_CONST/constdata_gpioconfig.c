/*
 * constdata_gpioconfig.c
 *
 *  Created on: Jan 13, 2020
 *      Author: satish
 */
#include "constdata_gpio.h"

/*This table has all the cases represented in pg 657 of the datasheet*/

/*create an enumeration map later on */
const gpio_config gpio_pin_spec[] =
 {
  /*config for digital input lookuptable with pull up config*/
  {0, 0 , 0 , 1 , 0 , 1 , 0 ,0 ,0 ,0 }, //0
  /*config for digital input lookuptable with pull down config*/
  {0, 0 , 0 , 1 , 0 , 0 , 1 ,0 ,0 ,0 }, //1
  /*config for digital input lookuptable with open drain output and 2mA */
  {0, 1 , 1 , 1 , 0 , 0 , 1 ,0 ,0 ,0 }, //2
  /*config for digital input lookuptable with open drain output and 4ma*/
  {0, 1 , 1 , 1 , 0 , 0 , 0 ,1 ,0 ,0 }, //3
  /*config for digital input lookuptable with open drain output and 8ma*/
   {0, 1 , 1 , 1 , 0 , 0 , 0 ,0 ,1 ,0 }, //4
  /*config pins  for i2c with pullup config  */
   {1, 0 , 0 , 1 , 1 , 0 , 0 , 0, 0,0 }, //5
    /*config pins  for i2c with pullup config slew rate enabled  */
   {1, 0 , 0 , 1 , 1 , 0 , 0 , 0, 0,1 }, //6
   /*config pins  for i2c with pulldown config  */
   {1, 0 , 0 , 1 , 0 , 1 , 0 , 0, 0,0 }, //7
   /*config pins  for i2c with pulldown config slew rate enabled  */
   {1, 0 , 0 , 1 , 0 , 1 , 0 , 0, 0,1 }, //8
   /*config pins for digital input timer with pullup config  */
   {1, 0 , 0 , 1 , 1 , 0 , 0 , 0, 0,0 }, //9
   /*config pins for digital input timer with pulldown config  */
   {1, 0 , 0 , 1 , 0 , 1 , 0 , 0, 0,0 }, //10
   /*config pins for Quardrature Encoder input with pulldown config */
   {1, 0 , 0 , 1 , 0 , 0 , 1 , 0, 0,0 }, //11 
   /*pwm pull up config */
   /*config pins for input with 2ma rate pwm config slew rate disabled  */
   {1, 0 , 0 , 1 , 1 , 0 , 1 , 0, 0,0 }, //12
      /*config pins for input with 2ma rate pwm config slew rate enabled  */
   {1, 0 , 0 , 1 , 1 , 0 , 1 , 0, 0,1 },  //13
    /*config pins for input with 4ma pwm config slew rate disabled  */
   {1, 0 , 0 , 1 , 1 , 0 , 0 , 1, 0,0 }, //14
    /*config pins for input with 4ma pwm config slew rate enabled  */
   {1, 0 , 0 , 1 , 1 , 0 , 0 , 1, 0,1 }, //15
     /*config pins for input with 8ma pwm config slew rate disabled  */
   {1, 0 , 0 , 1 , 1 , 1 , 0 , 0, 1,0 }, //16
    /*config pins for input with 8ma pwm config slew rate disabled  */
   {1, 0 , 0 , 1 , 1 , 1 , 0 , 0, 1,1 }, //17
   /*Pull down for pwm*/
   /*config pins for input with 2ma rate pwm config slew rate disabled  */
   {1, 0 , 0 , 1 , 0 , 1 , 1 , 0, 0,0 }, //18
      /*config pins for input with 2ma rate pwm config slew rate enabled  */
   {1, 0 , 0 , 1 , 0 , 1 , 1 , 0, 0,1 },  //19
    /*config pins for input with 4ma pwm config slew rate disabled  */
   {1, 0 , 0 , 1 , 0 , 1 , 0 , 1, 0,0 }, //20
    /*config pins for input with 4ma pwm config slew rate enabled  */
   {1, 0 , 0 , 1 , 0 , 1 , 0 , 1, 0,1 }, //21
    /*config pins for input with 8ma pwm config slew rate disabled  */
   {1, 0 , 0 , 1 , 0 , 1 , 0 , 0, 1,1 }, //22
   /*config pins for input with 8ma pwm config slew rate enabled  */
   {1, 0 , 0 , 1 , 0 , 1 , 0 , 0, 1,1 }, //23
   /*SSI or SPI  and UART configuration and diagital comparator pull up  */
   /*w ma and slewrate disabled */
   {1, 0 , 0 , 1 , 1 , 0 , 1 , 0, 0,0 }, //24
   /*2ma and slew rate enabled*/
   {1, 0 , 0 , 1 , 1 , 0 , 1 , 0, 0,1 }, //25
   /*4 ma and slewrate disabled */
   {1, 0 , 0 , 1 , 1 , 0 , 0 , 1, 0,0 }, //26
    /*4 ma and slewrate enabled */
   {1, 0 , 0 , 1 , 1 , 0 , 0 , 1, 0,0 }, //27
   /*8 ma and slewrate disabled */
   {1, 0 , 0 , 1 , 1 , 0 , 0 , 0, 1,0 }, //28
    /*8 ma and slewrate enabled */
   {1, 0 , 0 , 1 , 1 , 0 , 0 , 0, 1,1 }, //29
   /*SSI or SPI pull down config */
     /*w ma and slewrate disabled */
   {1, 0 , 0 , 1 , 0 , 1 , 1 , 0, 0,0 }, //30
   /*2ma and slew rate enabled*/
   {1, 0 , 0 , 1 , 0 , 1 , 1 , 0, 0,1 }, //31
   /*4 ma and slewrate disabled */
   {1, 0 , 0 , 1 , 0 , 1 , 0 , 1, 0,0 }, //32
    /*4 ma and slewrate enabled */
   {1, 0 , 0 , 1 , 0 , 1 , 0 , 1, 0,0 }, //33
   /*8 ma and slewrate disabled */
   {1, 0 , 0 , 1 , 0 , 1 , 0 , 0, 1,0 }, //34
    /*8 ma and slewrate enabled */
   {1, 0 , 0 , 1 , 0 , 1 , 0 , 0, 1,1 }, //35 
   /*Analog comaprator  */
   {0, 0 , 0 , 0 , 0 , 0 , 0 , 0, 0,0 }, //35
 };  


