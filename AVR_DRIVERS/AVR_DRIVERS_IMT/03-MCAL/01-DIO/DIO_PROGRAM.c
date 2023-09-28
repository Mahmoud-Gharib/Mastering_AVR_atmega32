/*==================================================================================*
 * File        : DIO_PROGRAM.c														*
 * Description : This file includes DIO Driver implementations for Atmega32     	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

/************ LIB  **********/
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

/************ MCAL **********/
#include "DIO_CONFIG.h"
#include "DIO_PRIVATE.h"
#include "DIO_INTERFACE.h"

/*============================================================================================================*
 * Prototype   : void MDIO_voidSetPinDirection (u8 Copy_u8PortId, u8 Copy_u8PinId ,u8 Copy_u8PinDirection);	  *
 * Description : Set direction of Pin in Port									     						  *
 * Arguments   : PORT 																						  *
 * 				 PIN															 							  *
 *               Direction : takes INPUT or OUTPUT															  *
 * return      : void																					      *
 *============================================================================================================*/
void MDIO_voidSetPinDirection (u8 Copy_u8PortId, u8 Copy_u8PinId ,u8 Copy_u8PinDirection)
{
	switch(Copy_u8PortId)
	{
	case DIO_u8_PORTA:
		if(Copy_u8PinDirection == DIO_u8_OUTPUT )
		{
			SET_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinDirection == DIO_u8_INPUT)
		{
			CLR_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);
		}
		break;
	case DIO_u8_PORTB:
		if(Copy_u8PinDirection == DIO_u8_OUTPUT )
		{
			SET_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinDirection == DIO_u8_INPUT)
		{
			CLR_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);
		}
		break;
	case DIO_u8_PORTC:
		if(Copy_u8PinDirection == DIO_u8_OUTPUT )
		{
			SET_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinDirection == DIO_u8_INPUT)
		{
			CLR_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);
		}
		break;
	case DIO_u8_PORTD:
		if(Copy_u8PinDirection == DIO_u8_OUTPUT )
		{
			SET_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinDirection == DIO_u8_INPUT)
		{
			CLR_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);
		}
		break;
	default:

		break;
	}
}

/*============================================================================================================*
 * Prototype   : void MDIO_voidSetPinValue     (u8 Copy_u8PortId, u8 Copy_u8PinId ,u8 Copy_u8PinValue);	  	  *
 * Description : Set LEVEL of Pin in Port										     						  *
 * Arguments   : PORT 																						  *
 * 				 PIN															 							  *
 *               Value : takes HIGH or LOW																	  *
 * return      : void																					      *
 *============================================================================================================*/
void MDIO_voidSetPinValue     (u8 Copy_u8PortId, u8 Copy_u8PinId ,u8 Copy_u8PinValue)
{
	switch(Copy_u8PortId)
	{
	case DIO_u8_PORTA:
		if(Copy_u8PinValue == DIO_u8_HIGH )
		{
			SET_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinValue == DIO_u8_LOW)
		{
			CLR_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);
		}
		break;
	case DIO_u8_PORTB:
		if(Copy_u8PinValue == DIO_u8_HIGH )
		{
			SET_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinValue == DIO_u8_LOW)
		{
			CLR_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);
		}
		break;
	case DIO_u8_PORTC:
		if(Copy_u8PinValue == DIO_u8_HIGH )
		{
			SET_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinValue == DIO_u8_LOW)
		{
			CLR_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);
		}
		break;
	case DIO_u8_PORTD:
		if(Copy_u8PinValue == DIO_u8_HIGH )
		{
			SET_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinValue == DIO_u8_LOW)
		{
			CLR_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);
		}
		break;
	default:

		break;
	}
}

/*============================================================================================================*
 * Prototype   : void MDIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection);	  	  			  *
 * Description : Set Direction of  Port												     					  *
 * Arguments   : PORT 																						  *
 *               Direction 																	  				  *
 * return      : void																					      *
 *============================================================================================================*/
void MDIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection)
{
	switch(Copy_u8PortId)
	{
	case DIO_u8_PORTA:
		DIO_u8_DDRA_REG = Copy_u8PortDirection;
		break;
	case DIO_u8_PORTB:
		DIO_u8_DDRB_REG = Copy_u8PortDirection;
		break;
	case DIO_u8_PORTC:
		DIO_u8_DDRC_REG = Copy_u8PortDirection;
		break;
	case DIO_u8_PORTD:
		DIO_u8_DDRD_REG = Copy_u8PortDirection;
		break;
	default:

		break;
	}
}

/*============================================================================================================*
 * Prototype   : void MDIO_voidSetPortValue    (u8 Copy_u8PortId, u8 Copy_u8PortValue);	  					  *
 * Description : Set LEVEL of  Port												     						  *
 * Arguments   : PORT 																						  *
 *               Value 																						  *
 * return      : void																					      *
 *============================================================================================================*/
void MDIO_voidSetPortValue    (u8 Copy_u8PortId, u8 Copy_u8PortValue)
{
	switch(Copy_u8PortId)
	{
	case DIO_u8_PORTA:
		DIO_u8_PORTA_REG = Copy_u8PortValue;
		break;
	case DIO_u8_PORTB:
		DIO_u8_PORTB_REG = Copy_u8PortValue;
		break;
	case DIO_u8_PORTC:
		DIO_u8_PORTC_REG = Copy_u8PortValue;
		break;
	case DIO_u8_PORTD:
		DIO_u8_PORTD_REG = Copy_u8PortValue;
		break;
	default:

		break;
	}
}

/*==========================================================================================================*
 * Prototype   : u8 MDIO_u8GetPinValue         (u8 Copy_u8PortId, u8 Copy_u8PinId);                       	*
 * Description : Read Pin Value																				*
 * Arguments   : PORT																					    *
 * 				 Pin 																						*
 * return      : Pin Value																					*
 *==========================================================================================================*/
u8 MDIO_u8GetPinValue         (u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	u8 Local_u8VALUE;
	switch(Copy_u8PortId)
	{
	case DIO_u8_PORTA:
		Local_u8VALUE = GET_BIT(DIO_u8_PINA_REG,Copy_u8PinId);
		break;
	case DIO_u8_PORTB:
		Local_u8VALUE = GET_BIT(DIO_u8_PINB_REG,Copy_u8PinId);
		break;
	case DIO_u8_PORTC:
		Local_u8VALUE = GET_BIT(DIO_u8_PINC_REG,Copy_u8PinId);
		break;
	case DIO_u8_PORTD:
		Local_u8VALUE = GET_BIT(DIO_u8_PIND_REG,Copy_u8PinId);
		break;
	default:

		break;
	}
	return Local_u8VALUE;
}
