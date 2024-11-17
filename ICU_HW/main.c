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


volatile static uint32 u16PeriodTicks=0u;
volatile static uint32 u16OnTicks=0u;
volatile static uint32 u16Reading1=0u;
volatile static uint32 u16Reading2=0u;
volatile static uint32 u16Reading3=0u;
volatile static uint32 u16Reading4=0u;
void ICU_HW(void);
void main(void)
{

   PORT_voidInit();
   CLCD_voidInit();
   Timer0_voidInit();
   Timer1_voidInit();
   Timer0_voidSetCompareMatchValue(63u);
   Timer_u8SetCallBack(Timer1_ICR_INT,&ICU_HW);
   Timer_u8SetCallBack(Timer0_OVF_INT,&ICU_HW);

   GIE_VoidEnableGlobal();

   while(1)
   {
	   u16OnTicks = u16Reading3-u16Reading2;
	   u16PeriodTicks = u16Reading2-u16Reading1;
      /*waiting until both reading is ready*/
	   //while((u16PeriodTicks ==0)&&(u16OnTicks==0));
	   CLCD_voidGoToXY(2,0);
	   CLCD_voidSendNumber(u16OnTicks);
	    CLCD_voidGoToXY(2,1);
	  	CLCD_voidSendNumber(u16PeriodTicks);
	  	//while(u16Reading4==0);

   }
}

void ICU_HW(void)
{

  volatile static uint8 Local_u16Counter=0u;
  Local_u16Counter++;
  if(Local_u16Counter == 1u)
  {
	  /*Read Input capture ICR1*/
	 u16Reading1 =Timer1_u16GetInputCaptureValue();
  }
  else if(Local_u16Counter == 2u)
  {
	  /*Read Input capture ICR1*/
	  	 u16Reading2 =Timer1_u16GetInputCaptureValue();
	  	 /*Set Input Capture select to falling edge*/




	  	 Timer1_u16SetInputCapture(0);
	  	//CLR_BIT(TCCR1B,TCCR1B_ICES1);
  }
  else if(Local_u16Counter == 3)
  {
	  /*Read Input capture ICR1*/
	 	u16Reading3 =Timer1_u16GetInputCaptureValue();
	 	CLR_BIT(TIMSK,TIMSK_TICIE1);

	 	//Local_u16Counter =0u;
  }
  else
  {
	Local_u16Counter=0;
  }

}

