

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_


/*	options :
				STOP_TIMER
				NO_DEV
				DEV_BY_8
				DEV_BY_64
				DEV_BY_256
				DEV_BY_1024
				EXTCLKFALLING
				EXTCLKRISING
*/
#define TIMER0_CLK				DEV_BY_1024



/*	options :

 OC0_DISCONNECTED			0
 CLEARONCMP					2
 SETONCMP					3
*/
#define CompareOutputMode		CLEARONCMP

/*
Options
	NORMAL_MODE
	CMP_MODE
	PWM_FAST
	PWM_PHASECORRECT
*/
#define TIMER0_MODE				PWM_FAST

#define PRE_LOAD_VALUE			0







#endif