#include "shell_header.h"

/**
 * run_command - function that runs commands entered by the user
 *@cp: char
 *@cmd: char
 * Return: 0
 */
void run_command(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);
	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		free(cp);
		free_buffer(cmd);
		exit(98);
	}
	else
		wait(&status);
}
