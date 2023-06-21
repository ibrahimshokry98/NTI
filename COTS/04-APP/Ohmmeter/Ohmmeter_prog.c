
#define F_CPU 16000000UL
#include "util/delay.h"
#include "STD_Types.h"
#include "BITMATH.h"

#include "DIO_int.h"
#include "ADC_Interface.h"

#include "Lcd_int.h"

#include "Ohmmeter_int.h"

void Ohmmeter_Init (void)
{
	LCD_voidInit();
	ADC_voidInit(Prescaler128);
	LCD_voidGoTOXY(0,6);
	uint8 txt[] = "Ohmmeter";
	LCD_voidWriteString(txt);
	LCD_voidGoTOXY(2,0);
	LCD_voidWriteChar('o');
	LCD_voidWriteChar('h');
	LCD_voidWriteChar('m');
}


void Ohmmeter_start(void)
{
	uint16 read;
	read = ADC_u16ReadADCPOLL(Channel1) * (5000.0/1024);
	read/=40;
	LCD_voidGoTOXY(1,0);
	LCD_voidWriteInteger (read);
	LCD_voidWriteChar(' ');
	LCD_voidWriteChar(' ');
	LCD_voidWriteChar(' ');
}