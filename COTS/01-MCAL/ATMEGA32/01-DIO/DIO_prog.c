#include "STD_Types.h"
#include "BITMATH.h"

#include "DIO_int.h"
#include "DIO_config.h"
#include "DIO_priv.h"




void DIO_INIT(void)
{
	DDRA_REG = DDRAVAL;
	DDRB_REG = DDRAVAL;
	DDRC_REG = DDRCVAL;
	DDRD_REG = DDRDVAL;
	
	PORTA_REG = PORTAVAL ;
	PORTB_REG = PORTBVAL ;
	PORTC_REG = PORTCVAL ;
	PORTD_REG = PORTDVAL ;
}




void Set_Pin_Direction (uint8 Port,uint8 pin,uint8 PIN_Direction)
{
	if (PIN_Direction==INPUT)
	{
		switch (Port)
		{
			case PORTA : Clear_Bit(DDRA_REG,pin) ; break;
			case PORTB : Clear_Bit(DDRB_REG,pin) ; break;
			case PORTC : Clear_Bit(DDRC_REG,pin) ; break;
			case PORTD : Clear_Bit(DDRD_REG,pin) ; break;
			default : break;
		}
	}
	else if (PIN_Direction==OUTPUT)
	{
		switch (Port)
		{
			case PORTA : Set_Bit(DDRA_REG,pin) ; break;
			case PORTB : Set_Bit(DDRB_REG,pin) ; break;
			case PORTC : Set_Bit(DDRC_REG,pin) ; break;
			case PORTD : Set_Bit(DDRD_REG,pin) ; break;
			default : break;
		}
	}
}

void Set_Pin_Val (uint8 Port,uint8 pin,uint8 val)
{
		if (val==LOW)
		{
			switch (Port)
			{
				case PORTA : Clear_Bit(PORTA_REG,pin) ; break;
				case PORTB : Clear_Bit(PORTB_REG,pin) ; break;
				case PORTC : Clear_Bit(PORTC_REG,pin) ; break;
				case PORTD : Clear_Bit(PORTD_REG,pin) ; break;
				default : break;
			}
		}
		else if (val==HIGH)
		{
			switch (Port)
			{
				case PORTA : Set_Bit(PORTA_REG,pin) ; break;
				case PORTB : Set_Bit(PORTB_REG,pin) ; break;
				case PORTC : Set_Bit(PORTC_REG,pin) ; break;
				case PORTD : Set_Bit(PORTD_REG,pin) ; break;
				default : break;
			}
		}
}
void Toggle_Pin (uint8 Port,uint8 pin) 
{
	switch (Port)
	{
		case PORTA : Clear_Bit(PORTA_REG,pin) ; break;
		case PORTB : Clear_Bit(PORTB_REG,pin) ; break;
		case PORTC : Clear_Bit(PORTC_REG,pin) ; break;
		case PORTD : Clear_Bit(PORTD_REG,pin) ; break;
		default : break;
	}
	
}

uint8 Read_Pin_Val (uint8 Port,uint8 pin)
{
	uint8 Pin_Val=1 ;
		switch (Port)
		{
			case PORTA : Pin_Val = Read_Bit(PINA_REG,pin); break;
			case PORTB : Pin_Val = Read_Bit(PINB_REG,pin); break;
			case PORTC : Pin_Val = Read_Bit(PINC_REG,pin); break;
			case PORTD : Pin_Val = Read_Bit(PIND_REG,pin); break;
			default : break;
		}
		return Pin_Val;
}

void Set_Port_Direction (uint8 Port,uint8 PORT_Direction)
{
	if (PORT_Direction==INPUT)
	{
			switch (Port)
			{
				case PORTA : Clear_REG(DDRA_REG) ; break;
				case PORTB : Clear_REG(DDRB_REG) ; break;
				case PORTC : Clear_REG(DDRC_REG) ; break;
				case PORTD : Clear_REG(DDRD_REG) ; break;
				default : break;
			}
	}
		else if (PORT_Direction==OUTPUT)
		{
			switch (Port)
			{
				case PORTA : Set_REG(DDRA_REG) ; break;
				case PORTB : Set_REG(DDRB_REG) ; break;
				case PORTC : Set_REG(DDRC_REG) ; break;
				case PORTD : Set_REG(DDRD_REG) ; break;
				default : break;
			}
		}
}


void Set_Port_Val (uint8 Port, uint8 val) 
{

		switch (Port)
		{
			case PORTA : Set_REG_Val(PORTA_REG,val) ; break;
			case PORTB : Set_REG_Val(PORTB_REG,val) ; break;
			case PORTC : Set_REG_Val(PORTC_REG,val) ; break;
			case PORTD : Set_REG_Val(PORTD_REG,val) ; break;
			default : break;
		}
	
}
void Toggle_Port (uint8 Port) 
{
		switch (Port)
		{
			case PORTA : Toggle_REG(PORTA_REG) ; break;
			case PORTB : Toggle_REG(PORTB_REG) ; break;
			case PORTC : Toggle_REG(PORTC_REG) ; break;
			case PORTD : Toggle_REG(PORTD_REG) ; break;
			default : break;
		}
}
uint8 Read_Port_Val (uint8 Port)
{
	uint8 Read_Port_Value=0 ;
	switch (Port)
	{
		case PORTA : Read_Port_Value = Read_REG(PINA_REG); break;
		case PORTB : Read_Port_Value = Read_REG(PINB_REG); break;
		case PORTC : Read_Port_Value = Read_REG(PINC_REG); break;
		case PORTD : Read_Port_Value = Read_REG(PIND_REG); break;
		default : break;
	}
	return Read_Port_Value;
}