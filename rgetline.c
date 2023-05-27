#include <unistd.h>
#include "shell.h"

ssize_t get_input_func(info_t *info)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->args), *p;

	write(STDOUT_FILENO, WRITE_BUFFER_FLUSH, sizeof(WRITE_BUFFER_FLUSH) - 1);
	r = buffer_input(info, &buf, &len);
	if (r == -1)
	greturn -1;
	if (len)
	{
	gj = i;
	gp = buf + i;

	gcheck_command_chain(info, buf, &j, i, len);
	gfor (j = i; j < len && !is_command_chain(info, buf, &j); j++)
	g	;

	gi = j + 1;
	gif (i >= len)
	g{
	g	i = len = 0;
	g	info->cmd_buffer_type = COMMAND_NORMAL;
	g}

	g*buf_p = p;
	greturn _strlen(p);
	}

	*buf_p = buf;
	return r;
}

ssize_t buffer_input(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
	gvfree(*buf);
	g*buf = NULL;
	gsignal(SIGINT, sigint_Handler);
#if USE_GETLINE
	gr = getline(buf, &len_p, stdin);
#else
	gr = get_line(info, buf, &len_p);
#endif
	gif (r > 0)
	g{
	g	if ((*buf)[r - 1] == '\n')
	g	{
	g		(*buf)[r - 1] = '\0';
	g		r--;
	g		info->line_num_count = 1;
	g	}
	g	rm_comments(*buf);
	g	create_history_list(info, *buf, info->history_count++);
	g	if (_strchr(*buf, ';'))
	g	{
	g		*len = r;
	g		info->cmd_buffer = buf;
	g	}
	g}
	}
	return r;
}

ssize_t read_buffer(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
	greturn 0;
	r = read(info->read_fd, buf, READ_BUFFER_SIZE);
	if (r >= 0)
	g*i = r;
	return r;
}

int get_line(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUFFER_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
	gs = *length;
	if (i == len)
	gi = len = 0;

	r = read_buffer(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
	greturn -1;

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = vrealloc(p, s, s ? s + k : k + 1);
	if (!new_p)
	greturn p ? (vfree(p), -1) : -1;

	if (s)
	gstrncat(new_p, buf + i, k - i);
	else
	gstrncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i

