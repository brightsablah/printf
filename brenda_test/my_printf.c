#include "main.h"

#define BUFFER_SIZE 1024

static char b_output[BUFFER_SIZE];
static int b_index;

/**
 * b_flush_buffer - flushes output buffer to write to std output
 *
 * Return: 0 for success , -1 for error
 */
int b_flush_buffer(void)
{
	if (write(1, b_output, b_index) == -1)
	{
		return (-1);
	}
	b_index = 0; /* Reset the buffer index */

	return (0);
}

/**
 * b_putchar - custom function to print a character and handle errors
 * @b: character to write to standard output
 *
 * Return: 0 for success and -1 for error
 */
int b_putchar(char b)
{
	if (b_index == BUFFER_SIZE)
	{
		if (b_flush_buffer() == -1)
		{
			return (-1);
		}
	}
	b_output[b_index++] = b;

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
				case 'i':
					get_my_func = print_b_integer;
					break;
				case 'd':
					get_my_func = print_b_integer;
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
	if (b_flush_buffer() == -1)
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	return (logo);
}
