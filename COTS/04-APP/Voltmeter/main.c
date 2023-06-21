/*
 * main.c
 *
 * Created: 6/18/2023 8:37:31 PM
 *  Author: Shokry
 */ 

#include "STD_Types.h"
#include "BITMATH.h"
#define F_CPU 16000000UL
#include "DIO_int.h"
#include "ADC_Interface.h"

#include "Lcd_int.h"
#include "Ohmmeter.h"

int main(void)
{
	Ohmmeter_Init();
    while(1)
    {
		Ohmmeter_start();
    }
}