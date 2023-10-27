/*==================================================================================*
 * File        : KEYPAD_PROGRAM.c													*
 * Description : This file includes KEYPAD Driver implementations 					*
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
#include "../../03-MCAL/01-DIO/DIO_INTERFACE.h"

/************ HAL **********/
#include "KEYPAD_CONFIG.h"
#include "KEYPAD_PRIVATE.h"
#include "KEYPAD_INTERFACE.h"

/* KEYPAD ARR 4*4 */
u8 arr[4][4] = {

		{ 7 , 8 , 9 , '/'},

		{ 4 , 5 , 6 , '*'},

		{ 1 , 2 , 3 , '-'},

		{ 'C' , 0 , '=' , '+'}
};
u8 KeypadCol [4] = KEYPAD_COLs;
u8 KeypadRow [4] = KEYPAD_ROWs;
void HKEYPAD_voidInit(void)
{
	MDIO_voidSetPinDirection(KEYPAD_ROW_PORT,KeypadRow[0],DIO_u8_OUTPUT);
	MDIO_voidSetPinDirection(KEYPAD_ROW_PORT,KeypadRow[1],DIO_u8_OUTPUT);
	MDIO_voidSetPinDirection(KEYPAD_ROW_PORT,KeypadRow[2],DIO_u8_OUTPUT);
	MDIO_voidSetPinDirection(KEYPAD_ROW_PORT,KeypadRow[3],DIO_u8_OUTPUT);
	
	MDIO_voidSetPinValue(KEYPAD_ROW_PORT,KeypadRow[0],DIO_u8_HIGH);
	MDIO_voidSetPinValue(KEYPAD_ROW_PORT,KeypadRow[1],DIO_u8_HIGH);
	MDIO_voidSetPinValue(KEYPAD_ROW_PORT,KeypadRow[2],DIO_u8_HIGH);
	MDIO_voidSetPinValue(KEYPAD_ROW_PORT,KeypadRow[3],DIO_u8_HIGH);
	
	MDIO_voidSetPinDirection(KEYPAD_COL_PORT,KeypadCol[0],DIO_u8_INPUT);
	MDIO_voidSetPinDirection(KEYPAD_COL_PORT,KeypadCol[1],DIO_u8_INPUT);
	MDIO_voidSetPinDirection(KEYPAD_COL_PORT,KeypadCol[2],DIO_u8_INPUT);
	MDIO_voidSetPinDirection(KEYPAD_COL_PORT,KeypadCol[3],DIO_u8_INPUT);
}

u8 HKEYPAD_u8GetPressedKey (void)
{
	u8 Local_u8Reading = 0xFF;
	u8 Local_u8Row = 0;
	u8 Local_u8Col = 0;

	u8 Local_value = RELEASED;
	for (Local_u8Row = 0 ; Local_u8Row <= 3 ; Local_u8Row++)
	{
		MDIO_voidSetPinValue(KEYPAD_ROW_PORT,KeypadRow[Local_u8Row],DIO_u8_LOW);
		for (Local_u8Col = 0 ; Local_u8Col <= 3 ; Local_u8Col++)
		{
			Local_value = MDIO_u8GetPinValue(KEYPAD_COL_PORT,KeypadCol[Local_u8Col]);
			if(Local_value == PRESSED)
			{
				Local_value = MDIO_u8GetPinValue(KEYPAD_COL_PORT,KeypadCol[Local_u8Col]);
				if(Local_value == PRESSED)
				{
					Local_u8Reading = arr[Local_u8Row][Local_u8Col];
				}
			}
		}
		MDIO_voidSetPinValue(KEYPAD_ROW_PORT,KeypadRow[Local_u8Row],DIO_u8_HIGH);
	}
	return Local_u8Reading ;
}
