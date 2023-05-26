#include "shell.h"

/**
 * loop_hsh - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int loop_hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	for (; r != -1 && builtin_ret != -2;)
	{
	clear_cmd(info);

	switch (check_interactive_mode(info))
	{
		case 1:
		_putsfd("$ ", STDOUT_FILENO);
		break;
	}

	_putfd(BUF_FLUSH, STDERR_FILENO);
	r = ssize_t_get_input_func(info);

	if (r != -1)
	{
		set_cmd(info, av);
		builtin_ret = find_builtin_cmd(info);

		switch (builtin_ret)
		{
		case -1:
			find_cmd_func(info);
			break;
		}
	}
	else if (check_interactive_mode(info))
	{
		_putchar('\n');
	}

	free_cmd(info, 0);
	}

	write_hist(info);
	free_cmd(info, 1);

	if (!check_interactive_mode(info) && info->status)
	{
	exit(info->status);
	}

	if (builtin_ret == -2)
	{
	switch (info->error_num)
	{
		case -1:
		exit(info->status);
		default:
		exit(info->error_num);
	}
	}

	return (builtin_ret);
}

/**
 * find_builtin_cmd - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *					0 if builtin executed successfully,
 *					1 if builtin found but not successful,
 *				 -2 if builtin signals exit()
 */
int find_builtin_cmd(info_t *info)
{
	int i, built_in_ret = -1;

	struct built_table {
	char *nature;
	int (*func)(info_t *);
	} builtintbl[] = {
	{"exit", my_exit},
	{"env", _env},
	{"help", _help},
	{"history", _history},
	{"setenv", _setenv2},
	{"unsetenv", _unsetenv2},
	{"cd", _cd},
	{"alias", _alias},
	{NULL, NULL}
	};

	for (i = 0; builtintbl[i].nature; i++)
	{
	switch (_strcmp(info->args[0], builtintbl[i].nature))
	{
		case 0:
		info->lline_num_count++;
		built_in_ret = builtintbl[i].func(info);
		break;
	}
	}

	return (built_in_ret);
}

/**
 * find_cmd_func - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void find_cmd_func(info_t *info)
{
	char *path_cmd = NULL;
	int i, k;

	info->path_cmd = info->args[0];

	if (info->history_countt == 1)
	{
	info->lline_num_count++;
	info->history_countt = 0;
	}

	for (i = 0, k = 0; info->cmd_buffer[i]; i++)
	{
	switch (!check_delim(info->cmd_buffer[i], " \t\n"))
	{
		case 1:
		k++;
		break;
	}
