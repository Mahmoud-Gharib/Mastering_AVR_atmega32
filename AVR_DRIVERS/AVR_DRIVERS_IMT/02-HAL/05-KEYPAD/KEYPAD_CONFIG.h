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

#define KEYPAD_ROW_PORT    DIO_u8_PORTA
#define KEYPAD_COL_PORT    DIO_u8_PORTC

#define KEYPAD_R0 	DIO_u8_PIN4           
#define KEYPAD_R1	DIO_u8_PIN5
#define KEYPAD_R2	DIO_u8_PIN6
#define KEYPAD_R3	DIO_u8_PIN7

#define KEYPAD_C0   DIO_u8_PIN2           
#define KEYPAD_C1	DIO_u8_PIN3
#define KEYPAD_C2	DIO_u8_PIN4
#define KEYPAD_C3	DIO_u8_PIN5

#endif
