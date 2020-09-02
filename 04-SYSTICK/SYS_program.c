/*****************************************************************************************************************/
/* Author     : Eman ashraf                                                                                      */
/* version    : v01                                                                                              */
/* Date       : 8 August 2020                                                                                    */
/* Descrption :                                                                                                  */                                                                             
/*****************************************************************************************************************/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYS_interface.h"
#include "SYS_private.h"
#include "SYS_config.h"
 /* define callback global varaible */
static void(*MSTK_CallBack)(void);

void MSTK_voidInit(void)
{
	#if CLOCK_SOURCE == MSTK_SRC_AHB
	/* disable stk - disable interrupt - set clock source AHB*/
	MSTK -> CTRL = 0X00000004;
	
    #elseif CLOCK_SOURCE == MSTK_SRC_AHB_8
	/* disable stk - disable interrupt - set clock source AHB /8*/
	MSTK -> CTRL = 0;
	
	#else 
        #error  ("wrong clock source type") 		

	#endif
	
}

void MSTK_voidSetBusyWait( u32 Copy_u32Ticks )
{
/* PUT ticks to load register */
MSTK -> LOAD = Copy_u32Ticks;
/* Enable timer   */
SET_BIT(MSTK -> CTRL , 0);
/* WAIT timer flag  */
while ( GET_BIT(MSTK -> CTRL,16)==0);


/* Stop timer   */

CLR_BIT(MSTK -> CTRL ,0);
MSTK -> LOAD = 0;
MSTK -> VAL =0;



	
}


void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
/* PUT ticks to load register */
MSTK -> LOAD = Copy_u32Ticks;
/* Enable timer   */
SET_BIT(MSTK -> CTRL , 0);

MSTK_CallBack = Copy_ptr;
  
  /*set mode to single interval */
MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
/*enable interrupt */
  
SET_BIT(MSTK->CTRL, 1);


}   




void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{ 

/* PUT ticks to load register */
MSTK -> LOAD = Copy_u32Ticks;
/* Enable timer   */
SET_BIT(MSTK -> CTRL , 0);

MSTK_CallBack = Copy_ptr;
  
  /*set mode to single interval */
MSTK_u8ModeOfInterval = MSTK_PERODIC_INTERVAL;
/*enable interrupt */
  
SET_BIT(MSTK->CTRL, 1);



}
void MSTK_voidStopInterval(void)
{
	/*Disable interrupt */
	CLR_BIT(MSTK->CTRL, 1);
    /* stop timer */
CLR_BIT(MSTK -> CTRL ,0);
MSTK -> LOAD = 0;
MSTK -> VAL =0;
	
}

u32  MSTK_u32GetElapsedTime(void)
{
	return  (MSTK -> LOAD) - (MSTK -> VAL) ;
}
u32  MSTK_u32GetRemainingTime(void)
{ 
return  (MSTK -> VAL)  ;

}



void SysTick_Handler(void)
{
	u8 Local_u8Temporary;
	
	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(MSTK->CTRL, 1);
	
		/* Stop Timer */
		CLR_BIT(MSTK->CTRL, 0);
		MSTK -> LOAD = 0;
		MSTK -> VAL  = 0;
	}
	
	/* Callback notification */
	MSTK_CallBack();
	
	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(MSTK->CTRL,16);
}
