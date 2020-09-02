/*****************************************************************************************************************/
/* Author     : Eman ashraf                                                                                      */
/* version    : v01                                                                                              */
/* Date       : 12 August 2020                                                                                   */
/* Descrption :  NVIC  PROGRAM  FILE                                                                             */ 
/*****************************************************************************************************************/

#include "STD_TYPES.h" 
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
 
 
 void MNVIC_VoidInit (void)
 {

#define SCB_AIRCR
SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIPTION ;
	 
 }
 
 
void MNVIC_VoidSetGroupPriority(u8 copy_u8PeripherailId,u8 copy_u8Priority )
{ 
if( copy_u8PeripherailId <60)
{
	 if (MNVIC_GROUP_SUB_DISTRIPTION==MNVIC_GROUP_4_SUB_0)
	 {
		 NVIC_IPR[copy_u8PeripherailId]= (copy_u8Priority <<4);
	 }
	 
	 else if (MNVIC_GROUP_SUB_DISTRIPTION==MNVIC_GROUP_3_SUB_1)
	 {
		 NVIC_IPR[copy_u8PeripherailId]= (copy_u8Priority <<5) ;
		 
	 }
	 else if (MNVIC_GROUP_SUB_DISTRIPTION==MNVIC_GROUP_2_SUB_2)
	 {
		 NVIC_IPR[copy_u8PeripherailId]= (copy_u8Priority <<6) ;
		 
	 }
	 
	 else if (MNVIC_GROUP_SUB_DISTRIPTION==MNVIC_GROUP_1_SUB_3)
	 {
		 NVIC_IPR[copy_u8PeripherailId]= (copy_u8Priority <<7) ;
		 
	 }
 
    else if (MNVIC_GROUP_SUB_DISTRIPTION==MNVIC_GROUP_0_SUB_4)
	 {
		 NVIC_IPR[copy_u8PeripherailId]=0 ;
		 
	 }
}
	else 
	{ 
     //error
	}
}
	
	
	
	
void MNVIC_VoidSetSubPriority(u8 copy_u8PeripherailId,u8 copy_u8Priority )
{ 
if( copy_u8PeripherailId <60)
{
	 
   if (MNVIC_GROUP_SUB_DISTRIPTION==MNVIC_GROUP_3_SUB_1)
	 {
		 NVIC_IPR[copy_u8PeripherailId]= (copy_u8Priority <<4) ;
		 
	 }
	 else if (MNVIC_GROUP_SUB_DISTRIPTION==MNVIC_GROUP_2_SUB_2)
	 {
		 NVIC_IPR[copy_u8PeripherailId]= (copy_u8Priority <<5) ;
		 
	 }
	 
	 else if (MNVIC_GROUP_SUB_DISTRIPTION==MNVIC_GROUP_1_SUB_3)
	 {
		 NVIC_IPR[copy_u8PeripherailId]= (copy_u8Priority <<6) ;
		 
	 }
 
    else if (MNVIC_GROUP_SUB_DISTRIPTION==MNVIC_GROUP_0_SUB_4)
	 {
		 NVIC_IPR[copy_u8PeripherailId]=(copy_u8Priority <<6) ;
		 
	 }
	 
	 else{  //error }
}
	else 
	{ 
     //error
	}
}
	


void MNVIC_VoidEnableInterrupt( u8 copy_u8InteruptId ) 
{
if ( copy_u8InteruptId <= 31)
	{
		NVIC_ISER0 = (1 << copy_u8InteruptId);
	}
	
	else if (  copy_u8InteruptId <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << copy_u8InteruptId);
	}
	
	else
	{
		/* Return Error */
	}
}





void MNVIC_VoidDisableInterrupt( u8 copy_u8InteruptId ) 
{
if ( copy_u8InteruptId <= 31)
	{
		NVIC_ISER0 = (1 << copy_u8InteruptId);
	}
	
	else if (  copy_u8InteruptId <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << copy_u8InteruptId);
	}
	
	else
	{
		/* Return Error */
	}
}

 void MNVIC_VoidSetPandingFlag( u8 copy_u8InteruptId ) 
{
if ( copy_u8InteruptId <= 31)
	{
		 NVIC_ISPR0   = (1 << copy_u8InteruptId);
	
	
	else if (  copy_u8InteruptId <= 59)
	{
		Copy_u8IntNumber -= 32;
		 NVIC_ISPR1 = (1 << copy_u8InteruptId);
	}
	
	else
	{
		/* Return Error */
	}
}

void MNVIC_VoidClearPandingFlag( u8 copy_u8InteruptId ) 
{
if ( copy_u8InteruptId <= 31)
	{
		  NVIC_ICPR0  = (1 << copy_u8InteruptId);
	
	
	else if (  copy_u8InteruptId <= 59)
	{
		Copy_u8IntNumber -= 32;
		  NVIC_ICPR1 = (1 << copy_u8InteruptId);
	}
	
	else
	{
		/* Return Error */
	}
}

	 

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result;
	
	if ( Copy_u8IntNumber <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}
	
	else
	{
		/* Return Error */
	}
	
	return Local_u8Result;
	
}




