#include "main.h"

/**
 * removeenter - helper function to trim enter.
 * @input: input string.
 * Return: trimmed string.
 */

char *removeenter(char *input)
{
	int i;
	char *output = NULL;
	int j;

	j = _strlen(input);
	output = malloc(j);
	for (i = 0; input[i] != '\n'; i++)
	{
		output[i] = input[i];
	}
	_free(input);
	return (output);
}
