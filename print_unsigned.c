#include "main.h"
/**
* print_unsigned - Prints an unsigned integer
* @arg: A va_list containing the unsigned integer to print
* @buffer: pointer a buffer that stores print output
*
* Description:
* This function prints an unsigned integer to the standard output.
*/
void print_unsigned(va_list arg, Buffer *buffer, format_options *options)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int temp;
	int num_digits;
	int i, len, spaces, zeroes;
	char decimal_representation[16];/* Maximum 16 chars for unsigned int */

/* special case for unsigned number = 0 */
	if (num == 0)
	{
		len = 1;
		spaces = options->width - len;
		while (spaces > 0)
		{
			buffer_append_char(buffer, ' ');
			spaces--;
		}
		if (options->precision > len)
		{
			zeroes = options->precision - len;
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

		buffer_append_char(buffer, '0');
		return;
	}

	temp = num;
	num_digits = 0;
	while (temp > 0) /* finding number of digits */
	{
		temp /= 10;
		num_digits++;
	}
/* passing character of numbers to the array */
	for (i = num_digits - 1; i >= 0; i--)
	{
		decimal_representation[i] = '0' + (num % 10);
		num /= 10;
	}

	len = num_digits;
	spaces = options->width - len;
	while (spaces > 0)
	{
		buffer_append_char(buffer, ' ');
		spaces--;
	}
	if (options->precision > len)
	{
		zeroes = options->precision - len;
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

/* printing out characters in the array */
	for (i = 0; i < num_digits; i++)	{
		buffer_append_char(buffer, decimal_representation[i]);
	}
}
