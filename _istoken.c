#include "main.h"

/**
 * _istoken - verify character.
 * @input: character.
 * @delim: string of tokens.
 * Return: 0 or -1.
 */

int _istoken(char input, char *delim)
{
	while (*delim)
	{
		if (input == *delim++)
			return (0);
	}
	return (-1);
}
