#include "main.h"

int _printf(const char *format, ...)
{
	char *buffer;
	const char *str;
	int buffer_index = 0, buffer_size = 0;
	va_list arg_list;

	va_start(arg_list, format);

	if (format == NULL)
		return (-1);
	while (format[buffer_size] != '\0')
		buffer_size++;

	buffer = malloc(buffer_size + 1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					buffer[buffer_index++] = (char)va_arg(arg_list, int);
					break;
				case 's':
				{
					str = va_arg(arg_list, const char *);
					while (*str)
					{
						buffer[buffer_index++] = *str++;
					}
					break;
				}
				case '%':
					buffer[buffer_index++] = '%';
					break;
				default:
					break;
				}
			}
			else
			{
				buffer[buffer_index++] = *format;
			}
			format++;
	}
		buffer[buffer_index++] = '\0';
		va_end(arg_list);

		write(1, buffer, buffer_index);
		free(buffer);
		return (buffer_index);
}
