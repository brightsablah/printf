#include "main.h"
/**
* rot13 - Encodes a string into ROT13
* @str: A pointer to the string to encode
*
* Description:
* This function encodes a string into ROT13, a simple letter substitution
* cipher that replaces a letter with the 13th letter after it in the alphabet.
* It processes only alphabetical characters while leaving non-alphabetical
* characters unchanged. The function modifies the input string in-place.
*
* @str: Pointer to the input string to be encoded.
*
* Return: Pointer to the modified (encoded) string.
*/
char *rot13(char *str)
{
	int i;
	char a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char b[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

/* swapping characters */
	for (i = 0; str[i] != '\0'; i++)
	{
		char c = str[i];
		int j;

		for (j = 0; a[j] != '\0'; j++)
		{
			if (c == a[j])
			{
				str[i] = b[j];
				break;
			}
		}
	}

	return (str);
}
