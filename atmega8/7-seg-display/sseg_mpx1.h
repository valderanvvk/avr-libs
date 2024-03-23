/*
Author: valderan

AVR Microcontroller Atmega8
7-SEGMENT DISPLAY LIBRARY

PROTEUS MODEL:
	7SEG-MPX1-CC (Common Cathode) testing
*/
#pragma once

#include <avr/io.h>

// макрос установки бита
#define _SET_BIT(REG, BIT) ((REG) |= (1 << BIT))
// макрос очистки бита
#define _CLEAR_BIT(REG, BIT) ((REG) &= ~(1 << BIT))
// макрос чтения значения бита
#define _READ_BIT(REG, BIT) ((REG) & (1 << BIT))

// кол-во пинов для индикатора
#define PIN_COUNT 8
// позиция точки в массиве
#define DOT_POSITION_IN_ARRAY 7
// шаблон пинов по которому будет идти перебор

// struct for pin
typedef struct
{
	volatile uint8_t *PORT; // порт к которому подсоединен пин
	uint8_t NUM;						// номер пина для PORT
} PIN;

// задание структуры подключения для одного порта
#define CREATE_AND_ASSIGN_TO_PORT(PORT) \
	{                                     \
		{&PORT, 0},                         \
				{&PORT, 1},                     \
				{&PORT, 2},                     \
				{&PORT, 3},                     \
				{&PORT, 4},                     \
				{&PORT, 5},                     \
				{&PORT, 6},                     \
		{                                   \
			&PORT, 7                          \
		}                                   \
	}

#define SEG_NUMBERS {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

// устанавливает бит порта в активное состояние
void seg_pin_on(PIN *pin);

// устанавливает бит порта в неактивное состояние
void seg_pin_off(PIN *pin);

// кждый 8й эллемент массива должен быть определен как dp(точка)
// либо определяется в DOT_POSITION_IN_ARRAY
// активирует dp индикатора
void seg_dot_on(PIN *pin);

// деактивирует dp индикатора
void seg_dot_off(PIN *pin);

// отображение данных на индикаторе
void seg_show(PIN *pin, uint8_t number);

// отключение дисплея
void seg_off(PIN *pin);