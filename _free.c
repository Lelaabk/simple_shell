#include "main.h"

/**
 * _free - frees tha memory
 * @input: input char.
 */

void _free(char *input)
{
	free(input);
	input = NULL;
}
