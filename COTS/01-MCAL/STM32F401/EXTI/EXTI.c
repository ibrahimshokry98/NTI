/*
 * EXTI.c
 *
 *  Created on: Jun 24, 2023
 *      Author: Shokry
 */
#include "STD_Types.h"
#include "BITMATH.h"

#include "NVIC.h"

#include "EXTI.h"
#include "EXTI_Priv.h"

void EXTI_Enable (uint8 EXTI_ID,uint8 EXTI_Sense)
{
	if (EXTI_ID>=0 && EXTI_ID<=22)
	{
		switch (EXTI_Sense)
		{
		case RisingEdge:
			Set_Bit(EXTI_RTSR,EXTI_ID);
			Clear_Bit(EXTI_FTSR,EXTI_ID);
			Set_Bit(EXTI_IMR,EXTI_ID);
			break;
		case FallingEdge :
			Set_Bit(EXTI_FTSR,EXTI_ID);
			Clear_Bit(EXTI_RTSR,EXTI_ID);
			Set_Bit(EXTI_IMR,EXTI_ID);
			break;
		case OnChange :
			Set_Bit(EXTI_FTSR,EXTI_ID);
			Set_Bit(EXTI_RTSR,EXTI_ID);
			Set_Bit(EXTI_IMR,EXTI_ID);
			break;
		default: break;
		}
	}
	else
	{
		//Report An Error
	}
}


void EXTI_Fire(uint8 EXTI_ID)
{
	if (EXTI_ID>=0 && EXTI_ID<=22)
	{
		Set_Bit(EXTI_SWIER,EXTI_ID);
	}
	else
	{
		//Report An Error
	}
}

void EXTI_Disable (uint8 EXTI_ID)
{
	if (EXTI_ID>=0 && EXTI_ID<=22)
	{
		Clear_Bit(EXTI_IMR,EXTI_ID);
	}
	else
	{
		//Report An Error
	}

}




static void (*EXTIPF[23]) (void) = {0};

void EXTI_SetCallBack (uint8 EXTI_ID,void (*PF) (void))
{
	if (PF != NULL)
	{
		EXTIPF[EXTI_ID] = PF;
	}
	else
	{
		//Report An Error
	}

}

void EXTI0_IRQHandler (void)
{
	if (EXTIPF != NULL)
	{
		EXTIPF[0]();
		Set_Bit(EXTI_PR,13);
		NVIC_ClrPendingFlag(40);
	}
	else
	{
		//Report An Error

	}
}

void EXTI1_IRQHandler (void);
void EXTI2_IRQHandler (void);
void EXTI3_IRQHandler (void);
void EXTI4_IRQHandler (void);


