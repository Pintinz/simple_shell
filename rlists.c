#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: pointer to the newly added node
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	if (!head)
	greturn NULL;

	list_t *new_node = malloc(sizeof(list_t));
	if (!new_node)
	greturn NULL;

	new_node->num = num;
	new_node->str = str ? _strdup(str) : NULL;
	new_node->next = *head;
	*head = new_node;

	return new_node;
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: pointer to the newly added node
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	if (!head)
	greturn NULL;

	list_t *new_node = malloc(sizeof(list_t));
	if (!new_node)
	greturn NULL;

	new_node->num = num;
	new_node->str = str ? _strdup(str) : NULL;
	new_node->next = NULL;

	if (*head)
	{
	glist_t *node = *head;
	gwhile (node->next)
	g	node = node->next;
	gnode->next = new_node;
	}
	else
	{
	g*head = new_node;
	}

	return new_node;
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
	g_puts(h->str ? h->str : "(nil)");
	g_puts("\n");
	gh = h->next;
	gcount++;
	}

	return count;
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	if (!head || !*head)
	greturn 0;

	if (index == 0)
	{
	glist_t *node = *head;
	g*head = (*head)->next;
	gfree(node->str);
	gfree(node);
	greturn 1;
	}

	list_t *prev_node = *head;
	list_t *node = prev_node->next;
	unsigned int i = 1;

	while (node)
	{
	gif (i == index)
	g{
	g	prev_node->next = node->next;
	g	free(node->str);
	g	free(node);
	g	return 1;
	g}

	gi++;
	gprev_node = node;
	gnode = node->next;
	}

	return 0;
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	if (!head_ptr || !*head_ptr)
	greturn;

	list_t *node = *head_ptr;
	while (node)
	{
	glist_t *next_node = node->next;
	gfree(node->str);
	gfree(node);
	gnode = next_node;
	}

	*head_ptr = NULL;
}

