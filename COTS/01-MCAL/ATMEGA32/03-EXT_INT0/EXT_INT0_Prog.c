
#include "STD_Types.h"
#include "BITMATH.h"
#include "EXT_INT0_config.h"
#include "EXT_INT0_interface.h"
#include "EXT_INT0_Private.h"

void EXT_INT0_Enable(void)
{
	Set_Bit(GICR_REG,INT0);
}

void EXT_INT0_Disable(void)
{
	Clear_Bit(GICR_REG,INT0);
}

void EXT_INT0_SenseControl (uint8 INT_Trigger)
{
	switch (INT_Trigger)
	{
		case FallingEdge :
			Clear_Bit(MCUCR_REG,ISC00);
			Set_Bit(MCUCR_REG,ISC01);
			break;
		case RisingEdge :
			Set_Bit(MCUCR_REG,ISC00);
			Set_Bit(MCUCR_REG,ISC01);
			break;
		case Onchange :
			Set_Bit(MCUCR_REG,ISC00);
			Clear_Bit(MCUCR_REG,ISC01);
		case LowLevel :
			Clear_Bit(MCUCR_REG,ISC00);
			Clear_Bit(MCUCR_REG,ISC01);
	}
}

void EXT_INT0_ReturnFlag (uint8* PIF)
{
	*PIF = Read_Bit(GIFR_REG,INTF0);
}

void (*EXT0_PF)(void)= (void*)0;


/********************ISR**********************/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	EXT0_PF();
}
/***********CallBack*************/
void EXT_INT0_CallBack (void (*PF)(void))
{
	EXT0_PF = PF ;
}
