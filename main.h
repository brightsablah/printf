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
#include <ctype.h>
#include <string.h>

/**
* struct format - A structure managing format options
* @width: output width
* @precision: output precision
*
*/
struct format
{
	int width;
	int precision;
};
typedef struct format format_options;

void parse_format_options(va_list, const char *, unsigned int *,
format_options *);

/**
 * struct buff - A structure for managing the output buffer
 * @output_buffer: The character array to store the buffer data
 * @buffer_index: The current size of the buffer
 * @char_count: number of characters added to buffer
 * @temp_buffer: temporal buffer to manage output
 * Description:
 * This structure is used to manage the output buffer for _printf.
 */
struct buff
{
	char output_buffer[BUFFER_SIZE];
	size_t buffer_index;
	int char_count;
	char *temp_buffer;
};
typedef struct buff Buffer;

void buffer_init(Buffer *buffer);
void buffer_append_char(Buffer *, char);
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
	void (*print_function)(va_list, Buffer *, format_options *options);
};
typedef struct fmt fmt_spec;


/* Print Function prototypes */
int _printf(const char *format, ...);
void print_char(va_list arg, Buffer *buffer, format_options *options);
void print_string(va_list arg, Buffer *buffer, format_options *options);
void print_int(va_list arg, Buffer *buffer, format_options *options);
void print_unsigned(va_list arg, Buffer *buffer, format_options *options);
void print_octal(va_list arg, Buffer *buffer, format_options *options);
void print_hex(va_list arg, Buffer *buffer, format_options *options);
void print_hex_upper(va_list arg, Buffer *buffer, format_options *options);
void print_pointer(va_list arg, Buffer *buffer, format_options *options);
void print_percent(va_list arg, Buffer *buffer, format_options *options);
void print_binary(va_list arg, Buffer *buffer, format_options *options);
void print_reverse(va_list arg, Buffer *buffer, format_options *options);
void print_rot13(va_list arg, Buffer *buffer, format_options *options);
void print_ASCII_string(va_list arg, Buffer *buffer, format_options *options);

/* Support Functions */
void write_buffer(void);
int _putchar(char c);
int _print_number(int num, Buffer *buffer);
char *rot13(char *str);
char *_strdup(char *str);
int number_length(int num);

#endif
