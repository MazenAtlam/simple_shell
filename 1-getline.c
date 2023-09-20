#include "shell.h"

/**
 * _getline - A function that reads an entire line from stream
 * @lineptr: A pointer in which stores the address of the line text
 * @n: The size of the buffer containing the text into
 * @stream: The file stream to read the line from
 *
 * Return: The length of the line (success), -1 (failure) and errno is set
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	return (getline(lineptr, n, stream));
}
