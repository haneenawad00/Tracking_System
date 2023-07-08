 /******************************************************************************
 * Module: LCD
 * File Name: lcd.c
 * Description: Source file for the LCD driver
 * Author: Haneen Ahmed
 *******************************************************************************/

#include <util/delay.h> /* For the delay functions */
#include "../LIB/bit_math.h" /* For GET_BIT Macro */
#include "lcd.h"
#include "../MCAL/dio.h"



/*  This function sends a command to the LCD module to set various settings or control the display.
 * Commands are typically used to set the cursor position, turn the display on or off, or clear the display.
 * The u8CmdCpy argument is the command to be sent to the LCD module.    */
void LCD_vidSendCommand(uint8 u8CmdCpy)
{
	DIO_SetPortDirection(PORTA ,FULL_OUTPUT);
	/* Set RS to LOW */
	DIO_SetPinValue(PORTA, 0, LOW);
	/* Set R/W to LOW */
	DIO_SetPinValue(PORTA, 1, LOW);
	/* Set E to HIGH  */
	DIO_SetPinValue(PORTA, 2, HIGH);
	/* Load Command on Data bus */
	DIO_SetPortValue(PORTC, u8CmdCpy);
	/* Set E to LOW */
	DIO_SetPinValue(PORTA, 2, LOW);
	/* Wait for E to settle */
	_delay_ms(5);
	/* Set E to HIGH */
	DIO_SetPinValue(PORTA, 2, HIGH);
	/* Delay for 10ms to let the LCD execute command */
	_delay_ms(10);

}


/*This function initializes the LCD module by setting up the necessary communication settings and configuring the module for use.
 * It typically involves setting pins and modes for data and control lines.*/
void LCD_vidInit(void)
{
	DIO_SetPortDirection(PORTC ,FULL_OUTPUT); //data port
    DIO_SetPortDirection(PORTA ,FULL_OUTPUT);//ctrl port
	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(30);
	/* Return Home  */
	LCD_vidSendCommand(lcd_Home);
	_delay_ms(15);
	/* Function Set  */
	LCD_vidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(1);
	/* Display ON OFF Control */
	LCD_vidSendCommand(lcd_DisplayOn);
	_delay_ms(1);
	/* Clear Display */
	LCD_vidSendCommand(lcd_Clear);
	_delay_ms(15);
	/* Entry Mode Set  */
	LCD_vidSendCommand(lcd_EntryMode);
	_delay_ms(2);
}

/*This function writes a single character to the LCD module.
 *  The u8DataCpy argument is the character to be written.*/

void LCD_vidWriteCharctr(uint8 u8DataCpy)
{
	/* Set RS to HIG */
	DIO_SetPinValue(PORTA, 0, HIGH);
	/* Set R/W to LOW */
	DIO_SetPinValue(PORTA, 1, LOW);
	/* Set E to HIGH */
	DIO_SetPinValue(PORTA, 2, HIGH);
	/* Load Command on Data bus */
	DIO_SetPortValue(PORTC, u8DataCpy);
	/* Set E to LOW */
	DIO_SetPinValue(PORTA, 2, LOW);
	/* Wait for E to settle */
	_delay_ms(5);
	/* Set E to HIGH */
	DIO_SetPinValue(PORTA, 2, HIGH);
	/* Delay to let the LCD Display the character */
	_delay_ms(10);
}

 /* This function writes a string of characters to the LCD module.
  *  The pu8StringCpy argument is a pointer to the string to be written.                                                         */

void LCD_vidWriteString (uint8* pu8StringCpy)
	{
	uint8 i = 0;
		while(pu8StringCpy[i] != '\0')
		{
			LCD_vidWriteCharctr(pu8StringCpy[i]);
			i++;
		}

	}

void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
		case 0:
			lcd_memory_address=col;
				break;
		case 1:
			lcd_memory_address=col+0x40;
				break;
		case 2:
			lcd_memory_address=col+0x10;
				break;
		case 3:
			lcd_memory_address=col+0x50;
				break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_vidSendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_vidWriteString(Str); /* display the string */
}
