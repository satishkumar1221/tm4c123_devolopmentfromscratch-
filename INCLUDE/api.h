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

//#define write_Registers(address,mask) { ((address  & max_bitset) | mask ); }

/*Use this APi only to access the system registers*/
//inline void write_Registers(uint32_t address, uint32_t mask) { (address |  mask ); }
/*Check the api once in for all*/
//inline void clear_registers_withmask(uint32_t address, uint32_t mask) {(address ^ mask); }
/*Flush all the registers*/
//inline void flush_registers(uint32_t address, uint32_t mask) {(address & 0x00);}
/**/
#endif /* INCLUDE_API_H_ */

