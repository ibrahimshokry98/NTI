/*
 * RCC_Priv.h
 *
 *  Created on: Jun 24, 2023
 *      Author: Shokry
 */

#ifndef RCC_PRIV_H_
#define RCC_PRIV_H_

/****************************Addresses*************************************/
#define RCC_Base			((uint32)0x40023800)
#define RCC_CR      		*(vuint32_t*) (RCC_Base+0x00)
#define RCC_PLLCFGR      	*(vuint32_t*) (RCC_Base+0x04)
#define RCC_CFGR      		*(vuint32_t*) (RCC_Base+0x08)
#define RCC_CIR      		*(vuint32_t*) (RCC_Base+0x0c)
#define RCC_AHB1ENR      	*(vuint32_t*) (RCC_Base+0x30)
#define RCC_AHB2ENR      	*(vuint32_t*) (RCC_Base+0x34)
#define RCC_APB1ENR     	*(vuint32_t*) (RCC_Base+0x40)
#define RCC_APB2ENR      	*(vuint32_t*) (RCC_Base+0x44)
/***************************************************************************/

#define HSI				1
#define HSE				2
#define PLL				3

#define  PLLMMask 		0xFFFFFFE0

#define  PLLNMask 		0xFFFFC01F

#define  PLLPMask 		0xFFFF3FFF

/*Main PLL (PLL) division factor for main system clock*/
#define Divby2			0
#define Divby4			1
#define Divby6			2
#define Divby8			3


#define AHBNODIV		0b0000
#define AHBDIV2			0b1000
#define AHBDIV4			0b1001
#define AHBDIV8			0b1010
#define AHBDIV16		0b1011
#define AHBDIV64		0b1100
#define AHBDIV128		0b1101
#define AHBDIV256		0b1110
#define AHBDIV512		0b1111

#define AHBPrescalerMask	0xFFFFFF0F


#define APBNODIV		0b000
#define APBDIV2			0b100
#define APBDIV4			0b101
#define APBDIV8			0b110
#define APBDIV16		0b111

#define APB1PrescalerMask	0xFFFFE3FF

#define APB2PrescalerMask	0xFFFF1FFF

#endif /* RCC_PRIV_H_ */
