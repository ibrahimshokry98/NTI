
#ifndef WATCHDOG_PRIV_
#define WATCHDOG_PRIV_ 


#define WDTCR					*((vuint8_t*)0x41)
#define WDTOE 					4						/*Watchdog Turn-off Enable*/
#define WDE 					3						/*Watchdog Enable*/

#define PrescalerMask			0xF8

#define DisableWatchDogS1		((1<<WDE) | (1<<WDTOE))
#define DisableWatchDogS2		0x00

#endif