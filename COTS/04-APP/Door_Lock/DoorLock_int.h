

#ifndef DOOR_LOCK_H_
#define DOOR_LOCK_H_


#define BuzzerPort		PORTC
#define BuzzerPin		PIN6

#define LedPort		PORTA
#define LedPin		PIN4


extern uint16 CorrectPass;
void DoorLock_voidFunc(void);
void DoorLock_voidInit(void);

#endif /* DOOR_LOCK_H_ */