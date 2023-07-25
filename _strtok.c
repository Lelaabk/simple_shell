#include "main.h"

/**
 * _strtok - split string
 * @input: input string
 * Return: splitted string
 */

char **_strtok(char *input)
{
	int j = _strlen(input);
	char **output = malloc(j);
	char *buff = strtok(input, "\n\t ");
	char *delim = "\n\t ";
	int i = 0;

	/*buff = strtok(input, delim);*/
	while (buff != NULL)
	{
		output[i] = buff;
		i++;
		buff = strtok(NULL, delim);
	}
	_free(buff);
	if (output[0] == NULL)
	{
	free(output);
	_free(input);
	exit(0);
	}
	return (output);
}
