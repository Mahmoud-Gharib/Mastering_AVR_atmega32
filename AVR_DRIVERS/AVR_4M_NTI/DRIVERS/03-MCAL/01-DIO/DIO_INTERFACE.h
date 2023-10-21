/*==================================================================================*
 * File        : DIO_INTERFACE.h     												*
 * Description : This file includes DIO Driver prototypes and macros for Atmega32	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "../../00-LIB/STD_TYPES.h"

/* Macros for PORTS */
#define DIO_u8_PORTA             0
#define DIO_u8_PORTB             1
#define DIO_u8_PORTC             2
#define DIO_u8_PORTD             3

/* Macros for PINS */
#define DIO_u8_PIN0              0
#define DIO_u8_PIN1              1
#define DIO_u8_PIN2              2
#define DIO_u8_PIN3              3
#define DIO_u8_PIN4              4
#define DIO_u8_PIN5              5
#define DIO_u8_PIN6              6
#define DIO_u8_PIN7              7

/* Macros for Pin Direction */
#define DIO_u8_OUTPUT            1
#define DIO_u8_INPUT             0

/* Macros for Pin Value */
#define DIO_u8_HIGH              1
#define DIO_u8_LOW               0

/*Prototypes DIO DRIVERS*/
void MDIO_voidSetPinDirection (u8 Copy_u8PortId, u8 Copy_u8PinId ,u8 Copy_u8PinDirection);
void MDIO_voidSetPinValue     (u8 Copy_u8PortId, u8 Copy_u8PinId ,u8 Copy_u8PinValue);
void MDIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection);
void MDIO_voidSetPortValue    (u8 Copy_u8PortId, u8 Copy_u8PortValue);
u8 MDIO_u8GetPinValue         (u8 Copy_u8PortId, u8 Copy_u8PinId);

#endif
