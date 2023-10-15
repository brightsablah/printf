#include "main.h"

/**
* b_print_number - prints numbers
* @num: number to be printed
*
* Return: number of characters printed
*/
int b_print_number(int num)
{
	int count = 0;

	if (num / 10)
		count += b_print_number(num / 10);

	b_putchar('0' + num % 10);
	count++;

	return (count);
}

/**
 * print_b_integer - function to print an integer
 * @args: va_list containing the integer to print
 *
 * Return: number of characters printed
 */
int print_b_integer(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;

	if (num < 0)
	{
		b_putchar('-');
		count++;
		num = -num;
	}
	count += b_print_number(num);
	return (count);
}

/**
 * print_b_float -  function to print a float
 * @args: va_list containing the float to printva_list check
 *
 * Return: number of characters printed
 */
int print_b_float(va_list args)
{
	double num = va_arg(args, int);
	int count = 0;

	if (num < 0)
	{
		b_putchar('-');
		count++;
		num = -num;
	}
	count += b_print_number(num);
	return (count);
}
