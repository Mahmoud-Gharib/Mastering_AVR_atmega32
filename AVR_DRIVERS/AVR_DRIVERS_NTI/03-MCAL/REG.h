/*==============================================================================*
 * File        : REG.h															*
 * Description : This file includes macros for Drivers of Atmega32           	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 							*
 * Date        : 1/2/2022														*
 * Git account : https://github.com/Mahmoud-Gharib								*
 * mail        : mahmoudgharib99999@gmil.com 									*
 *==============================================================================*/
#ifndef REG_H_
#define REG_H_

#include "../00-LIB/STD_TYPES.h"

/***************************** DIO Registers macros **********************/
/*PORTA*/
#define  PORTA    (*((volatile u8*)0x3B))
#define  DDRA     (*((volatile u8*)0x3A))
#define  PINA     (*((volatile u8*)0x39))
/*PORTB*/									
#define  PORTB    (*((volatile u8*)0x38))
#define  DDRB     (*((volatile u8*)0x37))
#define  PINB     (*((volatile u8*)0x36))
/*PORTC*/										
#define  PORTC    (*((volatile u8*)0x35))
#define  DDRC     (*((volatile u8*)0x34))
#define  PINC     (*((volatile u8*)0x33))
/*PORTD*/
#define  PORTD    (*((volatile u8*)0x32))
#define  DDRD     (*((volatile u8*)0x31))
#define  PIND     (*((volatile u8*)0x30))
/************************** EXT INT Registers macros ***************************/
#define  SREG     (*((volatile u8*)0x5F))
#define  MCUCR     (*((volatile u8*)0x55))
#define  GICR     (*((volatile u8*)0x5B))
/************************** ADC Registers macros ***************************/
#define ADMUX          (*((volatile u8*)0x27))
#define ADCSRA         (*((volatile u8*)0x26))
#define ADCL           (*((volatile u8*)0x24))
#define ADCH           (*((volatile u8*)0x25))
#define ADC_VALUE      (*((volatile u16*)0x24))
/************************** TIMER0 Registers macros ************************/
/*OVER_FLOW*/
#define TCCR0          (*((volatile u8*)0x53))
#define TIMSK          (*((volatile u8*)0x59))
/*CTC*/
#define OCR0          (*((volatile u8*)0x5C))
/*************************** WDT Registers macros **************************/
#define WDTCR         (*((volatile u8*)0x41))
/************************** TIMER1 Registers macros ************************/
#define TCCR1A               (*((volatile u8*)0x4F))
#define TCCR1B               (*((volatile u8*)0x4E))
#define OCR1A_VALUE          (*((volatile u16*)0x4A))
#define ICR1_VALUE           (*((volatile u16*)0x46))
/************************** USART Registers macros ************************/
#define UDR			(*((volatile u8*)0x2C))
#define UBRRH		(*((volatile u8*)0x40))
#define SPDR		(*((volatile u8*)0x29))
#define UCSRA		(*((volatile u8*)0x2B))
#define UCSRB		(*((volatile u8*)0x2A))
#define UCSRC		(*((volatile u8*)0x40))
/************************** SPI Registers macros ************************/
#define SPCR		(*((volatile u8*)0x2D))
#define SPSR		(*((volatile u8*)0x2E))
#define SPDR		(*((volatile u8*)0x2F))
/************************** I2C Registers macros ************************/
#define TWSR		(*((volatile u8*)0x21))
#define TWDR		(*((volatile u8*)0x23))
#define TWAR		(*((volatile u8*)0x22))
#define TWCR		(*((volatile u8*)0x56))
#define TWBR		(*((volatile u8*)0x20))

#endif
