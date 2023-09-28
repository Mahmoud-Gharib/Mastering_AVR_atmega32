/*==================================================================================*
 * File        : UART_CONFIG.h  													*
 * Description :																   	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/
#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/* CHARACTER_SIZE OPTIONS ->  [  5,6,7,8,9  ]*/
#define CHARACTER_SIZE				8
/* PARITY_CHECK OPTIONS ->  [ ODD,EVEN, NON ]  */
#define  PARITY_CHECK               NON
/* STOP_BITS OPTIONS  [ 1, 2  ]         */
#define  STOP_BITS                  1
/* BUAD_RATE OPTIONS   [ 9600,115200,38400 ] */
#define BUAD_RATE                   9600

#endif
