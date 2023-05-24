#include "honor.h"

/**
 * shell_exit - exits the shell
 * Return: -1
 */
int shell_exit(void)
{
	return (-1);
}

/**
 * shell_env - prints environment
 * Return: (0);
 */
int shell_env(void)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (0);
}
