#ifndef VARIADIC_H
#define VARIADIC_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void print_all(const char * const format, ...);

/**
* struct fmt - format specifier struct
* @format: character representing format specifier
* @print_function: function pointer to the print function to be invoked
*/
struct fmt
{
	char format;
	void (*print_function)(va_list);
};
typedef struct fmt fmt_spec;

void print_char(va_list);
void print_string(va_list);
void print_int(va_list);
void print_float(va_list);

#endif
