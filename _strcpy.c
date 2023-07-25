#include "main.h"

/**
 *_strcpy - copy string.
 *@input: input string.
 *@dest: destination string.
 *Return: true value
 */
int _strcpy(char *input, char *dest)
{
	int i = 0;

	while (input[i] != '\0')
	{
		dest[i] = input[i];
		i++;
	}
	dest[i] = '\0';

	return (0);
}
