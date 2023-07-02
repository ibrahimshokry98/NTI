#ifndef WATCHDOG_INT_
#define WATCHDOG_INT_ 

/* Prescalers
0: 16K     (VCC = 3.0V) 17.1ms 	(VCC = 5.0V) 16.3ms
1: 32K 	   (VCC = 3.0V) 34.3ms 	(VCC = 5.0V) 32.5ms
2: 64K     (VCC = 3.0V) 68.5ms 	(VCC = 5.0V) 65ms
3: 128K    (VCC = 3.0V) 0.14s 	(VCC = 5.0V) 0.13s
4: 256K    (VCC = 3.0V) 0.27s 	(VCC = 3.0V) 0.26s
5: 512K    (VCC = 3.0V) 0.55s 	(VCC = 3.0V) 0.52s
6: 1,024K  (VCC = 3.0V) 1.1s 	(VCC = 3.0V) 1.0s
7: 2,048K  (VCC = 3.0V) 2.2s 	(VCC = 3.0V) 2.1s
*/
void WDT_Sleep(uint8 Prescaler);

void WDT_Enable(void);

void WDT_Disable(void);

#endif