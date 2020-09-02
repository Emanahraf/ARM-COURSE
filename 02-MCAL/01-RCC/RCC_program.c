/*****************************************************************************************************************/
/* Author     : Eman ashraf                                                                                      */
/* version    : v01                                                                                              */
/* Date       : 8 August 2020                                                                                    */
/* Descrption :                                                                                                  */                                                                             
/*****************************************************************************************************************/  
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "rcc_config.h"

void RCC_voidInitSydtemClock (void)
{
	#if  RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	   
	     RCC_CR   =  0x00010000 ;    /* enable HSE with by pass */
		 RCC_CFGR =  0x00000001 ;
	
	#elif  RCC_CLOCK_TYPE == RCC_HSE_RC
	     RCC_CR   =  0x00050000 ;    /* enable HSE with  no by pass */
		 RCC_CFGR =  0x00000001 ;
        
	#elif RCC_CLOCK_TYPE == RCC_HSI
		 RCC_CR   =  0x00000081 ;     /* enable HSI  */
		 RCC_CFGR =  0x00000000 ;
		 
    #elif RCC_CLOCK_TYPE == RCC_PLL
	      RCC_CFGR &= ~(15 << 18);           /* clear four bit for mutipcation */
          RCC_CFGR |= (RCC_PLL_MUL << 18);   /* load  four bit for mutipcation */
	      SET_BIT(RCC_CR ,24) ;        /* enable pll */
		  SET_BIT(RCC_CFGR ,1);        /* enable pll AS system clock */
		  CLR_BIT(RCC_CFGR ,0) ;       /* enable pll AS system clock */
		  
	    #if  RCC_PLL_INPUT  ==    RCC_HSE_IN_DIV_2
	       
	        
		      SET_BIT(RCC_CR   ,16) ;      /* ENABLE HSE bit                */
		      SET_BIT(RCC_CFGR ,16) ;    /* ENABLE HSE as pll input source*/
			  SET_BIT(RCC_CFGR ,17);     /* enable HSE divied by 2        */
		     
		#elif RCC_PLL_INPUT  ==   RCC_HSI_IN_DIV_2 
		      SET_BIT(RCC_CR ,0) ;      /* ENABLE HSI bit                */
		      SET_BIT(RCC_CR ,7) ;      /* no Triming                */
              CLR_BIT(RCC_CR ,16) ;		/* ENABLE HSI AS pLL input source */	  
		
		#elif RCC_PLL_INPUT   ==   RCC_HSE_IN 
		     
		     
		      SET_BIT(RCC_CR ,16) ;      /* ENABLE HSE bit                */
		      SET_BIT(RCC_CFGR ,16) ;    /* ENABLE HSE as pll input source*/
			  CLR_BIT(RCC_CFGR ,17);     /* enable HSE not divied by 2        */
	    #else
	    #error(" you Choosed Wrong pll type ")
	
	    #endif
			   
	#else
		#error(" you Choosed Wrong Clock type ")
	
	#endif
	
}

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
		}
	}
	
	else
	{
		/* Return Error */
	}

}


void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
		}
	}
	
	else
	{
		/* Return Error */
	}

}
