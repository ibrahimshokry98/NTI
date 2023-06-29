/*
 * NVIC.h
 *
 *  Created on: Jun 24, 2023
 *      Author: Shokry
 */

#ifndef NVIC_H_
#define NVIC_H_


/*
 * GRP_16_SUB_1
 * GRP_8_SUB_2
 * GRP_4_SUB_4
 * GRP_2_SUB_8
 * GRP_1_SUB_16
 */
#define NUM_OF_GROUPS 		GRP_16_SUB_1


void NVIC_Init(void);
void NVIC_SetInterruptPeri(uint8 INTId,uint8 Periority);
void NVIC_EnablePer(uint8 PerID);
void NVIC_DisablePer(uint8 PerID);
void NVIC_SetPendingFlag(uint8 PerID);
void NVIC_ClrPendingFlag(uint8 PerID);
uint8 NVIC_GetActiveFlag(uint8 PerID);
#endif /* NVIC_H_ */
