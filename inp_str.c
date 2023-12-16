#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: no value
 */

void _eputs(char *input_str)
{
	int index = 0;

	if (!input_str)
		return;
	while (input_str[index] != '\0')
	{
		_eputchar(input_str[index]);
		index++;
	}
}

/**
 * _eputchar - writes the character c to the stderr
 * @character: The character to be printed
 *
 * Return: 1 (Success), -1 on error
 */

int _eputchar(char c)
{
	static int count;
	static char buffer[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || count >= WRITE_BUF_SIZE)
	{
		write(2, buffer, count);
		count = 0;
	}
	if (ch != BUF_FLUSH)
		buffer[count++] = ch;
	return (1);
}

/**
 * _putfd - writes the character to fd
 * @ch: character to print
 * @fd: file descriptor to write to
 *
 * Return: 1 (Success), -1 on error
 */

int _putfd(char ch, int file_descriptor)
{
	static int count;
	static char buffer[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || count >= WRITE_BUF_SIZE)
	{
		write(file_descriptor, buffer, count);
		count = 0;
	}
	if (ch != BUF_FLUSH)
		buffer[count++] = ch;
	return (1);
}

/**
 * _putsfd - prints the input string
 * @input_str: string to be printed
 * @file_descriptor: file descriptor to write to
 *
 * Return: number of chars put
 */

int _putsfd(char *input_str, int file_descriptor)
{
	int index = 0;

	if (!input_str)
		return (0);
	while (*input_str)
	{
		index += _putfd(*input_str++, file_descriptor);
	}
	return (index);
}
