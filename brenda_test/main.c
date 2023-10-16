#include <limits.h>
#include <stdio.h>
#include "main.h"

int main(void) {
    int len;
    int len2;
    unsigned int ui;
    char character;
    char *string;
    int integer;
    int large_num;
    double large_double;
    double precision_double;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;

    character = 'C';
    string = "StringTest";
    integer = 42;

    large_num = 1234567890;
    large_double = 1234567.8901234567;
    precision_double = 3.14159265359;

    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);

    _printf("Character: [%c]\n", character);
    printf("Character: [%c]\n", character);
    _printf("String: [%s]\n", string);
    printf("String: [%s]\n", string);
    _printf("Percent sign: [%%]\n");
    printf("Percent sign: [%%]\n");
    _printf("Integer (d): [%d]\n", integer);
    printf("Integer (d): [%d]\n", integer);
    _printf("Integer (i): [%i]\n", integer);
    printf("Integer (i): [%i]\n", integer);

    _printf("Large integer: [%d]\n", large_num);
    printf("Large integer: [%d]\n", large_num);
    _printf("Large double: [%f]\n", large_double);
    printf("Large double: [%f]\n", large_double);

    _printf("Zero-padded integer: [%05d]\n", 42);
    printf("Zero-padded integer: [%05d]\n", 42);
    _printf("Right-aligned string: [%10s]\n", "Align");
    printf("Right-aligned string: [%10s]\n", "Align");
    _printf("Left-aligned string: [%-10s]\n", "Align");
    printf("Left-aligned string: [%-10s]\n", "Align");

    _printf("Limited precision double: [%.2f]\n", precision_double);
    printf("Limited precision double: [%.2f]\n", precision_double);

    return 0;
}
