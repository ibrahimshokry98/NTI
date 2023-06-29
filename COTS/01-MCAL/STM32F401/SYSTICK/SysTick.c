/*
 * SysTick.c
 *
 *  Created on: Jun 25, 2023
 *      Author: Shokry
 */


#include "STD_Types.h"
#include "BITMATH.h"

#include "SysTick.h"
#include "SysTick_Priv.h"

#ifndef NULL
#define NULL (*void)0
#endif

static uint8 Mode;        /* Software Flag */

static void(*STK_PF) (void) = 0;  /*   Call Back FN    */

void STK_Init()
{
	/* SysTick Enable & Choose Clock AHP/8       Ftimer = 1MH / Tick time 1 uSec  */
	STK->CTRL =0x00000001 ;
}

void STK_BusyWait(uint32 Ticks)
{
	/* Disable Timer  */
	Clear_Bit(STK->CTRL,0);
	/* Load Ticks */
	STK->LOAD = Ticks ;
	/* Enable  Timer  */
	Set_Bit(STK->CTRL,0);
	/* Dummy Wait */
	while (Read_Bit(STK->CTRL,16)==0)
	{
		asm("NOP");
	}
	/*  Disable Timer  */
	Clear_Bit(STK->CTRL,0);
	STK->LOAD = 0 ;
	STK->VAL = 0 ;
}

void STK_SignalInterval(uint32 Ticks,void (*PF) (void))
{

	/* Disable Timer 			 */
	Clear_Bit(STK->CTRL,0);
	/* Load Ticks 				 */
	STK->LOAD = Ticks ;
	/* Set The Mode of interrupt */
	Mode = SingleInterval;
	/* Assign Call Back			 */
	STK_PF =PF ;
	/* Enable Timer Interrupt 	 */
	Set_Bit(STK->CTRL,1);
	/* Enable  Timer  			 */
	Set_Bit(STK->CTRL,0);
}

void STK_PeriodInterval(uint32 Ticks,void (*PF) (void))
{

	/* Disable Timer 			 */
	Clear_Bit(STK->CTRL,0);
	/* Load Ticks 				 */
	STK->LOAD = Ticks ;
	/* Set The Mode of interrupt */
	Mode = PeriodInterval;
	/* Assign Call Back			 */
	STK_PF =PF ;
	/* Enable Timer Interrupt 	 */
	Set_Bit(STK->CTRL,1);
	/* Enable  Timer  			 */
	Set_Bit(STK->CTRL,0);
}

void STK_StopInterval(void)
{
	Clear_Bit(STK->CTRL,0);
	STK->LOAD = 0 ;
	STK->VAL = 0 ;
}

void SysTick_Handler (void)
{

	/* Check Interrupt Mode 		*/
	if (Mode == SingleInterval)
	{
		/* Disable Interrupt 		*/
		Clear_Bit(STK->CTRL,0);
		/* Disable Timer			*/
		Clear_Bit(STK->CTRL,0);
		STK->LOAD = 0 ;
		STK->VAL = 0 ;
	}
	STK_PF();
	Read_Bit(STK->CTRL,16);
}
