#include "main.h"
/**
* print_reverse - Prints a string in reverse
* @arg: A va_list containing the string to print
*
* Description:
* This function prints a string in reverse order to the standard output.
*/
void print_reverse(va_list arg)
{
	char *str = va_arg(arg, char *);
	int length = 0, i;

/* special case for NULL string */
	if (str == NULL)
		return;

/* checking length of string */
	while (str[length] != '\0')
	{
		length++;
	}
/* print characters in reverse */
	for (i = length - 1; i >= 0; i--)
	{
		buffer_append_char(&buffer, str[i]);
	}
}
