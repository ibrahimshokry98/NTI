


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

enum Channels {
	Channel0,
	Channel1,
	Channel2,
	Channel3,
	Channel4,
	Channel5,
	Channel6,
	Channel7
	};
enum Prescalers {
	Prescaler2,
	Prescaler4=2,
	Prescaler8,
	Prescaler16,
	Prescaler32,
	Prescaler64,
	Prescaler128
	};

enum VREFS {
	AREF,
	AVCC,
	AIV=3
	};
	
void ADC_voidInit (uint8 PrescalerVal);
uint16 ADC_u16ReadADCPOLL (uint8 channel);
uint16 ADC_u16ReadADCINT (uint8 channel);
void ADC_voidEnableINt (void);
void ADC_voidDisableINt (void);
void ADC_voidSetCallBack(void(*PF)(void));
sint16 ADC_s16ConvertADC (sint16 SensorY0,sint16 SensorY1, uint16 ADCX0, uint16 ADCX1,uint16 Read);

#endif /* ADC_INTERFACE_H_ */