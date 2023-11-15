#include "shell_header.h"

/**
 * This function takes in two parameters: 'command' (a pointer to a pointer 
 * to char) and 'line' (a pointer to char). It is responsible for freeing 
 * the memory allocated for 'line' and 'command' and then exiting the program 
 * with a success status.
 *
 * @param command A pointer to a pointer to char representing the command 
 * to be executed.
 * @param line A pointer to char representing the input line.
 *
 * @return None.
 */
void exit_function(char **command, char *line)
{
	free(line);
	free_buffer(command);
	exit(0);
}
