#include "shell_header.h"

/**
 * Executes a command by forking a child process and using the execve 
 * system call. Handles error cases and frees allocated memory.
 *
 * @param cp A pointer to a string representing the command to be executed.
 * @param cmd A pointer to an array of strings representing the command 
 * and its arguments.
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
