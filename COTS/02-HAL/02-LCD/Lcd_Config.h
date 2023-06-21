

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*select the number of data pins connected with LCD
 * 		options: 1-FOUR_BIT
 * 				 2-EIGHT_BIT                     */
#define EIGHT_BIT           1
#define FOUR_BIT            2


#define LCD_BIT_MODE           FOUR_BIT		
/*****************8bit Mode***********************/
#define		Data_Pin0				
#define		Data_Pin0_Port

#define		Data_Pin1
#define		Data_Pin1_Port

#define		Data_Pin2
#define		Data_Pin2_Port

#define		Data_Pin3
#define		Data_Pin3_Port
/***********4bit mode*************/
#define		Data_Pin4			PIN0
#define		Data_Pin4_Port		PORTB

#define		Data_Pin5			PIN1
#define		Data_Pin5_Port		PORTB

#define		Data_Pin6			PIN2
#define		Data_Pin6_Port		PORTB
	
#define		Data_Pin7			PIN4
#define		Data_Pin7_Port		PORTB


#define		RS					PIN3
#define		RS_Port				PORTA
					
#define		RW	
#define		RW_Port				
				
#define		EN					PIN2
#define		EN_Port				PORTA
				



#endif /* LCD_CONFIG_H_ */