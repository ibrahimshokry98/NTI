
#include "STD_Types.h"
#include "BITMATH.h"

#include "TIMER0_interface.h"
#include "TIMER0_config.h"
#include "TIMER0_private.h"


void(*TIMER_FUNCPTR)(void) = 0 ;

void Timer0_vidInit(void)
{
	/*Select Timer Mode*/
	#if TIMER0_MODE == NORMAL_MODE 
		TCCR0->WGM01 = 0;
		TCCR0->WGM00 = 0;
	#elif TIMER0_MODE == CMP_MODE
		TCCR0->WGM01 = 0;
		TCCR0->WGM00 = 1;
	#elif TIMER0_MODE == PWM_PHASECORRECT
		TCCR0->WGM01 = 1;
		TCCR0->WGM00 = 0;
		TCCR0->COM00_COM01 = CompareOutputMode ;
	#elif TIMER0_MODE == PWM_FAST
		TCCR0->WGM01 = 1;
		TCCR0->WGM00 = 1; 
		TCCR0->COM00_COM01 = CompareOutputMode ;
	#endif
}

void TIMER0_voidDutyCycle(uint8 DutyCycleVal)
{
	uint8 CMPVAL;
	#if CompareOutputMode == CLEARONCMP
		CMPVAL = ((float32)DutyCycleVal/100) * 256 ; 
	#elif CompareOutputMode == SETONCMP
		CMPVAL = (1-((float32)DutyCycleVal/100)) * 256 ;
	#endif
	OCR0 = CMPVAL -1 ;
}

void Timer0_vidStart(void)
{
	/*Select Pre-load*/
	TCNT0 = PRE_LOAD_VALUE ;
	
	/*Select the Clock that operate the timer*/
	TCCR0->CS00_CS02 = TIMER0_CLK ;
}

void Timer0_vidStop(void)
{
	/*stop the Clock that operate the timer*/
	TCCR0->CS00_CS02 = STOP_TIMER ;
}

void Timer0_vidEnableInterrupt(void)
{
	#if TIMER0_MODE == NORMAL_MODE
		/*Enable the interrupt*/
		TIMSK->TOIE0 = 1;
		TIMSK->OCIE0 = 0;
	#elif TIMER0_MODE == CMP_MODE
		/*Enable the interrupt*/
		TIMSK->OCIE0 = 1;
		TIMSK->TOIE0 = 0;
	#endif
}

void Timer0_vidDisableInterrupt(void)
{	
	#if TIMER0_MODE == NORMAL_MODE
		/*Disable the interrupt*/
		TIMSK->TOIE0 = 0;
	#elif TIMER0_MODE == CMP_MODE
		/*Enable the interrupt*/
		TIMSK->OCIE0 = 0;
	#endif
	
}

void Timer0_vidCallback(void(*ptr)(void))
{
	
	if (TIMER_FUNCPTR!=0)
	{
		TIMER_FUNCPTR = ptr;
	}
	
}

void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	if (TIMER_FUNCPTR!=0)
	{
		TIMER_FUNCPTR();
	}
}

void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	if (TIMER_FUNCPTR!=0)
	{
		TIMER_FUNCPTR();
	}
}