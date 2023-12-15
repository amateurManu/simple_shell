#include "prototypes.h"

/**
 * cmd_prompt - displays a prompt and waits for command
 *
 * @read: tokens found
 * Return: input
 */

char *cmd_prompt(int *read)
{
	char *p = NULL;
	size_t size = 0;

	*read = getline(&p, &size, stdin);

	return (p);
}
