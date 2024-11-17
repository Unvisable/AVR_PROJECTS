/*
 * main.c
 *
 *  Created on: Feb 29, 2024
 *      Author: user
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"util/delay.h"
#include"Port_interface.h"
#include"DIO_interface.h"
#include"EXTI_interface.h"
#include"GIE_interface.h"
void INT0_Func(void);
void INT1_Func(void);
void main(void)
{
  PORT_voidInit();
  EXTI_VoidInit();
  EXTI_u8SetCallBack(INT0, &INT0_Func);
  EXTI_u8SetCallBack(INT1, &INT1_Func);
  GIE_VoidEnableGlobal();
 while(1)
 {
	 DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
	 _delay_ms(100);
	 DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
	 	 _delay_ms(100);
 }



}

void INT0_Func(void)
{
	  DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
}
void INT1_Func(void)
{
	  DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
}

