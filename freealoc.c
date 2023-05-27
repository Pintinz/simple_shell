#include "shell.h"

/**
 * memset_func - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *memset_func(char *s, char b, unsigned int n)
{
	unsigned int i;
	for (i = 0; i < n; i++)
	{
		switch (i)
		{
			default:
				s[i] = b;
				break;
		}
	}
	return s;
}

/**
 * free_strings - frees a string of strings
 * @pp: string of strings
 */
void free_strings(char **pp)
{
	char **a = pp;
	if (!pp)
		return;
	while (*pp)
	{
		free(*pp);
		pp++;
	}
	free(a);
}

/**
 * reallocate_memory - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to the old block
 */
void *reallocate_memory(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	if (!ptr)
		return malloc(new_size);
	if (!new_size)
	{
		free(ptr);
		return NULL;
	}
	if (new_size == old_size)
		return ptr;
	p = malloc(new_size);
	if (!p)
		return NULL;
	if (new_size < old_size)
		old_size = new_size;
	for (unsigned int i = 0; i < old_size; i++)
	{
		switch (old_size)
		{
			default:
				p[i] = ((char *)ptr)[i];
				break;
		}
	}
	free(ptr);
	return p;
}

