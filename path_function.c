#include "shell_header.h"

/**
 * It processes an array of strings representing paths, a command string 
 * to append to each path, and an ErrorCode variable; validates inputs, 
 * iterates through each path, appends the command, and returns the path 
 * if it corresponds to an executable file, logging errors and returning 
 * a message if no valid path is found.
 *
 * path: an array of strings representing different paths
 * command: a string representing the command to be appended to each path
 * error: a pointer to an ErrorCode variable to store error information
 *
 * returns: a pointer or NULL
 */
char *path_function(char **path, char *command)
{
	int i = 0;
	char *output;

	while (path[i])
	{
		output = path_append(path[i], command);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		i++;
	}
	return (NULL);
}
