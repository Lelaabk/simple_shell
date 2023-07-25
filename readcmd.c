#include "main.h"

/**
 * readcmd - determine number of words in string.
 * @input: input string.
 * @delim: input delim.
 * Return: number of words.
 */

int readcmd(char *input, char *delim)
{
	int i;
	int count = 0;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (_istoken(input[i], delim) == -1)
			if ((!input[i + 1] || _istoken(input[i + 1], delim) == 0))
				count++;
	}
	return (count);
}
