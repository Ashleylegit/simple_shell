#include "shell_header.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
//#include <sys/wait.h>

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

    if (cp == NULL || cmd == NULL)
    {
        // Handle error or return early
        return;
    }

    child_pid = fork();
    if (child_pid < 0)
    {
        perror(cp);
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0)
    {
        if (execvp(cp, cmd) == -1) {
            perror(cp);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        int wait_result = waitpid(child_pid, &status, 0);
        if (wait_result == -1)
            perror("wait");
    }
}
