#include "shell_header.h"

/**
* path_function - function that checks for a valid path
* @path: char
* @command: char
* Return: path or NULL
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
