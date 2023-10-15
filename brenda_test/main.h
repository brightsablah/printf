#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024

#include <stdarg.h> /* for variadic function */
#include <stdlib.h> /* for malloc and free */
#include <unistd.h> /* used by write */

int _print_number(int num);
int b_putchar(char b);
int b_putstr(char *str);
int print_b_char(va_list args);
int print_b_string(va_list args);
int print_b_integer(va_list args);
int print_b_float(va_list args);
int _printf(const char *format, ...);
int b_flush_buffer(void);

#endif
