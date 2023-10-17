#include "main.h"

typedef struct {
    char put_flags;
    int put_width;
    int put_precision;
    char put _length;
} handle_op;


void handle_print_formating(const char *format, int *i, handle_op *selection) {

    selection->put_flags = 0;
    selection->put_width = 0;
    selection->put_precision = -1;
    selection->put_length = 0;

    /* handle flags */
    while (format[*i] == '+' || format[*i] == ' ' || format[*i] == '0' || format[*i] == '-' || format[*i] == '#')
    {
        selection->put_flags |= format[(*i)++];
    }

    /* handle width */
    if (format[*i] >= '1' && format[*i] <= '9')
    {
        selection->put_width = 0;
        while (format[*i] >= '0' && format[*i] <= '9')
	{
            selection->put_width = selection->put_width * 10 + (format[(*i)++] - '0');
        }
    }

    /* handle  precision */
    if (format[*i] == '.')
    {
        (*i)++;
        selection->put_precision = 0;
        while (format[*i] >= '0' && format[*i] <= '9')
	{
            selection->put_precision = selection->put_precision * 10 + (format[(*i)++] - '0');
        }
    }

    /* handle length modifier */
    if (format[*i] == 'h' || format[*i] == 'l')
    {
        selection->get_length = format[(*i)++];
        if (format[*i] == 'h' || format[*i] == 'l')
	{
            selection->get_length = format[(*i)++];
        }
    }
}

