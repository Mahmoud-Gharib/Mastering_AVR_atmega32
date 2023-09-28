/*==============================================================================*
 * File        : RTO_PRIVATE.h													*
 * Description : This file includes macros of RTO Driver of Atmega32           	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 							*
 * Date        : 																*
 * Git account : https://github.com/Mahmoud-Gharib								*
 * mail        : mahmoudgharib99999@gmail.com 									*
 *==============================================================================*/
#ifndef RTO_PRIVATE_H_
#define RTO_PRIVATE_H_

typedef struct
{
	u16 FirstDelay;
	u16 Periodicity;
	void(*pF)(void);

}RTO_TCB;

static void RTO_voidScheduler(void);

#endif
