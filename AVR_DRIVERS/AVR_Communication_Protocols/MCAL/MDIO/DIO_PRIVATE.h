#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/***************************** DIO Registers Macros **********************/
/*PORTA*/
#define DIO_PORTA_REG           *((volatile u8 *)0x3B)
#define DIO_DDRA_REG            *((volatile u8 *)0x3A)
#define DIO_PINA_REG            *((volatile u8 *)0x39)
/*PORTB*/
#define DIO_PORTB_REG           *((volatile u8 *)0x38)
#define DIO_DDRB_REG            *((volatile u8 *)0x37)
#define DIO_PINB_REG            *((volatile u8 *)0x36)
/*PORTC*/
#define DIO_PORTC_REG           *((volatile u8 *)0x35)
#define DIO_DDRC_REG            *((volatile u8 *)0x34)
#define DIO_PINC_REG            *((volatile u8 *)0x33)
/*PORTD*/
#define DIO_PORTD_REG           *((volatile u8 *)0x32)
#define DIO_DDRD_REG            *((volatile u8 *)0x31)
#define DIO_PIND_REG            *((volatile u8 *)0x30)

#endif



