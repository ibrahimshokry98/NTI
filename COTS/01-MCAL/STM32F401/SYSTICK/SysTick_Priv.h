/*
 * SysTick_Priv.h
 *
 *  Created on: Jun 25, 2023
 *      Author: Shokry
 */

#ifndef SYSTICK_PRIV_H_
#define SYSTICK_PRIV_H_

typedef struct {
	uint32 CTRL;
	uint32 LOAD;
	uint32 VAL;
	uint32 CALIB;
}STK_t;

#define STK 		((volatile STK_t*)(0xE000E010))


/*  Interval Mode */
#define SingleInterval			0
#define PeriodInterval			1

#endif /* SYSTICK_PRIV_H_ */
