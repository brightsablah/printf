#include "main.h"
/**
 * print_string - Prints a string
 * @arg: A va_list containing the string to print
 * @buffer: pointer a buffer that stores print output
 *
 * Description:
 * This function prints a string to the standard output.
 * If the string is NULL, it prints "(null)" instead.
 */
void print_string(va_list arg, Buffer *buffer, format_options *options)
{
	char *str = va_arg(arg, char *);
	char *null_str = "(null)";
	int len, spaces, i;

	(void)(options);

	if (str == NULL)
	{
		len = strlen(null_str);
		spaces = options->width - len;
		while (spaces > 0)
		{
			buffer_append_char(buffer, ' ');
			spaces--;
		}
		while (*null_str)
		{
			buffer_append_char(buffer, *null_str);
			null_str++;
		}
	}
	else
	{
		len = strlen(str);
		spaces = options->width - len;
		while (spaces > 0)
		{
			buffer_append_char(buffer, ' ');
			spaces--;
		}

		if (options->precision > 0)
		{
			if (options->precision > len)
			{
				while (*str)
				{
					buffer_append_char(buffer, *str);
					str++;
				}
			}
			else
			{
				for (i = 0; i < options->precision; i++)
				{
					if (str[i] != '\0')
					{
						buffer_append_char(buffer, str[i]);
					}
				}
				buffer_append_char(buffer, '\0');
			}
		return;

		}
		while (*str)
		{
			buffer_append_char(buffer, *str);
			str++;
		}
	}
}
