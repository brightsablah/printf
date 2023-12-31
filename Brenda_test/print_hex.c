#include "main.h"
/**
* print_hex - Prints an integer in hexadecimal (lowercase)
* @arg: A va_list containing the integer to print
*
* Description:
* This function prints an integer in hexadecimal (lowercase)
* format to the standard output.
*/
void print_hex(va_list arg, Buffer *buffer)
{
	unsigned int num = va_arg(arg, unsigned int);
	char hex_digits[16] = "0123456789abcdef"; /* Hexadecimal digits */
	char hex_representation[8]; /* Assuming 8 characters for a 32-bit integer */
	int count = 0, i;

/* special case for num = 0 */
	if (num == 0)
	{
		buffer_append_char(buffer, '0');
		return;
	}
/* doing number base division and adding remainders to hex array */
	while (num > 0)
	{
		hex_representation[count++] = hex_digits[num % 16];
		num /= 16;
	}
/* printing out the elements of the hex array */
	for (i = count - 1; i >= 0; i--)
	{
		buffer_append_char(buffer, hex_representation[i]);
	}
}
