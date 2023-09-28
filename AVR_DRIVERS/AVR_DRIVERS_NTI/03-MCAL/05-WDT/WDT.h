#ifndef WDT_H_
#define WDT_H_

#include "../../00-LIB/STD_TYPES.h"

void MWDT_voidInitWDT(void);
void MWDT_voidRefreshWDT(void);

#endif 
/*
int main(void)
{
	HLED_voidInitLed(B_LED);
	MWDT_voidInitWDT();
	HLED_voidLedOn(B_LED);
	
	while(1)
	{
		MWDT_voidRefreshWDT();
		_delay_ms(1500);
	}
}
*/