#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../00-LIB/STD_TYPES.h"
#define  PRESSED        0
#define  RELEASED       1

void HKEYPAD_voidInitKeypad(void);
u8   HKEYPAD_u8ReadKeypad(void);



#endif 

/*
int main(void)
{
	u8 reading = 0;
	HKEYPAD_voidInitKeypad();
	HSSD_voidInitSsd();
	
	while (1)
	{
		HSSD_voidDisplaySsd(25);
		reading = HKEYPAD_u8ReadKeypad();
		while(reading != 0)
		{
			HSSD_voidDisplaySsd(reading - 48);
			reading=0;
		}
	}
}
*/