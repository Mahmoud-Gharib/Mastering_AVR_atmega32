/*==================================================================================*
 * File        : LDR_PROGRAM.c														*
 * Description : This file includes LDR SENSOR Driver implementations 				*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

/************ LIB  **********/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>

/************ MCAL **********/
/************ MCAL **********/
#include "../../MCAL/ADC/ADC_INTERFACE.h"

/************ HAL **********/
#include "LDR_CONFIG.h"
#include "LDR_PRIVATE.h"
#include "LDR_INTERFACE.h"

/*==============================================================================*
 * Prototype   : void HLDR_voidInit(void);										*
 * Description : Set initialization of LDR Sensor								*
 * Arguments   : void			 												*
 * return      : void															*
 *==============================================================================*/
void HLDR_voidInit(void)
{
	MADC_voidInit();
}

/*==============================================================================*
 * Prototype   : u16 HTEMP_u16GetAnalogLDRValue (u8 Copy_u8ChannelNum);			*
 * Description : Read value of LDR Sensor										*
 * Arguments   : Channel Number			 										*
 * return      : LDR Value														*
 *==============================================================================*/
u16 HTEMP_u16GetAnalogLDRValue (u8 Copy_u8ChannelNum)
{
	MADC_voidAdcStartConversion(Copy_u8ChannelNum);
	u16 Local_u16Adc_value = MADC_u16GetDigitalValue();
	u16 Local_u16LDR_value = (((Local_u16Adc_value*100UL)/1023));
	return Local_u16LDR_value;
}
