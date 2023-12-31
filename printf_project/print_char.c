#include "main.h"
/**
 * print_char - Prints a character
 * @arg: A va_list containing the character to print
 *
 * Description:
 * This function prints a character to the standard output.
 */
void print_char(va_list arg, Buffer *buffer)
{
	char c = va_arg(arg, int);

	buffer_append_char(buffer, c);
}
