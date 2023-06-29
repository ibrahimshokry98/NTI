/*
 * GPIOx.h
 *
 *  Created on: Jun 23, 2023
 *      Author: Shokry
 */

#ifndef GPIOX_H_
#define GPIOX_H_


void Set_Pin_Direction (uint8 Port,uint8 pin,uint8 PIN_Direction);
void Set_Pin_VAL (uint8 Port,uint8 pin,uint8 PIN_VAL);
void Toggle_Pin_Val (uint8 Port,uint8 pin);
uint8 Get_Pin_VAL (uint8 Port,uint8 pin);




/*******************************PIN DIRECTIONS************************************/
#define AF0						0			/*   System    */
#define AF1						1			/*   System    */
#define AF2						2			/*   System    */
#define AF3						3			/*   System    */
#define AF4						4
#define AF5						5
#define AF6						6
#define AF7						7
#define AF8						8
#define AF9						9
#define AF10					10
#define AF11					11
#define AF12					12
#define AF13					13
#define AF14					14
#define AF15					15
#define OUPUTPUSHPULL			16
#define OUTPUTOPENDRAIN			17
#define ANALOGMODE				18
#define INPUTPOLLUP				19
#define INPUTPOLLDOWN			20
#define INPUTFLOAT				21
/*********************************************************************************/

/************************GPIOx*****************************/
#define GPIOA			0
#define GPIOB			1
#define GPIOC			2
#define GPIOD			3
/**********************************************************/

/*******************************PIN VALUES*******************************/
#define LOW				0
#define HIGH			1
/************************************************************************/

/*******************************PINS************************************/
#define PIN0			0
#define PIN1			1
#define PIN2			2
#define PIN3			3
#define PIN4			4
#define PIN5			5
#define PIN6			6
#define PIN7			7
#define PIN8			8
#define PIN9			9
#define PIN10			10
#define PIN11			11
#define PIN12			12
#define PIN13			13
#define PIN14			14
#define PIN15			15
/*************************************************************************/

#endif /* GPIOX_H_ */
