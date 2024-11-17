/*
 * main.c
 *
 *  Created on: May 10, 2024
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "Port_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "Timers_interface.h"
#include "TIMER_reg.h"
#include "CLCD_interface.h"




uint16 u16PeriodTicks=0u;
uint16 u16OnTicks=0u;

void ICU_SW(void);

void main(void)
{

   PORT_voidInit();
   CLCD_voidInit();
   Timer0_voidInit();
   Timer0_voidSetCompareMatchValue(63);
    CLR_BIT(TCCR1A,TCCR1A_WGM10);
   	CLR_BIT(TCCR1A,TCCR1A_WGM11);
   	CLR_BIT(TCCR1A,TCCR1B_WGM12);
   	CLR_BIT(TCCR1A,TCCR1B_WGM13);
   	/*Clearing bits is very very important*/
   	TCCR1B &=0b11111000;
   	TCCR1B |=0b011;
   EXTI_VoidInit();
   //EXTI_u8EnableIntChannel(INT0);
   EXTI_u8SetCallBack(INT1,&ICU_SW );
   GIE_VoidEnableGlobal();

   while(1)
   {
      /*waiting until both reading is ready*/
	   while((u16PeriodTicks ==0)&&(u16OnTicks==0));
      CLCD_voidGoToXY(2,0);
      CLCD_voidSendNumber(u16OnTicks);
      CLCD_voidGoToXY(2,1);
      CLCD_voidSendNumber(u16PeriodTicks);
   }
}

void ICU_SW(void)
{

  volatile static uint8 Local_u16Counter=0u;
  Local_u16Counter++;
  if(Local_u16Counter == 1u)
  {
	  /*Make Timer =0*/
	 Timer1_u16SetValue(0);
	  //TCNT1=0u;
  }
  else if(Local_u16Counter == 2u)
  {
	  /*Read the timer --> period timer no of ticks*/
	  u16PeriodTicks = Timer1_u16GetTimerValue();
	  //CLCD_voidGoToXY(0,0);
	  //CLCD_voidSendNumber(TCNT1);
	  /*Convert the External interrupt trigger to falling edge*/
	  EXTI_u8SetSenseCtrl(INT1,FALLING_EDGE);
  }
  else
  {
    /*Read the timer in the following falling edge to get the on time*/
	  u16OnTicks = Timer1_u16GetTimerValue();
	  /*Subtract the period ticks from on ticks to get on time*/
	  u16OnTicks -=u16PeriodTicks;
	  /*Disable the external interrupt not the global interrupt*/
	  EXTI_u8DisableIntChannel(INT1);
	  /*For more than one time operation make the Local_u16Counter =0u*/
  }
}
