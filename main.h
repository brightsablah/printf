#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

void write_buffer(void);
int _printf(const char *format, ...);
int _putchar(char c);
int _print_number(int num);
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

/* Function prototypes */
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
/*
struct fmt
{
  char format;
  int (*print_function)(char *, va_list);
};
typedef struct fmt fmt_spec;

int print_char(char *, va_list);
int print_string(char *, va_list);
int print_int(char *, va_list);
int print_float(char *, va_list);
int print_percent(char *, va_list);
int print_unsigned(char *, va_list);
int print_hex(char *, va_list);
int print_hex_upper(char *, va_list);
int print_percent(char *, va_list);
int print_octal(char *, va_list);
int print_pointer(char *, va_list);
int print_binary(char *, va_list);
*/
#endif
