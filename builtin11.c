#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */

int _myhistory(info_t *info)
{
	history_t *current = info->history;

	int line_number = 0;

	while (current != NULL)
	{
		printf("%d %s\n", line_number++, current->cmd);
		current = current->next;
	}

	return (0);
}

/**
 * unset_alias - unsets an alias
 * @info: parameter struct
 * @str: the string alias to unset
 *
 * Return: Always 0 on success, 1 on error
 */

int unset_alias(info_t *info, char *str)
{
	list_t *alias_node = node_starts_with(info->alias, str, '=');

	if (alias_node != NULL)
	{
		delete_node_at_index(&(info->alias),
				get_node_index(info->alias, alias_node));
        return (0);
	}

	return (1);
}

/**
 * set_alias - sets an alias to a string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *p = _strchr(str, '=');

	if (p != NULL)
	{
		*p = '\0';
		unset_alias(info, str);
		*p = '=';
		return (add_node_end(&(info->alias), str, 0) == NULL);
	}

	return (1);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */

int print_alias(list_t *node)
{
	if (node)
	{
		char *p = _strchr(node->str, '=');

		if (p)
		{
			*p = '\0';
			printf("%s='%s'\n", node->str, p + 1);
			*p = '=';
			return (0);
		}
	}

	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */

int _myalias(info_t *info)
{
	if (info->argc == 1)
	{
		list_t *node = info->alias;

		while (node != NULL)
		{
			print_alias(node);
			node = node->next;
		}
	}
	else
	{
		for (int i = 1; info->argv[i] != NULL; i++)
		{
			char *p = _strchr(info->argv[i], '=');

			if (p != NULL)
				*p = '\0';
				set_alias(info, info->argv[i]);
				*p = '=';
			else
				print_alias(node_starts_with(info->alias, info->argv[i], '='));
		}
	}

	return (0);
}
