#include "main.h"

/**
*interactive_checker - check for input.
*@ptr: input ptr.
*@str2: input arg.
*Return: pointer.
*/

char **interactive_checker(char **ptr, char *str2)
{
	char *cmdcpy;

	if (!ptr)
		{
		return (NULL);
		}

	cmdcpy = (char *)malloc((_strlen(ptr[0]) + 1) * sizeof(char));

	_strcpy(ptr[0], cmdcpy);

	if (_strcmp(ptr[0], "exit") != -1)
	{
		exit(0);
	}

	if (ptr[0][0] != '/')
		ptr[0] = _strcat("/bin/", ptr[0]);

	if ((access(ptr[0], F_OK) != 0))
	{
	errhandler(cmdcpy, str2);
	return (NULL);
	}
	else
	{
		return (ptr);
	}
}
