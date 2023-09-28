/*==================================================================================*
 * File        : STEPPER_PROGRAM.c													*
 * Description : This file includes STEPPER Driver implementations 					*
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
#include "STEPPER_CONFIG.h"
#include "STEPPER_PRIVATE.h"
#include "STEPPER_INTERFACE.h"

/*===================================================================================================================================*
 * Prototype   : void HSTEPPER_voidRotate (u8 Copy_u8MotorPortId, u8 Copy_u8FirstPinId, u8 Copy_u8Direction, u16 Copy_u16Angle);	 *					
 * Description : Set DIRECTION OF DCMOTOR , RUN it																					 *						
 * Arguments   : MotorPort, FirstPin, Direction	, Angle		 																		 *						
 * return      : void																												 *						
 *===================================================================================================================================*/
void HSTEPPER_voidRotate (u8 Copy_u8MotorPortId, u8 Copy_u8FirstPinId, u8 Copy_u8Direction, u16 Copy_u16Angle)
{
	u16 Local_u16Counter = 0;
	u16 Local_U16Revolution =(u16)((Copy_u16Angle * 2048UL) / (360 * 4));

	u8 Local_u8SecondPinID = Copy_u8FirstPinId + 1;
	u8 Local_u8ThirdPinID  = Copy_u8FirstPinId + 2;
	u8 Local_u8FourthPinID = Copy_u8FirstPinId + 3;
	
	MDIO_voidSetPinDirection(Copy_u8MotorPortId,Copy_u8FirstPinId,  DIO_OUTPUT);
	MDIO_voidSetPinDirection(Copy_u8MotorPortId,Local_u8SecondPinID,DIO_OUTPUT);
	MDIO_voidSetPinDirection(Copy_u8MotorPortId,Local_u8ThirdPinID, DIO_OUTPUT);
	MDIO_voidSetPinDirection(Copy_u8MotorPortId,Local_u8FourthPinID,DIO_OUTPUT);
	
	MDIO_voidSetPinValue(Copy_u8MotorPortId,Copy_u8FirstPinId,  DIO_HIGH);
	MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8SecondPinID,DIO_HIGH);
	MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8ThirdPinID, DIO_HIGH);
	MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8FourthPinID,DIO_HIGH);
	
	
	switch(Copy_u8Direction)
	{
		case CLOCKWISE:
		for(Local_u16Counter = 0; Local_u16Counter < Local_U16Revolution; Local_u16Counter++)
		{
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Copy_u8FirstPinId,  DIO_LOW);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8SecondPinID,DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8ThirdPinID, DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8FourthPinID,DIO_HIGH);
			_delay_ms(10);
			
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Copy_u8FirstPinId,  DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8SecondPinID,DIO_LOW);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8ThirdPinID, DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8FourthPinID,DIO_HIGH);
			_delay_ms(10);
			
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Copy_u8FirstPinId,  DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8SecondPinID,DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8ThirdPinID, DIO_LOW);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8FourthPinID,DIO_HIGH);
			_delay_ms(10);
			
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Copy_u8FirstPinId,  DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8SecondPinID,DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8ThirdPinID, DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8FourthPinID,DIO_LOW);
			_delay_ms(10);
		}
		break;
		case COUNTERCLOCKWISE:
		for(Local_u16Counter = 0; Local_u16Counter < Local_U16Revolution; Local_u16Counter++)
		{
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Copy_u8FirstPinId,  DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8SecondPinID,DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8ThirdPinID, DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8FourthPinID,DIO_LOW);
			_delay_ms(10);
			
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Copy_u8FirstPinId,  DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8SecondPinID,DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8ThirdPinID, DIO_LOW);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8FourthPinID,DIO_HIGH);
			_delay_ms(10);
			
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Copy_u8FirstPinId,  DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8SecondPinID,DIO_LOW);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8ThirdPinID, DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8FourthPinID,DIO_HIGH);
			_delay_ms(10);
			
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Copy_u8FirstPinId,  DIO_LOW);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8SecondPinID,DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8ThirdPinID, DIO_HIGH);
			MDIO_voidSetPinValue(Copy_u8MotorPortId,Local_u8FourthPinID,DIO_HIGH);
			_delay_ms(10);
		}
		break;
		default :
		
		break;	
	}	
}

