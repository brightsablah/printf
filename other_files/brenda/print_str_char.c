#include "main.h"

/**
 * b_putchar - customised function to print b and handle errors
 * @b: character to write to std output
 *
 * Return: 0 sucess and -1 for error
 */
int b_putchar(char b)
{
	if (write(1, &b, 1) == -1)
	{
		return (-1);
	}
	return (0);
}

/**
 * _print - costumised print function for strings and characters
 * @format: list of different types of arguments
 *
 * Return: number of printed characters excluding null byte
 */
int _printf(const char *format, ...)
{
	const char *arrangement;
	char *word;
	char symbol;
	int  check = 0, logo = 0;

	va_list args;

	va_start(args, format);

	word = "";

	for (arrangement = format; *arrangement; arrangement++)
	{
		if (*arrangement == '%')
		{
			arrangement++;
			if (*arrangement == 'c')
			{
				symbol = va_arg(args, int);

				if (b_putchar(symbol) == -1)
				{
					va_end(args);
					return (-1);
				}
				logo++;

			} else if (*arrangement == 's')
			{
				word = va_arg(args, char *);
				if (word == NULL)
				{
					word = "(null)";
				}

				while (word[check])
				{
					if (b_putchar(word[check]) == -1)
					{
						va_end(args);
						return (-1);
					}
					check++;
					logo++;
				}
			} else if (*arrangement == '%')
			{
				if (b_putchar('%') == -1)
				{
					va_end(args);
					return (-1);
				}
				logo++;
			}
		}
		else
		{
			if (b_putchar(*arrangement) == -1)
			{
				va_end(args);
				return (-1);
			}
			logo++;
		}
	}
	va_end(args);
	return (logo);
}
