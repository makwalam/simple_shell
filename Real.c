#include "shell.h"

/**
 * _Memset - Fills memory with a constant byte
 * @s: The Ptr to the memory area.
 * @b: The byte to fill *s with
 * @n: The amount of bytes to be filled
 * Return: (s) a pntr to the mmry area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees a strng of strngs
 * @pp: strng of strngs
 */

void ffree(char **bb)
{
	char **a = bb;

	if (!bb)
		return;
	while (*bb)
		free(*bb++);
	free(a);
}

/**
 * _Realloc - reallocates a block of memory
 * @ptr: pntr to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 * Return:Pnter to da ol'block nameen.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

