/*
 * RCC.h
 *
 *  Created on: Jun 23, 2023
 *      Author: Shokry
 */

#ifndef RCC_H_
#define RCC_H_


/***********************************APIS******************************************/
void RCC_voidSysClkInit(void);
void RCC_voidEnablePerClk (uint8 BusID , uint8 PerID);
void RCC_voidDisablePerClk (uint8 BusID , uint8 PerID);

/*********************************************************************************/

/*******************************************************************************************************************
 *                                            CONFIGRATIONS
 * *****************************************************************************************************************/

/**************************Clock Source*******************************/

/*Choose HSI OR HSE OR PLL */
#define Clock_Source	HSI
/*********************************************************************/
/**************************PLL Source*******************************/
/* Choose HSI OR HSE */
#define PLLSOURCE		HSI

/***********************************************PLL******************************************************/

/*Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock*/

/* Choose 2 to 63 */
#define PLLM			2

/******************************************/
/*Main PLL (PLL) multiplication factor for VCO*/


/* Choose 192 to 432 */
#define PLLN			192

/*******************************************/

/*Main PLL (PLL) division factor for main system clock*/

/* Choose
 * 	Divby2
 * 	Divby4
 * 	Divby6
 * 	Divby8
 */
#define PLLP			Divby2

/******************************************************************************************************/

/************************************AHB prescaler**************************************/


/* Choose from them
 * AHBNODIV
 * AHBDIV2
 * AHBDIV4
 * AHBDIV8
 * AHBDIV16
 * AHBDIV64
 * AHBDIV128
 * AHBDIV256
 * AHBDIV512
 */
#define AHBPrescaler		AHBNODIV
/*****************************************************************************************/

/**************************************(APB1-2)****************************************/

/***********************ABP1***************************/


/*Choose from them
 * APBNODIV
 * APBDIV2
 * APBDIV4
 * APBDIV8
 * APBDIV16
*/
#define APB1Prescaler		APBNODIV
/***********************ABP2***************************/

/*Choose from them
 * APBNODIV
 * APBDIV2
 * APBDIV4
 * APBDIV8
 * APBDIV16
*/
#define APB2Prescaler		APBNODIV
/***************************************************************************************/

/************************************BUSES****************************************/
#define AHP1		0
#define AHP2		1
#define APB1		2
#define APB2		3
/*********************************************************************************/
#endif /* RCC_H_ */
