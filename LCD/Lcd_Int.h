/*************************************************************/
/************ Author : kareem hagag ******************/
/************ date : 30/7/2026 ******************/
/************ Title: interface file ********************/
/**************************************************************/
#ifndef     LCD_INTERFACE_H
#define 	LCD_INTERFACE_H
#include "../../std_lib/Std_Types.h"
void LCD_voidInit(void); // Initialize the LCD hardware
void LCD_voidSendCmd(u8 u8Cmd); // Sends a command (RS = 0)
void LCD_voidSendData(u8 u8Data); // Displays character (RS = 1)
void LCD_voidSendString(u8 *u8String); // Displays string
void LCD_voidSendNumber(s32 s32Number);// Prints a signed number
void LCD_voidGoToXY(u8 X, u8 Y); // Moves the cursor to specific position
void LCD_voidClearScreen(void); // Clears all displayed text

#endif
