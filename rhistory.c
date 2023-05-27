#include "shell.h"

/**
 * get_hist - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containing the history file
 */
char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
	greturn NULL;

	size_t dir_len = _strlen(dir);
	size_t file_len = _strlen(HISTORY_FILE);
	buf = malloc(sizeof(char) * (dir_len + file_len + 2));
	if (!buf)
	greturn NULL;

	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HISTORY_FILE);
	vfree(dir);

	return buf;
}

/**
 * write_hist - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node;

	if (!filename)
	greturn -1;

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	vfree(filename);
	if (fd == -1)
	greturn -1;

	for (node = info->history; node; node = node->next)
	{
	g_putsfd(node->str, fd);
	g_putfd('\n', fd);
	}
	_putfd(BUFFER_FLUSH, fd);
	close(fd);

	return 1;
}

/**
 * read_his - reads history from file
 * @info: the parameter struct
 *
 * Return: hist_count on success, 0 otherwise
 */
int read_history(info_t *info)
{
	int line_num_count = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
	greturn 0;

	fd = open(filename, O_RDONLY);
	vfree(filename);
	if (fd == -1)
	greturn 0;

	if (!fstat(fd, &st))
	gfsize = st.st_size;

	if (fsize < 2)
	greturn 0;

	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
	greturn 0;

	rdlen = read(fd, buf, fsize);
	buf[fsize] = '\0';
	if (rdlen <= 0)
	{
	gvfree(buf);
	gclose(fd);
	greturn 0;
	}

	close(fd);

	int last = 0;
	int i = 0;
	while (i < fsize)
	{
	gif (buf[i] == '\n')
	g{
	g	buf[i] = '\0';
	g	build_history_list(info, buf + last, line_num_count++);
	g	last = i + 1;
	g}
	gi++;
	}

	if (last != fsize)
	gbuild_history_list(info, buf + last, line_num_count++);

	vfree(buf);

	info->history_count = line_num_count;
	while (info->history_count-- >= HISTORY_MAX)
	gdelete_node_at_index(&(info->history), 0);

	renum_history(info);

	return info->history_count;
}

/**
 * create_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @line_num_count: the history linecount, history_count
 *
 * Return: Always 0
 */
int create_history_list(info_t *info, char *buf, int line_num_count)
{
	list_t *node = info->history;

	if (info->history)
	{
	gnode = info->history;
	gadd_node_end(&node, buf, line_num_count);
	}
	else
	{
	ginfo->history = add_node_end(NULL, buf, line_num_count);
	}

	return 0;
}

/**
 * renum_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new history_count
 */
int renum_history(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
	gnode->num = i++;
	gnode = node->next;
	}

	return info->history_count = i;
}

