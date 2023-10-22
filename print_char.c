#include "main.h"
/**
 * print_char - Prints a character
 * @arg: A va_list containing the character to print
 * @buffer: pointer a buffer that stores print output
 *
 * Description:
 * This function prints a character to the standard output.
 */
void print_char(va_list arg, Buffer *buffer, format_options *options)
{
	char c = va_arg(arg, int);
	int len = 1;
	int spaces = options->width - len;

	while (spaces > 0)
	{
		buffer_append_char(' ');
		spaces--;
	}

	buffer_append_char(buffer, c);
}
