/*
 * EXTI_Priv.h
 *
 *  Created on: Jun 24, 2023
 *      Author: Shokry
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

#define EXTI_Base		((uint32)0x40013C00)

#define EXTI_IMR		*(vuint32_t*) (EXTI_Base+0x00)
#define EXTI_EMR		*(vuint32_t*) (EXTI_Base+0x04)
#define EXTI_RTSR		*(vuint32_t*) (EXTI_Base+0x08)
#define EXTI_FTSR		*(vuint32_t*) (EXTI_Base+0x0C)
#define EXTI_SWIER		*(vuint32_t*) (EXTI_Base+0x10)
#define EXTI_PR			*(vuint32_t*) (EXTI_Base+0x14)



#endif /* EXTI_PRIV_H_ */
