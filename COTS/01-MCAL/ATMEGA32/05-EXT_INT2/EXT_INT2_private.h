


#ifndef EXT_INT2_PRIVATE_H_
#define EXT_INT2_PRIVATE_H_


#define MCUCSR_REG			*((vuint32_t*)0x54)
#define GICR_REG			*((vuint32_t*)0x5B)
#define GIFR_REG			*((vuint32_t*)0x5A)

#define INT2		5
#define INTF2		5	
#define ISC2		6

#endif /* EXT_INT2_PRIVATE_H_ */