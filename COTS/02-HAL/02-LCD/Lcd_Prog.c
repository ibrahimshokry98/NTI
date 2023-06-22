
/**************************************************************************************/
/*********************************LIB DIRECTIVES***************************************/
/**************************************************************************************/

#define F_CPU	16000000UL
#include <util/delay.h>
#include "STD_Types.h"
#include "BITMATH.h"
/**************************************************************************************/
/***************************DIO Component Directives***********************************/
/**************************************************************************************/
#include "DIO_int.h"

/**************************************************************************************/
/***************************LCD Component Directives***********************************/
/**************************************************************************************/
#include "LCD_int.h"
#include "Lcd_Priv.h"
#include "Lcd_Config.h"
/**************************************************************************************/
/***************************Function Implementation***********************************/
/**************************************************************************************/

static void LCD_SendPulse(void);

static void LCD_SendPulse(void)
{
	Set_Pin_Val(EN_Port,EN,HIGH);
	_delay_ms(30);
	Set_Pin_Val(EN_Port,EN,LOW);
	_delay_ms(30);
}

void LCD_voidWriteChar(uint8 Copy_uint8Data)
{
	//Set RS 1
	Set_Pin_Val(RS_Port,RS,HIGH);
	//Set RW 0
	//Set_Pin_Val(RW_Port,RW,LOW);
	//Command on Data Bus
	Data_t DATA;
	DATA.All_Byte =  Copy_uint8Data;

#if LCD_BIT_MODE == EIGHT_BIT

	Set_Pin_Val(Data_Pin7_Port,Data_Pin7,DATA.Bits.bit7);
	Set_Pin_Val(Data_Pin6_Port,Data_Pin6,DATA.Bits.bit6);
	Set_Pin_Val(Data_Pin5_Port,Data_Pin5,DATA.Bits.bit5);
	Set_Pin_Val(Data_Pin4_Port,Data_Pin4,DATA.Bits.bit4);
	Set_Pin_Val(Data_Pin3_Port,Data_Pin3,DATA.Bits.bit3);
	Set_Pin_Val(Data_Pin2_Port,Data_Pin2,DATA.Bits.bit2);
	Set_Pin_Val(Data_Pin1_Port,Data_Pin1,DATA.Bits.bit1);
	Set_Pin_Val(Data_Pin0_Port,Data_Pin0,DATA.Bits.bit0);
	LCD_SendPulse();

#elif LCD_BIT_MODE == FOUR_BIT

	Set_Pin_Val(Data_Pin7_Port,Data_Pin7,DATA.Bits.bit7);
	Set_Pin_Val(Data_Pin6_Port,Data_Pin6,DATA.Bits.bit6);
	Set_Pin_Val(Data_Pin5_Port,Data_Pin5,DATA.Bits.bit5);
	Set_Pin_Val(Data_Pin4_Port,Data_Pin4,DATA.Bits.bit4);
	LCD_SendPulse();
	Set_Pin_Val(Data_Pin7_Port,Data_Pin7,DATA.Bits.bit3);
	Set_Pin_Val(Data_Pin6_Port,Data_Pin6,DATA.Bits.bit2);
	Set_Pin_Val(Data_Pin5_Port,Data_Pin5,DATA.Bits.bit1);
	Set_Pin_Val(Data_Pin4_Port,Data_Pin4,DATA.Bits.bit0);
	LCD_SendPulse();
#endif
}


void LCD_voidSendCMD(uint8 Copy_uint8CMD)
{
	//Set RS 0
	Set_Pin_Val(RS_Port,RS,LOW);

	//Set RW 0
	//Set_Pin_Val(RW_Port,RW,LOW);

	//Command on Data Bus
	Data_t CMD;
	CMD.All_Byte =  Copy_uint8CMD;

#if LCD_BIT_MODE == EIGHT_BIT
	Set_Pin_Direction(Data_Pin7_Port,Data_Pin7,OUTPUT);
	Set_Pin_Direction(Data_Pin6_Port,Data_Pin6,OUTPUT);
	Set_Pin_Direction(Data_Pin5_Port,Data_Pin5,OUTPUT);
	Set_Pin_Direction(Data_Pin4_Port,Data_Pin4,OUTPUT);
	Set_Pin_Direction(Data_Pin3_Port,Data_Pin3,OUTPUT);
	Set_Pin_Direction(Data_Pin2_Port,Data_Pin2,OUTPUT);
	Set_Pin_Direction(Data_Pin1_Port,Data_Pin1,OUTPUT);
	Set_Pin_Direction(Data_Pin0_Port,Data_Pin0,OUTPUT);
	LCD_SendPulse();

#elif LCD_BIT_MODE == FOUR_BIT
	
	Set_Pin_Val(Data_Pin7_Port,Data_Pin7,CMD.Bits.bit7);
	Set_Pin_Val(Data_Pin6_Port,Data_Pin6,CMD.Bits.bit6);
	Set_Pin_Val(Data_Pin5_Port,Data_Pin5,CMD.Bits.bit5);
	Set_Pin_Val(Data_Pin4_Port,Data_Pin4,CMD.Bits.bit4);
	LCD_SendPulse();
	Set_Pin_Val(Data_Pin7_Port,Data_Pin7,CMD.Bits.bit3);
	Set_Pin_Val(Data_Pin6_Port,Data_Pin6,CMD.Bits.bit2);
	Set_Pin_Val(Data_Pin5_Port,Data_Pin5,CMD.Bits.bit1);
	Set_Pin_Val(Data_Pin4_Port,Data_Pin4,CMD.Bits.bit0);
	LCD_SendPulse();
#endif
}

