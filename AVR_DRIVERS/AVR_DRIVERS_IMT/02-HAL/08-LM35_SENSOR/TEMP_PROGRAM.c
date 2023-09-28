/*==================================================================================*
 * File        : TEMP_PROGRAM.c														*
 * Description : This file includes TEMP SENSOR Driver implementations 				*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

/************ LIB  **********/
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include <util/delay.h>

/************ MCAL **********/
#include "../../03-MCAL/03-ADC/ADC_INTERFACE.h"

/************ HAL **********/
#include "TEMP_CONFIG.h"
#include "TEMP_PRIVATE.h"
#include "TEMP_INTERFACE.h"

/*==============================================================================*
 * Prototype   : void HTEMP_voidInit(void);										*
 * Description : Set initialization of TEMP Sensor								*
 * Arguments   : void			 												*
 * return      : void															*
 *==============================================================================*/
void HTEMP_voidInit(void)
{
	MADC_voidInit();
}

/*==============================================================================*
 * Prototype   : u8 HTEMP_u8GetAnalogTempreatureDegree (u8 Copy_u8ChannelNum);	*
 * Description : Read value of TEMP Sensor										*
 * Arguments   : Channel Number			 										*
 * return      : TEMP Value														*
 *==============================================================================*/
u8 HTEMP_u8GetAnalogTempreatureDegree (u8 Copy_u8ChannelNum)
{
	MADC_voidAdcStartConversion(Copy_u8ChannelNum);
	u16 Local_u16Adc_value = MADC_u16GetDigitalValue();
	u8 Local_u8Lm35_value = (((Local_u16Adc_value*500UL)/1023));
	return Local_u8Lm35_value;
}
