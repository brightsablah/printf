#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char output_buffer[BUFFER_SIZE];
int buffer_index = 0;

int _printf(const char *format, ...)
{
    va_list arg_list;
    int len = 0;

    va_start(arg_list, format);

    while (format[len] != '\0')
    {
        if (format[len] == '%')
        {
            handle_flags(arg_list, format + len + 1);
            len++;
        }
        else
        {
            _putchar(format[len]);
        }
        len++;
    }

    va_end(arg_list);
    write_buffer();

    return buffer_index;
}
void handle_flags(va_list arg_list, const char *format)
{
    int width = 0;
    int precision = -1;
    int flags = 0;

    while (1)
    {
        if (*format == '+')
        {
            flags |= 1;
            format++;
        }
        else if (*format == ' ')
        {
            flags |= 2;
            format++;
        }
        else if (*format == '#')
        {
            flags |= 4;
            format++;
        }
        else if (*format == '0')
        {
            flags |= 8;
            format++;
        }
        else if (*format == '-')
        {
            flags |= 16;
            format++;
        }
        else
        {
            break;
        }
    }

    if (*format >= '0' && *format <= '9')
    {
        
    }

    if (*format == '.')
    {
        format++;
        if (*format >= '0' && *format <= '9')
        {
            precision = strtol(format, (char**)&format, 10);
        }
        else if (*format == '*')
        {
            precision = va_arg(arg_list, int);
            format++;
        }
    }

    switch (*format)
    {
        case 'c':
        {
            char c = va_arg(arg_list, int);
            break;
        }
        case 's':
        {
            char *str = va_arg(arg_list, char *);
            break;
        }
        case 'd':
        case 'i':
        {
            int num = va_arg(arg_list, int);
	    break;
        }
        case 'u':
        {
            unsigned int num = va_arg(arg_list, unsigned int);
	    break;
        }
        default:
            break;
    }
}
void print_char(va_list arg)
{
    char c = va_arg(arg, int);
    _putchar(c);
}

void print_string(va_list arg)
{
    char *str = va_arg(arg, char *);
    char *null_str = "(null)";

    if (str == NULL) {
        while (*null_str) {
            _putchar(*null_str);
            null_str++;
        }
    } else {
        while (*str) {
            _putchar(*str);
            str++;
        }
    }
}



void print_percent(va_list arg)
{
    (void)(arg);
    _putchar('%');
}

int _putchar(char c)
{
    if (buffer_index < BUFFER_SIZE) {
        output_buffer[buffer_index++] = c;
        return 1;  
    } else {
        write_buffer();  
        return _putchar(c); 
    }
}

void write_buffer(void)
{
    ssize_t result = write(STDOUT_FILENO, output_buffer, buffer_index);
    if (result == -1) {
        
    }
    
}
int _print_number(int num)
{
    int count = 0;
    char *int_min = "-2147483648";

    if (num == INT_MIN) {
        /* Handle the special case of the largest negative value */
        while (int_min[count] != '\0') {
            if (_putchar(int_min[count])) {
                count++;
            } else {
                write_buffer();  /* Buffer is full, so write its contents */
            }
        }
    } else if (num < 0) {
        if (_putchar('-')) {
            count++;
        } else {
            write_buffer();  /* Buffer is full, so write its contents */
        }
        num = -num;
    }

    if (num != INT_MIN) {
        if (num / 10) {
            count += _print_number(num / 10);
        }

        if (_putchar('0' + num % 10)) {
            count++;
        } else {
            write_buffer();  /* Buffer is full, so write its contents */
        }
    }

    return count;
}


  void print_reverse(va_list arg)
  {
    char *str = va_arg(arg, char *);

    int length = 0, i;
    if (str == NULL)
    {
      return;
    }

      while (str[length] != '\0')
      {
          length++;
      }

      for (i = length - 1; i >= 0; i--)
      {
          _putchar(str[i]);
      }
  }

void print_rot13(va_list arg)
{
  char *str = va_arg(arg, char *);
    char *rot13_str;
    int i;

  if (str == NULL)
    return;

  rot13_str = _strdup(str);
    if (rot13_str == NULL)
      return;

 rot13(rot13_str);

  for (i = 0; rot13_str[i] != '\0'; i++)
    _putchar(rot13_str[i]);

}

  /**
  * _strdup - duplicates string
  * Description: cpoies string into another initialized memory
  * @str: string to be copied
  *
  * Return: pointer to duplicate string or null if unsuccessful
  */

  char *_strdup(char *str)
  {
    char *dupstr;
    int len = 0, i;

    if (str == NULL)
    {
      return (NULL);
    }

    while (str[len] != '\0')
    {
      len++;
    }

    dupstr = (char *)(malloc((len + 1) * sizeof(char)));

    if (dupstr == NULL)
    {
      return (NULL);
    }

    for (i = 0; i < len; i++)
    {
      dupstr[i] = str[i];
    }

    /* null teminating duplicate string */
    dupstr[len] = '\0';

    return (dupstr);
  }

/**
* rot13 - encodes string into rot13
* Description: converts all specified characters into
* specified codes
* @str: pointer to string input
* Return: Pointer to converted string
*/
char *rot13(char *str)
{
  int i, j;
  char a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char b[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";


  for (i = 0; str[i] != '\0'; i++)
  {
    for (j = 0; a[j] != '\0'; j++)
    {
      if (str[i] == a[j])
      {
        str[i] = b[j];
        break;
      }
    }
  }
return (str);

}


  void print_ASCII_string(va_list arg)
  {
      char *str = va_arg(arg, char *);
      if (str == NULL) {
          return;
      }
      while (*str) {
          if (*str < 32 || *str >= 127) {
              /* Print non-printable characters as \x followed by the ASCII code value */
              _putchar('\\');
              _putchar('x');
              _putchar((*str / 16 < 10) ? ('0' + (*str / 16)) : ('A' + (*str / 16 - 10)));
              _putchar((*str % 16 < 10) ? ('0' + (*str % 16)) : ('A' + (*str % 16 - 10)));
          } else {
              _putchar(*str);
          }
          str++;
      }
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
  char *null_ptr = "(nil)";

  if (ptr == NULL) {
      /* Handle the special case of a NULL pointer */
      while(*null_ptr != '\0')
      {
        _putchar(*null_ptr++);
      }
/* Print a (nil) for NULL pointer */
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

    /*printf("%p", ptr);*/
}

void print_binary(va_list arg)
{
    unsigned int num = va_arg(arg, unsigned int);
    int leading_zeros = 1;  /* Flag to skip leading zeros*/
    int i;

    /* Special case for num = 0*/
    if (num == 0)
    {
      _putchar('0');
      return;
    }

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
