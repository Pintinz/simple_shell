#include shell.h

/**
 * bfree - frees a pointer and sets it to NULL
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, 0 otherwise
 */
int bfree(void **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return 0;
	free(*ptr);
	*ptr = NULL;
	return 1;
}

