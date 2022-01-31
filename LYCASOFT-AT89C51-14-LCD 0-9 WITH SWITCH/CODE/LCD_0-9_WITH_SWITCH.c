#include<reg51.h>
#include "8051_delay.h"
#include "LCD_4_BIT_HEADER_FILE.h"

sbit SW = P1^0;

int Count;
void main()
{
	SW = 1;

	Lcd_Intialization();

	Lcd_Command(0x80);
	Lcd_String("LYCO SOFT");

	while(1)
	{
		Lcd_Command(0xc0);
		Lcd_Data(Count+48);
		
		if(SW == 1)
		{
			Count++;
		}
		
		if(Count > 9)
			Count = 0;
	}
}