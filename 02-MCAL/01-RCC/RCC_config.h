/*****************************************************************************************************************/
/* Author  : Eman ashraf                                                                                         */
/* version : v01                                                                                                 */
/* Date    : 8 August 2020                                                                                       */ 
/*****************************************************************************************************************/
#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H
/* Options : RCC_HSE_CRYSTAL
             RCC_HSE_RC
			 RCC_HSI
			 RCC_PLL
*/
         
          
 
#define RCC_CLOCK_TYPE  RCC_HSE_CRYSTAL
 

/*if you choose pll option you should choose clock source first */
#if RCC_CLOCK_TYPE ==  RCC_PLL
#define RCC_PLL_INPUT  RCC_HSE_IN_DIV_2
#endif 
/*
 pll options :   RCC_HSE_IN
                 RCC_HSE_IN_DIV_2
			     RCC_HSI_IN_DIV_2
*/
define RCC_PLL_INPUT 

/*  option : 2 to 16 */
#if  RCC_CLOCK_TYPE ==  RCC_PLL
#define RCC_MUL_FACTOR     4

#endif