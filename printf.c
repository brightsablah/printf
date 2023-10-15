#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>


int _printf(const char *format, ...)
{
    unsigned int i = 0, j = 0;
    va_list arg_list;
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
        {'b', print_binary}
    };

    va_start(arg_list, format);

    if(format == NULL)
      return (-1);
  
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
                _putchar('%');  /* Treat %% as a literal % */
            }
        }
        else
        {
            _putchar(format[i]);
        }
        i++;
    }
    va_end(arg_list);
    return i;
}


void print_char(va_list arg)
{ 
     char c = va_arg(arg, int);
    _putchar(c);
}

void print_string(va_list arg)
{
    char *str = va_arg(arg, char *);
    while (*str)
      {
        _putchar(*str);
        str++;
      }
      /*if (str == NULL)
        str = "(nil)";
      printf("%s", str); */
}

void print_int(va_list arg)
{
    int num = va_arg(arg, int);

      _print_number(num);
    /*printf("%d", num);*/
}

void print_unsigned(va_list arg)
{
    unsigned int num = va_arg(arg, unsigned int);

  unsigned int temp;
  int num_digits;
  int i;
  /* Initialize an array to store decimal digits */
  char decimal_representation[16]; /* Maximum 16 characters for an unsigned int */
  
   /* Handle the special case of 0 */
    if (num == 0) {
        _putchar('0');
        return;
    }

    /* Calculate the number of decimal digits required */
    temp = num;
    num_digits = 0;
    while (temp > 0) {
        temp /= 10;
        num_digits++;
    }



    /* Extract and store each decimal digit in reverse order */
    for (i = num_digits - 1; i >= 0; i--) {
        decimal_representation[i] = '0' + (num % 10);
        num /= 10;
    }

    /* Print the decimal digits */
    for (i = 0; i < num_digits; i++) {
        _putchar(decimal_representation[i]);
    }
  
  /*printf("%u", num);*/
}

void print_octal(va_list arg)
{
    unsigned int num = va_arg(arg, unsigned int);
  int octal_digits[12]; /* Assuming a maximum of 12 octal digits*/
  int count = 0;
  int i;

  /* Handle the special case of 0*/
  if (num == 0) {
      _putchar('0');
      return;
  }

  /* Extract and store each octal digit in reverse order*/
  while (num > 0) {
      octal_digits[count++] = num % 8;
      num /= 8;
  }

  /* Print the octal digits in reverse order*/
  for (i = count - 1; i >= 0; i--) {
      _putchar('0' + octal_digits[i]);
  }
  
    /*printf("%o", num);*/
}

void print_hex(va_list arg)
{
    unsigned int num = va_arg(arg, unsigned int);
    char hex_digits[16] = "0123456789abcdef"; /* Hexadecimal digits*/
    char hex_representation[8]; /* Assuming 8 characters for a 32-bit integer*/
    int count = 0;
    int i;

    /* Handle the special case of 0*/
    if (num == 0) {
        _putchar('0');
        return;
    }

    /*Extract and store each hexadecimal digit in reverse order*/
    while (num > 0) {
        hex_representation[count++] = hex_digits[num % 16];
        num /= 16;
    }

    /* Print the hexadecimal digits in reverse order*/
    for (i = count - 1; i >= 0; i--) {
        _putchar(hex_representation[i]);
    }
  
  /*printf("%x", num);*/
}

void print_hex_upper(va_list arg)
{
    unsigned int num = va_arg(arg, unsigned int);
  char hex_digits[16] = "0123456789ABCDEF"; /* Uppercase hexadecimal digits*/
  char hex_representation[8]; /* Assuming 8 characters for a 32-bit integer*/
  int count = 0;
  int i;

  /*Handle the special case of 0*/
  if (num == 0) {
      _putchar('0');
      return;
  }

  /* Extract and store each uppercase hexadecimal digit in reverse order*/
  while (num > 0) {
      hex_representation[count++] = hex_digits[num % 16];
      num /= 16;
  }

  /* Print the uppercase hexadecimal digits in reverse order*/
  for (i = count - 1; i >= 0; i--) {
      _putchar(hex_representation[i]);
  }
    /*printf("%X", num);*/
}

void print_pointer(va_list arg)
{
    void *ptr = va_arg(arg, void *);

  int i, num_digits;
  char *hex_digits;
  char hex_representation[16];
  uintptr_t temp;
  uintptr_t ptr_value;

  if (ptr == NULL) {
      /* Handle the special case of a NULL pointer */
      _putchar('0');
      _putchar('x');
      _putchar('0'); /* Print a single zero for NULL pointer */
  } else {
      /* Print the "0x" prefix for a non-NULL pointer */
      _putchar('0');
      _putchar('x');

      /* Calculate the number of hexadecimal digits required */
      ptr_value = (uintptr_t)ptr;
      num_digits = 0;
      temp = ptr_value;
      while (temp > 0) {
          temp /= 16;
          num_digits++;
      }
    
    /* Initialize an array to store hexadecimal digits */
    hex_digits = "0123456789abcdef"; /* Uppercase hexadecimal digits */
   /* char hex_representation[16];  Maximum 16 characters for 64-bit pointer */

      /* Extract and store each uppercase hexadecimal digit in reverse order */
      for (i = num_digits - 1; i >= 0; i--) {
          hex_representation[i] = hex_digits[ptr_value % 16];
          ptr_value /= 16;
      }

      /* Print the uppercase hexadecimal digits */
      for (i = 0; i < num_digits; i++) {
          _putchar(hex_representation[i]);
      }
  }
  
/*
	char hex_digits[16] = "0123456789abcdef";
	char hex_representation[16];
	int count = 0;
  int i;

	unsigned long long address = (unsigned long long)ptr;

	while (address > 0)
	{
		hex_representation[count++] = hex_digits[address % 16];
		address /= 16;
	}

	_putchar('0');
	_putchar('x');

	for (i = count - 1; i >= 0; i--)
	{
		_putchar(hex_representation[i]);
	}
  */
    /*printf("%p", ptr);*/
}

void print_percent(va_list arg)
{
    (void)(arg);
    _putchar('%');
    /*printf("%c", '%');*/
}

void print_binary(va_list arg)
{
    unsigned int num = va_arg(arg, unsigned int);
    int leading_zeros = 1;  /* Flag to skip leading zeros*/
    int i;

    for (i = sizeof(unsigned int) * 8 - 1; i >= 0; i--)
    {
        int bit = (num >> i) & 1;
        if (bit || !leading_zeros)
        {
          _putchar('0' + bit);
          leading_zeros = 0;
            /*printf("%d", bit);*/
            /*leading_zeros = 0;*/
        }
    }
}

int _putchar(char c)
    {
      return (write(1, &c, 1));
    }

int _print_number(int num)
{
  int count = 0;

  if (num < 0)
    {
      _putchar('-');
      num  = -num;
    }
  
  if (num / 10)
    count += _print_number(num / 10);

  _putchar('0' + num % 10);
  count++;

  return (count);
}

