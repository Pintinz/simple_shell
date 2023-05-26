#include "shell.h"

/**
 * _strcpy - Copies a string from source to destination
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to destination string
 */
char *_strcpy(char *dest, const char *src)
{
	if (dest == src || src == NULL)
	return dest;

	int i;
	for (i = 0; src[i] != '\0'; i++)
	{
	dest[i] = src[i];
	}

	dest[i] = '\0';
	return dest;
}

/**
 * _strdup - Duplicates a string
 * @str: String to duplicate
 *
 * Return: Pointer to the duplicated string, or NULL if allocation fails
 */
char *_strdup(const char *str)
{
	if (str == NULL)
	return NULL;

	int length = 0;
	for (; str[length] != '\0'; length++)
	;

	char *ret = malloc(sizeof(char) * (length + 1));
	if (ret == NULL)
	return NULL;

	int i;
	for (i = 0; i <= length; i++)
	{
	ret[i] = str[i];
	}

	return ret;
}

/**
 * _puts - Prints a string to the standard output
 * @str: String to print
 */
void _puts(const char *str)
{
	if (str == NULL)
	return;

	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
	_putchar(str[i]);
	}
}

/**
 * _putchar - Writes a character to the standard output
 * @c: Character to write
 *
 * Return: On success, 1. On failure, -1.
 */
int _putchar(char c)
{
	static int i = 0;
	static char buf[WRITE_BUF_SIZE];

	switch (c)
	{
	case BUF_FLUSH:
		if (i >= WRITE_BUF_SIZE)
		{
		write(1, buf, i);
		i = 0;
		}
		break;
	default:
		if (c != BUF_FLUSH)
		buf[i++] = c;
		break;
	}

	return 1;
}

