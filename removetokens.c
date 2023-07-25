#include "main.h"

/**
 * removetokens - remove delims . export words.
 * @input: input string.
 * @delim: string of delims.
 * Return: pointerof strings.
 */

char **removetokens(char *input, char *delim)
{
	int i, j, k, l;
	int wordsnum = readcmd(input, delim);
	char **output = malloc((wordsnum + 1) * sizeof(char *));

	if (wordsnum == 0)
	{
		free(output);
		return (NULL);
	}

	if (input == NULL)
		return (NULL);

	for (i = 0, j = 0; i < wordsnum; i++)
	{
		while (_istoken(input[j], delim) == 0)
			j++;

		l = 0;
		while (_istoken(input[j + l], delim) == -1 && input[j + l])
			l++;

		output[i] = malloc(l + 1);
		if (!output[i])
		{
			_freeptr(output);
			return (NULL);
		}

		for (k = 0; k < l; k++)
			output[i][k] = input[j++];

		output[i][k] = 0;
	}
	output[i] = NULL;
return (output);
}
