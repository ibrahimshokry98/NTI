/*
 * uart.c
 *
 *  Created on: Jul 2, 2023
 *      Author: Shokry
 */



#include "STD_Types.h"
#include "BITMATH.h"

#include "uart_private.h"
#include "uart_interface.h"


void UART_Init(void)
{

	uint8 UCSRC_Data = 0x80;
	uint16 UBRR_Val = 0;

	/*Set Baud Rate*/

	/*USART Mode Select*/
	#if USART_Mode == Asynchronous
	Clear_Bit(UCSRC_Data,URSEL);
	UBRR_Val = UBBRVAL;
	UBRRL_REG = (uint8) UBRR_Val ;
	UBRRH_REG = (uint8)(UBRR_Val>>8);
	#elif USART_Mode == Synchronous
	Set_Bit(UCSRC_Data,URSEL);
		#if Clock_Polarity == TXRISING
		Clear_Bit(UCSRC_Data,UCPOL);
		#elif Clock_Polarity == TXFALLING
		Set_Bit(UCSRC_Data,UCPOL);
	#endif
	#endif

	/* Select Data size */
	#if DAtA_SIZE == 5
	Clear_Bit(UCSRC_Data,UCSZ0);
	Clear_Bit(UCSRC_Data,UCSZ1);
	Clear_Bit(UCSRB_REG,UCSZ2);
	#elif DAtA_SIZE == 6
	Set_Bit(UCSRC_Data,UCSZ0);
	Clear_Bit(UCSRC_Data,UCSZ1);
	Clear_Bit(UCSRB_REG,UCSZ2);
	#elif DAtA_SIZE == 7
	Clear_Bit(UCSRC_Data,UCSZ0);
	Set_Bit(UCSRC_Data,UCSZ1);
	Clear_Bit(UCSRB_REG,UCSZ2);
	#elif DAtA_SIZE == 8
	Set_Bit(UCSRC_Data,UCSZ0);
	Set_Bit(UCSRC_Data,UCSZ1);
	Clear_Bit(UCSRB_REG,UCSZ2);
	#elif DAtA_SIZE == 9
	Set_Bit(UCSRC_Data,UCSZ0);
	Set_Bit(UCSRC_Data,UCSZ1);
	Set_Bit(UCSRB_REG,UCSZ2);
	#endif

	/* Select Parity */
	#if PARITY_MODE == EVEN
	Clear_Bit(UCSRC_Data,UPM0);
	Set_Bit(UCSRC_Data,UPM1);
	#elif PARITY_MODE == ODD
	Set_Bit(UCSRC_Data,UPM0);
	Set_Bit(UCSRC_Data,UPM1);
	#elif PARITY_MODE == DISABLED
	Clear_Bit(UCSRC_Data,UPM0);
	Clear_Bit(UCSRC_Data,UPM1);
	#endif

	/* Select Stop Bits */
	#if STOP_BITS == 1
	Set_Bit(UCSRC_Data,USBS);
	#elif STOP_BITS == 2
	Clear_Bit(UCSRC_Data,USBS);
	#endif

	/* Set UCSRC_REG  With its options */
	UCSRC_REG = UCSRC_Data ;

	/*Enable Receiver and transmitter*/
	Set_Bit(UCSRB_REG,RXEN);
	Set_Bit(UCSRB_REG,TXEN);
}


void UART_SendChar (sint8 Data)
{
	while (Read_Bit(UCSRA_REG,UDRE)==0);
	UDR_REG = Data ;
}

void UART_SendString (char* Data)
{
	while (*Data)
	{
		UART_SendChar (*Data);
		Data++;
	}
}


uint8 UART_RecieveChar (void)
{
	while (Read_Bit(UCSRA_REG,RXC)==0);
	return UDR_REG ;
}
