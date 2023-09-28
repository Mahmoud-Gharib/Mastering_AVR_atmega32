/*==================================================================================*
 * File        : LCD_CFG.h  														*
 * Description :																   	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*		
 * Date        : 7/2/2022															*		
 * Git account : https://github.com/Mahmoud-Gharib									*		
 * mail        : mahmoudgharib99999@gmil.com 										*		
 *==================================================================================*/
#ifndef LCD_CFG_H_
#define LCD_CFG_H_
			/*==========================*
			* SELECT LCD MODE :			*
			*		1._4_BIT_MODE		*
			*		2._8_BIT_MODE		*
			*===========================*/

#define LCD_MODE _4_BIT_MODE

#define LCD_DATA_PORT    M_PORTD

#define LCD_DATA_PIN_4   PD0
#define LCD_DATA_PIN_5	 PD1
#define LCD_DATA_PIN_6	 PD2
#define LCD_DATA_PIN_7	 PD3

#define LCD_RS_PIN   PD6
#define LCD_EN_PIN   PD7

#endif 
