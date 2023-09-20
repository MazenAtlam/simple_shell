#include "shell.h"

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
