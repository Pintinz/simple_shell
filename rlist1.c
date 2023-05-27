#include "shell.h"

/**
 * list_len - determines the length of a linked list
 * @h: pointer to the first node
 *
 * Return: size of the list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	for (; h; h = h->next)
		count++;

	return count;
}

/**
 * list_to_strings - returns an array of strings from the list's str field
 * @head: pointer to the first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	size_t count = list_len(head);
	char **strs;
	char *str;

	if (!head || count == 0)
		return NULL;

	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return NULL;

	for (size_t i = 0; head; head = head->next, i++)
	{
		str = malloc(_strlen(head->str) + 1);
		if (!str)
		{
			for (size_t j = 0; j < i; j++)
				free(strs[j]);

			free(strs);
			return NULL;
		}

		_strcpy(str, head->str);
		strs[i] = str;
	}

	strs[count] = NULL;
	return strs;
}

/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to the first node
 *
 * Return: size of the list
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	for (; h; h = h->next)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		count++;
	}

	return count;
}

/**
 * node_starts_with - returns the node whose string starts with the prefix
 * @node: pointer to the list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: matching node or NULL
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	for (; node; node = node->next)
	{
		char *p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return node;
	}

	return NULL;
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to the list head
 * @node: pointer to the node
 *
 * Return: index of the node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t index = 0;

	for (; head; head = head->next, index++)
	{
		if (head == node)
			return index;
	}

	return -1;
}

