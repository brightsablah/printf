#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

/* Including Headers */
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>

/**
 * struct Buffer - A structure for managing the output buffer
 * @output_buffer: The character array to store the buffer data
 * @buffer_index: The current size of the buffer
 *
 * Description:
 * This structure is used to manage the output buffer for _printf.
 */
struct buff
{
	char output_buffer[BUFFER_SIZE];
	size_t buffer_index;
}; 
typedef struct buff Buffer;

void buffer_init(Buffer *buffer);
void buffer_append_char(Buffer *buffer, char c);
void buffer_flush(Buffer *buffer);

/**
 * struct fmt - Format specifier struct
 * @format: The character representing the format specifier
 * @print_function: Function pointer to the print function to be invoked
 *
 * Description:
 * This structure defines a format specifier and its associated print function.
 */
struct fmt
{
	char format;
	void (*print_function)(va_list);
};
typedef struct fmt fmt_spec;


/* Print Function prototypes */
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

/* Support Functions */
void write_buffer(void);
int _putchar(char c);
int _print_number(int num);
char *rot13(char *str);
char *_strdup(char *str);

#endif
