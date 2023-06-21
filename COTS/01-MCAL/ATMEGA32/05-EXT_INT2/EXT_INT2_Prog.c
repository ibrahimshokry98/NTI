

#include "STD_Types.h"
#include "BITMATH.h"
#include "EXT_INT2_config.h"
#include "EXT_INT2_interface.h"
#include "EXT_INT2_private.h"

void EXT_INT2_Enable(void)
{
	Set_Bit(GICR_REG,INT2);
}

void EXT_INT2_Disable(void)
{
	Clear_Bit(GICR_REG,INT2);
}

void EXT_INT2_SenseControl (uint8 INT_Trigger)
{
	switch (INT_Trigger)
	{
		case FallingEdge :
			Clear_Bit(MCUCSR_REG,ISC2);
			break;
		case RisingEdge :
			Set_Bit(MCUCSR_REG,ISC2);
			break;
	}
}

void EXT_INT2_ReturnFlag (uint8* PIF)
{
	*PIF = Read_Bit(GIFR_REG,INTF2);
}

void (*EXT2_PF)(void)= (void*)0;


/********************ISR**********************/
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	EXT2_PF();
}
/***********CallBack*************/
void EXT_INT2_CallBack (void (*PF)(void))
{
	EXT2_PF = PF ;
}
