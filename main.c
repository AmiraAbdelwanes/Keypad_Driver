#include<util/delay.h>
#include "STD_types.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"
/***********************DIO*******************/
#include"DIO_register.h"
#include"DIO_interface.h"
/*********************Keypad*******************/
#include"keybad_inter.h"
/***********************LCD*******************/
#include"lcd_conf.h"
#include"lcd_inter.h"


void main()
{
	/**********************LCD Init**********************/
	DIO_enumSetPinDirection(DIO_U8_PORT_B,DIO_U8_PIN0,DIO_U8_OUTPUT);//RS
	DIO_enumSetPinDirection(DIO_U8_PORT_B,DIO_U8_PIN1,DIO_U8_OUTPUT);//RW
	DIO_enumSetPinDirection(DIO_U8_PORT_B,DIO_U8_PIN3,DIO_U8_OUTPUT);//EN
	DIO_enumSetPortDirection(DIO_U8_PORT_A,0xff);
	LCD_enuInit();
	/*********************Keypad Init********************/
	keypad_init(DIO_U8_PORT_C);
	/**********************Code**************************/
	LCD_enuSendCMD(0x01);
	lcd_gotox_y(0,1);
	LCD_vidWriteString("Choose Option");
	_delay_ms(100);
	LCD_enuSendCMD(0x01);
	lcd_gotox_y(0,1);
	LCD_vidWriteString("1-Light   2-Fan");
	lcd_gotox_y(1,1);
	LCD_vidWriteString("3-Temp 4-safety");

	u8 key1=0;
		u8 option=0;
		key1= Keypad_u8Keypress(DIO_U8_PORT_C);
		while(!key1)
		{
			key1=Keypad_u8Keypress(DIO_U8_PORT_C);
		}
		switch (key1)
		{
		case'1':
		{
			LCD_enuSendCMD(0x01);
			lcd_gotox_y(0,1);
			LCD_vidWriteString("1-Room1 2-Room2");
			lcd_gotox_y(1,1);
			LCD_vidWriteString("3-Hall   4-All");
			key1=0;
	break;
		}
		}
	while (1)
	{}




}
