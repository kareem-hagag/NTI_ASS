/*************************************************************/
/************ Auther : kareem hagag ******************/
/************ date : 29/7/2026 ******************/
/************ Title: MAIN ********************/
/**************************************************************/
#include "../std_lib/Std_Types.h"
#include "../std_lib/Bit_Math.h"
#include "../mcal/Dio_Int.h"
#include "../mcal/Dio_Private.h"
#include "../mcal/Dio_Config.h"
#include <avr/delay.h>

int main(void)
{
	DIO_voidInitialization();
	DIO_voidSetPinDirection(DIO_PORTA, PIN0, OUTPUT);

while(1)
	{
		DIO_voidTogglePinValue(DIO_PORTA, PIN0);
		_delay_ms(100);
	}

	return 0;
}