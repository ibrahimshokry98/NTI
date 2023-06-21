


#ifndef EXT_INT1_PRIVATE_H_
#define EXT_INT1_PRIVATE_H_


#define MCUCR_REG			*((vuint32_t*)0x55)
#define GICR_REG			*((vuint32_t*)0x5B)
#define GIFR_REG			*((vuint32_t*)0x5A)

#define INT1		7
#define INTF1		7
#define ISC10		2	
#define ISC11		3

#endif /* EXT_INT1_PRIVATE_H_ */