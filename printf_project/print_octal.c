#include "main.h"
/**
* print_octal - Prints an octal number
* @arg: A va_list containing the octal number to print
*
* Description:
* This function prints an octal number to the standard output.
*/
void print_octal(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	int octal_digits[12]; /* Assuming a max of 12 octal digits enough for 32bit*/
	int count = 0;
	int i;

/* special case for num = 0 */
	if (num == 0)
	{
		buffer_append_char(&buffer, '0');
	return;
	}
/* doing number base division and passing remainder to octal array */
	while (num > 0)
	{
		octal_digits[count++] = num % 8;
		num /= 8;
	}
/* printing out octal digits */
	for (i = count - 1; i >= 0; i--)
	{
		buffer_append_char(&buffer, '0' + octal_digits[i]);
	}
}
