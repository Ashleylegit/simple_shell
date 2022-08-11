#include "shell_header.h"

/**
* environment_function - function that prints the environment string to stdout
* Return: 0
*/
void environment_function(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
