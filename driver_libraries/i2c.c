/*
 * i2c.c
 *
 *  Created on: Jan 25, 2020
 *      Author: satish
 */
#include "i2c.h"

#include "diagnostic_manager.h"
//#define bitset_find (pim) (pim &0xFF) 
/*For now added the pin numbners directly but must be later added on to this cosnt table for refrence*/


const i2c_port_pin_config_table tbl[] =
{
     //module   port       AFSEL_SCL      scl      sda  master   slave
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



static void master_single_data_transmit_statemachine(uint32_t *MCS_Reg_Addr ,uint32_t *MCA_reg ,uint32_t *MDR, uint32_t slave_address , uint8_t slavedata);


inline uint8_t calculate_MTPR(set_clk_rate baud)
{
    /*only supporting 100kbpersecond baud*/
    /*TPR = (System Clock/(2*(SCL_LP + SCL_HP)*SCL_CLK))-1;
TPR = (16.384 MHz/(2*(6+4)*100000))-1;
TPR = 8*/
//Write the I2CMTPR
    return(0x09);
}

 void initilizei2cmodulemasterconfig(i2c_bus modulenumber , uint8_t master , uint8_t slave , set_clk_rate baud)
 {
             
             SYSCTL_RCGCI2C_R =  0x0F;//(SYSCTL_RCGCI2C_R |tbl[modulenumber].i2c_moduleselect) ;
             switch(modulenumber)
            {  
              SYSCTL_RCGCI2C_R = 0X0f;
             case i2c_bus0 : //SYSCTL_RCGCI2C_R = 0x01;
                             GPIO_PORTB_AFSEL_R = 0X00;
                             GPIO_PORTB_ODR_R = (GPIO_PORTB_ODR_R | (tbl[modulenumber].sda_pin));
                             GPIO_PORTB_LOCK_R  = GPIO_LOCK_KEY ;
                             GPIO_PORTB_CR_R = 0X00;
                             // I2C0_MTPR_R =  calculate_MTPR(baud);
                             I2C0_MCR_R =    (I2C0_MCR_R | (1<<4) | (1<<6)); // 4 bit is master
                             I2C0_MTPR_R = 0x08;
                             I2C0_MIMR_R = 0x01;
                             enable_interrupts();
                             break;

            case i2c_bus1 : //SYSCTL_RCGCI2C_R = (1 <<1); 
                           
                            GPIO_PORTA_AFSEL_R = ((1<<6) | (1<<7));
                            /*set the opendrain */
                            GPIO_PORTA_ODR_R = (GPIO_PORTA_ODR_R | (tbl[modulenumber].scl_pin));
                            GPIO_PORTA_ODR_R = (GPIO_PORTA_ODR_R |(tbl[modulenumber].sda_pin));
                            /*Set the Digital Enable Pin */
                            GPIO_PORTA_DEN_R = (GPIO_PORTA_DEN_R | ((1<<6) | (1<<7)));
                            /*Set the alternate functions for the PINS in the port config register */
                            GPIO_PORTA_PCTL_R = (/*(GPIO_PORTA_PCTL_R & 0x00)*/   0x33000000);
                            /*Set up the MCr register */
                            I2C1_MCR_R =    0x10; /*/| (1<<6)*///);
                            /*Set up the baud for the MTPR register*/
                            I2C1_MTPR_R = 0x09;
                            //I2C1_MSA_R  = 0x0076;
                          //  I2C1_MDR_R = 0x01;
                            //I2C2_MCS_R = 0x07;

                            break;                           
                            
                            
            case i2c_bus2 :  //SYSCTL_RCGCI2C_R = (1 <<2); 
                             GPIO_PORTD_AFSEL_R = ((1) | (1<<1));
                            /*set the opendrain */
                            GPIO_PORTD_ODR_R = (GPIO_PORTD_ODR_R | (tbl[modulenumber].scl_pin));
                            GPIO_PORTD_ODR_R = (GPIO_PORTD_ODR_R |(tbl[modulenumber].sda_pin));
                            /*Set the Digital Enable Pin */
                            GPIO_PORTD_DEN_R = (GPIO_PORTD_DEN_R | ((1) | (1<<1)));
                            /*Set the alternate functions for the PINS in the port config register */
                            GPIO_PORTD_PCTL_R = (/*(GPIO_PORTA_PCTL_R & 0x00)*/   0x00000033);
                            /*Set up the MCr register */
                            I2C2_MCR_R =    0x10; /*/| (1<<6)*///);
                            /*Set up the baud for the MTPR register*/
                            I2C2_MTPR_R = 0x09;
                            break;

            case i2c_bus3 : //SYSCTL_RCGCI2C_R = (1 <<3); 
                            /*set the opendrain */
                            GPIO_PORTE_ODR_R = (GPIO_PORTE_ODR_R | (tbl[modulenumber].scl_pin));
                            GPIO_PORTE_ODR_R = (GPIO_PORTE_ODR_R |(tbl[modulenumber].sda_pin));
                            /*Set the Digital Enable Pin */
                            GPIO_PORTE_DEN_R = (GPIO_PORTE_DEN_R | ((1<<4) | (1<<5)));
                            /*Set the alternate functions for the PINS in the port config register */
                            GPIO_PORTE_PCTL_R = (/*(GPIO_PORTA_PCTL_R & 0x00)*/   0x00330000);
                            /*Set up the MCr register */
                            I2C3_MCR_R =    0x10; /*/| (1<<6)*///);
                            /*Set up the baud for the MTPR register*/
                            I2C3_MTPR_R = 0x09;
                            break;
            default :


            }

 }

 void initilizei2cmoduleslaveconfig(i2c_bus modulenumber , uint8_t master , uint8_t slave, set_clk_rate baud )
 {

 }

/*private function implementation*/
static void master_single_data_transmit_statemachine(uint32_t *MCS_Reg_Addr ,uint32_t *MCA_reg ,uint32_t *MDR, uint32_t slave_address , uint8_t slavedata)
{
  //uint8_t temp;

  while(check_registervalue(0x01,i2c_busy_mask,*MCS_Reg_Addr))
  {

    /*poll and configure timeout*/
      //  i2c_exception_handler((uint32_t *)MCS_Reg_Addr);

  }


  if(check_registervalue(0x00,i2c_busy_mask,*MCS_Reg_Addr))
  {
      write_address_slave(slave_address,MCA_reg);
      write_data_slave(slavedata,MDR);
       *MCS_Reg_Addr = 0x07;
      

  }

 if(check_registervalue(0x00,i2c_busy_mask,*MCS_Reg_Addr))
 {
   /*check for error bit*/
    if(check_registervalue(0x00,0x02,*MCS_Reg_Addr))
    {

    }
    else
    {
      /* code */
      //error handler
    }
    
 }

}

void master_single_data_transmit(i2c_bus modulenumber , uint32_t slave_address , uint8_t slavedata)
{  //#if TM4C123
   // uint32_t temp;
    switch(modulenumber)
    {
      /*Add a build flag to separate the register implementation*/
      case i2c_bus0 :
                       master_single_data_transmit_statemachine((uint32_t*)0x40020004,(uint32_t*)0x40020000,(uint32_t*)0x40020008,slave_address,slavedata);
                      break;
      case i2c_bus1 :
                       master_single_data_transmit_statemachine((uint32_t*)0x40021004,(uint32_t*)0x40021000,(uint32_t*)0x40021008,slave_address,slavedata);
                           break;
    }
}

