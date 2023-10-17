#include "main.h"
#include "main.h"
/**
* print_hex_upper - Prints an integer in hexadecimal (uppercase)
* @arg: A va_list containing the integer to print
*
* Description:
* This function prints an integer in hexadecimal (uppercase)
* format to the standard output.
*/
void print_hex_upper(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	char hex_digits[16] = "0123456789ABCDEF"; /*Upper Hexadecimal digits */
	char hex_representation[8]; /* Assuming 8 characters for a 32-bit integer */
	int count = 0, i;

/* special case for num = 0 */
	if (num == 0)
	{
		_putchar('0');
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
		_putchar(hex_representation[i]);
	}
}
