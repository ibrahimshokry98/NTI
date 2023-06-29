/*
 * RCC.c
 *
 *  Created on: Jun 23, 2023
 *      Author: Shokry
 */
#include "STD_Types.h"
#include "BITMATH.h"
#include "RCC.h"
#include "RCC_Priv.h"

void RCC_voidSysClkInit(void)
{
#if Clock_Source == HSI
	Set_Bit(RCC_CR,0);
	Clear_Bit(RCC_CFGR,0);
	Clear_Bit(RCC_CFGR,1);

#elif Clock_Source == HSE
	//Set_Bit(RCC_CR,18);
	Set_Bit(RCC_CR,16);
	Set_Bit(RCC_CFGR,0);
	Clear_Bit(RCC_CFGR,1);
#elif Clock_Source == PLL

	RCC_PLLCFGR &= PLLMMask;
	RCC_PLLCFGR |= PLLM;
	RCC_PLLCFGR &= PLLNMask;
	RCC_PLLCFGR |= (PLLM<<6);
	RCC_PLLCFGR &= PLLPMask ;
	RCC_PLLCFGR |= (PLLP<<16);
	#if PLLSOURCE == HSI
	/* Select HSI AS PLL Source */
	Clear_Bit(RCC_PLLCFGR,22);
	/* Enable HSI */
	Set_Bit(RCC_CR,0);
	#elif PLLSOURCE == HSE
	/* Select HSE AS PLL Source */
	Set_Bit(RCC_PLLCFGR,22);
	/* Enable HSE */
	Set_Bit(RCC_CR,16);
	#endif
	Set_Bit(RCC_CR,24);
	Clear_Bit(RCC_CFGR,0);
	Set_Bit(RCC_CFGR,1);
#endif

	RCC_CFGR &= AHBPrescalerMask ;
	RCC_CFGR |= (AHBPrescaler<<4);
	RCC_CFGR &= APB1PrescalerMask ;
	RCC_CFGR |= (APB1Prescaler<<10);
	RCC_CFGR &= APB2PrescalerMask ;
	RCC_CFGR |= (APB1Prescaler<<13);
}


void RCC_voidEnablePerClk (uint8 BusID , uint8 PerID)
{
	if (BusID<3 && PerID<32)
	{
		switch (BusID)
		{
		case AHP1 :
			RCC_AHB1ENR |= (1<<PerID) ;
			break;
		case AHP2 :
			RCC_AHB2ENR |= (1<<PerID) ;
			break;
		case APB1 :
			RCC_APB1ENR |= (1<<PerID) ;
			break;
		case APB2 :
			RCC_APB2ENR |= (1<<PerID) ;
			break;
		default : break;
		}
	}
	else {
		/*Report An error*/
	}
}


void RCC_voidDisablePerClk (uint8 BusID , uint8 PerID)
{
	if (BusID<3 && PerID<32)
	{
		switch (BusID)
		{
		case AHP1 :
			RCC_AHB1ENR &= ~(1<<PerID) ;
			break;
		case AHP2 :
			RCC_AHB2ENR &= ~(1<<PerID) ;
			break;
		case APB1 :
			RCC_APB1ENR &= ~(1<<PerID) ;
			break;
		case APB2 :
			RCC_APB2ENR &= ~(1<<PerID) ;
			break;
		default : break;
		}
	}
	else {
		/*Report An error*/
	}
}
