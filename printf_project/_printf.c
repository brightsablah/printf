#include "main.h"

static char output_buffer[BUFFER_SIZE];
static int buffer_index = 0;

/**
* _printf - Custom printf function
* @format: The format string
* @...: Variable number of arguments
*
* Description:
* This function mimics the behavior of the standard printf function,
* supporting various format specifiers, and writing the output
* to the standard output
* Return: The number of characters written to the standard output.
*/
int _printf(const char *format, ...)
{
	unsigned int i = 0, j = 0;
	int specifier_found;
	va_list arg_list;
	fmt_spec specifiers[] = {
		{'%', print_percent},
		{'c', print_char},
		{'s', print_string},
		{'i', print_int},
		{'d', print_int},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hex},
		{'X', print_hex_upper},
		{'p', print_pointer},
		{'b', print_binary},
		{'r', print_reverse},
		{'R', print_rot13},
		{'S', print_ASCII_string},
	};

	va_start(arg_list, format);
	if (format == NULL)
	return (-1);

/* Resetting buffer index to zero at start of each _printf call */
	buffer_index = 0;

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == ' ' && format[i + 2] == '\0')
				i++;

			specifier_found = 0;
			for (j = 0; j < sizeof(specifiers) / sizeof(specifiers[0]); j++)
			{
				if (format[i + 1] == specifiers[j].format)
				{
					if (specifiers[j].print_function != NULL)
					{
						specifiers[j].print_function(arg_list); /*call the print function*/
					}
					else
					{
						_putchar('%');
						_putchar(format[i + 1]); /* print unsupported specifier */
					}
					specifier_found = 1; /* character after % handled */
					i++; /* skip specifier character */
					break;
				}
			}
			if (!specifier_found)
				_putchar('%');
		}
		else
		{
		_putchar(format[i]);
		}
		i++;
	}
	va_end(arg_list);
	write_buffer(); /* flush buffer */

	return (buffer_index);
}
