#include "main.h"

/**
 * _strcmp - compare 2 strings.
 * @inp1: string 1.
 * @inp2: string 2.
 * Return: 0 on success
 */

int _strcmp(char *inp1, char *inp2)
{
	int i;

	if (inp1 == NULL || inp2 == NULL)
	{
		_free(inp1);
		_free(inp2);
		exit(0);
	}
	for (i = 0; inp1[i] && inp2[i];)
	{
		if (inp1[i] == inp2[i])
		{
			i++;
		}
		else
		{
			return (-1);
		}
	}
return (0);
}
