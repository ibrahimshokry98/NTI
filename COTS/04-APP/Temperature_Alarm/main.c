#define F_CPU 16000000UL
#include "util/delay.h"
#include "STD_Types.h"
#include "BITMATH.h"

#include "DIO_int.h"
#include "ADC_Interface.h"

#include "Lcd_int.h"

#include "TemperatureAlarm_int.h"



int main()
{
	Alarm_Init();
	while(1)
	{
		Alarm_start();
	}
}