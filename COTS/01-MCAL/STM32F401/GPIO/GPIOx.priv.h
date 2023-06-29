/*
 * GPIOx.priv.h
 *
 *  Created on: Jun 24, 2023
 *      Author: Shokry
 */

#ifndef GPIOX_PRIV_H_
#define GPIOX_PRIV_H_

/********************************GPIO ADDRESSES**************************************/
/***************************GPIOA**********************************/
#define GPIOA_BASE			((uint32)0x40020000)
#define GPIOA_MODER			*(vuint32_t*) (GPIOA_BASE+0x00)
#define GPIOA_OTYPER		*(vuint32_t*) (GPIOA_BASE+0x04)
#define GPIOA_OSPEEDR		*(vuint32_t*) (GPIOA_BASE+0x08)
#define GPIOA_PUPDR			*(vuint32_t*) (GPIOA_BASE+0x0c)
#define GPIOA_IDR			*(vuint32_t*) (GPIOA_BASE+0x10)
#define GPIOA_ODR			*(vuint32_t*) (GPIOA_BASE+0x14)
#define GPIOA_BSRR			*(vuint32_t*) (GPIOA_BASE+0x18)
#define GPIOA_AFRL			*(vuint32_t*) (GPIOA_BASE+0x20)
#define GPIOA_AFRH			*(vuint32_t*) (GPIOA_BASE+0x24)
/******************************************************************/
/***************************GPIOB**********************************/
#define GPIOB_BASE			((uint32)0x40020400)
#define GPIOB_MODER			*(vuint32_t*) (GPIOB_BASE+0x00)
#define GPIOB_OTYPER		*(vuint32_t*) (GPIOB_BASE+0x04)
#define GPIOB_OSPEEDR		*(vuint32_t*) (GPIOB_BASE+0x08)
#define GPIOB_PUPDR			*(vuint32_t*) (GPIOB_BASE+0x0c)
#define GPIOB_IDR			*(vuint32_t*) (GPIOB_BASE+0x10)
#define GPIOB_ODR			*(vuint32_t*) (GPIOB_BASE+0x14)
#define GPIOB_BSRR			*(vuint32_t*) (GPIOB_BASE+0x18)
#define GPIOB_AFRL			*(vuint32_t*) (GPIOB_BASE+0x20)
#define GPIOB_AFRH			*(vuint32_t*) (GPIOB_BASE+0x24)
/******************************************************************/
/***************************GPIOC**********************************/
#define GPIOC_BASE			((uint32)0x40020800)
#define GPIOC_MODER			*(vuint32_t*) (GPIOC_BASE+0x00)
#define GPIOC_OTYPER		*(vuint32_t*) (GPIOC_BASE+0x04)
#define GPIOC_OSPEEDR		*(vuint32_t*) (GPIOC_BASE+0x08)
#define GPIOC_PUPDR			*(vuint32_t*) (GPIOC_BASE+0x0c)
#define GPIOC_IDR			*(vuint32_t*) (GPIOC_BASE+0x10)
#define GPIOC_ODR			*(vuint32_t*) (GPIOC_BASE+0x14)
#define GPIOC_BSRR			*(vuint32_t*) (GPIOC_BASE+0x18)
#define GPIOC_AFRL			*(vuint32_t*) (GPIOC_BASE+0x20)
#define GPIOC_AFRH			*(vuint32_t*) (GPIOC_BASE+0x24)
/******************************************************************/
/***************************GPIOD**********************************/
#define GPIOD_BASE			((uint32)0x40021200)
#define GPIOD_MODER			*(vuint32_t*) (GPIOD_BASE+0x00)
#define GPIOD_OTYPER		*(vuint32_t*) (GPIOD_BASE+0x04)
#define GPIOD_OSPEEDR		*(vuint32_t*) (GPIOD_BASE+0x08)
#define GPIOD_PUPDR			*(vuint32_t*) (GPIOD_BASE+0x0c)
#define GPIOD_IDR			*(vuint32_t*) (GPIOD_BASE+0x10)
#define GPIOD_ODR			*(vuint32_t*) (GPIOD_BASE+0x14)
#define GPIOD_BSRR			*(vuint32_t*) (GPIOD_BASE+0x18)
#define GPIOD_AFRL			*(vuint32_t*) (GPIOD_BASE+0x20)
#define GPIOD_AFRH			*(vuint32_t*) (GPIOD_BASE+0x24)
/******************************************************************/
/*****************************************************************************************************/



#endif /* GPIOX_PRIV_H_ */
