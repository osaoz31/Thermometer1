
#ifndef __STDIO_REDIRECT_TO_USART_H
#define __STDIO_REDIRECT_TO_USART_H

	void init_stdio_redirect_to_usart(UART_HandleTypeDef * huartx);
	int __io_putchar(int ch);
	int _write(int file, char * ptr, int len);

#endif /* __STDIO_REDIRECT_TO_USART_H */

