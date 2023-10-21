/*==================================================================================*
 * File        : DIP_PROGRAM.c														*
 * Description : This file includes DIP SWITCH Driver implementations 				*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

/************ LIB  **********/
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

/************ MCAL **********/
#include "../../03-MCAL/01-DIO/DIO_INTERFACE.h"

/************ HAL **********/
#include "DIP_CONFIG.h"
#include "DIP_PRIVATE.h"
#include "DIP_INTERFACE.h"

void HSWITCH_voidInit  (void)
{
	MDIO_voidSetPinDirection (DIO_u8_PORTD , SWITCH_1 ,DIO_u8_INPUT);
	MDIO_voidSetPinDirection (DIO_u8_PORTD , SWITCH_2 ,DIO_u8_INPUT);
	MDIO_voidSetPinDirection (DIO_u8_PORTD , SWITCH_3 ,DIO_u8_INPUT);
	MDIO_voidSetPinDirection (DIO_u8_PORTD , SWITCH_4 ,DIO_u8_INPUT);
}

u8 HDIP_u8GetPressedKey  (u8 Copy_u8SwitchPinId)
{
	u8 Local_u8VALUE  = 0;
	switch(Copy_u8SwitchPinId)
	{
		case SWITCH_1_t:
			Local_u8VALUE = MDIO_u8GetPinValue(DIO_u8_PORTD , SWITCH_1);
			break;
		case SWITCH_2_t:
			Local_u8VALUE = MDIO_u8GetPinValue(DIO_u8_PORTD , SWITCH_2);			
			break;
		case SWITCH_3_t:
			Local_u8VALUE = MDIO_u8GetPinValue(DIO_u8_PORTD , SWITCH_3);			
			break;
		case SWITCH_4_t:
			Local_u8VALUE = MDIO_u8GetPinValue(DIO_u8_PORTD , SWITCH_4);			
			break;
		default :
			break;
	}
	return Local_u8VALUE;
}


