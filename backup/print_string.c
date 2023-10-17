/**
 * print_string - Prints a string
 * @arg: A va_list containing the string to print
 *
 * Description:
 * This function prints a string to the standard output.
 * If the string is NULL, it prints "(null)" instead.
 */
void print_string(va_list arg)
{
	char *str = va_arg(arg, char *);
	char *null_str = "(null)";

	if (str == NULL)
	{
		while (*null_str)
		{
			_putchar(*null_str);
			null_str++;
		}
	}
	else
	{
		while (*str)
		{
			_putchar(*str);
			str++;
		}
	}
}
