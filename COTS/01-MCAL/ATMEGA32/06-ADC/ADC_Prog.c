

#include "STD_Types.h"
#include "BITMATH.h"

#include "ADC_Private.h"
#include "ADC_config.h"
#include "ADC_Interface.h"

void ADC_voidInit (uint8 PrescalerVal)
{
	// VREF = AVCC
	Set_Bit(ADMUX_REG,REFS0);
	Clear_Bit(ADMUX_REG,REFS1);
	
	//Prescaler
	ADCSRA_REG &= PrescalerMask ;
	ADCSRA_REG |= PrescalerVal ;
	
/*
	//Enable Auto trigger
	Set_Bit(ADCSRA_REG,ADATE);
	
	//select auto trigger
	SFIOR_REG &= SFIORMask ;
	SFIOR_REG |= 0b01011111;
*/
		
	// Enable ADC
	Set_Bit(ADCSRA_REG,ADEN);
		
}




uint16 ADC_u16ReadADCPOLL (uint8 channel)
{
	
	
	//channel selection
	ADMUX_REG &= ChannelMask;
	ADMUX_REG|=channel ;
	Set_Bit(ADCSRA_REG,ADSC);
	while (Read_Bit(ADCSRA_REG,ADIF)==0);
	Set_Bit(ADCSRA_REG,ADIF);
	ADCL_REG ;
	return ADCL_REG ;	
}

uint16 ADC_u16ReadADCINT (uint8 channel)
{
	uint16 ReadData ;
	
	//channel selection
	ADMUX_REG &= ChannelMask;
	ADMUX_REG|=channel ;
	Set_Bit(ADCSRA_REG,ADSC);
	while (Read_Bit(ADCSRA_REG,ADIF)==0);
	
	ReadData = ADCL_REG ;
	return ReadData ;
}

void ADC_StartConvertion (void)
{
	Set_Bit(ADCSRA_REG,ADSC);
}
void ADC_voidEnableINt (void)
{
	Set_Bit(ADCSRA_REG,ADIE);
}

void ADC_voidDisableINt (void)
{
	Clear_Bit(ADCSRA_REG,ADIE);
}


/********************ISR**********************/
void (*ADC_PF) (void);
void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	ADC_PF();
}

void ADC_voidSetCallBack(void(*PF)(void))
{
	ADC_PF = PF ;
}

sint16 ADC_s16ConvertADC (sint16 SensorY0,sint16 SensorY1, uint16 ADCX0, uint16 ADCX1,uint16 Read)
{
	return ( ( ((float32) SensorY1-SensorY0) / ((float32)ADCX1-ADCX0) ) * Read );
}