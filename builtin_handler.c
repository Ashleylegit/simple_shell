#include "shell_header.h"

/**
 * Handles the execution of built-in functions in a shell program.
 *
 * @param command - A pointer to an array of strings representing the command
 * and its arguments.
 * @param line - A pointer to a string representing the entire command line 
 * input.
 * @return Returns 1 if a built-in function is executed, 0 otherwise.
 */
int builtin_handler(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*command, builtin.env) == 0)
	{
		environment_function();
		return (1);
	}
	else if (_strcmp(*command, builtin.exit) == 0)
	{
		exit_function(command, line);
		return (1);
	}
	return (0);
}
