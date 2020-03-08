#include<stdio.h> 
#include "api.h"
#include "spi.h"
#include "tm4c123gh6pm.h"
/*Giveds an idean on when the transmission ofdata has to done and when the data transmission have to be stopped*/
/*temp test*/
uint32_t regvalue;
uint8_t test_mode_enabled = 1;
const uint8_t spi_modes [4][2] = {{0,0},
                                  {1,0},
                                  {0,1},
                                  {1,1}};

/*State machine to select the SPI*/
/*transfer rate in MHz*/
static uint32_t get_CRR_value(uint32_t transferrate)
{
    uint32_t temp; 
    temp = ((system_clock - (transferrate)* reg_read(SPI_CLK_PRESCALE_DIC_PORTA,0XFE)) /((transferrate) * reg_read(SPI_CLK_PRESCALE_DIC_PORTA,0XFE)));
    regvalue = temp;
    return(temp);

}

static void configure_dma()
{

}

void configure_spi_bus_master(SPI_BUS port_select , uint32_t spi_transferrate, frameformat frame_format,Boolean SPO , Boolean SPH)
{
    switch(port_select)
    {
        /*Use of the Generic API's instead of the one given in tm4c123*/
        case SPIO_PORTA : reg_write(RCGCSSI,0x01);
                          /*Enable the clock using the RCGCGPIO register*/
                          reg_write(RCGCGPIO,0x01);
                          /*Unlock GPIO port*/
                          GPIO_PORTA_LOCK_R = 0x4C4F434B;
                          /*configure the GPIO_AFSEL registers. refer pg 671*/
                          reg_write(GPIO_AFSEL_A,0x00);
                          reg_write(GPIO_PORTA_DEN,0x00);
                          reg_write(GPIO_PULLUP_PORTA,0x00);
                          reg_write(GPIO_PORTA_PCTL,0x00222200);
                          reg_write(GPIO_PORTA_CR,0X01);
                          /*SPI configuration starts here*/  
                          /*Disable the SSE register*/
                          reg_write(SSICR1_PORTA ,(0<<1));
                          /*Select the SPi as master*/
                          reg_write(SSICR1_PORTA,SSI_CR1_MS);
                          /*Configure the SSI Clock by writing to SSi cc register*/
                          reg_write(SPI_CLK_CNTRL,0x00);
                          /*SSIIN_CLK = (SYSTEM CLOCK)/(CPSDVSR *(1+SCR))*/ /*CPSDVSR is whatis there in clk prescale register*/
                          reg_write(SPI_CLK_PRESCALE_DIC_PORTA, 2);//must only be evennumber
                          /*configure the main control registers*/
                          /*serial clock rate =     clock phase polarity= spi_modes[0][0];spi_modes[0][1]  protocaol mode = 0x00      datasize = x0F           */
                          /*currently configuring the spi frequency to be 1 Mhz*/
                          reg_write(SSI_CRO_PORTA,(get_CRR_value(spi_transferrate)<<8));
                          /*sete the data to be xferred to 16 bit*/
                          reg_write(SSI_CRO_PORTA ,0x0F);
                          reg_write(SSI_CRO_PORTA ,(frame_format<<4)) ;//no neeed to set as we are using freescale format
                          if(frame_format == Freescale)
                          {
                              reg_write(SSI_CRO_PORTA ,(SPO<<6));
                              reg_write(SSI_CRO_PORTA ,(SPH<<7));
                          }
                          configure_dma();
                          reg_write(SSICR1_PORTB ,(1<<1));
                          //clock polarity and phase is asls 0
                          break;

        case SPI1_PORTF : reg_write(RCGCSSI,(0x01<<1));
                          reg_write(RCGCGPIO,(0x01<<5));
                          break;

        case SPI2_PORTB : reg_write(RCGCSSI,(0x01<<2));
                          reg_write(RCGCGPIO,(0x01<<1));
                          reg_write(RCGCSSI,0x01);
                          /*Enable the clock using the RCGCGPIO register*/
                          reg_write(RCGCGPIO,0x01);
                          /*Unlock GPIO port*/
                          GPIO_PORTB_LOCK_R = 0x4C4F434B;
                          /*configure the GPIO_AFSEL registers. refer pg 671*/
                          reg_write(GPIO_AFSEL_B,0xF0);
                          reg_write(GPIO_PORTB_DEN,0xF0);
                          //reg_write(GPIO_PULLUP_PORTB,0x00);
                          reg_write(GPIO_PORTB_PCTL,0x22220000);
                          //reg_write(GPIO_PORTA_CR,0X01);
                          /*SPI configuration starts here*/  
                          /*Disable the SSE register*/
                          reg_write(SSICR1_PORTB ,(0<<1));
                          /*Select the SPi as master*/
                          reg_write(SSICR1_PORTB,0X00);
                          /*Configure the SSI Clock by writing to SSi cc register*/
                          reg_write(SPI_CLK_CNTRL,0x00);
                          /*SSIIN_CLK = (SYSTEM CLOCK)/(CPSDVSR *(1+SCR))*/ /*CPSDVSR is whatis there in clk prescale register*/
                          reg_write(SPI_CLK_PRESCALE_DIC_PORTB, 2);//must only be evennumber
                          /*configure the main control registers*/
                          /*serial clock rate =     clock phase polarity= spi_modes[0][0];spi_modes[0][1]  protocaol mode = 0x00      datasize = x0F           */
                          /*currently configuring the spi frequency to be 1 Mhz*/
                          reg_write(SSI_CRO_PORTB,(get_CRR_value(spi_transferrate)<<8));
                          /*sete the data to be xferred to 16 bit*/
                          reg_write(SSI_CRO_PORTB ,0x0F);
                          reg_write(SSI_CRO_PORTB ,(frame_format<<4)) ;//no neeed to set as we are using freescale format
                          if(frame_format == Freescale)
                          {
                              reg_write(SSI_CRO_PORTB ,(SPO<<6));
                              reg_write(SSI_CRO_PORTB ,(SPH<<7));
                          }
                          configure_dma();
                          /*Make the chip select high in gpiodr register */
                          /*temp config loopback */
                          if(test_mode_enabled)
                          {
                          reg_write(SSICR1_PORTB ,1);
                          }
                          reg_write(SSICR1_PORTB ,((1<<1) |(1<<4)));
                          break;
        
        case SPI3_PORTD :reg_write(RCGCSSI,(0x01<<3));
                         reg_write(RCGCGPIO,(0x01<<3));
                        break;
    }
}

/*We will have a common datastructure that can be used to xmit the data over the SPI. Application has to have a mapping to this data structure*/
/**We are going to have a common structuire for this */

/*Master to slave*/
/*slave to master */
void spi_put_data_txbuffer(SPI_BUS port_select, uint16_t data )
{
    switch(port_select)
    {
       case SPIO_PORTA : SPI_Pack_data_txbuffer();
                          break;

       case SPI1_PORTF : SPI_Pack_data_txbuffer();
                         break;   

       case SPI2_PORTB : SPI_Pack_data_txbuffer(SPI_Data_Register_PortB, data);      
                         break;

       case SPI3_PORTD : SPI_Pack_data_txbuffer();
                         break; 
    }   
}

void SPI_Pack_data_txbuffer(SPI_BUS *port_select, uint16_t data)
{
   *(volatile uint32_t *)port_select = data; 

}
/*Done by togling the chip selct line from high to low */
void start_spi_transfer()
{
    /*Toggle the chip select bit to 0. 1 to 0 transition */

}
/*Done by toggling the chip slect line from low to high*/
void stop_spi_transfer()
{
    /*togglr the bit for 0 to 1 . 0 to 1 transition*/

}