#define F_CPU 16000000UL
#include "util/delay.h"
#include "STD_Types.h"
#include "BITMATH.h"

#include "DIO_int.h"
#include "ADC_Interface.h"

#include "Lcd_int.h"

#include "LightSense_Int.h"
#include "LightSense_Private.h"

void System_Init (void)
{
	LCD_voidInit();
	ADC_voidInit(Prescaler128);
	uint8 txt[] = "Status ";
	LCD_voidWriteString(txt);
	LCD_voidGoTOXY(1,0);
}


void System_start(void)
{
	uint16 read;
	read = ADC_u16ReadADCPOLL(Channel0) * (1000.0/1024);
	read = read * LightnessConvertor ;
	LCD_voidGoTOXY(1,0);
	if (read<60)
	{
		LCD_voidWriteChar('W');	
	}
	else
	{
		LCD_voidWriteChar('S');
	}
}

