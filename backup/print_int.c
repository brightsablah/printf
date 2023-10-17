#include "main.h"
#include "main.h"
/**
* print_int - Prints an integer
* @arg: A va_list containing the integer to print
*
* Description:
* This function prints an integer to the standard output.
*/
void print_int(va_list arg)
{
	int num = va_arg(arg, int);

	_print_number(num);
}
