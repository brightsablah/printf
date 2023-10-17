#include "main.h"
/**
 * print_string - Prints a string
 * @arg: A va_list containing the string to print
 *
 * Description:
 * This function prints a string to the standard output.
 * If the string is NULL, it prints "(null)" instead.
 */
void print_string(va_list arg, Buffer *buffer)
{
	char *str = va_arg(arg, char *);
	char *null_str = "(null)";

	if (str == NULL)
	{
		while (*null_str)
		{
			buffer_append_char(&buffer, *null_str);
			null_str++;
		}
	}
	else
	{
		while (*str)
		{
			buffer_append_char(&buffer, *str);
			str++;
		}
	}
}
