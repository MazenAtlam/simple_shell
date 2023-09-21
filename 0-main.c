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
	char *cmd[MAX], *cmdline, *buff;
	size_t n = 50;
	unsigned int i = 0, count = 0, executed = 0;
	bcmd_t b_cmd[] = { {"exit", exit_cmd}, {"cd", exit_cmd},
		{"env", env_cmd}, {NULL, NULL} };

	if (argc != ARGSNUM)
	{	write(STDERR_FILENO, "Usage: simple_shell\n", 20 * sizeof(char));
		return (127);	}
	while (1)
	{	fflush(stdin);
		write(STDOUT_FILENO, "$ ", 2 * sizeof(char));
		buff = malloc(50 * sizeof(char));
		if (buff == NULL)
		{	write(STDERR_FILENO, argv[0], _strlen(argv[0]) * sizeof(char));
			write(STDERR_FILENO, ": ", 2 * sizeof(char));
			perror("");
			return (130);	}
		if (_getline(&buff, &n, stdin) == -1)
			break;
		buff[_strlen(buff) - 1] = '\0';
		cmdline = _strtok(buff, "#");
		if (cmdline != NULL)
		{	count++;
			executed = 0;
			cmd[0] = _strtok(cmdline, " ");
			i = 0;
			while (cmd[i++] != NULL)
				cmd[i] = _strtok(NULL, " ");
			for (i = 0; b_cmd[i].c != NULL; i++)
			{
				if (_strcmp(cmd[0], b_cmd[i].c) == 0)
				{	b_cmd[i].func(cmd, argv[0], buff, count, envp);
					executed = 1;	}	}
			if (!executed)
				check_cmd(cmd, argv[0], buff, count, envp);	}	}
	write(STDOUT_FILENO, "\n", sizeof(char));
	free(buff);
	return (0);
}
