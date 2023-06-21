#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


void Set_Pin_Direction (uint8 Port,uint8 pin,uint8 PIN_Direction);
void Set_Pin_Val (uint8 Port,uint8 pin,uint8 val) ;
void Toggle_Pin (uint8 Port,uint8 pin) ;
uint8 Read_Pin_Val (uint8 Port,uint8 pin);
void DIO_INIT(void);
void Set_Port_Direction (uint8 Port,uint8 PORT_Direction);
void Set_Port_Val (uint8 Port,uint8 val) ;
void Toggle_Port (uint8 Port) ;
uint8 Read_Port_Val (uint8 Port);


enum PORTs {
	PORTA,
	PORTB,
	PORTC,
	PORTD
};

enum PINs {
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
};

enum Directions {
	INPUT,
	OUTPUT
};

enum BIT_VAL{
	LOW,
	HIGH
};

#endif /* INTERFACE_H_ */