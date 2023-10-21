/*==================================================================================*
 * File        : LCD_CONFIG.h  														*
 * Description :																   	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/*==========================*
* SELECT LCD MODE :			*
*		1._4_BIT_MODE		*
*		2._8_BIT_MODE		*
*===========================*/

#define LCD_MODE         	_4_BIT_MODE

#define LCD_DATA_PORT    	DIO_u8_PORTB

#define LCD_DATA_PIN_4   	DIO_u8_PIN0
#define LCD_DATA_PIN_5	 	DIO_u8_PIN1
#define LCD_DATA_PIN_6	 	DIO_u8_PIN2
#define LCD_DATA_PIN_7	 	DIO_u8_PIN4

#define LCD_CONTROL_PORT    DIO_u8_PORTA

#define LCD_RS_PIN       	DIO_u8_PIN3
#define LCD_EN_PIN       	DIO_u8_PIN2

#endif
