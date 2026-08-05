/*************************************************************/
/************ Author : kareem hagag ******************/
/************ date : 30/7/2026 ******************/
/************ Title: private file  ********************/
/**************************************************************/
#ifndef     LCD_PRIVATE_H
#define     LCD_PRIVATE_H
#include "../../std_lib/Std_Types.h"
/********* LCD Commands ***********/
#define LCD_CLEAR               0x01
#define LCD_HOME                0x02
#define LCD_DISPLAYOFF          0x08
#define LCD_DISPLAYON           0x0C
#define LCD_FUNCTION_RESET      0x30
#define LCD_FUNCTIONSET_8BIT    0x38 // 2 LINE DISPLAY 5*7 FONT
#define LCD_SETCURSOR           0x80
#define LCD_ENTRY_MODE          0x06 // Increment cursor, no display shift

/********* Private Helper Functions ***********/
static void LCD_voidPutonBus(u8 u8Char);

#endif
