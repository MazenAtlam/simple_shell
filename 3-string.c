#include "shell.h"

/**
 * _strdup - A function that duplicates a string
 * @str: The string to be duplicated
 *
 * Return: A pointer to the new string
 */
char *_strdup(char *str)
{
	char *new_str;
	size_t i, str_len;

	if (str == NULL)
	{
		write(STDERR_FILENO, "Invalid argument\n", 17 * sizeof(char));

		exit(102);
	}
	str_len = _strlen(str);
	new_str = malloc((str_len + 1) * sizeof(char));
	if (new_str == NULL)
	{
		perror("");

		exit(103);
	}
	for (i = 0; i < str_len; i++)
		new_str[i] = str[i];
	new_str[i] = '\0';

	return (new_str);
}
