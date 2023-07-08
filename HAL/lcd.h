 /******************************************************************************
 * Module: LCD
 * File Name: lcd.h
 * Description: Header file for the LCD driver
 * Author: Haneen Ahmed
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "../LIB/std_types.h"





/* LCD Commands */
#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80




void LCD_vidInit(void);
void LCD_vidSendCommand(uint8 u8CmdCpy);
void LCD_vidWriteCharctr(uint8 u8DataCpy);
void LCD_vidWriteString (uint8* pu8StringCpy);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_moveCursor(uint8 row,uint8 col);


#endif /* LCD_H_ */
