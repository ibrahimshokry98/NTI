


#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_


#define LCD_LINE1_BASE            	0x80
#define LCD_LINE2_BASE			  	0xC0
#define LCD_LINE3_BASE				0x94
#define LCD_LINE4_BASE				0xD4


typedef struct {
	uint8 bit0:1;
	uint8 bit1:1;
	uint8 bit2:1;
	uint8 bit3:1;
	uint8 bit4:1;
	uint8 bit5:1;
	uint8 bit6:1;
	uint8 bit7:1;
}Bits_Val;


typedef union {
	uint8 All_Byte ;
	Bits_Val Bits ;
}Data_t;

#endif /* LCD_PRIV_H_ */