
#include "STD_Types.h"
#include "BITMATH.h"
#include "GP_INT_interface.h"
#include "GP_INT_REGs.h"


void GP_INT_Enable (void)
{
	Set_Bit(SREG_REG,GIEBIT);
}

void GP_INT_Disable (void)
{
	Clear_Bit(SREG_REG,GIEBIT);
}