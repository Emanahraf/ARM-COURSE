/*****************************************************************************************************************/
/* Author     : Eman ashraf                                                                                      */
/* version    : v01                                                                                              */
/* Date       : 12 August 2020                                                                                   */
/* Descrption :  Gpio  cofigration file                                                                          */ 
/*****************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "rcc_config.h"

void SEVENSEGEMEVT_voidDisplay (u8 copy_u8Port, u8 copy_u8Common,u8 copy_u8NUM )

{  /* ARRAY OF NUMBER FROM 0 TO 10 */
	 u8 NUM[]={0b001111111,0b0000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b01111111,0b01111111,0b01101111} ;
	switch(copy_u8Port)
	{
	case GPIOA :
         if(copy_u8Common==COMMON_CASODE)   /* CHECK IF COMMON_CASODE OR COMMON_ANODE*/
		 {
			 GPIOA_ODR=0 ;                   /* CLEAR BINS */
			 GPIOA_ODR= NUM[copy_u8NUM] ;  /* DISPLAY  NUMBER */
	
			 
		 }	else if(copy_u8Common==COMMON_ANODE ){
			 GPIOA_ODR=0 ;                   /* CLEAR BINS */
			 GPIOA_ODR=~NUM[copy_u8NUM] ; /* DISPLAY  NUMBER */
	
		 }
		 break ;
		
	}
	case GPIOB :
         if(copy_u8Common==COMMON_CASODE) /* CHECK IF COMMON_CASODE OR COMMON_ANODE*/
		 {
			 GPIOB_ODR=0 ;                   /* CLEAR BINS */
			 GPIOB_ODR= NUM[copy_u8NUM] ;  /* DISPLAY  NUMBER */
	
			 
		 }	else if(copy_u8Common==COMMON_ANODE ){
			 GPIOB_ODR=0 ;                  /* CLEAR BINS */
			 GPIOB_ODR=~NUM[copy_u8NUM] ; /* DISPLAY  NUMBER */
		 }
		 break ;
		
	}
	case GPIOC :
         if(copy_u8Common==COMMON_CASODE)
		 {
			 GPIOC_ODR=0 ;                   /* CLEAR BINS */
			 GPIOC_ODR= NUM[copy_u8NUM] ; /* DISPLAY  NUMBER */
		 }  
	
			 
		 }	else if(copy_u8Common==COMMON_ANODE ){
			 GPIOC_ODR=0 ;                   /* CLEAR BINS */
			 GPIOC_ODR=~NUM[copy_u8NUM] ; /* DISPLAY  NUMBER */
		 } 
		 }
		 break ;
		
	}
	
}