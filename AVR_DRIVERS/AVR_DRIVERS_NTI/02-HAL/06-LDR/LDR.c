#include "../06-LDR/LDR.h"

#include "../../03-MCAL/03-ADC/ADC.h"
#include "../06-LDR/LDR_CFG.h"

void HLDR_voidInitLDR(void)
{
	MADC_voidInitAdc();
}

u32 HLDR_u32LDRRead(void)
{
	MADC_voidAdcStartConversion(CHANNEL_1);
	u32 Adc_value = MADC_u16ReadAdc();
	u32 Lm35_value = (((Adc_value*100)/1023));
	return Lm35_value;
}


