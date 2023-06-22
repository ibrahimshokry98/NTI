
#define F_CPU 16000000UL
#include "util/delay.h"
#include "STD_Types.h"
#include "BITMATH.h"

#include "DIO_int.h"
#include "EXT_INT0_interface.h"
#include "EXT_INT1_interface.h"
#include "GP_INT_interface.h"

#include "Lcd_int.h"
#include "KeyPad_int.h"

void func1 (void);
void func2 (void);
vuint8_t LCDFlag;
vuint8_t SystemFlag=1;
int main()
{
	EXT_INT0_CallBack(func1);
	EXT_INT1_CallBack(func2);
	EXT_INT0_SenseControl(RisingEdge);
	EXT_INT1_SenseControl(RisingEdge);
	EXT_INT0_Enable();
	EXT_INT1_Enable();
	GP_INT_Enable();
	Set_Pin_Direction(PORTC,PIN6,OUTPUT);
	Set_Pin_Direction(PORTB,PIN7,OUTPUT);
	Set_Pin_Val(PORTB,PIN7,LOW);
	LCD_voidInit();
	KeyPad_voidInit();
	uint8 counter=0;
	uint8 digit=0xFF;

	while(1)
	{
		while (LCDFlag == 0);
		LCD_voidWriteString("Set Your Alarm");
		LCD_voidGoTOXY(1,0);
		while (digit != 'k')
		{
			do
			{
				digit = KeyPad_uint8PressedKey();
			}while(digit==0xFF);
			if ( (digit>=0) && (digit<=9) )
			{
				LCD_voidWriteInteger(digit);
				counter = counter*10 + digit;
			}
		}
		LCD_voidSendCMD(0x01);
		LCD_voidGoTOXY(1,9);
		while ( (counter != 0) )
		{
			LCD_voidGoTOXY(1,9);
			LCD_voidWriteInteger(counter);
			_delay_ms(1000);
			if (SystemFlag == 0)
			{
				LCD_voidSendCMD(0x01);
				counter--;
			}
		}
		LCD_voidGoTOXY(1,8);
		LCD_voidWriteString("Wakeup");
		while (counter ==0)
		{
			Set_Pin_Val(PORTC,PIN6,HIGH);
		}
	}
}

void func1 (void)
{
	LCDFlag = 1 ;
	Toggle_Pin(PORTB,PIN7);
}
void func2 (void)
{
	Toggle_Bit(SystemFlag,0);
}