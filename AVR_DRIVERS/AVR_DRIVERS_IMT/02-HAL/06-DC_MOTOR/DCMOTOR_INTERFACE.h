/*==================================================================================*
 * File        : DCMOTOR_INTERFACE.h     											*
 * Description : This file includes DCMOTOR Driver prototypes and macros			*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

#ifndef DCMOTOR_INTERFACE_H
#define DCMOTOR_INTERFACE_H

#include "../../00-LIB/STD_TYPES.h"

#define  CLOCKWISE        		0
#define  COUNTERCLOCKWISE       1

/*Prototypes DCMOTOR DRIVERS*/
void HDCMOTOR_voidRotateMotor (u8 Copy_u8MotorPort1, u8 Copy_u8MotorPinNo1,u8 Copy_u8MotorPort2, u8 Copy_u8MotorPinNo2, u8 Copy_u8MotorDirection);

#endif
