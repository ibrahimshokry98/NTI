


#ifndef EXT_INT2_INTERFACE_H_
#define EXT_INT2_INTERFACE_H_


void EXT_INT2_Enable(void);
void EXT_INT2_Disable(void);
void EXT_INT2_CallBack (void (*PF)(void));
void EXT_INT2_SenseControl (uint8 INT_Trigger);


enum EXT_INT_Triggering {
	FallingEdge,
	RisingEdge,
	Onchange,
	LowLevel
};




#endif /* EXT_INT2_INTERFACE_H_ */