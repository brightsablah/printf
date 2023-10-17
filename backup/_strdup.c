#include "main.h"
#include "main.h"
/**
* _strdup - Duplicates a string
* @str: The string to duplicate
*
* Description:
* This function duplicates a string into a new block of memory
* Return: a pointer to the duplicated string. NULL if memory allocation fails.
*/
char *_strdup(char *str)
{
	char *dupstr;
	int len = 0, i;

/*special case for NULL string */
	if (str == NULL)
		return (NULL);

/* checking length of string */
	while (str[len] != '\0')
	{
		len++;
	}

/* allocating memory for duplicate string */
	dupstr = (char *)(malloc((len + 1) * sizeof(char)));
/* checking if memory allocation was successful */
	if (dupstr == NULL)
		return (NULL);

/* creating duplicate string */
	for (i = 0; i < len; i++)
	{
		dupstr[i] = str[i];
	}

	dupstr[len] = '\0'; /* Null-terminating the duplicate string */

	return (dupstr);
}
