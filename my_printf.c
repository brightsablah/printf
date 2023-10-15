#include "main.h"

/**
 * b_putchar - custom function to print a character and handle errors
 * @b: character to write to standard output
 *
 * Return: 0 for success and -1 for error
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
 * _printf - print various customised data types
 * @format: list of arguments
 *
 * Return: number of printed characters excluding the null byte
 */
int _printf(const char *format, ...)
{
	const char *arrangement;
	int logo = 0;

	int (*get_my_func)(va_list);

	va_list args;

	va_start(args, format);

	for (arrangement = format; *arrangement; arrangement++)
	{
		if (*arrangement == '%')
		{
			arrangement++;

			if (*arrangement == '%')
			{
				if (b_putchar('%') == -1)
				{
					va_end(args);
					return (-1);
				}
				logo++;
			} else
			{
				switch (*arrangement)
				{
				case 'c':
					get_my_func = print_b_char;
					break;
				case 's':
					get_my_func = print_b_string;
					break;
				case 'd':
					get_my_func = print_b_integer;
					break;
				case 'i':
					get_my_func = print_b_float;
					break;
				default:
					get_my_func = NULL;
					break;
				}

				if (get_my_func)
				{
					logo += get_my_func(args);
				} else
				{
					if (b_putchar('%') == -1)
					{
						va_end(args);
						return (-1);
					}
					if (b_putchar(*arrangement) == -1)
					{
						va_end(args);
						return (-1);
					}
					logo += 1;
				}
			}
		} else
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
