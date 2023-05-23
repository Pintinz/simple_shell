#include "shell.h"

/**
 * execute_setenv - a function that executes the set environment
 * @args: a double pointer that pass the arguments
 */

void execute_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, "setenv: Invalid syntax\n", 23);
		return;
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		write(STDERR_FILENO, "setenv: Failed to set environment variable\n", 43);
	}
}


/**
 * execute_unsetenv - a function that executes the unset environment
 * @args: a double pointer that passes the arguments
 */

void execute_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		write(STDERR_FILENO, "unsetenv: Variable name not provided\n", 36);
		return;
	}

	if (unsetenv(args[1]) == -1)
	{
		write(STDERR_FILENO, "unsetenv: Failed to unset environment variable\n", 47);
	}
}

/**
 * my_atoi - a function that takes a string and converts it to an integer
 * @str: string to be converted to an integer
 * Return: it returns an integer
 */

int my_atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	/* Handle leading whitespace*/
	while (str[i] == ' ' || str[i] == '\t')
		i++;

	/* Handle sign*/
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}

	/* Process digits*/
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	/* Apply sign*/
	result *= sign;

	return (result);
}
