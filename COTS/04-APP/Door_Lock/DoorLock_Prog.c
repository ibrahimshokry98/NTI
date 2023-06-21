
/*****************************************************************************************************/
/* *************************LIBS******************************/						
#include "STD_Types.h"
#include "BITMATH.h"
/* *************************MCAL******************************/
#include "DIO_int.h"
/* *************************HAL*******************************/
#include "Lcd_int.h"
#include "KeyPad_int.h"
/* *************************APP*******************************/
#include "DoorLock_int.h"
/* *************************Others****************************/
uint16 CorrectPass=1234;
/*****************************************************************************************************/
void DoorLock_voidInit(void)
{
		KeyPad_voidInit();
		LCD_voidInit();
		Set_Pin_Direction(BuzzerPort,BuzzerPin,OUTPUT);
		Set_Pin_Direction(LedPort,LedPin,OUTPUT);
}
void DoorLock_voidFunc(void)
{
		uint8 Local_uint8EnterPass[] = "Enter Password:" ;
		uint8 Local_uint8Welcome[] = "Welcome" ;
		uint8 Local_uint8Wrong[] = "Wrong Pass" ;
		LCD_voidWriteString(Local_uint8EnterPass);
		LCD_voidGoTOXY(1,0);
		uint8 local_pass;
		uint16 CurrentPass=0;
		uint8 count=0;
		uint8 tries=0;
		while(tries<3 && CurrentPass!=CorrectPass)
		{
			for (count=0;count<4;count++)
			{
				do
				{
					local_pass = KeyPad_uint8PressedKey();
				}while(local_pass==0xFF);
				LCD_voidWriteChar('*');
				CurrentPass = CurrentPass*10 + local_pass;
			}
			tries++;
			LCD_voidSendCMD(0x01);
		}
		if (CurrentPass==CorrectPass)
		{
			LCD_voidGoTOXY(0,7);
			LCD_voidWriteString(Local_uint8Welcome);
			Set_Pin_Val(LedPort,LedPin,HIGH);
		}
		else if(tries==3)
		{
			LCD_voidGoTOXY(0,5);
			LCD_voidWriteString(Local_uint8Wrong);
			Set_Pin_Val(BuzzerPort,BuzzerPin,HIGH);
		}
		while(1);
}