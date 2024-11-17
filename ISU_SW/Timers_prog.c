/*
 * Timers_prog.c
 *
 *  Created on: Apr 20, 2024
 *      Author: user
 */
#include"STD_TYPES.h"
#include"ErrType.h"
#include"BIT_MATH.h"
#include"Timers_interface.h"
#include"Timers_cfg.h"
#include"Timers_prv.h"
#include"TIMER_reg.h"


//static void (*Timer0_CallBackFunc)(void)=NULL;
static void (*Timer_CallBackFunc[8])(void)={NULL};
void Timer0_voidInit(void)
{
	/*Set FAST_PMW*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	/*Set on top , clear on compare*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
	/*clear prescaler*/
	TCCR0 &=0b11111000;
	/*Set prescaler divsion by 64*/
	TCCR0 |= 0b011;


}

void Timer1_voidInit(void)
{
   /*Set Normal mode (default*/
	/*Clear prescaller*/
	TCCR1B &= 0b11111000;

	/*Set precaller division by 64*/
	 TCCR1B |=0b011;
}

uint16 Timer1_u16GetTimerValue(void)
{
	return TCNT1;
}

void Timer1_u16SetValue(uint16 Copy_u16Value)
{
	TCNT1 = Copy_u16Value;
}

uint8 Timer_u8SetCallBack(uint8 Copy_u8InitState,void(*Copy_pvCallBack)(void))
{
	uint8 Local_u8ErrorState=OK;
	if(Copy_pvCallBack != NULL)
	{
		/*Set Localy Function globally*/
		Timer_CallBackFunc[Copy_u8InitState] = Copy_pvCallBack;
	}
	else
	{
		Local_u8ErrorState= NULL_PTR_ERR;
	}
	return Local_u8ErrorState;

}

void Timer0_voidSetPreloadValue(uint8 Copy_u8PreloadValue)
{
  TCNT0 = Copy_u8PreloadValue;
}

void Timer0_voidSetCompareMatchValue(uint8 Copy_u8CompareValue)
{
  OCR0 = Copy_u8CompareValue;
}


/*Timer0 overflow ISR*/
void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	if(Timer_CallBackFunc[Timer0_OVF_INT]!= NULL)
	{
		Timer_CallBackFunc[Timer0_OVF_INT]();
	}
	else
	{

	}
}
/*Timer0 Compare match interrupt*/
void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	if(Timer_CallBackFunc[Timer0_OC_INT]!= NULL)
	{
		Timer_CallBackFunc[Timer0_OC_INT]();
	}
	else
	{

	}
}
