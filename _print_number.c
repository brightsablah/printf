#include "main.h"
/**
* _print_number - Prints an integer
* @num: The integer to print
* @buffer: pointer a buffer that stores print output
*
* Description:
* This function prints an integer to the standard output.
* It handles the special case
* of the largest negative value (INT_MIN) and
* uses recursion to print the digits.
* Return: The function returns the number of characters printed.
*/
int _print_number(int num, Buffer *buffer)
{
	int count = 0;
	char *int_min = "-2147483648";

/* special case for largest negative number */
	if (num == INT_MIN)
	{
		while (int_min[count] != '\0')
		{
			buffer_append_char(buffer, int_min[count]);
			count++;
		}
	}
	else if (num < 0) /* handle negatives */
	{
		buffer_append_char(buffer, '-');
		count++;
		num = -num;
	}
/* handle other cases */
	if (num != INT_MIN)
	{
		if (num / 10)
		count += _print_number(num / 10, buffer);

		buffer_append_char(buffer, '0' + num % 10);
		count++;
	}

	return (count);
}
