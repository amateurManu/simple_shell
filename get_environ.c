#include "shell.h"

/**
 * get_environment - returns the string array copy of our environment
 * @shell_info: Structure containing potential arguments. Used to maintain
 *               constant function prototype.
 * Return: Always 0
 */
char **get_environment(shell_info_t *shell_info)
{
    if (!shell_info->environment || shell_info->environment_changed)
    {
        shell_info->environment = list_to_strings(shell_info->env_list);
        shell_info->environment_changed = 0;
    }

    return (shell_info->environment);
}

/**
 * _unset_environment_variable - Remove an environment variable
 * @shell_info: Structure containing potential arguments. Used to maintain
 *               constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @variable: the string env variable property
 */
int _unset_environment_variable(shell_info_t *shell_info, char *variable)
{
    list_t *node = shell_info->env_list;
    size_t index = 0;
    char *position;

    if (!node || !variable)
        return (0);

    while (node)
    {
        position = starts_with(node->str, variable);
        if (position && *position == '=')
        {
            shell_info->environment_changed = delete_node_at_index(&(shell_info->env_list), index);
            index = 0;
            node = shell_info->env_list;
            continue;
        }
        node = node->next;
        index++;
    }
    return (shell_info->environment_changed);
}

/**
 * _set_environment_variable - Initialize a new environment variable,
 *                             or modify an existing one
 * @shell_info: Structure containing potential arguments. Used to maintain
 *               constant function prototype.
 * @variable: the string env variable property
 * @value: the string env variable value
 *  Return: Always 0
 */
int _set_environment_variable(shell_info_t *shell_info, char *variable, char *value)
{
    char *buffer = NULL;
    list_t *node;
    char *position;

    if (!variable || !value)
        return (0);

    buffer = malloc(_strlen(variable) + _strlen(value) + 2);
    if (!buffer)
        return (1);
    _strcpy(buffer, variable);
    _strcat(buffer, "=");
    _strcat(buffer, value);
    node = shell_info->env_list;
    while (node)
    {
        position = starts_with(node->str, variable);
        if (position && *position == '=')
        {
            free(node->str);
            node->str = buffer;
            shell_info->environment_changed = 1;
            return (0);
        }
        node = node->next;
    }
    add_node_end(&(shell_info->env_list), buffer, 0);
    free(buffer);
    shell_info->environment_changed = 1;
    return (0);
}
