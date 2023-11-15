#include "shell_header.h"

/**
 * Appends a command to a path and returns the resulting string.
 *
 * @param path The base path to append the command to.
 * @param command The command to append to the path.
 * @param error A pointer to an ErrorCode variable to store any error that 
 * occurs.
 * @return The resulting string after appending the command to the path. 
 * If an error occurs, NULL is returned and the error pointer is set 
 * accordingly.
 */
char *path_append(char *path, char *command)
{
	char *pad;
	size_t i = 0, j = 0;

	if (command == 0)
		command = "";

	if (path == 0)
		path = "";

	pad = malloc(sizeof(char) * (_strlen(path) + _strlen(command) + 2));
	if (!pad)
		return (NULL);

	while (path[i])
	{
		pad[i] = path[i];
		i++;
	}

	if (path[i - 1] != '/')
	{
		pad[i] = '/';
		i++;
	}
	while (command[j])
	{
		pad[i + j] = command[j];
		j++;
	}
	pad[i + j] = '\0';
	return (pad);
}
