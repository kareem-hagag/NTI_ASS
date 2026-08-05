/**************************************************************/
/************ Author : Kareem Hagag ***************************/
/************ Date   : 30/7/2026 ******************************/
/************ Title  : Program File (8-Bit Mode) **************/
/**************************************************************/
#include <util/delay.h>
#include "../../std_lib/Std_Types.h"
#include "../../std_lib/Bit_Math.h"
#include "../../mcal/DIO/Dio_Int.h"
#include "Lcd_Config.h"
#include "Lcd_Private.h"
#include "Lcd_Int.h"

#include <util/delay.h>
#include "../../std_lib/Std_Types.h"
#include "../../std_lib/Bit_Math.h"
#include "../../mcal/DIO/Dio_Int.h"
#include "Lcd_Config.h"
#include "Lcd_Private.h"
#include "Lcd_Int.h"


static void LCD_voidPutonBus(u8 u8Char)
{
    DIO_voidSetpinValue(LCD_D0, GET_BIT(u8Char, 0));
    DIO_voidSetpinValue(LCD_D1, GET_BIT(u8Char, 1));
    DIO_voidSetpinValue(LCD_D2, GET_BIT(u8Char, 2));
    DIO_voidSetpinValue(LCD_D3, GET_BIT(u8Char, 3));
    DIO_voidSetpinValue(LCD_D4, GET_BIT(u8Char, 4));
    DIO_voidSetpinValue(LCD_D5, GET_BIT(u8Char, 5));
    DIO_voidSetpinValue(LCD_D6, GET_BIT(u8Char, 6));
    DIO_voidSetpinValue(LCD_D7, GET_BIT(u8Char, 7));
}

void LCD_voidInit(void)
{
    /* Set Control & Data Pins as Output */
    DIO_voidSetPinDirection(LCD_RS, 1);
    DIO_voidSetPinDirection(LCD_RW, 1);
    DIO_voidSetPinDirection(LCD_EN, 1);
    DIO_voidSetPinDirection(LCD_D0, 1);
    DIO_voidSetPinDirection(LCD_D1, 1);
    DIO_voidSetPinDirection(LCD_D2, 1);
    DIO_voidSetPinDirection(LCD_D3, 1);
    DIO_voidSetPinDirection(LCD_D4, 1);
    DIO_voidSetPinDirection(LCD_D5, 1);
    DIO_voidSetPinDirection(LCD_D6, 1);
    DIO_voidSetPinDirection(LCD_D7, 1);

    _delay_ms(35);
    LCD_voidSendCmd(LCD_HOME);
    _delay_ms(1);
    LCD_voidSendCmd(LCD_FUNCTIONSET_8BIT);
    _delay_ms(1);
    LCD_voidSendCmd(LCD_DISPLAYON);
    _delay_ms(1);
    LCD_voidSendCmd(LCD_CLEAR);
    _delay_ms(2);
    LCD_voidSendCmd(LCD_ENTRY_MODE);
    _delay_ms(1);
}

void LCD_voidSendCmd(u8 u8Cmd)
{
    DIO_voidSetpinValue(LCD_RS, 0);
    DIO_voidSetpinValue(LCD_RW, 0);
    LCD_voidPutonBus(u8Cmd);
    DIO_voidSetpinValue(LCD_EN, 1);
    _delay_ms(2);
    DIO_voidSetpinValue(LCD_EN, 0);
}

void LCD_voidSendData(u8 u8Data)
{
    DIO_voidSetpinValue(LCD_RS, 1);
    DIO_voidSetpinValue(LCD_RW, 1);
    LCD_voidPutonBus(u8Data);
    DIO_voidSetpinValue(LCD_EN, 1);
    _delay_ms(2);
    DIO_voidSetpinValue(LCD_EN, 0);}

void LCD_voidSendString(u8 *u8String)
{
    u8 u8Index = 0;
    while (u8String[u8Index] != '\0')
    {
        LCD_voidSendData(u8String[u8Index]);
        u8Index++;
    }
}

void LCD_voidGoToXY(u8 X, u8 Y)
{
    u8 u8Address = 0;
    if (X == 0)
    {
        u8Address = Y;
    }
    else
    {
        u8Address = Y + 0x40;
    }
    LCD_voidSendCmd(u8Address + LCD_SETCURSOR);
}

void LCD_voidClearScreen(void)
{
    LCD_voidSendCmd(LCD_CLEAR);
    _delay_ms(2);
}

void LCD_voidSendNumber(s32 s32Number)
{
    if (s32Number == 0)
    {
        LCD_voidSendData('0');
        return;
    }

    if (s32Number < 0)
    {
        LCD_voidSendData('-');
        s32Number = -s32Number;
    }

    if (s32Number / 10 != 0)
    {
        LCD_voidSendNumber(s32Number / 10);
    }

    LCD_voidSendData((s32Number % 10) + '0');
}
