/*****************************************************************************************************************/
/* Author     : Eman ashraf                                                                                      */
/* version    : v01                                                                                              */
/* Date       : 8 August 2020                                                                                    */
/* Descrption :                                                                                                  */                                                                             
/*****************************************************************************************************************/ 
#ifndef SYS_INTERFACE_H
#define SYS_INTERFACE_H


void MSTK_voidInit(void);
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks );
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidStopInterval(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);





#endf
