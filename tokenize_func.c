#include "shell.h"

/**
 * **strtow1 - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow1(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || *str == '\0')
	return NULL;

	if (!d)
	d = " ";

	for (i = 0; str[i] != '\0'; i++)
	switch (!check_delim(str[i], d) && (check_delim(str[i + 1], d) || !str[i + 1]))
	{
		case 1:
		numwords++;
		break;
	}

	if (numwords == 0)
	return NULL;

	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
	return NULL;

	for (i = 0, j = 0; j < numwords; j++)
	{
	for (; check_delim(str[i], d); i++)
		;

	k = 0;

	for (; !check_delim(str[i + k], d) && str[i + k] != '\0'; k++)
		;

	s[j] = malloc((k + 1) * sizeof(char));
	if (!s[j])
	{
		for (k = 0; k < j; k++)
		free(s[k]);
		free(s);
		return NULL;
	}

	for (m = 0; m < k; m++)
		s[j][m] = str[i++];

	s[j][m] = '\0';
	}

	s[j] = NULL;
	return s;
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || *str == '\0')
	return NULL;

	for (i = 0; str[i] != '\0'; i++)
	switch ((str[i] != d && str[i + 1] == d) || (str[i] != d && !str[i + 1]) || str[i + 1] == d)
	{
		case 1:
		numwords++;
		break;
	}

	if (numwords == 0)
	return NULL;

	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
	return NULL;

	for (i = 0, j = 0; j < numwords; j++)
	{
	for (; str[i] == d && str[i] != '\0'; i++)
		;

	k = 0;

	for (; str[i + k] != d && str[i + k] != '\0'; k++)
		;

	s[j] = malloc((k + 1) * sizeof(char));
	if (!s[j])
	{
		for (k = 0; k < j; k++)
		free(s[k]);
		free(s);
		return NULL;
	}

	for (m = 0; m < k; m++)
		s[j][m
