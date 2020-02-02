/*
 * i2c.c
 *
 *  Created on: Jan 25, 2020
 *      Author: satish
 */
#include "i2c.h"
#include "diagnostic_manager.h"
//#define bitset_find (pim) (pim &0xFF) 
const i2c_port_pin_config_table tbl[] =
{
     //module   port          AFSEL      scl      sda  master   slave 
    {i2c_bus0,module0, RCGC_GPIO_PORTB, (1<<2) ,(1<<3) ,1      ,0 },
    {i2c_bus1,module1, RCGC_GPIO_PORTA, (1<<6) ,(1<<7) ,1      ,0}, 
    {i2c_bus2,module2, RCGC_GPIO_PORTD, (1) ,   (1<<1) ,1      ,0 },
    {i2c_bus3,module3, RCGC_GPIO_PORTE, (1<<4) ,(1<<5) ,1       ,0},
    /*slave config*/
    {i2c_bus0,module0, RCGC_GPIO_PORTA, (1<<6) ,(1<<7) ,1      ,0},
    {i2c_bus1,module1, RCGC_GPIO_PORTB, (1<<2) ,(1<<3) ,1      ,0}, 
    {i2c_bus2,module2, RCGC_GPIO_PORTD, (1) ,   (1<<1) ,1      ,0 },
    {i2c_bus3,module3, RCGC_GPIO_PORTE, (1<<4) ,(1<<5) ,1       ,0},
};

i2c_configuration i2c_config ;
/*API to activate the i2c ports and do the system initilization*/
/*give the mask value to activate the appropriate i2c module 
  ex : number 3 will activate i2c channel 0 and 1 */
//void initilize_i2c_structure()
//{
    /*configured according to the requirement */
    //i2c_config.modules_to_be_enabled = (module0 | module1);
   // i2c_config.ports_i2c_present = (RCGC_GPIO_PORTA | RCGC_GPIO_PORTB);
 //   i2c_config.master_slave_config = ((0<<module0) | (0<<module1));
    //i2c.pins_select = 
 //   i2c_config.slave_addr_data_tobesent.slave_address = 0x3B;
    /*temporary */
  //  i2c_config.slave_addr_data_tobesent.data = 0x20;
 //   initilize_i2c();

//}

