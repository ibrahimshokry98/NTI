/*
 * SysTick.h
 *
 *  Created on: Jun 25, 2023
 *      Author: Shokry
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

void STK_Init();
void STK_BusyWait(uint32 Ticks);
void STK_SignalInterval(uint32 Ticks,void (*PF) (void));
void STK_PeriodInterval(uint32 Ticks,void (*PF) (void));
void STK_StopInterval(void);

#endif /* SYSTICK_H_ */
