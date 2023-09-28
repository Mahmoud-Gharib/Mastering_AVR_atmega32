/*==================================================================================*
 * File        : RTO_PROGRAM.c														*
 * Description : This file includes RTO Driver implementations for Atmega32     	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*		
 * Date        : 																	*		
 * Git account : https://github.com/Mahmoud-Gharib									*		
 * mail        : mahmoudgharib99999@gmail.com 										*		
 *==================================================================================*/

/********************* LIB ************************/
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

/**************** MCAL ***************/
#include "TIMERS_interface.h"

/**************** RTO ***************/
#include "RTO_CONFIG.h"
#include "RTO_PRIVATE.h"
#include "RTO_INTERFACE.h"

/*Array Of TCBs*/
RTO_TCB RTO_AstrTasks[RTO_u8_MAX_NUMBER_TASKS];

void RTO_voidInit(void)
{
	/*Set Call Back Func */
	TIMERS_u8Timer0CTCsetCallBack(&RTO_voidScheduler);
	/* Start Timer */
	TIMERS_voidTimerInit();
}

u8   RTO_u8CreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity,u16 Copy_u16FirstDelay,void (*Copy_pF)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	
	if (Copy_pF != NULL && Copy_u8Priority < RTO_u8_MAX_NUMBER_TASKS)
	{
		RTO_AstrTasks[Copy_u8Priority].FirstDelay = Copy_u16FirstDelay; 
		RTO_AstrTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
		RTO_AstrTasks[Copy_u8Priority].pF = Copy_pF;
		
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

static void RTO_voidScheduler(void)
{
	u8 Local_u8Counter;
	/* for LOOP to LOOP READY TASK */ 
	for(Local_u8Counter = 0 ; Local_u8Counter < RTO_u8_MAX_NUMBER_TASKS ; Local_u8Counter)
	{
		if( RTO_AstrTasks[ Local_u8Counter ].FirstDelay == 0)
		{
			/* Call Task */
			RTO_AstrTasks[Local_u8Counter].pF();
			/* Update for FirstDelay Value By Periodicity */
			RTO_AstrTasks[Local_u8Counter].FirstDelay = RTO_AstrTasks[ Local_u8Counter ].Periodicity - 1;
		}
		else
		{
			RTO_AstrTasks[ Local_u8Counter ].FirstDelay--;
		}
	}
}
