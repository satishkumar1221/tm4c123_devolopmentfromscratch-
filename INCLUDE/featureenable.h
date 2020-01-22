/*
 * featureenable.h
 *
 *  Created on: Jan 5, 2020
 *      Author: satish
 */

#ifndef INCLUDE_FEATUREENABLE_H_
#define INCLUDE_FEATUREENABLE_H_

/*Macros to select the system clock. Have to added in another parts of the code */

#ifdef SYS_CLK 16384MHZ
#define SYSTEM_CLK_ENABLE 1
#elif  SYS_CLK_PLL
#define PLL_CLK_ENABLE 1
#endif

#if TM4C123GH6PM
#define MICRO_TI 1
#else
#define MICRO_TI 0


#endif /* INCLUDE_FEATUREENABLE_H_ */
