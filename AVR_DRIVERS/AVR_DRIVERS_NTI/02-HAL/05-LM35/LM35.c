#include "../05-LM35/LM35.h"

#include "../../03-MCAL/03-ADC/ADC.h"
#include "../05-LM35/LM35_CFG.h"

void HLM35_voidInitLm35(void)
{
	MADC_voidInitAdc();
}

u32 HLM35_u32Lm35Read(void)
{
	MADC_voidAdcStartConversion(CHANNEL_0);
	u32 Adc_value = MADC_u16ReadAdc();
	u32 Lm35_value = (((Adc_value*500)/1023));
	return Lm35_value;
}


