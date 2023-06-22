 

#define F_CPU	16000000UL
#include "util/delay.h"
#include "STD_Types.h"
#include "BITMATH.h"


#include "DIO_int.h"

#include "EXT_INT1_interface.h"
#include "EXT_INT0_interface.h"

#include "GP_INT_interface.h"
#include "SSInterface.h"

void func1 (void);
void func2 (void);

SSData_t SS1 = {PORTB,{PIN0,PIN1,PIN2,PIN4},PORTA,PIN3,Cathode} ;
SSData_t SS2 = {PORTB,{PIN0,PIN1,PIN2,PIN4},PORTA,PIN2,Cathode} ;
vuint8_t SS1count=0;
vuint8_t SS2count=0;
int main(void)
{
	EXT_INT0_CallBack(func2);
	EXT_INT1_CallBack(func1);
	SS_Init(&SS1);
	SS_Init(&SS2);
	EXT_INT1_SenseControl(RisingEdge);
	EXT_INT0_SenseControl(RisingEdge);
	EXT_INT1_Enable();
	EXT_INT0_Enable();
	GP_INT_Enable();
	
	
    while(1)
    {
		SS_Display(&SS1,SS1count);
		SS_Disable(&SS2);
		_delay_ms(10);
		SS_Display(&SS2,SS2count);
		SS_Disable(&SS1);
		_delay_ms(10);
    }
}

void func1 (void)
{
	SS1count++;
	if (SS1count==10)
	{
		SS1count = 0;
		SS2count++;
		if (SS2count==10)
		{
			SS2count = 0;
		}
	}
}
void func2 (void)
{
	SS1count=0;
	SS1count=0;
}