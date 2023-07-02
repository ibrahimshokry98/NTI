
#include "STD_Types.h"
#include "BitMath.h"

void WDT_Sleep(uint8 Prescaler)
{
	WDTCR &= PrescalerMask ;
	WDTCR |= Prescaler ;
}

void WDT_Enable(void)
{
	Set_Bit (WDTCR,WDE);
}

void WDT_Disable(void)
{
	WDTCR = DisableWatchDogS1;
	WDTCR = DisableWatchDogS2;
}