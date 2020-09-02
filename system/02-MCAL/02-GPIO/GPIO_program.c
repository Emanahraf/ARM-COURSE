/*****************************************************************************************************************/
/* Author     : Eman ashraf                                                                                      */
/* version    : v01                                                                                              */
/* Date       : 12 August 2020                                                                                   */
/* Descrption :  Gpio  program  file                                                                             */ 
/*****************************************************************************************************************/
#include "STD_TYPES.h" 
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetBinDirction(u8 copy_u8Port ,u8 copy_u8Pin ,u8 copy_u8Mode){
	  switch(copy_u8Port)
	  {
		    case GPIOA :
	             if(copy_u8Pin <= 7)
				 {
					 GPIOB_CRL &=~((0b1111)      << (copy_u8Pin *4)) ;
					 GPIOB_CRL |= (copy_u8Mode) << (copy_u8Pin *4) ;
			     }
				 else if(copy_u8Pin <= 15)
				 {   copy_u8Pin= copy_u8Pin-8 ;
					 GPIOB_CRH &=~((0b1111)      << (copy_u8Pin *4)) ;
					 GPIOB_CRH |= (copy_u8Mode) << copy_u8Pin *4) ;
			     }
				 break ;
		    case GPIOB :
			    if(copy_u8Pin <= 7)
				 {
					 GPIOB_CRL &=~((0b1111)      << (copy_u8Pin *4)) ;
					 GPIOB_CRL |= (copy_u8Mode) << copy_u8Pin *4) ;
			     }
				 else if(copy_u8Pin <= 15)
				 {   copy_u8Pin= copy_u8Pin-8 ;
					 GPIOB_CRH &=~((0b1111)      << (copy_u8Pin *4)) ;
					 GPIOB_CRH |= (copy_u8Mode) << (copy_u8Pin *4) ;
			     }
				 break ;
		    case GPIOC :if(copy_u8Pin <= 7)
				 {
					 GPIOB_CRL &=~((0b1111)      << (copy_u8Pin *4)) ;
					 GPIOB_CRL |= (copy_u8Mode) << (copy_u8Pin *4) ;
			     }
				 else if(copy_u8Pin <= 15)
				 {   copy_u8Pin= copy_u8Pin-8 ;
					 GPIOB_CRH &=~((0b1111)      <<(copy_u8Pin *4)) ;
					 GPIOB_CRH |= (copy_u8Mode) << (copy_u8Pin *4) ;
			     }
				 break ;
			default:   /*error*/ break;
	  }
}
	  
	  void MGPIO_voidSetBinValue(u8 copy_u8Port ,u8 copy_u8Pin ,u8 copy_u8Value)
	  {
		  switch(copy_u8Port){
		  case GPIOA :
		       if( copy_u8Value==HIGH)
				 {
					SET_BIT(GPIOA_ODR , copy_u8Pin );
			     }
			   else if(copy_u8Value==LOW)
				 { 
			        CLR_BIT(GPIOA_ODR , copy_u8Pin ) ;
			     }
			   break ;
			 case GPIOB :
		       if( copy_u8Value==HIGH)
				 {
					SET_BIT(GPIOB_ODR , copy_u8Pin );
			     }
			   else if(copy_u8Value==LOW)
				 { 
			        CLR_BIT(GPIOB_ODR , copy_u8Pin ) ;
			     }
			   break ;
			 case GPIOC :
		       if( copy_u8Value==HIGH)
				 {
					SET_BIT(GPIOC_ODR , copy_u8Pin );
			     }
			   else if(copy_u8Value==LOW)
				 { 
			        CLR_BIT(GPIOC_ODR , copy_u8Pin ) ;
			     }
			   break ;
              default : /*  error */  break ;
              
		  }
	  }
u8  GPIO_voidSetBinDirction(u8 copy_u8Port ,u8 copy_u8Pin )
{  
 u8 loc_u8Result = 0 ;
 switch(copy_u8Port){
		  case GPIOA :
		       loc_u8Result=GET_BIT( GPIOA_IDR ,copy_u8Pin);
			   break ;
		  case GPIOB :
		       loc_u8Result=GET_BIT( GPIOB_IDR ,copy_u8Pin);
			   break ;
	      case GPIOC :
		       loc_u8Result=GET_BIT( GPIOC_IDR ,copy_u8Pin);
			   break ;
	
}
  return loc_u8Result ;
}

 void MGPIO_voidFastSetBinValue(u8 copy_u8Port ,u8 copy_u8Pin ,u8 copy_u8Value)
 {
	 switch(copy_u8Port){
		  case GPIOA :
		       if( copy_u8Value==HIGH)
				 {
					SET_BIT(GPIOA_BSRR , copy_u8Pin );
			     }
			   else if(copy_u8Value==LOW)
				 { 
			        CLR_BIT(GPIOA_BRR , copy_u8Pin ) ;
			     }
			   break ;
			 case GPIOB :
		       if( copy_u8Value==HIGH)
				 {
					SET_BIT(GPIOB_BSRR , copy_u8Pin );
			     }
			   else if(copy_u8Value==LOW)
				 { 
			        CLR_BIT(GPIOB_BRR, copy_u8Pin ) ;
			     }
			   break ;
			 case GPIOC :
		       if( copy_u8Value==HIGH)
				 {
					SET_BIT(GPIOC_BSRR , copy_u8Pin );
			     }
			   else if(copy_u8Value==LOW)
				 { 
			        CLR_BIT(GPIOC_BRR , copy_u8Pin ) ;
			     }
			   break ;
              default : /*  error */  break ;
              
		  }
 }
 
 
 void MGPIO_voidLockBinConfigration(u8 copy_u8Port ,u8 copy_u8Pin ,u8 copy_u8Mode)
 {
	 switch(copy_u8Port)
	  {
		    case GPIOA :
	             if(copy_u8Mode==LOCK)
				 {
					 
			     }
				 else if(copy_u8Mode==LOCK)
				 { 
			 
			     }
				 
				 break ;
		    case GPIOB :
			    if(copy_u8Pin <= 7)
				 {
					 
			     }
				 else if(copy_u8Pin <= 15)
				 {   
			 
			     }
				 break ;
		    case GPIOC :if(copy_u8Pin <= 7)
				 {
					
			     }
				 else if(copy_u8Pin <= 15)
				 {   
			     }
				 break ;
			default:   /*error*/ break;
	  }
 }