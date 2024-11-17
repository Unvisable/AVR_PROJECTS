#include "STD_TYPES.h"
#include "BitMath.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "ERROR_TYP_STATE.h"
#include "CLCD_interface.h"
#include "CLCD_prv.h"
#include "CLCD_cfg.h"
#if CLCD_u8BIT_MODE == FOUR_BIT
static void voidSetHalfDataPort(uint8 Copy_u8Data)
{
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,  CLCD_u8D4_PIN, GET_BIT(Copy_u8Data,0));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,  CLCD_u8D5_PIN, GET_BIT(Copy_u8Data,1));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,  CLCD_u8D6_PIN, GET_BIT(Copy_u8Data,2));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,  CLCD_u8D7_PIN, GET_BIT(Copy_u8Data,3));

}
#endif
static void voidSendEnablePulse(void)
{
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN, DIO_u8PIN_LOW);
}

void CLCD_voidInit(void)
{
	/*Wait for more than 30 ms after power on*/
	_delay_ms(40);
#if CLCD_u8BIT_MODE == EIGHT_MODE
	/*Function set command: 2 lines, Font size: 5x7*/
	CLCD_voidSendCmd(0b00111000);
#elif CLCD_u8BIT_MODE == FOUR_MODE
	voidSetHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetHalfDataPort(0b1000);
    voidSendEnablePulse();
#endif
	/*Display on off control : Display on, cursor off, blink cursor off*/
	CLCD_voidSendCmd(0b00001100);
	_delay_ms(40);
	/*Clear display*/
	CLCD_voidSendCmd(1);

}
void CLCD_voidSendCmd(uint8 Copy_u8Cmd)
{
	/*Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT, CLCD_u8RS_PIN, DIO_u8PIN_LOW);

	/*Set RW pin to low for writing*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT, CLCD_u8RW_PIN, DIO_u8PIN_LOW);

	/*Send the command*/
#if CLCD_u8BIT_MODE == EIGHT_BIT
	DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Cmd);
	  voidSendEnablePulse();
#elif CLCD_u8BIT_MODE == FOUR_BIT
	/*Send the most significant bits for Command First*/
	voidSetHalfDataPort(Copy_u8Cmd>>4);
	voidSendEnablePulse();
	voidSetHalfDataPort(Copy_u8Cmd);
    voidSendEnablePulse();
#else
#error Wrong CLCD_u8BIT_MODE Configuration option
#endif

	/*Send enable pulse*/

}

void CLCD_voidSendData(uint8 Copy_u8Data)
{
	/*Set RS pin to high for data*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT, CLCD_u8RS_PIN, DIO_u8PIN_HIGH);

	/*Set RW pin to low for writing*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT, CLCD_u8RW_PIN, DIO_u8PIN_LOW);

	/*Send the Data*/
#if CLCD_u8BIT_MODE == EIGHT_BIT
	DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Data);
	  voidSendEnablePulse();
#elif CLCD_u8BIT_MODE == FOUR_BIT
	/*Send the most significant bits for Data First*/
	voidSetHalfDataPort(Copy_u8Data>>4);
	voidSendEnablePulse();
	voidSetHalfDataPort(Copy_u8Data);
    voidSendEnablePulse();
#else
#error Wrong CLCD_u8BIT_MODE Configuration option
#endif
}

uint8 CLCD_u8SendString(const char* Copy_PchString)
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_PchString !=NULL)
	{
		uint8 Local_u8Iterator =0u;
		while(Copy_PchString[Local_u8Iterator] != '\0')
		{
			CLCD_voidSendData(Copy_PchString[Local_u8Iterator]);
			 Local_u8Iterator++;
		}
	}
	else
	{
		Local_u8ErrorState=NULL_PTR_ERR ;
	}
    return Local_u8ErrorState;
}

void CLCD_voidSendNumber(sint32 Copy_s32Number)
{
	char Local_chNumber[10];
	uint8 Local_u8RightDigit , Local_u8Counter=0;
	sint8 Local_s8Counter2;
   if(Copy_s32Number == 0)
   {
	   CLCD_voidSendData('0');
	   return;
   }
   else if(Copy_s32Number <0)
   {
	   Copy_s32Number *=-1;
	   CLCD_voidSendData('-');
   }
   while(Copy_s32Number !=0)
   {
	   Local_u8RightDigit =(uint8)((uint32)Copy_s32Number %10);/*RIGHT THE MOST DIGIT*/
	   Copy_s32Number /= 10; /*REMOVE THE NUMBER*/
	   Local_chNumber[Local_u8Counter]=Local_u8RightDigit + '0';/*Convert to ASCI*/
	   Local_u8Counter++;
   }
   for(Local_s8Counter2 = (sint8)Local_u8Counter-1; Local_s8Counter2 >= 0; Local_s8Counter2--)
	   {
		   CLCD_voidSendData(Local_chNumber[(uint8)Local_s8Counter2]);
	   }
}


