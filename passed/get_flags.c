#include "main.h"

/**
 * struct FormatFlag - formatting flag for non-custom conversion specifiers .
 * @flagChar: Character representing the flag.
 * @flagValue: Numeric value associated with the flag.
 */
struct FormatFlag {
	char flagChar;
	int flagValue;
};
struct FormatFlag flags[] = {
	{ '-', 1 },
	{ '+', 2 },
	{ '0', 4 },
	{ '#', 8 },
	{ ' ', 16 },
	{ '\0', 0 }
};

/**
 * flags - Checks formatting flags from the format string.
 * @format: The format string to check.
 * @position: A pointer to the current position within the format string.
 *
 * Return: integer of the detected flags.
 */
int get_flags(const char *format, int *position)
{
	int flagsValue = 0;
	char currentChar;
	int j;

	while (format[*position] != '\0')
	{
		currentChar = format[*position];

		for (j = 0; flags[j].flagChar != '\0'; j++)
		{
			if (currentChar == flags[j].flagChar)
			{
				flagsValue |= flags[j].flagValue;
				break;
			}
		}

		if (currentChar != flags[j].flagChar)
		{
			break;
		}
		(*position)++;
	}
	return (flagsValue);
}
