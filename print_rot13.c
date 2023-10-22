#include "main.h"
/**
* print_rot13 - Prints a string encoded in ROT13
* @arg: A va_list containing the string to print
* @buffer: pointer a buffer that stores print output
*
* Description:
* This function prints a string encoded in ROT13 to the standard output.
*/
void print_rot13(va_list arg, Buffer *buffer, format_options *options)
{
	char *str = va_arg(arg, char *);
	char *rot13_str;
	int i;

	(void)(options);

/* special case for NULL string */
	if (str == NULL)
		return;

/* creating a copy of string so i don't edit the original string */
	rot13_str = _strdup(str);
	if (rot13_str == NULL) /* checking if string copying was succesful */
	return;

/* converting copied string to a ROT13 string */
	rot13(rot13_str);

/* printing ROT13 string */
	for (i = 0; rot13_str[i] != '\0'; i++)
	{
		buffer_append_char(buffer, rot13_str[i]);
	}

	free(rot13_str);
}
