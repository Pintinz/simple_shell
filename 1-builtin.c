#include "shell.h"

/**
 * _history - a function that Displays history list, one command per line
 * @info: a string containing arguments
 * Return: Always 0.
 */
int _history(info_t *info)
{
	display_list(info->history);
	return (0);
}

/**
 * uput_aAlias -a function that Unsets an alias.
 * @info: Parameter.
 * @alias: The string to unset.
 * Return: if successful, it returns 0, else 1
 */
int unput_alias(info_t *info, char *alias)
{
	char *equal;
	int result;

	equal = _strchr(alias, '=');
	if (!equal)
		return (1);

	*equal = '\0';
	result = remove_index_node(&(info->alias),
		fetch_node_index(info->alias, node_beginning(info->alias, alias, -1)));
	*equal = '=';

	return (result);
}

/**
 * put_alias - a function that Sets an alias.
 * @info: Parameter string.
 * @alias: The string to set.
 * Return: successfull returns 0, 1 on error.
 */
int put_alias(info_t *info, char *alias)
{
	char *equal;

	equal = _strchr(alias, '=');
	if (!equal)
		return (1);

	if (!*(equal + 1))
		return (unput_alias(info, alias));

	unput_alias(info, alias);
	return (end_add_node(&(info->alias), alias, 0) == NULL);
}

/**
 * display_alias - a function that Prints an alias.
 * @alias: a string alias to display.
 * Return: if successfull returns 0, 1 on error.
 */
int display_alias(list_t *alias)
{
	char *equal, *value;

	if (alias)
	{
		equal = _strchr(alias->str, '=');
		for (value = alias->str; value <= equal; value++)
			_putchar(*value);
		_putchar('\'');
		_puts(equal + 1);
		_puts("'\n");
		return (0);
	}

	return (1);
}

/**
 * _alias - a function that does same thing with the alias built-in command.
 * @info: String containing arguments.
 * Return: Always 0.
 */

int _alias(info_t *info)
{
	int m = 1;
	char *equal;
	list_t *alias;

	if (info->argc == 1)
	{
		alias = info->alias;
		while (alias)
		{
			display_alias(alias);
			alias = alias->next;
		}
		return (0);
	}

	while (info->argv[m])
	{
		equal = _strchr(info->argv[m], '=');
		if (equal)
			put_alias(info, info->argv[m]);
		else
			display_alias(node_beginning(info->alias, info->argv[m], '='));

		m++;
	}

	return (0);
}
