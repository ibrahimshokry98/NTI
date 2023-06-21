

#define F_CPU 16000000UL
#include "util/delay.h"
#include "STD_Types.h"
#include "BITMATH.h"

#include "DIO_int.h"

#include "KeyPad_int.h"
#include "Lcd_int.h"

#include "Calculater_Interface.h"

int main(void)
{
	
	CALC_voidInit();
	CALC_voidWelcome();
	CALC_voidCalculate();

}