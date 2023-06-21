
#define F_CPU 16000000UL
#include "util/delay.h"
#include "STD_Types.h"
#include "BITMATH.h"

#include "DIO_int.h"
#include "ADC_Interface.h"

#include "Lcd_int.h"



void Voltmeter_Init (void)
{
	LCD_voidInit();
	ADC_voidInit(Prescaler128);
	LCD_voidGoTOXY(0,6);
	uint8 txt[] = "Voltmeter  ";
	LCD_voidWriteString(txt);
	LCD_voidGoTOXY(2,0);
	LCD_voidWriteChar('m');
	LCD_voidWriteChar('V');
}


void Voltmeter_start(void)
{
	uint16 read;
	read = ADC_u16ReadADCPOLL(Channel1) * (5000.0/1024)/;
	LCD_voidGoTOXY(1,0);
	LCD_voidWriteInteger (read);
	LCD_voidWriteChar(' ');
	LCD_voidWriteChar(' ');
	LCD_voidWriteChar(' ');
	

}