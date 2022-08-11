#include "shell_header.h"

/**
* builtin_handler - function that handles the execution of builtin functions
* @command: char
* @line: char
* Return: 1 or 0
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
