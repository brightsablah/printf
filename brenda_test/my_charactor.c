#include "main.h"

/**
 * print_b_char - function  print customised character
 * @args: va_list with character to print
 *
 * Return: number of characters printed
 */
int print_b_char(va_list args)
{
	char symbol = va_arg(args, int);

	return (b_putchar(symbol));
}
