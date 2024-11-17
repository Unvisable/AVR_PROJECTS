/*
 * main.c

 *
 *  Created on: Apr 26, 2024
 *      Author: user
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"ErrType.h"
#include"util/delay.h"
#include"DIO_interface.h"
#include"Port_interface.h"
#include"GIE_interface.h"
#include"Timers_interface.h"
#include"Timers_reg.h"
#include "Calculator_interface.h"
#include "Keypad_INTERFACE.h"
void PlayTone(uint8);
uint8 Local_u8PressedKey;
void main(void)
{
	PORT_voidInit();
    Timer0_voidInit();

    //Timer0_voidSetCompareMatchValue(0u);
	while(1)
	{
         Local_u8PressedKey = Keypad4x4();
         _delay_ms(10);
         if(Local_u8PressedKey!='\0')
         {
        	 PlayTone(Local_u8PressedKey);
        	 Local_u8PressedKey=0;
         }
         else
         {
        	 Timer0_voidSetCompareMatchValue(0u);
         }




	}
}

void PlayTone(uint8 Copy_u8PressedKey)
{
	uint8 PwmValue=0u;
	switch(Copy_u8PressedKey)
	{
	case(7): PwmValue = 255u; break; /*100% duty cycle*/
	case(8): PwmValue = 230u; break; /*90% duty cycle*/
	case(9): PwmValue = 204u; break; /*80% duty cycle*/
	case('/'): PwmValue = 179u; break; /*70% duty cycle*/
	case(4): PwmValue = 153u; break; /*60% duty cycle*/
	case(5): PwmValue = 128u; break; /*50% duty cycle*/
	case(6): PwmValue = 103;  break; /*40% duty cycle*/
	case('*'): PwmValue = 76u;  break; /*30% duty cycle*/
	case(1): PwmValue = 51u;  break; /*20% duty cycle*/
	case(2):PwmValue = 25u;  break; /*10% duty cycle*/
	default: PwmValue =0u; break;
	}
	Timer0_voidSetCompareMatchValue(PwmValue);

}

