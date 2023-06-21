

#include "STD_Types.h"
#include "BITMATH.h"

#include "DIO_int.h"


#include "KeyPad_int.h"
#include "KeyPad_Config.h"
#include "KeyPad_priv.h"

void KeyPad_voidInit(void)
{
	Set_Pin_Direction(Row1Port,Row1Pin,INPUT);
	Set_Pin_Direction(Row2Port,Row2Pin,INPUT);
	Set_Pin_Direction(Row3Port,Row3Pin,INPUT);
	Set_Pin_Direction(Row4Port,Row4Pin,INPUT);
	
	Set_Pin_Val(Row1Port,Row1Pin,HIGH);
	Set_Pin_Val(Row2Port,Row2Pin,HIGH);
	Set_Pin_Val(Row3Port,Row3Pin,HIGH);
	Set_Pin_Val(Row4Port,Row4Pin,HIGH);
	
	Set_Pin_Direction(Column1Port,Column1Pin,OUTPUT);
	Set_Pin_Direction(Column2Port,Column2Pin,OUTPUT);
	Set_Pin_Direction(Column3Port,Column3Pin,OUTPUT);
	Set_Pin_Direction(Column4Port,Column4Pin,OUTPUT);
	
	Set_Pin_Val(Column1Port,Column1Pin,HIGH);
	Set_Pin_Val(Column2Port,Column2Pin,HIGH);
	Set_Pin_Val(Column3Port,Column3Pin,HIGH);
	Set_Pin_Val(Column4Port,Column4Pin,HIGH);
}


const uint8 KeyPadValues[4][4] = KeyPadMatrix;

uint8 KeyPad_uint8PressedKey(void)
{
	const uint8 ColumnsPins[4]=Columns_Pins;
	const uint8 ColumnsPorts[4]=Columns_Ports;
	const uint8 RowsPins[4]=Rows_Pins;
	const uint8 RowsPorts[4]=Rows_Ports;
	
	uint8 Local_ColCount;
	uint8 Local_RowCount;
	
	uint8 local_PinVal;

	uint8 Local_uint8PressedKey = 0xFF;
	for (Local_ColCount=0;Local_ColCount<4;Local_ColCount++)
	{
		Set_Pin_Val(ColumnsPorts[Local_ColCount],ColumnsPins[Local_ColCount],LOW);
		for (Local_RowCount=0;Local_RowCount<4;Local_RowCount++)
		{
			local_PinVal=Read_Pin_Val(RowsPorts[Local_RowCount],RowsPins[Local_RowCount]);
			if (local_PinVal==LOW)
			{
				while (local_PinVal==LOW)
				{
					local_PinVal=Read_Pin_Val(RowsPorts[Local_RowCount],RowsPins[Local_RowCount]);
				}
				Local_uint8PressedKey = KeyPadValues[Local_RowCount][Local_ColCount];
				return Local_uint8PressedKey;
			}
			
		}
		Set_Pin_Val(ColumnsPorts[Local_ColCount],ColumnsPins[Local_ColCount],HIGH);
	}
	
	return Local_uint8PressedKey;
	
}
