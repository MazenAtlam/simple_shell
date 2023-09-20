#include "shell.h"

/**
 * num_length - A function that computes the length of an integer
 * @num: The integer
 *
 * Return: The length
*/

unsigned int num_length(unsigned int num)
{
	unsigned int length = 0;

	if (num < 10)
		return (1);

	while (num != 0)
	{
		num = num / 10;
		length++;
	}

	return (length);
}

/**
 * _atoi - A function that convers a string of numbers into an integer
 * @str: The string into which contains the number
 *
 * Return: The integer (success), 0 (if there are any other characters)
 */
unsigned int _atoi(char *str)
{
	unsigned int i = 0, num = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);

		num = (num * 10) + (str[i] - 48);
	}

	return (num);
}

/**
 * _itoa - A function that convers an integer into a string
 * @num: The number
 *
 * Return: A pointer to the allocated string
 */
char *_itoa(unsigned int num)
{
	char *str;
	unsigned int num_len = num_length(num), i = 0, denom = 1;

	for (i = 0; i < num_len - 1; i++)
		denom = denom * 10;
	str = malloc(num_len + 1);
	for (i = 0; denom != 0; i++)
	{
		str[i] = (num / denom) + 48;
		num = num % denom;
		denom = denom / 10;
	}
	str[i] = '\0';

	return (str);
}
