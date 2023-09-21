#include "shell.h"

/**
 * check_cmd - A function that executes some commands
 * @cmd: A pointer to an array of tokens which containing the command line in
 * @sh: The shell name
 * @buff: The buffer allocated to contain the command line
 * @count: The number of errors counted from executing the shell
 * @envp: An array of pointers to the environment variables
 *
 * Return: Nothing
 */
void check_cmd(char *cmd[], char *sh, char *buff, unsigned int count,
		char *envp[])
{	struct stat stat_buff;
	char *path, *path_copy, *path_token, *ac_cmd, *counter;
	unsigned int cmd_len, dir_len;

	if (stat(cmd[0], &stat_buff) == 0)
		if (exec_cmd(cmd, sh, count, envp) == 0)
		{	free(buff);
			return;	}
	path = getenv("PATH");
	if (path != NULL)
	{	path_copy = strdup(path);
		cmd_len = _strlen(cmd[0]);
		path_token = _strtok(path_copy, ":");
		while (path_token != NULL)
		{	dir_len = _strlen(path_token);
			ac_cmd = malloc((cmd_len + dir_len + 2) * sizeof(char));
			ac_cmd = _strcpy(ac_cmd, path_token);
			ac_cmd[_strlen(ac_cmd)] = '/';
			ac_cmd = _strcat(ac_cmd, cmd[0]);
			ac_cmd[_strlen(ac_cmd)] = '\0';
			if (stat(ac_cmd, &stat_buff) == 0)
			{	cmd[0] = ac_cmd;
				if (exec_cmd(cmd, sh, count, envp) == 0)
				{	free(ac_cmd);
					free(buff);
					free(path_copy);
					return;	}	}
			free(ac_cmd);
			path_token = _strtok(NULL, ":");	}
		counter = _itoa(count);
		write(STDERR_FILENO, sh, _strlen(sh) * sizeof(char));
		write(STDERR_FILENO, ": ", 2 * sizeof(char));
		write(STDERR_FILENO, counter, _strlen(counter) * sizeof(char));
		write(STDERR_FILENO, ": ", 2 * sizeof(char));
		write(STDERR_FILENO, cmd[0], _strlen(cmd[0]) * sizeof(char));
		write(STDERR_FILENO, ": ", 2 * sizeof(char));
		perror("");
		free(counter);
		free(buff);
		free(path_copy);	}	}
