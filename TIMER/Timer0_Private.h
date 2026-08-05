/***     Auther : kareem hagag ***/
/***     Title: private file  ***/
#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#define TCCR0   *((volatile u8*)0x53)
#define TCNT0   *((volatile u8*)0x52)
#define OCR0    *((volatile u8*)0x51)
#define TIMSK   *((volatile u8*)0x59)
#define TIFR    *((volatile u8*)0x58)

#define TIMER0_CS00     0
#define TIMER0_CS01     1
#define TIMER0_CS02     2
#define TIMER0_WGM01    3
#define TIMER0_COM00    4
#define TIMER0_COM01    5
#define TIMER0_WGM00    6

#endif
