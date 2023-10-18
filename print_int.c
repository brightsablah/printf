#include "main.h"
/**
* print_int - Prints an integer
* @arg: A va_list containing the integer to print
* @buffer: pointer a buffer that stores print output
*
* Description:
* This function prints an integer to the standard output.
*/
void print_int(va_list arg, Buffer *buffer)
{
	int num = va_arg(arg, int);

	_print_number(num, buffer);
}
