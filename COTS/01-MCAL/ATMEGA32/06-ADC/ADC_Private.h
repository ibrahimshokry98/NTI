


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define	ADMUX_REG		*((vuint8_t*)0x27)

#define	ADCSRA_REG		*((vuint8_t*)0x26)

#define	ADCH_REG		*((vuint8_t*)0x25)

#define	ADCL_REG		*((vuint16_t*)0x24)

#define	SFIOR_REG		*((vuint8_t*)0x50)


enum ADMUX_Bits {
	MUX0,
	MUX1,
	MUX2,
	MUX3,
	MUX4,
	ADLAR,
	REFS0,
	REFS1       
	};
	
enum ADCSRA_Bits {
	ADPS0,
	ADPS1,
	ADPS2,
	ADIE,
	ADIF,
	ADATE,
	ADSC,
	ADEN       
};

#define PrescalerMask 0b11111000

#define ChannelMask 0b11100000

#define SFIORMask 0b00011111

#endif /* ADC_PRIVATE_H_ */