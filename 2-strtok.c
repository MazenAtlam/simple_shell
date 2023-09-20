#include "shell.h"

/**
 * _strtok - A function that splits a string into tokens
 * @str: The string
 * @delim: The delimiter specified to break the string
 *
 * Return: A pointer to the next token (success),
 *		NULL (if there is no more tokens)
 */
char *_strtok(char *str, char *delim)
{
	return (strtok(str, delim));
}
