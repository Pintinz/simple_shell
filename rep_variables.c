#include "shell.h"

/**
 * _chain - tests if current char in buffer is a chain delimiter
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimiter, 0 otherwise
 */
int _chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	switch (buf[j])
	{
	case '|':
	if (buf[j + 1] == '|')
	{
	buf[j] = 0;
	j++;
	info->cmd_buf_type = CMD_OR;
	break;
	}
	return (0);
	case '&':
	if (buf[j + 1] == '&')
	{
	buf[j] = 0;
	j++;
	info->cmd_buf_type = CMD_AND;
	break;
	}
	return (0);
	case ';':
	buf[j] = 0;
	info->cmd_buf_type = CMD_CHAIN;
	break;
	default:
	return (0);
	}

	*p = j;
	return (1);
}

/**
 * check - checks if we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	switch (info->cmd_buf_type)
	{
	case CMD_AND:
	if (info->status)
	{
	buf[i] = 0;
	j = len;
	}
	break;
	case CMD_OR:
	if (!info->status)
	{
	buf[i] = 0;
	j = len;
	}
	break;
	}

	*p = j;
}

/**
 * rep_aliases - replaces an alias in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int rep_aliases(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
	node = node_starts_with(info->alias, info->argv[0], '=');
	if (!node)
	return (0);
	free(info->argv[0]);
	p = _strchr(node->str, '=');
	if (!p)
	return (0);
	p = _strdup(p + 1);
	if (!p)
	return (0);
	info->argv[0] = p;
	}

	return (1);
}

/**
 * rep_variables - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int rep_variables(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
	if (info->argv[i][0] != '$' || !info->argv[i][1])
	continue;
	if (!_strcmp(info->argv[i], "$?"))
	{
	replace_string(&(info->argv[i]), _strdup(convert_number(info->status, 10, 0)));
	continue;
	}
	if (!_strcmp(info->argv[i], "$$"))


