/*==================================================================================*
 * File        : SPI_INTERFACE.h     												*
 * Description : This file includes SPI Driver prototypes and macros for Atmega32	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H



/*********** MODES macros ***********/
#define MASTER   1
#define SLAVE    2

/*********** Prototypes SPI DRIVERS **************/
void MSPI_voidInit(void);
void MSPI_voidSendData(u8 Copy_u8Data);
u8   MSPI_u8ReciveData(void);
u8   MSPI_u8SendReciveData(u8 Copy_u8Data);

#endif
