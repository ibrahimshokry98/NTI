/*
 * GPIOx.c
 *
 *  Created on: Jun 23, 2023
 *      Author: Shokry
 */

#include "STD_Types.h"
#include "BITMATH.h"
#include "GPIOx.h"
#include "GPIOx.priv.h"


void Set_Pin_Direction (uint8 Port,uint8 pin,uint8 PIN_Direction)
{
	if (PIN_Direction==OUPUTPUSHPULL)
	{
		switch (Port)
		{
		case GPIOA:
			GPIOA_MODER &= ~(0b11<<(pin*2));
			GPIOA_MODER |= (0b01<<(pin*2));
			Clear_Bit(GPIOA_OTYPER,pin);
			break;
		case GPIOB:
			GPIOB_MODER &= ~(0b11<<(pin*2));
			GPIOB_MODER |= (0b01<<(pin*2));
			Clear_Bit(GPIOB_OTYPER,pin);
			break;
		case GPIOC:
			GPIOC_MODER &= ~(0b11<<(pin*2));
			GPIOC_MODER |= (0b01<<(pin*2));
			Clear_Bit(GPIOC_OTYPER,pin);
			break;
		case GPIOD:
			GPIOD_MODER &= ~(0b11<<(pin*2));
			GPIOD_MODER |= (0b01<<(pin*2));
			Clear_Bit(GPIOD_OTYPER,pin);
			break;
		default : break;
		}
	}
	else if (PIN_Direction==OUTPUTOPENDRAIN)
	{
		switch (Port)
		{
		case GPIOA:
			GPIOA_MODER &= ~(0b11<<(pin*2));
			GPIOA_MODER |= (0b01<<(pin*2));
			Set_Bit(GPIOA_OTYPER,pin);
			break;
		case GPIOB:
			GPIOB_MODER &= ~(0b11<<(pin*2));
			GPIOB_MODER |= (0b01<<(pin*2));
			Set_Bit(GPIOB_OTYPER,pin);
			break;
		case GPIOC:
			GPIOC_MODER &= ~(0b11<<(pin*2));
			GPIOC_MODER |= (0b01<<(pin*2));
			Set_Bit(GPIOC_OTYPER,pin);
			break;
		case GPIOD:
			GPIOD_MODER &= ~(0b11<<(pin*2));
			GPIOD_MODER |= (0b01<<(pin*2));
			Set_Bit(GPIOD_OTYPER,pin);
			break;
		default : break;
		}
	}
	else if (PIN_Direction==INPUTPOLLUP)
	{
		switch (Port)
		{
		case GPIOA:
			GPIOA_MODER &= ~(0b11<<(pin*2));
			GPIOA_PUPDR &= ~(0b11<<(pin*2));
			GPIOA_PUPDR |=  (0b01<<(pin*2));
			break;
		case GPIOB:
			GPIOB_MODER &= ~(0b11<<(pin*2));
			GPIOB_PUPDR &= ~(0b11<<(pin*2));
			GPIOB_PUPDR |=  (0b01<<(pin*2));
			break;
		case GPIOC:
			GPIOC_MODER &= ~(0b11<<(pin*2));
			GPIOC_PUPDR &= ~(0b11<<(pin*2));
			GPIOC_PUPDR |=  (0b01<<(pin*2));
			break;
		case GPIOD:
			GPIOD_MODER &= ~(0b11<<(pin*2));
			GPIOD_PUPDR &= ~(0b11<<(pin*2));
			GPIOD_PUPDR |=  (0b01<<(pin*2));
			break;
		default : break;
		}
	}
	else if (PIN_Direction==INPUTPOLLDOWN)
	{
		switch (Port)
		{
		case GPIOA:
			GPIOA_MODER &= ~(0b11<<(pin*2));
			GPIOA_PUPDR &= ~(0b11<<(pin*2));
			GPIOA_PUPDR |=  (0b10<<(pin*2));
			break;
		case GPIOB:
			GPIOB_MODER &= ~(0b11<<(pin*2));
			GPIOB_PUPDR &= ~(0b11<<(pin*2));
			GPIOB_PUPDR |=  (0b10<<(pin*2));
			break;
		case GPIOC:
			GPIOC_MODER &= ~(0b11<<(pin*2));
			GPIOC_PUPDR &= ~(0b11<<(pin*2));
			GPIOC_PUPDR |=  (0b10<<(pin*2));
			break;
		case GPIOD:
			GPIOD_MODER &= ~(0b11<<(pin*2));
			GPIOD_PUPDR &= ~(0b11<<(pin*2));
			GPIOD_PUPDR |=  (0b10<<(pin*2));
			break;
		default : break;
		}
	}
	else if (PIN_Direction==INPUTFLOAT)
	{
		switch (Port)
		{
		case GPIOA:
			GPIOA_MODER &= ~(0b11<<(pin*2));
			GPIOA_PUPDR &= ~(0b11<<(pin*2));
			break;
		case GPIOB:
			GPIOB_MODER &= ~(0b11<<(pin*2));
			GPIOB_PUPDR &= ~(0b11<<(pin*2));
			break;
		case GPIOC:
			GPIOC_MODER &= ~(0b11<<(pin*2));
			GPIOC_PUPDR &= ~(0b11<<(pin*2));
			break;
		case GPIOD:
			GPIOD_MODER &= ~(0b11<<(pin*2));
			GPIOD_PUPDR &= ~(0b11<<(pin*2));
			break;
		default : break;
		}
	}
	else if (PIN_Direction==ANALOGMODE)
	{
		switch (Port)
		{
		case GPIOA:
			GPIOA_MODER |=  (0b11<<(pin*2));
			break;
		case GPIOB:
			GPIOB_MODER |=  (0b11<<(pin*2));
			break;
		case GPIOC:
			GPIOC_MODER |=  (0b11<<(pin*2));
			break;
		case GPIOD:
			GPIOD_MODER |=  (0b11<<(pin*2));
			break;
		default : break;
		}
	}
	else if (PIN_Direction<=AF0 && PIN_Direction>=AF15)
	{
		if (pin>=PIN0 && pin<=PIN7)
		{
			switch (Port)
			{
			case GPIOA:
				GPIOA_MODER &= ~(0b11<<(pin*2));
				GPIOA_MODER |=  (0b10<<(pin*2));
				GPIOA_AFRL  &= ~(0b1111<<(pin*4));
				GPIOA_AFRL  |= (PIN_Direction<<(pin*4));

				break;
			case GPIOB:
				GPIOB_MODER &= ~(0b11<<(pin*2));
				GPIOB_MODER |=  (0b10<<(pin*2));
				GPIOB_AFRL  &= ~(0b1111<<(pin*4));
				GPIOB_AFRL  |= (PIN_Direction<<(pin*4));
				break;
			case GPIOC:
				GPIOC_MODER &= ~(0b11<<(pin*2));
				GPIOC_MODER |=  (0b10<<(pin*2));
				GPIOC_AFRL  &= ~(0b1111<<(pin*4));
				GPIOC_AFRL  |= (PIN_Direction<<(pin*4));
				break;
			case GPIOD:
				GPIOD_MODER &= ~(0b11<<(pin*2));
				GPIOD_MODER |=  (0b10<<(pin*2));
				GPIOD_AFRL  &= ~(0b1111<<(pin*4));
				GPIOD_AFRL  |= (PIN_Direction<<(pin*4));
				break;
			default : break;
			}
		}
		else if (pin>=PIN8 && pin<=PIN15)
		{
			switch (Port)
			{
			case GPIOA:
				GPIOA_MODER &= ~(0b11<<(pin*2));
				GPIOA_MODER |=  (0b10<<(pin*2));
				GPIOA_AFRH  &= ~(0b1111<<(pin*4));
				GPIOA_AFRH  |= (PIN_Direction<<(pin*4));

				break;
			case GPIOB:
				GPIOB_MODER &= ~(0b11<<(pin*2));
				GPIOB_MODER |=  (0b10<<(pin*2));
				GPIOB_AFRH  &= ~(0b1111<<(pin*4));
				GPIOB_AFRH  |= (PIN_Direction<<(pin*4));
				break;
			case GPIOC:
				GPIOC_MODER &= ~(0b11<<(pin*2));
				GPIOC_MODER |=  (0b10<<(pin*2));
				GPIOC_AFRH  &= ~(0b1111<<(pin*4));
				GPIOC_AFRH  |= (PIN_Direction<<(pin*4));
				break;
			case GPIOD:
				GPIOD_MODER &= ~(0b11<<(pin*2));
				GPIOD_MODER |=  (0b10<<(pin*2));
				GPIOD_AFRH  &= ~(0b1111<<(pin*4));
				GPIOD_AFRH  |= (PIN_Direction<<(pin*4));
				break;
			default : break;
			}
		}
	}
}

