#include "main.h"
/**
* print_pointer - Prints a pointer address
* @arg: A va_list containing the pointer to print
*
* Description:
* This function prints a pointer address in hexadecimal format
* to the standard output.
*/
void print_pointer(va_list arg)
{
	void *ptr = va_arg(arg, void *);
	int i, num_digits;
	char hex_representation[16];
	uintptr_t temp;
	uintptr_t ptr_value;
	char *null_ptr = "(nil)";

	char *hex_digits "0123456789abcdef";
/* special case for when ptr is NULL */
	if (ptr == NULL)
	{
		while (*null_ptr != '\0')
		{
		_putchar(*null_ptr++);
		}
	}
	else
	{
		_putchar('0'); /* starting hex printing with '0x' */
		_putchar('x');
		ptr_value = (uintptr_t)ptr; /* converting ptr value to unsingned int */
		num_digits = 0;
		temp = ptr_value;
		while (temp > 0) /* checking number of digits in converted value */
		{
			temp /= 16;
			num_digits++;
		}
/* doing number base division and passing the remainder to hex array */
		for (i = num_digits - 1; i >= 0; i--)
		{
			hex_representation[i] = hex_digits[ptr_value % 16];
			ptr_value /= 16;
		}
/* printing content of hex array */
		for (i = 0; i < num_digits; i++)
		{
			_putchar(hex_representation[i]);
		}
	}
}
