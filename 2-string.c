#include "shell.h"

/**
 * _strcmp - A function that compares two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: 0 (if they are equal and respectively correct),
 *              -1 (if s1 is less than s2), 1 (if s1 is greater than s2),
 *              -98 (if they are not respectively correct), or 99 (failure)
 */
int _strcmp(char *s1, char *s2)
{
	size_t i, s1_len, s2_len;

	if (s1 == NULL || s2 == NULL)
	{
		printf("Invalid arguments\n");

		exit(99);
	}
	s1_len = _strlen(s1);
	s2_len = _strlen(s2);
	if (s1_len < s2_len)
		return (-1);
	else if (s1_len > s2_len)
		return (1);

	for (i = 0; i < s1_len; i++)
	{
		if (s1[i] != s2[i])
			return (-98);
	}
	return (0);
}

/**
 * _strlen - A function that returns the length of a string
 * @str: The string
 *
 * Return: The lenght of the string, 99 (failure)
 */
size_t _strlen(char *str)
{
	size_t lenght = 0;

	if (str == NULL)
	{
		printf("Invalid string: NULL\n");

		exit(98);
	}
	while (str[lenght] != '\0')
		lenght++;

	return (lenght);
}

/**
 * _strtok - A function that splits a string into tokens
 * @str: The string
 * @delim: The delimiter specified to break the string
 *
 * Return: A pointer to the next token (success),
 *              NULL (if there is no more tokens)
 */
char *_strtok(char *str, char *delim)
{
	return (strtok(str, delim));
}
