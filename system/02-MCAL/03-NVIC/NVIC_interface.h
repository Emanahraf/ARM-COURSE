/*****************************************************************************************************************/
/* Author     : Eman ashraf                                                                                      */
/* version    : v01                                                                                              */
/* Date       : 12 August 2020                                                                                   */
/* Descrption :  NVIC  interface  FILE                                                                     */ 
/*****************************************************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H 



void MNVIC_VoidInit (void);
void MNVIC_VoidSetGroupPriority(u8 copy_u8PeripherailId,u8 copy_u8Priority );
void MNVIC_VoidSetSubPriority  (u8 copy_u8PeripherailId,u8 copy_u8Priority );
void MNVIC_VoidEnableInterrupt( u8 copy_u8InteruptId );
void MNVIC_VoidDisableInterrupt( u8 copy_u8InteruptId ) ;
void MNVIC_VoidSetPandingFlag( u8 copy_u8InteruptId ) ;
void MNVIC_VoidClearPandingFlag( u8 copy_u8InteruptId ) ;
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);





#endif