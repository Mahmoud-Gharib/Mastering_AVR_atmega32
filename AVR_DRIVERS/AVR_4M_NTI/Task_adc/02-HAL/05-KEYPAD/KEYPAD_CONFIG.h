/*==================================================================================*
 * File        : KEYPAD_CONFIG.h  													*
 * Description :																   	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/
#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

#define KEYPAD_ROW_PORT    DIO_u8_PORTC
#define KEYPAD_COL_PORT    DIO_u8_PORTD

#define KEYPAD_ROWs  {DIO_u8_PIN5 , DIO_u8_PIN4 , DIO_u8_PIN3 , DIO_u8_PIN2}
#define KEYPAD_COLs  {DIO_u8_PIN7 , DIO_u8_PIN6 , DIO_u8_PIN5 , DIO_u8_PIN3 }

#endif
