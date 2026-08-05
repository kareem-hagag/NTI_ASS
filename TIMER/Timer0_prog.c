/***     Auther : kareem hagag ***/
/***     Title: program file  ***/
#include <avr/io.h>
#include "../../std_lib/Std_Types.h"
#include "../../std_lib/Bit_Math.h"
#include "../DIO/Dio_Int.h"
#include "Timer0_Config.h"
#include "Timer0_Private.h"
#include "Timer0_Int.h"

void TIMER0_voidPWM_Init(void)
{
    DIO_voidSetPinDirection(DIO_PORTB, PIN3, OUTPUT);

    SET_BIT(TCCR0, TIMER0_WGM00);
    SET_BIT(TCCR0, TIMER0_WGM01);

    SET_BIT(TCCR0, TIMER0_COM01);
    CLR_BIT(TCCR0, TIMER0_COM00);

    TCCR0 |= TIMER0_PRESCALER;

    OCR0 = 0;
}

void TIMER0_voidSetDutyCycle(u8 u8DutyCycle)
{
    if (u8DutyCycle > 100)
    {
        u8DutyCycle = 100;
    }
    OCR0 = (u8)(((u16)u8DutyCycle * 255) / 100);
}

void TIMER0_voidPWM_Stop(void)
{
    CLR_BIT(TCCR0, TIMER0_CS00);
    CLR_BIT(TCCR0, TIMER0_CS01);
    CLR_BIT(TCCR0, TIMER0_CS02);
}
