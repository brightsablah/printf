/**
 * print_char - Prints a character
 * @arg: A va_list containing the character to print
 *
 * Description:
 * This function prints a character to the standard output.
 */
void print_char(va_list arg)
{
	char c = va_arg(arg, int);

	_putchar(c);
}
