#define F_CPU 16000000UL
#include "util/delay.h"
#include "STD_Types.h"
#include "BITMATH.h"
#include "Lcd_int.h"
#include "KeyPad_int.h"
#include "Calculater_Interface.h"
void CALC_voidInit(void)
{
	LCD_voidInit();
	KeyPad_voidInit();
}

void CALC_voidWelcome(void)
{
		LCD_voidGoTOXY(0,8);
		LCD_voidWriteString("HELLO");
		LCD_voidGoTOXY(1,1);
		LCD_voidWriteString("Simple Calculator");
		LCD_voidGoTOXY(2,6);
		LCD_voidWriteString("Project");
		_delay_ms(5000);
		LCD_voidClearDisplay();
		LCD_voidGoTOXY(0,0);
}
/*Calc_uint32Power Calculate 10 power of Exponent*/
uint32 Calc_uint32Power(uint8 Exponent)
{
	uint32 Result=1;
	uint8 i;
	for(i=0;i<Exponent;i++)
	{
		Result*=10;
	}
	return Result;
}
uint8 CALC_uint8ReadFromUser(float32* Ptr_Operand, uint8* DigitCounter)
{
	uint8 Digits=0;
	*DigitCounter=0;
	while(Digits>=0&&Digits<=9)
	{
		do{
			Digits=KeyPad_uint8PressedKey();
		}while(Digits==0xFF);
		if(Digits>=0&&Digits<=9)
		{
			*Ptr_Operand=(*Ptr_Operand*10)+Digits;
			LCD_voidWriteInteger(Digits);
			*DigitCounter=(*DigitCounter)+1;
		}
	}
	return Digits;
}
void CALC_voidCalculate(void)
{
	/*Integer part and Floating point part*/
	float32 Operand=0;
	float32 FloatPart=0;
	/*result*/
	static float32 FResult=0;
	uint8 LastOprator;
	uint8 Digits;
	/*FLags*/
	uint8 DividebyZeroFlag=0;			//Raise when user Divide by zero
	uint8 FirstOperationFlag=0;         //Raise After first operation entered
	uint8 MultiSignFlag=0;				//Raise when user Enter two signs without Operand between them
	/*counter*/
	uint8 floatcount=0;
	LCD_voidClearDisplay();
	LCD_voidGoTOXY(0,0);
	LCD_voidWriteInteger(0);
	LCD_voidGoTOXY(0,0);
	while(1)
	{
		Digits=CALC_uint8ReadFromUser(&Operand, &floatcount);
		if(Digits=='=')
		{
			if(FirstOperationFlag==0)
			{
				FResult=Operand;
				Operand=0;
				LCD_voidClearDisplay();
				LCD_voidGoTOXY(1,0);
				LCD_voidWriteFloat(FResult);
				LCD_voidGoTOXY(0,0);
				LCD_voidWriteString("Answer");
			}
			else
			{
				switch (LastOprator)
				{
				case '+':
					FResult=FResult+Operand;
					Operand=0;
					LastOprator=Digits;
					break;
				case '-':
					FResult=FResult-Operand;
					Operand=0;
					LastOprator=Digits;
					break;
				case '*':
					FResult=FResult*Operand;
					Operand=0;
					LastOprator=Digits;
					break;
				case '/':
					if(Operand==0)
					{
						LCD_voidClearDisplay();
						LCD_voidWriteString("Division by ZERO!");
						Operand=0;
						FloatPart=0;
						FResult=0;
						FirstOperationFlag=0;
						_delay_ms(2000);
						DividebyZeroFlag=1;

					}
					else
					{
						FResult=FResult/Operand;
						Operand=0;
						LastOprator=Digits;
					}
					break;
				}
				LCD_voidClearDisplay();
				if(DividebyZeroFlag==0)
				{
					LCD_voidGoTOXY(1,0);
					LCD_voidWriteFloat(FResult);
					LCD_voidGoTOXY(0,0);
					LCD_voidWriteString("Answer");
					FirstOperationFlag=0;
				}
				else
				{
					DividebyZeroFlag=0;
					LCD_voidGoTOXY(0,0);
					LCD_voidWriteInteger(FResult);
					LCD_voidGoTOXY(0,0);
				}
			}
			do{
				Digits=KeyPad_uint8PressedKey();
			}while(Digits==0xFF);
			if((Digits>=0&&Digits<=9))
			{

				FResult=0;
				Operand=Digits;
				FloatPart=0;
				LCD_voidClearDisplay();
				LCD_voidWriteInteger(Digits);
			}
			else if(Digits=='.')
			{
				FResult=0;
				Operand=0;
				FloatPart=0;
				LCD_voidClearDisplay();
				LCD_voidGoTOXY(0,0);
			}
			else
			{
				Operand=FResult;
			}
		}
		if(Digits=='.')
		{
			LCD_voidClearDisplay();
			if(FResult==0)
			{
				LCD_voidGoTOXY(0,0);
				LCD_voidWriteFloat(Operand);
				LCD_voidWriteChar('.');
			}
			else
			{
				LCD_voidGoTOXY(1,0);
				LCD_voidWriteFloat(FResult);
				LCD_voidGoTOXY(0,0);
				LCD_voidWriteString("Answer");
				LCD_voidWriteChar(LastOprator);
				LCD_voidWriteFloat(Operand);
				LCD_voidWriteChar('.');
			}
			Digits=CALC_uint8ReadFromUser(&FloatPart,&floatcount);
			if(Digits=='.')
			{
				LCD_voidClearDisplay();
				LCD_voidWriteString("Two Floating Point!");
				Operand=0;
				FloatPart=0;
				FResult=0;
				FirstOperationFlag=0;
				_delay_ms(5000);
				LCD_voidClearDisplay();
				LCD_voidGoTOXY(0,0);
				LCD_voidWriteInteger(0);
				LCD_voidGoTOXY(0,0);
			}
			else
			{
				FloatPart=FloatPart/Calc_uint32Power(floatcount);
				Operand+=(FloatPart);
				FloatPart=0;

			}
		}
		if(Digits=='+'||Digits=='-'||Digits=='*'||Digits=='/')
		{
			LCD_voidWriteChar(Digits);
			if(FirstOperationFlag==1)
			{
				switch (LastOprator)
				{
				case '+':
					if(floatcount==1)
					{
						if(Digits!='-')
						{
							LCD_voidSendCMD(0x10);
							LCD_voidWriteChar(' ');
							LCD_voidSendCMD(0x10);
							LCD_voidSendCMD(0x10);
							LCD_voidWriteChar(Digits);

						}
						LastOprator=Digits;
						MultiSignFlag=1;
					}
					else
					{
						FResult=FResult+Operand;
						Operand=0;
						LastOprator=Digits;
					}
					break;
				case '-':
					if(Operand==0)
					{
						if(Digits!='+')
						{
							LCD_voidSendCMD(0x10);
							LCD_voidWriteChar(' ');
							LCD_voidSendCMD(0x10);
							LCD_voidSendCMD(0x10);
							LCD_voidWriteChar(Digits);
						}
						MultiSignFlag=1;
					}
					else
					{
						FResult=FResult-Operand;
						Operand=0;
						LastOprator=Digits;
					}
					break;
				case '*':
					if(Operand==0)
					{
						MultiSignFlag=1;
						if(Digits=='-')
						{
							FResult*=-1;
						}
						else if (Digits=='+')
						{
							/*NoThing*/
						}
						else
						{
							LCD_voidSendCMD(0x10);
							LCD_voidWriteChar(' ');
							LCD_voidSendCMD(0x10);
							LCD_voidSendCMD(0x10);
							LCD_voidWriteChar(Digits);
							LastOprator=Digits;
						}
					}
					else
					{
						FResult=FResult*Operand;
						Operand=0;
						LastOprator=Digits;
					}

					break;
				case '/':
					if(floatcount==0)
					{
						MultiSignFlag=1;
						if(Digits=='-')
						{
							FResult*=-1;
						}
						else if (Digits=='+')
						{
							/*Nothing*/
						}
						else
						{
							LCD_voidSendCMD(0x10);
							LCD_voidWriteChar(' ');
							LCD_voidSendCMD(0x10);
							LCD_voidSendCMD(0x10);
							LCD_voidWriteChar(Digits);
							LastOprator=Digits;
							LastOprator=Digits;
						}
					}
					else
					{
						if(Operand==0)
						{
							LCD_voidClearDisplay();
							LCD_voidWriteString("Division by ZERO!");
							Operand=0;
							FResult=0;
							FirstOperationFlag=0;
							_delay_ms(5000);
							DividebyZeroFlag=1;
						}
						else
						{
							FResult=FResult/Operand;
							Operand=0;
							LastOprator=Digits;
						}
					}

					break;
				}

				if(DividebyZeroFlag==0)
				{
					if(MultiSignFlag==0)
					{
						LCD_voidClearDisplay();
						LCD_voidGoTOXY(1,0);
						LCD_voidWriteFloat(FResult);
						LCD_voidGoTOXY(0,0);
						LCD_voidWriteString("Answer");
						LCD_voidWriteChar(LastOprator);
					}
					else
					{
						MultiSignFlag=0;
					}

				}
				else
				{
					LCD_voidClearDisplay();
					DividebyZeroFlag=0;
					LCD_voidGoTOXY(0,0);
					LCD_voidWriteInteger(FResult);
					LCD_voidGoTOXY(0,0);
				}
			}
			else
			{
				FResult=Operand;
				Operand=0;
				LastOprator=Digits;
				FirstOperationFlag=1;
			}
		}

	}
}
