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

/**
 * main - Entry point
 *
 * Return: 0 (Success)
 */

int main(void)
{
	int read;
	char *input;

	do {
		printf("oloyeodero$: ");
		input = cmd_prompt(&read);

		if (read != -1)
		{
			printf("You entered: %s", input);
			free(input);
		}
		else
		{
			perror("Error reading input");
		}
	} 
	while (read != -1);

	return (0);
}
