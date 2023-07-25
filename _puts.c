#include "main.h"

/**
 * _puts - write to stdout.
 * @str: input string.
 */

void _puts(char *str)
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
	write(2, str, i);
	str = NULL;
}
