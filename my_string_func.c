#include "shell.h"

/**
 * str_cspn - A function that rejects characters
 * @str: string characters
 * @reject: the character it detects to start rejecting from
 * Return: it returns length
 */

int str_cspn(const char *str, const char *reject)
{
		int length, j;

		for (length = 0; str[length]; length++)
		{
			for (j = 0; reject[j]; j++)
			{
				if (str[length] == reject[j])
				{
					return (length);
				}
			}
		}
		return (length);
}

/**
 * my_strcmp - function compares two strings s1 and s2
 * and returns an integer value
 * @s1: first string
 * @s2: second string
 * Return: it returns the difference btw two string
 */

int my_strcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == '\0')
		{
			return (0);
		}
	}
	return (s1[i] - s2[i]);
}

/**
 * my_strlen - a function used to determine the length of a string str
 * @str: a pointer to a string
 * Return: it returns len
 */

size_t my_strlen(const char *str)
{
	size_t len = 0;

	while (*str++)
	{
		len++;
	}

	return (len);
}

/**
 * my_memcpy - a function that copy's a block of memory from
 * a source
 * @dest: a pointer to the destination buffer
 * @src: a pointer to the source buffer containing the
 * data to be copied
 * @n: the number of bytes to be copied
 * Return: it returns dest
 */

void *my_memcpy(void *dest, const void *src, size_t n)
{
	char *d = dest;
	const char *s = src;

	while (n--)
	{
		*d++ = *s++;
	}

	return (dest);
}

/**
 * my_strdup - a function that creates a new copy of a string s
 * @s: a pointer
 * Return: it retuns s
 */

char *my_strdup(const char *s)
{
	size_t len = my_strlen(s);
	char *d = malloc(len + 1);

	if (d == NULL)
	{
		return (NULL);
	}

	my_memcpy(d, s, len);
	d[len] = '\0';
	return (d);
}
