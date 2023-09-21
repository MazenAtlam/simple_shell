#include "shell.h"

/**
 * exit_cmd - A function that executes the built-in command exit
 * @cmd: A pointer to an array of tokens which containing the command line in
 * @sh: The shell name
 * @buff: The buffer allocated to contain the command line
 * @count: The number of errors counted from executing the shell
 * @envp: An array of pointers to the environment variables
 *
 * Return: Nothing
 */
void exit_cmd(char *cmd[], char *sh, char *buff, unsigned int count,
		char *envp[])
{
	char *counter;
	unsigned int status;

	(void) envp;
	if (cmd[1] == NULL)
	{
		free(buff);

		exit(0);
	}

	status = _atoi(cmd[1]);
	if (status <= INT_MAX)
	{
		if (status != 0)
		{
			while (status > 255)
				status -= 256;
			free(buff);

			exit(status);
		}
		if (cmd[1][0] == '0')
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
	write(STDERR_FILENO, cmd[1], _strlen(cmd[1]) * sizeof(char));
	write(STDERR_FILENO, "\n", sizeof(char));
	free(counter);
	free(buff);
}
