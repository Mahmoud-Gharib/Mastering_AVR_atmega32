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


/*voltage reference macros*/
#define  AVCC_PIN            1
#define  AREF_PIN            2
#define  INTERNAL2V          3
						     
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
#define  DIVISION_BY_2		 2
#define  DIVISION_BY_4		 4
#define  DIVISION_BY_8       8
#define  DIVISION_BY_16      16
#define  DIVISION_BY_32		 32
#define  DIVISION_BY_64		 64
#define  DIVISION_BY_128	 128

/*CONVERSION_MODE macro*/	
#define  AUTO_TRIGGER_MODE         1
#define  SINGLE_CONVERSION_MODE    2

/*Prototypes ADC DRIVERS*/
void MADC_voidInit(void);
u16  MADC_u16GetDigitalValue(void);
void MADC_voidAdcStartConversion(u8 Copy_u8ChannelNum);
void MADC_voidAdcIntEnable(void);
void MADC_voidAdcIntDisable(void);
void MADC_Adc_SET_CALL_BACK(void(*)(void));


#endif
