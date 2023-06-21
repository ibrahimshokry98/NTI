

#ifndef EXT_INT1_INTERFACE_H_
#define EXT_INT1_INTERFACE_H_


void EXT_INT1_Enable(void);
void EXT_INT1_Disable(void);
void EXT_INT1_CallBack (void (*PF)(void));
void EXT_INT1_SenseControl (uint8 INT_Trigger);



#define FallingEdge		0
#define	RisingEdge		1
#define	Onchange		2
#define	LowLevel		3





#endif /* EXT_INT1_INTERFACE_H_ */