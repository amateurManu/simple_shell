#include "shell.h"

/**
 * _myenv - prints current environment
 * @shell_info: structure with arguments
 *
 * Return: 0
 */

int _myenv(info_t *shell_info)
{
	print_list_str(shell_info->env);
	return (0);
}

/**
 * _getenv_custom - gets value of environment variable
 * @shell_info: structure with arguments
 * @name: env var name
 * Return: value
 */

char *_getenv_custom(info_t *shell_info, const char *name)
{
	list_t *node = shell_info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - new environment variable
 * @shell_info: structure containing potential arguments
 * Return: 0
 */

int _mysetenv(info_t *shell_info)
{
	if (shell_info->argc != 3)
	{
		_eputs("Incorrect number of args\n");
		return (1);
	}
	if (_setenv(shell_info, shell_info->argv[1], shell_info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - removes env variable
 * @shell_info: struct with potential args
 * Return 0
 */

int _myunsetenv(info_t *shell_info)
{
	int i;

	if (shell_info->argc == 1)
	{
		_eputs("Few arguments.\n");
		return (1);
	}
	for (i = 1; i <= shell_info->argc; i++)
		_unsetenv(shell_info, shell_info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env list
 * @shell_info: struct with potential args
 * Return: 0
 */

int populate_env_list(info_t *shell_info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		addNode_end(&node, environ[i], 0);
	shell_info->env = node;
	return (0);
}
