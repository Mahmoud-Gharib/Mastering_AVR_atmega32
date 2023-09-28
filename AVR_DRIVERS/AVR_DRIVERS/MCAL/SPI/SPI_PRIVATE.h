/*==============================================================================*
 * File        : SPI_PRIVATE.h													*
 * Description : This file includes macros for SPI of Atmega32          	 	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 							*
 * Date        : 																*
 * Git account : https://github.com/Mahmoud-Gharib								*
 * mail        : mahmoudgharib99999@gmail.com 									*
 *==============================================================================*/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/***************************** SPI Registers macros **********************/
#define SPCR		(*((volatile u8*)0x2D))
#define SPSR		(*((volatile u8*)0x2E))
#define SPDR		(*((volatile u8*)0x2F))

#endif
