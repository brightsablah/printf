#include "main.h"

static char output_buffer[BUFFER_SIZE]; /* array storing output to be printed */
static int buffer_index = 0;/* track position in output buffer */


/**
 * _printf - take format string and print output
 * @format: string analysed
 *
 * Return: amount of printed characters
 */
int _printf(const char *format, ...)
{
    unsigned int i = 0, j = 0;
    va_list arg_list;
    /* match format specifier to matching print function */
    fmt_spec specifiers[] = {
        {'%', print_percent},
        {'c', print_char},
        {'s', print_string},
        {'i', print_int},
        {'d', print_int},
        {'u', print_unsigned},
        {'o', print_octal},
        {'x', print_hex},
        {'X', print_hex_upper},
        {'p', print_pointer},
        {'b', print_binary},
        {'r', print_reverse},
        {'R', print_rot13},
        {'S', print_ASCII_string},
    };

    va_start(arg_list, format);

    if(format == NULL)
      return (-1);

  /* resetting buffer index to zero at the beginning of each _printf call */
  buffer_index = 0;

  while (format != NULL && format[i] != '\0')
    {
        if (format[i] == '%')
        {
            int specifier_found = 0;
            for (j = 0; j < sizeof(specifiers) / sizeof(specifiers[0]); j++)
            {
                if (format[i + 1] == specifiers[j].format)
                {
                    if (specifiers[j].print_function != NULL)
                    {
                        specifiers[j].print_function(arg_list);
                    }
                    else
                    {
                        _putchar('%');
                        _putchar(format[i + 1]);
                       /* printf("Unsupported specifier: %%%c\n", format[i + 1]); */
                    }
                    specifier_found = 1;
                    i++;  /* Skip the specifier character */
                    break;
                }
            }
            if (!specifier_found)
            {
                /*printf("%%");*/
                _putchar('%');
                /*i++;*/
              /* Treat %% as a literal % */
            }
        }
        else
        {
            _putchar(format[i]);
        }
        i++;
    }
  /* cleanup and return */
  va_end(arg_list);
  write_buffer();

  return(buffer_index);
}