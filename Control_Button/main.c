#include <avr/io.h>
#include <util/delay.h>
#include "BitMath.h"
#include "STD_TYPES.h"

void main(void)
{
	/*Set Pin As Input*/
	CLR_BIT(DDRD,2);
	CLR_BIT(DDRD,3);
	CLR_BIT(DDRD,4);
	/*ACTIVATE PULL UP*/
	SET_BIT(PORTD,2);
	SET_BIT(PORTD,3);
	SET_BIT(PORTD,4);
	/*Set LEd AS output*/
	//SET_BIT(DDRC,0);
	//CLR_BIT(PORTC,0);
	DDRC=0xFF;
	PORTC=0x00;
	sint8 i;
	while(1)
	{
		if((GET_BIT(PIND,2)==0))
		{
			for( i=0;i<=9;i++)
			 {
				   SET_BIT(PORTC,i);
				   _delay_ms(200);
			   }
		PORTC=0x00;

		}
		else if((GET_BIT(PIND,3)==0))
		{
			_delay_ms(250);
			if((GET_BIT(PIND,2)==0))
			{
				 SET_BIT(PORTC,7);
				  _delay_ms(250);
				  SET_BIT(PORTC,6);
				  _delay_ms(250);
				  SET_BIT(PORTC,5);
				  _delay_ms(250);
				  SET_BIT(PORTC,4);
				  _delay_ms(250);
				  SET_BIT(PORTC,3);
				  _delay_ms(250);
				  SET_BIT(PORTC,2);
				  _delay_ms(250);
				  SET_BIT(PORTC,1);
				  _delay_ms(250);
				  SET_BIT(PORTC,0);
				  _delay_ms(1000);

				  CLR_BIT(PORTC,7);
				   _delay_ms(250);
				   CLR_BIT(PORTC,6);
				   _delay_ms(250);
				   CLR_BIT(PORTC,5);
				  _delay_ms(250);
				  CLR_BIT(PORTC,4);
				  _delay_ms(250);
				  CLR_BIT(PORTC,3);
				  _delay_ms(250);
				  CLR_BIT(PORTC,2);
				  _delay_ms(250);
				  CLR_BIT(PORTC,1);

					 _delay_ms(1000);

					 SET_BIT(PORTC,1);
					 _delay_ms(250);
					 SET_BIT(PORTC,2);
					 _delay_ms(250);
					 SET_BIT(PORTC,3);
					 _delay_ms(250);
					 SET_BIT(PORTC,4);
					  _delay_ms(250);
					  SET_BIT(PORTC,5);
					   _delay_ms(250);
					   SET_BIT(PORTC,6);
					   _delay_ms(250);
					   SET_BIT(PORTC,7);
						_delay_ms(250);

						 _delay_ms(2000);


			}
			else
			{
				for( i=9;i>=0;i--)
				 {
					   SET_BIT(PORTC,i);
					   _delay_ms(200);
				   }

			}

			PORTC=0x00;

		}
		else if((GET_BIT(PIND,4)==0))
		{
			for(i=0;i<=3;i++)
			{
				PORTC=0xFF;
				_delay_ms(250);
				PORTC=0x00;
				_delay_ms(250);
			}
		}

	}

}
