


#ifndef TIMER0_PRIVTAE_H_
#define TIMER0_PRIVTAE_H_


typedef struct
{
	uint8 CS00_CS02			: 3 ;
	uint8 WGM01				: 1 ;
	uint8 COM00_COM01		: 2 ;
	uint8 WGM00				: 1 ;
	uint8 FOC0				: 1 ;
}TCCR0_Bits ;

#define TCCR0					((volatile TCCR0_Bits*)0x53)


#define TCNT0					*((volatile uint8 *)0x52)

typedef struct
{
	uint8 TOIE0		: 1 ;
	uint8 OCIE0		: 1 ;
}TIMSK_Bits ;

#define TIMSK					((volatile TIMSK_Bits*)0x59)



#define OCR0					*((volatile uint8 *)0x5C)

/*Clock selection*/

#define STOP_TIMER			0b000
#define NO_DEV				0b001
#define DEV_BY_8			0b010
#define DEV_BY_64			0b011
#define DEV_BY_256			0b100
#define DEV_BY_1024			0b101
#define EXTCLKFALLING		0b110
#define EXTCLKRISING		0b111

/*Mode selection*/
#define NORMAL_MODE			1
#define CMP_MODE			2
#define PWM_PHASECORRECT	3
#define PWM_FAST			4

/*
Compare Output Mode,FAST PWM0 0 Normal port operation, OC0 disconnected.
0 1 Reserved
1 0 Clear OC0 on Compare Match, set OC0 at BOTTOM,
(non-inverting mode)
1 1 Set OC0 on Compare Match, clear OC0 at BOTTOM,
(inverting mode)
*/

#define OC0_DISCONNECTED			1
#define CLEARONCMP					2
#define SETONCMP					3

#endif
















/*TIMER 1*/
#define TCCR1A					*((volatile uint8 *)(0x4F))
#define TCCR1A_COM1A1           7
#define TCCR1A_COM1A0           6
#define TCCR1A_COM1B1           5
#define TCCR1A_COM1B0           4
#define TCCR1A_FOC1A            3
#define TCCR1A_FOC1B            2
#define TCCR1A_WGM11			1
#define TCCR1A_WGM10			0

#define TCCR1B					*((volatile uint8 *)(0x4E))

#define TCNT1H					*((volatile uint8 *)(0x4D))

#define TCNT1L					*((volatile uint8 *)(0x4C))

#define TCNT1					*((volatile u16 *)(0x4C))

#define ICR1H					*((volatile uint8 *)(0x47))

#define ICR1L					*((volatile uint8 *)(0x46))

#define ICR1					*((volatile u16 *)(0x46))

#define OCR1AL					*((volatile uint8 *)(0x4A))

#define OCR1AH					*((volatile uint8 *)(0x4B))

#define OCR1A					*((volatile u16 *)(0x4A))

#define OCR1BL					*((volatile uint8 *)(0x48))

#define OCR1BH					*((volatile uint8 *)(0x49))

#define OCR1B					*((volatile u16 *)(0x48))


/******************************************************************************************************/

