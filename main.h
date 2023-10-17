#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024

#include <stdarg.h> /* for variadic function */
#include <stdlib.h> /* for malloc and free */
#include <unistd.h> /* used by write */
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
void handle_flags(va_list arg_list, const char *format);
int _printf(const char *format, ...);
void print_char(va_list arg);
void print_string(va_list arg);
void print_int(va_list arg);
void print_unsigned(va_list arg);
void print_octal(va_list arg);
void print_hex(va_list arg);
void print_hex_upper(va_list arg);
void print_pointer(va_list arg);
void print_percent(va_list arg);
void print_binary(va_list arg);
void print_reverse(va_list arg);
void print_rot13(va_list arg);
void print_ASCII_string(va_list arg);
char *_strdup(char *str);
char *rot13(char *str);
int _putchar(char c);
void write_buffer(void);
int _print_number(int num);
#endif
