/*==================================================================================*
 * File        : DIO.c																*
 * Description : This file includes DIO Driver implementations for Atmega32     	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*		
 * Date        : 1/2/2022															*		
 * Git account : https://github.com/Mahmoud-Gharib									*		
 * mail        : mahmoudgharib99999@gmil.com 										*		
 *==================================================================================*/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include "../REG.h"
#include "DIO.h"

/*==============================================================================*
 * Prototype   : void MDIO_voidSetDirectionPin(u8 Copy_u8Pin,u8 Copy_u8Status);	*
 * Description : Set direction of Pin in Port									*
 * Arguments   : Pin : takes Pin 												*
 *               Status : takes INPUT or OUTPUT									*
 * return      : void															*
 *==============================================================================*/
void MDIO_voidSetDirectionPin(u8 Copy_u8Pin,u8 Copy_u8Status)
{
	u8 Local_u8Pin = Copy_u8Pin % 10;
	u8 Local_u8PORT = Copy_u8Pin / 10;
	switch(Copy_u8Status)
	{
		case INPUT:
		switch(Local_u8PORT)
		{
			case M_PORTA:
			CLR_BIT(DDRA,Local_u8Pin);
			break;
			case M_PORTB:
			CLR_BIT(DDRB,Local_u8Pin);
			break;
			case M_PORTC:
			CLR_BIT(DDRC,Local_u8Pin);
			break;
			case M_PORTD:
			CLR_BIT(DDRD,Local_u8Pin);
			break;
			default:
			
			break;	
		}
		break;
		case OUTPUT:
		switch(Local_u8PORT)
		{
			case M_PORTA:
			SET_BIT(DDRA,Local_u8Pin);
			break;
			case M_PORTB:
			SET_BIT(DDRB,Local_u8Pin);
			break;
			case M_PORTC:
			SET_BIT(DDRC,Local_u8Pin);
			break;
			case M_PORTD:
			SET_BIT(DDRD,Local_u8Pin);
			break;
			default:
			
			break;
		}	
		break;
		default:
		
		break;
	}
}
/*==============================================================================*
 * Prototype   : void MDIO_voidSetLevelPin(u8 Copy_u8Pin,u8 Copy_u8Value);  	*
 * Description : Set Level of Pin in Port										*
 * Arguments   : Pin : takes Pin 												*
 *               Value : takes HIGH or LOW			     						*
 * return      : void															*
 *==============================================================================*/
void MDIO_voidSetLevelPin(u8 Copy_u8Pin,u8 Copy_u8Value)
{
	u8 Local_u8Pin = Copy_u8Pin % 10;
	u8 Local_u8PORT = Copy_u8Pin / 10;
	switch(Copy_u8Value)
	{
		case LOW:
		switch(Local_u8PORT)
		{
			case M_PORTA:
			CLR_BIT(PORTA,Local_u8Pin);
			break;
			case M_PORTB:
			CLR_BIT(PORTB,Local_u8Pin);
			break;
			case M_PORTC:
			CLR_BIT(PORTC,Local_u8Pin);
			break;
			case M_PORTD:
			CLR_BIT(PORTD,Local_u8Pin);
			break;
			default:
			
			break;
		}
		break;
		case HIGH:
		switch(Local_u8PORT)
		{
			case M_PORTA:
			SET_BIT(PORTA,Local_u8Pin);
			break;
			case M_PORTB:
			SET_BIT(PORTB,Local_u8Pin);
			break;
			case M_PORTC:
			SET_BIT(PORTC,Local_u8Pin);
			break;
			case M_PORTD:
			SET_BIT(PORTD,Local_u8Pin);
			break;
			default:
			
			break;
		}
		break;
		default:
		
		break;
	}
}
/*==============================================================================*
 * Prototype   : void MDIO_voidTogPin(u8 Copy_u8Pin);                       	*
 * Description : Set Toggle Pin in Port											*
 * Arguments   : Pin : takes Pin 												*
 * return      : void															*
 *==============================================================================*/
void MDIO_voidTogPin(u8 Copy_u8Pin)
{
	u8 Local_u8Pin = Copy_u8Pin % 10;
	u8 Local_u8PORT = Copy_u8Pin / 10;
	switch(Local_u8PORT)
	{
		case M_PORTA:
		TOG_BIT(PORTA,Local_u8Pin);
		break;
		case M_PORTB:
		TOG_BIT(PORTB,Local_u8Pin);
		break;
		case M_PORTC:
		TOG_BIT(PORTC,Local_u8Pin);
		break;
		case M_PORTD:
		TOG_BIT(PORTD,Local_u8Pin);
		break;
		default:
		
		break;
	}
}
/*==============================================================================*
 * Prototype   : u8 MDIO_u8ReadValuePin(u8 Copy_u8Pin);                       	*
 * Description : Read Pin Value													*
 * Arguments   : Pin : takes Pin 												*
 * return      : Pin Value														*
 *==============================================================================*/
