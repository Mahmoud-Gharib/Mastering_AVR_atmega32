//#define F_CPU 16000000UL
#include "../03-KEYPAD/KEYPAD.h"

#include <util/delay.h>
#include "../../03-MCAL/01-DIO/DIO.h"
#include "../03-KEYPAD/KEYPAD_CFG.h"

u8 arr[4][4] = {

		{'7', '8', '9', '/'},

		{'4', '5', '6', '*'},

		{'1', '2', '3', '-'},

		{'C', '0', '=', '+'}
};


void HKEYPAD_voidInitKeypad(void)
{
	MDIO_voidSetDirectionPin(KEY_PAD_R0,OUTPUT);
	MDIO_voidSetDirectionPin(KEY_PAD_R1,OUTPUT);
	MDIO_voidSetDirectionPin(KEY_PAD_R2,OUTPUT);
	MDIO_voidSetDirectionPin(KEY_PAD_R3,OUTPUT);
	
	MDIO_voidSetLevelPin(KEY_PAD_R0,HIGH);
	MDIO_voidSetLevelPin(KEY_PAD_R1,HIGH);
	MDIO_voidSetLevelPin(KEY_PAD_R2,HIGH);
	MDIO_voidSetLevelPin(KEY_PAD_R3,HIGH);
	
	MDIO_voidSetDirectionPin(KEY_PAD_C0,INPUT);
	MDIO_voidSetDirectionPin(KEY_PAD_C1,INPUT);
	MDIO_voidSetDirectionPin(KEY_PAD_C2,INPUT);
	MDIO_voidSetDirectionPin(KEY_PAD_C3,INPUT);
}
u8 HKEYPAD_u8ReadKeypad(void)
{	
	u8 Local_u8Reading = 0;
	u8 Local_u8Row = 0;
	u8 Local_u8Col = 0;

	u8 value = RELEASED;
	for (Local_u8Row = KEY_PAD_R0 ; Local_u8Row <= KEY_PAD_R3 ; Local_u8Row++)
	{
		MDIO_voidSetLevelPin(Local_u8Row,LOW);
		for (Local_u8Col = KEY_PAD_C0 ; Local_u8Col <= KEY_PAD_C3 ; Local_u8Col++)
		{
			value = MDIO_u8ReadValuePin(Local_u8Col);
			if(value == PRESSED)
			{
				_delay_ms(120);
				value = MDIO_u8ReadValuePin(Local_u8Col);
				if(value == PRESSED)
				{
					while(MDIO_u8ReadValuePin(Local_u8Col) == PRESSED);
					Local_u8Reading = arr[Local_u8Row - KEY_PAD_R0][Local_u8Col - KEY_PAD_C0];
				}
			}
		}
		MDIO_voidSetLevelPin(Local_u8Row,HIGH);
	}
	return Local_u8Reading ;
}

