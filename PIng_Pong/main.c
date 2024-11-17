#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"util/delay.h"
#include"Port_interface.h"
#include"DIO_interface.h"
#include"DIO_reg.h"
#include"EXTI_interface.h"
#include"CLCD_interface.h"
#include"GIE_interface.h"
void INT0_Func(void);
void INT1_Func(void);
void INT2_Func(void);
uint8 i=0;
uint8 Local_u8Counter=0u;
void main(void)
{
	PORT_voidInit();
	CLCD_voidInit();
	EXTI_VoidInit();
	EXTI_u8SetCallBack(INT0, &INT0_Func);
	EXTI_u8SetCallBack(INT1, &INT1_Func);
	EXTI_u8SetCallBack(INT2, &INT2_Func);
	GIE_VoidEnableGlobal();

	CLCD_voidSendCmd(1);
	while(1)
	{


		for( i=0; i<=16; i++)
		{
			CLCD_voidGoToXY(i,0);
			CLCD_u8SendString(" PING_PONG");
			_delay_ms(2000);

		}


	}
}

void INT0_Func(void)
{
	if(GET_BIT(PIND,2)==0)
	{
		do
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_LOW);
					_delay_ms(50);
					 DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_HIGH);
					 _delay_ms(50);
					 if(GET_BIT(PIND,2))
					 {
						 break;
					 }
		}while(1);
	}
	else
	{
	  do
	  {
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_LOW);
						_delay_ms(4000);
						 DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_HIGH);
						 _delay_ms(4000);
						 if(GET_BIT(PIND,2)==0)
											 {
												 break;
											 }
	  }while(1);
	}

}
void INT1_Func(void)
{

}
void INT2_Func(void)
{

}