void Set_Pin_VAL (uint8 Port,uint8 pin,uint8 PIN_VAL)
{
	if (PIN_VAL == HIGH)
	{
		switch (Port)
		{
		case GPIOA :
			Set_Bit(GPIOA_ODR,pin);
			break;
		case GPIOB:
			Set_Bit(GPIOB_ODR,pin);
			break;
		case GPIOC:
			Set_Bit(GPIOC_ODR,pin);
			break;
		case GPIOD:
			Set_Bit(GPIOD_ODR,pin);
			break;
		default : break;
		}
	}
	else if (PIN_VAL == LOW)
	{
		switch (Port)
		{
		case GPIOA :
			Clear_Bit(GPIOA_ODR,pin);
			break;
		case GPIOB:
			Clear_Bit(GPIOB_ODR,pin);
			break;
		case GPIOC:
			Clear_Bit(GPIOC_ODR,pin);
			break;
		case GPIOD:
			Clear_Bit(GPIOD_ODR,pin);
			break;
		default : break;
		}
	}
}


uint8 Get_Pin_VAL (uint8 Port,uint8 pin)
{
	uint8 read ;
	switch (Port)
	{
	case GPIOA :
		read = Read_Bit(GPIOA_IDR,pin);
		break;
	case GPIOB:
		read = Read_Bit(GPIOB_IDR,pin);
		break;
	case GPIOC:
		read = Read_Bit(GPIOC_IDR,pin);
		break;
	case GPIOD:
		read = Read_Bit(GPIOD_IDR,pin);
		break;
	default : break;
	}
	return read ;
}

void Toggle_Pin_Val (uint8 Port,uint8 pin)
{
	switch (Port)
	{
	case GPIOA :
		Toggle_Bit(GPIOA_ODR,pin);
		break;
	case GPIOB:
		Toggle_Bit(GPIOB_ODR,pin);
		break;
	case GPIOC:
		Toggle_Bit(GPIOC_ODR,pin);
		break;
	case GPIOD:
		Toggle_Bit(GPIOD_ODR,pin);
		break;
	default : break;
	}
}

