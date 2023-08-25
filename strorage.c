#include "shell.h"

/**
 * bfree - Frees a Pointer and NULLs the address
 * @pta: address of the Pointer to free.
 * Return: If freed 1, otherwise 0.
 */

int bfree(void **pta)
{
	if (pta && *pta)
	{
		free(*pta);
		*pta = NULL;
		return (1);
	}
	return (0);
}
