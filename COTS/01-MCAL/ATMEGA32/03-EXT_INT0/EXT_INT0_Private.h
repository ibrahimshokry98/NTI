

#ifndef EXT_INT0_PRIVATE_H_
#define EXT_INT0_PRIVATE_H_


#define MCUCR_REG			*((vuint32_t*)0x55)
#define GICR_REG			*((vuint32_t*)0x5B)
#define GIFR_REG			*((vuint32_t*)0x5A)

#define INT0		6
#define INTF0		6
#define ISC00		0	
#define ISC01		1

#endif /* EXT_INT0_PRIVATE_H_ */