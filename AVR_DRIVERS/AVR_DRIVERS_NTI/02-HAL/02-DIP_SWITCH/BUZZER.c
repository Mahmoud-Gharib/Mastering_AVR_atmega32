/*==================================================================================*
 * File        : BUZZER.c															*
 * Description : This file includes BUZZER Driver implementations				    *
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*		
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*		
 * mail        : mahmoudgharib99999@gmail.com 										*		
 *==================================================================================*/
#include <util/delay.h>
#include "../../00-LIB/STD_TYPES.h"
#include "../../03-MCAL/01-DIO/DIO.h"
#include "BUZZER_CFG.h"
#include "BUZZER.h"
/*==============================================================================*
 * Prototype   : void HBUZZER_voidInitBuzzer(void);						    	*
 * Description : Set initialization direction of BUZZER							*
 * Arguments   : void															*
 * return      : void															*
 *==============================================================================*/
void HBUZZER_voidInitBuzzer(void)
{
	MDIO_voidSetDirectionPin(BUZZER_PIN,OUTPUT);
}
/*==============================================================================*
 * Prototype   : void HBUZZER_voidBUZZERState(void);							*
 * Description : Turn on and off BUZZER											*
 * Arguments   : void															*
 * return      : void															*
 *==============================================================================*/
void HBUZZER_voidBUZZERState(void)
{
	MDIO_voidSetLevelPin(BUZZER_PIN,HIGH);
	_delay_ms(3000);
	MDIO_voidSetLevelPin(BUZZER_PIN,LOW);
}
