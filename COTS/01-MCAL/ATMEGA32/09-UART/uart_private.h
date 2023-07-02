/*
 * uart_private.h
 *
 *  Created on: Jul 2, 2023
 *      Author: Shokry
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


#define UDR_REG				*((vuint8_t*)0x2C)

#define UCSRA_REG			*((vuint8_t*)0x2B)
//bits
#define MPCM				0
#define U2X					1
#define PE					2
#define DOR					3
#define FE					4
#define UDRE				5
#define TXC					6
#define RXC					7

#define UCSRB_REG			*((vuint8_t*)0x2A)
//bits
#define TXB8				0
#define RXB8 				1
#define UCSZ2 				2
#define TXEN 				3
#define RXEN 				4
#define UDRIE				5
#define TXCIE  				6
#define RXCIE 				7

#define UCSRC_REG			*((vuint8_t*)0x40)
//bits
#define UCPOL				0
#define UCSZ0				1
#define UCSZ1				2
#define USBS				3
#define UPM0				4
#define UPM1				5
#define UMSEL				6
#define URSEL				7

#define UBRRL_REG			*((vuint8_t*)0x29)
#define UBRRH_REG			*((vuint8_t*)0x40)


#define EVEN				1
#define ODD					2
#define DISABLED			3


#define Asynchronous		1
#define Synchronous			2

#define TXRISING			1
#define TXFALLING			2


#define SingleSpeed			1
#define DoupleSpeed			2


#endif /* UART_PRIVATE_H_ */
