/*
 * main.c
 *
 * Created: 6/18/2023 10:45:33 AM
 *  Author: Shokry
 */ 


#undef F_CPU
#define  F_CPU 16000000UL
#include <util/delay.h>
#include "STD_Types.h"
#include "BITMATH.h"

#include "DIO_int.h"
#include "GP_INT_interface.h"

#include "TIMER0_interface.h"

#include "ADC_Interface.h"
#include "Lcd_int.h"




int main(void)
{
	uint16 readed;
	Set_Pin_Direction(PORTB,PIN3,OUTPUT);
	Set_Pin_Direction(PORTA,PIN4,OUTPUT);
	Timer0_vidInit();
	ADC_voidInit(Prescaler128);
	
	TIMER0_voidDutyCycle(50);
	LCD_voidInit();
	Timer0_vidStart();
	
    while(1)
    {
		readed = ADC_u16ReadADCPOLL(Channel0);
		readed = readed * ((float32)100/1024);
		TIMER0_voidDutyCycle(readed);
		LCD_voidWriteInteger(readed);	
		LCD_voidGoTOXY(0,0);
    }
}

