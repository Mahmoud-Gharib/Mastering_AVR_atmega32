/************ LIB  **********/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/********** MCAL ***********/
#include "../MDIO/DIO_CONFIG.h"
#include "../MDIO/DIO_PRIVATE.h"
#include "../MDIO/DIO_INTERFACE.h"

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
	case DIO_PORTA:
		if(Copy_u8PinDirection == DIO_OUTPUT )
		{
			SET_BIT(DIO_DDRA_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinDirection == DIO_INPUT)
		{
			CLR_BIT(DIO_DDRA_REG,Copy_u8PinId);
		}
		break;
	case DIO_PORTB:
		if(Copy_u8PinDirection == DIO_OUTPUT )
		{
			SET_BIT(DIO_DDRB_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinDirection == DIO_INPUT)
		{
			CLR_BIT(DIO_DDRB_REG,Copy_u8PinId);
		}
		break;
	case DIO_PORTC:
		if(Copy_u8PinDirection == DIO_OUTPUT )
		{
			SET_BIT(DIO_DDRC_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinDirection == DIO_INPUT)
		{
			CLR_BIT(DIO_DDRC_REG,Copy_u8PinId);
		}
		break;
	case DIO_PORTD:
		if(Copy_u8PinDirection == DIO_OUTPUT )
		{
			SET_BIT(DIO_DDRD_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinDirection == DIO_INPUT)
		{
			CLR_BIT(DIO_DDRD_REG,Copy_u8PinId);
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
	case DIO_PORTA:
		if(Copy_u8PinValue == DIO_HIGH )
		{
			SET_BIT(DIO_PORTA_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinValue == DIO_LOW)
		{
			CLR_BIT(DIO_PORTA_REG,Copy_u8PinId);
		}
		break;
	case DIO_PORTB:
		if(Copy_u8PinValue == DIO_HIGH )
		{
			SET_BIT(DIO_PORTB_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinValue == DIO_LOW)
		{
			CLR_BIT(DIO_PORTB_REG,Copy_u8PinId);
		}
		break;
	case DIO_PORTC:
		if(Copy_u8PinValue == DIO_HIGH )
		{
			SET_BIT(DIO_PORTC_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinValue == DIO_LOW)
		{
			CLR_BIT(DIO_PORTC_REG,Copy_u8PinId);
		}
		break;
	case DIO_PORTD:
		if(Copy_u8PinValue == DIO_HIGH )
		{
			SET_BIT(DIO_PORTD_REG,Copy_u8PinId);
		}
		else if(Copy_u8PinValue == DIO_LOW)
		{
			CLR_BIT(DIO_PORTD_REG,Copy_u8PinId);
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
	case DIO_PORTA:
		DIO_DDRA_REG = Copy_u8PortDirection;
		break;
	case DIO_PORTB:
		DIO_DDRB_REG = Copy_u8PortDirection;
		break;
	case DIO_PORTC:
		DIO_DDRC_REG = Copy_u8PortDirection;
		break;
	case DIO_PORTD:
		DIO_DDRD_REG = Copy_u8PortDirection;
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
	case DIO_PORTA:
		DIO_PORTA_REG = Copy_u8PortValue;
		break;
	case DIO_PORTB:
		DIO_PORTB_REG = Copy_u8PortValue;
		break;
	case DIO_PORTC:
		DIO_PORTC_REG = Copy_u8PortValue;
		break;
	case DIO_PORTD:
		DIO_PORTD_REG = Copy_u8PortValue;
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
	case DIO_PORTA:
		Local_u8VALUE = GET_BIT(DIO_PINA_REG,Copy_u8PinId);
		break;
	case DIO_PORTB:
		Local_u8VALUE = GET_BIT(DIO_PINB_REG,Copy_u8PinId);
		break;
	case DIO_PORTC:
		Local_u8VALUE = GET_BIT(DIO_PINC_REG,Copy_u8PinId);
		break;
	case DIO_PORTD:
		Local_u8VALUE = GET_BIT(DIO_PIND_REG,Copy_u8PinId);
		break;
	default:

		break;
	}
	return Local_u8VALUE;
}
