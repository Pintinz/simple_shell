#include "honor.h"
/**
**exit_shell - exits the shell when calledm
**Return: void
**/

	int exit_shell(void)
	{
		return (-1);
	}


/**
**shell_env - to print the working environment
**Return: void
**/

	int shell_env(void)
	{
		unsigned int num;

		num = 0;
		while (environ[num] != NULL)
		{
			write(STDOUT_FILENO, environ[num], _strlen(environ[num]));
			write(STDOUT_FILENO, "\n", 1);
			num++;
		}
		return (0);
	}
