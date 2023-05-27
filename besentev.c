#include "shell.h"

/**
 * builtin_setenv - Set a new environment variable or modify an existing one
 * @tokens: Array of tokens containing the command and arguments
 * Return: Always returns 1 to continue execution
 */
int builtin_setenv(char **tokens)
{
	char *variable, *value;

	if (tokens[1] == NULL || tokens[2] == NULL)
	{
		perror("Error: Invalid arguments\n");
		return (1);
	}

	variable = tokens[1];
	value = tokens[2];

	if (setenv(variable, value, 1) == -1)
	{
		perror("Error: Failed to set environment variable\n");
		return (1);
	}

	return (1);
}

/**
 * builtin_unsetenv - Remove an environment variable
 * @tokens: Array of tokens containing the command and arguments
 * Return: Always returns 1 to continue execution
 */
int builtin_unsetenv(char **tokens)
{
	char *variable;

	if (tokens[1] == NULL)
	{
		perror("Error: Invalid arguments\n");
		return (1);
	}

	variable = tokens[1];

	if (unsetenv(variable) == -1)
	{
		perror("Error: Failed to unset environment variable\n");
		return (1);
	}

	return (1);
}

/**
 * builtin_execute - Execute the builtin commands
 * @tokens: Array of tokens containing the command and arguments
 * Return: Returns 0 if the command is a builtin, otherwise returns -1
 */
int builtin_execute(char **tokens)
{
	built_s builtin[] = {
		{"setenv", builtin_setenv},
		{"unsetenv", builtin_unsetenv},
		
	};
	int num_builtins = shell_num_builtins(builtin);
	int i;

	if (tokens[0] == NULL)
		return (0);

	for (i = 0; i < num_builtins; i++)
	{
		if (_strcmp(tokens[0], builtin[i].name, _strlen(tokens[0])) == 0)
			return (builtin[i].p(tokens));
	}

	return (-1);
}

/**
 * shell_num_builtins - Get the number of builtin commands
 * @builtin: Array of builtin commands
 * Return: Number of builtin commands
 */
int shell_num_builtins(built_s builtin[])
{
	int i = 0;

	while (builtin[i].name != NULL)
		i++;

	return (i);
}

int main(void)
{
	/* Rest of the code */
	return (0);
}

