/*****************************************************************************************************************/
/* Author     : Eman ashraf                                                                                      */
/* version    : v01                                                                                              */
/* Date       : 12 August 2020                                                                                   */
/* Descrption :  Gpio  interface file                                                                            */ 
/*****************************************************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
/* GPIO STATUS  */

#define HIGH 1
#define LOW  0

/* GPIO PORTS*/

#define  GPIOA   0
#define  GPIOB   1
#define  GPIOC   2

/* PIN NUMBER */

#define  PIN0     0
#define  PIN1     1
#define  PIN2     2
#define  PIN3     3
#define  PIN4     4
#define  PIN5     5
#define  PIN6     6
#define  PIN7     7
#define  PIN8     8
#define  PIN9     9 
#define  PIN10    10
#define  PIN11    11
#define  PIN12    12
#define  PIN13    13
#define  PIN14    14
#define  PIN15    15

/* GPIO INPUT MODES */

#define INP_ANALOG              0b0000
#define INP_FLOATING            0b0100
#define INP_PULL_UP_DOWN        0b1000

/* GPIO OUTPUT MODES */

#define  OUT_SPEED_10MHZ_PP      0b0001
#define  OUT_SPEED_10MHZ_OD      0b0101
#define  OUT_SPEED_10MHZ_AFPP    0b1001
#define  OUT_SPEED_10MHZ_AFOD    0b1101

#define  OUT_SPEED_2MHZ_PP        0b0010
#define  OUT_SPEED_2MHZ_OD        0b0110
#define  OUT_SPEED_2MHZ_AFPP      0b1010
#define  OUT_SPEED_2MHZ_AFOD      0b1110

#define  OUT_SPEED_50MHZ_PP       0b0011
#define  OUT_SPEED_50MHZ_OD       0b0111
#define  OUT_SPEED_50MHZ_AFPP     0b1011
#define  OUT_SPEED_50MHZ_AFOD     0b1111

/* lock mode*/
#define LOCK      0
##define UNLOCK   1

void MGPIO_voidSetBinDirction(u8 copy_u8Port ,u8 copy_u8Pin ,u8 copy_u8Mode);

void MGPIO_voidSetBinValue(u8 copy_u8Port ,u8 copy_u8Pin ,u8 copy_u8Value);

u8  GPIO_voidSetBinDirction(u8 copy_u8Port ,u8 copy_u8Pin );
    


#endif