#pragma once 

#include "api.h"
#include "tm4c123gh6pm.h"

#define RCGCSSI                     0x400FE61C
#define RCGCGPIO                    0x400FE608
#define GPIO_AFSEL_A                0x40004420
#define GPIO_PORTA_DEN              0x4000451C
#define GPIO_PORTA_PCTL             0x4000452C
#define  GPIO_PULLUP_PORTA          0x40004510
#define GPIO_PORTA_CR               0x40004524
#define SSICR1_PORTA                0x40008004
#define SPI_CLK_CNTRL               0x40008FC8
#define SPI_CLK_PRESCALE_DIC_PORTA 0x40008010
#define SSI_CRO_PORTA               0x40008000
/*port B */
#define GPIO_AFSEL_B        0x40005420
#define GPIO_PORTB_DEN      0x4000551C
#define GPIO_PORTB_PCTL     0x4000552C
#define  GPIO_PULLUP_PORTB  0x40005510
#define GPIO_PORTB_CR       0x40005524
#define SSICR1_PORTB        0x4000A004
#define SPI_CLK_CNTRL       0x4000AFC8
#define SPI_CLK_PRESCALE_DIC_PORTB 0x4000A010
#define SSI_CRO_PORTB               0x4000A000
#define SPI_Data_Register_PortB            0x4000A008
/*system clock in MHZ*/
#define system_clock 20
typedef enum 
{
   SPIO_PORTA, 
   SPI1_PORTF, 
   SPI2_PORTB,
   SPI3_PORTD
}SPI_BUS; 

typedef enum
{
    Freescale,
    TexasInstruments,
    Microwire

}frameformat;