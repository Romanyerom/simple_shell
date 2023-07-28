#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
    list_t *node = info->env;
    while (node != NULL)
    {
        printf("%s\n", node->str);
        node = node->next;
    }
    return 0;
}

/**
 * _getenv - gets the value of an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	while (node != NULL)
	{
		if (_startswith(node->str, name))
			return (node->str + _strlen(name));
		node = node->next;
    }
    return NULL;
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _mysetenv(info_t *info)
{
    if (info->argc != 3)
    {
        _eputs("Incorrect number of arguments\n");
        return 1;
    }

    char *name = info->argv[1];
    char *value = info->argv[2];

    if (_setenv(info, name, value))
        return 0;

    return 1;
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *            constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
    if (info->argc == 1)
    {
        _eputs("Too few arguments.\n");
        return 1;
    }

    for (int i = 1; i < info->argc; i++)
        _unsetenv(info, info->argv[i]);

    return 0;
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *                    constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
    char **envp = environ;
    list_t *node = NULL;

    while (*envp)
    {
        add_node_end(&node, *envp, 0);
        envp++;
    }

    info->env = node;
    return 0;
}
