#include "main.h"
/**
* print_int - Prints an integer
* @arg: A va_list containing the integer to print
*
* Description:
* This function prints an integer to the standard output.
*/
void print_int(va_list arg, Buffer *buffer)
{
	int num = va_arg(arg, int);

	void(*buffer);
	_print_number(num);
}
