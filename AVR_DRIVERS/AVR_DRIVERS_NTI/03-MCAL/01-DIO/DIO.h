/*==================================================================================*
 * File        : DIO.h     														    *
 * Description : This file includes DIO Driver prototypes and macros for Atmega32	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*		
 * Date        : 1/2/2022															*		
 * Git account : https://github.com/Mahmoud-Gharib									*		
 * mail        : mahmoudgharib99999@gmail.com 										*		
 *==================================================================================*/

#ifndef DIO_H_
#define DIO_H_

#include "../../00-LIB/STD_TYPES.h"

/*Direction macros*/
#define OUTPUT      1
#define INPUT       0
/*Levels macros*/
#define LOW         0
#define HIGH        1
/*PullUp Resistor */
#define ENABLE      0
#define DISABLE     1
/*Ports macros*/
#define M_PORTA     1
#define M_PORTB     2
#define M_PORTC     3
#define M_PORTD     4
/*Pins macros*/	
/*Pins of PortA macros*/		    
#define PA0         10
#define PA1	        11
#define PA2	        12
#define PA3	        13
#define PA4	        14
#define PA5	        15
#define PA6	        16
#define PA7	        17
/*Pins of PortB macros*/				    
#define PB0         20
#define PB1	        21
#define PB2	        22
#define PB3	        23
#define PB4	        24
#define PB5	        25
#define PB6	        26
#define PB7	        27
/*Pins of PortC macros*/				    
#define PC0         30
#define PC1	        31
#define PC2	        32
#define PC3	        33
#define PC4	        34
#define PC5	        35
#define PC6	        36
#define PC7	        37
/*Pins of PortD macros*/	
#define PD0         40
#define PD1	        41
#define PD2	        42
#define PD3	        43
#define PD4	        44
#define PD5	        45
#define PD6	        46
#define PD7	        47
/*Prototypes DIO DRIVERS*/
void MDIO_voidSetDirectionPin(u8 Copy_u8Pin,u8 Copy_u8Status);
void MDIO_voidSetLevelPin(u8 Copy_u8Pin,u8 Copy_u8Value);
void MDIO_voidTogPin(u8 Copy_u8Pin);
u8 MDIO_u8ReadValuePin(u8 Copy_u8Pin);
void MDIO_voidPullUpPin(u8 Copy_u8Pin,u8 Copy_u8Status);

void MDIO_voidSetDirectionPort(u8 Copy_u8Port,u8 Copy_u8Status);
void MDIO_voidSetLevelPort(u8 Copy_u8Port,u8 Copy_u8Value);
void MDIO_voidTogPort(u8 Copy_u8Port);
u8 MDIO_u8ReadValuePort(u8 Copy_u8Port);


#endif 