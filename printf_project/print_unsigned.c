#include "main.h"
/**
* print_unsigned - Prints an unsigned integer
* @arg: A va_list containing the unsigned integer to print
*
* Description:
* This function prints an unsigned integer to the standard output.
*/
void print_unsigned(va_list arg, Buffer *buffer)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int temp;
	int num_digits;
	int i;
	char decimal_representation[16];/* Maximum 16 chars for an unsigned int */

/* special case for unsigned number = 0 */
	if (num == 0)
	{
		buffer_append_char(&buffer, '0');
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
/* printing out characters in the array */
	for (i = 0; i < num_digits; i++)
	{
		buffer_append_char(&buffer, decimal_representation[i]);
	}
}
