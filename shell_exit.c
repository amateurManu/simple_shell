#include "shell.h"

/**
 * _custom_strncpy - copies a string
 * @destination: the destination string to be copied to
 * @source: the source string
 * @num: the number of characters to be copied
 * Return: the concatenated string
 */
char *_custom_strncpy(char *destination, char *source, int num)
{
    int index, j;
    char *result = destination;

    index = 0;
    while (source[index] != '\0' && index < num - 1)
    {
        destination[index] = source[index];
        index++;
    }
    if (index < num)
    {
        j = index;
        while (j < num)
        {
            destination[j] = '\0';
            j++;
        }
    }
    return result;
}

/**
 * _custom_strncat - concatenates two strings
 * @destination: the first string
 * @source: the second string
 * @num: the maximum number of bytes to be used
 * Return: the concatenated string
 */
char *_custom_strncat(char *destination, char *source, int num)
{
    int i, j;
    char *result = destination;

    i = 0;
    j = 0;
    while (destination[i] != '\0')
        i++;
    while (source[j] != '\0' && j < num)
    {
        destination[i] = source[j];
        i++;
        j++;
    }
    if (j < num)
        destination[i] = '\0';
    return result;
}

/**
 * _custom_strchr - locates a character in a string
 * @str: the string to be parsed
 * @character: the character to look for
 * Return: (str) a pointer to the memory area str
 */
char *_custom_strchr(char *str, char character)
{
    do
    {
        if (*str == character)
            return str;
    } while (*str++ != '\0');

    return NULL;
}
