/*==============================================================================*
 * File        : ADC_PRIVATE.h													*
 * Description : This file includes macros for ADC of Atmega32 					*
 * Author      : Mahmoud Gharib Embedded SW Engineer 							*
 * Date        : 																*
 * Git account : https://github.com/Mahmoud-Gharib								*
 * mail        : mahmoudgharib99999@gmail.com 									*
 *==============================================================================*/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define  SREG     (*((volatile u8*)0x5F))
/************************** ADC Registers macros ***************************/
#define ADMUX          (*((volatile u8*)0x27))
#define ADCSRA         (*((volatile u8*)0x26))
#define ADCL           (*((volatile u8*)0x24))
#define ADCH           (*((volatile u8*)0x25))
#define ADC_VALUE      (*((volatile u16*)0x24))

#endif
