#define F_CPU 16000000UL
#include "util/delay.h"
#include "STD_Types.h"
#include "BITMATH.h"

#include "DIO_int.h"
#include "ADC_Interface.h"

#include "Lcd_int.h"

#include "TemperatureAlarm_int.h"
#include "TemperatureAlarm_Private.h"

static void Alarm_Off(void);
static void Alarm_On(void);
void Alarm_Init (void)
{
		Set_Pin_Direction(GreenLedPin,GreenLedPin,OUTPUT);
		Set_Pin_Direction(RedLedPort,PIN7,OUTPUT);
		Set_Pin_Direction(BuzzerPort,BuzzerPin,OUTPUT);
		LCD_voidInit();
		ADC_voidInit(Prescaler128);
		uint8 txt[] = "Temperature is ";
		LCD_voidWriteString(txt);
		LCD_voidGoTOXY(1,0);
}


void Alarm_start(void)
{
	uint16 read;
	read = ADC_u16ReadADCPOLL(Channel1) * (5000.0/1024);
	sint16 temp= ADC_s16ConvertADC(-50,150,0,1500,read);
	
	LCD_voidWriteInteger (temp);
	LCD_voidWriteChar(' ');
	LCD_voidWriteChar(' ');
	LCD_voidGoTOXY(1,3);
	LCD_voidWriteChar('c');
	LCD_voidGoTOXY(1,0);
	if (temp<25)
	{
		Alarm_Off();
	}
	else
	{
		Alarm_On();
	}
}

static void Alarm_Off(void)
{
	Set_Pin_Val(PORTA,PIN4,HIGH);
	Set_Pin_Val(PORTB,PIN7,LOW);
	Set_Pin_Val(PORTC,PIN6,LOW);
}

static void Alarm_On(void)
{
	Set_Pin_Val(PORTA,PIN4,LOW);
	Set_Pin_Val(PORTB,PIN7,HIGH);
	Set_Pin_Val(PORTC,PIN6,HIGH);
}