u8 MDIO_u8ReadValuePin(u8 Copy_u8Pin)
{
	u8 Local_u8Value = 0;
	u8 Local_u8Pin = Copy_u8Pin % 10;
	u8 Local_u8PORT = Copy_u8Pin / 10;
	switch(Local_u8PORT)
	{
		case M_PORTA:
		Local_u8Value = GET_BIT(PINA,Local_u8Pin);
		break;
		case M_PORTB:
		Local_u8Value = GET_BIT(PINB,Local_u8Pin);
		break;
		case M_PORTC:
		Local_u8Value = GET_BIT(PINC,Local_u8Pin);
		break;
		case M_PORTD:
		Local_u8Value = GET_BIT(PIND,Local_u8Pin);
		break;
		default:
		
		break;
	}
	return Local_u8Value;
}
/*==============================================================================*
 * Prototype   : void MDIO_voidPullUpPin(u8 Copy_u8Pin,u8 Copy_u8Status);       *
 * Description : Enable Or Disable PullUp Resistor								*
 * Arguments   : Pin : takes Pin												*
 *               Status : takes ENABLE or DISABLE								*
 * return      : void															*
 *==============================================================================*/
void MDIO_voidPullUpPin(u8 Copy_u8Pin,u8 Copy_u8Status)
{
	u8 Local_u8Pin = Copy_u8Pin % 10;
	u8 Local_u8PORT = Copy_u8Pin / 10;
	switch(Copy_u8Status)
	{
		case DISABLE:
		switch(Local_u8PORT)
		{
			case M_PORTA:
			CLR_BIT(PORTA,Local_u8Pin);
			break;
			case M_PORTB:
			CLR_BIT(PORTB,Local_u8Pin);
			break;
			case M_PORTC:
			CLR_BIT(PORTC,Local_u8Pin);
			break;
			case M_PORTD:
			CLR_BIT(PORTD,Local_u8Pin);
			break;
			default:
			
			break;
		}
		break;
		case ENABLE:
		switch(Local_u8PORT)
		{
			case M_PORTA:
			SET_BIT(PORTA,Local_u8Pin);
			break;
			case M_PORTB:
			SET_BIT(PORTB,Local_u8Pin);
			break;
			case M_PORTC:
			SET_BIT(PORTC,Local_u8Pin);
			break;
			case M_PORTD:
			SET_BIT(PORTD,Local_u8Pin);
			break;
			default:
			
			break;
		}
		break;
		default:
		
		break;
	}
	
}
/*==================================================================================*
 * Prototype   : void MDIO_voidSetDirectionPort(u8 Copy_u8Port,u8 Copy_u8Status);	*
 * Description : Set direction of Port											    *
 * Arguments   : Port : takes Port 												    *
 *               Status : takes INPUT or OUTPUT									    *
 * return      : void															    *
 *==================================================================================*/
void MDIO_voidSetDirectionPort(u8 Copy_u8Port,u8 Copy_u8Status)
{
	u8 Local_u8PORT = Copy_u8Port / 10;
	switch(Copy_u8Status)
	{
		case INPUT:
		switch(Local_u8PORT)
		{
			case M_PORTA:
			DDRA = 0x00;
			break;
			case M_PORTB:
			DDRB = 0x00;
			break;
			case M_PORTC:
			DDRC = 0x00;
			break;
			case M_PORTD:
			DDRD = 0x00;
			break;
			default:
			
			break;
		}
		break;
		case OUTPUT:
		switch(Local_u8PORT)
		{
			case M_PORTA:
			DDRA = 0xFF;
			break;
			case M_PORTB:
			DDRB = 0xFF;
			break;
			case M_PORTC:
			DDRC = 0xFF;
			break;
			case M_PORTD:
			DDRD = 0xFF;
			break;
			default:
			
			break;
		}
		break;
		default:
		
		break;
	}
}
/*==============================================================================*
 * Prototype   : void MDIO_voidSetLevelPort(u8 Copy_u8Port,u8 Copy_u8Value);  	*
 * Description : Set Level of Port												*
 * Arguments   :Port : takes Port 												*
 *               Value : takes HIGH or LOW			     						*
 * return      : void															*
 *==============================================================================*/
void MDIO_voidSetLevelPort(u8 Copy_u8Port,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case M_PORTA:
		PORTA = Copy_u8Value;
		break;
		case M_PORTB:
		PORTB = Copy_u8Value;
		break;
		case M_PORTC:
		DDRC = Copy_u8Value;
		break;
		case M_PORTD:
		PORTD = Copy_u8Value;
		break;
		default:
		break;
	}
}
/*==============================================================================*
 * Prototype   : void MDIO_voidTogPort(u8 Copy_u8Port);                       	*
 * Description : Set Toggle Port												*
 * Arguments   : Port : takes Port 												*
 * return      : void															*
 *==============================================================================*/
void MDIO_voidTogPort(u8 Copy_u8Port)
{
	switch(Copy_u8Port)
	{
		case M_PORTA:
		PORTA ^= 255;
		break;
		case M_PORTB:
		PORTB ^= 255;
		break;
		case M_PORTC:
		PORTC ^= 255;
		break;
		case M_PORTD:
		PORTD ^= 255;
		break;
		default:
		
		break;
	}
}
/*==============================================================================*
 * Prototype   : u8 MDIO_u8ReadValuePort(u8 Copy_u8Port);                      	*
 * Description : Read Port Value												*
 * Arguments   : Port : takes Port 												*
 * return      : Port Value														*
 *==============================================================================*/
u8 MDIO_u8ReadValuePort(u8 Copy_u8Port)
{
	u8 Local_u8Value = 0;
	switch(Copy_u8Port)
	{
		case M_PORTA:
		Local_u8Value = PINA;
		break;
		case M_PORTB:
		Local_u8Value = PINB;
		break;
		case M_PORTC:
		Local_u8Value = PINC;
		break;
		case M_PORTD:
		Local_u8Value = PIND;
		break;
		default:
		
		break;
	}
	return Local_u8Value;
}


