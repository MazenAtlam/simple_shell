#include "shell.h"

/**
 * exit_cmd - A function that executes the built-in command exit
 * @s_status: The status in string type
 * @sh: The shell name
 * @buff: The buffer allocated to contain the command line
 * @count: The number of errors counted from executing the shell
 *
 * Return: Nothing
 */
void exit_cmd(char *s_status, char *sh, char *buff, unsigned int count)
{
	char *counter;
	unsigned int status;

	if (s_status == NULL)
	{
		free(buff);

		exit(0);
	}
	status = _atoi(s_status);
	if (status <= INT_MAX)
	{
		if (status != 0)
		{
			while (status > 255)
				status -= 256;
			free(buff);

			exit(status);
		}
		if (s_status[0] == '0')
		{
			free(buff);

			exit(0);
		}
	}
	counter = _itoa(count);
	write(STDERR_FILENO, sh, _strlen(sh) * sizeof(char));
	write(STDERR_FILENO, ": ", 2 * sizeof(char));
	write(STDERR_FILENO, counter, _strlen(counter) * sizeof(char));
	write(STDERR_FILENO, ": exit: Illegal number: ", 24 * sizeof(char));
	write(STDERR_FILENO, s_status, _strlen(s_status) * sizeof(char));
	write(STDERR_FILENO, "\n", sizeof(char));
	free(counter);
}
