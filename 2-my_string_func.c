#include "shell.h"

/**
 * my_strcat - A function that concatenate the characters
 * from the src to the end of dest
 * @dest: a pointer to a character array
 * @src: This is a pointer to a constant character string
 */

void my_strcat(char *dest, const char *src)
{
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

/**
 * my_strcpy - A function that copy the characters from
 * the src to the dest
 * @dest: a pointer to a character array
 * @src: A pointer to a constant character array
 */

void my_strcpy(char *dest, const char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}


/**
 * my_strchr - A function that locate the first
 * occurence of the target character in the str
 * @str: a pointer to a constant character array
 * @target: the chacter to search for
 * Return: it returns NULL
 */
char* my_strchr(const char *str, char target)
{
	while (*str != '\0')
	{
		if (*str == target)
		{
			return ((char*)str);
		}
		str++;
	}
	return (NULL);
}

/**
 * my_strncmp - a function that compares the first n characters of str1 & str2
 * @str1: first string
 * @str2: second string
 * @n: the number of arguments passed 
 * Return: it returns str1 & str2
 */

int my_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}

	if (n == 0)
		return 0;
	else
		return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
