#include "proj.h"

/**
 * builtin_execute - Executes the built-in functions.
 * @tokens: The arguments being passed.
 * Return: The status of the execution.
 */
int builtin_execute(char **tokens)
{
	int status;
	unsigned int length;
	unsigned int num;
	unsigned int i;

	built_s builtin[] = {
	{"exit", shell_exit},
	{"env", shell_env},
	{NULL, NULL}
	};

	if (tokens[0] == NULL)
	return (1);

	length = _strlen(tokens[0]);

	num = shell_num_builtins(builtin);
	for (i = 0; i < num; i++)
	{
	if (_strcmp(tokens[0], builtin[i].name, length) == 0)
	{
		status = (builtin[i].p)();
		return (status);
	}
	}
	return (1);
}

/**
 * shell_num_builtins - Counts the number of built-in commands.
 * @builtin: The array of built-in commands.
 * Return: The number of built-in commands.
 */
int shell_num_builtins(built_s builtin[])
{
	unsigned int i;

	i = 0;
	while (builtin[i].name != NULL)
	i++;

	return (i);
}

