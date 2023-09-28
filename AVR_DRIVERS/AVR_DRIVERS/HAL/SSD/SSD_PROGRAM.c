/*==================================================================================*
 * File        : SSD_PROGRAM.c														*
 * Description : This file includes SSD Driver implementations 						*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

/************ LIB  **********/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/************ MCAL **********/
#include "../../MCAL/DIO/DIO_INTERFACE.h"

/************ HAL **********/
#include "SSD_CONFIG.h"
#include "SSD_PRIVATE.h"
#include "SSD_INTERFACE.h"

/*============================================================================================================*
 * Prototype   : void HSSD_voidDisplayNumber (u8 Copy_u8SSDPortId, u8 Copy_u8Number);	  	   				  *
 * Description : Display Number On SSD													     				  *
 * Arguments   : PORT 																						  *
 * 				 Number Display															 					  *
 * return      : void																					      *
 *============================================================================================================*/
void HSSD_voidDisplayNumber (u8 Copy_u8SSDPortId, u8 Copy_u8Number)
{
	MDIO_voidSetPortDirection( Copy_u8SSDPortId, 0xFF);

	switch(Copy_u8Number)
	{
	case 0:
		MDIO_voidSetPortValue(Copy_u8SSDPortId,0b00111111);
		break;
	case 1:
		MDIO_voidSetPortValue(Copy_u8SSDPortId,0b00000110);
		break;
	case 2:
		MDIO_voidSetPortValue(Copy_u8SSDPortId,0b01011011);
		break;
	case 3:
		MDIO_voidSetPortValue(Copy_u8SSDPortId,0b01001111);
		break;
	case 4:
		MDIO_voidSetPortValue(Copy_u8SSDPortId,0b01100110);
		break;
	case 5:
		MDIO_voidSetPortValue(Copy_u8SSDPortId,0b01101101);
		break;
	case 6:
		MDIO_voidSetPortValue(Copy_u8SSDPortId,0b01111101);
		break;
	case 7:
		MDIO_voidSetPortValue(Copy_u8SSDPortId,0b00000111);
		break;
	case 8:
		MDIO_voidSetPortValue(Copy_u8SSDPortId,0b01111111);
		break;
	case 9:
		MDIO_voidSetPortValue(Copy_u8SSDPortId,0b01101111);
		break;
	default:

		break;
	}
}
