/*
 * NVIC_Priv.h
 *
 *  Created on: Jun 24, 2023
 *      Author: Shokry
 */

#ifndef NVIC_PRIV_H_
#define NVIC_PRIV_H_

/***********************************************************Addresses***************************************************************************/
#define NVIC_Base			((uint32)0xE000E000)
/********************************NVIC_ISERx***********************************/
#define NVIC_ISER0      	*(vuint32_t*)(NVIC_Base+0x100+0x00)
#define NVIC_ISER1      	*(vuint32_t*)(NVIC_Base+0x100+0x04)
#define NVIC_ISER2      	*(vuint32_t*)(NVIC_Base+0x100+0x08)
#define NVIC_ISER3      	*(vuint32_t*)(NVIC_Base+0x100+0x0C)
#define NVIC_ISER4      	*(vuint32_t*)(NVIC_Base+0x100+0x10)
#define NVIC_ISER5      	*(vuint32_t*)(NVIC_Base+0x100+0x14)
#define NVIC_ISER6      	*(vuint32_t*)(NVIC_Base+0x100+0x18)
#define NVIC_ISER7      	*(vuint32_t*)(NVIC_Base+0x100+0x1C)
/*****************************************************************************/
/********************************NVIC_ICERx***********************************/
#define NVIC_ICER0      	*(vuint32_t*)(NVIC_Base+0x180+0x00)
#define NVIC_ICER1      	*(vuint32_t*)(NVIC_Base+0x180+0x04)
#define NVIC_ICER2      	*(vuint32_t*)(NVIC_Base+0x180+0x08)
#define NVIC_ICER3      	*(vuint32_t*)(NVIC_Base+0x180+0x0C)
#define NVIC_ICER4      	*(vuint32_t*)(NVIC_Base+0x180+0x10)
#define NVIC_ICER5      	*(vuint32_t*)(NVIC_Base+0x180+0x14)
#define NVIC_ICER6      	*(vuint32_t*)(NVIC_Base+0x180+0x18)
#define NVIC_ICER7      	*(vuint32_t*)(NVIC_Base+0x180+0x1C)
/*****************************************************************************/
/********************************NVIC_ISPRx***********************************/
#define NVIC_ISPR0      	*(vuint32_t*)(NVIC_Base+0x200+0x00)
#define NVIC_ISPR1      	*(vuint32_t*)(NVIC_Base+0x200+0x04)
#define NVIC_ISPR2      	*(vuint32_t*)(NVIC_Base+0x200+0x08)
#define NVIC_ISPR3      	*(vuint32_t*)(NVIC_Base+0x200+0x0C)
#define NVIC_ISPR4      	*(vuint32_t*)(NVIC_Base+0x200+0x10)
#define NVIC_ISPR5      	*(vuint32_t*)(NVIC_Base+0x200+0x14)
#define NVIC_ISPR6      	*(vuint32_t*)(NVIC_Base+0x200+0x18)
#define NVIC_ISPR7      	*(vuint32_t*)(NVIC_Base+0x200+0x1C)
/*****************************************************************************/
/********************************NVIC_ICPRx***********************************/
#define NVIC_ICPR0      	*(vuint32_t*)(NVIC_Base+0x280+0x00)
#define NVIC_ICPR1      	*(vuint32_t*)(NVIC_Base+0x280+0x04)
#define NVIC_ICPR2      	*(vuint32_t*)(NVIC_Base+0x280+0x08)
#define NVIC_ICPR3      	*(vuint32_t*)(NVIC_Base+0x280+0x0C)
#define NVIC_ICPR4      	*(vuint32_t*)(NVIC_Base+0x280+0x10)
#define NVIC_ICPR5      	*(vuint32_t*)(NVIC_Base+0x280+0x14)
#define NVIC_ICPR6      	*(vuint32_t*)(NVIC_Base+0x280+0x18)
#define NVIC_ICPR7      	*(vuint32_t*)(NVIC_Base+0x280+0x1C)
/*****************************************************************************/
/********************************NVIC_IABRx***********************************/
#define NVIC_IABR0      	*(vuint32_t*)(NVIC_Base+0x300+0x00)
#define NVIC_IABR1      	*(vuint32_t*)(NVIC_Base+0x300+0x04)
#define NVIC_IABR2      	*(vuint32_t*)(NVIC_Base+0x300+0x08)
#define NVIC_IABR3      	*(vuint32_t*)(NVIC_Base+0x300+0x0C)
#define NVIC_IABR4      	*(vuint32_t*)(NVIC_Base+0x300+0x10)
#define NVIC_IABR5      	*(vuint32_t*)(NVIC_Base+0x300+0x14)
#define NVIC_IABR6      	*(vuint32_t*)(NVIC_Base+0x300+0x18)
#define NVIC_IABR7      	*(vuint32_t*)(NVIC_Base+0x300+0x1C)
/*****************************************************************************/
/********************************NVIC_IPRx***********************************/
#define NVIC_IPRx 	     	(vuint8_t*)(NVIC_Base+0x400+0x00)
/*****************************************************************************/
#define GRP_16_SUB_1		((uint32)0x5FA00000)
#define GRP_8_SUB_2			((uint32)0x5FA00400)
#define GRP_4_SUB_4			((uint32)0x5FA00500)
#define GRP_2_SUB_8			((uint32)0x5FA00600)
#define GRP_1_SUB_16		((uint32)0x5FA00700)

#endif /* NVIC_PRIV_H_ */
