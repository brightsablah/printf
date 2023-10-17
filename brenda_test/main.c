#include <limits.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Positive with plus flag:[%+d]\n", 762534);
    len2 = printf("Positive with plus flag:[%+d]\n", 762534);
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;

    _printf("Left-justified with minus flag:[%-20s]\n", "Left Justified");
    printf("Left-justified with minus flag:[%-20s]\n", "Left Justified");

    _printf("Unsigned octal with # flag:[%#o]\n", ui);
    printf("Unsigned octal with # flag:[%#o]\n", ui);

    _printf("Unsigned hexadecimal with # flag:[%#x, %#X]\n", ui, ui);
    printf("Unsigned hexadecimal with # flag:[%#x, %#X]\n", ui, ui);

    _printf("Padded with zeros with 0 flag:[%05d]\n", 42);
    printf("Padded with zeros with 0 flag:[%05d]\n", 42);

    _printf("Space flag without sign:[% d]\n", 123);
    printf("Space flag without sign:[% d]\n", 123);

    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%%r]\n");
    printf("Unknown:[%%r]\n");
    return (0);
}
