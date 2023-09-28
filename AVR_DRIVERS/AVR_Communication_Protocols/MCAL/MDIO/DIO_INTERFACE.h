#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "../../LIB/STD_TYPES.h"


/* Macros for PORTS */
#define DIO_PORTA             0
#define DIO_PORTB             1
#define DIO_PORTC             2
#define DIO_PORTD             3

/* Macros for PINS */
#define DIO_PIN0              0
#define DIO_PIN1              1
#define DIO_PIN2              2
#define DIO_PIN3              3
#define DIO_PIN4              4
#define DIO_PIN5              5
#define DIO_PIN6              6
#define DIO_PIN7              7

/* Macros for Pin Direction */
#define DIO_OUTPUT            1
#define DIO_INPUT             0

/* Macros for Pin Value */
#define DIO_HIGH              1
#define DIO_LOW               0

/*Prototypes DIO DRIVERS*/
void MDIO_voidSetPinDirection   (u8 Copy_u8PortId, u8 Copy_u8PinId ,u8 Copy_u8PinDirection);
void MDIO_voidSetPinValue       (u8 Copy_u8PortId, u8 Copy_u8PinId ,u8 Copy_u8PinValue);
void MDIO_voidSetPortDirection  (u8 Copy_u8PortId, u8 Copy_u8PortDirection);
void MDIO_voidSetPortValue      (u8 Copy_u8PortId, u8 Copy_u8PortValue);
u8   MDIO_u8GetPinValue         (u8 Copy_u8PortId, u8 Copy_u8PinId);

#endif
