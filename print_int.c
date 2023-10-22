#include "main.h"
/**
* print_int - Prints an integer
* @arg: A va_list containing the integer to print
* @buffer: pointer a buffer that stores print output
*
* Description:
* This function prints an integer to the standard output.
*/
void print_int(va_list arg, Buffer *buffer, format_options *options)
{
	int num, len, spaces, zeroes;

	num = va_arg(arg, int);
	len = number_length(num);
	spaces = options->width - len;

	while (spaces > 0)
	{
		buffer_append_char(buffer, ' ');
		spaces--;
	}

	if (options->precision > len)
	{
		zeroes = options->precision - len;
		if (num < 0)
		{
			buffer_append_char(buffer, '-');
			num = -num;
			zeroes++;
		}
		while (zeroes > 0)
		{
			buffer_append_char(buffer, '0');
			zeroes--;
		}
	}
	else if (options->precision == 0)
	{
		return;
	}

	_print_number(num, buffer);
}
