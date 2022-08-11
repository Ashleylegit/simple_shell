#include "shell_header.h"

/**
* path_append - function that adds a path to a command
* @path: char
* @command: char
* Return: buffer or NULL
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
