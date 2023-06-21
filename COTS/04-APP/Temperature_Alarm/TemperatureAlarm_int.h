/*
 * TemperatureAlarm_int.h
 *
 * Created: 6/21/2023 10:52:03 AM
 *  Author: Shokry
 */ 


#ifndef TEMPERATUREALARM_INT_H_
#define TEMPERATUREALARM_INT_H_



#define GreenLedPort			PORTA
#define GreenLedPin				PIN4

#define RedLedPort				PORTB
#define RedLedPin				PIN7

#define BuzzerPort				PORTC
#define BuzzerPin				PIN6

void Alarm_Init (void);
void Alarm_start(void);



#endif /* TEMPERATUREALARM_INT_H_ */