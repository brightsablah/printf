#include "main.h"
/**
* print_binary - Prints an integer in binary format
* @arg: A va_list containing the integer to print in binary
* @buffer: pointer a buffer that stores print output
*
* Description:
* This function prints an integer in binary format to the standard output.
*/
void print_binary(va_list arg, Buffer *buffer, format_options *options)
{
	unsigned int num = va_arg(arg, unsigned int);
	int leading_zeros = 1; /* Flag to skip leading zeros */
	int i, bit;

/* special case for num = 0 */
	if (num == 0)
	{
		buffer_append_char(buffer, '0');
		return;
	}
/* looping through bits of num value */
	for (i = sizeof(unsigned int) * 8 - 1; i >= 0; i--)
	{
/* checking for leading zeroes and printing bits */
		bit = (num >> i) & 1;
		if (bit || !leading_zeros)
		{
			buffer_append_char(buffer, '0' + bit);
			leading_zeros = 0;
		}
	}
}
