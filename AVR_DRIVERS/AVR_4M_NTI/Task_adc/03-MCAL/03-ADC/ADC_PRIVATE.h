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

typedef struct
{
	u8  					 	: 5;
	u8  Auto_Trigger_Source 	: 3;
} SFIOR;

#define SFIOR_REG      ((SFIOR *)0x50)

typedef struct
{
	u8  ChannelNum 				  : 5;
	u8  ADJUST           		  : 1;
    u8  VOLTAGE_REFERENCE 		  : 2;
} ADMUX;

#define ADMUX_REG      ((ADMUX *)0x27)

typedef struct
{
	u8  PRESCALER_DIVISION_FACTOR 	: 3;
	u8  IntEnable 					: 1;
	u8  IntFalg 					: 1;
	u8  AutoTrigger 				: 1;
	u8  StartConversion 			: 1;
	u8  Enable 						: 1;
} ADCSRA;

#define ADCSRA_REG      ((ADCSRA *)0x26)

#define MADC_BASE_ADDRESS   0x24

typedef struct
{
  volatile u16 ADC_ADC_VALUE;
  volatile u8  ADC_ADCSRA;
  volatile u8  ADC_ADMUX;
} ADC;

#define MADC      ((ADC *)MADC_BASE_ADDRESS)

#endif
