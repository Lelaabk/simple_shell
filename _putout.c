#include "main.h"

/**
 * _putout - write to stdout.
 * @str: input string.
 */

void _putout(char *str)
{
	int i = 0;

	if (!str)
	{
		exit(0);
	}

	while (str[i])
	{
		i++;
	}
	write(1, str, i);
	str = NULL;
}
