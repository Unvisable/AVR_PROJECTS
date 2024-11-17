
#include"STD_TYPES.h"
#include"ErrType.h"
#include <util/delay.h>
#include"DIO_interface.h"

#define SSD_PORT  DIO_u8PORTA
#define COM_PORT  DIO_u8PORTC
#define SSD1_COM  DIO_u8PIN6
#define SSD2_COM  DIO_u8PIN7

uint8 SSD_ARR[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01100111};
void main(void)
{
	DIO_u8SetPortDirection(SSD_PORT,DIO_u8PIN_OUTPUT); /*PORTA as OUTPUT*/

	DIO_u8SetPinDirection(COM_PORT,SSD1_COM,DIO_u8PIN_OUTPUT); /*Com pin as output*/
	DIO_u8SetPinDirection(COM_PORT,SSD2_COM,DIO_u8PIN_OUTPUT); /*Com pin as output*/
	while(1)
	{
		/*SSD1 on*/
		DIO_u8SetPinValue(COM_PORT , SSD1_COM, DIO_u8PIN_HIGH);
		/*SSD2 off*/
		DIO_u8SetPinValue(COM_PORT , SSD2_COM, DIO_u8PIN_LOW);
		/*Display 0*/
		DIO_u8SetPortValue(SSD_PORT, (SSD_ARR[0])<<1);
		/*WAIT*/
		_delay_ms(5);

		/*SSD1 off*/
		DIO_u8SetPinValue(COM_PORT , SSD1_COM, DIO_u8PIN_LOW);
		/*SSD2 on*/
		DIO_u8SetPinValue(COM_PORT , SSD2_COM, DIO_u8PIN_HIGH);
		/*Display 4*/
		DIO_u8SetPortValue(SSD_PORT, (SSD_ARR[4])<<1);
		/*WAIT*/
		_delay_ms(5);


	}
}

