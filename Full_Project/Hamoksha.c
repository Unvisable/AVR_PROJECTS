#include"Hamoksha.h"
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "util/delay.h"
#include"CLCD_interface.h"
uint8 Intro[8]= {0b00100,0b01010,0b00100,0b11111,0b00100,0b01110,0b01010,0b00000};

uint8 Run[8]={0b00011,0b00011,0b11100,0b00111,0b00100,0b01010,0b10001,0b00000};
uint8 Gun[8]={0b00000,0b00000,0b11111,0b10111,0b10000,0b10000,0b00000,0b00000};
uint8 Bullet[8]={0b00000,0b00000,0b11000,0b00111,0b11000,0b00000,0b00000,0b00000};

uint8 Dead[8]={0b00100,0b00100,0b10100,0b11111,0b10111,0b00100,0b00100,0b00000};

uint8 Dance[8]={0b00011000,0b00011000,0b00011100,0b00001100,0b00001100,0b00010010,0b00000010,0};
uint8 Dance2[8]={0b01110,0b01110,0b10101,0b01110,0b00100,0b00100,0b01010,0b10001};
uint8 Dance3[8]={0b01110,0b01110,0b00100,0b00111,0b00100,0b11111,0b00000,0b00000};
uint8 Dance4[8]={0b01110,0b01110,0b00100,0b11100,0b00100,0b11111,0b00000,0b00000};

uint8 play[8]={0b01110,0b01110,0b00101,0b01110,0b10100,0b01010,0b10001,0b00000};
uint8 Ball[8]={0b00000,0b00000,0b00000,0b00000,0b00000,0b01100,0b01100,0b00000};
uint8 Goal[8]={0b00111,0b00100,0b00100,0b00100,0b00100,0b00100,0b00111,0b00000};
uint8 O[8]={0b00000,0b00111,0b00100,0b11111,0b00000,0b00000,0b00000,0b00000};
uint8 M[8]={	0b00000,0b00000,0b00000,0b11111,0b01110,0b01010,0b01110,0b00000};
uint8 R[8]={0b00000,0b00000,0b00000,0b00011,0b00010,0b00100,0b01000,0b10000};

void Hamokhsa_intro()
{
	CLCD_voidGoToXY(1,0);
	CLCD_u8SendString("HI IAM HAMOKSHA");
	CLCD_u8SendSpecialCharacter(0, Intro,5,1);

}
void Hamoksha_run()
{
	CLCD_voidGoToXY(2,0);
	CLCD_u8SendString("I can run");
	for(uint8 i=0; i<14;i++)
	{
		CLCD_u8SendSpecialCharacter(0, Run,i,1);
		_delay_ms(100);
		CLCD_voidGoToXY(i,1);
		CLCD_u8SendString(" ");
	}


}
void Hamoksha_dance()
{
	CLCD_voidGoToXY(3,0);
	CLCD_u8SendString("I can dance");
	for(uint8 i=0; i<3;i++)
		{
			CLCD_u8SendSpecialCharacter(0, Intro,5,1);
			_delay_ms(100);
			CLCD_u8SendSpecialCharacter(0, Dance,5,1);
			_delay_ms(100);
			CLCD_u8SendSpecialCharacter(0, Dance2,5,1);
		    _delay_ms(100);
		    CLCD_u8SendSpecialCharacter(0, Dance3,5,1);
		    _delay_ms(100);
		    CLCD_u8SendSpecialCharacter(0, Dance4,5,1);
			_delay_ms(100);

		}

}
void Hamoksha_playFootball()
{
	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("I can play");
	_delay_ms(500);
	CLCD_voidSendCmd(1);
	CLCD_u8SendSpecialCharacter(0,Run,7,1);
	for(uint8 i=0; i<=4;i++)
	{
		CLCD_voidGoToXY(8,1);
			CLCD_u8SendString(".");
			_delay_ms(150);
			CLCD_voidGoToXY(8,1);
			CLCD_u8SendString(" ");
			CLCD_voidGoToXY(8,0);
			CLCD_u8SendString(".");
			_delay_ms(150);
			CLCD_voidGoToXY(8,0);
			CLCD_u8SendString(" ");
	}
	CLCD_voidSendCmd(1);
	CLCD_u8SendSpecialCharacter(7,Ball,8,1);
	CLCD_u8SendSpecialCharacter(12,Goal,12,1);
	for(uint8 i=0;i<=8;i++)
	{
		CLCD_u8SendSpecialCharacter(1,Run,i,1);
		_delay_ms(150);
		CLCD_voidGoToXY(i,1);
		CLCD_u8SendString(" ");
		_delay_ms(150);
	}

		CLCD_u8SendSpecialCharacter(7,Ball,10,1);
		_delay_ms(150);
		CLCD_voidGoToXY(10,1);
		CLCD_u8SendString(" ");
		_delay_ms(150);
	CLCD_u8SendSpecialCharacter(1,Intro,8,1);
	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("GOALLLL");


}
void Hamoksha_isDead()
{
	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("Don't kill me");
	CLCD_u8SendSpecialCharacter(0,Gun,0,1);
	_delay_ms(200);
	CLCD_u8SendSpecialCharacter(1,Intro,14,1);
	for(uint8 i=1; i<12;i++)
		{
		  CLCD_voidGoToXY(i,1);
		  CLCD_u8SendSpecialCharacter(2,Bullet,i,1);
		  _delay_ms(50);
		  CLCD_voidGoToXY(i,1);
		  CLCD_u8SendString(" ");
		  _delay_ms(50);
		}
	    CLCD_voidGoToXY(0,1);
	    CLCD_u8SendString(" ");
		CLCD_u8SendSpecialCharacter(1, Dead,14,1);
		_delay_ms(1000);
		CLCD_voidGoToXY(0,0);
		CLCD_u8SendString("Hamoksha is dead");
		_delay_ms(1000);
		CLCD_voidSendCmd(1);
		CLCD_voidGoToXY(5,0);
		CLCD_u8SendString("The End");
}
void ArabicName()
{

		for(uint8 i=4; i<=12; i++)
		{
			CLCD_u8SendSpecialCharacter(2,O,i,1);
			CLCD_u8SendSpecialCharacter(1,M,i-1,1);
			CLCD_u8SendSpecialCharacter(0,R,i-2,1);
			_delay_ms(150);
			CLCD_voidSendCmd(1);
			CLCD_u8SendSpecialCharacter(2,O,i,0);
			CLCD_u8SendSpecialCharacter(1,M,i-1,0);
			CLCD_u8SendSpecialCharacter(0,R,i-2,0);
			_delay_ms(150);
			CLCD_voidSendCmd(1);
		}


}
