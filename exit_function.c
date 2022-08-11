#include "shell_header.h"

/**
* exit_function - function that handles the exit command
* @command: char
* @line: char
* Return: nothing
*/
void exit_function(char **command, char *line)
{
	free(line);
	free_buffer(command);
	exit(0);
}
