#include "shell.h"

/**
 * env_cmd - A function that prints the current environment
 * @cmd: A pointer to an array of tokens which containing the command line in
 * @sh: The shell name
 * @buff: The buffer allocated to contain the command line
 * @count: The number of errors counted from executing the shell
 * @envp: An array of pointers to the environment variables
 *
 * Return: Nothing
 */
void env_cmd(char *cmd[], char *sh, char *buff, unsigned int count,
		char *envp[])
{
	int i;

	(void) cmd;
	(void) sh;
	(void) count;
	for (i = 0; envp[i] != NULL; i++)
	{
		write(STDOUT_FILENO, envp[i], _strlen(envp[i]) * sizeof(char));
		write(STDOUT_FILENO, "\n", sizeof(char));
	}
	free(buff);
}
