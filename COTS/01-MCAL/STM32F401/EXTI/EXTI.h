/*
 * EXTI.h
 *
 *  Created on: Jun 24, 2023
 *      Author: Shokry
 */

#ifndef EXTI_H_
#define EXTI_H_

void EXTI_Enable (uint8 EXTI_ID,uint8 EXTI_Sense);
void EXTI_Disable (uint8 EXTI_ID);
void EXTI_Fire(uint8 EXTI_ID);
void EXTI_SetCallBack (uint8 EXTI_ID,void (*PF) (void));

#define RisingEdge			1
#define FallingEdge			2
#define OnChange			3
#endif /* EXTI_H_ */
