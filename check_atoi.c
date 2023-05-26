#include "shell.h"

/**
 * check_interactive_mode - a function that Returns
 * true if the shell is in interactive mode
 * @info: Struct address of a string
 * Return: it returns 1 if interactive mode, 0 otherwise
 */

int check_interactive_mode(info_t *info)
{
	return ((isatty(STDIN_FILENO) && info->read_fd <= 2));
}

/**
 * check_delim - a function that Checks if a character is a delimiter
 * @m: The character to check if it is a delim
 * @delim: The string checked and its a delimeter
 *
 * Return: it returns 1 if true, 0 if false
 */

int check_delim(char m, char *delim)
{
	while (*delim != '\0')
	{
	if (*delim == m)
	return (1);
	delim++;
	}
	return (0);
}

/**
 * check_alpha - a function that  Checks for an alphabetic character
 * @m: The character to check if it is an alph
 * Return: it returns 1 if m is alphabetic, 0 otherwise
 */

int check_alpha(int m)
{
	return ((m >= 'a' && m <= 'z') || (m >= 'A' && m <= 'Z'));
}

/**
 * _atoi - a function that Converts a string to an integer
 * @str: string to be converted
 * Return: it returns 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *str)
{
	int a = 0;
	int myth = 1;
	int outcome = 0;
	unsigned int num = 0;
	int clap = 0;

	while (str[a] != '\0' && clap != 2)
	{
	switch (str[a])
	{
	case '-':
	myth = -1;
	break;
	default:
	if (str[a] >= '0' && str[a] <= '9')
	{
	clap = 1;
	num = (num * 10) + (str[a] - '0');
	}
	else if (clap == 1)
	{
	clap = 2;
	}
	}
	ai++;
	}

	outcome = myth * num;

	return (outcome);
}

