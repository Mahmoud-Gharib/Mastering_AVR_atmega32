/*==================================================================================*
 * File        : STEPPER_INTERFACE.h     											*
 * Description : This file includes STEPPER Driver prototypes and macros			*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

#ifndef STEPPER_INTERFACE_H
#define STEPPER_INTERFACE_H


#define  CLOCKWISE        		0
#define  COUNTERCLOCKWISE       1

/*Prototypes STEPPER DRIVERS*/
void HSTEPPER_voidRotate (u8 Copy_u8MotorPortId, u8 Copy_u8FirstPinId, u8 Copy_u8Direction, u16 Copy_u16Angle);

#endif
