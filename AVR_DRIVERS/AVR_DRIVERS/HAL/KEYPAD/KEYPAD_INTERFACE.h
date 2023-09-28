/*==================================================================================*
 * File        : KEYPAD_INTERFACE.h     											*
 * Description : This file includes KEYPAD Driver prototypes and macros				*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H


#define  PRESSED        0
#define  RELEASED       1

/*Prototypes KEYPAD DRIVERS*/
void HKEYPAD_voidInit(void);
u8 HKEYPAD_u8GetPressedKey (void);

#endif
