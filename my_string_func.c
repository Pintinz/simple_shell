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
