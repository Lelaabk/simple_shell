#include "main.h"

/**
 *_strcat - concats 2 strings
 *@a: input string a.
 *@b: input string b.
 *Return: mixed string.
 */

char *_strcat(char *a, char *b)
{
	char *output = NULL;
	int alen, blen, i, j, k;

	if (!a)
		a = "";
	if (!b)
		b = "";

	alen = _strlen(a);
	blen = _strlen(b);

	output = malloc((alen + blen + 1) * sizeof(char));

	if (!a)
		return (NULL);

	for (i = 0; i < alen; i++)
		output[i] = a[i];

	for (j = alen, k = 0; k <= blen; k++)
		output[j++] = b[k];
	_free(b);
	return (output);
}

/**
 *getpath - adding /bin
 *@input: input string.
 *Return: /bin/string
 */

char *getpath(char *input)
{
	char *bin = "/bin/";
	char *output = NULL;

	output = _strcat(bin, input);
	return (output);
}
