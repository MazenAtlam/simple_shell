#ifndef SHELL_H
#define SHELL_H

#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/**
 * struct built_in_cmd - A struct of built-in commands
 * @c: The command
 * @func: A pointer to function that executes this command
 *
 * Description: The commands that are built-in Unix shell
 */
typedef struct built_in_cmd
{
	char *c;
	void (*func)();
} bcmd_t;

char *_strtok(char *str, char *delim);
size_t _strlen(char *s);
int _strcmp(char *s1, char *s2);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
unsigned int num_length(unsigned int num);
unsigned int _atoi(char *str);
char *_itoa(unsigned int num);
void exec_cmd(char *cmd[], char *envp[], unsigned int count);
void exit_cmd(char *s_status, char *sh, char *buff, unsigned int count);
void cd_cmd(char *s_status, char *sh, char *buff, unsigned int count);

#endif /*_shell.h_*/