void LCD_voidInit(void)
{
	/* wait for VDD Rises to 4.5 V for 30ms */
	_delay_ms(35);

	Set_Pin_Direction(RS_Port,RS,OUTPUT);
	//Set_Pin_Direction(RW_Port,RW,OUTPUT);
	Set_Pin_Direction(EN_Port,EN,OUTPUT);

#if LCD_BIT_MODE == FOUR_BIT
	Set_Pin_Direction(Data_Pin7_Port,Data_Pin7,OUTPUT);
	Set_Pin_Direction(Data_Pin6_Port,Data_Pin6,OUTPUT);
	Set_Pin_Direction(Data_Pin5_Port,Data_Pin5,OUTPUT);
	Set_Pin_Direction(Data_Pin4_Port,Data_Pin4,OUTPUT);
	LCD_voidSendCMD(0x02) ;
	_delay_ms(2);
	LCD_voidSendCMD(0x28) ;
	_delay_ms(1);

#elif LCD_BIT_MODE == EIGHT_BIT
	Set_Pin_Direction(Data_Pin7_Port,Data_Pin7,OUTPUT);
	Set_Pin_Direction(Data_Pin6_Port,Data_Pin6,OUTPUT);
	Set_Pin_Direction(Data_Pin5_Port,Data_Pin5,OUTPUT);
	Set_Pin_Direction(Data_Pin4_Port,Data_Pin4,OUTPUT);
	Set_Pin_Direction(Data_Pin3_Port,Data_Pin3,OUTPUT);
	Set_Pin_Direction(Data_Pin2_Port,Data_Pin2,OUTPUT);
	Set_Pin_Direction(Data_Pin1_Port,Data_Pin1,OUTPUT);
	Set_Pin_Direction(Data_Pin0_Port,Data_Pin0,OUTPUT);
	LCD_voidSendCMD(0x02) ;
	_delay_ms(2);
	LCD_voidSendCMD(0x38) ;
	_delay_ms(1);
#endif
	/* Display On/Off D=0  /Cursor off   */
	LCD_voidSendCMD(0x0C);
	/* wait for  39Micros */
	_delay_ms(1);
	/* Clear Display On/Off    */
	LCD_voidSendCMD(0x01);
	/* wait for  39Micros */
	_delay_ms(2);
	/* Entry mode  ID=1 write from write  S=0 Shifting off  (0b00000000)  */
	LCD_voidSendCMD(0x06);
	_delay_ms(1);
}

void LCD_voidWriteString(const char* Copy_puint8Data)
{
	while (*Copy_puint8Data)
	{
		LCD_voidWriteChar(*Copy_puint8Data);
		Copy_puint8Data++;
	}
}

void LCD_voidWriteInteger(sint32 Copy_sint32Data)
{
	sint32 Local_sint32Data = Copy_sint32Data ;
	uint8 local_arruint8Data[10];
	int i=0;
	if (Local_sint32Data<0)
	{
		LCD_voidWriteChar('-');
		Local_sint32Data *= (-1) ;
	}
	do
	{
		local_arruint8Data[i] = (Local_sint32Data%10)+'0';
		Local_sint32Data/=10;
		i++;
	}
	while (Local_sint32Data);
	i--;
	
	for (;i>=0;i--)
	{
		LCD_voidWriteChar(local_arruint8Data[i]);
	}
}

void LCD_voidWriteFloat(float64 Copy_f64FltNumber)
{
	uint32 Local_u32MaxDigits=10000;
	if(Copy_f64FltNumber<0)
	{
		LCD_voidWriteChar('-');
		Copy_f64FltNumber*=(-1);
	}
	uint32 Local_u32Intpart=(uint32)Copy_f64FltNumber;
	Copy_f64FltNumber=Copy_f64FltNumber-Local_u32Intpart;
	LCD_voidWriteInteger(Local_u32Intpart);
	Copy_f64FltNumber*=100000;
	Local_u32Intpart=(uint32)Copy_f64FltNumber;
	if(Local_u32Intpart!=0)
	{
		LCD_voidWriteChar('.');
		while(Local_u32Intpart<Local_u32MaxDigits)
		{
			Local_u32MaxDigits/=10;
			LCD_voidWriteInteger(0);
		}
		while((Local_u32Intpart%10)==0)
		{
			Local_u32Intpart/=10;;
		}
		LCD_voidWriteInteger(Local_u32Intpart);
	}
}

void LCD_voidGoTOXY(uint8 Copy_u8XPOS,uint8 Copy_u8YPOS)
{
	switch(Copy_u8XPOS)
	{
		case 0 : LCD_voidSendCMD(LCD_LINE1_BASE+Copy_u8YPOS); break;
		case 1 : LCD_voidSendCMD(LCD_LINE2_BASE+Copy_u8YPOS); break;
		case 2 : LCD_voidSendCMD(LCD_LINE3_BASE+Copy_u8YPOS); break;
		case 3 : LCD_voidSendCMD(LCD_LINE4_BASE+Copy_u8YPOS); break;
		default: break;
	}
}

void LCD_voidWriteSpecialCharacter(char* Copy_arru8Pattern,uint8 Copy_u8Block)
{
	LCD_voidSendCMD(Copy_u8Block*8+64);
	int count;
	for (count=0;count<8;count++);
	{
		LCD_voidWriteChar(Copy_arru8Pattern[count]);
	}
	LCD_voidSendCMD(128);
}

void LCD_voidDisplaySpecialCharacter(uint8 Copy_u8Block)
{
	LCD_voidWriteChar(Copy_u8Block);
}