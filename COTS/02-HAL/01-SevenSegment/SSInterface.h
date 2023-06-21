


#ifndef INTERFACE_H_
#define INTERFACE_H_

#define SSZero		0b0000
#define SSOne		0b0001
#define SSTwo		0b0010
#define SSThree		0b0011
#define SSFour		0b0100
#define SSFive		0b0101
#define SSSex		0b0110
#define SSSeven		0b0111
#define SSEight		0b1000
#define SSNine		0b1001

#define Zero		0
#define One			1
#define Two			2
#define Three		3
#define Four		4
#define Five		5
#define Six			6
#define Seven		7
#define Eight		8
#define Nine		9

typedef struct{
	uint8 SegPort;
	uint8 SegPin[4];
	uint8 EnPort ;
	uint8 EnPin;
	uint8 Common;
}SSid;

void SS_Init ( SSid* SSD );
void SS_Display ( SSid* SSD,uint8 Number);

enum Common_Statue
{
	Anode,
	Cathode
	};


#endif /* INTERFACE_H_ */

