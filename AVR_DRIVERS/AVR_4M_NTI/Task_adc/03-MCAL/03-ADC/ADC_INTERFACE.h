/*==================================================================================*
 * File        : ADC_INTERFACE.h     												*
 * Description : This file includes ADC Driver prototypes and macros for Atmega32	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../00-LIB/STD_TYPES.h"

/*voltage reference macros*/
#define  AREF_PIN            0
#define  AVCC_PIN            1
#define  INTERNAL2V          3

/*Adjust*/
#define RIGHT_ADJUST         0
#define LEFT_ADJUST          1

/*Channel macros*/		     
#define  CHANNEL_0           0
#define  CHANNEL_1           1
#define  CHANNEL_2           2
#define  CHANNEL_3           3
#define  CHANNEL_4           4
#define  CHANNEL_5           5
#define  CHANNEL_6           6
#define  CHANNEL_7           7

/*PRESCALER macro*/		     
#define  DIVISION_BY_2		 1
#define  DIVISION_BY_4		 2
#define  DIVISION_BY_8       3
#define  DIVISION_BY_16      4
#define  DIVISION_BY_32		 5
#define  DIVISION_BY_64		 6
#define  DIVISION_BY_128	 7

/*CONVERSION_MODE macro*/	
#define  AUTO_TRIGGER_MODE         1
#define  SINGLE_CONVERSION_MODE    0

/*ADC Auto Trigger Source*/
#define  FREE_RUNNING_MODE     0
#define  ANALOG_COMPARATOR     1
#define  EXTERNAL_INT_0        2
#define  TIMER0_CTC			   3
#define  TIMER0_OV             4
#define  TIMER1_CTCB           5
#define  TIMER1_OV             6
#define  TIMER1_CE             7

/*MODE macro*/
#define  WITH_INTERRUPT         1
#define  WITHOUT_INTERRUPT      2

/*Prototypes ADC DRIVERS*/
void MADC_voidInit(void);
u16  MADC_u16GetDigitalValue(void);
void MADC_voidAdcStartConversion(u8 Copy_u8ChannelNum);
void MADC_voidAdcIntEnable(void);
void MADC_voidAdcIntDisable(void);
void MADC_Adc_SET_CALL_BACK(void(*)(void));


#endif
