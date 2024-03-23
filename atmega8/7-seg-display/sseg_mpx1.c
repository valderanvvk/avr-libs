#include "sseg_mpx1.h"

// устанавливает бит порта в активное состояние
void seg_pin_on(PIN *pin)
{
	_SET_BIT(*pin->PORT, pin->NUM);
};

// устанавливает бит порта в неактивное состояние
void seg_pin_off(PIN *pin)
{
	_CLEAR_BIT(*pin->PORT, pin->NUM);
}

// активирует dp индикатора
void seg_dot_on(PIN *pin)
{
	pin = pin + DOT_POSITION_IN_ARRAY;
	_SET_BIT(*pin->PORT, pin->NUM);
}

// деактивирует dp индикатора
void seg_dot_off(PIN *pin)
{
	pin = pin + DOT_POSITION_IN_ARRAY;
	_CLEAR_BIT(*pin->PORT, pin->NUM);
}

// отображение данных на индикаторе
void seg_show(PIN *pin, uint8_t number)
{
	uint8_t read_number = 0;
	for (uint8_t i = 0; i < PIN_COUNT; i++)
	{
		if (i != DOT_POSITION_IN_ARRAY)
		{
			uint8_t bit = _READ_BIT(number, read_number);
			if (bit)
				seg_pin_on(pin);
			else
				seg_pin_off(pin);
			read_number++;
			pin = pin + 1;
		}
	}
}

// отключение дисплея
void seg_off(PIN *pin)
{
	for (uint8_t i = 0; i < PIN_COUNT; i++)
	{
		seg_pin_off(pin);
		pin = pin + 1;
	}
}