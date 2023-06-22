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
	char character1[] ={0x0E,0x0E,0x04,0x0E,0x15,0x04,0x0A,0x11};
	char character2[]= {0x00,0x00,0x10,0x0A,0x1F,0x02,0x00,0x00};
	LCD_voidInit();
	ADC_voidInit(Prescaler128);
	LCD_voidWriteSpecialCharacter(character1,0);
	LCD_voidWriteSpecialCharacter(character2,1);
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
		LCD_voidWriteChar(0);	
	}
	else
	{
		LCD_voidWriteChar(1);
	}
}

