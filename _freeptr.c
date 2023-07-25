#include "main.h"

/**
 * _freeptr - free pointer **.
 * @ptr: input pointer.
 * Return: NULL if not found.
 */

void _freeptr(char **ptr)
{
	int i = 0;

	if (!ptr)
		return;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}
