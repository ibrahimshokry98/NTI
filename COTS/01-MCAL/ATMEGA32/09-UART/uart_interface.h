/*
 * uart_interface.h
 *
 *  Created on: Jul 2, 2023
 *      Author: Shokry
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/* Select 5 to 9 */
#define DAtA_SIZE			8

/* Select from
* EVEN
* ODD
* DISABLED
*/
#define PARITY_MODE			DISABLED

/* Select 1 OR 2 */
#define STOP_BITS			1



/* Select from
* Asynchronous
* Synchronous
*/
#define USART_Mode			Asynchronous

#if USART_Mode == Synchronous
/* Select from
* TXRISING
* TXFALLING
*/
#define Clock_Polarity		TXRISING

#elif USART_Mode == Asynchronous
#define BAUDRATE			9600			/* select Bit Rate you want */
#define F_OSC				8				/* Write The Clock of the UART in MHZ*/

/* Select from
* SingleSpeed
* DoupleSpeed
*/
#define Speed_Mode		SingleSpeed
#if Speed_Mode == SingleSpeed
#define UBBRVAL 		((uint16)(((F_OSC*1000000UL)/(16UL*BAUDRATE))-1))
#elif Speed_Mode == DoupleSpeed
#define UBBRVAL 		((uint16)(((F_OSC*1000000UL)/(8UL*BAUDRATE))-1))
#endif
#endif

void UART_Init(void);
void UART_SendChar (sint8 Data);
void UART_SendString (char* Data);
uint8 UART_RecieveChar (void);
#endif /* UART_INTERFACE_H_ */
