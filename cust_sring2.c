#include "shell.h"

/**
 * _strlen - Calculates the length of a string
 * @s: Input string
 *
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
	return 0;

	for (; *s; s++)
	i++;

	return i;
}

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: 0 if the strings are equal, negative value if s1 is less than s2,
 *				 positive value if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	for (; *s1 && *s2; s1++, s2++)
	{
	if (*s1 != *s2)
		return *s1 - *s2;
	}

	if (*s1 == *s2)
	return 0;
	else
	return *s1 < *s2 ? -1 : 1;
}

/**
 * starts_with - Checks if a string starts with another string
 * @haystack: String to search in
 * @needle: String to search for
 *
 * Return: Pointer to the start of the matching substring, or NULL if not found
 */
char *starts_with(const char *haystack, const char *needle)
{
	for (; *needle; needle++, haystack++)
	{
	if (*needle != *haystack)
		return NULL;
	}

	return (char *)haystack;
}

/**
 * _strcat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	for (; *dest; dest++)
	;

	for (; *src; src++, dest++)
	{
	*dest = *src;
	}

	*dest = *src;
	return ret;
}

