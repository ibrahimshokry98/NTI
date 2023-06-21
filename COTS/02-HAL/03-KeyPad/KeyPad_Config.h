

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


#define Row1Pin			PIN5		
#define Row1Port		PORTC

#define Row2Pin			PIN4
#define Row2Port		PORTC

#define Row3Pin			PIN3
#define Row3Port		PORTC

#define Row4Pin			PIN2
#define Row4Port		PORTC

#define Column1Pin		PIN7
#define Column1Port		PORTD

#define Column2Pin		PIN6
#define Column2Port		PORTD

#define Column3Pin		PIN5
#define Column3Port		PORTD

#define Column4Pin		PIN3
#define Column4Port		PORTD

#define KeyPadMatrix { {7,8,9,'/'}, {4,5,6,'*'}, {1,2,3,'-'}, { '.',0,'=','+'} }

#endif /* KEYPAD_CONFIG_H_ */