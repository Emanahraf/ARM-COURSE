/*****************************************************************************************************************/
/* Author     : Eman ashraf                                                                                      */
/* version    : v01                                                                                              */
/* Date       : 12 August 2020                                                                                   */
/* Descrption :  NVIC  private  FILE                                                                             */ 
/*****************************************************************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H 

#define NVIC_ISER0       *((u32*)0xE000E100) /* Enable External interrupts from 0  to 31 */    
#define NVIC_ISER1       *((u32*)0xE000E104) /* Enable External interrupts from 32 to 63 */

#define NVIC_ICER0       *((u32*)0xE000E180) /* Disable External interrupts from 0  to 31 */
#define NVIC_ICER1       *((u32*)0xE000E184) /* Disable External interrupts from 32 to 63 */

#define NVIC_ISPR0       *((u32*)0xE000E200)
#define NVIC_ISPR1       *((u32*)0xE000E204)

#define NVIC_ICPR0       *((u32*)0xE000E280)
#define NVIC_ICPR1       *((u32*)0xE000E284)

#define NVIC_IABR0       *((volatile u32*)0xE000E300)
#define NVIC_IABR1       *((volatile u32*)0xE000E304)


#define NVIC_IPR              ((u32*)0xE000E400)

#define MNVIC_GROUP_4_SUB_0    0X05FA0300
#define MNVIC_GROUP_3_SUB_1    0X05FA0400
#define MNVIC_GROUP_2_SUB_2    0X05FA0500
#define MNVIC_GROUP_1_SUB_3    0X05FA0600
#define MNVIC_GROUP_0_SUB_4    0X05FA0700

#endif