inline uint8_t calculate_MTPR(set_clk_rate baud)
{
    /*only supporting 100kbpersecond baud*/
    /*TPR = (System Clock/(2*(SCL_LP + SCL_HP)*SCL_CLK))-1;
TPR = (16.384 MHz/(2*(6+4)*100000))-1;
TPR = 8*/
//Write the I2CMTPR
    return(0x08);
}

 void initilizei2cmodulemasterconfig(i2c_bus modulenumber , uint8_t master , uint8_t slave , uint32_t slave_address , uint8_t slavedata, set_clk_rate baud)
 {
             SYSCTL_RCGCI2C_R = (SYSCTL_RCGCI2C_R |tbl[modulenumber].i2c_moduleselect) ;
             switch(modulenumber)
            {  
             case i2c_bus0 : GPIO_PORTB_AFSEL_R = GPIO_PORTB_AFSEL_R |  (tbl[modulenumber].i2c_portselect);
                             GPIO_PORTB_ODR_R = (GPIO_PORTB_ODR_R | (tbl[modulenumber].sda_pin));
                             // I2C0_MTPR_R =  calculate_MTPR(baud);
                             I2C0_MCR_R =    (I2C0_MCR_R | (1<<4) | (1<<6)); // 4 bit is master
                             I2C0_MTPR_R = 0x09;
                             I2C0_MSA_R  = slave_address;
                             I2C0_MDR_R = 0X20;
                             I2C0_MCS_R  = 0x07;
                             enable_interrupts();
                             i2c_exception_handler(I2C0_MCS_R_addr);

                             break;
            case i2c_bus1 :  GPIO_PORTA_AFSEL_R = GPIO_PORTA_AFSEL_R |  (tbl[modulenumber].i2c_portselect);
                             GPIO_PORTA_ODR_R = (GPIO_PORTA_ODR_R | (tbl[modulenumber].sda_pin));
                             // I2C1_MTPR_R =  calculate_MTPR(baud);
                             I2C1_MCR_R =    (I2C1_MCR_R | (1<<4) | (1<<6)); // 4 bit is master
                             I2C1_MTPR_R = 0x09;
                             I2C1_MSA_R  = slave_address;
                             I2C1_MDR_R = 0X20;
                             I2C1_MCS_R  = 0x07;
                             enable_interrupts();
                             i2c_exception_handler(I2C1_MCS_R_addr);
                             break;
                            
            case i2c_bus2 :  GPIO_PORTD_AFSEL_R = GPIO_PORTA_AFSEL_R |  (tbl[modulenumber].i2c_portselect);
                             GPIO_PORTD_ODR_R = (GPIO_PORTA_ODR_R | (tbl[modulenumber].sda_pin));
                             I2C2_MTPR_R =  calculate_MTPR(baud);
                             I2C2_MCR_R =    (I2C0_MCR_R | (1<<4) | (1<<6)); // 4 bit is master
                             I2C2_MTPR_R = calculate_MTPR(baud);
                             I2C2_MSA_R  = slave_address;
                             I2C2_MDR_R = 0X20;
                             I2C2_MCS_R  = 0x07;
                             enable_interrupts();
                             i2c_exception_handler(I2C2_MCS_R_addr);
                             break;
            case i2c_bus3 : GPIO_PORTE_AFSEL_R = GPIO_PORTA_AFSEL_R |  (tbl[modulenumber].i2c_portselect);
                             GPIO_PORTE_ODR_R = (GPIO_PORTA_ODR_R | (tbl[modulenumber].sda_pin));
                             I2C3_MTPR_R =  calculate_MTPR(baud);
                             I2C3_MCR_R =    (I2C0_MCR_R | (1<<4) | (1<<6)); // 4 bit is master
                             I2C3_MTPR_R = calculate_MTPR(baud);
                             I2C3_MSA_R  = slave_address;
                             I2C3_MDR_R = 0X20;
                             I2C3_MCS_R  = 0x07;
                             enable_interrupts(I2C3_MCS_R_addr);
                             i2c_exception_handler();
                             break;
            default :


            }



             /*set the open drain config for sda */


 }
 void initilizei2cmoduleslaveconfig(i2c_bus modulenumber , uint8_t master , uint8_t slave, set_clk_rate baud )
 {

 }
void initilize_i2c()
{
    disable_interrupts();
    /* initilize i2c clock by setting RCGC i2C*/
    //SYSCTL_RCGCI2C_R = i2c_config.modules_to_be_enabled;
    /*clock is already enabled at the beginning of the system initization for all modules*/
    /*AFSEL also configured for the required pins in gpio initilization. Generic API pending to be written */
           //RCGC_GPIO_PORTA;
           //RCGC_GPIO_PORTB; 
    /*I2SDA open drain. Currenly initilized in sysinit. Will hav eo find a way to make it generic*/
           //oDC
           //odc

    /*From the manual important o configure PCTL port B.Have to write generic API */
     // GPIO_PORTB_PCTL_R = (GPIO_PCTL_PB3_I2C0SDA | GPIO_PCTL_PB2_I2C0SCL);
      /*Have to write a generic function for master or slave select*/
      /*For now we are configuring it directly*/
   //   I2C0_MCR_R = (1<<4); //master mode enabled for both
     // I2C1_MCR_R = (1<<4); //master mode enabled for both
    //  I2C0_MCR_R =  I2C0_MCR_R | (1<<6); //glitch filte enabled
  //    I2C1_MCR_R = I2C1_MCR_R | (1<<6); //glitch filte enabled
  //    I2C0_MTPR_R  = 0x09;
  ///    I2C1_MTPR_R = 0x09;
   //   I2C0_MSA_R = 0x076;
   //   I2C1_MSA_R = 0x077;
    //  I2C0_MCS_R = 0x0007;
    initilizei2cmodulemasterconfig(i2c_bus0,1,0,0x3B,0x20,onehundredkb_sec);
  //  initilizei2cmodulemasterconfig(i2c_bus1,1,0,0x076,0x20,onehundredkb_sec);



    /*Enable multi master in i2c for the 2 ports */

}

/*void timer()
{
    GPIO_PCTL_PB3_T3CCP1 =
}*/
