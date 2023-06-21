

#include "STD_Types.h"
#include "BITMATH.h"
#include "DIO_int.h"

#include "SSInterface.h"



void SS_Init ( SSid* SSD )
{
	for (uint8 i=0;i<4;i++)
	{
		Set_Pin_Direction (SSD->SegPort,SSD->SegPin[i],OUTPUT);
		Set_Pin_Val (SSD->SegPort,SSD->SegPin[i],LOW);
	}
	Set_Pin_Direction (SSD->EnPort,SSD->EnPin,OUTPUT);
	Set_Pin_Val (SSD->SegPort,SSD->SegPin,HIGH);
	
}

void SS_Display ( SSid* SSD,uint8 Number)
{
	if (SSD->Common==Cathode)
	{
		switch (Number)
		{
			case Zero :
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],LOW);
				break;
			case One :
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],LOW);
				break;
			case Two :
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],LOW);
				break;
			case Three :
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],LOW);
				break;
			case Four :
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],LOW);
				break;
			case Five :
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],LOW);
				break;
			case Six :
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],LOW);
				break;
			case Seven :
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],LOW);
				break;
			case Eight :
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],HIGH);
				break;
			case Nine :
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],HIGH);
				break;								
		}
	}
	else if(SSD->Common==Anode)
	{
			switch (Number)
			{
				case Zero :
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],!LOW);
				break;									 
				case One :								 
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],!HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],!LOW);
				break;									 
				case Two :								 
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],!HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],!LOW);
				break;									
				case Three :							
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],!HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],!HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],!LOW);
				break;								
				case Four :							
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],!HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],!LOW);
				break;									
				case Five :								
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],!HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],!HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],!LOW);
				break;									 
				case Six :								 
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],!HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],!HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],!LOW);
				break;									 
				case Seven :							 
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],!HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],!HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],!HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],!LOW);
				break;									
				case Eight :							
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],!HIGH);
				break;									
				case Nine :								
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[0],!HIGH);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[1],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[2],!LOW);
				Set_Pin_Val (SSD->SegPort,SSD->SegPin[3],!HIGH);
				break;
			}
		
	}
}
void SS_Enable ( SSid* SSD )
{
	Set_Pin_Val (SSD->EnPort,SSD->EnPin,HIGH);
	
}
void SS_Disable ( SSid* SSD )
{
	Set_Pin_Val (SSD->EnPort,SSD->EnPin,LOW);
}