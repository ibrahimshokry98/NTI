/*
 * NVIC.c
 *
 *  Created on: Jun 24, 2023
 *      Author: Shokry
 */

#include "STD_Types.h"
#include "BITMATH.h"

#include "NVIC.h"
#include "NVIC_Priv.h"

void NVIC_Init(void)
{
	#ifndef SCB_AIRCR
		#define SCB_AIRCR		*(vuint32_t*)(0x0C + 0xE000ED00)
	#endif

	SCB_AIRCR = NUM_OF_GROUPS ;
}

void NVIC_SetInterruptPeri(uint8 INTId , uint8 Periority )
{
	*(NVIC_IPRx+INTId) = (Periority<<4);
}

void NVIC_EnablePer(uint8 PerID)
{
	/*Range Check*/
	if (PerID < 32)
	{
		NVIC_ISER0 = (1<<PerID) ;
	}
	else if (PerID < 64)
	{
		PerID -= 32 ;
		NVIC_ISER1 = (1<<PerID) ;
	}
	else if (PerID < 84)
	{
		PerID -= 64 ;
		NVIC_ISER2 = (1<<PerID) ;
	}
}

void NVIC_DisablePer(uint8 PerID)
{
	/*Range Check*/
	if (PerID < 32)
	{
		NVIC_ICER0 = (1<<PerID) ;
	}
	else if (PerID < 64)
	{
		PerID -= 32 ;
		NVIC_ICER1 = (1<<PerID) ;
	}
	else if (PerID < 84)
	{
		PerID -= 64 ;
		NVIC_ICER2 = (1<<PerID) ;
	}
}


void NVIC_SetPendingFlag(uint8 PerID)
{
	/*Range Check*/
	if (PerID < 32)
	{
		NVIC_ISPR0 = (1<<PerID) ;
	}
	else if (PerID < 64)
	{
		PerID -= 32 ;
		NVIC_ISPR1 = (1<<PerID) ;
	}
	else if (PerID < 84)
	{
		PerID -= 64 ;
		NVIC_ISPR2 = (1<<PerID) ;
	}
}

void NVIC_ClrPendingFlag(uint8 PerID)
{
	/*Range Check*/
	if (PerID < 32)
	{
		NVIC_ICPR0 = (1<<PerID) ;
	}
	else if (PerID < 64)
	{
		PerID -= 32 ;
		NVIC_ICPR1 = (1<<PerID) ;
	}
	else if (PerID < 84)
	{
		PerID -= 64 ;
		NVIC_ICPR2 = (1<<PerID) ;
	}
}


uint8 NVIC_GetActiveFlag(uint8 PerID)
{
	uint8 Local_u8Flag = 0xAA ;
	/*Range Check*/
	if (PerID < 32)
	{
		Local_u8Flag = Read_Bit(NVIC_IABR0 , PerID);
	}
	else if (PerID < 64)
	{
		PerID -= 32 ;
		Local_u8Flag = Read_Bit(NVIC_IABR1 , PerID);
	}
	else if (PerID < 84)
	{
		PerID -= 64 ;
		Local_u8Flag = Read_Bit(NVIC_IABR2 , PerID);
	}
	return Local_u8Flag;
}
