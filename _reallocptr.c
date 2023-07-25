#include "main.h"

/**
* _reallocptr - function to reallocate pointer
* @ptr_o: input old ptr.
* @old_size: old pointer size.
* @new_size: new pointer size.
* Return: new Ptr
*/

char **_reallocptr(char **ptr_o, int old_size, int new_size)
{
	char **ptr_n;
	int i;

	if (ptr_o == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr_o);

	ptr_n = malloc(sizeof(char *) * new_size);
	if (ptr_n == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		ptr_n[i] = ptr_o[i];

	free(ptr_o);

	return (ptr_n);
}
