#include "main.h"

/**
	* _trimmer - function to trim enter.
	* @input: input string.
	* Return: trimmed
*/

char *_trimmer(char *input)
{
	int i, j;
	char *output;

	for (i = 0; input[i]; i++)
	{
		if (input[i] == '\n')
		{
			input[i] = '\0';
			break;
		}
	}

	output = malloc(i + 1);

	for (j = 0; j <= i; j++)
	{
		output[j] = input[j];
	}
	_free(input);
	return (output);
}
