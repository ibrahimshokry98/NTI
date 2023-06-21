
/* *************************LIBS******************************/ 
#include "STD_Types.h"
#include "BITMATH.h"
/* *************************MCAL******************************/ 
#include "DIO_int.h"
/* *************************HAL******************************/ 
#include "Lcd_int.h"
#include "KeyPad_int.h"
/* *************************APP******************************/ 
#include "DoorLock_int.h"
/* *************************Others******************************/ 

int main(void)
{
	CorrectPass = 1234;
	DoorLock_voidInit();
	DoorLock_voidFunc();
	return 0;
}