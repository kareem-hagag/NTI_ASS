/*************************************************************/
/************ Author : kareem hagag ******************/
/************ date : 30/7/2026 ******************/
/************ Title: Configuration file ********************/
/**************************************************************/
#ifndef   LCD_CONFIG_H
#define   LCD_CONFIG_H
/*** Control Pins ***/
#define LCD_RS    DIO_PORTB, PIN0   //Register Select
#define LCD_EN    DIO_PORTB, PIN1   //Enable
#define LCD_RW    DIO_PORTB, PIN2   //Read/Write

/*** data pins ***/
#define LCD_D0    DIO_PORTA, PIN0
#define LCD_D1    DIO_PORTA, PIN1
#define LCD_D2    DIO_PORTA, PIN2
#define LCD_D3    DIO_PORTA, PIN3
#define LCD_D4    DIO_PORTA, PIN4
#define LCD_D5    DIO_PORTA, PIN5
#define LCD_D6    DIO_PORTA, PIN6
#define LCD_D7    DIO_PORTA, PIN7

#endif
