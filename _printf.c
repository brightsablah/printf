#include "main.h"

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
	Buffer buffer; /* declaring buffer */

	va_start(arg_list, format);
	if (format == NULL)
	return (-1);

	buffer_init(&buffer); /* buffer initialization */
/* Resetting buffer index to zero at start of each _printf call */

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == ' ' && format[i + 2] == '\0')
				i++;

			if (format[i + 1] == '\0')
			{
				buffer_append_char(&buffer, '%');
				return (-1);
			}

			specifier_found = 0;
			for (j = 0; j < sizeof(specifiers) / sizeof(specifiers[0]); j++)
			{
				if (format[i + 1] == specifiers[j].format)
				{
					if (specifiers[j].print_function != NULL)
					{
						specifiers[j].print_function(arg_list, &buffer); /*call print function*/
					}
					else
					{
						buffer_append_char(&buffer, '%');
						buffer_append_char(&buffer, format[i + 1]); /* print specifier */
					}
					specifier_found = 1; /* character after % handled */
					i++; /* skip specifier character */
					break;
				}
			}
			if (!specifier_found)
				buffer_append_char(&buffer, '%');
		}
		else
		{
		buffer_append_char(&buffer, format[i]);
		}
		i++;
	}
	va_end(arg_list);
	buffer_flush(&buffer); /* flush buffer */

	return (buffer.char_count);
}
