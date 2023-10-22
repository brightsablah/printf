#include "main.h"

void parse_format_options(va_list arg, const char *format, unsigned int *index,
format_options *options)
{
	options->width = -1;
	options->precision = -1;

	(*index)++;

	if (format[*index] == '*')
	{
		options->width = va_arg(arg, int);
		(*index)++;
	}
	if (isdigit(format[*index]))
	{
		options->width = 0;
		options->width = strtol(format + *index, NULL, 10);
		while (isdigit(format[*index]))
		{
			(*index)++;
		}
	}

	if (format[*index] == '.')
	{
		options->precision = 0;
		(*index)++;
		if (format[*index] == '*')
			{
				options->precision = va_arg(arg, int);
				(*index)++;
			}
		if (isdigit(format[*index]))
		{
			options->precision = strtol(format + *index, NULL, 10);
			while (isdigit(format[*index]))
			{
				(*index)++;
			}
		}
	}
}
