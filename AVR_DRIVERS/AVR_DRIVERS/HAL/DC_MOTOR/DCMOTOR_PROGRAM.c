/*==================================================================================*
 * File        : DCMOTOR_PROGRAM.c													*
 * Description : This file includes DCMOTOR Driver implementations 					*
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
#include "DCMOTOR_CONFIG.h"
#include "DCMOTOR_PRIVATE.h"
#include "DCMOTOR_INTERFACE.h"

/*===================================================================================================================================================================*
 * Prototype   : void HDCMOTOR_voidRotateMotor (u8 Copy_u8MotorPort1, u8 Copy_u8MotorPinNo1,u8 Copy_u8MotorPort2, u8 Copy_u8MotorPinNo2, u8 Copy_u8MotorDirection);	 *
 * Description : Set DIRECTION OF DCMOTOR , RUN it																											         *
 * Arguments   : MotorPort, MotorPinNo1,MotorPinNo2, MotorDirection			 																						 *
 * return      : void																																				 *
 *===================================================================================================================================================================*/
void HDCMOTOR_voidRotateMotor (u8 Copy_u8MotorPort1, u8 Copy_u8MotorPinNo1,u8 Copy_u8MotorPort2, u8 Copy_u8MotorPinNo2, u8 Copy_u8MotorDirection)
{
	MDIO_voidSetPinDirection(Copy_u8MotorPort1,Copy_u8MotorPinNo1,DIO_OUTPUT);
	MDIO_voidSetPinDirection(Copy_u8MotorPort2,Copy_u8MotorPinNo2,DIO_OUTPUT);
	
	switch(Copy_u8MotorDirection)
	{
		case CLOCKWISE:
		MDIO_voidSetPinValue(Copy_u8MotorPort1,Copy_u8MotorPinNo1,DIO_HIGH);
		MDIO_voidSetPinValue(Copy_u8MotorPort2,Copy_u8MotorPinNo2,DIO_LOW);
		break;
		case COUNTERCLOCKWISE:
		MDIO_voidSetPinValue(Copy_u8MotorPort1,Copy_u8MotorPinNo1,DIO_LOW);
		MDIO_voidSetPinValue(Copy_u8MotorPort2,Copy_u8MotorPinNo2,DIO_HIGH);
		break;
		default :
		
		break;	
	}	
}

