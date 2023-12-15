#include "prototypes.h"

/**
 * main - Entry point
 * @argc: number of arguments passed to program
 * @argv: string of arguments passed to program
 * Return 0 (Success)
 */

int main(int argc, char *argv[])
{
	int read;
	char *line;

	do {
		printf("oloyeodero$ ");
		line = cmd_prompt(&read);

		if (read != -1)
		{
			printf("Entered: %s", line);
			free(line);
		}
		else
		{
			perror("Error reading line");
		}
	}
	while (read != -1);

	return (0);
}
