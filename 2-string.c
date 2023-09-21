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
		write(STDERR_FILENO, "Invalid arguments\n", 18 * sizeof(char));

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
		write(STDERR_FILENO, "Invalid string: NULL\n", 21 * sizeof(char));

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

/**
 * _strcpy - A function that copies a string into another one
 * @dest: The string that is copied into
 * @src: The string that is copied from
 *
 * Return: A pointer to the new string
 */
char *_strcpy(char *dest, char *src)
{
	size_t i, src_len = _strlen(src);

	if (dest == NULL || src == NULL)
	{
		write(STDERR_FILENO, "Invalid arguments\n", 18 * sizeof(char));

		exit(100);
	}
	for (i = 0; i < src_len; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - A function that appends a string to another one
 * @dest: The string that is appended into
 * @src: The string that is appended from
 *
 * Return: A pointer to the new string
 */
char *_strcat(char *dest, char *src)
{
	size_t i, j, dest_len, src_len;

	if (dest == NULL || src == NULL)
	{
		write(STDERR_FILENO, "Invalid arguments\n", 18 * sizeof(char));

		exit(101);
	}
	dest_len = _strlen(dest);
	src_len = _strlen(src);
	if (src_len == 0)
		dest[dest_len] = '\0';
	else
	{
		for (i = dest_len, j = 0; j < src_len; i++, j++)
			dest[i] = src[j];
	}

	return (dest);
}
