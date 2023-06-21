

#ifndef BITMATH_H_
#define BITMATH_H_

#define Set_Bit(REG,BIT)			(REG|=(1<<BIT))
#define Clear_Bit(REG,BIT)			(REG&=~(1<<BIT))
#define Toggle_Bit(REG,BIT)			(REG^=(1<<BIT))
#define Read_Bit(REG,BIT)			((REG>>BIT)&1)

#define Set_REG(REG)				(REG=0xFF)
#define Set_REG_Val(REG,REG_Val)	(REG=REG_Val)
#define Clear_REG(REG)				(REG=0x00)
#define Toggle_REG(REG)				(REG^=(0xFF))
#define Read_REG(REG)				(REG)


#endif /* BITMATH_H_ */

