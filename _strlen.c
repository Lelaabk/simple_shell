#include "main.h"

/**
 * _strlen - get length of a string.
 * @input: input string.
 * Return: length of string.
 */

int _strlen(char *input)
{
	int i;

	for (i = 0; input[i];)
	{
		i++;
	}
	return (i);
}
