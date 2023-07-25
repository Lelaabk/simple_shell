#include "main.h"

/**
* removecomments - function that removes comments.
* @input: function input.
* Return: output
*/

char *removecomments(char *input)
{
	int i, final;

	final = 0;
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '#')
		{
			if (i == 0)
			{
				_free(input);
				return (NULL);
			}

			if (input[i - 1] == ' ' || input[i - 1] == '\t' || input[i - 1] == ';')
				final = i;
		}
	}

	if (final != 0)
	{
		input = _realloc(input, i, final + 1);
		input[final] = '\0';
	}

	return (input);
}
