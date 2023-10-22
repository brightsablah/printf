#include "main.h"
/**
* print_percent - Prints a percent sign
* @arg: A va_list (unused)
* @buffer: pointer a buffer that stores print output
*
* Description:
* This function prints a percent sign ("%") to the standard output.
*/
void print_percent(va_list arg, Buffer *buffer, format_options *options)
{
	(void)arg; /* Unused parameter */

	buffer_append_char(buffer, '%');
}
