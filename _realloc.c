#include "main.h"

/**
	* _realloc - reallocate memory size.
	* @prev: pointer to old size.
	* @old: old size.
	* @new: new size
	* Return: new ptr.
*/

void *_realloc(void *prev, int old, int new)
{
	char *ptr;

	if (!prev)
		return (malloc(new));
	if (!new)
		return (free(prev), NULL);
	if (new == old)
		return (prev);

	ptr = malloc(new);
	if (!ptr)
		return (NULL);

	old = old < new ? old : new;
	while (old--)
		ptr[old] = ((char *)prev)[old];
	free(prev);
	return (ptr);
}
