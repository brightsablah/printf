#include "print.h"


void print_all(const char * const format, ...)
{
	unsigned int i = 0, j = 0, match;
	va_list arg_list;
	fmt_spec specifiers[] = {{'c', print_char}, {'i', print_int}, {'f', print_float}, {'s', print_string}};

	va_start(arg_list, format);

	while (format != NULL && format[i] != '\0')
	{
		match = 0;
		for (j = 0; j < sizeof(specifiers) / sizeof(specifiers[0]); j++)
		{
			if (format[i] == specifiers[j].format)
			{
				specifiers[j].print_function(arg_list);
				match = 1;
				break;
			}
		}

		if (format [i + 1] != '\0' && match == 1)
			printf(", ");

		i++;
	}
	printf("\n");
	va_end(arg_list);
}

void print_string(va_list arg)
{
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

void print_float(va_list arg)
{
	printf("%f", va_arg(arg, double));
}

void print_int(va_list arg)
{
	printf("%d", va_arg(arg, int));
}

void print_char(va_list arg)
{
	char c = va_arg(arg, int);
	printf("%c", c);
}
