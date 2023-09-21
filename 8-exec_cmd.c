#include "shell.h"

/**
 * exec_cmd - A function that executes some commands
 * @cmd: A pointer to an array of tokens which containing the command line in
 * @sh: The shell name
 * @count: The number of errors counted from executing the shell
 * @envp: An array of pointers to the environment variables
 *
 * Return: 0 (success), Non-zero value (failure)
 */
int exec_cmd(char *cmd[], char *sh, unsigned int count, char *envp[])
{	char *counter;
	pid_t cid;
	int wstatus;

	cid = fork();
	if (cid == -1)
	{	counter = _itoa(count);
		write(STDERR_FILENO, sh, _strlen(sh) * sizeof(char));
		write(STDERR_FILENO, ": ", 2 * sizeof(char));
		write(STDERR_FILENO, counter, _strlen(counter) * sizeof(char));
		write(STDERR_FILENO, ": ", 2 * sizeof(char));
		write(STDERR_FILENO, cmd[0], _strlen(cmd[0]) * sizeof(char));
		write(STDERR_FILENO, ": ", 2 * sizeof(char));
		perror("");
		free(counter);
		return (1);
	}
	else if (cid == 0)
		exit(execve(cmd[0], cmd, envp));

	wait(&wstatus);
	if (WIFEXITED(wstatus))
	{
		if (WEXITSTATUS(wstatus) == -1)
		{	counter = _itoa(count);
			write(STDERR_FILENO, sh, _strlen(sh) * sizeof(char));
			write(STDERR_FILENO, ": ", 2 * sizeof(char));
			write(STDERR_FILENO, counter, _strlen(counter) * sizeof(char));
			write(STDERR_FILENO, ": ", 2 * sizeof(char));
			write(STDERR_FILENO, cmd[0], _strlen(cmd[0]) * sizeof(char));
			write(STDERR_FILENO, ": ", 2 * sizeof(char));
			perror("");
			free(counter);
			return (2);
		}
		else
			return (0);
	}
	return (3);
}
