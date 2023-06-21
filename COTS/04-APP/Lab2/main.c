/*
 * main.c
 *
 * Created: 6/14/2023 4:45:38 PM
 *  Author: Shokry
 */ 

/* *************************LIBS******************************/
#define F_CPU	16000000UL
#include "STD_Types.h"
#include "BITMATH.h"
/* *************************MCAL******************************/
#include "DIO_int.h"
/* *************************HAL******************************/
#include "KeyPad_int.h"
#include "SSInterface.h"
/* *************************APP******************************/
/* *************************Others******************************/
#include <util/delay.h>

int main(void)
{
	SSData_t SS1 = {PORTB,{PIN0,PIN1,PIN2,PIN4},PORTA,PIN3,Cathode} ;
	SSData_t SS2 = {PORTB,{PIN0,PIN1,PIN2,PIN4},PORTA,PIN2,Cathode} ;
	SS_Init(&SS1);
	SS_Init(&SS2);
	KeyPad_voidInit();
	Set_Pin_Direction(PORTA,PIN4,OUTPUT);
	Set_Pin_Direction(PORTC,PIN6,OUTPUT);
	Set_Pin_Val(PORTA,PIN4,LOW);
	Set_Pin_Val(PORTC,PIN6,LOW);
	uint8 PressedKey = 0xFF;
	uint8 SS1count = 0;
	uint8 SS2count = 0;
    while(1)
    {
		SS_Display(&SS1,SS1count);
		SS_Disable(&SS2);
		_delay_ms(5);
		SS_Display(&SS2,SS2count);
		SS_Disable(&SS1);
		_delay_ms(5);
		do {
				PressedKey = KeyPad_uint8PressedKey();
				SS_Display(&SS1,SS1count);
				SS_Disable(&SS2);
				_delay_ms(5);
				SS_Display(&SS2,SS2count);
				SS_Disable(&SS1);
				_delay_ms(5);
		}while (PressedKey==0xFF);
		
		switch (PressedKey)
		{
			case 1 :
				Toggle_Pin(PORTA,PIN4);
				break;
			case 2 :
				Toggle_Pin(PORTC,PIN6);
				break;
			case 3 :
				SS1count++;
				if (SS1count==10)
				{
					SS1count = 0;
					SS2count++;
					if (SS2count==10)
					{
						SS2count = 0;
					}
				}
				break;
			case 4 :
				SS1count--;
				if (SS1count==255)
				{
					SS1count = 9;
					SS2count--;
					if (SS2count==255)
					{
						SS2count = 9;
					}
				}
				break;	
			default: break;
		}
    }
}