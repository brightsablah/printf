#include "main.h"

/* Define functions to handle flags */
void set_flag_bit(flag_t *flags, unsigned char bit) {
    flags->flag |= bit;
}

void clear_flag_bit(flag_t *flags, unsigned char bit) {
    flags->flag &= ~bit;
}

flag_t flags(const char *format, unsigned int *index)
{
    flag_t result = {0, 0};
    unsigned int i = *index;

    for (; format[i] != '\0'; i++) {
        if (format[i] == '+') {
            result.sign = '+';
        } else if (format[i] == '-') {
            result.flag |= NEG_FLAG_BIT;
        } else if (format[i] == ' ') {
            result.flag |= SPACE_FLAG_BIT;
        } else if (format[i] == '0') {
            result.flag |= ZERO_FLAG_BIT;
        } else if (format[i] == '#') {
            result.flag |= SHARP_FLAG_BIT;
        } else {
            break;
        }
    }

    *index += 1;
    return (result);
}
