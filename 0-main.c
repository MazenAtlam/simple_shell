#define ARGSNUM 1

#include "shell.h"

/**
 * main - Entry point
 * @argc: The number of arguments entered
 * @argv: An array of pointers to this arguments
 * @envp: An array of pointers to the environment variables
 *
 * Return: 0 (success), non-zero value (failure)
 */
int main(int argc, char *argv[], char *envp[])
{
	char *av[MAX];
	char *cmdline;
	char *buff = NULL;
	size_t n = 0;
	unsigned int i = 0, count = 0;
	bcmd_t b_cmd[] = { {"exit", exit_cmd}, {"cd", cd_cmd}, {NULL, NULL} };

	if (argc != ARGSNUM)
	{
		write(STDERR_FILENO, "Usage: simple_shell\n", 20 * sizeof(char));
		return (127);
	}
	while (1)
	{
		fflush(stdin);
		if (_getline(&buff, &n, stdin) == -1)
			break;
		cmdline = _strtok(buff, "#");
		if (cmdline != NULL)
		{
			count++;
			av[0] = _strtok(cmdline, " ");
			i = 0;
			while (av[i++] != NULL)
				av[i] = _strtok(NULL, " ");
			for (i = 0; b_cmd[i].c != NULL; i++)
			{
				if (_strcmp(av[0], b_cmd[i].c) == 0)
					b_cmd[i].func(av[1], argv[0], buff, count);
			}
			exec_cmd(av, envp, count);
		}
	}
	write(STDOUT_FILENO, "\n", sizeof(char));
	free(buff);

	return (0);
}
