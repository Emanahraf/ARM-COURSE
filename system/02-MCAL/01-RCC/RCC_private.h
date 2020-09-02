/*****************************************************************************************************************/
/* Author  : Eman ashraf                                                                                         */
/* version : v01                                                                                                 */
/* Date    : 8 August 2020                                                                                       */ 
/*****************************************************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H
 /* register map */
#define RCC_CFGR       *((u32*)0x40021004)
#define RCC_CIR        *((u32*)0x40021008)
#define RCC_APB2RSTR   *((u32*)0x4002100C)
#define RCC_APB1RSTR   *((u32*)0x40021010)
#define RCC_AHBENR     *((u32*)0x40021014)
#define RCC_APB2ENR    *((u32*)0x40021018)
#define RCC_APB1ENR    *((u32*)0x4002101C)
#define RCC_BDCR       *((u32*)0x40021020)
#define RCC_CSR        *((u32*)0x40021024)



/* Clock Types */
#define RCC_HSE_CRYSTAL   0
#define RCC_HSE_RC        1
#define RCC_HSI           2
#define RCC_PLL           3


/*  PLL Types */
#define RCC_HSE_IN         0     
#define RCC_HSE_IN_DIV_2   1
#define RCC_HSI_IN_DIV_2   2


			           


#endif