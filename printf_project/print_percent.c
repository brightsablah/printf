#include "main.h"
/**
* print_percent - Prints a percent sign
* @arg: A va_list (unused)
*
* Description:
* This function prints a percent sign ("%") to the standard output.
*/
void print_percent(va_list arg)
{
	(void)arg; /* Unused parameter */

	buffer_append_char(&buffer, '%');
}

