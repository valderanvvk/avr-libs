#define F_CPU 8000000UL // 8 MHz

#include <avr/io.h>
#include <util/delay.h>

#include "sseg_mpx1.h"

int main(void)
{
	// установка регистров направления DDR
	DDRD = 255;
	_SET_BIT(DDRC, 1);
	_SET_BIT(DDRB, 1);

	// определение массива чисел для индикатора
	uint8_t nums[] = SEG_NUMBERS;

	// массив подключения пинов к индикатору
	PIN pins[8] = {
			{&PORTD, 0},	// q
			{&PORTD, 1},	// b
			{&PORTC, 1},	// c
			{&PORTB, 1},	// d
			{&PORTD, 4},	// e
			{&PORTD, 5},	// f
			{&PORTD, 6},	// g
			{&PORTD, 7}}; // dp

	uint8_t i = 0;
	uint8_t toggle_dp = 0;

	while (1)
	{
		// работа с точкой на индикаторе
		toggle_dp = toggle_dp ? 0 : 1;
		if (toggle_dp)
			seg_dot_on(pins);
		else
			seg_dot_off(pins);

		// отображение числа на индикаторе
		seg_show(pins, nums[i]);
		i = ++i > 9 ? 0 : i;

		_delay_ms(300);
	}
}