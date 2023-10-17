/**
* print_ASCII_string - Prints a string with non-printable
* ASCII characters as '\xXX'
* @arg: A va_list containing the string to print
*
* Description:
* This function prints a string, representing non-printable ASCII characters
* as '\x' followed by the ASCII code value. It handles special cases where
* characters are not printable.
*/
void print_ASCII_string(va_list arg)
{
	char *str = va_arg(arg, char *);

/* special case for NULL string */
	if (str == NULL)
		return;

	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			/* Print non-printable characters as \x followed by the ASCII code value */
			_putchar('\\');
			_putchar('x');
			_putchar((*str / 16 < 10) ? ('0' + (*str / 16)) : ('A' + (*str / 16 - 10)));
			_putchar((*str % 16 < 10) ? ('0' + (*str % 16)) : ('A' + (*str % 16 - 10)));
		}
		else
		{
			_putchar(*str);
		}
		str++;
	}
}
