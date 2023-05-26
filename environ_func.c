#include "shell.h"

/**
 * _env - a function that prints the current environment
 * @info: String containing arguments
 * Return: Always 0
 */
int _env(info_t *info)
{
	display_list_str(info->env);
	return (0);
}

/**
 * _getenv - a function that gets the value of the environment variable
 * @info: String containing arguments.
 * @str: name of the environment
 * Return: the variable value
 */
char *_getenv(info_t *info, const char *ptr)
{
	list_t *node = info->env;
	char *n;

	while (node)
	{
	n = node_beginning(node->str, ptr);
	if (n && *n)
	return (n);
	node = node->next;
	}
	return (NULL);
}

/**
 * _setenv2 - A function that sets a new environment variable
 * @info: String containing arguments.
 * Return: Always 0
 */
int _setenv2(info_t *info)
{
	if (info->argc != 3)
	{
	_eputs("Incorrect number of arguments\n");
	return (1);
	}
	if (_setenv1(info, info->argv[1], info->argv[2]))
	return (0);
	return (1);
}

/**
 * unsetenv2 - a function that  Remove an environment variable
 * @info: String containing arguments.
 *	Return: Always 0
 */
int unsetenv2(info_t *info)
{
	int n;

	if (info->argc == 1)
	{
	_eputs("Too few arguments.\n");
	return (1);
	}
	for (n = 1; n <= info->argc; n++)
	_unsetenv1(info, info->argv[n]);

	return (0);
}

/**
 * generate_env_list - a function that populates environment linked list
 * @info: String containing arguments.
 * Return: Always 0
 */
int generate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
	end_add_node(&node, environ[i], 0);
	info->env = node;
	return (0);
}
