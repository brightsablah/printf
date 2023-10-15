#include "main.h"
#include <string.h>
typedef int (*format_handler)(va_list);

int handle_c(va_list arg_list) {
    return write(1, (char[]){va_arg(arg_list, int)}, 1);
}

int handle_s(va_list arg_list) {
    const char *str = va_arg(arg_list, const char *);
    if (str == NULL) str = "(null)";
    return write(1, str, (int)strlen(str));
}

int handle_percent(va_list arg_list) {
    (void)arg_list;
    return write(1, "%", 1);
}

static const struct {
    char specifier;
    format_handler handler;
} format_handlers[] = {
    {'c', handle_c},
    {'s', handle_s},
    {'%', handle_percent},
};

int _printf(const char *format, ...) {
    if (format == NULL) return -1;

    va_list arg_list;
    va_start(arg_list, format);

    int count = 0;
    char format_char;
    
    while ((format_char = *format++)) {
        if (format_char != '%') {
            count += write(1, &format_char, 1);
        } else {
            format_handler handler = NULL;
            for (size_t i = 0; i < sizeof(format_handlers) / sizeof(format_handlers[0]); i++) {
                if (format_handlers[i].specifier == *format) {
                    handler = format_handlers[i].handler;
                    break;
                }
            }
            count += handler ? handler(arg_list) : write(1, "%", 1);
            format++;
        }
    }

    va_end(arg_list);
    return count;
}

