#include "shell.h"

/**
 * is_cmd_func - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd_func(info_t *info, char *path)
{
	struct stat st;
	(void)info;
	if (!path || stat(path, &st))
		return 0;
	switch (st.st_mode & S_IFMT)
	{
		case S_IFREG:
			return 1;
		default:
			return 0;
	}
}

/**
 * duplicate_chars - duplicates characters
 * @path_str: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *duplicate_chars(char *path_str, int start, int stop)
{
	static char buf[1024];
	int k = 0;
	for (int i = start; i < stop; i++)
	{
		switch (path_str[i])
		{
			case ':':
				break;
			default:
				buf[k++] = path_str[i];
				break;
		}
	}
	buf[k] = '\0';
	return buf;
}

/**
 * find_path_cmd - finds this cmd in the PATH string
 * @info: the info struct
 * @path_str: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path_cmd(info_t *info, char *path_str, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;
	if (!path_str)
		return NULL;
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd_func(info, cmd))
			return cmd;
	}
	for (;;)
	{
		switch (path_str[i])
		{
			case '\0':
			case ':':
				path = duplicate_chars(path_str, curr_pos, i);
				if (!*path)
					_strcat(path, cmd);
				else
				{
					_strcat(path, "/");
					_strcat(path, cmd);
				}
				if (is_cmd_func(info, path))
					return path;
				if (!path_str[i])
					break;
				curr_pos = i;
				break;
		}
		i++;
	}
	return NULL;
}

