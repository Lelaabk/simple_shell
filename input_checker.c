#include "main.h"

/**
 * input_checker - to check inputs.
 *@ptr: input pointer.
 *@str1: input buff.
 *@arg: input arg.
 *Return: pointer to new array.
 */

char **input_checker(char **ptr, char *str1, char *arg)
{
	char *cmdcpy = NULL;
	/*char **dir = NULL;*/
	/*char buff[256];*/
	/*size_t buffsize = 0;*/

	if (!ptr)
	{
		return (NULL);
	}
	cmdcpy = (char *)malloc((_strlen(ptr[0]) + 1) * sizeof(char));

	_strcpy(ptr[0], cmdcpy);

	if (_strcmp(ptr[0], "exit") == 0)
	{
		if (ptr[1] != NULL)
			exit(atoi(ptr[1]));
		_free(ptr[0]);
		free(ptr);
		_free(cmdcpy);
		_free(str1);

		return (NULL);
	}
	if ((access(ptr[0], F_OK) != 0))
	{
		errhandler(cmdcpy, arg);
		_free(ptr[0]);
		_free(cmdcpy);
		_free(str1);
		free(ptr);
		return (NULL);
		/*exit(0);*/
	}
	else
	{
		_free(cmdcpy);
		_free(str1);
		return (ptr);
	}
}
