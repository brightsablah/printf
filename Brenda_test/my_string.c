#include "main.h"

/**
 * b_putstr -  print string and handle errors
 * @str: string to write to std output
 *
 * Return: 0 for success else -1 for error
 */
int b_putstr(char *str)
{
	while (*str)
	{
		if (b_putchar(*str) == -1)
			return (-1);
		str++;
	}
	return (0);
}

/**
 * print_b_string - custom function to print a string
 * @args: va_list containing the string to print
 *
 * Return: number of printed charactors
 */
int print_b_string(va_list args)
{
	char *word = va_arg(args, char *);

	if (word == NULL)
	{
		word = "(null)";
	}
	return (b_putstr(word));
}
