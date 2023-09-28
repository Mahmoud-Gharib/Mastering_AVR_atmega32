/*==================================================================================*
 * File        : KEYPAD_PROGRAM.c													*
 * Description : This file includes KEYPAD Driver implementations 					*
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
#include "../../MCAL/DIO/DIO_INTERFACE.h"

/************ HAL **********/
#include "KEYPAD_CONFIG.h"
#include "KEYPAD_PRIVATE.h"
#include "KEYPAD_INTERFACE.h"

/* KEYPAD ARR 4*4 */
u8 arr[4][4] = {

		{'7', '8', '9', '/'},

		{'4', '5', '6', '*'},

		{'1', '2', '3', '-'},

		{'C', '0', '=', '+'}
};

/*==============================================================================*
 * Prototype   : void HKEYPAD_voidInit(void);									*
 * Description : Set initialization direction of KEYPAD							*
 * Arguments   : void			 												*
 * return      : void															*
 *==============================================================================*/
void HKEYPAD_voidInit(void)
{
	MDIO_voidSetPinDirection(KEYPAD_ROW_PORT,KEYPAD_R0,DIO_OUTPUT);
	MDIO_voidSetPinDirection(KEYPAD_ROW_PORT,KEYPAD_R1,DIO_OUTPUT);
	MDIO_voidSetPinDirection(KEYPAD_ROW_PORT,KEYPAD_R2,DIO_OUTPUT);
	MDIO_voidSetPinDirection(KEYPAD_ROW_PORT,KEYPAD_R3,DIO_OUTPUT);
	
	MDIO_voidSetPinValue(KEYPAD_ROW_PORT,KEYPAD_R0,DIO_HIGH);
	MDIO_voidSetPinValue(KEYPAD_ROW_PORT,KEYPAD_R1,DIO_HIGH);
	MDIO_voidSetPinValue(KEYPAD_ROW_PORT,KEYPAD_R2,DIO_HIGH);
	MDIO_voidSetPinValue(KEYPAD_ROW_PORT,KEYPAD_R3,DIO_HIGH);
	
	MDIO_voidSetPinDirection(KEYPAD_COL_PORT,KEYPAD_C0,DIO_INPUT);
	MDIO_voidSetPinDirection(KEYPAD_COL_PORT,KEYPAD_C1,DIO_INPUT);
	MDIO_voidSetPinDirection(KEYPAD_COL_PORT,KEYPAD_C2,DIO_INPUT);
	MDIO_voidSetPinDirection(KEYPAD_COL_PORT,KEYPAD_C3,DIO_INPUT);
}

/*==============================================================================*
 * Prototype   : u8 HKEYPAD_u8GetPressedKey (void);								*
 * Description : value of keypad												*
 * Arguments   : void					 										*
 * return      : value of keypad												*
 *==============================================================================*/
u8 HKEYPAD_u8GetPressedKey (void)
{
	u8 Local_u8Reading = 0;
	u8 Local_u8Row = 0;
	u8 Local_u8Col = 0;

	u8 Local_value = RELEASED;
	for (Local_u8Row = KEYPAD_R0 ; Local_u8Row <= KEYPAD_R3 ; Local_u8Row++)
	{
		MDIO_voidSetPinValue(KEYPAD_ROW_PORT,Local_u8Row,DIO_LOW);
		for (Local_u8Col = KEYPAD_C0 ; Local_u8Col <= KEYPAD_C3 ; Local_u8Col++)
		{
			Local_value = MDIO_u8GetPinValue(KEYPAD_COL_PORT,Local_u8Col);
			if(Local_value == PRESSED)
			{
				_delay_ms(120);
				Local_value = MDIO_u8GetPinValue(KEYPAD_COL_PORT,Local_u8Col);
				if(Local_value == PRESSED)
				{
					while(MDIO_u8GetPinValue(KEYPAD_COL_PORT,Local_u8Col) == PRESSED);
					Local_u8Reading = arr[Local_u8Row - KEYPAD_R0][Local_u8Col - KEYPAD_C0];
				}
			}
		}
		MDIO_voidSetPinValue(KEYPAD_ROW_PORT,Local_u8Row,DIO_HIGH);
	}
	return Local_u8Reading ;
}
