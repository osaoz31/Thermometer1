#include "main.h"
#include "stdio_redirect_to_usart.h"

UART_HandleTypeDef * huart;

int __io_putchar(int ch)
{
	uint8_t c[1];
	c[0] = ch & 0x00FF;

	HAL_UART_Transmit(huart, &*c, 1, 10);
	return ch;
}

int _write(int file, char * ptr, int len)
{
	int Dataldx;
	for (Dataldx = 0; Dataldx < len; Dataldx++)
	{
		__io_putchar(*ptr++);
	}

	return len;
}

void init_stdio_redirect_to_usart(UART_HandleTypeDef * huartx)
{
	huart = huartx;
}
