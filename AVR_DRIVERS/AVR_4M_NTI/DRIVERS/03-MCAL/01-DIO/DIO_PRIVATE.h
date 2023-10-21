/*==============================================================================*
 * File        : DIO_PRIVATE.h													*
 * Description : This file includes macros for DIO of Atmega32          	 	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 							*
 * Date        : 																*
 * Git account : https://github.com/Mahmoud-Gharib								*
 * mail        : mahmoudgharib99999@gmail.com 									*
 *==============================================================================*/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/***************************** DIO Registers macros **********************/
/*PORTA*/
#define DIO_u8_PORTA_REG           *((volatile u8 *)0x3B)
#define DIO_u8_DDRA_REG            *((volatile u8 *)0x3A)
#define DIO_u8_PINA_REG            *((volatile u8 *)0x39)
/*PORTB*/
#define DIO_u8_PORTB_REG           *((volatile u8 *)0x38)
#define DIO_u8_DDRB_REG            *((volatile u8 *)0x37)
#define DIO_u8_PINB_REG            *((volatile u8 *)0x36)
/*PORTC*/
#define DIO_u8_PORTC_REG           *((volatile u8 *)0x35)
#define DIO_u8_DDRC_REG            *((volatile u8 *)0x34)
#define DIO_u8_PINC_REG            *((volatile u8 *)0x33)
/*PORTD*/
#define DIO_u8_PORTD_REG           *((volatile u8 *)0x32)
#define DIO_u8_DDRD_REG            *((volatile u8 *)0x31)
#define DIO_u8_PIND_REG            *((volatile u8 *)0x30)

#endif
