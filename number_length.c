#include "main.h"

int number_length(int num)
{
	int length = 0;

	if (num == 0)
	{
		return (1);
	}

	if (num < 0)
	{
		length++;
		num = -num;
	}

	while (num > 0)
	{
		length++;
		num /= 10;
	}

	return (length);
}
