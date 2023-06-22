

#ifndef LCD_INT_H_
#define LCD_INT_H_

void LCD_voidInit(void);
void LCD_voidWriteChar(uint8 Copy_uint8Data);
void LCD_voidWriteSpecialCharacter(char* Copy_arruint8Pattern,uint8 Copy_uint8Block);
void LCD_voidDisplaySpecialCharacter(uint8 Copy_uint8Block);
void LCD_voidGoTOXY(uint8 Copy_uint8XPOS,uint8 Copy_uint8YPOS);
void LCD_voidSendCMD(uint8 Copy_uint8CMD);
void LCD_voidWriteString(const char* Copy_puint8Data);
void LCD_voidWriteInteger(sint32 Copy_sint32Data);
void LCD_voidWriteFloat(float64 Copy_f64FltNumber);

#define LCD_voidClearDisplay()		LCD_voidSendCMD(0x01)


#endif /* LCD_INT_H_ */