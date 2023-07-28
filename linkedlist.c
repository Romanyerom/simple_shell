#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of the node
 * @num: node index used by history
 *
 * Return: pointer to the new node
 */

list_t *add_node(list_t **head, const char *str, int num)
{
	if (!head)
		return (NULL);

	list_t *new_head = malloc(sizeof(list_t));

	if (!new_head)
		return (NULL);

	new_head->num = num;
	new_head->str = str ? _strdup(str) : NULL;
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of the node
 * @num: node index used by history
 *
 * Return: pointer to the new node
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	if (!head)
		return (NULL);

	list_t *new_node = malloc(sizeof(list_t));

	if (!new_node)
		return (NULL);

	new_node->num = num;
	new_node->str = str ? _strdup(str) : NULL;
	new_node->next = NULL;

	if (*head)
	{
		list_t *last = *head;

		while (last->next)
			last = last->next;

		last->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to the first node
 *
 * Return: size of the list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}

	return (i);
}

/**
 * delete_node_at_index - deletes node at the given index
 * @head: address of pointer to the first node
 * @index: index of the node to delete
 *
 * Return: 1 on success, 0 on failure
 */

int delete_node_at_index(list_t **head, unsigned int index)
{
	if (!head || !*head)
		return (0);

	if (!index)
	{
		list_t *node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}

	list_t *node = *head;
	list_t *prev_node = NULL;

	unsigned int i = 0;

	while (node)
	{
		if (i == index)
		{
			if (prev_node)
				prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}

		i++;
		prev_node = node;
		node = node->next;
	}

	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to the head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	if (!head_ptr || !*head_ptr)
		return;

	list_t *node = *head_ptr;

	while (node)
	{
		list_t *next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}

	*head_ptr = NULL;
}