/*****************************************************************************************************************/
/* Author     : Eman ashraf                                                                                      */
/* version    : v01                                                                                              */
/* Date       : 8 August 2020                                                                                    */
/* Descrption :                                                                                                  */                                                                             
/*****************************************************************************************************************/ 
#ifndef SYS_INTERFACE_H
#define SYS_INTERFACE_H

typedef struct 
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
}MSTK_TYPE;

#define MSTK ((MSTK_TYPE*)0xE000E010)
 
#define   MSTK_SRC_AHB             0
#define	  MSTK_SRC_AHB_8           1

#define MSTK_SINGLE_INTERVAL         0
#define MSTK_PERODIC_INTERVAL        1





#endf

