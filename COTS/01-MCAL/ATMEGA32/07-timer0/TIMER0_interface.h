

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_



void Timer0_vidInit(void);

void Timer0_vidStart(void);

void Timer0_vidStop(void);

void Timer0_vidEnableInterrupt(void);

void Timer0_vidDisableInterrupt(void);

void Timer0_vidCallback(void(*ptr)(void));

void TIMER0_voidDutyCycle(uint8 DutyCycleVal);


#endif