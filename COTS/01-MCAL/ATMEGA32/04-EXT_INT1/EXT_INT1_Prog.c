

#include "STD_Types.h"
#include "BITMATH.h"
#include "EXT_INT1_config.h"
#include "EXT_INT1_interface.h"
#include "EXT_INT1_Private.h"

void EXT_INT1_Enable(void)
{
	Set_Bit(GICR_REG,INT1);
}

void EXT_INT1_Disable(void)
{
	Clear_Bit(GICR_REG,INT1);
}

void EXT_INT1_SenseControl (uint8 INT_Trigger)
{
	switch (INT_Trigger)
	{
		case FallingEdge :
			Clear_Bit(MCUCR_REG,ISC10);
			Set_Bit(MCUCR_REG,ISC11);
			break;
		case RisingEdge :
			Set_Bit(MCUCR_REG,ISC10);
			Set_Bit(MCUCR_REG,ISC11);
			break;
		case Onchange :
			Set_Bit(MCUCR_REG,ISC10);
			Clear_Bit(MCUCR_REG,ISC11);
		case LowLevel :
			Clear_Bit(MCUCR_REG,ISC10);
			Clear_Bit(MCUCR_REG,ISC11);
	}
}

void EXT_INT1_ReturnFlag (uint8* PIF)
{
	*PIF = Read_Bit(GIFR_REG,INTF1);
}

void (*EXT1_PF)(void)= (void*)0;


/********************ISR**********************/
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	EXT1_PF();
}
/***********CallBack*************/
void EXT_INT1_CallBack (void (*PF)(void))
{
	EXT1_PF = PF ;
}
