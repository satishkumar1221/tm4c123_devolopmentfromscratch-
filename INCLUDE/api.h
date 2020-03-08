/*
 * api.h
 *
 *  Created on: Nov 29, 2019
 *      Author: satish
 */

#ifndef INCLUDE_API_H_
#define INCLUDE_API_H_

#include "stdint.h"
/*Macro defanitions*/

#define max_bitset 0xFFFFFFFF

typedef enum 
{
    FALSE, //0 
    TRUE  //1

}Boolean;

/*Average of the 2 unsigned numbers using bitwise operations */
#define Avg_two_numbers_overflowprot(a,b) ((a | b ) - ((a ^ b) >> 1))
#define reg_write(addr,value) ((*(volatile uint32_t *)addr) | value)
/*Use this API to read data drom a register with a given mask*/
inline uint32_t reg_read(volatile uint32_t *address , uint32_t mask)
{
    uint32_t temp; 
    temp = ((*(volatile uint32_t *)address) & mask);
    return(temp); 
}
/*Use this APi to set bits in a global variable*/
inline void  set_bits_byte(uint8_t *ptr_var_address,uint8_t mask) {(*(ptr_var_address)|mask);}
/*Use this APi to clear bits in a global variable*/
inline void clear_bits_byte(uint8_t *ptr_var_address,uint8_t mask){(*(ptr_var_address)& mask);}
/*Use this APi to clear bits in a global variable*/
inline void  set_bits_word(uint16_t *ptr_var_address,uint16_t mask) {(*(ptr_var_address)|mask);}
/*Use this APi to clear bits in a global variable*/
inline void clear_bits_word(uint16_t *ptr_var_address,uint16_t mask){(*(ptr_var_address)& mask);}
/*Use this APi to clear bits in a global variable*/
inline void  set_bits_integer(uint16_t *ptr_var_address,uint16_t mask) {(*(ptr_var_address)|mask);}
/*Use this APi to clear bits in a global variable*/
inline void clear_bits_integer(uint16_t *ptr_var_address,uint32_t mask){(*(ptr_var_address)& mask);}

#endif /* INCLUDE_API_H_ */

