/*****************************************************************************************************************/
/* Author     : Eman ashraf                                                                                      */
/* version    : v01                                                                                              */
/* Date       : 12 August 2020                                                                                   */
/* Descrption :    c file                                                                       */ 
/*****************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
 #include "DIO_interface.h"
#include "SYS_interface.h"
#include "LEDMXT_interface.h"

#include "LEDMXT_private.h"
#include "LEDMXT_config.h"


void HLEDMXT_voidInit(void)
{
	
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_ROW0_PIN ,OUTPUT_SPEED_2MHZ_PP);
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_ROW1_PIN ,OUTPUT_SPEED_2MHZ_PP);
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_ROW2_PIN ,OUTPUT_SPEED_2MHZ_PP);
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_ROW3_PIN ,OUTPUT_SPEED_2MHZ_PP);
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_ROW4_PIN ,OUTPUT_SPEED_2MHZ_PP);
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_ROW5_PIN ,OUTPUT_SPEED_2MHZ_PP);
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_ROW6_PIN ,OUTPUT_SPEED_2MHZ_PP);
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_ROW7_PIN ,OUTPUT_SPEED_2MHZ_PP);
 
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_COL0_PIN ,OUTPUT_SPEED_2MHZ_PP);
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_COL1_PIN ,OUTPUT_SPEED_2MHZ_PP);
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_COL2_PIN ,OUTPUT_SPEED_2MHZ_PP);
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_COL3_PIN ,OUTPUT_SPEED_2MHZ_PP);
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_COL4_PIN ,OUTPUT_SPEED_2MHZ_PP);
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_COL5_PIN ,OUTPUT_SPEED_2MHZ_PP);
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_COL6_PIN ,OUTPUT_SPEED_2MHZ_PP);
 MGPIO_VidSetPinDirection( GPIOA ,LEDMXT_COL7_PIN ,OUTPUT_SPEED_2MHZ_PP);
 
 
}




void HLEDMXT_voidDisplay(u8 *copy_u8Data)
{
	while(1){
	/* Disable all columns */
	
	DisableAllCloumns();
	   /* Set Rows value  */
		SetRowsValue(copy_u8Data[0]);
	/* Enable cloum 0 */
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL0_PIN ,LOW );
		MSTK_voidSetBusyWait(2500);
		 
	DisableAllCloumns();
    /* Set Rows value  */
		SetRowsValue(copy_u8Data[1]);	
	/* Enable cloum 1 */
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL1_PIN ,LOW );
		MSTK_voidSetBusyWait(2500);

	DisableAllCloumns();
    /* Set Rows value  */
		SetRowsValue(copy_u8Data[2]);	
	/* Enable cloum 2 */
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL2_PIN ,LOW );
		MSTK_voidSetBusyWait(2500);

      DisableAllCloumns();
     /* Set Rows value  */
		SetRowsValue(copy_u8Data[3]);	
	/* Enable cloum 3 */
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL3_PIN ,LOW );
		MSTK_voidSetBusyWait(2500);
		
      DisableAllCloumns();
     /* Set Rows value  */
		SetRowsValue(copy_u8Data[4]);	
	/* Enable cloum 4 */
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL4_PIN ,LOW );
		MSTK_voidSetBusyWait(2500);
		
		DisableAllCloumns();
		/* Set Rows value  */
		SetRowsValue(copy_u8Data[5]);	
	/* Enable cloum 5 */
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL5_PIN ,LOW );
		MSTK_voidSetBusyWait(2500);
		
	DisableAllCloumns();
	/* Set Rows value  */
		SetRowsValue(copy_u8Data[6]);	
	/* Enable cloum 6 */
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL7_PIN ,LOW );
		MSTK_voidSetBusyWait(2500);
		
    DisableAllCloumns();
   /* Set Rows value  */
		SetRowsValue(copy_u8Data[7]);	
	/* Enable cloum 7 */
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL7_PIN ,LOW );
		MSTK_voidSetBusyWait(2500);
	}
}
  
  
static void DisableAllCloumns(void)
{
	MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL0_PIN ,HIGH);
	MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL1_PIN ,HIGH);
	MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL2_PIN ,HIGH);
	MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL3_PIN ,HIGH);
    MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL4_PIN ,HIGH);
    MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL5_PIN ,HIGH);
    MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL6_PIN ,HIGH);
    MGPIO_VidSetPinValue(GPIOB ,LEDMXT_COL7_PIN ,HIGH);
}

static void SetRowsValue(u8 copy_u8Value)
{
		u8 Local_u8bit ;

	    Local_u8bit=GET_BIT(copy_u8Value,0);
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_ROW0_PIN ,Local_u8bit );
		
		 Local_u8bit=GET_BIT(copy_u8Value,1);
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_ROW1_PIN ,Local_u8bit );
		
		 Local_u8bit=GET_BIT(copy_u8Value,2);
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_ROW2_PIN ,Local_u8bit );
		
		 Local_u8bit=GET_BIT(copy_u8Value,3);
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_ROW3_PIN ,Local_u8bit );
		
		 Local_u8bit=GET_BIT(copy_u8Value,4);
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_ROW4_PIN ,Local_u8bit );
		
		 Local_u8bit=GET_BIT(copy_u8Value,5);
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_ROW5_PIN ,Local_u8bit );
		
		 Local_u8bit=GET_BIT(copy_u8Value,6);
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_ROW6_PIN ,Local_u8bit );
		
		 Local_u8bit=GET_BIT(copy_u8Value,7);
		MGPIO_VidSetPinValue(GPIOB ,LEDMXT_ROW7_PIN ,Local_u8bit );
}