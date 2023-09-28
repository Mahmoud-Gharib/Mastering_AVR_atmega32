
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include "../REG.h"
#include "WDT_CFG.h"
#include "WDT.h"


void MWDT_voidInitWDT(void)
{
	//Reset After 2.1 s
	 SET_BIT(WDTCR,0);
	 SET_BIT(WDTCR,1);
	 SET_BIT(WDTCR,2);
	// WDT Enable
	SET_BIT(WDTCR,3);
}

void MWDT_voidRefreshWDT(void)
{
	asm("WDR");
}